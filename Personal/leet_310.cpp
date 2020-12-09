//
//  leet_310.cpp
//  codingtestprep
//
//  Created by 김혜진 on 2020. 11. 15..
//  Copyright © 2020년 김혜진. All rights reserved.
//


//O(N^2) time complexity solution
class Solution {
public:
    queue<int> q;
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //connected graph, run bfs once starting from each node (total n times)
        //compute height of each tree with different root and get the minimum
        int* visited = new int[n];
        int* height = new int[n];
        int* minroot = new int[n];
        int minheight = 2*n;
        vector<int> output;
        
        for(int i = 0; i < n; i++){
            fill(&visited[0], &visited[n], 0);
            fill(&height[0], &height[n], 0);
            q.push(i);
            visited[i] = 1;
            
            minroot[i] = bfs(n, edges, visited, height);
            minheight = min(minheight, minroot[i]);
        }
        
        for(int i = 0; i < n; i++){
            if(minroot[i] == minheight) output.push_back(i);
        }
        return output;
    }
    
    int bfs(int n, vector<vector<int>>& edges, int* visited, int* height){
        int e = edges.size();
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < e; i++){
                if(edges[i][0] == cur && visited[edges[i][1]] != 1){
                    int nxt = edges[i][1];
                    q.push(nxt);
                    visited[nxt] = 1;
                    height[nxt] = height[cur] + 1;
                }
                else if(edges[i][1] == cur && visited[edges[i][0]] != 1){
                    int nxt = edges[i][0];
                    q.push(nxt);
                    visited[nxt] = 1;
                    height[nxt] = height[cur] + 1;
                }
            }
        }
        
        int h = 0;
        for(int i = 0; i < n; i++){
            h = max(h, height[i]);
        }
        
        return h;
    }
};


//O(n) time complexity solution
//topological sort -> find centroid
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> output;
        
        //exception : null
        if(edges.size() == 0){
            output.push_back(0);
            return output;
        }
        
        //build adjacency list
        int e = edges.size();
        vector<vector<int>> adj;
        for(int i = 0; i < n; i++){
            adj.push_back({});
        }
        for(int i = 0; i < e; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //create q
        queue<int> q;
        
        //put all the leaves to the q
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 1){
                q.push(i);
            }
        }
        
        //at each iteration, remove the current leaf from q and remove its associated edges
        //iterate until having <=2 nodes
        int remain = n;
        while(remain > 2){
            remain = remain - q.size();
            int leafsize = q.size();
            for(int k = 0; k < leafsize; k++){
                int cur = q.front();
                q.pop();
                
                int el = adj[cur].front();
                adj[cur].pop_back();
                for(int i = 0; i < adj[el].size(); i++){
                    if(adj[el][i] == cur) adj[el].erase(adj[el].begin() + i);
                }
                if(adj[el].size() == 1){
                    q.push(el);
                }
            }
        }
        
        while(!q.empty()){
            output.push_back(q.front());
            q.pop();
        }
        return output;
    }
};
