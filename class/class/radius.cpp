#include<iostream>
using namespace std;

const float PI=3.1415926;
const float Fence_Price=35;
const float Concrete_Price=25;

class Circle{ //��������

public:		//�ⲿ�ӿ�
    Circle(float r);//�뾶
	float circumference();//�ܳ�
	float area();//���
	
private://˽�����ݳ�Ա
	float radius;//
	};
//���ʵ��
//���캯����ʼ������
Circle::Circle(float r){
radius = r;
}
float Circle::circumference()
{ return 2*PI*radius;
}
float Circle::area()
{ return PI*radius*radius;
}
int main(){
	float radius;
	cout<<"Enter the radius of the pool"<<endl;
	cin>>radius;
	Circle pool(radius);
	Circle poolRim(radius+3);
	float fenceCost=Fence_Price*pool.area()+Concrete_Price*(poolRim.area()-pool.area());
	cout<<"Fencing Cost is :"<<fenceCost<<endl;
	while(1);
}
