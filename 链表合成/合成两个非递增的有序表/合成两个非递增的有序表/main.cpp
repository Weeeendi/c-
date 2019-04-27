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
	l->next=NULL;//����ָ�����Ҫ��ʱָ��������
	p=l;
	while (l)
	{
		q=(LinkList)malloc(sizeof(LNode));
		q->next=NULL;
		scanf("%d",&q->data);
		if(q->data<0)//������Ϊ��ʱֹͣ¼��Ԫ��
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

�ϲ������ǵݼ��������LA��LB����ϳɷǵ����������LC

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
	if (!pa)//��paΪ�գ�ֻ�����ʣ�µ�pb
	{
		q=pb; pb=pb->next;
	}
	else if(!pb)//ͬ��
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
	    q->next=lc->next;//��pָ����ָ��λ��ժ�£�ͷ����Lc
		lc->next=q;
	}
	delete la,lb;
}

/****************************************

La��Lb��Lc�ֱ�Ϊ�����ǵݼ����������la��ɾ��Lb��Lc�й��е�Ԫ��

******************************************************************/

void DeleteBCfA(LinkList &la,LinkList &lb,LinkList &lc)
{
	LinkList pa,pre,pb,pc;
	pre=pa=la;
	pa=la->next;
	pb=lb->next;
	pc=lc->next;
	while(pa&&pb&&pc)//�κ�һ��ָ��Ϊ�գ���������Ԫ���ظ���
	{
		if(pa->data<pc->data||pa->data<pb->data)//a�ҵ����������еĹ���Ԫ��
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
	printf("������LA\n");
	creatlist(La);
	printf("������Lb\n");
	creatlist(Lb);
	printf("������Lc\n");
	creatlist(LC);
	//print(La);
    //print(Lb);
	//print(LC);
	//inverse(La);
	//printf("����ABΪC\n");
	//unionAB(LC,La,Lb);
	//print(LC);
	DeleteBCfA(La,Lb,LC);
	//printf("��A����ɾ��B C���е�Ԫ��\n");
	print(La);
}