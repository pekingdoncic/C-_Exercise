#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-9;
bool isEqual(double a,double b)
{
	return fabs(a-b)<EPS; 
}
//用例只通过50%，应该是精度的问题！ 
int main() {
    double x11,y11,x12,y12;
    cin>>x11>>y11>>x12>>y12;
    double x21,y21,x22,y22;
    cin>>x21>>y21>>x22>>y22;
//    if(x11==x12&&y11==y12||x21==x22&&y21==y22){
//		cout<<"error"<<endl;
//		return 0;
//	}
	if(isEqual(x11,x12)&&isEqual(y11,y12)||isEqual(x21,x22)&&isEqual(y21,y22))
	{
		cout<<"error"<<endl;
		return 0;
	}
	 
//	bool isVertical1=(x11==x12);
//	bool isVertical2=(x21==x22);
	bool isVertical1=isEqual(x11,x12);
	bool isVertical2=isEqual(x21,x22);
	double k1,k2,b1,b2,x,y;
	if(!isVertical1){
		k1=(y12-y11)/(x12-x11);
		b1=y11-k1*x11;
	}
	if(!isVertical2){
		k2=(y22-y21)/(x22-x21);
		b2=y21-k2*x21;
	}
	
//	double k1=(y12-y11)/(x12-x11);
//	double k2=(y22-y21)/(x22-x21);
//	if(!isVertical1&&!isVertical2&&k1==k2){
	if(!isVertical1&&!isVertical2&&isEqual(k1,k2)){
		//if(b1==b2){
		if(isEqual(b1,b2)){
			//TODO
			cout<<"coincide"<<endl;
		}
		else
		{
			cout<<"parallel"<<endl;
		}
	}
	else if(isVertical1&&isVertical2){
	//	if(x11==x21){
	if(isEqual(x11,x21)){
		//TODO
			cout<<"coincide"<<endl;
		}
		else
		{
			cout<<"parallel"<<endl;
		}
	}
	else
	{
		if(isVertical1){
			x=x11;
			y=k2*x+b2;
		}
		if(isVertical2){
			x=x21;
			y=k1*x+b1;
		}
		else
		{
			x=(b2-b1)/(k1-k2);
			y=k1*x+b1;
		}
//		double x=(y21-y11+k1*x11-k2*x21)/(k1-k2);
//		double y=k1*(x-x11)+y11;
	
	}		
	cout<<fixed<<setprecision(2)<<x<<" "<<y<<endl;
	return 0;
}
