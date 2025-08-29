#include <bits/stdc++.h>
using namespace std;

int main()
{
	int number;
	cin>>number;
	int temp=number;
	vector<int> answer;
	if(temp==0){
		cout<<0<<endl;
		return 0;
	}
	while(temp){
		int cunchu=temp%8;
		answer.push_back(cunchu);
		temp=temp/8;
	}
	for(int i=(int)answer.size()-1;i>=0;i--){
		cout<<answer[i];
	}
	
	return 0;
} 
