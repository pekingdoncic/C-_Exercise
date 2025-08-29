#include <bits/stdc++.h>
using namespace std;
int main()
{
	int WordNum;
	cin>>WordNum;//要背的单词数量
	cin.ignore();//除去换行符 
	vector<string> Member;
	for(int i=0;i<WordNum;i++){
		string s;
		getline(cin,s);
		Member.push_back(s);
	} 
	
	int PassageWord;
	cin>>PassageWord;
	cin.ignore();//去除换行符
	vector<string> Passage;
	for(int i=0;i<PassageWord;i++)
	{
		string s;
		getline(cin,s);
		Passage.push_back(s);
	} 
	unordered_set<string> PassAgeSet(Passage.begin(),Passage.end());
	//把其处理为不重复的集合，用于去找到包含的背单词的个数
	 
	unordered_set<string> MemberSet(Member.begin(),Member.end());
	 
	 
	int result1=0;//文章中最多包含的要背的单词数
	for(auto word:Member)
	{
		if(PassAgeSet.find(word)!=PassAgeSet.end())
		{
			result1++;
		} 
		
	}
	int zuichangchangdu=0;
	int m=Member.size();
	int xiabiao[m]={0};
//cout<<"m: "<<m<<endl;
	
	//unordered_set<unordered_set<string>::iterator> xiabiao;
	 for(int i=0;i<Passage.size();i++){
	 	for(int j=0;j<m;j++){
		 	if(Member[j]==Passage[i]&&xiabiao[j]==0){
			 	xiabiao[j]++;
			 	zuichangchangdu++;
//			 	cout<<"i: "<<i<<"j: "<<j<<endl;
//			 	cout<<zuichangchangdu<<endl;
			 	break;
			 }
			 else if((Member[j]==Passage[i])&&xiabiao[j]!=0){
			 	for(int z=0;z<m;z++)
			 	{
				 	xiabiao[z]=0;
			 	}
			 	zuichangchangdu=1;
//			 	cout<<"i: "<<i<<"j: "<<j<<endl;
//			 	cout<<"n"<<endl;
			 	break;
			 }
		 }
		 if(zuichangchangdu==m){
		 	break;
		 }
	 }
	 
	 
	//auto a=MemberSet.begin();
	//cout<<a<<endl;

//	for(int i=0;i<Passage.size();i++){
//		if(MemberSet.find(Passage[i])!=MemberSet.end()){
//			zuichangchangdu++;
//			xiabiao.insert(MemberSet.find(Passage[i]));
//		}
//		if(MemberSet.find(Passage[i])!=MemberSet.end()&& xiabiao.find(MemberSet.find(Passage[i]))!=xiabiao.end()){
//			zuichangchangdu=0;
//		}
//	}
	//cout<<"个数： "<<PassAgeSet.size()<<endl;
//	cout<<"结果1： "<<result1<<endl;
//	cout<<"结果2："<<zuichangchangdu<<endl;
	cout<<result1<<endl;
	cout<<zuichangchangdu<<endl;
	return 0;
} 
