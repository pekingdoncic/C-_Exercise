#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void DFS(vector<vector<char>>& grid, int hang,int lie)
	{
		int hangsize=grid.size();
		int liesize=grid[0].size();
		
		grid[hang][lie]='0';
		if(hang-1>=0 && grid[hang-1][lie]=='1') DFS(grid,hang-1,lie);
		if(hang+1<hangsize &&grid[hang+1][lie]=='1') DFS(grid,hang+1,lie);
		if(lie-1>=0 && grid[hang][lie-1] == '1') DFS(grid,hang,lie-1);
		if(lie+1<liesize && grid[hang][lie+1]=='1') DFS(grid,hang,lie+1);
				
	}
    int numIslands(vector<vector<char>>& grid) {
        int hangsize=grid.size();
        int liesize=grid[0].size();
		int numlands=0;
		
		for(int i=0;i<hangsize;i++){
			for(int j=0;j<liesize;j++){
				if(grid[i][j]=='1'){
					numlands++;
					DFS(grid,i,j);
				}
			}
		}
		return numlands;
    }
    int BFS_numIslands(vector<vector<char>>& grid){
		int hangsize=grid.size();
		if(!hangsize)
			return 0;
		int liesize=grid[0].size();
		int result_land=0;
		for(int i=0;i<hangsize;i++){
			for(int j=0;j<liesize;j++){
				if(grid[i][j]=='1'){
					result_land++;
					grid[i][j]='0';
					queue<pair<int,int>> qupos;
					qupos.push({i,j});
					while(!qupos.empty()){
						auto element=qupos.front();
						qupos.pop();
						int hang=element.first;
						int lie=element.second;
						if(hang-1>=0&&grid[hang-1][lie]=='1'){
							qupos.push({hang-1,lie});
							grid[hang-1][lie]='0';
						}
						if(hang+1<hangsize&&grid[hang+1][lie]=='1'){
							qupos.push({hang+1,lie});
							grid[hang+1][lie]='0';
						}
						if(lie-1>=0&&grid[hang][lie-1]=='1'){
							qupos.push({hang,lie-1});
							grid[hang][lie-1]='0';
						}
						if(lie+1<liesize&&grid[hang][lie+1]){
							qupos.push({hang,lie+1});
							grid[hang][lie+1]= '0';
						}
					}
				}				
			}
		}
		return result_land;
	}
};
int main()
{
	Solution so;
	vector<vector<char>> grid={ {'1', '1', '0', '0'},
	        {'1', '0', '1', '0'},
	        {'0', '0', '1', '1'}};
	int result=so.BFS_numIslands(grid);
	cout<<result<<endl;	
	queue<pair<int,int>> temp;
	temp.push({1,2});
	
	return 0;
}
