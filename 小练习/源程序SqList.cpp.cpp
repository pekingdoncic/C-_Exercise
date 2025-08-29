#include <stdio.h>
#include <iostream>
using namespace std; 
#include <string.h>
#include <fstream>
#define MAXSIZE 200
typedef struct
{
	char no[20]; //ͼ��ISBN 
	char name[50];//ͼ������ 
	float price;//ͼ��۸�	
}Book;
typedef struct
{
	Book *elem;//�洢�ռ�Ļ���ַ 
	int length;	//˳����� 
}SqList;//

void menu();//һ�����˵�
void readfile(SqList &l);//��ȡ�ļ�
void InitList(SqList &l); //��ʼ�����Ա�
void writefile(SqList l,char filename[]);//д�ļ� 
 
void  finding(SqList l);//����Ԫ��
void locationfinding(SqList s);//λ�ò��� 
void namefinding(SqList l); //�������� 

void Insert(SqList &L,bool &flag);//����Ԫ�� 
void ListDelete_Sq(SqList &L,bool &flag);//ɾ��Ԫ�� 
 
void browseAll(SqList l,bool b,bool &flag);//�������ͼ����Ϣ 
void bookstatistics(SqList &l,bool b,bool &flag);//ͳ������ͼ�鱾�顣 
void UpdatePrice(SqList &l1,bool &flag);//���¼۸� 
void PriceSort(SqList &l2,bool &flag);//�۸��������� 
void newinverseSort(SqList &l,bool &flag);//����洢 
void quit(SqList &l); //�˳����� 

void returnmenu(SqList &s);//�������˵� 
void wrongInput();
void DestroyList(SqList &L);//�������Ա�L 
void ClearList(SqList &L); //������Ա�L


int main()
{
	menu();
	return 0;
}
//���˵� 
void menu()
{
	SqList l;//�����������ǲ��ǿ��Բ������ã������ӾͲ���ı��ˣ�
	InitList(l);
	readfile(l);//��ȡ�ļ�����������û������
	bool flag=0; //flag=0��ʱ�򣬾���Ҫ���¶��ļ�����֤��ȡ����book.txt�ļ��� 
	system("cls");//���� 
	cout<<"************��ӭʹ��ͼ����Ϣ����ϵͳ************"<<endl;
	while(1)
	{
	cout<<"------------------------------------------------"<<endl; 
	cout<<"�������Ҫʹ�õĹ����������Ӧ������"<<endl;
	cout<<"ͼ�����(1)"<<endl;
	cout<<"ͼ��ͳ��(2)"<<endl;
	cout<<"ͼ�����(3)"<<endl;
	cout<<"ͼ��ɾ��(4)"<<endl;
	cout<<"ͼ�����(5)"<<endl;
	cout<<"�۸����(6)"<<endl;
	cout<<"�۸�����(7)"<<endl;
	cout<<"����洢(8)"<<endl;
	cout<<"�˳�ϵͳ(0)"<<endl;
	cout<<"��ѡ�� "<<endl; 
	int i;//ѡ������
	cin>>i;
	switch(i)
	{
		case 1:browseAll(l,0,flag);break;
		case 2:bookstatistics(l,0,flag);break;
		case 3:Insert(l,flag);break;
		case 4:ListDelete_Sq(l,flag);break; 
		case 5:finding(l);break;
		case 6:UpdatePrice(l,flag);break;
		case 7:PriceSort(l,flag);break; 
		case 8:newinverseSort(l,flag);break; 
		case 0:quit(l);break;
		default:wrongInput();
	}
	}
}

//��ʾ���е�ͼ�� 
void browseAll(SqList l,bool b,bool &flag)
{
		if(flag==false)
		{ 	
			DestroyList(l);
			ClearList(l); 
			InitList(l);
			readfile(l);//��ȡ�ļ�����������û������
			flag=true; 
		}
	cout<<"����ͼ��չʾ���£�"<<endl;
	cout<<"������ҵ��ѧͼ��ݼ������ͼ��ɹ��б�"<<endl;
	cout<<"    ISBN	          "<<"����	                    "<<"����"<<endl;
	for(int i=0;i<l.length;i++)//ע�⣬��ѭ�����һ��=�ţ��Ͷ�һ��0������ע��ѭ�������� 
	cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;
	cout<<"------------------------------------------------"<<endl; 
	if(b==false)
	returnmenu(l);	
}

