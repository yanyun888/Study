#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<typename IT>
void print (IT begin, IT end) {
	while (begin != end)
		cout << *begin++ << ' ';
	cout << endl;
}
class Student {
public:
	Student (string const& name, int age) :
		m_name (name), m_age (age) {}
	bool operator< (Student const& rhs) const {
		return m_name < rhs.m_name;
	}
	friend ostream& operator<< (ostream& os,
		Student const& student) {
		return os << '(' << student.m_name << ','
			<< student.m_age << ')';
	}
private:
	string m_name;
	int m_age;
	friend bool cmpStuByName (Student const&,
		Student const&);
	friend class CmpStuByName;
};
bool cmpStuByName (Student const& sx,
	Student const& sy) {
	if (sx.m_name == sy.m_name)
		return sy.m_age < sx.m_age;
	return sx.m_name < sy.m_name;
}
class CmpStuByName {
public:
	CmpStuByName (bool raise = true) :
		m_raise (raise) {}
	bool operator() (Student const& sx,
		Student const& sy) {
		if (m_raise)
			return sx.m_name < sy.m_name;
		return sy.m_name < sx.m_name;
	}
private:
	bool m_raise;
};
int main (void) {
	vector<int> v1;
	v1.push_back (24);
	v1.push_back (39);
	v1.push_back (17);
	v1.push_back (22);
	v1.push_back (39);
	v1.push_back (24);
	v1.push_back (17);
	v1.push_back (66);
	v1.push_back (11);
	print (v1.begin (), v1.end ());
	sort (v1.begin (), v1.end ());
	print (v1.begin (), v1.end ());
	sort (v1.rbegin (), v1.rend ());
	print (v1.begin (), v1.end ());
	vector<Student> v2;
	v2.push_back (Student ("zhangfei", 22));
	v2.push_back (Student ("zhaoyun", 23));
	v2.push_back (Student ("zhangfei", 25));
	v2.push_back (Student ("guanyu", 40));
	v2.push_back (Student ("zhangfei", 17));
	print (v2.begin (), v2.end ());
//	sort (v2.begin (), v2.end ());
	sort (v2.begin (), v2.end (), cmpStuByName);
//	sort (v2.begin (), v2.end (), CmpStuByName ());
	print (v2.begin (), v2.end ());
	sort (v2.begin (), v2.end (),
		CmpStuByName (false));
	print (v2.begin (), v2.end ());
	return 0;
}
