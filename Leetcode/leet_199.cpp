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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> res;
        if(!root) return res;
        
        q.push(root);
        
        while(!q.empty()){
            int cursize = q.size();
            for(int i = 0; i < cursize; i++){
                
                TreeNode* cur = q.front();
                q.pop();
                
                if(i == 0) res.push_back(cur->val);
                
                if(cur->right){
                    q.push(cur->right);
                }
                if(cur->left){
                    q.push(cur->left);
                }
            }
            
        }
        return res;
    }
};
