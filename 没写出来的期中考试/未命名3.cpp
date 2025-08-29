#include "iostream"

#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;

typedef struct LNode {
	int data; /* 存储数字 */
	LNode *next; /* 指向下一个结点的指针 */
}*PtrToNode;

typedef PtrToNode List;

void K_Reverse(List &L, int K)
{
	int i=1;
	List p=L->next,q,r;
	L->next=NULL;
	for(i=1;i<=K;i++)
	{
		q=p->next;
		r=p->next;
		p->next=L->next;
		L->next=p;
		p=q;	
	}
	p=L->next;

	for(i=1;i<K;i++)
	{
		p=p->next;
	}
	p->next=r;
}


List ReadInput(int num)
{	
	//读入链表数据
	int i;
	List L, p, rear;
	L = new LNode();
	L->next= NULL;
	rear = L;//链表尾
	for (i = 0; i<num; i++)
	{
		p = new LNode();
		cin >> p->data;
		p->next = NULL;
		rear->next = p;
		rear = p;
	}
	return L;
}
void PrintList(List &L)
{
	//按顺序输出链表
	List p;
	p = L->next;
	while (p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}

}

int main()
{
	List L;  //定义一个链表L
	int num;
	cin >> num;
	L = ReadInput(num);
	int K;
	cin >> K;
	K_Reverse(L, K);
	PrintList(L);
	return 0;
}


