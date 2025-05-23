//https://www.geeksforgeeks.org/problems/merge-two-bst-s/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root , vector<int> &in){
        if(root == NULL){
            return;
        }
        inorder(root->left , in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        //stored inorder in vector 
        vector<int> bst1 , bst2; //created vector to store inorder for both
        inorder(root1 , bst1);
        inorder(root2 , bst2);

        //merge two sorted arrays
        vector<int>sorted = merge(bst1 , bst2);

        //converting sorted to bst
        // int s =0;
        // int e = sorted.size()-1;
        // return inordertoBST(s ,e , sorted);
        
        return sorted;
    }
    
       vector<int> merge(vector<int> bst1, vector<int> bst2){
        vector<int> ans(bst1.size()+bst2.size());
        int i = 0 , j = 0 , k = 0;
        while(i<bst1.size() && j<bst2.size()){
            if(bst1[i]<bst2[j]){
                ans[k++]=bst1[i];
                i++;
            }
            else{
                ans[k++]=bst2[j];
                j++;
            }
        }
        while(i<bst1.size()){
            ans[k++]=bst1[i];
                i++;
        }
        while(j<bst2.size()){
            ans[k++]=bst2[j];
                j++;
        }
        return ans;
    }
    
   Node* inordertoBST(int s ,int e , vector<int> &sorted){
        if(s>e){//base case
            return NULL;
        }
        int mid = (s+e)/2;
        Node* root = new Node(sorted[mid]);
        root->left = inordertoBST( s ,mid -1 ,sorted);
        root->right = inordertoBST( mid+1, e ,sorted);
        return root;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends