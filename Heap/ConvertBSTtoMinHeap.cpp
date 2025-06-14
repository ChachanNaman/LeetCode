#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public :
     int data;
     Node *left;
     Node *right;
     Node(int x){
        data = x;
        left = right  = NULL;
     }
};

void toinorder(Node *root, vector<int> &ansin){
    if(root == NULL){  //BASE CASE
        return;
    }

    toinorder(root->left , ansin);
    ansin.push_back(root->data);
    toinorder(root->right , ansin);
}

void intopreorder(Node *root,vector<int> &ansin , int &index ){
    if(root == NULL){
        return ;
    }
    root->data = ansin[index++];

    intopreorder(root->left,ansin ,index );
    intopreorder(root->right,ansin ,index );
}

void preorderprint(Node *root){
    if(root == NULL){
        return ;
    }
    cout<<root->data <<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}
int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);
 
    vector<int> ans;
    toinorder(root, ans);

    int index = 0;
    intopreorder(root, ans, index);

    preorderprint(root);
    cout<<endl;
}