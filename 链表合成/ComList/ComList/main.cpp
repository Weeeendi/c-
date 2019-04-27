
/*
1.带头结点
2.遍历单项链表
3.删除链表E
4.判断链表是否有序 
5.合成2个有序链表 
*/
#include<iostream>
using namespace std;

typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode;

class LinkList
{
private:
	LNode *head;
public:
	 LinkList() { head = NULL; }
	~LinkList();
	void CreatList1(int n);
	void CreatList2(int n);
	bool ListInsert(int i,int e);
	int ListDelete(int i);
	int LinkList::Length();
	bool LinkList::GetElem(int i, int *e);
};
int LinkList::Length()
{
    LNode *p = head;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}
LinkList::~LinkList()//和清空一样
{
	LNode *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
void LinkList::CreatList1(int n) //头插法创建线性表
{
	LNode  *p,*s;
	p=head;
	cout<<"请依次输入"<<n<<"个元素的数值:"<<endl;
	for(int i=1;i<n;i++)
	{
		s=new LNode;
	    cin>> s->data;
		s->next=p->next;
		p->next=s;
	}
	
}

//void LinkList::CreatList2(int n)  //尾插法创建线性表
//{
//	LNode  *p=head,*s;
//   int j=0;
//	cout<<"请依次输入"<<n<<"个元素的数值:"<<endl;
//	for(int i=1;i<n;i++)
//	{
//		s=new LNode;
//		cin>>s->data;
//		p->next=s;
//		p=s;
//	}
//}
bool LinkList::ListInsert(int i, int e)
{
    LNode*p = head,*s;
    int j = 0;
    if (i == 0)
    {
		s = (LNode*)new LNode[1];
        s->data = e;
        s->next = p;
        head = s;
		return true;
    }
    while (p&&j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;//到队尾了
	s= (LNode*)new LNode[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool LinkList::GetElem(int i, int *e)//*e是返回的元素
{
    LNode *p = head;
    int j = 0;
    while (p&&j < i)
    {
        p = p->next;
        j++;
    }
    if (p == NULL) return false;
    *e = p->data;
    return true;
}
//void LinkList::ListInsert(int i,int e)
//{
//	LNode *p;
//	p=head;
//	int j=0;
//		//cout<<"请输入你要插入的元素位置:"<<endl;
//	while(p&&j<i)
//	{
//		j++;p=p->next;
//	}
//	if(!p||j>i-1)
//	{
//		cout<<"输入位置异常"<<endl;
//		return;
//	}
//	else
//	{ LNode *s;
//	s=(LNode *)new LNode[1];
//	s->data=e;
//	s->next=p->next;
//	p->next=s;
//	}
//}

void main()
{
	int a = 0;
    int *p = &a;
	LinkList Li;
	for(int i=0;i<5;i++)
	Li.ListInsert(i,i);
	for (int i = 0;i < Li.Length();i++)//遍历该链表
    {

        if (Li.GetElem(i, p))
            cout << *p<<"   ";
    }
	int len;
	len=Li.Length();
	cout<<len<<endl;
}