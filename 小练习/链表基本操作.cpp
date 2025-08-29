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
	string no;//ͼ��ISBN  
	string name;//ͼ������ 
	float price;//ͼ��۸�	
}Book;
typedef struct LNode
{
	Book data;
	struct LNode *next;  
}LNode,*LinkList;

Status InitList(LinkList &L)//�������� 
{
	L=new LNode;
	L->next=NULL;
	cout<<"���������"<<endl;
	return OK;
} 
Status GetElem(LinkList L,int i,Book &e)//��ȡԪ�� 
{
	LinkList p;//p��һ��ָ�룡 
	p=L->next;//pָ����Ԫ�ڵ� 
	int j;
	j=1;
	while(p&&j<i)//��С��i��ʱ�򣬲���˳�����ϲ��� 
	{
		p=p->next;
		j++;
	}
	if(p!=NULL||j>i)
		return ERROR;
	e=p->data;//��ȡ���Ԫ�� 
	return OK;
}
LNode *LocateElem(LinkList L,Book e)//���� 
{
	LinkList p;
	p=L->next;//ָ��ͷ��ַ 
	while(p&&p->data.price==e.price)
		p=p->next;//�������� 
	return p; //����ָ��ָ���ֵ�� 
}
Status LinkInsert(LinkList &L,int i,Book e)//���� 
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
		LinkList s;//��Ҫ�����±�������ö����ָ�룡 
	s=new LNode;
	s->data=e;//������ 
	s->next=p->next;//ָ���ԭ��pָ�����һ���ڵ���sָ�����һ���ڵ�
	return OK; 
}
Status DestroyList_L(LinkList &L)//�������������������������ȫ��ɾ���� 
{
    LinkList p;//ע�⣬�����һ����ָ�룡 
       while(L)
        {
            p=L;  
            L=L->next;
            delete p;  
        }
     return OK;
 }

Status ListDelete(LinkList &L,int i)//ɾ������ 
{
	LinkList p=L,q;//ָ��ͷ�ڵ㣡 
	int j=0;
	while((p->next)&&(j<i-1))//�ҵ���i-1���ڵ�λ�ü�ɾ���ڵ��ǰһ���ڵ� 
	{
		p=p->next;
		++j;
	}
	if(p->next==NULL||(j>i-1))//�ж�λ�úϷ���� 
		return ERROR;
	q=p->next;//��ʱ����p����Ϣ����p����һ���ڵ���q����Ϊ����p->next->next�� 
	p->next=q->next; //�� 
	delete p;
	return OK;
}

Status ClearList(LinkList & L)// ��L����Ϊ�ձ� 
{  
   LinkList p,q;
   p=L->next;   //pָ���һ�����
   while(p)       //û����β 
      {  q=p->next; delete p;     p=q;   }
   L->next=NULL;   //ͷ���ָ����Ϊ�� 
   return OK;
 }
//���
int  ListLength_L(LinkList L){
//����L������Ԫ�ظ���
    LinkList p;
    p=L->next;  //pָ���һ�����
    int i=0;             
    while(p!=NULL)
	{//����������,ͳ�ƽ����
        i++;
        p=p->next;    
	} 
	cout<<i<<endl;
    return i;                             
 }

void CreateList_F(LinkList &L,int n)//CreateList_F 
{ 
     L=new LNode; 
     L->next=NULL; //�Ƚ���һ����ͷ���ĵ����� 
	 for(int i=n;i>0;--i)
	 { 
        LinkList p;
		p=new LNode; //�����½��
//		cout<<"����������ISBN�����֣��۸�"<<endl; 
//        cin>>p->data.no;   		       //����Ԫ��ֵ 
//        cin>>p->data.name;
//        cin>>p->data.price; //����Ԫ��ֵ //�����->�Ͳ��У���֪��Ϊʲô�� 
        p->next=L->next;//ǰ�巨�� 
		L->next=p; 	//���뵽��ͷ 
     } 
    
     cout<<"ǰ�巨�����������"<<endl;
}

void CreateList_L(LinkList &L,int n)//CreateList_L 
{ 
      //��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L 
      L=new LNode; 
      L->next=NULL; 
	  LinkList r=L;	 //r��βָ���¼β����λ�ã���βָ��rָ��ͷ���  	                                   
      for(int i=0;i<n;++i)
	  {
		LNode *p; 
       	p=new LNode;
//       	cout<<"����������ISBN�����֣��۸�"<<endl; 
//        cin>>p->data.price;   		       //����Ԫ��ֵ 
//        cin>>p->data.no;
//        cin>>p->data.name;
		p->next=NULL; 
		r->next=p;       //���뵽��β 
        r=p; 	                                  //rָ���µ�β��� 
      } 
      cout<<"β�巨�����������"<<endl;
      return; 
}

void readfile(LinkList &s)//��ȡ�ļ����ݵ�˳����� 
{
	ifstream is("book.txt");
	if(!is)
		exit(0);
	//��ȡ�ļ����� 
	char title[50];
	char ISBNTitle[20];
	char nameTitle[20];
	char priceTitle[20];
	is>>title;
	is>>ISBNTitle>>nameTitle>>priceTitle;
	//��ȡ�ļ����ݵ�˳�����
//	s=new LNode; 
//    s->next=NULL; 
//	LinkList r=s;	 //r��βָ���¼β����λ�ã���βָ��rָ��ͷ���  	                                
//   while(is!=NULL)//��while��is!=NULL������һ���ļ�����֪��Ϊʲô�� 
//	  {
//		LNode *p; 
//       	p=new LNode;
//		is>>p->data.no>>p->data.name>>p->data.price;
//		p->next=NULL; 
//		r->next=p;       //���뵽��β 
//        r=p;
//        cout<<p->data.no<<"    "<<p->data.name<<"     "<<p->data.price<<endl;
//	  }
//ͷ�巨�� 
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
