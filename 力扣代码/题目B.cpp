#include <bits/stdc++.h>
#include<set>
#include<iostream>
using namespace std;
int main()
{	
	int N;
	cin>>N;
	int answer;
	//���ַ��������������е����ŵģ�substrings
	//�����У����Բ����ţ�subsequences
	//˼·���ǣ���Ѱ��a������ж����ֲ�ͬ���ַ�����Ȼ��Ѱ��b�ַ�������a�ַ�
	//���в�ͬ���ַ���֮����ӣ� 
	while(N>0)
	{
		string substring,subsequence;
		cin>>substring;
		cin>>subsequence;
		unordered_set<char> temp1;
		//���룬�õ���ͬ���ַ����࣡ 
		for(int i=0;i<substring.size();i++){
			temp1.insert(substring[i]);
		}
		answer=substring.size();

		unordered_set<char> temp2;//�洢�ַ���2���ж��ٲ�ͬ���ַ��� 
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
