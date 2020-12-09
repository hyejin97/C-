class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited; //whether visited
    vector<int> recur; //whether visited at the moment
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //construct a graph (course -> pre-course) in adjacency list (DAG, no-cycle)
        int numPreset = prerequisites.size();
        for(int i = 0; i < numCourses; i++){
            adj.push_back({});
            visited.push_back(0);
            recur.push_back(0);
        }
        for(int j = 0; j < numPreset; j++){
            adj[prerequisites[j][0]].push_back(prerequisites[j][1]);
        }
        //topo-sort a->b->c->...
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(isCycle(i, numCourses, prerequisites)) return false;
            }
        }
        return true;
    }
    
    bool isCycle(int course, int numCourses, vector<vector<int>>& prerequisites){
        visited[course] = 1;
        recur[course] = 1;
        
        //if there are some prerequisites, we should put it to the stack first.
        for(int j = 0; j < adj[course].size(); j++){
            if(visited[adj[course][j]] == 0){
                if(isCycle(adj[course][j], numCourses, prerequisites)) return true;
            }
            else if(recur[adj[course][j]]) return true;
        }
        
        recur[course] = 0;
        return false;
    }
}; 
