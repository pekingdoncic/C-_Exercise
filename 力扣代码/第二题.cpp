//#include<bits/stdc++.h>
//using namespace std;
//int way(int x,int y,int X,int Y,int n,int m) {
//	if (x < 0 || y < 0 || x > n || y > m) return 0;//�жϱ߽磬��ֹ���� 
//	if(x==n&&y==m) return 1;//�䵽��B�� 
//	if ((x == X && y == Y) || (abs(x -X) == 1 && abs(y - Y) == 2) || (abs(x - X) == 2 && abs(y -Y) == 1))
//        return 0;//�����ڽ�ֹ������ 
//    	return way(x+1,y,X,Y,n,m)+way(x,y+1,X,Y,n,m);//���������������� 
//}
//
//int main(){
//	int x=0,y=0,X,Y,n,m;
//	cin>>n>>m>>X>>Y;
//	cout<<way(x,y,X,Y,n,m);
//}

//����һ����򵥵ĵݹ鷨�� 
//#include <bits/stdc++.h>
//using namespace std;
//int way(int x,int y,int Bx,int By,int Hx,int Hy){
//	//�߽����⣺ 
//	if(x<0||y<0||x>Bx||y>By){
//		return 0;
//	}
//	if(x==Bx||y==By){
//		return 1;
//	}
//	//�����ٿ�����һ�����������������λ���غϣ� 
//	//if((abs(x-Hx)==1&&abs(y-Hy)==2)||(abs(x-Hx)==2&&abs(y-Hy)==1)){
//	if((abs(x-Hx)==1&&abs(y-Hy)==2)||(abs(x-Hx)==2&&abs(y-Hy)==1)||((x==Hx)&&(y==Hy))){
//		return 0;
//	}
//	return way(x+1,y,Bx,By,Hx,Hy)+way(x,y+1,Bx,By,Hx,Hy);
//}
//int main()
//{
//	int x,y,Bx,By,Hx,Hy;
//	x=y=0;
//	cin>>Bx>>By>>Hx>>Hy;
//	cout<<way(x,y,Bx,By,Hx,Hy);
//	return 0;
//}

//����������̬�滮����
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int Ax,Ay,Bx,By,Hx,Hy;
	cin>>Bx>>By>>Hx>>Hy;
	Ax=Ay=0;
	//ע���﷨�� 
	vector <int> dx{-2,-1,1,2,-2,-1,1,2,0};
	vector <int> dy{-1,-2,-2,-1,1,2,2,1,0};
//	dx=[-2,-1,1,2,-2,-1,1,2];
//	dy=[-1,-2,-2,-1,1,2,2,1];
//	vector<vector<bool>> horse_Controller(Bx+1,(By+1,false));
	
	//ȷ����ķ�Χ�� 
	vector<vector<bool>> horse_Controller(Bx+1,vector<bool>(By+1,false));
	for(int i=0;i<9;i++){
		int x=Hx+dx[i];
		int y=Hy+dy[i];
		if(x>=0&&x<=Bx&&y>=0&&y<=By) //���ﻹ��Ҫ���Ǿ���С�����յı߽磡 
			horse_Controller[x][y]=true;
	}
	
	//��̬�滮Ѱ·
	vector<vector<int>> dp(Bx+1,vector<int>(By+1,0));
	dp[Ax][Ay]=1;
	for(int i=0;i<=Bx;i++){
		for(int j=0;j<=By;j++){
			//������Ƶĵط���·�����㣡 
			if(horse_Controller[i][j]){
				dp[i][j]=0;
			}
			else//��Щʱ��Ҫע��if��else�����𣡣����� 
			{
				if(i>0){
					dp[i][j]+=dp[i-1][j]; 
				}
				if(j>0){
					dp[i][j]+=dp[i][j-1];
				}
			}		
		}
	} 
	cout<<dp[Bx][By]<<endl;
	 
	return 0;
}
