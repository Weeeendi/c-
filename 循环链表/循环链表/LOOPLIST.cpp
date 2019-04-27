#include<iostream>
using namespace std;

struct LNode
{
	int data;
    LNode*next;
};
struct SLList
{
	LNode*pb;//尾指针
	int size;
};

void InitList(SLList& L)
{
	L.pb=NULL;
	L.size=0;
}

void add(SLList &List,LNode *s)//将s所指的结点添加到链表的尾部
{
	if(!List.pb)//判断链表是否非空
	{
		List.pb=s;
		List.pb->next=List.pb;
	}
	else
	{
		LNode *p=List.pb->next;
		List.pb->next=s;  
		List.pb=s;
		List.pb->next=p;
	}
	List.size++;
}

//int count(SLList List)
//{
//	LNode *P=List->pb->next;
//	int count;
//	while (P==List->pb)
//	{
//
//	}
//
//}
void print(SLList &l)
{
	LNode *q;
	q=l.pb->next;
	cout<<q->data<<"\t";
		q=q->next;
	while (q!=l.pb->next)
	{
		cout<<q->data<<"\t";
		q=q->next;
	}
	cout<<endl;
}

void main()
{
	SLList mylist;
	InitList(mylist);
    while(1)
	{
		LNode *q=(LNode*)malloc(sizeof(LNode));
		q->next=NULL;
		cin>>q->data;
		if(q->data<0)
			break;
		add(mylist,q);
	}
	print(mylist);
}