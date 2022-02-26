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

class Pair{
        
     public:  
        int hd;
        Node* node;
        Pair(int hd, Node* node){
            this->node = node;
            this->hd = hd;
        }
    };
   
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<Pair> que;
        map<int, int> ma;
        
        que.push(Pair(0, root));
        while(!que.empty()){
            Pair curr = que.front();
            que.pop();
                ma[curr.hd] = curr.node->data;
            if(curr.node->left != NULL){
                Pair p(curr.hd-1, curr.node->left);
                que.push(p);
            }
            if(curr.node->right != NULL){
                Pair p(curr.hd+1, curr.node->right);
                que.push(p);
            }
        }
        vector<int> ans;
        for (auto itr = ma.cbegin(); itr != ma.cend(); ++itr) {
              ans.push_back(itr->second);
        }
        return ans;
    }
    
     
    

};