//ͳ��ͼ������ 
void bookstatistics(SqList &l,bool b,bool &flag)
{
		if(flag==false)
		{ 	
			DestroyList(l);
			ClearList(l); 
			InitList(l);
			readfile(l);//��ȡ�ļ�����������û������
			flag=true; 
		}
	cout<<"�ܹ��У� "<<l.length<<"����"<<endl;
	if(b==false)
	returnmenu(l);
}

//���Һ��� 
void  finding(SqList l)
{
	while(1)
	{
	cout<<"��ѡ��������ͣ�"<<endl;
	cout<<"��λ�ý��в���(1)"<<endl;
	cout<<"���������в���(2)"<<endl;
	cout<<"�������˵�(��1,2�ż�)"<<endl;
	cout<<"�����룺 "<<endl;
	int i; 
	cin>>i;
	switch(i)
	{
		case 1:locationfinding(l);break;
		case 2:namefinding(l);break;
		default:return;
	}
	}	
}
//λ�ò��� 
void locationfinding(SqList s)
{
	A:;
	cout<<"��������Ҫ��ѯ��λ��:"<<endl;
	int num;
	cin>>num;
	if(num>=s.length||num<0)
	{
	cout<<"����λ�÷Ƿ�����ѡ��������������Ƿ�����һ���˵���"<<endl;
	cout<<"�������룬�밴1"<<endl;
		cout<<"������һ���밴��1�����ּ�"<<endl;
		int op;
		cin>>op;
		switch(op)
		{
			case 1:goto A;break;
			default: return;
		}	
	}
	else
	{
	cout<<"    ISBN	          "<<"����	                    "<<"����"<<endl;
	cout<<s.elem[num-1].no<<"   "<<s.elem[num-1].name<<"   "<<s.elem[num-1].price<<endl;
	cout<<"���������밴1�������ϲ�˵��밴��1"<<endl;
	int op;
		cin>>op;
		switch(op)
		{
			case 1:goto A;break;
			default: return;
		}	
	}
}
//�������� 
void namefinding(SqList l)
{
	B:;
	cout<<"������������"<<endl;
	char bookname[50];
	int all=0;
	int namefound[50];
	cin>>bookname;
	for(int i=0;i<l.length;i++)
	{
		int compare=strcmp(bookname,l.elem[i].name);
		if(compare==0)
		{
			//cout<<l.elem[i].no<<"  "<<l.elem[i].name<<"  "<<l.elem[i].price<<endl;
			namefound[all]=i;
			all++;
		}
	}
	if(all>0)
	{
		cout<<"�ܹ���ѯ���� "<<all<<"����"<<endl;
		cout<<"    ISBN	     "<<"    ����	      "<<"����"<<endl;
		for(int i=0;i<all;i++)
		{
			cout<<l.elem[namefound[i]].no<<"        "<<
			l.elem[namefound[i]].name<<"        "<<l.elem[namefound[i]].price<<endl;	
		}
		cout<<"���������밴1�������ϲ�˵��밴��1"<<endl;
		int op;
			cin>>op;
			switch(op)
			{
				case 1:goto B;break;
				default: return;
			}	
	}
	if(all==0)
	{
		cout<<"ͼ����Ϣ����ϵͳ��û���Ȿ�飬��ѡ��������������Ƿ�����һ���˵�"<<endl;
		cout<<"�������룬�밴1"<<endl;
		cout<<"������һ���밴��1�����ּ�"<<endl;
		int op;
		cin>>op;
		switch(op)
		{
			case 1:goto B;break;
			default: return;
		}
	}
} 

