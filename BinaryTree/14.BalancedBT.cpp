class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node * root){
        if(!root)
            return 0;
        // if(!root->left && !root->right)
        //     return 0;
            
        int l = height(root->left);
        int r = height(root->right);
        
        return (1+ max(l,r));
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(!root)
            return true;
        int diff = abs(height(root->left) - height(root->right));
        
        if((diff<2) && (isBalanced(root->left)) && (isBalanced(root->right))){
            return true;
        }
        return false;
    }
};