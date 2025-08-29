/*#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
#define N 300
#define OVERFLOW 0
#define OK 1
#define ERROR -1
#define MAXSIZE 200
using namespace std;
typedef struct
{
	char no[20]; //ͼ��ISBN 
	char name[50];//ͼ������ 
	float price;//ͼ��۸�	
}Book;
typedef struct
{
	Book *elem;//�洢�ռ�Ļ���ַ 
	int length;	
}SqList;
void bookstatistics(SqList &l)
{
	cout<<"�ܹ��У� "<<l.length+1<<"����"<<endl;
}
void InitList(SqList &l);
void readfile(SqList &s);
void  finding(SqList l);
void locationfinding(SqList s);
void namefinding(SqList l);
void  finding(SqList l);
void wrongInput();
void browseAll(SqList l);
void UpdatePrice(SqList &l,SqList &l1);
void writefile(SqList l,char filename[]);
void PriceSort(SqList &l2);
void newinverseSort(SqList &l); 
void Insert(SqList &L);
void ListDelete_Sq(SqList &L);
void bookstatistics(SqList &l);
int main()
{
SqList s,l;
InitList(s);
InitList(l);
readfile(s);
//for(int i=0;i<s.length;i++)
//	{
////		cout<<"1"<<endl;
//		l.elem[i]=s.elem[i]; 
//		cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;	
//	}
//	for(int i=0;i<l.length;i++)//ע�⣬��ѭ�����һ��=�ţ��Ͷ�һ��0������ע��ѭ�������� 
//	//cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;
//	browseAll(l);
//namefinding(s); 
//locationfinding(s);
//finding(s);
UpdatePrice(s,l); 
//PriceSort(l);
//newinverseSort(s);
//Insert(s);
//ListDelete_Sq(s) ; 
		return 0;
}

void  finding(SqList l)
{
	while(1)
	{
		cout<<endl; 
	cout<<"��ѡ��������ͣ�"<<endl;
	cout<<"��λ�ý��в���(1)"<<endl;
	cout<<"���������в���(2)"<<endl;
	cout<<"������һ��(��1,2�ż�)"<<endl;
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
void wrongInput()
 {
 	cout<<"����������������룡"<<endl;
 	return; 
 }

void InitList(SqList &l) //����һ���յ�˳���L
{
	l.elem=new Book[MAXSIZE];   //Ϊ˳������ռ�
    if(!l.elem) 
		exit(0);       //�洢����ʧ��
    l.length=0;	            	  //�ձ���Ϊ0
    return;
}
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
	//cout<<title<<endl;
	is>>ISBNTitle>>nameTitle>>priceTitle;
	//cout<<ISBNTitle<<"   "<<nameTitle<<"   "<<priceTitle<<endl;
	//��ȡ�ļ����ݵ�˳�����
	while(is>>s.elem[s.length].no>>s.elem[s.length].name>>s.elem[s.length].price)
		s.length++;		
	is.close();
}
//���¼۸�
void UpdatePrice(SqList &l,SqList &l1)
{
	//lΪԭ���ļ��е����ݣ�����֮������ݴ�����l1�� 
	for(int i=0;i<l.length;i++)
	{
		l1.elem[i]=l.elem[i];
		l1.length++;	
	}//������֮������ݲ��ܱ��棬��֪��Ϊʲô�� ���������ӳ����ˣ� 
	for(int i=0;i<l1.length;i++)
	{
		if(l1.elem[i].price<45)		
			l1.elem[i].price=l1.elem[i].price*1.2;
		else
			l1.elem[i].price=l1.elem[i].price*1.1;
	}
	browseAll(l1);
	char filename[]="book-newprice.txt";
	writefile(l1,filename);
	return;
}
void browseAll(SqList l)
{
//	cout<<"������ҵ��ѧͼ��ݼ������ͼ��ɹ��б�"<<endl;
//	cout<<"    ISBN	          "<<"����	                    "<<"����"<<endl;
	cout<<"--------------------------------------------------------"<<endl;
	for(int i=0;i<l.length;i++)//ע�⣬��ѭ�����һ��=�ţ��Ͷ�һ��0������ע��ѭ�������� 
	cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;
	return;
}
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
//�۸����� 
void PriceSort(SqList &l2)
{
	InitList(l2);
	readfile(l2);//��l2Ϊԭ��book�ļ�����Ϣ 
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
	browseAll(l2);
	char filename[]="book-newsort.txt"; 
	writefile(l2,filename);
	return; 
}
//����洢 
void newinverseSort(SqList &l)
{
	Book c;
	for(int i=0;i<l.length/2;i++)
	{	
		c=l.elem[i];
		l.elem[i]=l.elem[l.length-1-i];
		l.elem[l.length-1-i]=c;	
	} 
	browseAll(l);
	bookstatistics(l); 
	char filename[]="book-newinverse.txt";
	writefile(l,filename);
	return; 
}
//����Ԫ�� 
void Insert(SqList &L)
{
	Book e;
	int i;
	C:; 
	cout<<"����������λ��"<<endl;
	cin>>i; 
	if(i<1 || i>L.length+1)//iֵ���Ϸ��� 
	{
		cout<<"����λ�÷Ƿ�����ѡ��������������Ƿ�����һ���˵���"<<endl;
		cout<<"�������룬�밴1"<<endl;
		cout<<"������һ���밴��1�����ּ�"<<endl;
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
   	for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
     cout<<"������������ı��: "<<endl;
	 cin>>e.no;
	 cout<<"�����������������"<<endl;
	 cin>>e.name;
	 cout<<"������������ļ۸�" <<endl;
	 cin>>e.price; 
	 L.elem[i-1]=e;                     //����Ԫ��e�����i��λ��
     ++L.length;//����1
	 browseAll(L);
	 bookstatistics(L);	
	 char filename[]="book.txt";
	 writefile(L,filename);	     	
     return ;
	}
} 
//ɾ��Ԫ�� 
void ListDelete_Sq(SqList &L)
{
	int i;
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
	for(int j=i;j<L.length;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;//��-1�� 
		browseAll(L);
	bookstatistics(L);
	char filename[]="book.txt";
	 writefile(L,filename);	   	
  	return ;
	}	
}











//lΪԭ���ļ��е����ݣ�����֮������ݴ�����l1�� 
//	for(int i=0;i<l.length;i++)
//	{
//		l1.elem[i]=l.elem[i];
//		l1.length++;	
//	}//������֮������ݲ��ܱ��棬��֪��Ϊʲô�� ���������ӳ����ˣ� 
//SqList s;
//createSqList(s);
//	ifstream is("book.txt");
//	if(!is)
//	{
//		exit(0);
//	}
//	is>>title;
//	cout<<title<<endl;
//	is>>ca1>>ca2>>ca3;
//	cout<<ca1<<"   "<<ca2<<"   "<<ca3<<endl;
//	
//	//Book c; 
//	while(is>>s.elem[s.length].no>>s.elem[s.length].name>>s.elem[s.length].price)
//	{
//		s.length++;
//	}
//	for(int i=0;i<s.length;i++)//ע�⣬��ѭ�����һ��0������ 
//	{
//		cout<<s.elem[i].no<<"   "<<s.elem[i].name<<"   "<<s.elem[i].price<<"   "<<endl;
//	}
//	is.close();
//	return 0;
//}
//	for(i=0;!feof(fp);i++)
//	{
//		fscanf(fp,"%s%s%f",b[i].no,b[i].name,&b[i].price);
//		cout<<b[i].no<<"  "<<b[i].name<<"  "<<b[i].price<<endl;
//	}
//	cout<<i+1<<endl;
//	for(int j=0;j<=i;j++)
//	{
//		strcpy(s.elem[j].no,b[j].no);
//		strcpy(s.elem[j].name,b[j].name);
//		s.elem[j].price=b[j].price; 
//	s.elem[j]=b[j];
//		cout<<s.elem[j].no<<"  "<<s.elem[j].name<<"  "<<s.elem[j].price<<endl;
//	}
//	delete []b;
	//delete []s.elem;
//	for(int i=0;!feof(fp);i++)
//	{
//	fscanf(fp,"%s %s %lf",s.elem[i].no,s.elem[i].name,&s.elem[i].price);
//	cout<<s.elem[i].no<<"  "<<s.elem[i].no<<"  "<<s.elem[i].price<<endl;
//	}
//	InitList_Sq(s);
//		ListInsert_Sq(s,i,c);
//	cout<<GetLength(s)<<endl;
//	cout<<IsEmpty<<endl;
//int i=0;
//	fstream myfile;
//	myfile.open("book.txt",ios::in);
//	if(!myfile)
//	{
//		cout<<"Cannot open the test.txt file.\n";
//		exit(0);
//	}
//	Book b[N];
//	myfile>>b[0].no>>b[0].name>>b[0].price;
//	if (myfile.eof()) {
//			break;
//	}
//cout<<"1"<<endl;
//		cout << b[0].no << "\t";
//		cout<<"1"<<endl;
//		myfile.close();
//	cout<<"����\tѧ��\t�ɼ�\n";
//	for(i=0;i<N;i++)
//	{
//		myfile.read((char *)&b[i],sizeof(Book));
//		cout<<b[i].no<<"\t"<<b[i].name<<"\t"<<b[i].price<<"\n";
//	}
//	myfile.close();
//���ھ����ýṹ�����ȫû�����⣬����һ�õ��ṹ��ָ���ʱ�򣬾����˴������ˣ��ṹ��ָ��ָ��������⣡
//���ԣ�������Ҫ�������ýṹ�����Щ������д�ã�Ȼ����ȥ������
//����flag����¼�Լ���û�ж����ļ��� 
//	int InitList_Sq(SqList L);
//	Book b[N];
//	FILE *fp;
	
//���ڶ��ļ��� 
	/*SqList s;
	InitList_Sq(s);
//		s.elem=new Book[N];
	fp=fopen("book.txt","r");
	int i=0;
	if(fp==NULL)
	{
    	printf("fail to open the file! \n");
    	return;
    }
	char title[20];
	char ca1[20];
	char ca2[20];
	char ca3[20];
	fscanf(fp,"%s",title);
	cout<<title<<endl;
	fscanf(fp,"%s %s %s",ca1,ca2,ca3);
	printf("%s   %s   %s\n",ca1,ca2,ca3);
//	for(i=0;!feof(fp);i++)
//	{
		fscanf(fp,"%s %s %f",s.elem[i].no,s.elem[i].name,&s.elem[i].price);
		cout<<"1"<<endl;
		printf("%s   %s   %.0f\n",s.elem[i].no,s.elem[i].name,s.elem[i].price);
//	}//ע�⡣������д����ȫ���ݵĻ�����ô������ռ�û������
	//cout<<"�ܹ���: "<<i<<"����"<<endl;
	//rewind(fp);
	fclose(fp); 
	return;*/

