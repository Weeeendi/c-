#include<iostream>
#include<stack>

using namespace std;

/*��������������������1.0��������������������������������������������
decimal to octal  
����������������������������������������������������������������*/

/*��������������������2.0��������������������������������������������
A-ary to B-ary  
����������������������������������������������������������������*/

void AtoB()//��A������ת��ΪB����
{
	stack<int> S;
	int N,A,B;
	cout<<"Please input a A-ary number:"<<endl;
	cin>>N;
	cout<<"Please input A :"<<endl;
	cin>>A;
	cout<<"Please input B :"<<endl;
	cin>>B;
	while(N)
	{S.push(N%B);
	 N=N/B;
	}
	while(!S.empty())
	{cout<<S.top();
	 S.pop();
	}
	cout<<endl;
}

/*---------------------------------
The fundamental operation of queue
-----------------------------------*/
#define QueueSize 100
typedef struct Squeue
{
	char base[QueueSize];
	int front;
	int rear;
}SLqueue;

void InitQueue(SLqueue *SQ)
{
	SQ->front=SQ->rear=0;
}

int EnQueue(SLqueue &Q,char e)
{
	if((Q.rear+1)%QueueSize==Q.front)			//���������ش���
	{
		return -1;
	}
	else
	{
		Q.base[Q.rear]=e;                        //Ԫ��x���
		Q.rear=(Q.rear+1)%QueueSize;             //�ƶ�βָ��ָ����һ���ռ�	
	}
	return 1;
}

char DeQueue(SLqueue &Q)
{
	char e;
	if (Q.front==Q.rear) return -1;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%QueueSize;
	return(e);
}

int QueueLength(SLqueue &Q)
{
	return (Q.rear-Q.front+QueueSize)%QueueSize; 
}


void main()
{
	//AtoB();
	SLqueue queue;
	char elem;
	queue.front=queue.rear=0;
	EnQueue(queue,'e');
	EnQueue(queue,'a');
	EnQueue(queue,'l');
	cout<<QueueLength(queue)<<endl;
	elem=DeQueue(queue);
	cout<<elem<<endl;
	cout<<QueueLength(queue)<<endl;
	system("PAUSE");
}

