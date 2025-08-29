#include <iostream>
using namespace std;
void PrintA(int R[],int n)
{//�������
   int i;
   for(i=0;i<n;i++)
   {
   	cout<<R[i]<<" ";
   }
   cout<<endl;
}
void Partition(int a[],int n)
{//�����������ɵļ��ϻ���Ϊ�������ཻ���Ӽ�A1��A2
  	int mid;
	int low=0;
  	int high=n-1;
	int start=0;
	int end=n-1;
	while(start<end)
	{
		low=start;
		high=end;
		//findmidposition������ 
		int temp=a[low];
	while(1)
	{
		while(low<high&&a[high]>=temp)
		{
			high--;
		}
		if(low>=high)
		{
			break;
		}
		a[low++]=a[high];
		while(low<high&&a[low]<=temp)
		{
			low++;
		}
		if(low>=high)
		{
			break;
		}
		a[high--]=a[low];
	}
		a[low]=temp;
	//findmidpoisition����	
		mid=low;
		
	
		if(mid==n/2)
		{
			break;
		}
		else if(mid<n/2)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
		cout<<"start: "<<start<<endl;
		cout<<"end: "<<end<<endl;
		cout<<"mid: "<<mid<<endl;
	}
	int b[n/2];
	int c[n/2];
	int num=0;
	for(int j=0;j<n/2;j++)
	{
		b[j]=a[num];
		num++;
	}
	PrintA(b,n/2);
	int j;
	if(n%2==0)
	{
		for( j=0;j<n/2;j++)
		{
			c[j]=a[num];
			num++;	
		}
		PrintA(c,n/2);
	} 
	else
	{
		for( j=0;j<n/2+1;j++)
		{
			c[j]=a[num];
			num++;	
		}
		PrintA(c,n/2+1);
	}
	
//	cout<<num<<endl;
//	cout<<a[num]<<endl;
//	cout<<c[2]<<endl;
	
	
	//PrintA(a,n);
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int *a=new int[n];
        for(int i=0;i<n;i++)  
        {
            cin>>a[i];
        }
        Partition(a,n);
    }
    return 0;
}


/*#include <stdio.h>
#define LEN 20000
int FindMidPosition(int a[],int low,int high)
{
	int temp=a[low];
	while(1)
	{
		while(low<high&&a[high]>=temp)
		{
			high--;
		}
		if(low>=high)
		{
			break;
		}
		a[low++]=a[high];
		while(low<high&&a[low]<=temp)
		{
			low++;
		}
		if(low>=high)
		{
			break;
		}
		a[high--]=a[low];
	}
	a[low]=temp;
	return low;
}

void Divide(int a[],int start,int end,int n)
{
	int mid;
	while(start<end)
	{
		mid=FindMidPosition(a,start,end);
		if(mid==n/2)
		{
			break;
		}
		else if(mid<n/2)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
}

void OutputArray(int a[],int start,int end)
{
	int i;
	for(i=start;i<=end-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);
}

int main()
{
	int n,i;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		else
		{
			int a[LEN];
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			Divide(a,0,n-1,n);
			OutputArray(a,0,n/2-1);
			OutputArray(a,n/2,n-1);
		}
	}
	return 0;
}*/


