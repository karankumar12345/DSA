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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if (root == NULL) {
            return ans;
        }

        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int lev = temp.second.first;
            int hd = temp.second.second;
            nodes[lev][hd].push_back(frontNode->val);
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, make_pair(lev - 1, hd +1)));
            }
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, make_pair(lev + 1, hd + 1)));
            }
        }
        for (auto i : nodes) {
            vector<int> temp;
            for (auto it : i.second) {
                if (it.second.size()> 1) {
                    sort(it.second.begin(), it.second.end());
                }
                for (auto j : it.second) {
                    temp.push_back(j);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};