//���¼۸�
void UpdatePrice(SqList &l1,bool &flag)
{	
	cout<<"ԭ�����鼮��Ϣ"<<endl; 
	browseAll(l1,1,flag);
	for(int i=0;i<l1.length;i++)
	{
		if(l1.elem[i].price<45)		
			l1.elem[i].price=l1.elem[i].price*1.2;
		else
			l1.elem[i].price=l1.elem[i].price*1.1;
	}
	cout<<"���¼۸�֮�����Ϣ"<<endl;
	bool d=true; 
	browseAll(l1,1,d);
	char filename[]="book-newprice.txt";
	writefile(l1,filename);
	flag=false; //�����˵������¶�һ���ļ���ȷ����ʾ����book�ļ������ݡ� 
	returnmenu(l1);
}

//�۸��������� ��ð���㷨�� 
void PriceSort(SqList &l2,bool &flag)
{
	cout<<"ԭ�����鼮��Ϣ"<<endl; 
	browseAll(l2,1,flag);
	for(int i=0;i<l2.length;i++)
	{
		for(int j=0;j<l2.length-1-i;j++)
		{
			if(l2.elem[j+1].price<l2.elem[j].price)
			{
				Book c;
				c=l2.elem[j+1];
				l2.elem[j+1]=l2.elem[j];
				l2.elem[j]=c;
			}
		}
	}	
	cout<<"����֮�������"<<endl;
	bool d=true; 
	browseAll(l2,1,d);
	char filename[]="book-newsort.txt"; 
	writefile(l2,filename);
	flag=false;//ȷ�����˵���ȡ����book.txt��������ݡ� 
	returnmenu(l2);
}

//����洢 
void newinverseSort(SqList &l,bool &flag)
{
	cout<<"ԭ�����鼮��Ϣ"<<endl; 
	browseAll(l,1,flag);
	Book c;
	for(int i=0;i<l.length/2;i++)
	{	
		c=l.elem[i];
		l.elem[i]=l.elem[l.length-1-i];
		l.elem[l.length-1-i]=c;	
	} 
	cout<<"����洢֮�����Ϣ��"<<endl; 
	bool d=true; 
	browseAll(l,1,d);
	char filename[]="book-newinverse.txt";
	writefile(l,filename);
	flag=false;
	returnmenu(l); 
}

