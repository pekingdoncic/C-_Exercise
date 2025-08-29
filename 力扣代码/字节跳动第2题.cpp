#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		int number;
		string s;
		cin>>number>>s;
		long answer;
		
		long total=n*(n+1)/2;
		long oddanswer=(number+1)*(number+1)/4;
		if(s=="even"){			
			answer=total-oddanswer;
		}
		else if(s=="odd")//ÆæÊýÊý×é 
		{
			answer=oddanswer; 
		}
		else
		{
			return 0;
		}
		cout<<answer<<endl;
	}
	return 0;
}
