#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
  public:
      int getlength(ListNode *head)
      {
	  	int length=0;
	  	ListNode *temp=head;
	  	while(temp){
		  	length++;
		  	temp=temp->next;
		  }
		  return length;
	  }
	   
      ListNode* removeNthFromEnd(ListNode* head, int n) {
          
      }
  };
  
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        vector<int> cunchu;
//        ListNode *temp=head;
//        
//        while(temp!=nullptr){
//			cunchu.push_back(temp->val);
//			temp=temp->next;
//		}
//		for(int i=0,j=cunchu.size()-1;i<cunchu.size(),j>=0;i++,j--){
//			if(cunchu[i]!=cunchu[j]){
//				return false;
//			}
//		}
//    }
//};
  
   
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) 
//     {
//		if(head==nullptr){
//			return nullptr;
//		}	 	
//		
//		stack<ListNode *> temp;
//		ListNode *a=head;
//		while(a!=nullptr){
//			temp.push(a);
//			a=a->next;
//		}
//		ListNode *answer=temp.top();
//		temp.pop();
//		ListNode *newHead=answer; 
//		while(!temp.empty()){
//			newHead=newHead->next;
//			newHead=temp.top();
//			temp.pop();
//		}
//		newHead->next=nullptr;
//		return answer;
//	 }
// }; 





//int main()
//{
//	char a='a';
//	char A=toupper(a);
//	cout<<A<<endl;
//	string ss
//	string ::iterator it=ss.begin(); 
//	return 0;
//}

//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        for(auto &row :matrix){
//			for(auto element : row){
//				if(element==target){
//					return true;
//					lower_bound()
//				}
//			}
//		}
//		return false;
//    }
//};

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//    unordered_set<char> window;
//    int Answer=0;
//	int n=s.size();
//    int leftwin=0,rightwin=0;
//	for(int rightwin=0;rightwin<n;rightwin++){
//		//要 
//		while(window.find(s[rightwin])!=window.end()){
//			window.erase(s[leftwin]);
//			leftwin++;
//			
//		}
//		window.insert(s[rightwin]);		
//	Answer=max(Answer,rightwin-leftwin+1);
//	}
//	return Answer;	 
//    }
//};
//class Solution {
//public:
//    bool isValid(string s) {
//        if(s.size()%2==1)
//        return false;
//        else
//        {
//		unordered_map<char,char> define=
//        	{{')','('},{'}','{'},{']','['}};
//        stack<char> stk;
//        for(int i=0;i<(int)s.size();i++){
//			if(define.count(s[i])){
//				//找不到匹配的项 
//				if(stk.empty()||stk.top()!=define[s[i]]){
//					return false;
//				}
//				stk.pop();
//			}
//			stk.push(s[i]);
//		}
//		return stk.empty();
//		}
//    }
//};
//class MinStack {
//public:
//	int minvalue=10000;
//	stack<int> mainstck;
//    MinStack() {
//    }
//    
//    void push(int val) 
//	{
//    	mainstck.push(val);
//    	minvalue=min(val,minvalue);
//    }
//    
//    void pop() {
//		if(!mainstck.empty()){
//			mainstck.pop();
//		}
//    }
//    
//    int top() {
//		return mainstck.top();
//    }
//    
//    int getMin() {
//		return minvalue
//    }
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
 
 
