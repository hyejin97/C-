class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited;
        vector<int> color;
        queue<int> q;
        
        //initialize vectors
        int v = graph.size();
        for(int i = 0; i < v; i++){
            visited.push_back(0);
            color.push_back(0);
        }
        
        for(int s = 0; s < v; s++){
            if(visited[s]) continue;
            q.push(s);
            visited[s] = 1;
            while(!q.empty()){
                int cur = q.front();
                int cur_clr = color[cur];
                q.pop();
                for(int i = 0; i < graph[cur].size(); i++){
                    int nxt = graph[cur][i];
                    if(!visited[nxt]){
                        q.push(nxt);
                        visited[nxt] = 1;
                        color[nxt] = !cur_clr;
                    }
                    else{
                        if(color[nxt] == cur_clr) return false;
                    }
                }
            }
        }
        return true;
    }
};
