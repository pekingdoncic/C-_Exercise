#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0){
			return -1;
		}
		if(n==1){
			return nums[0]==target? 0 :-1;
		}
		int left=0,righ=n-1;
		while(left<=righ){
			int mid=(left+righ)/2;
			if(nums[mid]==target)
				return mid;
			if(nums[left]<=nums[mid])//为有序的部分 
			{
				if(nums[left]==target)
					return left; 
				else if(nums[left]<target&&target<nums[mid]){
					righ=mid-1;
				}
				else
				{
					left=mid+1;
				}
			}
			else
			{
				if(nums[righ]==target){
					return righ;
				}
				else if(nums[mid]<target&&target<nums[righ]){
					left=mid+1;
				}
				else
					righ=mid-1;
			}
		}
		return -1;//这里一定要注意有返回值！ 
    }
};
int main()
{
	Solution so;
	vector<int> nums={4,5,6,7,0,1,2};
	int target=0;
	cout<<so.search(nums,target)<<endl;
	return 0;
}
