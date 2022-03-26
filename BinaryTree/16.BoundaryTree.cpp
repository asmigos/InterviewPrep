public:
    void leftNode(Node* root, vector <int>& ans ){
        if(!root) return;
        if(root->left){
            ans.push_back(root->data);
            leftNode(root->left, ans);
        }
        else if(root->right){
            ans.push_back(root->data);
            leftNode(root->right, ans);
        }
    }
    void leafNode(Node* root, vector <int>& ans ){
        if(!root)
            return;
        leafNode(root->left, ans);
        if(!root->left && !root->right) ans.push_back(root->data);
        leafNode(root->right, ans);
    }
    void rightNodeRev(Node* root, vector <int>& ans ){
        if(!root)
            return;
        if(root->right){
            rightNodeRev(root->right, ans);
            ans.push_back(root->data);
        }else if(root->left){
            rightNodeRev(root->left, ans);
            ans.push_back(root->data);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        
        if(!root)
            return ans;
        ans.push_back(root->data);
        if(!root->left && !root->right){
            return ans;
        }
        leftNode(root->left, ans);
        leafNode(root,ans);
        rightNodeRev(root->right, ans);
        
        return ans;
    }