#include<iostream>
using namespace std;
#define KeyType int
#define M 4
typedef struct BTNode
{
	KeyType Key[M+1];//vector of keywords
	BTNode *parent;//Pointer to the parent node
	BTNode *ptr[M+1];//vector of subTree pointer
	string record[M+1];//record
}BTNode,*BTree;

typedef struct{
	BTNode *pt;//Pointer to the found node
	int i;//keyword number
	bool tag;//the tag which is whether keywords was found
}Result;