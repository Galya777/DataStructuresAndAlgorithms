template <class T>
struct elem
{T inf;
 elem* link;
};
template <class T>
class stack
{public:
  stack();
  ~stack();
  stack(stack const &);
  stack& operator=(stack const & r);
  void push(T const&);
  int  pop(T & x);
  bool empty() const;
  void Print();
 private:
  elem<T> *start; 
  void delstack();
  void copy(stack const&);
};
template <class T>
stack<T>::stack() 
{start = NULL;
} 
template <class T>
stack<T>::~stack()
{delstack();
}
template <class T>
stack<T>::stack(stack<T> const & r)
{copy(r);
}
template <class T>
stack<T>& stack<T>::operator=(stack<T> const& r)
{if (this != &r)
{delstack();
 copy(r);
}
return *this;
}
template <class T>
void stack<T>::delstack()
{elem<T> *p;
 while (start)
 {p = start;
  start = start->link;
  delete p;
 }
}
template <class T>
void stack<T>::copy(stack<T> const & r)
{if (r.start)
{elem<T> *p = r.start, *q = NULL, *s=NULL;
 start = new elem<T>;
 start->inf = p->inf;
 start->link = q;
 q = start;
 p = p->link;
 while (p)
 {s = new elem<T>;
  s->inf = p->inf;
  q->link = s;
  q = s;
  p = p->link;
 }
 q->link = NULL;
}
else start = NULL;
}
template <class T>
void stack<T>::push(T const& s)
{elem<T> *p = start;
 start = new elem<T>;
 start->inf = s;
 start->link = p;
}
template <class T>
int stack<T>::pop(T & s)
{if (start)
 {s = start->inf;
  elem<T> *p= start;
  start = start->link;
  delete p;
  return 1;
 }
 else return 0;
}
template <class T>
void stack<T>::Print()
{T x;
 while (pop(x))
   cout << x << " ";
 cout << endl;
}
template <class T>
bool stack<T>::empty() const
{return start == NULL;
}
