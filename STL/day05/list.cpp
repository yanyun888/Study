#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
template<typename T>
ostream& operator<< (ostream& os, list<T> const& l){
	for (typename list<T>::const_iterator it =
		l.begin (); it != l.end (); ++it)
		os << *it << ' ';
	return os;
}
void square (int& i) {
	i *= i;
}
class IntCmp {
public:
	bool operator() (int const& a,
		int const& b) const {
		return a > b;
	}
};
int main (void) {
	int ai[] ={10,10,10,20,10,10,20,20,30,30,40,30};
	list<int> li (ai, ai + sizeof (ai) /
		sizeof (ai[0]));
	cout << li << endl;
	for_each (li.begin (), li.end (), square);
	cout << li << endl;
	li.sort (IntCmp ());
	cout << li << endl;
	li.unique ();
	cout << li << endl;
	list<int> l1, l2;
	l1.push_back (10);
	l1.push_back (20);
	l1.push_back (30);
	l2.push_back (7000);
	l2.push_back (8000);
	l2.push_back (9000);
	cout << "l1: " << l1 << endl;
	cout << "l2: " << l2 << endl;
	list<int>::iterator pos = l1.begin ();
	++pos;
	/*
	l1.splice (pos, l2);
	*//*
	list<int>::iterator del = l2.begin ();
	++del;
	l1.splice (pos, l2, del);
	*/
	list<int>::iterator begin = l2.begin (),
		end = l2.end ();
	--end;
	l1.splice (pos, l2, begin, end);
	cout << "l1: " << l1 << endl;
	cout << "l2: " << l2 << endl;
	list<int> l3, l4;
	l3.push_back (10);
	l3.push_back (50);
	l3.push_back (60);
	l3.push_back (80);
	l3.push_back (90);
	l3.sort (IntCmp ());
	l4.push_back (20);
	l4.push_back (40);
	l4.push_back (70);
	l4.sort (IntCmp ());
	cout << "l3: " << l3 << endl;
	cout << "l4: " << l4 << endl;
	l3.merge (l4, IntCmp ());
	cout << "l3: " << l3 << endl;
	cout << "l4: " << l4 << endl;
	return 0;
}
