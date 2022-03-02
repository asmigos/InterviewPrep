  vector<int> bfsOfGraph(int V, vector<int> g[]) {
        queue q;
            int* vis; //create vec of size n with all val=0
            for(int i=0;i<n;i++){
                vis[i] = 0;
            }
            int *a;
            q.push(g);
            
            int i=0;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                a[i] = f;
                i++;
                for(auto x:g[f]){
                    if(!vis[x]){
                        vis[x] = 1;
                        q.push(x);
                    }
                }
                
            }
            return a;
  }
    