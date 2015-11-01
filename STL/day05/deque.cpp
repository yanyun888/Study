#include <iostream>
#include <deque>
using namespace std;
template<typename IT>
void print (IT begin, IT end) {
	while (begin != end)
		cout << &*begin << ':' << *begin++ << ' ';
	cout << endl;
}
int main (void) {
	deque<string> ds;
	ds.push_front ("tarena");
	ds.push_front ("microsoft");
	ds.push_front ("ibm");
	print (ds.begin (), ds.end ());
	ds.pop_front ();
	print (ds.begin (), ds.end ());
	ds.push_back ("emc");
	ds.push_back ("oracle");
	ds.push_back ("apple");
	print (ds.begin (), ds.end ());
	ds.pop_back ();
	print (ds.begin (), ds.end ());
	cout << ds[2] << endl;
	return 0;
}
