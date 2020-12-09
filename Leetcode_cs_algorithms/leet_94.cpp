//
//  leet_94.cpp
//  algorithms
//
//  Created by 김혜진 on 2020. 10. 18..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Binary Tree Inorder Traversal

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
    vector<int> order;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return order;
        if(root->left == NULL && root->right == NULL){
            order.push_back(root->val);
            return order;
        }
        //traverse left
        if(root->left != NULL){
            inorderTraversal(root->left);
        }
        order.push_back(root->val);
        if(root->right != NULL){
            inorderTraversal(root->right);
        }
        return order;
    }
};
