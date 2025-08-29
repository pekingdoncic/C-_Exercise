#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<int>> answer={};
	int n;
	//current_pos,当前位置，sub_len,要寻找的子集长度，sub，子集，nums，数组 
	void backtrack(int current_pos,int sub_len,vector<int> sub,vector<int>& nums){
		if(sub_len==0){
			answer.emplace_back(sub);
			return;
		}
		for(int i=current_pos;i<n;i++){
			sub.emplace_back(nums[i]);
			backtrack(i+1,sub_len-1,sub,nums);
			sub.pop_back();
			//backtrack(current_pos+1,sub_len-1,sub,nums);
		}
		
	}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=(int)nums.size();
        for(int i=0;i<=n;i++){
        	vector<int> sub={};
			backtrack(0,i,sub,nums);
		}
        
        return answer;
    }
};
int main()
{
	Solution so;
	vector<int> nums={1,2,3};
	vector<vector<int>> answer=so.subsets(nums);
	for (const auto& subset : answer) {
		cout<<"["; 
	   for (int num : subset) {
	            cout << num << ", ";
	        }
		cout<<"],";
	    }
	
	return 0;
}
