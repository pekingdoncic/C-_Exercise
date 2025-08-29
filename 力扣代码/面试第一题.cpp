#include <bits/stdc++.h>
using namespace std;
int partitionNum(vector<int>& nums,int left,int right)
{
	int pivot=nums[right];
	int i=left-1;
	for(int j=0;j<right;j++){
		if(nums[i]>pivot){
			i++;
			swap(nums[i],nums[j]);
		}
	}
	swap(nums[i+1],nums[right]);
	return i+1;
}

int QuickSelectNum(vector<int> &nums,int left,int right,int k)
{
	if(nums[left]==nums[right]){
		return nums[left];
	}
	int index=partitionNum(nums,left,right);
	if(k==index){
		return nums[k];
	}
	else if(k<index){
		return QuickSelectNum(nums,left,index-1,k);
	}
	else
	{
		return QuickSelectNum(nums,index+1,right,k);
	}
}
int FindAnswer(vector<int> &nums,int k)
{
	return QuickSelectNum(nums,0,nums.size()-1,k);	
}
int main()
{
//	string ss;
//	getline(cin,ss);
//	vector<int> Input;
//	stringstream s;
//	while(ss>>s){
//		int temp;
//		s>>temp;
//		Input.push_back(temp);
//	}
	vector<int> a={3,2,4,5,9};
	int k;
	cin>>k;
//	cout<<"K: "<<k<<"Answer: "<<FindAnswer(a,k)<<endl;
	FindAnswer(a,k);
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	} 
}