//����Ԫ�� 
void Insert(SqList &L,bool &flag)
{
	Book e;
	int i;
	browseAll(L,1,flag);
	cout<<"--------------------------------------------------------"<<endl;
	C:; 
	cout<<"����������λ��"<<endl;
	cin>>i; 
	if(i<1 || i>L.length+1)//iֵ���Ϸ��� 
	{
		cout<<"����λ�÷Ƿ�����ѡ��������������Ƿ�����һ���˵���"<<endl;
		cout<<"�������룬�밴1"<<endl;
		cout<<"�������˵��밴��1�����ּ�"<<endl;
		int op;
		cin>>op;
		switch(op)
		{
			case 1:goto C;break;
			default: return;
		}	
	}
	else if(L.length==MAXSIZE)//��ǰ�洢�ռ�����
	{
		cout<<"˳����������޷�����"<<endl;
		return;	
	}
	else
	{	             
     cout<<"������������ı��: "<<endl;
	 cin>>e.no;
	 cout<<"�����������������"<<endl;
	 cin>>e.name;
	 cout<<"������������ļ۸�" <<endl;
	 cin>>e.price; 
	
     cout<<"������鼮��Ϣ���£�"<<endl;
     cout<<"    ISBN	          "<<"����	                    "<<"����"<<endl;
	 cout<<e.no<<"     "<<e.name<<"   "<<e.price<<endl; 
	 cout<<"ȷ�������\nȷ���밴1\n���������밴2\n�����1��2�������˵�"<<endl;
		int option;
		cin>>option;
	 if(option==1)
	 {
	 	for(int j=L.length-1;j>=i-1;j--) 
       		L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
       	 L.elem[i-1]=e;                     //����Ԫ��e�����i��λ��
     	 ++L.length;//����1
     	browseAll(L,1,flag);
	 	bookstatistics(L,1,flag);	
	 	char filename[]="book.txt";
	 	writefile(L,filename);	     	
     	return ; 
	  } 
	 else if(option==2) 
	 	goto C;
	else
		return; 
	}
} 
//ɾ��Ԫ�� 
void ListDelete_Sq(SqList &L,bool &flag)
{
	int i;
	browseAll(L,1,flag);
	cout<<"--------------------------------------------------------"<<endl;
	D:; 
	cout<<"������ɾ����λ��"<<endl;
	cin>>i; 
   if((i<1)||(i>L.length)) //iֵ���Ϸ� 
   	{
	   cout<<"����λ�÷Ƿ�����ѡ��������������Ƿ�����һ���˵���"<<endl;
		cout<<"�������룬�밴1"<<endl;
		cout<<"������һ���밴��1�����ּ�"<<endl;
		int op;
		cin>>op;
		switch(op)
		{
			case 1:goto D;break;
			default: return;
		}
	}
	else
	{
		cout<<"ɾ������Ϣ���£�"<<endl;
		cout<<"    ISBN	          "<<"����	                    "<<"����"<<endl;
		cout<<L.elem[i-1].no<<"         "<<L.elem[i-1].name<<"       "<<L.elem[i-1].price<<endl;
		cout<<"ȷ��ɾ����\nȷ���밴1\n���������밴2\n�����1��2�������˵�"<<endl;
		int option;
		cin>>option;
		if(option==1)
		{
		for(int j=i;j<L.length;j++)
			L.elem[j-1]=L.elem[j];
		--L.length;//��-1�� 
		 browseAll(L,1,flag);
		 bookstatistics(L,1,flag);
		 char filename[]="book.txt";
	 	 writefile(L,filename);	   	
  		 return ;
		}
		else if(option==2)
			goto D;
		else
			return;
	}	
}

//�˳����� 
void quit(SqList &l)
{
	printf("��ȷ��Ҫ�˳���\n");
	printf("ȷ���˳��밴0�����˳��������˵��������0����\n");
	int i;
	cin>>i;
	if(i==0)
	{
		DestroyList(l);
		ClearList(l); 
		exit(0);
	}
	else
		return; 
 }
//���˵������������󱨴� 
void wrongInput()
 {
 	cout<<"����������������룡"<<endl;
 	return; 
 }

//��ʼ��˳��� 
void InitList(SqList &l) //����һ���յ�˳���l
{
	l.elem=new Book[MAXSIZE];   //Ϊ˳������ռ�
    if(!l.elem) 
		exit(0);       //�洢����ʧ��
    l.length=0;	            	  //�ձ���Ϊ0
    return;
}

//���ļ� 
void readfile(SqList &s)//��ȡ�ļ����ݵ�˳����� 
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
	while(is>>s.elem[s.length].no>>s.elem[s.length].name>>s.elem[s.length].price)
		s.length++;		
	is.close();
}
//д�ļ� 
void writefile(SqList l,char filename[])
{
	ofstream of;
	of.open(filename, ios::out);
	of<<"������ҵ��ѧͼ��ݼ������ͼ��ɹ��б�"<<endl; 
	of<<"ISBN	                  ����	                ����"<<endl;
	for(int i=0;i<l.length;i++)
	{
		of<<l.elem[i].no<<"          "<<l.elem[i].name<<"      "<<l.elem[i].price<<endl;
	}
	of.close();
 } 

//�������Ա�L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;   
 //�ͷŴ洢�ռ�
}
//���˳���L���� 
void ClearList(SqList &L) 
{
	if(L.length!=0)
   		L.length=0;               
 //�����Ա�ĳ�����Ϊ0
}

//�������˵�
void returnmenu(SqList &s)
{
	cout<<"ѡ�񷵻����˵�(��0)����ֱ���˳�(0)��"<<endl;
	int op;
	cin>>op;
	if(op==0)
		quit(s);
	else
		return; 
 } 

