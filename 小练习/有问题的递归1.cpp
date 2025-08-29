#include <iostream>
using namespace std;
typedef struct LNode
{
	double data;
	struct LNode *next;
} *LinkList;//定义链表 

void InitList_L(LinkList &L){ 
   L=new LNode;                    	
   L->next=NULL;
   return ; 
} 

void CreateList_L(LinkList &L,int n){ 
      //正位序输入n个元素的值，建立带表头结点的单链表L 
      L=new LNode; 
      L->next=NULL;
	  LinkList r; 	
      r=L; 	                                //尾指针r指向头结点 
      for(int i=0;i<n;++i){ 
       LinkList p;
	   p=new LNode;	       //生成新结点 
        cin>>p->data;   		       //输入元素值 
        p->next=NULL; r->next=p;       //插入到表尾 
        r=p; 	                                  //r指向新的尾结点 
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


