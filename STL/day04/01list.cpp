/*File Name: 01list.cpp
**Author: 
**Version: 
**Created Time: 15/10/09-09:45  */

//双向线性链表容器，迭代器和泛型算法

 
#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

//链表类模板
template<typename T>
class List{
public:
	List(void):m_head(NULL),m_tail(NULL){}
	~List(void){
		clear();
	}
	List(List const& that):m_head(NULL),m_tail(NULL){
		for(Node* node = that.m_head; node ;node = node->m_next)
			push_back(node->m_data);
	}
	List& operator = (List const& rhs){
		if( &rhs !=  this){
			List list = rhs;
			swap(m_head, list.m_head);
			swap(m_tail, list.m_tail);
			//交换指针，完成深拷贝，原对象的析构
		}
		return *this;
	}
	
	//
	T& front (void){
		if(empty () == true)
			throw underflow_error("链表下溢！");
		return m_head->m_data;
	} 
	T const& front (void) const{
		return const_cast<List*>(this)->front();
	}
	//
	void push_front(T const& data){
		m_head = new Node(data,NULL,m_head);
		//new 如果没有成功分配会抛出异常
		if (m_head->m_next)
			m_head->m_next->m_prev = m_head;
		else
			m_tail = m_head;
	}
	void pop_front(void){
		if(empty())
			throw underflow_error("链表下溢!");
		Node* next = m_head->m_next;
		delete m_head;
		m_head = next;
		if (m_head) 
			m_head->m_prev = NULL;
		else //如果是最后一个结点
			m_tail = NULL;
	}

	T& back(void){
		if(empty())
			throw underflow_error("链表下溢！");
		return m_tail->m_data;
	}
	T const& back (void) const{
		return const_cast<List*>(this)->back();
	}

	void push_back(T const& data){
		m_tail = new Node(data,m_tail);
		if(m_tail->m_prev)
			m_tail->m_prev->m_next = m_tail;
		else
			m_head = m_tail;
	}
	void pop_back(void){
		if(empty())
			throw underflow_error("链表下溢！");
		Node* prev = m_tail->m_prev;
		delete m_tail;
		m_tail = prev;
		if(m_tail)
			m_tail->m_next = NULL;
		else
			m_head = NULL;
	}
	//删除所有匹配元素
	void remove (T const& data){
		for(Node* node = m_head,*next;node;node = node->m_next){
			next = node->m_next;
			if(equal(node->m_data,data)){
				if(node->m_prev)
					node->m_prev->m_next = node->m_next;
				else
					m_head = node->m_next;
				if(node->m_next)
					node->m_next->m_prev = node->m_prev;
				else
					m_tail = node->m_prev;
				delete node;
			}
		}
	}


	//清空容器
	void clear (void){
		while(!empty())
			pop_front();
	}
	//判空
	bool empty (void) const{
		return !m_head && !m_tail;
	}

	size_t size(void) const{
		size_t nodes = 0;
		for(Node* node = m_head;node;node=node->m_next)
			++nodes;
		return nodes;
	}
	friend ostream& operator<< (ostream& os,List const& list){
		for(Node* node = list.m_head;node;node = node->m_next)
			os << *node;
		return os;
	}

	//随机访问
	T& operator[] (size_t i) {
		for(Node* node = m_head;node;node = node->m_next)
			if(! i--)
				return node->m_data;
		throw out_of_range("下标越界！");
	}
	T const& operator[] (size_t i) const{
		return const_cast<List&>(*this)[i];
	}
private:
	//元素比较函数的通用版本
	bool equal(T const& a,T const& b) const{
		return a==b;
	}
	class Node{
	public:
		Node(T const& data,Node* prev = NULL,Node* next = NULL):
			m_data(data),m_prev(prev),m_next(next){}
		friend ostream& operator<< (ostream& os,Node const& node){
			return os << '(' << node.m_data << ')';
		}
		T m_data;
		Node* m_prev;
		Node* m_next;
	};

	Node* m_head;
	Node* m_tail;
public:
	//正向迭代器
	class Iterator {
	public:
		Iterator(Node* head = NULL,Node* tail = NULL,Node* node = NULL):
			m_head(head),m_tail(tail),m_node(node){}
		bool operator== (Iterator const& rhs) const{
			return m_node == rhs.m_node;
		}
		bool operator!= (Iterator const& rhs) const{
			return ! (*this == rhs);
		}
		Iterator& operator++(void){
			if(m_node)
				m_node = m_node->m_next;
			else
				m_node = m_head;
			return *this;
		}
		Iterator const operator++(int){
			Iterator old = *this;
			++ *this;
			return old;
		}
		Iterator& operator--(void){
			if(m_node)
				m_node = m_node->m_prev;
			else
				m_node = m_tail;
			return *this;
		}
		Iterator const operator-- (int){
			Iterator old = *this;
			-- *this;
			return old;
		}
		T& operator* (void) const{
			return m_node->m_data;
		}
		T* operator-> (void) const{
			return &**this; //?
		}

