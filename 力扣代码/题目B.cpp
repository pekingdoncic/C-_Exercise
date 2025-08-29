#include <bits/stdc++.h>
#include<set>
#include<iostream>
using namespace std;
int main()
{	
	int N;
	cin>>N;
	int answer;
	//子字符串：必须是其中的连着的！substrings
	//子序列：可以不连着！subsequences
	//思路就是，先寻找a输入的有多少种不同的字符！，然后寻找b字符串中与a字符
	//串中不同的字符。之后叠加！ 
	while(N>0)
	{
		string substring,subsequence;
		cin>>substring;
		cin>>subsequence;
		unordered_set<char> temp1;
		//输入，得到不同的字符种类！ 
		for(int i=0;i<substring.size();i++){
			temp1.insert(substring[i]);
		}
		answer=substring.size();

		unordered_set<char> temp2;//存储字符串2中有多少不同的字符！ 
		for(int i=0;i<subsequence.size();i++){
			temp2.insert(subsequence[i]);

		}
		for(auto it=temp2.begin();it!=temp2.end();it++){
			if(temp1.find(*it)==temp1.end()){
				answer++;
			}
		}
		cout<<answer<<endl;
		N--;
	} 
	 return 0;	
}
