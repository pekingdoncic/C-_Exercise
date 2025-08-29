#include <bits/stdc++.h>
using namespace std;
//string getPreString(string s)
//{
//	for(int i=0;i<s.size();i++){
//		if(s[i]=='a'){
//			return "NULL";
//		}
//		else
//		{
//			if(i==s.size()-1){
//				s[i]=char(s[i]-1);
//			}
//		}
//	}
//	return s;
//}
//string getSString(string s,int l,int r)
//{
//	return s.substr(l-1,r-l+1);
//}
int main()
{
	string s;
	int q;
	cin>>s>>q;
//	cout<<s<<endl<<q<<endl;
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		//获取子串 
		string ss=s.substr(l-1,r-l+1);
	//	cout <<ss<<endl;
		//然后是 寻找上一个的串！
		//处理全部是a的字符串！ 
		bool IsOk=false;
		//注意，写size的时候，最好加一个(int)！ 
		for(int i=0;i<(int)ss.size();i++){
			if(ss[i]!='a'){
				IsOk=true;
			}
		}
		if(IsOk==false){
			cout<<"NULL"<<endl<<"Happy Chinese New Year!"<<endl;
		}
		else
		{
			int pos=-1;
			//部分有a的情况：找到第一个不是a的字符串，使其--！
			//这里注意 
			for(int i=ss.size()-1;i>=0;i--){
				if(ss[i]!='a'){
					pos=i;
					ss[i]--;
					break; 
				}
			}
			//把之后的字符串都变成z！ 
			for(int i=pos+1;i<ss.size();i++){
				ss[i]='z';
			}
			cout<<ss<<endl; 	
			if(s.find(ss)!=-1)
				cout<<"Happy New Year!"<<endl;
			else
				cout<<"Happy Chinese New Year!"<<endl;
		}
	}
	return 0;
}
