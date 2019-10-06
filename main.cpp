//数据结构作业-链表


#include <iostream>
using namespace std;

struct link
{
    int data;
    link *next;
};

link* Init()//初始化头结点
{
    link *head = new link;
    head->data = -1;
    head->next = NULL;
    return head;
}

link *CircleLinkInit(int n)//初始化循环单链表
{
    int data;
    cin >> data;
    link *head = new link;
    head->data = data;
    head->next = NULL;
    n--;
    link *beforeP = head;
    while(n--)
    {
        cin >> data;
        link *p = new link;
        p->data = data;
        p->next = head;
        beforeP->next = p;
        beforeP = beforeP->next;
    }
    return head;
}
void RearInsert( link *const head, const int data)//尾插
{
    link *p = head;
    link *newLink = new link;
    newLink->data = data;
    newLink->next = NULL;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = newLink;
}

void FrontInsert(link *const head, const int data)//头插
{
    link *newLink = new link;
    newLink->data = data;
    newLink->next = head->next;
    head->next = newLink;
}

void const Find(link *const head, const int data)
{
    link *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        if(p->data == data)
        {
            cout<<"Find it!"<<endl;
            return ;
        }
    }
    cout<<"Not found!"<<endl;
}
int const CircleFind(link *const head, const int data, int n)
{
    int t = n;
    link *p = head;
    while(n--)
    {
        if(p->data == data)
        {
//            cout<<"Find it!"<<endl;
            return (t - n - 1);
        }
        p = p->next;
    }
//    cout<<"Not found!"<<endl;
    return -1;
}
void Delete(link *const head, const int data)
{
    link *p = head;
    link *beforePoint = NULL;
    while(p->next != NULL)
    {
        beforePoint = p;
        p = p->next;
        if(p->data == data)
        {
            beforePoint->next = p->next;
            delete p;
        }
    }
}
void CircleDelete(link *const head, int index, int n)//删除循环链表的前趋节点
{
    link *p = head;
    while(index--)
        p = p->next;
    link *beforeP = NULL;
    n--;
    while(n--)
    {
        beforeP = p;
        p = p->next;
    }
    beforeP->next = p->next;
    delete p;
}
void OrderInsert(link *const head, const int data)//在有序链表中插值
{
    link *newLink = new link;
    link *p = head;
    link *beforePoint = NULL;
    newLink->data = data;
    newLink->next = NULL;
    while(p->next != NULL)
    {
        beforePoint = p;
        p = p->next;
        if(data <= p->data)
        {
            beforePoint->next = newLink;
            newLink->next = p;
            return ;
        }
    }
    p->next = newLink;
}
link *ReverseWithHead(link * head)
{
    link *p = head;
    link *copyHead = new link;
    copyHead->data = head->data;
    copyHead->next = NULL;
    while(p->next != NULL)
    {
        p = p->next;
        FrontInsert(copyHead, p->data);
    }
    link *beforePoint = NULL;
    while(head->next != NULL)
    {
        beforePoint = head;
        head = head->next;
        delete beforePoint;
    }
    delete head;
    return copyHead;
}
void const Out(link *const head)
{
    link *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        cout << p->data << " ";
    }
    cout << endl;
}
void const OutCircle(link *const head, int n)
{
    link *p = head;
    while(n--)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout<<endl;
}
int main()
{
    int data;
    int n;
//    cout << "初始化完成"<< endl;
//    link *head = Init();
//    cout << "插入:"<< endl;
//    cin >> n;
//    while(n--)
//    {
//        cin >> data;
//        RearInsert(head, data);
////        FrontInsert(head, data);
//    }
//    Out(head);
//    cout << "查找:"<< endl;
//    cin >> data;
//    Find(head, data);
//    cout << "删除:"<< endl;
//    cin >> data;
//    Delete(head, data);
//    Out(head);
//    cout << "在有序链表中插值:"<< endl;
////    while(cin >> data, data != EOF)
////    {
////        OrderInsert(head, data);
////        Out(head);
////    }
//    cin >> data;
//    OrderInsert(head, data);
//    Out(head);
//    cout << "逆置带头结点的链表:"<< endl;
//    head = ReverseWithHead(head);
//    Out(head);
    cout << "初始化循环单链表:"<< endl;
    cout << "输入循环链表个数(规定个数大于1):"<< endl;
    cin >> n;
    link *circleHead;
    circleHead = CircleLinkInit(n);
    OutCircle(circleHead, n);
    cout << "在循环单链表中删除元素的后继元素为:"<< endl;
    cin >> data;
    int index = CircleFind(circleHead, data, n);
    CircleDelete(circleHead, index, n);
    n--;
    OutCircle(circleHead, n);
    return 0;
}