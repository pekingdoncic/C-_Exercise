#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void backtrack(vector<vector<int>>& answer,vector<int>& nums,int pos,int len){
		if(pos==len){
			answer.push_back(nums);
			return;
		}
		else{
			for(int i=pos;i<len;i++)
			{
				swap(nums[pos],nums[i]);
				backtrack(answer,nums,pos+1,len);
				swap(nums[pos],nums[i]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        backtrack(answer,nums,0,int(nums.size()));
        return answer;
    }
};
int main()
{
	Solution so;
	vector<int> nums={1,2,3};
	auto answer=so.permute(nums);
	for(int i=0;i<(int)answer.size();i++){
		for(int j=0;j<(int)answer[0].size();j++)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
