/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int n = postorder.size() - 1;
        return build(postorder, n, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& postorder, int &preIndex, int start, int end) {
        if (start > end) {
            return NULL;
        }
        int rootValue = postorder[preIndex--];
        TreeNode* root = new TreeNode(rootValue);

        int mid = map[rootValue];
        root->right = build(postorder,preIndex, mid + 1, end);
        root->left = build(postorder,preIndex, start, mid - 1);

        ;
        return root;
    }
};