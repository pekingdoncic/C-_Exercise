#include <bits/stdc++.h>
using namespace std;
struct Cell{
	int value;
	pair<int,int> PrePosition;
};
int main()
{
	int hang,lie;
	cin>>hang>>lie;
	//�������룺 
	vector<vector<int>> juzhen(hang,vector<int>(lie));
	for(int i=0;i<hang;i++){
		for(int j=0;j<lie;j++){
			cin>>juzhen[i][j];
		}
	}
	//��̬�滮�� 
	vector<vector<Cell>> dp(hang,vector<Cell>(lie));
	vector<pair<int,int>> path;
	dp[0][0].value=juzhen[0][0];
	dp[0][0].PrePosition={-1,-1};
	
	//��һ�У�ֻ���Ǵ����� 
	for(int i=1;i<lie;i++){
		dp[0][i].value=dp[0][i-1].value+juzhen[0][i];
		dp[0][i].PrePosition={0,i-1};
	}
	
	//��һ�У�ֻ�ܴ�������ȥ���ɣ� 
	for(int i=1;i<hang;i++){
		dp[i][0].value=dp[i-1][0].value+juzhen[i][0];
		dp[i][0].PrePosition={i-1,0};
	}
	//��̬�滮��
	for(int i=1;i<hang;i++){
		for(int j=1;j<lie;j++){
			if(dp[i-1][j].value>dp[i][j-1].value){
				dp[i][j].value=juzhen[i][j]+dp[i-1][j].value;
				
				dp[i][j].PrePosition={i-1,j};
			}
			else
			{
				dp[i][j].value=juzhen[i][j]+dp[i][j-1].value;				
				dp[i][j].PrePosition={i,j-1};
			}
		}
	} 
	int i=hang-1,j=lie-1;
	while(i!=-1&&j!=-1){
		path.push_back({i,j});
		auto temp=dp[i][j].PrePosition;
		i=temp.first;
		j=temp.second;
	}
	reverse(path.begin(),path.end());
	
	//��ӡ·����
	for(auto p:path){
		cout<<juzhen[p.first][p.second]<<" ";
	}
	cout<<endl; 
	//��ӡ���ֵ�� 
	cout<<dp[hang-1][lie-1].value<<endl;
	return 0;
} 
