//
//  bfstraverse.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Task : saving depth and parent of each node of a tree

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[10]; //save neighbors of each node
int p[10]; //saving parents
int depth[10]; //saving depth of each node

void bfs(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
    
}

