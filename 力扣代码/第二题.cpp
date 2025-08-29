//#include<bits/stdc++.h>
//using namespace std;
//int way(int x,int y,int X,int Y,int n,int m) {
//	if (x < 0 || y < 0 || x > n || y > m) return 0;//判断边界，防止卡死 
//	if(x==n&&y==m) return 1;//卒到达B点 
//	if ((x == X && y == Y) || (abs(x -X) == 1 && abs(y - Y) == 2) || (abs(x - X) == 2 && abs(y -Y) == 1))
//        return 0;//卒落在禁止点的情况 
//    	return way(x+1,y,X,Y,n,m)+way(x,y+1,X,Y,n,m);//卒向下走与向右走 
//}
//
//int main(){
//	int x=0,y=0,X,Y,n,m;
//	cin>>n>>m>>X>>Y;
//	cout<<way(x,y,X,Y,n,m);
//}

//方法一，最简单的递归法！ 
//#include <bits/stdc++.h>
//using namespace std;
//int way(int x,int y,int Bx,int By,int Hx,int Hy){
//	//边界问题： 
//	if(x<0||y<0||x>Bx||y>By){
//		return 0;
//	}
//	if(x==Bx||y==By){
//		return 1;
//	}
//	//还是少考虑了一种情况，就是卒和马的位置重合！ 
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

//方法二，动态规划法！
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int Ax,Ay,Bx,By,Hx,Hy;
	cin>>Bx>>By>>Hx>>Hy;
	Ax=Ay=0;
	//注意语法！ 
	vector <int> dx{-2,-1,1,2,-2,-1,1,2,0};
	vector <int> dy{-1,-2,-2,-1,1,2,2,1,0};
//	dx=[-2,-1,1,2,-2,-1,1,2];
//	dy=[-1,-2,-2,-1,1,2,2,1];
//	vector<vector<bool>> horse_Controller(Bx+1,(By+1,false));
	
	//确定马的范围！ 
	vector<vector<bool>> horse_Controller(Bx+1,vector<bool>(By+1,false));
	for(int i=0;i<9;i++){
		int x=Hx+dx[i];
		int y=Hy+dy[i];
		if(x>=0&&x<=Bx&&y>=0&&y<=By) //这里还需要考虑就是小于最终的边界！ 
			horse_Controller[x][y]=true;
	}
	
	//动态规划寻路
	vector<vector<int>> dp(Bx+1,vector<int>(By+1,0));
	dp[Ax][Ay]=1;
	for(int i=0;i<=Bx;i++){
		for(int j=0;j<=By;j++){
			//被马控制的地方，路径清零！ 
			if(horse_Controller[i][j]){
				dp[i][j]=0;
			}
			else//有些时候要注意if和else的区别！！！！ 
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
