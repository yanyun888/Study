#include <iostream>
#include <map>
using namespace std;
class Candidate {
public:
	Candidate (string const& name = "") :
		m_name (name), m_votes (0) {}
	string const& name (void) const {
		return m_name;
	}
	int votes (void) const {
		return m_votes;
	}
	void vote (void) {
		++m_votes;
	}
private:
	string m_name;
	int m_votes;
};
int main (void) {
	map<char, Candidate> mcc;
	mcc.insert (
		pair<char, Candidate> ('A',
			Candidate ("张飞")));
	mcc.insert (
		make_pair ('B', Candidate ("赵云")));
	mcc['C'] = Candidate ("关羽");
	mcc['D'] = Candidate ("刘备");
	mcc['E'] = Candidate ("曹操");
	typedef map<char, Candidate>::iterator IT;
	pair<IT, bool> res = mcc.insert (
		make_pair ('F', Candidate ("黄忠")));
	if (! res.second)
		cout << "插入失败！" << endl;
	else
		cout << "插入成功："
			<< res.first->second.name () << endl;
	mcc['B'] = Candidate ("马超");
	for (int i = 0; i < 10; ++i) {
		for (IT it = mcc.begin (); it != mcc.end ();
			++it)
			cout << '(' << it->first << ") "
				<< it->second.name () << ' ';
		cout << endl << "请投票：" << flush;
		char key;
		cin >> key;
		IT it = mcc.find (key); // O(logN)
		if (it == mcc.end ()) {
			cout << "废票！" << endl;
			continue;
		}
		it->second.vote ();
	}
	IT win = mcc.begin ();
	for (IT it = mcc.begin (); it != mcc.end ();
		++it) {
		cout << it->second.name () << "获得"
			<< it->second.votes () << "票。" <<endl;
		if (it->second.votes () >
			win->second.votes ())
			win = it;
	}
	cout << "热烈祝贺" << win->second.name ()
		<< "同学成功当选首席保洁员！" << endl;
	return 0;
}
