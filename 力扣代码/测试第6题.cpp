#include <bits/stdc++.h>
using namespace std;
void DFS(int jiedian,vector<vector<int>>& Matrix,vector<bool>& visited,int n)
{
	visited[jiedian]=true;
	for(int i=0;i<n;i++){
		if(!visited[i]&&Matrix[jiedian][i]==1){
			DFS(i,Matrix,visited,n);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> Matrix(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>Matrix[i][j];
		}
	}
	vector<bool> visited(n,false);
	int answer=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			DFS(i,Matrix,visited,n);
			answer++;
		}
	}
	cout<<answer<<endl;
	return 0;
}
