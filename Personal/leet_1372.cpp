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
    //to compute the longest path, need to compute all the longest zigzag paths starting from each node in the tree
    //at each node, there are two cases --starting from right or left
    //basecase : starting node is leaf -> 0
    //compute max between
    //1. lp starting from leftchild
    //2. lp starting from rightchild
    //3. lp starting from root with left as the first direction
    //4. lp starting from root with right as the first direction
    
    //prev : 0 - left / 1 - right;
    int lp = 0;
    void zigzagTraverse(TreeNode* root, int count, int prev){
        if(!root) return;
        
        lp = max(lp, count);
        
        if(prev == 1){
            zigzagTraverse(root->right, 1, 1); //lp starting from rightchild
            zigzagTraverse(root->left, count + 1, 0); //lp starting from root with left as the first direction
        }
        else{
            zigzagTraverse(root->left, 1, 0); //lp starting from leftchild
            zigzagTraverse(root->right, count + 1, 1); //lp starting from root with right as the first direction
        }
    }
    
    int longestZigZag(TreeNode* root){
        zigzagTraverse(root, 0, 0);
        return lp;
    }
    
    
};
