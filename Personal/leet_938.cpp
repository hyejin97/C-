//
//  leet_938.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

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

//938.Range Sum of BST
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if(root == NULL) return 0;
        else if(root->val < L){
            return rangeSumBST(root->right, L, R);
        }
        else if(root->val > R){
            return rangeSumBST(root->left, L, R);
        }
        //root->val >= L && root->val <= R
        else{
            return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        }
    }
};
