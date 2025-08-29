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
	char no[20]; //图书ISBN 
	char name[50];//图书名字 
	float price;//图书价格	
}Book;
typedef struct
{
	Book *elem;//存储空间的基地址 
	int length;	
}SqList;
void bookstatistics(SqList &l)
{
	cout<<"总共有： "<<l.length+1<<"本书"<<endl;
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
//	for(int i=0;i<l.length;i++)//注意，若循环多加一个=号，就多一个0，所以注意循环条件！ 
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
	cout<<"请选择查找类型："<<endl;
	cout<<"按位置进行查找(1)"<<endl;
	cout<<"按书名进行查找(2)"<<endl;
	cout<<"返回上一层(非1,2号键)"<<endl;
	cout<<"请输入： "<<endl;
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
	cout<<"请输入你要查询的位置:"<<endl;
	int num;
	cin>>num;
	if(num>=s.length||num<0)
	{
	cout<<"输入位置非法，请选择重新输入或者是返回上一级菜单："<<endl;
	cout<<"重新输入，请按1"<<endl;
		cout<<"返回上一级请按非1的数字键"<<endl;
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
	cout<<"    ISBN	          "<<"书名	                    "<<"定价"<<endl;
	cout<<s.elem[num-1].no<<"   "<<s.elem[num-1].name<<"   "<<s.elem[num-1].price<<endl;
	cout<<"继续查找请按1，返回上层菜单请按非1"<<endl;
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
	cout<<"请输入书名："<<endl;
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
		cout<<"总共查询到： "<<all<<"本书"<<endl;
		cout<<"    ISBN	     "<<"    书名	      "<<"定价"<<endl;
		for(int i=0;i<all;i++)
		{
			cout<<l.elem[namefound[i]].no<<"        "<<
			l.elem[namefound[i]].name<<"        "<<l.elem[namefound[i]].price<<endl;	
		}
		cout<<"继续查找请按1，返回上层菜单请按非1"<<endl;
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
		cout<<"图书信息管理系统中没有这本书，请选择重新输入或者是返回上一级菜单"<<endl;
		cout<<"重新输入，请按1"<<endl;
		cout<<"返回上一级请按非1的数字键"<<endl;
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
 	cout<<"输入错误，请重新输入！"<<endl;
 	return; 
 }

void InitList(SqList &l) //构造一个空的顺序表L
{
	l.elem=new Book[MAXSIZE];   //为顺序表分配空间
    if(!l.elem) 
		exit(0);       //存储分配失败
    l.length=0;	            	  //空表长度为0
    return;
}
void readfile(SqList &s)//读取文件内容到顺序表中 
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
	//cout<<title<<endl;
	is>>ISBNTitle>>nameTitle>>priceTitle;
	//cout<<ISBNTitle<<"   "<<nameTitle<<"   "<<priceTitle<<endl;
	//读取文件内容到顺序表中
	while(is>>s.elem[s.length].no>>s.elem[s.length].name>>s.elem[s.length].price)
		s.length++;		
	is.close();
}
//更新价格
void UpdatePrice(SqList &l,SqList &l1)
{
	//l为原来文件中的数据，更改之后的数据存入了l1中 
	for(int i=0;i<l.length;i++)
	{
		l1.elem[i]=l.elem[i];
		l1.length++;	
	}//这块更改之后的数据不能保存，不知道为什么！ 是忘记增加长度了！ 
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
//	cout<<"北京林业大学图书馆计算机类图书采购列表"<<endl;
//	cout<<"    ISBN	          "<<"书名	                    "<<"定价"<<endl;
	cout<<"--------------------------------------------------------"<<endl;
	for(int i=0;i<l.length;i++)//注意，若循环多加一个=号，就多一个0，所以注意循环条件！ 
	cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;
	return;
}
void writefile(SqList l,char filename[])
{
	ofstream of;
	of.open(filename, ios::out);
	of<<"北京林业大学图书馆计算机类图书采购列表"<<endl; 
	of<<"ISBN	                  书名	                定价"<<endl;
	for(int i=0;i<l.length;i++)
	{
		of<<l.elem[i].no<<"          "<<l.elem[i].name<<"      "<<l.elem[i].price<<endl;
	}
	of.close();
 } 
