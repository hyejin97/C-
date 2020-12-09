//
//  leet_404.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 14..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//404. Sum of Left Leaves

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        
        //if left child is leaf
        //add and look at the right child
        if((root->left) && !(root->left->left) && !(root->left->right)) return root->left->val + sumOfLeftLeaves(root->right);
        //else traverse both left and right children
        else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        
        
    }
};
