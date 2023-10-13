template <class T>
struct elem_cir
{T inf;
 elem_cir<T> *link;
};
template <class T>
class CirList
{public:
 CirList();
 ~CirList();
 CirList(CirList &);
 CirList& operator=(CirList &);
 void print();
 void IterStart(elem_cir<T>* = NULL);
 elem_cir<T>* Iter();
 void ToEnd(T &);
 void Insert(T &);
 void DeleteElem(elem_cir<T>*, T &);
 private:
 elem_cir<T> *Start, 
	      	 *Current;
 void DeleteList();
 void CopyList(CirList &);
};
template <class T>
CirList<T>::CirList()
{Start = NULL;
}
template <class T>
CirList<T>::~CirList()
{DeleteList();
}
template <class T>
CirList<T>::CirList(CirList<T> & r)
{CopyList(r);
}
template <class T>
CirList<T>& CirList<T>::operator=(CirList<T> & r)
{if (this != &r)
 {DeleteList();
  CopyList(r);
 }
 return *this;
}
template <class T>
void CirList<T>::IterStart(elem_cir<T> *p)
{if (p) Current = p;
 else 
 if (!Start) Current = NULL;
 else Current = Start->link;
}
template <class T>
elem_cir<T>* CirList<T>::Iter()
{if (!Current) return NULL;
 elem_cir<T> *p = Current;
 if (Current == Start) Current = NULL;
  else Current = Current->link;
  return p;
 }
template <class T>
void CirList<T>::DeleteList()
{IterStart();
 elem_cir<T> *p = Iter();
 while (p) 
 {delete p; 
  p = Iter();
 }
}
template <class T>
void CirList<T>::CopyList(CirList & r)
{Start = NULL;
 r.IterStart();
 elem_cir<T> *p = r.Iter();
 while (p)
 {ToEnd(p->inf);
  p = r.Iter();
 }
}
template <class T>
void CirList<T>::Insert(T & x)
{elem_cir<T> *p = new elem_cir<T>;
 p->inf = x;
 if (Start) p->link = Start->link;
 else Start = p;
 Start->link = p;
}
template <class T>
void CirList<T>::ToEnd(T & x)
{Insert(x);
 Start = Start->link;
}
template <class T>
void CirList<T>::DeleteElem(elem_cir<T>* p, T & x)
{x = p->inf;
 if (Start != Start->link)
 {elem_cir<T> *q = Start;
  while (q->link != p) q = q->link;
  q->link = p->link; 
  if (p == Start) Start = q;
  delete p;
 }
 else
 {Start = NULL;
  delete p;
 }
}
template <class T>
void CirList<T>::print()
{IterStart();
 elem_cir<T> *p = Iter();
 while (p)
 {cout << p->inf << " ";
  p = Iter();
 }
 cout << endl;
}
