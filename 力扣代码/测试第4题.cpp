#include <bits/stdc++.h>
using namespace std;
int main()
{
	string inputstr;
	cin>>inputstr;
	int maxLength=0;
	if((int)inputstr.size()%2!=0){
		cout<<"无自重复子串"<<endl;
		return 0; 
	}
	else
	{
		string zichongfuzichuan="";
		for(int i=2;i<=(int)inputstr.size();i+=2){
			for(int j=0;j<=(int)inputstr.size()-i;j++){
				int midpos=j+i/2;
				string left=inputstr.substr(j,i/2);
				string right=inputstr.substr(midpos,i/2);
				if(left==right){
					if(i>maxLength){
						maxLength=i;
						zichongfuzichuan=inputstr.substr(j,i);
					}
				}
			}
		}
		cout<<zichongfuzichuan<<endl;
	}
	return 0;
} 
