class Solution{
    public:
    string chooseandswap(string a){
        // Code Here
        set<char> s;
        for(int i=0;i<a.size();i++){
            s.insert(a[i]);
        }
        
        
        for(int i=0;i<a.size();i++){
            s.erase(a[i]);
            if(s.empty()) break;
            
            char first;
            first = *s.begin();
            
            if(first < a[i]){
                char second = a[i];
                
                for(int j=0;j<a.size();j++){
                    if(a[j]==first) a[j] = second;
                    else if(a[j]==second) a[j] = first;
                }
                break;
            }
        }
        return a;
        
    }
    
}