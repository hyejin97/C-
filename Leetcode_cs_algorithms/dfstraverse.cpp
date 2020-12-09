//
//  dfstraverse.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//Task : saving depth and parent of each node of a tree

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[10];
int p[10];
int depth[10];

void dfs(int cur){
    cout << cur << '\n';
    for(int i = 0; i < adj[cur].size(); i++){
        int nxt = adj[cur][i];
        if(p[cur] == nxt) continue;
        p[nxt] = cur;
        depth[nxt] = depth[cur] + 1;
        dfs(nxt);
    }
}

