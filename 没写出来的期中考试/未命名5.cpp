#include <stdio.h>
#include <stdlib.h>
#include "iostream"
using namespace std;

struct LNode {
	int data;
	struct LNode *next;
};
typedef LNode* PtrLNode;

PtrLNode readlist()
{
//���ݶ������ݴ���������
	LNode* L=new LNode;
	L->next=NULL;
	PtrLNode p,q;
	//p=new LNode;
	//L->next=p;//������ʹ����Ԫ�ڵ��ֵΪ�գ� 
	//p->next=NULL;
	p=L;
	int num;
	while(cin>>num)
	{
		if(num==-1)
			break;
		q=new LNode;
		q->next=NULL;
		q->data=num;
		p->next=q;
		p=q;
	}
	return L;
}
PtrLNode getodd(PtrLNode &L)
{
//��L���������ó������ɵ�������
	PtrLNode p=L->next;
	PtrLNode L1=new LNode;
	//L1->next==NULL;
	PtrLNode q=L1->next,r;
	q->next==NULL;
	while(p)
	{
		if(p->next->data%2==1)
		{
			r=p->next;
			p->next=p->next->next;
			q->next=r;
			q=r;
		}
		p=p->next;
	}
    return L1;
}

void printlist(PtrLNode L)
{
	PtrLNode p = L->next;
	while (p) 
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	PtrLNode L,Odd;
	L = readlist();
	Odd = getodd(L);
	printlist(Odd);
	printlist(L);
	return 0;
}

