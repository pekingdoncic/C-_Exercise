#include <bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
//class Solution {
//public:
//    ListNode* reverseList(ListNode* head) {
//		stack<ListNode *> Node;
//		auto tempNode=head;
//		while(tempNode->next!=nullptr){
//			Node.push(tempNode);
//			tempNode=tempNode->next;
//		}
//		ListNode *NewNode=Node.top();
//		Node.pop();				
//		while(!Node.empty()){
//			NewNode->next=Node.top();
//			NewNode=NewNode->next;
//			Node.pop();
//		}
//		return NewNode;
//	
//    }
//    
//};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,vector<string>> mp;
		for(string& str:strs){
			string key=str;
			sort(key.begin(),key.end());
			mp[key].push_back(str); 
		}
		vector<vector<string>> answer;
		for(auto it=mp.begin();it!=mp.end();it++){
			answer.push_back(it->second);
		}
		return answer;
	
    }
};
