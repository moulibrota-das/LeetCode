/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int width = 0, minIndex = INT_MAX;
        
        while(!q.empty()){
            int n = q.size();
            auto head = q.front();
            minIndex = head.second;
            pair<TreeNode* ,int> it;
            for(int i=0; i<n; i++){
                it = q.front();
                TreeNode* temp = it.first;
                q.pop();
                
                if(temp->left) q.push({temp->left, (long long)2*(it.second-minIndex) + 1});
                if(temp->right) q.push({temp->right, (long long)2*(it.second - minIndex) + 2});
            }
            width = max(width , (it.second - head.second+1));
            // minIndex = INT_MAX;
        }
        
        return width;
    }
};