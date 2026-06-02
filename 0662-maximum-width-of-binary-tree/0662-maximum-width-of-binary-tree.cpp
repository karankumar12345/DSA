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
        if (root == NULL) {
            return 0;
        }

        // Queue stores pairs of nodes and their index positions in the tree
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long minIndex = q.front().second;  // To avoid overflow for large trees
            long long first, last;

            for (int i = 0; i < size; i++) {
                long long currIndex = q.front().second - minIndex;  // Normalize current index
                TreeNode* node = q.front().first;
                q.pop();

                // Store the first and last index at each level
                if (i == 0) first = currIndex;
                if (i == size - 1) last = currIndex;

                // Push left and right children with updated index positions
                if (node->left) {
                    q.push({node->left, 2 * currIndex + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * currIndex + 2});
                }
            }

            // Update the maximum width
            maxWidth = max(maxWidth, int(last - first + 1));
        }

        return maxWidth;
    }
};