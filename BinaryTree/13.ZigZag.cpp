#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
struct Node{
    int data;
    Node * left;
    Node * right;
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector <int> ans;
    	if(!root)
    	    return ans;
    	queue<Node*> q;
    	q.push(root);
    	bool ltor = true;
    	while(!q.empty()){
    	    int size = q.size();
    	    int row[size];
    	    for(int i=0;i<size;i++){
    	        Node* temp = q.front();
    	        q.pop();
    	        
    	        int index = ltor ? i : (size-1-i);
    	        row[index] = temp->data;
    	        
    	        if(temp->left)
    	            q.push(temp->left);
    	        if(temp->right)
    	            q.push(temp->right);
    	    }
    	    ltor = !ltor;
    	    for(int i=0;i<size;i++){
    	        ans.push_back(row[i]);
    	    }
    	}
    	return ans;
    }
};
