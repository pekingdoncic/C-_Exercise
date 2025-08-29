#include <stdio.h>
#include <iostream>
using namespace std; 
#include <string.h>
#include <fstream>
#define MAXSIZE 200
typedef struct
{
	char no[20]; //图书ISBN 
	char name[50];//图书名字 
	float price;//图书价格	
}Book;
typedef struct
{
	Book *elem;//存储空间的基地址 
	int length;	//顺序表长度 
}SqList;//

void menu();//一个主菜单
void readfile(SqList &l);//读取文件
void InitList(SqList &l); //初始化线性表
void writefile(SqList l,char filename[]);//写文件 
 
void  finding(SqList l);//查找元素
void locationfinding(SqList s);//位置查找 
void namefinding(SqList l); //书名查找 

void Insert(SqList &L,bool &flag);//插入元素 
void ListDelete_Sq(SqList &L,bool &flag);//删除元素 
 
void browseAll(SqList l,bool b,bool &flag);//浏览所有图书信息 
void bookstatistics(SqList &l,bool b,bool &flag);//统计所有图书本书。 
void UpdatePrice(SqList &l1,bool &flag);//更新价格 
void PriceSort(SqList &l2,bool &flag);//价格升序排序 
void newinverseSort(SqList &l,bool &flag);//逆序存储 
void quit(SqList &l); //退出函数 

void returnmenu(SqList &s);//返回主菜单 
void wrongInput();
void DestroyList(SqList &L);//销毁线性表L 
void ClearList(SqList &L); //清空线性表L


