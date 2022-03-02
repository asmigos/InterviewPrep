public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<bool> &vis, vector<int> adj[], vector<int> &m){
        vis[src] = true;
        m[src] = 1;
        
        for(auto i : adj[src]){
            if(vis[i] == false){
                bool conf = dfs(i,vis,adj, m);
                if(conf){
                    return true;
                }
            }else if(m[i]){
                return true;
            }
        }
        m[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<int> m(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = dfs(i,vis,adj, m);
                if(ans == true){
                    return true;
                    
                }
            }
        }
        return false;
    }