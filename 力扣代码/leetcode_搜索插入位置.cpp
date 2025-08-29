#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size=nums.size();
        int search_result=-1;
        for(int i=0;i<size;i++){
			if(nums[i]==target){
				search_result=i;
			}
			else if((i==0)&&(nums[i]>target)){
				search_result=i;
			}
			else if(i==size-1&&nums[i]<target){
				search_result=i+1;
			}
			else if(i+1<size){
				if(nums[i]<target&&nums[i+1]>target){
					search_result=i+1;
				}
			}			
		}
		return search_result;
    }
};
int main()
{
	Solution so;
	vector<int> nums={1,3,5,6};
	int targe=0;
	
	cout<<so.searchInsert(nums,targe)<<endl;
	return 0;
}
