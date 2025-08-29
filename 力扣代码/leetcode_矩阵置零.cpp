#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int hangsize=matrix.size();
        if(matrix[0].empty()){
			return;
		}
        int liesize=matrix[0].size();
        vector<pair<int,int>> iszero;
        
		//找到有零的位置 
        for(int i=0;i<hangsize;i++){
			for(int j=0;j<liesize;j++){
				if(matrix[i][j]==0){
					iszero.push_back({i,j});
				}
			}
		}
		
		for(auto &element :iszero){
			int hang=element.first;
			int lie =element.second;
			for(int i=0;i<hangsize;i++){
				for(int j=0;j<liesize;j++){
					if(matrix[hang][j]!=0||matrix[i][lie]!=0){
						matrix[hang][j]=0;
						matrix[i][lie]=0;
					}			
				}
			}		
		}
    }
};
int main()
{
	Solution so;
	vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
	so.setZeroes(matrix);
	for(int i=0;i<matrix.size();i++){
		for(int j=0;j<matrix[0].size();j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
