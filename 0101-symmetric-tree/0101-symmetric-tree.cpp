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
    bool isSameTree(TreeNode* lefttree, TreeNode* righttree) {
        if(lefttree==NULL && righttree==NULL){
            return true;
        }
        if(lefttree==NULL || righttree==NULL){
            return false;
        }
        return (lefttree->val==righttree->val && isSameTree(lefttree->left,righttree->right)&& isSameTree(lefttree->right,righttree->left));
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return isSameTree(root->left, root->right);
    }
};