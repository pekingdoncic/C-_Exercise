#include <iostream>
using namespace std;
typedef struct LNode
{
	double data;
	struct LNode *next;
} *LinkList;//�������� 

void InitList_L(LinkList &L){ 
   L=new LNode;                    	
   L->next=NULL;
   return ; 
} 

void CreateList_L(LinkList &L,int n){ 
      //��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
      L=new LNode; 
      L->next=NULL;
	  LinkList r; 	
      r=L; 	                                //βָ��rָ��ͷ��� 
      for(int i=0;i<n;++i){ 
       LinkList p;
	   p=new LNode;	       //�����½�� 
        cin>>p->data;   		       //����Ԫ��ֵ 
        p->next=NULL; r->next=p;       //���뵽��β 
        r=p; 	                                  //rָ���µ�β��� 
      } 
}//CreateList_L 



double GetAverage(LinkList L , int n)
{
	LinkList p;
	p=L->next;
	if(!p->next)
	{
		cout<<p->data<<endl;
		cout<<"Hello 1"<<endl;
		return p->data;
	}
	else
	{
	   double ave=GetAverage(p->next,n-1);
	   double r=(ave*(n-1)+p->data)/n;
	   cout<<r<<endl;
	   cout<<"Hello 2"<<endl;
	   return r;
	}
}

#include<stdio.h>
int fact( )
{ static int i=5;
   if(i==0)      return 1;
   else
    { i--;
       return(fact( )*(i+1)); }
}
int main( )
{  printf("factor of 5!=%d\n",fact());
   return 0;}