	private:
		Node* m_node;
		Node* m_tail;
		Node* m_head;
		friend class List;
	};
	//获取其实正向迭代器(指向首元素)
	Iterator begin(void){
		return Iterator(m_head,m_tail,m_head);
	}
	//获取终止正向迭代器(指向尾元素之后)
	Iterator end(void){
		return Iterator(m_head,m_tail);
	}
	//在指定迭代器之前插入,同时返回指向新插入元素的迭代器材
	Iterator insert(Iterator loc,T const& data){
		if(loc == end()){
			push_back (data);
			return Iterator(m_head,m_tail,m_tail);
		}
		else{
			Node* node = new Node(data,loc.m_node->m_prev,loc.m_node);
			if(node->m_prev)
				node->m_prev->m_next = node;
			else
				m_head = node;
			node->m_next->m_prev = node;
			return Iterator(m_head,m_tail,node);
		}

	}
	//删除指定迭代器位置的元素
	//同时返回指向 被删元素的下一个元素 的迭代器
	Iterator erase(Iterator loc){
		if(loc == end())
			throw invalid_argument("无效参数！");
		if(loc.m_node->m_prev)
			loc.m_node->m_prev->m_next = loc.m_node->m_next;
		else
			m_head = loc.m_node->m_next;
		if(loc.m_node->m_next)
			loc.m_node->m_next->m_prev = loc.m_node->m_prev;
		else
			m_tail = loc.m_node -> m_prev;
		Node* next = loc.m_node->m_next;
		delete loc.m_node;
		return Iterator(m_head,m_tail,next);
	}
	//常正向迭代器(相当于一个常量指针--目标只读)
	//反向迭代器(rbegin/rend)
	//常反向迭代器
};

template<>
bool List<char const*>::equal(char const* const& a,char const* const& b) const{
	return !strcmp(a,b);
}

//线性查找
int* find (int* begin,int* end,int key){
	int* it;
	for(it = begin; it != end ; ++it){
		if(*it == key)
			break;
	}
	return it;
}

template<typename IT,typename KEY>
IT find(IT begin,IT end, KEY const& key){
	IT it;
	for(it = begin; it != end; ++it)
		if(*it == key)
			break;
	return it;
}





//测试用例
void test1(void){
	List<int> l1;
	l1.push_front(30);
	l1.push_front(20);
	l1.push_front(10);
	cout << l1 << endl;
	++ l1.front();
	cout << l1 << endl;

}

void test2(void){
	
	char sa[][32] = {"北京","天津","北京","天津","上海","重庆"};
	

	/*
	char const* sa[] = {"北京","天津","北京","天津","上海","重庆"};
*/
	List<string> ls;
	for(size_t i=0;i<sizeof(sa)/sizeof(sa[0]);++i)
		ls.push_back(sa[i]);
	cout << ls << endl;
	ls.remove("北京");
	cout << ls << endl;
	cout << "----------------" << endl;

	List<char const*> lp;
	for(size_t i=0; i<sizeof(sa)/sizeof(sa[0]);++i)
		lp.push_back(sa[i]);
	cout << lp << endl;
	lp.remove("北京");
	cout << lp << endl;
}


void test3(void){
	List<int> l1;
	for(int i=1;i<10;++i)
		l1.push_back(i);
	cout << l1 << endl;
	size_t size = l1.size();

	/*这样的效率不高
	for(size_t i=0;i<size;++i)
		l1[i] *= l1[i];
	cout << l1 << endl;
	*/

	//这样效率高一些
	for(List<int>::Iterator it = l1.begin();it != l1.end() ; ++it)
		*it *= *it;
	cout << l1 << endl;
	List<int>::Iterator it = l1.begin();
	* ++++++++it = 0;
	cout << l1 <<endl;

}

void test4(void){
	List<int> l1;
	l1.insert(
		l1.insert( 
			l1.insert(l1.end(),50),40),30);
	cout << l1 << endl;
	List<int>::Iterator loc = l1.begin();
	l1.insert(++loc,35);
	cout << l1 << endl;
	loc = l1.end();
	l1.insert(loc,45);
	cout << l1 << endl;
	l1.erase(l1.erase(l1.erase(++loc)));
	cout << l1 << endl;
}

void test5(void){
	int ai[] = {13,27,19,34,48};
	int* pi = find(ai,ai+5,29);
	if(pi == ai+5)
		cout << "没找到" << endl;
	else
		cout << "找到了" << *pi <<endl;
	List<string> ls;
	ls.push_back("济南");
	ls.push_back("青岛");
	ls.push_back("菏泽");
	ls.push_back("潍坊");
	ls.push_back("临沂");

	List<string>::Iterator it = find(ls.begin(),ls.end(),"菏泽");
	if(it == ls.end())
		cout << "没找到" << endl;
	else
		cout << "找到了" << *it <<endl;

}


int main(void){

//	test1();
//	test2();
//	test3();
//	test4();
	test5();
	return 0;
}





