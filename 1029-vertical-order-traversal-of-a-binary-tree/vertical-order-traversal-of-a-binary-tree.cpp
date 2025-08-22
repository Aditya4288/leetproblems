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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            TreeNode* node = frontNode.first;
            int hd = frontNode.second.first;
            int lvl = frontNode.second.second;

            // Add value of node to map (nodes)
            nodes[hd][lvl].insert(node->val);
            
            if(node->left) q.push({node->left, {hd-1, lvl+1}});
            if(node->right) q.push({node->right, {hd+1, lvl+1}});
        }

        vector<vector<int>> result;
        for(auto& [hd, levelMap]: nodes){
            vector<int> vertical;
            for(auto& [lvl, values]: levelMap){
                vertical.insert(vertical.end(), values.begin(), values.end());
            }
            result.push_back(vertical);
        }

        return result;
    }
};