//
//  binarytree.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//4 ways to traverse a bianry tree

#include <iostream>
#include <queue>

using namespace std;

int lc[9] = {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9] = {0, 3, 5, 7, 0, 8, 0, 0, 0};

//level order traversal
void levelTraverse(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
}

//preorder traversal
void preorderTraverse(int cur){
    cout << cur << '\n';
    if(lc[cur]) preorderTraverse(lc[cur]);
    if(rc[cur]) preorderTraverse(rc[cur]);
}

//inorder traversal
void inorderTraverse(int cur){
    if(lc[cur]) inorderTraverse(lc[cur]);
    cout << cur << '\n';
    if(rc[cur]) inorderTraverse(rc[cur]);
}

//postorder traversal
void postorderTraverse(int cur){
    if(lc[cur]) inorderTraverse(lc[cur]);
    if(rc[cur]) inorderTraverse(rc[cur]);
    cout << cur << '\n';
}




