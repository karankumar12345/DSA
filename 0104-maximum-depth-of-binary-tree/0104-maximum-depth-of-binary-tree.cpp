class Solution {
public:

    int Height(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int left = Height(root->left);
        int right = Height(root->right);

        return 1 + max(left,right);
    }

    int maxDepth(TreeNode* root) {
        return Height(root);
    }
};