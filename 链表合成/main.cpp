#include <iostream>

using namespace std;

int main()
{


}

//一元多项式的实现
#define Max 20
typedef struct
{
    float coef;
    int exp;
}PolyArray[Max];

struct PolyNode
{
    float coef;
    int exp;
    PolyNode *next;
};
class Poly
{
private:
    PolyNode *Head;
public:
    Poly();//构造函数 建立空多项式
    ~Poly();//析构函数，释放多项式
};

bool Merge(SeqList &A,SeqList &B,Seqlist &C)
{
    if(A.n+B.n>C.n)return false;
    int i=1,j=1,k=1;
    while(i<=A.n&&j<=B.n)//circle,compare A element and B,save littler one to C
    {
        if(A.data[i-1]<=B.data[j-1])
           {
            C.data[k-1]=A.data[i-1];i++;
           }
        else {C.data[k-1]=B.data[i-1];j++;K++;}
    }
    while(i<A.n){C.data[k-1]=A.data[i-1];i++;k++}
    while(j<B.n){C.data[k-1]=B.data[j-1];j++;k++}
    C.n=K;
    return turn;
}
