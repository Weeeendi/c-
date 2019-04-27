#include<Windows.h>
#include<iostream>
#include<stack>
using namespace std;
#define MAX_TREE_SIZE 100

typedef struct BiNode
{
   char data;
   struct BiNode *Lchild;
   struct BiNode *Rchild;
}BiNode,*BiTree;



void CreateBitree(BiTree *root)
{
	char ch;
	cin>>ch;
	if(ch=='#')
		*root=NULL;
	else{
		if(!(*root=new BiNode))
			exit(1);
		(*root)->data=ch;//���ɽ��
		CreateBitree(&(*root)->Lchild);//����������
		CreateBitree(&(*root)->Rchild);//����������
	}
}

 void InitBitree()
 {
	 BiTree BT=NULL;
	 CreateBitree(&BT);
 }
/*
* �ݹ�����ֱ�������
*/
void InOrder(BiTree B)
{
	if(B==NULL)
		return;
		InOrder(B->Lchild);
		cout<<B->data<<"\t";
		InOrder(B->Rchild);
}

void PreOrder(BiTree B)
{
	if (B==NULL)
	return;
	    cout<<B->data<<"\t";
		PreOrder(B->Lchild);
		PreOrder(B->Rchild);
}

void PostOrder(BiTree B)//�������
{
	if (B==NULL)
	return;
		PostOrder(B->Lchild);
		PostOrder(B->Rchild); 
		cout<<B->data<<"\t";
}

//void DestroyBTree(BiTree BT)
//{
//    if (BT)
//    {
//        DestroyBTree(BT -> Lchild);
//        DestroyBTree(BT -> Lchild);
//        free(BT);
//        BT = NULL;
//    }
//}
/*
**�ǵݹ�ı����㷨
*/
void PreOrder1(BiTree B)
{
	stack <BiTree>myStack;//����ջ
	BiTree p;
	p=B;
	if(B==NULL) return;
	
	while (!(p==NULL&&myStack.empty()))//��pΪ����ջΪ��ʱ��������
	{
		while(!p==NULL)
		{cout<<p->data<<"\t";//�ڵ�һ�α�����ʱ����ý��
		myStack.push(p);     //���ýڵ���ջ	
		p=p->Lchild;		 //����������
		}
		if(myStack.empty())
		return;
		else{
			p=myStack.top();//pָ��ջ��Ԫ��
			myStack.pop();  //ջ��Ԫ�س�ջ
			p=p->Rchild;    //����������
		}
	}
}
void InOrder1(BiTree B)
{
	stack <BiTree>myStack;
	BiTree p;
	p=B;
	if(B==NULL) return;
	
	while (!(p==NULL&&myStack.empty()))
	{
		while(!p==NULL)
		{
		myStack.push(p);
		p=p->Lchild;
		}
		if(myStack.empty())
		return;
		else{
			p=myStack.top();
			myStack.pop();
			cout<<p->data<<"\t";//����Ԫ�س�ջʱ����ý��
			p=p->Rchild;
		}
	}
}

void PostOrder1(BiTree B)
{
	stack <BiTree>myStack;
	BiTree p,r;
	p=B;r=NULL;
	if(B==NULL) return;
	while (!(p==NULL&&myStack.empty()))
	{
		while(!p==NULL)//�ߵ������
		{
		myStack.push(p);
		p=p->Lchild;
		}
		if(myStack.empty())
		    return;
		else{
			p=myStack.top();
			if(p->Rchild&&p->Rchild!=r)//���������ڣ���δ������
				p=p->Rchild;
			else{
			myStack.pop();
			cout<<p->data<<"\t";
			r=p;//��¼������ʹ��Ľڵ�
			p=NULL;//�����ʹ�������pָ��
			}
		}//else
	}//while
}


//Ҷ�Ӽ���	
int count(BiTree B)
{
	int m,n;
	if(B){
		m=count(B->Lchild);
		n=count(B->Rchild);
		if(m+n==0)return 1;
		else return m+n;
	}else return 0;
}

//
void CopyTree(BiTree *t,BiTree s)//Դ  s  , Ŀ�ģ�t
{   if(s!=NULL) {
	*t=new BiNode;
	(*t)->data=s->data;
	CopyTree(&(*t)->Lchild,s->Lchild);
	CopyTree(&(*t)->Rchild,s->Rchild);
       }else *t=NULL;
}


/*
**�����������Ļ���������ʵ��
**
*/

//typedef enum PiontTag{Link,Thread};//ö������Ĭ��LinkΪ0��ThreadΪ1
typedef struct BiThrNode{
	char data;
	struct BiThrNode *Lchild,*Rchild;
	int ltag,rtag;//��־λ��Ϊ0ʱ�������Һ��ӣ�Ϊ1ʱ����ǰ������
}BiThrNode,*BiThrTree;

void inThreadBitree(BiThrTree &p,BiThrTree &pre)
{
	if (p)
	{
		inThreadBitree(p->Lchild,pre);//�ݹ�����������
		if(p->Lchild==NULL)//������Ϊ�գ�����ǰ������
		{
			p->Lchild=pre;//��һ������Lchildָ��ָ����ͷ�ڵ�
			p->ltag=1;
		}
		if(pre!=NULL&&pre->Rchild==NULL)//����ǰ�����ĺ�̽ڵ�
		{pre->Rchild=p;
		pre->rtag=1;
		}
		pre=p;//��ǵ�ǰ�ڵ��Ϊ�ոշ��ʹ��Ľ�㣻
		inThreadBitree(p->Rchild,pre);//�ݹ�������������
	}
}

void ThreadBiTree(BiThrTree p)
{
	BiThrTree thrt;//������������ͷ�ڵ�
	thrt=new BiThrNode;
	thrt->ltag=0;thrt->rtag=1;
	thrt->Rchild=NULL;
	BiThrTree pre=thrt;
	if (!p)
		thrt->Lchild=thrt;
	else
	{
		thrt->Rchild=p;
		inThreadBitree(p,pre);//�Էǿն���������������
		pre->Rchild=thrt;//������������һ�����
		pre->rtag=1;
		thrt->Rchild=pre;
	}
}

/*
*�����������������
*/
int InOrderThrTree(BiThrTree t)
{
	BiThrTree p;
	p=t->Lchild;
	while(p!=t)
	{  while(p->ltag=NULL)//�Ӹ��������ҵ�������
		p=p->Lchild;
	   cout<<p->data<<'\t';
	   while(p->rtag==1&&p->Rchild!=t)//�����������Ͼ����η��ʽ��
	   {
		p=p->Rchild;
	   cout<<p->data<<'\t';}
	p=p->Rchild;//����������������
	}//while
	cout<<endl;
	return 1;
}

int main()
{
	BiTree Tree,Tree2;
	Tree2=Tree=NULL;
	//InitBitree(Tree);
	cout<<"������������������,#�ű�ʾ������Ϊ��"<<endl;
	CreateBitree(&Tree);
	cout<<"�������������"<<endl;
	//InOrder(Tree);
	InOrder1(Tree);
	cout<<endl;
	cout<<"�������������"<<endl;
	//PreOrder(Tree);
	PreOrder1(Tree);
	cout<<endl;
	cout<<"�������������"<<endl;
	//PostOrder(Tree);
	PostOrder1(Tree);
	cout<<endl;
	cout<<count(Tree)<<endl;
	CopyTree(&Tree2,Tree);
	cout<<count(Tree2)<<endl;
	ThreadBiTree(Tree);
}