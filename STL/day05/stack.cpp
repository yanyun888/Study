#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <list>
using namespace std;
template<typename T, typename C = deque<T> >
class Stack {
public:
	void push (T const& data) {
		m_c.push_back (data);
	}
	void pop (void) {
		m_c.pop_back ();
	}
	T& top (void) {
		return m_c.back ();
	}
	T const& top (void) const {
		return m_c.back ();
	}
	void clear (void) {
		m_c.clear ();
	}
	size_t size (void) const {
		return m_c.size ();
	}
	bool empty (void) const {
		return m_c.empty ();
	}
private:
	C m_c;
};
int main (void) {
//	stack<string, vector<string> > ss;
//	Stack<string, vector<string> > ss;
//	Stack<string, list<string> > ss;
	Stack<string> ss;
	ss.push ("C++!");
	ss.push ("喜欢");
	ss.push ("我们");
	while (! ss.empty ()) {
		cout << ss.top () << flush;
		ss.pop ();
	}
	cout << endl;
	return 0;
}
