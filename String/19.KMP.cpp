class Solution{
    public:		
	int lps(string s) {
	    // Your code goes here
	    //METHOD - 1 == O(n^2)
	   int i=0, j=s.size()-1;
	   int count =0;
	   while(i<s.size()-1 && j > 0){
	      if(s.substr(0,i+1) == s.substr(j,s.size())){
	          count = i+1;
	      }
	      i++;
	      j--;
	   }
	   return count;
	   
	   //METHOD - 2  == O(n)
	   int lps[s.size()];
	   int len = 0, i=1;
	   lps[0] = 0;
	   
	   while(i < s.size()){
	       if(s[i] == s[len]){
	           lps[i] = len+1;
	           len++;
	           i++;
	       }
	       else{
	           if(len != 0){
	               len = lps[len-1];
	           }else{
	               lps[i] = 0;
	               i++;
	           }
	       }
	   }
	   return lps[s.size()-1];
	}
};