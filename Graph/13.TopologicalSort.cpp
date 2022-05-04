class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> inDegree(V,0);
	    
	    //Assigning indegree to each node
	    for(int i=0;i<V;i++){
	        for(auto x : adj[i]){
	            inDegree[x]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    //if indegree of any node is 0 then push it to queue
	    for(int i=0;i<V;i++){
	        if(inDegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> ans;
	    
	    //implementing BFS
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        //decrement indegree since vertex is removed
	        for(auto x : adj[node]){
	            inDegree[x]--;
	            if(inDegree[x] == 0) q.push(x);
	        }
	        
	    }
	    return ans;
	}
};