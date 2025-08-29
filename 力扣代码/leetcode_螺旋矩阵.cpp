#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
		if(matrix[0].empty()){
			return answer;
		}
		int hangsize=matrix.size();
		int liesize=matrix[0].size();
		int top=0,leftedge=0,bottom=hangsize-1,rightedge=liesize-1;
		
		  while (top <= bottom && leftedge <= rightedge) {
	            // 从左到右遍历
	            for (int i = leftedge; i <= rightedge; i++) {
	                answer.push_back(matrix[top][i]);
	            }
	            top++;
	            // 从上到下遍历
	            if (top <= bottom) {
	                for (int i = top; i <= bottom; i++) {
	                    answer.push_back(matrix[i][rightedge]);
	                }
	                rightedge--;
	            }
	            // 从右到左遍历
	            if (top <= bottom && leftedge <= rightedge) {
	                for (int i = rightedge; i >= leftedge; i--) {
	                    answer.push_back(matrix[bottom][i]);
	                }
	                bottom--;
	            }
	            // 从下到上遍历
	            if (top <= bottom && leftedge <= rightedge) {
	                for (int i = bottom; i >= top; i--) {
	                    answer.push_back(matrix[i][leftedge]);
	                }
	                leftedge++;
	            }
	        }
		return answer; 
    }
};
int main()
{
	Solution so;
	vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
	vector<int> answer=so.spiralOrder(matrix);
	for(int i=0;i<(int)matrix.size()*(int)matrix[0].size();i++){
		cout<<answer[i]<<endl;
	}
	return 0;
}
