#include<iostream>
#define p 13;
struct HashTable
{
	int *elem;//����Ԫ�ش����ַ
	int count;//��ǰ����Ԫ�صĸ���
	int size;//��ϣ����
}ht;

int CalHash(int key)
{
	return key%p;
}

int SearchHash(int key,int &s)//���ҳɹ�����1�����򷵻�0
{
	s=CalHash(key);
	while((ht.elem[s]!=-1)&&(ht.elem[s]!=key))//Conflict
		Collision(s);

}

void Collision(int &s)
{
	s++;
}
