#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string,vector<string>> hashsort;
    	for(string it: strs){
			string key=it;
			sort(key.begin(),key.end());
			hashsort[key].push_back(it);
		}
		vector<vector<string>> answer;

		for(auto it:hashsort){
			answer.push_back(it.second);
		}
		return answer;
    }
};
int main()
{
	vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
	Solution so;
	vector<vector<string>> answer=so.groupAnagrams(strs);
	  cout << "[";
	    for (size_t i = 0; i < answer.size(); ++i) {
	       cout << "[";
	        for (size_t j = 0; j < answer[i].size(); ++j) {
	            cout << "\"" << answer[i][j] << "\"";
	            if (j < answer[i].size() - 1) {
	                cout << ",";
	            }
	        }
	        cout << "]";
	        if (i < answer.size() - 1) {
	            cout << ",";
	        }
	    }
	   cout << "]" << endl;
	return 0;
}
