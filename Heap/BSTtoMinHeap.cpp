#include <iostream>
#include <vector>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

struct Node {
    int data;
    Node *left, *right;
};

void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}

struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preorderTraversal(Node* root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}
 

int main()
{
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    vector<int> arr;
    inorderTraversal(root, arr);
        root->data = arr[0];
        root->left->data = arr[1];
        root->right->data = arr[2];
        root->left->left->data = arr[3];
    root->left->right->data = arr[4];
    root->right->left->data = arr[5];
    root->right->right->data = arr[6];

    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}