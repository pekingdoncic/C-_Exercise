#include<bits/stdc++.h>
using namespace std;
long long Calculate(long long l,long long r,int w)
{
	vector<long long> Sum(w);
	for(int i=0;i<w;i++){
		Sum[i]=i%w;
	}
	long long cycleSum=accumulate(Sum.begin(),Sum.end(),0LL);
	
	long long qujianchangdu=r-l+1;
	long long wanzhengzhouqishuliang=qujianchangdu/w;
	long long remain=qujianchangdu%w;
	
	long long zonghe=wanzhengzhouqishuliang*cycleSum;
	long long StartIndex=l%w;
	
	for(int i=0;i<remain;i++){
		zonghe+=(StartIndex+i)%w;	
	}
	return zonghe;
} 

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long l,r;
		int w;
		cin>>l>>r>>w;
		long long answer=Calculate(l,r,w);
		cout<<answer<<endl;
	}
	return 0;
}
