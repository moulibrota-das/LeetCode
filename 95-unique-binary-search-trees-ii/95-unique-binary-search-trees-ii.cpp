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
    vector<TreeNode*> buildTree(int start, int end){
        vector<TreeNode*> temp;
        if(start > end){
            temp.push_back(NULL);
            return temp;
        }
        
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = buildTree(start,i-1);
            vector<TreeNode*> right = buildTree(i+1, end);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    
                    temp.push_back(root);
                }
            }
            
        }
        
        return temp;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};