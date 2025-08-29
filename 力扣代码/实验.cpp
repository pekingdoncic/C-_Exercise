#include <bits/stdc++.h>
using namespace std;
vector<int> PreArr(vector<int> arr)
{
	
	int n=arr.size();
	vector<int> prearr(n);
	prearr[0]=arr[0];
	for(int i=1;i<n;i++){
		prearr[i]=prearr[i-1]+arr[i];
	}
	return prearr;
}
int main()
{
	vector<int> arr={1,2,3,4,5,6,7,8,9};
	vector<int> prearr=PreArr(arr);
	while(true){
		int l,r;
		cin>>l>>r;
		int result=prearr[r]-prearr[l-1];
		cout<<result<<endl;
	}

	return 0;
}
