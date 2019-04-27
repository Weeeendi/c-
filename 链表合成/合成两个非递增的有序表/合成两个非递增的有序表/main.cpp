#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>


typedef struct LNode
{
	int data;
	struct LNode * next;
}LNode,*LinkList;

void creatlist(LinkList &l)
{
	LinkList q,p;
	l=(LinkList)malloc(sizeof(LNode));
	l->next=NULL;//创建指针后需要及时指向不能悬空
	p=l;
	while (l)
	{
		q=(LinkList)malloc(sizeof(LNode));
		q->next=NULL;
		scanf("%d",&q->data);
		if(q->data<0)//但数据为负时停止录入元素
			break;
		p->next=q;
		p=q;
	}
}

void print(LinkList &l)
{
	LinkList q;
	q=l->next;
	while (q)
	{
		printf("%d\t",q->data);
		q=q->next;
	}
	printf("\n");
}

void inverse(LinkList &l)
{
	LinkList p,succ;
	p=l->next; l->next=NULL;
	while (p)
	{
        succ=p->next;
		p->next=l->next;
		l->next=p;
		p=succ;
	}
}
/***************************************************

合并两个非递减的有序表LA和LB将其合成非递增的有序表LC

****************************************************/

void unionAB(LinkList &lc,LinkList &la,LinkList &lb)
{
	LinkList pa,pb,q;
	pa=la->next;
	pb=lb->next;
	q=NULL;
	lc=new LNode;
	lc->next=NULL;
	while(pa||pb)
	{
	if (!pa)//若pa为空，只需输出剩下的pb
	{
		q=pb; pb=pb->next;
	}
	else if(!pb)//同上
	{
		q=pa; pa=pa->next;
	}
	else if(pa->data<=pb->data)
	{
		q=pa; pa=pa->next;
	}
	else
	{
		q=pb; pb=pb->next;
	}
	    q->next=lc->next;//将p指针所指的位置摘下，头插入Lc
		lc->next=q;
	}
	delete la,lb;
}

/****************************************

La，Lb，Lc分别为三个非递减的有序表，从la中删除Lb和Lc中共有的元素

******************************************************************/

void DeleteBCfA(LinkList &la,LinkList &lb,LinkList &lc)
{
	LinkList pa,pre,pb,pc;
	pre=pa=la;
	pa=la->next;
	pb=lb->next;
	pc=lc->next;
	while(pa&&pb&&pc)//任何一个指针为空，都不会有元素重复了
	{
		if(pa->data<pc->data||pa->data<pb->data)//a找到两个链表中的公共元素
		{
			pre=pa;pa=pa->next;
		}
		else if(pb->data<pa->data)
		{
			pb=pb->next;
		}
		else if(pc->data<pb->data)
		{	pc=pc->next;}
		else
		{
			pre->next=pa->next; delete pa;pa=pre->next;
		}
	}//while
}//end



void main()
{
	LinkList La,Lb,LC;
	printf("请输入LA\n");
	creatlist(La);
	printf("请输入Lb\n");
	creatlist(Lb);
	printf("请输入Lc\n");
	creatlist(LC);
	//print(La);
    //print(Lb);
	//print(LC);
	//inverse(La);
	//printf("连接AB为C\n");
	//unionAB(LC,La,Lb);
	//print(LC);
	DeleteBCfA(La,Lb,LC);
	//printf("从A链中删除B C共有的元素\n");
	print(La);
}