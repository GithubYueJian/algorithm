/*
* Purpose: Link functions
* Author: Jian Yue
* Data:   2020/08/23,revised 2020/09/10,2022/04/02
* Refrence: ***
*/


#include<iostream>
#include<vector>
using namespace std;

//链表以及其基本成员函数
//链表中最重要的是指针，又叫指针变量。指针变量是变量，里面的地址是可以改变的
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    void display();
    static ListNode* create(vector<int> nums);
    ListNode* findNode(int value);
    void insertAfter(int value, int newValue);
    void append(int value);
    void prepend(int value);
    void remove(int value);
    void removeHead();
    void removeTail();
};

typedef ListNode* node;

//显示链表中所有元素，不显示头节点中无用元素
void ListNode::display()
{
    ListNode* currentNode = this->next;
    if (!currentNode)
        cout << "this is a nullptr";

    while (currentNode)
    {
        cout << currentNode->val << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
    return;
}

//通过数组建立一个链表，具有头节点
node ListNode::create(vector<int> nums)
{
    node head = new ListNode(0);
    node currentNode = head;
    for (auto num : nums)
    {
        node newNode = new ListNode(num);
        currentNode->next = newNode;
        currentNode = currentNode->next;
    }
    return head;
}

//寻找链表中的节点
node ListNode::findNode(int value)
{
    node currentNode = this->next;
    while (currentNode->val != value)
    {
        currentNode = currentNode->next;
        if (!currentNode)
            return nullptr;
    }
    node newHead = new ListNode(0);
    newHead->next = currentNode;
    return newHead;
}

//在原链表某个节点后插入一个节点
void ListNode::insertAfter(int value, int newValue)
{
    const node newNode = new ListNode(newValue);
    const node currentNode = this->findNode(value)->next;
    if (!currentNode)
        cout <<"\""<< value <<"\""<<" not in list,can not do insertAfter operation!" << endl;
    else
    {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
    return ;
}

//在尾部追加节点
void ListNode::append(int value)
{
    const node newNode = new ListNode(value);
    node currentNode = this->next;
    while (currentNode->next)
        currentNode = currentNode->next;
    currentNode->next = newNode;
    return ;
}

//在头部追加节点
void ListNode::prepend(int value)
{
    const node newNode = new ListNode(value);
    node currentNode = this->next;
    this->next = newNode;
    newNode->next = currentNode;
    return ;
}
//删除指定节点
void ListNode::remove(int value)
{
    node currentNode = this->next;
    node previousNode = nullptr;
    while (currentNode->val != value)
    {
        if (currentNode->next == nullptr)
        {
            cout << "\" " << value << "\" not in list\n";
            return ;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = currentNode->next;
    return ;
}

//删除首节点
void ListNode::removeHead()
{
    this->next = this->next->next;
    return ;
}
//删除尾节点
void ListNode::removeTail()
{
    node currentNode = this->next;
    node previousNode = nullptr;
    while (currentNode->next)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = nullptr;
    return;
}



int main()
{

    // fuctions testing
    node l1 = ListNode::create({ 1,2,3,4});
    cout << "l1: ";
    l1->display();

    l1->append(5);
    cout << "l1 append(5): ";
    l1->display();

    node l2 = l1->findNode(2);
    cout << "l2 = l1 findNode(2): ";
    cout << "\nl1: ";
    l1->display();
    cout << "l2: ";
    l2->display();

    l1->insertAfter(3, 30);
    cout << "l1->insertAfter(3, 30): ";
    l1->display();

    l1->prepend(0);
    cout << "l1->prepend(0): ";
    l1->display();

    l1->remove(4);
    cout << "l1->remove(4): ";
    l1->display();

    l1->removeHead();
    cout << "l1->removeHead(): ";
    l1->display();

    l1->removeTail();
    cout << "l1->removeTail(): ";
    l1->display();



  

    return 0;
}


/*
l1: 1 2 3 4
l1 append(5): 1 2 3 4 5
l2 = l1 findNode(2):
l1: 1 2 3 4 5
l2: 2 3 4 5
l1->insertAfter(3, 30): 1 2 3 30 4 5
l1->prepend(0): 0 1 2 3 30 4 5
l1->remove(4): 0 1 2 3 30 5
l1->removeHead(): 1 2 3 30 5
l1->removeTail(): 1 2 3 30
*/
