//
//  bfspathlen.cpp
//  C++
//
//  Created by 김혜진 on 2020. 9. 29..
//  Copyright © 2020년 김혜진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10];
int dist[10];

void bfs(){
    for(int i = 0; i < 10; i++) dist[i] = -1;
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
    
    
}
int main(){
    
}
