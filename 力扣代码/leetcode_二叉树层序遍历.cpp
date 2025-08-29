#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
		if(!root)
			return answer;
		queue<TreeNode*> cengqueue;
		cengqueue.push(root);
		vector<int> addarr;
		addarr.push_back(root->val);
		answer.push_back(addarr);
		addarr.clear();
		while(!cengqueue.empty()){
			int n=cengqueue.size();
			for(int i=0;i<n;i++){
				TreeNode* temp=cengqueue.front();
				cengqueue.pop();
				addarr.push_back(temp->val);
				if(temp->left){
					cengqueue.push(temp->left);
				}
				if(temp->right){
					cengqueue.push(temp->right);
				}
			}
			answer.push_back(addarr);
			addarr.clear();
		}
		return answer;
    }
};
int main()
{
	return 0;
}
