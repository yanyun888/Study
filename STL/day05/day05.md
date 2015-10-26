


##
3. 迭代器
1) 随机迭代器：除了顺序迭代器所提供的功能接口以外，还提供和整数加减、同类型迭代器之间大小比较，以及同类型
只有连续内存的容器，比如向量和双端队列才会提供随机迭代器，其他容器都只提供顺序迭代器。

向量和双端队列的单端开放特性
2)反向迭代器：以尾端为前，以首端为后。起始位置在尾元素，终止元素在首元素。
rbegin/rend 获取反向迭代器的方法。
使用反向迭代器也要++it;

对迭代器比较大小，比的是谁更靠前

3)有四个迭代器类型/八个迭代器函数
```
iterator
const_iterator
reverse_iterator
const_reverse_iterator
```
begin() - 起始正向迭代器
begin() const - 起始常正向迭代器
end() - 终止正向迭代器
end() const - 终止常正向迭代器
rbegin() 起始反向迭代器
rbegin() const 
rend()
rend() const

4) 任何对容器结构可能造成影响的操作，比如增减元素，都可能导致原先确定的迭代器失效。
为此，在使用这些迭代器之前,应该重新定位，以保证其内部的指针指向布局变化以后的内存。

4. 常用的成员函数
```
value_type& front(void);
value_type const& front(void) const;
value_type& back(void);
value_type const& back(void) const;
void push_back(value_type const& val);
void pop_back(value_type const& val);
iterator insert(iterator loc, value_type const& val);
iterator erase(iterator loc, value_type const& val);
```
注意在增删之后迭代器可能会出现失效的问题

5. 查找和排序
`#include<algorithm>`
iterator find(iterator begin，iterator end, value_type const& key);
在[begin,end)区间内查找第一个和key匹配的的元素，成功返回该元素的迭代器，否则返回end。

void sort(iterator begin,iterator end);
使用的是快速排序方法，NlogN线性对数级
该sort函数只能适用于随机迭代器，由于排序算法需要对迭代器进行加减数字运算。


##三、双端队列(deque)
所有vector所提供的功能deque都有，同时deque增加了前端的压入和弹出接口:`push_front/pop_front`
时间和空间复杂度略高于vector

##四、列表(list)
void unique(void);
for_each( begin, end, square );
void sort(void);  // 是list中的一个成员函数，将list中的元素按照升序排列
void sort(less cmp);  // 同样可以定义一个比较函数
成员函数的sort为了提高性能是通过改变指针的方式进行复制，这样的效率更高
splice(iterator pos, list& lst);
将lst列表中的全部元素剪切到调用列表的pos之前。
splice(iterator pos, list& lst,iterator del);
将lst列表中位于del处的元素剪切到调用列表的pos之前。
splice(iterator pos, list& lst, iterator begin, iterator end);
将lst列表哦中位于begin和end之间的元素剪切到pos之间。
void merge(list& lst);
void merge(list& lst);
如果调用列表和lst里表都是有序列表，那么合并之后的列表都是有序的。
时间复杂度 O(N) 线性的

#五、堆栈(stack)
适配器容器
`push->push_back`
`pop->pop_back`
`top->back`
`clear->clear`
`size->size`
栈本身符合一种后进先出的规则的一种操作模式
底层容器：vector/deque(缺省)/list
`stack<元素类型，[底层容器类]>`

#六、队列(queue)
适配器容器
push->push_back
pop->pop_front
back->back
front->front

底层容器：deque/list

#七、优先队列(priority_queue)
容器中每个元素都有一个优先级属性；每个放入一个元素，都会按照优先级的从高到低的顺序从
高到低排序；如果优先级相同，则遵循先进先出的顺序。

缺省情况下以大者为优，同时也可以通过比较器自定义优先级。
底层容器：vector/deque(缺省)
不支持list的原因，使用了随机迭代器

__总结__
```
vector\deque\list
stack\queue\priority_queue
```

关联容器
#八、映射map
一一对应
身份证号码--个人信息
条码--商品的价格
主键--记录
以键(Key)和值(Value)所构成的对(pair)为基本元素的平衡有序二叉树
借助树的结构可以加速检索
适合于相对稳定、基本不会修改的的数据结构

平衡有序二叉树中的平衡：指的是对于任何节点的两个子树的元素个数是相等的、或仅仅相差一个元素。
映射中有一个必须条件：键必须唯一

迭代遍历实际上是一个中序遍历(LDR)-->会生成一个升序序列
搜索性能：O(logN)

```
template<typename FIRST,typename SECOND>
class pair{
public:
    pair(FIRST const& f,SECOND const& s):
    first(f),second(s){}
    FIRST first;
    SECOND second;
};
```
键->first
值->second
映射容器中的元素类型就是pair`<KEY，value>`
使用键值作为下标访问的索引

键的类型不需要提供“==”运算符，有二叉树的特点决定的。
```
if(目标key<节点key)
    在节点的左子树中继续查找;
else if(节点key<目标key)
    在节点的右子树中继续查找；
else
    该节点就是匹配节点，查找成功！
 ```


##九、多重映射(multimap)
`#include<map>`
允许键重复的映射，一对多的关系。



day 04  pm3:10




