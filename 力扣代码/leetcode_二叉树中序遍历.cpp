#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
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
	vector<int> zhongxupailie(TreeNode* root,vector<int>& answer)
	{
		if(!root){
			return answer;
		}
		zhongxupailie(root->left,answer);
		answer.push_back(root->val);
		zhongxupailie(root->right,answer);
		return answer;
	}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        answer=zhongxupailie(root,answer);
        return answer;
    }
};

int main()
{
	Solution so;
	TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node3, nullptr);
    TreeNode* node1 = new TreeNode(1, nullptr, node2);
    vector<int> answer=so.inorderTraversal(node1);
    
    for(auto node : answer)
    {
		cout<<node<<endl;
	}
	return 0;
}