//	SqList s;
//	s=new Book[N];	
//	SqList L;
//	Book b[N];
//	FILE *fp;
//	fp=fopen("book.txt","r");
//	int i=0;
//	if(fp==NULL)
//	{
//    	printf("fail to open the file! \n");
//    	return 0;
//    }
//	while(1)
//	{
//		int j;
//		menu();
//		cin>>j;
//		cout<<"1"<<endl; 
//		switch (j)
//		{
//			case 1:browse();break;
//			case 0:quit();break; 
//			default:
//			{
//				cout<<"�����ѡ������������ѡ��"<<endl;
//			}
//		}
//	}
//browse();
//browse();
//browse();
//int i;
////Book b[N];
//	char title[50];
//	char ca1[20];
//	char ca2[20];
//	char ca3[20];
//	fscanf(fp,"%s",title);
//	printf("%s\n",title);
//	fscanf(fp,"%s %s %s",ca1,ca2,ca3);
//	printf("%s   %s   %s\n",ca1,ca2,ca3);
//	for(i=0;!feof(fp);i++)
//	{
//		fscanf(fp,"%s %s %f",b[i].no,b[i].name,&b[i].price);
//		printf("%s   %s   %.0f\n",b[i].no,b[i].name,b[i].price);
//	}//ע�⡣������д����ȫ���ݵĻ�����ô������ռ�û������

