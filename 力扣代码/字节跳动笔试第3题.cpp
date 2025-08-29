#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int number;
		cin>>number;
		string ss;
		cin>>ss;
		//查看是否有钩子？ 
		bool HaveJ=false;
		vector<int> Jpostion;
		for(int i=0;i<ss.size();i++){
			if(ss[i]=='J'){
				HaveJ=true;
				Jpostion.push_back(i);
			}			
		}
		if(HaveJ==false){
			if(ss.find('F')!= string::npos){
				cout<<"Too many fish!"<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else{
			int answer=0;
			for(int i=0;i<=(int)Jpostion.size();i++){
				
				int leftedge=(i==0)?0:Jpostion[i-1]+1;
				int rightedge=(i==Jpostion.size())?n-1:Jpostion[i]-1;
				
				int fish=0;
				for(int j=leftedge;j<=rightedge;j++){
					if(ss[j]=='F'){
						fish++;
					}		
				}
				answer=max(fish,answer);	
			}
			cout<<answer<<endl;
		} 
	}
	return 0;
}
