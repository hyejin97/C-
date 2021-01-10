/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        unordered_map<TreeNode*, TreeNode*> pm; //child, parent
        unordered_map<TreeNode*, TreeNode*>::iterator pit;
        unordered_map<TreeNode*, int> dist;
        unordered_map<TreeNode*, int>::iterator dit;
        queue<TreeNode*> q;
        vector<int> res;
        
        //first do dfs on the tree and annotate parent node
        dfsTree(root, pm, NULL);
        
        //bfs starting from the target
        q.push(target);
        dist.insert({target, 0});
        while(!q.empty()){
            TreeNode* cur = q.front();
            int curdist = (dist.find(cur))->second;
            q.pop();
            
            if(!cur) continue;
            
            if(cur->left){
                if(dist.find(cur->left) == dist.end()){
                    dist.insert({cur->left, curdist + 1});
                    q.push(cur->left);
                }
            }
            if(cur->right){
                if(dist.find(cur->right) == dist.end()){
                    dist.insert({cur->right, curdist + 1});
                    q.push(cur->right);
                }
            }
            if(((pit = pm.find(cur)) != pm.end()) && pit->second){
                if(dist.find(pit->second) == dist.end()){
                    dist.insert({pit->second, curdist + 1});
                    q.push(pit->second);
                }
            }
            
        }
        
        //save its distance at a vector array
        for(dit = dist.begin(); dit != dist.end() ; dit++){
            if(dit->second == K) res.push_back(dit->first->val);
        }
        return res;
    }
    
    void dfsTree(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& pm, TreeNode* par){
        if(root == NULL) return;
        
        pm.insert({root, par});
        if(root->left) dfsTree(root->left, pm, root);
        if(root->right) dfsTree(root->right, pm, root);
    }
};
