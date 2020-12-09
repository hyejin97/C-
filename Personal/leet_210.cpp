class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    vector<int> recur; //used for tracking a cycle
    vector<int> topoorder;
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //create adjacency list
        int numPreset = prerequisites.size();
        for(int i = 0; i < numCourses; i++){
            adj.push_back({});
            visited.push_back(0);
            recur.push_back(0);
        }
        for(int i = 0; i < numPreset; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        //toposort
        vector<int> empty;
        for(int i = 0; i < numCourses; i++){
            if(visited[i] == 0){
                if(toposort(i, numCourses) == false) return empty;
            }
        }
        return topoorder;
        
        
    }
    
    bool toposort(int course, int numCourses){
        visited[course] = 1;
        recur[course] = 1;
        
        for(int i = 0; i < adj[course].size(); i++){
            if(visited[adj[course][i]] == 0){
                if(!toposort(adj[course][i], numCourses)) return false;
            }
            else if(recur[adj[course][i]]) return false; //if there is a cycle
        }
        recur[course] = 0;
        topoorder.push_back(course);
        return true;
    }
};
