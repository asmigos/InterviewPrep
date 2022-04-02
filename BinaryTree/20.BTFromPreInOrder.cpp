class Solution{
    public:
    int idx = 0;
    int searchIdx(int in[], int ele, int n){
        int rootIdx;
        for(int i=0;i<n;i++){
            if(in[i] == ele){
                rootIdx = i;
            }
        }
        return rootIdx;
    }
    Node* solve(int in[], int pre[], int lb, int ub, int n){
        if(lb>ub) return NULL;
        Node* res = new Node(pre[idx++]);
        if(lb == ub) return res;
        int mid = searchIdx(in, res->data, n);
        res->left = solve(in, pre, lb, mid-1, n);
        res->right = solve(in, pre, mid+1, ub, n);
        return res;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        Node* root = solve(in, pre, 0, n-1, n);
        return root;
    }
};