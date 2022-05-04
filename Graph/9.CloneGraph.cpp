class Solution {
public:
    void dfs(Node* node, Node* copy, vector<Node*>& vis){
        vis[copy->val] = copy; // storing so that can be used directly at : 1
        for(auto x : node->neighbors){ //traversing all neighbors
            if(vis[x->val] == NULL){
                Node* newNode = new Node(x->val); //creating new node
                (copy->neighbors).push_back(newNode); //putting new node in neighbor of curr node
                dfs(x,newNode, vis); //calling dfs on new node
            }else{
                //1 : used here since this can be already visited by some other node as its neighbor
                (copy->neighbors).push_back(vis[x->val]); 
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        
        vector<Node*> vis(1000,NULL);
        Node* copy = new Node(node->val);
        
        dfs(node, copy, vis);
        
        return copy;
    }
};