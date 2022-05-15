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
    int high = 0;
    int sum = 0;
    void dfs(TreeNode* root,int count){
        if(root == NULL) return;
        
        if(count == high){
            sum += root->val;
        }
        else if(count > high){
            high = count;
            sum = root->val;
        }
        
        dfs(root->left, count+1);
        dfs(root->right, count+1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};