int main()
{
	menu();
	return 0;
}
//主菜单 
void menu()
{
	SqList l;//函数传参数是不是可以不用引用？那样子就不会改变了！
	InitList(l);
	readfile(l);//读取文件不这样里面没东西！
	bool flag=0; //flag=0的时候，就需要重新读文件！保证读取的是book.txt文件！ 
	system("cls");//清屏 
	cout<<"************欢迎使用图书信息管理系统************"<<endl;
	while(1)
	{
	cout<<"------------------------------------------------"<<endl; 
	cout<<"请根据需要使用的功能输入相对应的数字"<<endl;
	cout<<"图书浏览(1)"<<endl;
	cout<<"图书统计(2)"<<endl;
	cout<<"图书插入(3)"<<endl;
	cout<<"图书删除(4)"<<endl;
	cout<<"图书查找(5)"<<endl;
	cout<<"价格更新(6)"<<endl;
	cout<<"价格排序(7)"<<endl;
	cout<<"逆序存储(8)"<<endl;
	cout<<"退出系统(0)"<<endl;
	cout<<"请选择： "<<endl; 
	int i;//选项输入
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

//显示所有的图书 
void browseAll(SqList l,bool b,bool &flag)
{
		if(flag==false)
		{ 	
			DestroyList(l);
			ClearList(l); 
			InitList(l);
			readfile(l);//读取文件不这样里面没东西！
			flag=true; 
		}
	cout<<"所有图书展示如下："<<endl;
	cout<<"北京林业大学图书馆计算机类图书采购列表"<<endl;
	cout<<"    ISBN	          "<<"书名	                    "<<"定价"<<endl;
	for(int i=0;i<l.length;i++)//注意，若循环多加一个=号，就多一个0，所以注意循环条件！ 
	cout<<l.elem[i].no<<"   "<<l.elem[i].name<<"   "<<l.elem[i].price<<"   "<<endl;
	cout<<"------------------------------------------------"<<endl; 
	if(b==false)
	returnmenu(l);	
}

//统计图书总数 
void bookstatistics(SqList &l,bool b,bool &flag)
{
		if(flag==false)
		{ 	
			DestroyList(l);
			ClearList(l); 
			InitList(l);
			readfile(l);//读取文件不这样里面没东西！
			flag=true; 
		}
	cout<<"总共有： "<<l.length<<"本书"<<endl;
	if(b==false)
	returnmenu(l);
}

//查找函数 
void  finding(SqList l)
{
	while(1)
	{
	cout<<"请选择查找类型："<<endl;
	cout<<"按位置进行查找(1)"<<endl;
	cout<<"按书名进行查找(2)"<<endl;
	cout<<"返回主菜单(非1,2号键)"<<endl;
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
//位置查找 
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
//书名查找 
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

//更新价格
void UpdatePrice(SqList &l1,bool &flag)
{	
	cout<<"原来的书籍信息"<<endl; 
	browseAll(l1,1,flag);
	for(int i=0;i<l1.length;i++)
	{
		if(l1.elem[i].price<45)		
			l1.elem[i].price=l1.elem[i].price*1.2;
		else
			l1.elem[i].price=l1.elem[i].price*1.1;
	}
	cout<<"更新价格之后的信息"<<endl;
	bool d=true; 
	browseAll(l1,1,d);
	char filename[]="book-newprice.txt";
	writefile(l1,filename);
	flag=false; //让主菜单再重新读一遍文件，确保显示的是book文件的内容。 
	returnmenu(l1);
}

//价格升序排序： （冒泡算法） 
void PriceSort(SqList &l2,bool &flag)
{
	cout<<"原来的书籍信息"<<endl; 
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
	cout<<"升序之后的排序："<<endl;
	bool d=true; 
	browseAll(l2,1,d);
	char filename[]="book-newsort.txt"; 
	writefile(l2,filename);
	flag=false;//确保主菜单读取的是book.txt里面的内容。 
	returnmenu(l2);
}

//逆序存储 
void newinverseSort(SqList &l,bool &flag)
{
	cout<<"原来的书籍信息"<<endl; 
	browseAll(l,1,flag);
	Book c;
	for(int i=0;i<l.length/2;i++)
	{	
		c=l.elem[i];
		l.elem[i]=l.elem[l.length-1-i];
		l.elem[l.length-1-i]=c;	
	} 
	cout<<"逆序存储之后的信息："<<endl; 
	bool d=true; 
	browseAll(l,1,d);
	char filename[]="book-newinverse.txt";
	writefile(l,filename);
	flag=false;
	returnmenu(l); 
}

//插入元素 
void Insert(SqList &L,bool &flag)
{
	Book e;
	int i;
	browseAll(L,1,flag);
	cout<<"--------------------------------------------------------"<<endl;
	C:; 
	cout<<"请输入插入的位置"<<endl;
	cin>>i; 
	if(i<1 || i>L.length+1)//i值不合法， 
	{
		cout<<"输入位置非法，请选择重新输入或者是返回上一级菜单："<<endl;
		cout<<"重新输入，请按1"<<endl;
		cout<<"返回主菜单请按非1的数字键"<<endl;
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
     cout<<"请输入增加书的编号: "<<endl;
	 cin>>e.no;
	 cout<<"请输入增加书的书名"<<endl;
	 cin>>e.name;
	 cout<<"请输入增加书的价格" <<endl;
	 cin>>e.price; 
	
     cout<<"增添的书籍信息如下："<<endl;
     cout<<"    ISBN	          "<<"书名	                    "<<"定价"<<endl;
	 cout<<e.no<<"     "<<e.name<<"   "<<e.price<<endl; 
	 cout<<"确认添加吗？\n确认请按1\n重新输入请按2\n输入非1，2返回主菜单"<<endl;
		int option;
		cin>>option;
	 if(option==1)
	 {
	 	for(int j=L.length-1;j>=i-1;j--) 
       		L.elem[j+1]=L.elem[j];    //插入位置及之后的元素后移
       	 L.elem[i-1]=e;                     //将新元素e放入第i个位置
     	 ++L.length;//表长增1
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
//删除元素 
void ListDelete_Sq(SqList &L,bool &flag)
{
	int i;
	browseAll(L,1,flag);
	cout<<"--------------------------------------------------------"<<endl;
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
		cout<<"删除的信息如下："<<endl;
		cout<<"    ISBN	          "<<"书名	                    "<<"定价"<<endl;
		cout<<L.elem[i-1].no<<"         "<<L.elem[i-1].name<<"       "<<L.elem[i-1].price<<endl;
		cout<<"确认删除吗？\n确认请按1\n重新输入请按2\n输入非1，2返回主菜单"<<endl;
		int option;
		cin>>option;
		if(option==1)
		{
		for(int j=i;j<L.length;j++)
			L.elem[j-1]=L.elem[j];
		--L.length;//表长-1！ 
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

//退出函数 
void quit(SqList &l)
{
	printf("您确定要退出吗？\n");
	printf("确定退出请按0，不退出返回主菜单请输入非0数字\n");
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
//主菜单中如果输入错误报错： 
void wrongInput()
 {
 	cout<<"输入错误，请重新输入！"<<endl;
 	return; 
 }

//初始化顺序表 
void InitList(SqList &l) //构造一个空的顺序表l
{
	l.elem=new Book[MAXSIZE];   //为顺序表分配空间
    if(!l.elem) 
		exit(0);       //存储分配失败
    l.length=0;	            	  //空表长度为0
    return;
}

//读文件 
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
	is>>ISBNTitle>>nameTitle>>priceTitle;
	//读取文件内容到顺序表中
	while(is>>s.elem[s.length].no>>s.elem[s.length].name>>s.elem[s.length].price)
		s.length++;		
	is.close();
}
//写文件 
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

//销毁线性表L
void DestroyList(SqList &L)
{
  if (L.elem) delete[]L.elem;   
 //释放存储空间
}
//清空顺序表L长度 
void ClearList(SqList &L) 
{
	if(L.length!=0)
   		L.length=0;               
 //将线性表的长度置为0
}

//返回主菜单
void returnmenu(SqList &s)
{
	cout<<"选择返回主菜单(非0)或者直接退出(0)："<<endl;
	int op;
	cin>>op;
	if(op==0)
		quit(s);
	else
		return; 
 } 

