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
		(*root)->data=ch;//生成结点
		CreateBitree(&(*root)->Lchild);//构造左子树
		CreateBitree(&(*root)->Rchild);//构造右子树
	}
}

 void InitBitree()
 {
	 BiTree BT=NULL;
	 CreateBitree(&BT);
 }
/*
* 递归的三种遍历方法
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

void PostOrder(BiTree B)//后序遍历
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
**非递归的遍历算法
*/
void PreOrder1(BiTree B)
{
	stack <BiTree>myStack;//建立栈
	BiTree p;
	p=B;
	if(B==NULL) return;
	
	while (!(p==NULL&&myStack.empty()))//若p为空且栈为空时遍历结束
	{
		while(!p==NULL)
		{cout<<p->data<<"\t";//在第一次遍历到时输出该结点
		myStack.push(p);     //将该节点入栈	
		p=p->Lchild;		 //进入左子树
		}
		if(myStack.empty())
		return;
		else{
			p=myStack.top();//p指向栈顶元素
			myStack.pop();  //栈顶元素出栈
			p=p->Rchild;    //进入右子树
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
			cout<<p->data<<"\t";//到该元素出栈时输出该结点
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
		while(!p==NULL)//走到最左边
		{
		myStack.push(p);
		p=p->Lchild;
		}
		if(myStack.empty())
		    return;
		else{
			p=myStack.top();
			if(p->Rchild&&p->Rchild!=r)//右子树存在，且未被访问
				p=p->Rchild;
			else{
			myStack.pop();
			cout<<p->data<<"\t";
			r=p;//记录最近访问过的节点
			p=NULL;//结点访问过，重置p指针
			}
		}//else
	}//while
}


//叶子计数	
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
void CopyTree(BiTree *t,BiTree s)//源  s  , 目的：t
{   if(s!=NULL) {
	*t=new BiNode;
	(*t)->data=s->data;
	CopyTree(&(*t)->Lchild,s->Lchild);
	CopyTree(&(*t)->Rchild,s->Rchild);
       }else *t=NULL;
}


/*
**线索二叉树的基本操作和实现
**
*/

//typedef enum PiontTag{Link,Thread};//枚举类型默认Link为0，Thread为1
typedef struct BiThrNode{
	char data;
	struct BiThrNode *Lchild,*Rchild;
	int ltag,rtag;//标志位域，为0时代表左右孩子，为1时代表前后线索
}BiThrNode,*BiThrTree;

void inThreadBitree(BiThrTree &p,BiThrTree &pre)
{
	if (p)
	{
		inThreadBitree(p->Lchild,pre);//递归线索左子树
		if(p->Lchild==NULL)//左子树为空，建立前驱线索
		{
			p->Lchild=pre;//第一个结点的Lchild指针指向了头节点
			p->ltag=1;
		}
		if(pre!=NULL&&pre->Rchild==NULL)//建立前驱结点的后继节点
		{pre->Rchild=p;
		pre->rtag=1;
		}
		pre=p;//标记当前节点成为刚刚访问过的结点；
		inThreadBitree(p->Rchild,pre);//递归线索化右子树
	}
}

void ThreadBiTree(BiThrTree p)
{
	BiThrTree thrt;//线索二叉树的头节点
	thrt=new BiThrNode;
	thrt->ltag=0;thrt->rtag=1;
	thrt->Rchild=NULL;
	BiThrTree pre=thrt;
	if (!p)
		thrt->Lchild=thrt;
	else
	{
		thrt->Rchild=p;
		inThreadBitree(p,pre);//对非空二叉树进行线索化
		pre->Rchild=thrt;//处理遍历的最后一个结点
		pre->rtag=1;
		thrt->Rchild=pre;
	}
}

/*
*中序遍历线索二叉树
*/
int InOrderThrTree(BiThrTree t)
{
	BiThrTree p;
	p=t->Lchild;
	while(p!=t)
	{  while(p->ltag=NULL)//从根结点出发找到最左结点
		p=p->Lchild;
	   cout<<p->data<<'\t';
	   while(p->rtag==1&&p->Rchild!=t)//二叉线索不断就依次访问结点
	   {
		p=p->Rchild;
	   cout<<p->data<<'\t';}
	p=p->Rchild;//到右子树继续进行
	}//while
	cout<<endl;
	return 1;
}

int main()
{
	BiTree Tree,Tree2;
	Tree2=Tree=NULL;
	//InitBitree(Tree);
	cout<<"请依次输入二叉树结点,#号表示该子树为空"<<endl;
	CreateBitree(&Tree);
	cout<<"中序输出二叉树"<<endl;
	//InOrder(Tree);
	InOrder1(Tree);
	cout<<endl;
	cout<<"先序输出二叉树"<<endl;
	//PreOrder(Tree);
	PreOrder1(Tree);
	cout<<endl;
	cout<<"后序输出二叉树"<<endl;
	//PostOrder(Tree);
	PostOrder1(Tree);
	cout<<endl;
	cout<<count(Tree)<<endl;
	CopyTree(&Tree2,Tree);
	cout<<count(Tree2)<<endl;
	ThreadBiTree(Tree);
}