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
// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0;
//         }

//         int leftHt = height(root->left);
//         int rightHt = height(root->right);

//         int currHt = max(leftHt, rightHt) +1;
//         return currHt;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root == NULL){
//             return 0;
//         }
//         int currDiam = height(root->left) +height(root->right) ;
//         int leftDiam = diameterOfBinaryTree(root->left);
//         int rightDiam = diameterOfBinaryTree(root->right);

//         return max(currDiam, max(leftDiam, rightDiam));
//     }
// };


class Solution {
public:
    int maxi = 0;
    int dia(TreeNode* root, int& maxi){
        if(root == NULL){
            return 0;
        }

        int lh = dia(root->left,maxi);
        int rh = dia(root->right,maxi);

        maxi = max(maxi, lh + rh);

        return 1 + max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root){
        dia(root,maxi);

        return maxi;
    }

};
