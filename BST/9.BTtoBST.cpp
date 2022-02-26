class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    queue<int> qorder;
    vector<int> porder;
    void preOrder(Node * root){
        if(!root)
            return;
        porder.push_back(root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void convert(Node* root){
        if(!root)
            return;
            
        convert(root->left);
        root->data = qorder.front();
        qorder.pop();
        convert(root->right);
        
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        // vector<int> porder;
        Node * temp = root;
        preOrder(temp); //O(n)
        sort(porder.begin(), porder.end()); //O(nlogn)
        
        for(int i=0;i<porder.size();i++){ //O(n)
            qorder.push(porder[i]);
        }
        convert(root); //O(log n)
        
        return root;
    }
    
    
    
};
