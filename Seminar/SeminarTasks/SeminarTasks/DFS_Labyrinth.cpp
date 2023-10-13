#include <iostream>

using namespace std;


bool lab[5][5] = { 1, 1, 1, 0, 1,
				  1, 1, 1, 0, 1,
				  1, 0, 0, 0, 1,
				  1, 1, 0, 1, 1,
				  0, 1, 1, 1, 1 };


bool wayrec(int startx, int starty, int endx, int endy)
{
	if (startx == endx && starty == endy)
		return true;
	if (startx < 0 || starty < 0 || startx > 4 || starty > 4)
		return false;
	if (!lab[startx][starty])
		return false;

	lab[startx][starty] = 0;

	bool result = false;

	result = wayrec(startx + 1, starty, endx, endy);

	if (!result)
		result = wayrec(startx, starty + 1, endx, endy);

	if (!result)
		result = wayrec(startx - 1, starty, endx, endy);

	if (!result)
		result = wayrec(startx, starty - 1, endx, endy);

	lab[startx][starty] = 1;

	return result;


}

struct Position
{
	int x, y;
	Position(int _x, int _y) :x(_x), y(_y) {}
	Position() :x(0), y(0) {}

	bool correct()
	{
		return x >= 0 && y >= 0 && x <= 4 && y <= 4;
	}

	bool accessible()
	{
		return lab[x][y];
	}

	Position right()
	{
		return Position(x + 1, y);
	}
	Position left()
	{
		return Position(x - 1, y);
	}
	Position up()
	{
		return Position(x, y - 1);
	}
	Position down()
	{
		return Position(x, y + 1);
	}

	void visit(bool visited = true)
	{
		lab[x][y] = !visited;
	}

	void print()
	{
		cout << "(" << x << "," << y << ")\n";
	}

	bool operator == (const Position& p)
	{
		return x == p.x && y == p.y;
	}
};


struct TwoPositions
{
	Position source, dest;
	TwoPositions(Position s, Position d) :source(s), dest(d) {}
};

template <class T>
struct StackNode
{
	T data;
	StackNode* next;
	StackNode(T p, StackNode* n) :data(p), next(n) {}
};

template <class T>
class Stack
{
private:
	StackNode<T>* first;

public:

	Stack() :first(NULL) {}
	Stack(const Stack& s) { copy(s); }
	Stack& operator = (const Stack& s)
	{
		if (this != &s)
		{
			clear();
			copy(s);
		}

		return *this;
	}
	~Stack()
	{
		clear();
	}

	void push(const T& p)
	{
		first = new StackNode<T>(p, first);
	}

	T pop()
	{
		T result = first->data;
		StackNode<T>* tmp = first->next;

		delete first;
		first = tmp;

		return result;
	}

	T peek()
	{
		return first->data;
	}

	bool empty()
	{
		return first == NULL;
	}

	void print()
	{
		StackNode* tmp = first;
		while (tmp)
		{
			tmp->data.print();
			tmp = tmp->next;
		}
	}

private:
	void clear()
	{
		StackNode<T>* tmp;
		while (first)
		{
			tmp = first->next;
			delete first;
			first = tmp;
		}
	}

	void copyHelper(StackNode<T>* current)
	{
		if (current == NULL)
			return;

		copyHelper(current->next);
		push(current->data);
	}

	void copy(const Stack& s)
	{

		first = NULL;

		copyHelper(s.first);

	}
};

void traceBack(Stack<TwoPositions> steps, Position current)
{
	if (steps.empty())
		return;

	TwoPositions step = steps.pop();

	if (step.dest == current)
	{
		step.source.print();
		traceBack(steps, step.source);
	}
	else {
		traceBack(steps, current);
	}

}

bool wayiter(int startx, int starty, int endx, int endy)
{

	Stack<Position> nodes;
	Stack<TwoPositions> steps;

	nodes.push(Position(startx, starty));

	while (!nodes.empty() &&
		(nodes.peek().x != endx ||
			nodes.peek().y != endy))
	{

		Position top = nodes.pop();

		if (top.correct() && top.accessible())
		{

			nodes.push(top.right());
			steps.push(TwoPositions(top, top.right()));

			nodes.push(top.down());
			steps.push(TwoPositions(top, top.down()));

			nodes.push(top.left());
			steps.push(TwoPositions(top, top.left()));

			nodes.push(top.up());
			steps.push(TwoPositions(top, top.up()));

		}

		if (top.correct())
			top.visit();

	}

	traceBack(steps, Position(endx, endy));

	return !nodes.empty();

}

void main()
{
	cout << wayiter(0, 0, 4, 4) << endl;


	
}