#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		//vector<int>::iterator it=nums.begin();
		int n=nums.size();
		unordered_map<int,int> result;
		vector<int> answer;
		for (int i=0;i<n;i++)
		{
			if(result.find(target-nums[i])!=result.end())
			{
				auto it=result.find(target-nums[i]);
				
				answer.push_back(it->second);
				answer.push_back(i);
				return answer;
			}
			result[nums[i]]=i;
		}
		return answer;      
    }
};
int main()
{
	vector<int> nums={2,7,11,15}; 
	int target = 9;
	vector<int> result;
	
	/*ʵ���������ʱ����Ҫע�����µ����ַ�ʽ*/
	//����һ�� 
	//Solution* so=new Solution();
	//result=so->twoSum(nums,target);
	//delete so;
	//��������
	Solution so;
	result=so.twoSum(nums,target);
	for(auto it:result){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}
