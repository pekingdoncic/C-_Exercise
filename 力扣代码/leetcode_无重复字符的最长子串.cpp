#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	    int s_size=s.size();
	    unordered_set<char> temp;
	    int result=0;
	    int current_result=result;
		for(int i=0;i<s_size;i++){
			char ch=s[i];
			temp.insert(ch);
			for(int j=i+1;j<s_size;i++){
				if(temp.count(s[j])==0){
					temp.insert(s[j]);
					current_result++;
				}
				else
				{
					break;
				}
			}
			result=max(result,current_result);
			temp.clear();			 
		}
		return result;
    }
};

int main()
{
	Solution so;
	string str("asdvasdw");
	int result=so.lengthOfLongestSubstring(str);
	cout<<result<<endl;
	return 0;
}
