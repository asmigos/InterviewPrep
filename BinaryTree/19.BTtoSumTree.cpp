class Solution{
    public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sum(Node* node){
        if(!node){
            return 0;
        }
        
        int a = sum(node->left);
        int b = sum(node->right);
        int temp = node->data;
        node->data = a+b;
        return a+b+temp;
    }
    
    
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
    }
}