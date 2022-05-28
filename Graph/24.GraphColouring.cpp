class Solution{
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<bool> colour(n, false);
        vector<int> res(n,-1);
        res[0] = 0;
        
        int chromaticNum=0;
        for(int i=1;i<n;i++){
            //checking which colours are used in adj vertex
            for(auto x : graph[i]){
                if(res[x] != -1){
                    colour[res[x]] = true;
                }
            }
            
            int cr;
            for(int cr=0;cr<n;cr++){
                if(colour[cr] == false)
                    break;
            }
            
            res[i] = cr;
            chromaticNum = max(chromaticNum, cr+1);
            
            for(auto x : graph[i]){
                if(res[x] != -1){
                    colour[res[x]] = false;
                }
            }
        }
        cout<<m<<" "<<chromaticNum;
        if(m >= chromaticNum){
            return true;
        }
        
        return false;
    }
};