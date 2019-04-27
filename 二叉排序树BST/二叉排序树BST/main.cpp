#include<iostream>
#include<malloc.h>
using namespace std;
#define MAXSIZE 100

typedef int ElemType;
typedef struct BSTNode
{
	ElemType data;
	struct BSTNode *lchild,*rchild;
}BSTNode,*Tree;

Tree SearchMin(Tree root)
{
    if (root == NULL)
        return NULL;
    if (root->lchild == NULL)
        return root;
    else  //һֱ�������ң�ֱ��û�����ӵĽ��  
        return SearchMin(root->lchild);
}
Tree SearchMax(Tree root)
{
    if (root == NULL)
        return NULL;
    if (root->rchild == NULL)
        return root;
    else  //һֱ���Һ����ң�ֱ��û���Һ��ӵĽ��  
        return SearchMax(root->rchild);
}

Tree BST_search(Tree T,int key)
{
	Tree p=T;
	while(p)
    {
		if(key == p->data)
          return p;
        else
        p = (key < p -> data)?(p->lchild):(p->rchild);        
    }
	//cout<<"�����޵��ڸùؼ��ֵĽ��"<<endl;
	return NULL;     
}

void BST_InOrderTranversal(Tree root)
{
	if(root==NULL)
		return;
	BST_InOrderTranversal(root->lchild);//����������
	cout<<root->data<<' ';
	BST_InOrderTranversal(root->rchild);//����������
}

//����ĵݹ��㷨
void BST_Insert1(Tree *T,int ch)
{
	 Tree p=new BSTNode;
	 p->data=ch;
	 p->lchild=p->rchild=NULL;
	if(*T==NULL)
	{ 
	  *T=p;
	  return;
	}
	if((*T)->data==ch)
		return;
	else if((*T)->data<ch)
	 {BST_Insert1(&(*T)->rchild,ch);
	 
	 }
	else
	  {BST_Insert1(&(*T)->lchild,ch);
	   }
}
//����ķǵݹ��㷨
void BST_Insert(Tree *T,int ch)
{
	//��ʼ��������
	Tree p=new BSTNode;
	if(!p)return;
	p->data=ch;
	p->lchild=p->rchild=NULL;
	
	//��Ϊ�յ�һ�����Ϊ���ڵ�
	if(*T==NULL)
	  {
		  *T=p;
		  return;
	  }
	if(BST_search(*T,ch)!=NULL)//�������Ѵ���
		  return;
	//���в��룬�����ҵ�Ҫ�����λ�õĸ��ڵ�
	Tree tnode=NULL,troot=*T;
	while (troot)
    {       
        tnode = troot;
        troot = (ch < troot->data) ? troot->lchild : troot->rchild;
    }
	if (ch < tnode->data)
        tnode->lchild = p;
    else
        tnode->rchild = p; 	
}

//Delete the node that is equal to key 
bool BST_delete(Tree *T,ElemType key)
{
	Tree p=*T,parent=nullptr,s=nullptr;
	while(p)
	{
		if(p->data>key)
		{
			parent=p;
			p=p->lchild;
		}
		else if(p->data<key)
		{
			parent=p;
			p=p->rchild;
		}
		else
		{
			s=p;
			if(p->lchild==NULL)				// left child is null
			{
				if(parent->lchild==p)
					parent->lchild=p->rchild;
				else if(parent->rchild==p)
					parent->rchild=p->rchild;
				else
					*T=parent->rchild;
			}
			else if(p->rchild==NULL)			//right child is null
			{
				if(parent->lchild==p)
					parent->lchild=p->lchild;
				else if(parent->rchild==p)
					parent->rchild=p->lchild;
				else
					*T=parent->lchild;
			}
			else{			//both left and right child are not null
				parent=p;
				s=p->rchild;
				while (s->lchild!=NULL)//find the most left node,then exchange its value and p's;
				{
					parent=s;
					s=s->lchild;
				}
				p->data=s->data;
				if(parent->rchild==s)
					parent->rchild=s->rchild;//��һ����ת��s������������
				else
					parent->lchild=s->rchild;
			}
			free(s);
			return 1;
		}//else
	}//while
	cout<<"�������޵���key�Ľ��"<<endl;
	return 0;
}

void main()
{
	Tree BSTree;
	BSTree=NULL;
	int str[100],i=0;
	int ch;
	cout<<"������Ҫ����Ķ���������,������Ϊ����"<<endl;
	cin>>ch;
	while(ch>0)
	{
		str[i]=ch;
		i++;
		cin>>ch;
	}
	int n=i;
	i=0;
	while(i<n)
	{
		BST_Insert1(&BSTree,str[i]);
		i++;
	}
	BST_InOrderTranversal(BSTree);
	cout<<endl<<"please input the number you want to delete"<<endl;
	cin>>ch;
	if(BST_delete(&BSTree,ch))
	   BST_InOrderTranversal(BSTree);
}

