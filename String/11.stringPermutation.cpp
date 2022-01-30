#include <iostream>
#include <vector>

using namespace std;


class Solution{
    	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> vecString;
		    if(S.size()==0)
		        return vecString;
		  
		    sort(S.begin(), S.end());
		    
		    do{
		        vecString.push_back(S);
		    }while(next_permutation(S.begin(), S.end()));
		    
		    return vecString;
		}
};