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
//Ϊջ��ʼ�� 
void InitStack(SqStack &s)
{
	s.base=new int[N];//����ռ� 
	if(!s.base)
		exit(0);
	s.top=s.base;
	s.stacksize=N;
}
void PushStack(SqStack &s,int e)
{
	if(s.top-s.base==s.stacksize)
	return ;
	s.top++;//�ղ�Ϊʲô13ת������0110��
	*s.top=e;//����Ϊ�����߼������⣡����Ҫ��top++��ȥ��e����*s.top�� 
	
}

void PopStack(SqStack &s,int &e)//��ջ 
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
	cout<<"ѭ��ת����"<<endl;
	cout<<"ת���ɵĶ�������Ϊ��"<<endl; 
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
		digui(x/2);//ע����Ҫ�ȵ��ú�������ȥ��ʾ�������Ƕ��е���ʾ��ʽ���Ƚ��ȳ��� 
//		int i;
		cout<<x%2;
	}
 } 
int main()
{
	int x;
	cout<<"������Ҫת����ʮ������:"<<endl;
	cin>>x; 
	cout<<"��ѡ������ѭ��ת����1�����ǵݹ�ת����2����"<<endl;
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


