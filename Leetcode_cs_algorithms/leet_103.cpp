
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
    vector<vector<int>> levels;
    queue<pair<TreeNode*, int>> q; //node pointer, leftorright(left -- 0, right --1)
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //level order --> bfs
        //zigzag -->if previous direction was left, traverse down right and vice versa.
        if(!root) return levels;
        levels.push_back({});
        levels[0].push_back(root->val);
        q.push({root, 0});
        
        while(!q.empty()){
            int num = q.size(); //the number of items in the same level
            vector<int> order;
            int flag = q.front().second;
            for(int i = 0; i < num; i++){
                pair<TreeNode*, int> cur = q.front();
                q.pop();
                
                if(cur.first->right){
                    order.push_back(cur.first->right->val);
                    q.push({cur.first->right, 1 - flag});
                }
                if(cur.first->left){
                    order.push_back(cur.first->left->val);
                    q.push({cur.first->left, 1 - flag});
                }
                
            }
            if(flag == 0 && order.size() > 0) levels.push_back(order); //if previous direction was left
            else if(flag == 1 && order.size() > 0){ //if previous direction was right
                reverse(order.begin(), order.end());
                levels.push_back(order);
            }
        }
        
        return levels;
    }
    
};
