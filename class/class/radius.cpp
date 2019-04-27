#include<iostream>
using namespace std;

const float PI=3.1415926;
const float Fence_Price=35;
const float Concrete_Price=25;

class Circle{ //声明类名

public:		//外部接口
    Circle(float r);//半径
	float circumference();//周长
	float area();//面积
	
private://私有数据成员
	float radius;//
	};
//类的实现
//构造函数初始化数据
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
