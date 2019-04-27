#include<iostream>
#define p 13;
struct HashTable
{
	int *elem;//数据元素储存基址
	int count;//当前数据元素的个数
	int size;//哈希表长度
}ht;

int CalHash(int key)
{
	return key%p;
}

int SearchHash(int key,int &s)//查找成功返回1，否则返回0
{
	s=CalHash(key);
	while((ht.elem[s]!=-1)&&(ht.elem[s]!=key))//Conflict
		Collision(s);

}

void Collision(int &s)
{
	s++;
}
