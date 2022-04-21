class Solution{
    //method 1
    public:
    void storeArray(Node *root, vector<int> & array){
        if(!root)
            return;
            
        storeArray(root->left, array);
        array.push_back(root->data);
        storeArray(root->right, array);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> array;
        
        storeArray(root, array);
        sort(array.begin(), array.end());
        return array[array.size()-K];
    }


};