//价格排序： 
void PriceSort(SqList &l2)
{
	InitList(l2);
	readfile(l2);//让l2为原来book文件的信息 
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
//逆序存储 
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
//插入元素 
void Insert(SqList &L)
{
	Book e;
	int i;
	C:; 
	cout<<"请输入插入的位置"<<endl;
	cin>>i; 
	if(i<1 || i>L.length+1)//i值不合法， 
	{
		cout<<"输入位置非法，请选择重新输入或者是返回上一级菜单："<<endl;
		cout<<"重新输入，请按1"<<endl;
		cout<<"返回上一级请按非1的数字键"<<endl;
		int op;
		cin>>op;
		switch(op)
		{
			case 1:goto C;break;
			default: return;
		}	
	}
	else if(L.length==MAXSIZE)//当前存储空间已满
	{
		cout<<"顺序表已满，无法插入"<<endl;
		return;	
	}
	else
	{	             
   	for(int j=L.length-1;j>=i-1;j--) 
       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
     cout<<"请输入增加书的编号: "<<endl;
	 cin>>e.no;
	 cout<<"请输入增加书的书名"<<endl;
	 cin>>e.name;
	 cout<<"请输入增加书的价格" <<endl;
	 cin>>e.price; 
	 L.elem[i-1]=e;                     //将新元素e放入第i个位置
     ++L.length;//表长增1
	 browseAll(L);
	 bookstatistics(L);	
	 char filename[]="book.txt";
	 writefile(L,filename);	     	
     return ;
	}
} 
//删除元素 
void ListDelete_Sq(SqList &L)
{
	int i;
	D:; 
	cout<<"请输入删除的位置"<<endl;
	cin>>i; 
   if((i<1)||(i>L.length)) //i值不合法 
   	{
	   cout<<"输入位置非法，请选择重新输入或者是返回上一级菜单："<<endl;
		cout<<"重新输入，请按1"<<endl;
		cout<<"返回上一级请按非1的数字键"<<endl;
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
	--L.length;//表长-1！ 
		browseAll(L);
	bookstatistics(L);
	char filename[]="book.txt";
	 writefile(L,filename);	   	
  	return ;
	}	
}











//l为原来文件中的数据，更改之后的数据存入了l1中 
//	for(int i=0;i<l.length;i++)
//	{
//		l1.elem[i]=l.elem[i];
//		l1.length++;	
//	}//这块更改之后的数据不能保存，不知道为什么！ 是忘记增加长度了！ 
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
//	for(int i=0;i<s.length;i++)//注意，若循环多加一个0，所以 
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
//	cout<<"姓名\t学号\t成绩\n";
//	for(i=0;i<N;i++)
//	{
//		myfile.read((char *)&b[i],sizeof(Book));
//		cout<<b[i].no<<"\t"<<b[i].name<<"\t"<<b[i].price<<"\n";
//	}
//	myfile.close();
//现在就是用结构体就完全没有问题，但是一用到结构体指针的时候，就有了大问题了，结构体指针指向就有问题！
//所以，我现在要就是先用结构体把这些函数都写好，然后再去修正！
//设置flag来记录自己有没有读过文件！ 
//	int InitList_Sq(SqList L);
//	Book b[N];
//	FILE *fp;
	
//关于读文件： 
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
//	}//注意。如果这的写读不全数据的话，那么就是你空间没开够！
	//cout<<"总共有: "<<i<<"本书"<<endl;
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
//				cout<<"输入的选项有误，请重新选择"<<endl;
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
//	}//注意。如果这的写读不全数据的话，那么就是你空间没开够！

//char ch=fgetc(fp);
//while(ch!=EOF)
//{	putchar(ch);
//	ch=fgetc(fp);	
//}

//	cout<<"总共有: "<<i<<"本书"<<endl; 
//	fclose(fp);

//	Status InitList_Sq(SqList &L);//构造 
//	int IsEmpty(SqList L);//检测是否为空 
//	int GetLength(SqList L);//获得长度 
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
//	createSqList(s);//位置1 
//	fscanf(fp,"%s",title);
//	//createSqList(s);//位置2 
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
//	cout<<"总共有： "<<s.length+1<<"本书"<<endl;

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
//	}//注意。如果这的写读不全数据的话，那么就是你空间没开够！*/
//	fclose(fp);
//	return 0;	
//}





















//Status InitList_Sq(SqList &L)              //构造一 个空的顺序表L
//{
//    L.elem=new Book[N];   //为顺序表分配空间
//    if(!L.elem) exit(OVERFLOW);           //存储分配失败
//    L.length=0;				     //空表长度为0
////	L.listsize = LIST_INIT_SIZE;           //给线性表分配初始容量
//	cout<<"一个空的线性表已经构建成功"<<endl;      //输出空线性表构建成功的提示消息 
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
//void DestroyList(SqList &L)//释放存储空间
//{
//  if (L.elem) delete[]L.elem;    
//}
//
//void ClearList(SqList &L) //将线性表的长度置为0
//{
//   L.length=0;               
//}
//
//int GetLength(SqList L)//获得长度 
//{
//   return (L.length);             
//}
//
//Status IsEmpty(SqList L)//检测是否为空 
//{
//  if (L.length==0) return 1;      
//   else return 0;
//}
//int GetElem(SqList L,int i,Book &e)//寻找这个元素 
//{
//  if (i<1||i>L.length) return ERROR;   
//   //判断i值是否合理，若不合理，返回ERROR
//  e=L.elem[i-1];   //第i-1的单元存储着第i个数据
//  return OK;
//}
//int LocateELem(SqList L,Book e)//查找，通过值查找 
//{
//  	for (int i=0;i< L.length;i++)
//      	if (L.elem[i].price==e.price) return i+1;                
// 	 return 0;
//}
//Status ListInsert_Sq(SqList &L,int i ,Book e)//插入一个数据 
//{
//	int j;
//   if(i<1 || i>L.length+1) return ERROR;	         //i值不合法
//   if(L.length==N) return ERROR;    //当前存储空间已满     
//   for(j=L.length-1;j>=i-1;j--) 
//       L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
//    L.elem[i-1]=e;                     //将新元素e放入第i个位置
//    ++L.length;		     	//表长增1
//    return OK;
//}
///*Status ListDelete_Sq(SqList &L,int i)//删除数据的操作 
//{
//	int j;
//   if((i<1)||(i>L.length)) 
//   return ERROR;	 //i值不合法
//   for (j=i;j<=L.length-1;j++)                   
//　  　L.elem[j-1]=L.elem[j];//.elem[j-1]=L.elem[j];       //被删除元素之后的元素前移  
//   		--L.length;               	                 //表长减1
//  return OK;
//}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;



#define ASIZE 256 //ASCII字母的种类

//1.坏后缀数组建立，类似于字典（map），用于判断坏字符在pattern中的位置
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

//2.好后缀数组的建立,suffix为后缀字符对应前面的位置，prefix存储：是否存在匹配的前缀字串
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
		int j = i;//从第一个字符开始遍历，str[j]
		int k = 0;//最后一个字符的变化，对应下面的str[n - 1 - k]
		while (j >= 0 && str[j] == str[n - 1 - k])//和最后一个字符对比，相等则倒数第二个
		{
			j--;
			k++;
			suffix[k] = j + 1;//如果k=1，则是一个字符长度的后缀对应匹配位置的值
		}
		if (j == -1)//说明有前缀字符对应
			prefix[k] = true;
	}

}

