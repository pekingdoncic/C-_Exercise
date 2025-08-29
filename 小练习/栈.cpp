#include <iostream>
#include <stdio.h>
#define N 50
using namespace std;
typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;
//为栈初始化 
void InitStack(SqStack &s)
{
	s.base=new int[N];//分配空间 
	if(!s.base)
		exit(0);
	s.top=s.base;
	s.stacksize=N;
}
void PushStack(SqStack &s,int e)
{
	if(s.top-s.base==s.stacksize)
	return ;
	s.top++;//刚才为什么13转化成了0110！
	*s.top=e;//是因为语句的逻辑有问题！这里要先top++再去把e赋给*s.top！ 
	
}

void PopStack(SqStack &s,int &e)//出栈 
{
	if(s.top==s.base)
	return;
	e=*s.top;
	s.top--;
}
bool StackEmpty(SqStack s)
{
	if(s.base==s.top)
	return true;
	else 
	return false;
}
void converse(int x)
{
	SqStack s; 
	InitStack(s);
	int e; 
	while(x)
	{
		PushStack(s,x%2);
		x=x/2;
	}
	cout<<"循环转化："<<endl;
	cout<<"转化成的二进制数为："<<endl; 
	while(!StackEmpty(s))
	{
		PopStack(s,e);
		cout<<e;
	}
}
void digui(int x)
{
	if(x==0)
		return;
	else
	{
		digui(x/2);//注意需要先调用函数，再去显示，否则是队列的显示形式，先进先出！ 
//		int i;
		cout<<x%2;
	}
 } 
int main()
{
	int x;
	cout<<"请输入要转化的十进制数:"<<endl;
	cin>>x; 
	cout<<"请选择是用循环转化（1）还是递归转化（2）："<<endl;
	int op;
	cin>>op;
	switch(op)
	{
		case 1:converse(x);break;
		case 2:digui(x);break;
		default:return 0; 
	 } 
	return 0;
 } 


