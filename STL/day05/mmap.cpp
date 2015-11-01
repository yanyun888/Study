#include <iostream>
#include <map>
using namespace std;
int main (void) {
	multimap<string, int> msi;
	msi.insert (make_pair ("张飞", 100));
	msi.insert (make_pair ("赵云", 80));
	msi.insert (make_pair ("关羽", 90));
	msi.insert (make_pair ("张飞", 70));
	msi.insert (make_pair ("赵云", 90));
	msi.insert (make_pair ("关羽", 50));
	msi.insert (make_pair ("张飞", 85));
	msi.insert (make_pair ("赵云", 60));
	msi.insert (make_pair ("关羽", 100));
	typedef multimap<string, int>::iterator IT;
	for (IT it = msi.begin (); it != msi.end ();
		++it)
		cout << it->first << " : " << it->second
			<< endl;
	cout << "每个同学的各科总分：" << endl;
	for (IT it = msi.begin (); it != msi.end ();
		++it) {
		string key = it->first;
		IT end = msi.upper_bound (key);
		int sum = 0;
		for (; it != end; ++it)
			sum += it->second;
		cout << key << " - " << sum << endl;
		--it;
	}
	return 0;
}
