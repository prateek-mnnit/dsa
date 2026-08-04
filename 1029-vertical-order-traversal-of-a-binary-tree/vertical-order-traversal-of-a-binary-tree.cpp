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
    // column -> row -> sorted values
    map<int, map<int, multiset<int>>> mp;

    void dfs(TreeNode* root, int col, int row) {

        if (root == NULL)
            return;

        mp[col][row].insert(root->val);

        dfs(root->left, col - 1, row + 1);
        dfs(root->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        vector<vector<int>> ans;

        // Traverse columns in sorted order
        for (auto &col : mp) {

            vector<int> temp;

            // Traverse rows in sorted order
            for (auto &row : col.second) {

                // Traverse values in sorted order
                for (auto val : row.second) {

                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};