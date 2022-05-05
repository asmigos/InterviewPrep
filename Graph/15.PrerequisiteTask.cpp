class Solution{
    public:

    bool dfs(int src, vector<int> &vis, vector< vector<int> > &adjList, vector<int> m){
        vis[src] = 1;
        m[src] = 1;
        
        for(auto i : adjList[src]){
            if(!vis[i]){
                bool ans = dfs(i,vis,adjList,m);
                if(ans) return true;
            }else if(m[i]){ //reaches source again in traversal of adjList of src
                return true;
            }
        }
        m[src] = 0; //mark source again to 0 so that another src could use it in its adj list
        return false;
        
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	   vector< vector<int> > adjList(N);
	   
	   
	   //preparing adj list from given nodes
	   for(int i=0;i<prerequisites.size();i++){
	       adjList[prerequisites[i].second].push_back(prerequisites[i].first);
	   }
	   
	   vector<int> vis(N,0);
	   vector<int> m(N, 0);
	   
	   //checking if cycle present-> task cannot be finished(deadlock)
	   for(int i=0;i<N;i++){
	       if(!vis[i]){
	           bool isCycle = dfs(i, vis, adjList, m);
	           
	           if(isCycle == true){
	               return false;
	           }
	       }
	   }
	   
	   
	    return true;
	}
};