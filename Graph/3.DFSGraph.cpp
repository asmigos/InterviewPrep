 Solution{   
    public:
        // Function to return a list containing the DFS traversal of the graph.
        vector<int> ans;
        void dfs(int src,map<int,bool> &vis,vector<int> adj[]){
            vis[src] = true;
            ans.push_back(src);
            for(auto x:adj[src]){
                if(vis[x]==0)
                    dfs(x, vis,adj);
            }
        }
        vector<int> dfsOfGraph(int V, vector<int> adj[]) {
            // Code here
            ans.clear();
            
            map<int, bool> vis;
            dfs(0,vis,adj);
            
            return ans;
        }
 };