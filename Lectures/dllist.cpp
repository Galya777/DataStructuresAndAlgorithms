template <class T>
struct elem_link2
{T inf;
 elem_link2<T> *pred,
	      *succ;
};
template <class T>
class DLList
{public:
 DLList();
 ~DLList();
 DLList(DLList const&);
 DLList& operator=(DLList const &);
 void print();
 void print_reverse();
 void IterStart(elem_link2<T>* = NULL);
 void IterEnd(elem_link2<T>* = NULL);
 elem_link2<T>* IterSucc();
 elem_link2<T>* IterPred();
 void ToEnd(T const &);
 void DeleteElem(elem_link2<T> *, T &);
 int length();
 private:
 elem_link2<T> *Start, 
	    		*End,	
				      *CurrentS,
	         *CurrentE;
 void DeleteList();
 void CopyList(DLList const &);
};
template <class T>
DLList<T>::DLList()
{Start = NULL;
 End = NULL;
}
template <class T>
DLList<T>::~DLList()
{DeleteList();
}
template <class T>
DLList<T>::DLList(DLList<T> const& r)
{CopyList(r);
}
template <class T>
DLList<T>& DLList<T>::operator=(DLList<T> const & r)
{if (this != &r)
 {DeleteList();
  CopyList(r);
 }
 return *this;
}
template <class T>
void DLList<T>::DeleteList()
{elem_link2<T> *p = Start;
 while (p)
 {Start = Start->succ;
  delete p;
  p = Start;
 }
 End = NULL;
}
template <class T>
void DLList<T>::CopyList(DLList<T> const & r)
{Start = End = NULL;
 if (r.Start)
 {elem_link2<T> *p = r.Start;
  while (p)
  {ToEnd(p->inf);
   p = p->succ;
  }
 }
}
template <class T>	
void DLList<T>::print()
{elem_link2<T> *p = Start;
 while (p)
 {cout << p->inf << " ";
  p = p->succ;
 }
 cout << endl;
}
template <class T>
void DLList<T>::IterStart(elem_link2<T> *p)
{if (p) CurrentS = p;
 else CurrentS = Start;
}
template <class T>
	void DLList<T>::IterEnd(elem_link2<T> *p)
{if (p) CurrentE = p;
 else CurrentE = End;
}
template <class T>
elem_link2<T>* DLList<T>::IterSucc()
{elem_link2<T> *p = CurrentS;
 if (CurrentS) CurrentS = CurrentS->succ;
 return p;
}
template <class T>
elem_link2<T>* DLList<T>::IterPred()
{elem_link2<T> *p = CurrentE;
 if (CurrentE) CurrentE = CurrentE->pred;
 return p;
}
template <class T>
void DLList<T>::ToEnd(T const & x)
{elem_link2<T>* p = End;
 End = new elem_link2<T>;
 End->inf = x;
 End->succ = NULL;
 if (p) p->succ = End;
 else Start = End;
 End->pred = p;
}
template <class T>
void DLList<T>::DeleteElem(elem_link2<T> *p, T &x)
{x = p->inf;
 if (Strat == End)
 {Start = End = NULL;
 }
 else 
 if (p == Start)
 {Start = Start->succ;
  Start->pred = NULL;
 }
 else
 if (p == End)
 {End = p->pred;
  End->succ = NULL;
 }
 else
 {p->pred->succ = p->succ;
  p->succ->pred = p->pred;
 }
 delete p;
}
template <class T>
int DLList<T>::length()
{int n = 0;
 elem_link2<T> *p = Start;
 while (p)
 {n++;
  p = p->succ;
 }
 return n;
}