//char ch=fgetc(fp);
//while(ch!=EOF)
//{	putchar(ch);
//	ch=fgetc(fp);	
//}

//	cout<<"�ܹ���: "<<i<<"����"<<endl; 
//	fclose(fp);

//	Status InitList_Sq(SqList &L);//���� 
//	int IsEmpty(SqList L);//����Ƿ�Ϊ�� 
//	int GetLength(SqList L);//��ó��� 
//	Status ListInsert_Sq(SqList &L,int i ,Book e);
//	void DestroyList(SqList &L); 

	
//	Book b[N];
//	Book c;
//	s.elem=new Book[N];
//	if(!s.elem)
//		exit(0);
//	s.length=0;
//void createSqList(SqList &l);
//	SqList s;
//createSqList(s);
//	FILE *fp;
//	fp=fopen("book.txt","r");
//	char title[50];
//	char ca1[30];
//	char ca2[30];
//	char ca3[30];
//	createSqList(s);//λ��1 
//	fscanf(fp,"%s",title);
//	//createSqList(s);//λ��2 
//	printf("%s\n",title);
//	
//	fscanf(fp,"%s %s %s",ca1,ca2,ca3);
//	//cout<<"1"<<endl;
//	printf("%s   %s   %s\n",ca1,ca2,ca3);
//	cout<<"1"<<endl;
////	s.elem=new Book[N];
////	s.length=0;
//
//	for(int i=0;!feof(fp);i++)
//	{
////		cout<<"1"<<endl;
//	fscanf(fp,"%s %s %f",s.elem[i].no,s.elem[i].name,&s.elem[i].price);
//	//cout<<"1"<<endl;
//	cout<<s.elem[i].no<<"  "<<s.elem[i].name<<"  "<<s.elem[i].price<<endl;
//	s.length++;
//	}
//	cout<<"�ܹ��У� "<<s.length+1<<"����"<<endl;

