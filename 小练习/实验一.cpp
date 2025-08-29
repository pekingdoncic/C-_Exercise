#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //图书表可能达到的最大长度
using namespace std;
typedef struct
{//图书信息定义
    char no[50];    //图书ISBN
    char name[50];   //图书名字
    float price;   //图书价格
}Book;
typedef struct
{//图书表的顺序存储结构类型为SqList
    Book *elem;                   //存储空间的基地址
    int length;                   //图书表中当前图书个数
}SqList;
//int InitList_Sq(SqList &L)
//{//构造一个空的顺序表L
//    L.elem= new Book [MAXSIZE];
//    if(!L.elem)
//        exit(OVERFLOW);
//    L.length=0;
//    return OK;
//}
//int Input_Sq(SqList &L)
//{//顺序表的输入
//    if(!L.elem)
//        exit(OVERFLOW);
////        char ISBN[50];   
////    char bookname[50];
////    float jiage;
//    while(L.length<MAXSIZE)
//    {	
//    	cin>>L.elem[L.length].no>>L.elem[L.length].name>>L.elem[L.length].price;
//    	if(strcmp(L.elem[L.length].no,"0")==0&&!strcmp(L.elem[L.length].name,"0")==0&&L.elem[L.length].price==0)
//        	{
//        		break;	
//			}	
//		L.length++;
//    }
//}
//int Output_Sq(SqList L)
//{//顺序表的输出
//    while((cin>>L.elem[L.length].no!=0)&&(cin>>L.elem[L.length].no!=0)&&(cin>>L.elem[L.length].no!=0))
//    {
//        L.length++;
//    }
//    return OK; 
//}
//int main()
//{
//	SqList s;
//	InitList_Sq(s);
//	Input_Sq(s);
//		Output_Sq(s);
//}
//   char ISBN[20];   
//    char bookname[50];
//    float jiage;
//    while(L.length<MAXSIZE&&(strcmp(cin>>L.elem[L.length].no,0)!=0)&&(strcmp(cin>>L.elem[L.length].no,0)!=0)&&(strcmp(cin>>L.elem[L.length].no,0)!=0)
//    {
//        L.length++;
//    }
int InitList_Sq(SqList &L)
{//构造一个空的顺序表L
    L.elem= new Book [MAXSIZE];
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    return OK;
}
int Input_Sq(SqList &L)
{//顺序表的输入
    if(!L.elem)
        exit(OVERFLOW);
     else 
     {
         for (int i=0;i<MAXSIZE;i++)        
        {
        cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;    
        if(strcmp(L.elem[i].no,"0")&&strcmp(L.elem[i].name,"0")&&L.elem[i].price==0)        
           break;            //非法输入则函数结束
        else 
            L.length++;           //合法输入，表长才+1
        }
        return OK;
    }
}
int Output_Sq(SqList L)
{//顺序表的输出
   cout<<L.length-1<<endl;
    for(int i=0;i<L.length-1;i++)
        cout<<L.elem[i].no<<" "<< L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    return OK;
}
int main()
{
	SqList l;
	InitList_Sq(l);
	Input_Sq(l);
	Output_Sq(l);
	return 0;
}
// Book c;
//   for(int i=0;i<L.length/2;i++)
//	{	
//		c=L.elem[i];
//		L.elem[i]=L.elem[L.length-1-i];
//		L.elem[L.length-1-i]=c;	
//	} 
//   return OK;
//}
/*int Input_Sq(SqList &L)            //引用&的作用：形参变化改变形参
{
    while(L.length<MAXSIZE)
    {
        cin>>L.elem[L.length].no>>L.elem[L.length].name>>L.elem[L.length].price;    
        if(strcmp(L.elem[L.length].no,"0")==0&&strcmp(L.elem[L.length].no,"0")==0&&L.elem[L.length].price==0)        
            return OK;            //非法输入则函数结束
        else 
            L.length++;           //合法输入，表长才+1
    }
}*/
//求最贵的价格并且把所有符合条件的都输出！我这专门开了一个数组，其实没必要！ 
/*int n=0;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price==maxprice)
                {
                b[n]=L.elem[i];//空间复杂度有些大！ 
                n++;
                }//注意，不打花括号的坏习惯！，不然n==8！ 
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
           cout<<b[i].no<<" "<<b[i].name<<" "<<fixed<<setprecision(2)<<b[i].price<<endl;
       }
           */
//最爱图书的查找 
         /*  else//注意，先去查库存再去查书没问题，但是是不符合输出顺序要求！所有不可取！ 
    {
        float maxprice=0.0;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price>maxprice)
                maxprice=L.elem[i].price;
        }
        int n=0;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price==maxprice)
                {
                n++;
                }//注意，不打花括号的坏习惯！
        }
        cout<<n<<endl;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price==maxprice)
           cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
        }
         else//输出 
        {
            cout<<flag<<endl;
        for(int i=0;i<L.length;i++)////查库存
        {
            for(int j=0;j<flag;j++)
            {
                if(strcmp(bookname[j],L.elem[i].name)==0)
                {
                  cout<<L.elem[j].no<<" "<<L.elem[j].name<<" "<<fixed<<setprecision(2)<<L.elem[j].price<<endl;
                }
            }
        }
        }
        */
