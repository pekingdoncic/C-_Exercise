#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        for(auto element:nums){
			uset.insert(element);
		}
//		for(auto element :uset){
//			cout<<element<<"  ";
//		}
		int current_num;
		int current_length=0;
		int result=0;
		for(auto element : uset){
			//首先寻找这个序列头在哪里！ 
			if(uset.count(element-1)==0) {
				current_num=element;
				current_length=1;
			while(uset.count(current_num+1)!=0){
				current_length++;
				current_num++;
			}
			result=max(current_length,result);
			}
		}
		return result;
    }
};
int main()
{
	vector<int> nums={100,4,200,1,3,2};
	Solution so;
	int answer=so.longestConsecutive(nums);
	cout<<answer<<endl;
	
	return 0;
}