//typedef int  Status;
//int main()
//{
//	Book b[N];
//	FILE *fp;
//	int i; 
//	fp=fopen("book.txt","r");
//	char title[50];
//	char ca1[20];
//	char ca2[20];
//	char ca3[20];
//	fscanf(fp,"%s",title);
//	cout<<title<<endl;
////	cout<<"1"<<endl;
////	fscanf(fp,"%s %s %s",ca1,ca2,ca3);
////	cout<<"1"<<endl;
////	printf("%s   %s   %s\n",ca1,ca2,ca3);
////		cout<<"1"<<endl;
////while (!feof(fp))
////{
////	putchar(fgetc(fp));
////}
//	/*for(i=0;!feof(fp);i++)
//	{
//		fscanf(fp,"%s %s %f",b[i].no,b[i].name,&b[i].price);
//		printf("%s   %s   %.0f\n",b[i].no,b[i].name,b[i].price);
//	}//ע�⡣������д����ȫ���ݵĻ�����ô������ռ�û������*/
//	fclose(fp);
//	return 0;	
//}





















//Status InitList_Sq(SqList &L)              //����һ ���յ�˳���L
//{
//    L.elem=new Book[N];   //Ϊ˳������ռ�
//    if(!L.elem) exit(OVERFLOW);           //�洢����ʧ��
//    L.length=0;				     //�ձ���Ϊ0
////	L.listsize = LIST_INIT_SIZE;           //�����Ա�����ʼ����
//	cout<<"һ���յ����Ա��Ѿ������ɹ�"<<endl;      //��������Ա����ɹ�����ʾ��Ϣ 
//	
//	/*for(int i=0;!feof(fp);i++)
//	{
//	fscanf(fp,"%s%s%f",L.elem[i].no,L.elem[i].name,&L.elem[i].price);
//	cout<<L.elem[i].no<<"  "<<L.elem[i].no<<"  "<<L.elem[i].price<<endl;
//	}*/
//	//fclose(fp);
//	return OK;
//}
//
//void DestroyList(SqList &L)//�ͷŴ洢�ռ�
//{
//  if (L.elem) delete[]L.elem;    
//}
//
//void ClearList(SqList &L) //�����Ա�ĳ�����Ϊ0
//{
//   L.length=0;               
//}
//
//int GetLength(SqList L)//��ó��� 
//{
//   return (L.length);             
//}
//
//Status IsEmpty(SqList L)//����Ƿ�Ϊ�� 
//{
//  if (L.length==0) return 1;      
//   else return 0;
//}
//int GetElem(SqList L,int i,Book &e)//Ѱ�����Ԫ�� 
//{
//  if (i<1||i>L.length) return ERROR;   
//   //�ж�iֵ�Ƿ����������������ERROR
//  e=L.elem[i-1];   //��i-1�ĵ�Ԫ�洢�ŵ�i������
//  return OK;
//}
//int LocateELem(SqList L,Book e)//���ң�ͨ��ֵ���� 
//{
//  	for (int i=0;i< L.length;i++)
//      	if (L.elem[i].price==e.price) return i+1;                
// 	 return 0;
//}
//Status ListInsert_Sq(SqList &L,int i ,Book e)//����һ������ 
//{
//	int j;
//   if(i<1 || i>L.length+1) return ERROR;	         //iֵ���Ϸ�
//   if(L.length==N) return ERROR;    //��ǰ�洢�ռ�����     
//   for(j=L.length-1;j>=i-1;j--) 
//       L.elem[j+1]=L.elem[j];    //����λ�ü�֮���Ԫ�غ���
//    L.elem[i-1]=e;                     //����Ԫ��e�����i��λ��
//    ++L.length;		     	//����1
//    return OK;
//}
///*Status ListDelete_Sq(SqList &L,int i)//ɾ�����ݵĲ��� 
//{
//	int j;
//   if((i<1)||(i>L.length)) 
//   return ERROR;	 //iֵ���Ϸ�
//   for (j=i;j<=L.length-1;j++)                   
//��  ��L.elem[j-1]=L.elem[j];//.elem[j-1]=L.elem[j];       //��ɾ��Ԫ��֮���Ԫ��ǰ��  
//   		--L.length;               	                 //����1
//  return OK;
//}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;



