#include <bits/stdc++.h>
using namespace std;
bool isfitNonRepeated (string inputstr ,int start ,int len)
{
	string halfstr=inputstr.substr(start,len/2);
	int pos=inputstr.find(halfstr,start+len/2);

	return pos != string::npos;
}
string findAnswerString(string inputStr)
{
	int maxLength=0;
	string answer="";
	for(int i=(int)inputStr.length();i>=2;i-=2){
		for(int j=0;j<=(int)inputStr.length()-i;j++){
			if(isfitNonRepeated(inputStr,j,i)){
				if(i>maxLength){
					maxLength=i;
					answer=inputStr.substr(j,i);
				}
			}
		}
		if(maxLength>0){
			break;
		}
	} 
	return answer;
}

int main()
{
	string str;
	cin>>str;
	string answer=findAnswerString(str);
	cout<<answer<<endl;
}
