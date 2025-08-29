#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int hangsize=matrix.size();
        int liesize=matrix[0].size();
    	int i=0,j=0;
    	while(i<hangsize&&j<liesize){
			if(matrix[i][j]==target){
				return true;
			}
			else if(matrix[i][j]<target){
				int temp1=-1,temp2=-1;
				if(i+1<hangsize&&matrix[i+1][j]!=target)
				{
					temp1=abs(matrix[i+1][j]-target);
				}
				if(j+1<liesize&&matrix[i][j+1]!=target)
				{
					temp2=abs(matrix[i][j+1]-target);
				}
				if(temp1>=0&&temp2>=0&&temp1<temp2){
					i++;
				}
				else
				{
					j++;
				}
			}
		}
        return false;
        
    }
};
int main()
{
	Solution so;
	vector<vector<int>> matrixs={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
	int target=5;
	cout<<so.searchMatrix(matrixs,target)<<endl;
	return 0;
}
