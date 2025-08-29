#include <stdio.h> 
#include <iostream>
#include <string.h>
#include <fstream> 
#define N 109
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef int Status; 
typedef struct
{
	string no;//图书ISBN  
	string name;//图书名字 
	float price;//图书价格	
}Book;
typedef struct LNode
{
	Book data;
	struct LNode *next;  
}LNode,*LinkList;

Status InitList(LinkList &L)//创建链表 
{
	L=new LNode;
	L->next=NULL;
	cout<<"链表创建完成"<<endl;
	return OK;
} 
Status GetElem(LinkList L,int i,Book &e)//获取元素 
{
	LinkList p;//p是一个指针！ 
	p=L->next;//p指向首元节点 
	int j;
	j=1;
	while(p&&j<i)//在小于i的时候，不断顺滕摸瓜查找 
	{
		p=p->next;
		j++;
	}
	if(p!=NULL||j>i)
		return ERROR;
	e=p->data;//获取这个元素 
	return OK;
}
LNode *LocateElem(LinkList L,Book e)//查找 
{
	LinkList p;
	p=L->next;//指向头地址 
	while(p&&p->data.price==e.price)
		p=p->next;//遍历查找 
	return p; //返回指针指向的值！ 
}
Status LinkInsert(LinkList &L,int i,Book e)//插入 
{
	LinkList p;
	p=L;
	int j=0;
	while(p!=NULL&&(j<i-1))
	{
		p=p->next;
		j++;
	}
	if(p==NULL||j>i-1)
		return ERROR;
		LinkList s;//你要定义新编量必须得定义成指针！ 
	s=new LNode;
	s->data=e;//数据项 
	s->next=p->next;//指针项，原来p指向的下一个节点变成s指向的下一个节点
	return OK; 
}
Status DestroyList_L(LinkList &L)//销毁链表！即把链表里面的数据全部删除！ 
{
    LinkList p;//注意，定义的一定是指针！ 
       while(L)
        {
            p=L;  
            L=L->next;
            delete p;  
        }
     return OK;
 }

Status ListDelete(LinkList &L,int i)//删除链表 
{
	LinkList p=L,q;//指向头节点！ 
	int j=0;
	while((p->next)&&(j<i-1))//找到第i-1个节点位置即删除节点的前一个节点 
	{
		p=p->next;
		++j;
	}
	if(p->next==NULL||(j>i-1))//判断位置合法与否 
		return ERROR;
	q=p->next;//临时保存p的信息，让p的下一个节点变成q！因为不能p->next->next！ 
	p->next=q->next; //让 
	delete p;
	return OK;
}

Status ClearList(LinkList & L)// 将L重置为空表 
{  
   LinkList p,q;
   p=L->next;   //p指向第一个结点
   while(p)       //没到表尾 
      {  q=p->next; delete p;     p=q;   }
   L->next=NULL;   //头结点指针域为空 
   return OK;
 }
//求表长
int  ListLength_L(LinkList L){
//返回L中数据元素个数
    LinkList p;
    p=L->next;  //p指向第一个结点
    int i=0;             
    while(p!=NULL)
	{//遍历单链表,统计结点数
        i++;
        p=p->next;    
	} 
	cout<<i<<endl;
    return i;                             
 }

void CreateList_F(LinkList &L,int n)//CreateList_F 
{ 
     L=new LNode; 
     L->next=NULL; //先建立一个带头结点的单链表 
	 for(int i=n;i>0;--i)
	 { 
        LinkList p;
		p=new LNode; //生成新结点
//		cout<<"请依次输入ISBN，名字，价格"<<endl; 
//        cin>>p->data.no;   		       //输入元素值 
//        cin>>p->data.name;
//        cin>>p->data.price; //输入元素值 //这块用->就不行！不知道为什么！ 
        p->next=L->next;//前插法！ 
		L->next=p; 	//插入到表头 
     } 
    
     cout<<"前插法创建链表完成"<<endl;
}

void CreateList_L(LinkList &L,int n)//CreateList_L 
{ 
      //正位序输入n个元素的值，建立带表头结点的单链表L 
      L=new LNode; 
      L->next=NULL; 
	  LinkList r=L;	 //r是尾指针记录尾结点的位置！！尾指针r指向头结点  	                                   
      for(int i=0;i<n;++i)
	  {
		LNode *p; 
       	p=new LNode;
//       	cout<<"请依次输入ISBN，名字，价格"<<endl; 
//        cin>>p->data.price;   		       //输入元素值 
//        cin>>p->data.no;
//        cin>>p->data.name;
		p->next=NULL; 
		r->next=p;       //插入到表尾 
        r=p; 	                                  //r指向新的尾结点 
      } 
      cout<<"尾插法创建链表完成"<<endl;
      return; 
}

void readfile(LinkList &s)//读取文件内容到顺序表中 
{
	ifstream is("book.txt");
	if(!is)
		exit(0);
	//读取文件标题 
	char title[50];
	char ISBNTitle[20];
	char nameTitle[20];
	char priceTitle[20];
	is>>title;
	is>>ISBNTitle>>nameTitle>>priceTitle;
	//读取文件内容到顺序表中
//	s=new LNode; 
//    s->next=NULL; 
//	LinkList r=s;	 //r是尾指针记录尾结点的位置！！尾指针r指向头结点  	                                
//   while(is!=NULL)//用while（is!=NULL）会多读一份文件！不知道为什么！ 
//	  {
//		LNode *p; 
//       	p=new LNode;
//		is>>p->data.no>>p->data.name>>p->data.price;
//		p->next=NULL; 
//		r->next=p;       //插入到表尾 
//        r=p;
//        cout<<p->data.no<<"    "<<p->data.name<<"     "<<p->data.price<<endl;
//	  }
//头插法： 
	for(int i=0;i<108;i++)
	{
		LNode *p;
		p=new LNode;
		 is>>p->data.no>>p->data.name>>p->data.price;
		 p->next=s->next;
		 s->next=p;
		 cout<<p->data.no<<"    "<<p->data.name<<"     "<<p->data.price<<endl;
	 }     
	is.close();
}



int main()
{
	LinkList l;
	InitList(l);
	//CreateList_F(l,N);
	readfile(l);
	ListLength_L(l);
	cout<<"1"<<endl;
	return 0;
}
