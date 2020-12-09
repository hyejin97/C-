//
//  leet_886.cpp
//  C++
//
//  Created by 김혜진 on 2020. 10. 1..
//  Copyright © 2020년 김혜진. All rights reserved.
//

//886.possible bipartition 
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int *visited = new int[N+1];
        int *color = new int[N+1];
        
        for(int i = 0; i < N+1; i++){
            visited[i] = 0;
            color[i] = 0;
        }
        //create an adjacency list for undirected list
        vector<vector<int>> adj(N+1);
        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i = 1; i < N+1; i++){
            if(!visited[i]){
                bool res = dfsBipartition(i, adj, visited, color);
                if(res == false) return false;
            }
        }
        return true;
    }
    
    bool dfsBipartition(int cur, vector<vector<int>> &adj, int *visited, int *color){
        for(int i = 0; i < adj[cur].size(); i++){
            int nxt = adj[cur][i];
            if(visited[nxt]){
                //ruin the rule if already the same color
                if(color[nxt] == color[cur]) return false;
            }
            else{
                visited[nxt] = true;
                color[nxt] = !color[cur];
                int res = dfsBipartition(nxt, adj, visited, color);
                if(res == false) return false;
            }
        }
        return true;
        
    }
};