#define ASIZE 256 //ASCII��ĸ������

//1.����׺���齨�����������ֵ䣨map���������жϻ��ַ���pattern�е�λ��
void generateBC(string str, int bc[])
{
	for (int i = 0; i < ASIZE; i++)
	{
		bc[i] = -1;
	}

	for (int i = 0; i < str.size(); i++)
	{
		bc[str[i]] = i;
	}
}

//2.�ú�׺����Ľ���,suffixΪ��׺�ַ���Ӧǰ���λ�ã�prefix�洢���Ƿ����ƥ���ǰ׺�ִ�
void generateGS(string str, int suffix[], bool prefix[])
{
	int n = str.size();
	for (int i = 0; i < n - 1; i++)
	{
		suffix[i] = -1;
		prefix[i] = false;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int j = i;//�ӵ�һ���ַ���ʼ������str[j]
		int k = 0;//���һ���ַ��ı仯����Ӧ�����str[n - 1 - k]
		while (j >= 0 && str[j] == str[n - 1 - k])//�����һ���ַ��Աȣ���������ڶ���
		{
			j--;
			k++;
			suffix[k] = j + 1;//���k=1������һ���ַ����ȵĺ�׺��Ӧƥ��λ�õ�ֵ
		}
		if (j == -1)//˵����ǰ׺�ַ���Ӧ
			prefix[k] = true;
	}

}

//3.���غú�׺�ƶ��Ĵ���,indexΪ���ַ�λ��-�������Ǻú�׺��sizeΪstr��С
int getGsMove(int suffix[], bool prefix[], int index, int size)
{
	int len = size - index - 1;//���ַ��ĳ��ȣ���ΪindexΪ���ַ�λ�ã�����Ҫ���1
	if (suffix[len] != -1)//��ǰlen���ȵĺ�׺���ַ���ǰ����ƥ����ַ�
	{
		return index + 1 - suffix[len];//����λ�� = �ú�׺��λ��(index + 1) - �������е���һ�γ���λ��
	}

	//indexΪ���ַ���index+1Ϊ�ú�׺��index+2Ϊ�Ӻú�׺
	for (int i = index + 2; i < size; i++)
	{
		if (prefix[size - i])//��Ϊprefix��1��ʼ
			return i;//�ƶ���ǰλ����ǰ׺λ�ã�acba-��Ӧa�ƶ�3
	}

	return 0;

}




//4.�����ҵ�ƥ���ַ�����ͷ�����򷵻�-1
int BM(string str, string pattern)
{
	int n = str.size();
	int m = pattern.size();
	int bc[ASIZE];//���ַ�����
	int* suffix = (int *)malloc(sizeof(int) * m);
	bool* prefix = (bool *)malloc(sizeof(bool) * m);;

	generateBC(pattern, bc);
	generateGS(pattern, suffix, prefix);

	int i = 0;
	while (i <= n - m)
	{
		int j = 0;
		for (j = m - 1; j >= 0; j--)
		{
			if (pattern[j] != str[i + j])//�Ӻ���ǰƥ��str��pattern
				break;
		}
		if (j < 0)//ƥ�����
			return i;
		else     
		{
			int numBc = j - bc[str[i + j]];//bc�ƶ���λ��
			int numGs = 0;
			if (j < m - 1)//���һ���ַ����ǻ��ַ��������жϺ��ַ�
			{
				numGs = getGsMove(suffix, prefix, j, m);//Gs�ƶ���λ��
			}
			i += numBc > numGs ? numBc : numGs;
		}
	}


	return -1;
}

int main()
{
	string a,b;
	cin>>a>>b;
	cout << BM(a, b) << endl;

}




