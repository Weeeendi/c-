
/*
1.��ͷ���
2.������������
3.ɾ������E
4.�ж������Ƿ����� 
5.�ϳ�2���������� 
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
LinkList::~LinkList()//�����һ��
{
	LNode *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
void LinkList::CreatList1(int n) //ͷ�巨�������Ա�
{
	LNode  *p,*s;
	p=head;
	cout<<"����������"<<n<<"��Ԫ�ص���ֵ:"<<endl;
	for(int i=1;i<n;i++)
	{
		s=new LNode;
	    cin>> s->data;
		s->next=p->next;
		p->next=s;
	}
	
}

//void LinkList::CreatList2(int n)  //β�巨�������Ա�
//{
//	LNode  *p=head,*s;
//   int j=0;
//	cout<<"����������"<<n<<"��Ԫ�ص���ֵ:"<<endl;
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
        return false;//����β��
	s= (LNode*)new LNode[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool LinkList::GetElem(int i, int *e)//*e�Ƿ��ص�Ԫ��
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
//		//cout<<"��������Ҫ�����Ԫ��λ��:"<<endl;
//	while(p&&j<i)
//	{
//		j++;p=p->next;
//	}
//	if(!p||j>i-1)
//	{
//		cout<<"����λ���쳣"<<endl;
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
	for (int i = 0;i < Li.Length();i++)//����������
    {

        if (Li.GetElem(i, p))
            cout << *p<<"   ";
    }
	int len;
	len=Li.Length();
	cout<<len<<endl;
}