//3.返回好后缀移动的次数,index为坏字符位置-其后面就是好后缀，size为str大小
int getGsMove(int suffix[], bool prefix[], int index, int size)
{
	int len = size - index - 1;//好字符的长度，因为index为坏字符位置，所以要多减1
	if (suffix[len] != -1)//当前len长度的后缀坏字符串前边有匹配的字符
	{
		return index + 1 - suffix[len];//后移位数 = 好后缀的位置(index + 1) - 搜索词中的上一次出现位置
	}

	//index为坏字符，index+1为好后缀，index+2为子好后缀
	for (int i = index + 2; i < size; i++)
	{
		if (prefix[size - i])//因为prefix从1开始
			return i;//移动当前位置离前缀位置，acba-对应a移动3
	}

	return 0;

}




//4.返回找到匹配字符串的头，否则返回-1
int BM(string str, string pattern)
{
	int n = str.size();
	int m = pattern.size();
	int bc[ASIZE];//坏字符数组
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
			if (pattern[j] != str[i + j])//从后往前匹配str和pattern
				break;
		}
		if (j < 0)//匹配结束
			return i;
		else     
		{
			int numBc = j - bc[str[i + j]];//bc移动的位数
			int numGs = 0;
			if (j < m - 1)//最后一个字符就是坏字符，无需判断好字符
			{
				numGs = getGsMove(suffix, prefix, j, m);//Gs移动的位数
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




