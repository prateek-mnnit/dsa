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
    int maxi = INT_MIN;

    int maxSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int ls = maxSum(root->left);
        int rs = maxSum(root->right);

        ls = max(0,ls);
        rs = max(0,rs);
        maxi = max(maxi,ls+rs+root->val);

        return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);

        return maxi;  
    }
};