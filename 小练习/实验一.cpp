#include<iostream>
#include<string.h>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000    //ͼ�����ܴﵽ����󳤶�
using namespace std;
typedef struct
{//ͼ����Ϣ����
    char no[50];    //ͼ��ISBN
    char name[50];   //ͼ������
    float price;   //ͼ��۸�
}Book;
typedef struct
{//ͼ����˳��洢�ṹ����ΪSqList
    Book *elem;                   //�洢�ռ�Ļ���ַ
    int length;                   //ͼ����е�ǰͼ�����
}SqList;
//int InitList_Sq(SqList &L)
//{//����һ���յ�˳���L
//    L.elem= new Book [MAXSIZE];
//    if(!L.elem)
//        exit(OVERFLOW);
//    L.length=0;
//    return OK;
//}
//int Input_Sq(SqList &L)
//{//˳��������
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
//{//˳�������
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
{//����һ���յ�˳���L
    L.elem= new Book [MAXSIZE];
    if(!L.elem)
        exit(OVERFLOW);
    L.length=0;
    return OK;
}
int Input_Sq(SqList &L)
{//˳��������
    if(!L.elem)
        exit(OVERFLOW);
     else 
     {
         for (int i=0;i<MAXSIZE;i++)        
        {
        cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;    
        if(strcmp(L.elem[i].no,"0")&&strcmp(L.elem[i].name,"0")&&L.elem[i].price==0)        
           break;            //�Ƿ�������������
        else 
            L.length++;           //�Ϸ����룬����+1
        }
        return OK;
    }
}
int Output_Sq(SqList L)
{//˳�������
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
/*int Input_Sq(SqList &L)            //����&�����ã��βα仯�ı��β�
{
    while(L.length<MAXSIZE)
    {
        cin>>L.elem[L.length].no>>L.elem[L.length].name>>L.elem[L.length].price;    
        if(strcmp(L.elem[L.length].no,"0")==0&&strcmp(L.elem[L.length].no,"0")==0&&L.elem[L.length].price==0)        
            return OK;            //�Ƿ�������������
        else 
            L.length++;           //�Ϸ����룬����+1
    }
}*/
//�����ļ۸��Ұ����з��������Ķ����������ר�ſ���һ�����飬��ʵû��Ҫ�� 
/*int n=0;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price==maxprice)
                {
                b[n]=L.elem[i];//�ռ临�Ӷ���Щ�� 
                n++;
                }//ע�⣬�������ŵĻ�ϰ�ߣ�����Ȼn==8�� 
        }
        cout<<n<<endl;
        for(int i=0;i<n;i++)
        {
           cout<<b[i].no<<" "<<b[i].name<<" "<<fixed<<setprecision(2)<<b[i].price<<endl;
       }
           */
//�ͼ��Ĳ��� 
         /*  else//ע�⣬��ȥ������ȥ����û���⣬�����ǲ��������˳��Ҫ�����в���ȡ�� 
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
                }//ע�⣬�������ŵĻ�ϰ�ߣ�
        }
        cout<<n<<endl;
        for(int i=0;i<L.length;i++)
        {
            if(L.elem[i].price==maxprice)
           cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
        }
         else//��� 
        {
            cout<<flag<<endl;
        for(int i=0;i<L.length;i++)////����
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
