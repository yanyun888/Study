#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print (vector<int> const& vi) {
	for (vector<int>::const_iterator it =
		vi.begin (); it != vi.end (); ++it)
		cout << *it << ' ';
	cout << endl;
}
void rprint (vector<int> const& vi) {
	for (vector<int>::const_reverse_iterator it =
		vi.rbegin (); it != vi.rend (); ++it)
		cout << *it << ' ';
	cout << endl;
}
template<typename T>
void remove (vector<T>& vec, T const& key) {
	for (typename vector<T>::iterator it =
		vec.begin (); (it = find (it, vec.end (),
		key)) != vec.end (); it = vec.erase (it));
}
int main (void) {
	vector<int> vi;
	vi.push_back (10);
	vi.push_back (20);
	vi.push_back (30); // 300
	vi.push_back (40);
	vi.push_back (50);
	print (vi);
//	vi[2] *= 10;
//	vector<int>::iterator it = vi.begin ();
//	*++++it *= 10;
//	*(it += 2) *= 10;
//	*(vi.begin () + 2) *= 10;
	*(vi.end () - 3) *= 10;
	print (vi);
	vector<int>::iterator it1 = vi.begin (),
		it2 = it1;
	it2 += 2;
	cout << *it1 << ' ' << *it2 << endl; // 10 300
	// 前<后
	cout << boolalpha << (it1 < it2) << endl;
	// true
	cout << it1 - it2 << endl; // -2
	rprint (vi);
	vector<int>::reverse_iterator it3 =
		vi.rbegin (), it4 = it3;
	it4 += 2;
	cout << *it3 << ' ' << *it4 << endl; // 50 300
	cout << (it3 < it4) << endl; // true
	cout << it3 - it4 << endl; // -2
	vector<int> vn;
	vn.push_back (100);
	vector<int>::const_iterator it = vn.begin ();
	cout << *it << endl; // 100
	vn[0] = 200;
//	*it = 200;
	cout << *it << endl; // 200
	vn.push_back (300);
	it = vn.begin ();
	cout << *it << endl; // ?
	print (vn); // 200 300
	vector<int>::iterator loc = vn.end () - 1;
	for (int i = 0; i < 9; ++i) {
		loc = vn.insert (loc, 200 + (i + 1) * 10);
		++loc;
	}
	print (vn);
	loc = vn.begin ();
	while (loc != vn.end ()) {
		if (*loc / 10 % 2)
			loc = vn.erase (loc);
		else
			++loc;
	}
	print (vn);
	vn.clear ();
	int arr[] ={10, 20, 10, 30, 40, 10, 10, 20, 50};
	vn = vector<int> (arr, arr + sizeof (arr) /
		sizeof (arr[0]));
	print (vn);
	remove (vn, 10);
	print (vn); // 20 30 40 20 50
	loc = find (vn.begin (), vn.end (), 20);
	cout << *loc << ' ' << *(loc+1) << endl;
	// 20 30
	loc = find (vn.begin () + 1, vn.end (), 20);
	cout << *loc << ' ' << *(loc+1) << endl;
	// 20 50
	return 0;
}
