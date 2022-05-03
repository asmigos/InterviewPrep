class Solution{

    int countRev (string s)
{
    // your code here
    int n = s.size();
    if(n%2 != 0){
        return -1;
    }
    
    int op=0;
    int cl=0;
    stack<char> st;
    for(int i=0;i<n;i++){
        if(s[i]== '{'){
            st.push(s[i]);
            op++;
        }
        else if(s[i] == '}' && !st.empty() && st.top()== '{'){
            st.pop();
            op--;
        }
        else{
            st.push(s[i]);
            cl++;
        }
    }
    
    //since we removed complete now left with only which dosen't form pair
    //}}} {{{{{ -> {}{ }{}{}.  from opening-> 3/2 = (1.5)+1 = 2 reversed
    // same for closing.
    if(op&1) op = (op/2)+1;
    else op = op/2;
    
    if(cl&1) cl = (cl/2)+1;
    else cl = cl/2;
    
    return cl+op;
}
};