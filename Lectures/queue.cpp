template <class T>
struct q_elem
{T inf;
 q_elem<T>* link;
};
template <class T>
class queue
{public:
  queue();
  ~queue();
  queue(queue const &);
  queue& operator=(queue const &);
  void InsertElem(T const&);
  int DeleteElem(T &);
  bool empty() const;
  void print();
 private:
  q_elem<T> *front, *rear;
  void delqueue();
  void copy(queue const&);
};
template <class T>
queue<T>::queue() 
{front = NULL;
 rear = NULL;
} 
template <class T>
queue<T>::~queue()
{delqueue();
}
template <class T>
queue<T>::queue(queue const & r)
{copy(r);
}
template <class T>
queue<T>& queue<T>::operator=(queue const& r)
{if (this != &r)
{delqueue();
 copy(r);
}
return *this;
}
template <class T>
void queue<T>::delqueue()
{T x;
 while(DeleteElem(x));
}
template <class T>
void queue<T>::copy(queue const & r)
{rear = NULL;
 if (r.rear)
 {q_elem<T> *p = r.front;
  while (p)
  {InsertElem(p->inf);
   p = p->link;
  }
 }
}
template <class T>
void queue<T>::InsertElem(T const& x)
{q_elem<T> *p = new q_elem<T>;
 p->inf = x;
 p->link = NULL;
 if (rear) rear->link = p; else front = p;
 rear = p;
}
template <class T>
int queue<T>::DeleteElem(T & x)
{q_elem<T> *p;
 if (!rear) return 0;
 p = front;
 x = p->inf;
 if (p==rear) 
 {rear = NULL; front = NULL;}
 else front = p->link;
 delete p;
 return 1;
}
template <class T>
void queue<T>::print()
{T x;
 while (DeleteElem(x))
   cout << x << " ";
 cout << endl;
}
template <class T>
bool queue<T>::empty() const
{return rear == NULL;
}	
