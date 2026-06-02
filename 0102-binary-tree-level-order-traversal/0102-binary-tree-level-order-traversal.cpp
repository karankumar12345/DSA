class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size=q.size();

            vector<int> path;

            for(int i=0;i<size;i++){

                TreeNode* node=q.front();
                q.pop();

                path.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            ans.push_back(path);
        }

        return ans;
    }
};