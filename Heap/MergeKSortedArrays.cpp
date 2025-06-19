//Merge k Sorted Arrays
//https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1?page=1&category=Heap&sortBy=submissions

#include <queue>

class Solution {
  public:
    class node{
        public :
        int data;
        int i;  //rows
        int j;  //cols
        
        node(int data , int row , int col){
            this -> data = data ;
            i = row ;
            j = col;
        }
    };
    
    class compare{
        public:
        bool operator()(node *a , node*b){
            return a->data > b->data;
        }
    };
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    
    priority_queue<node * , vector<node*> , compare>minheap;
    
    //step-1->insert every 1st element of each array
        for(int i = 0 ; i<K; i++){
        node* tmp = new node(arr[i][0], i , 0);  //i variable and j =0 means first element of each array
        minheap.push(tmp);
        }
        
    //step-2->push top element of min heap into ans 
        vector<int> ans; //pehle first element insert kie aab min heap ka top store kara lia ans mein
        while(minheap.size()>0){
            node *tmp = minheap.top();
            ans.push_back(tmp->data);
            minheap.pop();
            
            
            int i = tmp->i;
            int j = tmp->j;
            
            //now check for next element of same index of tmp if its in size 
            if(j+1<arr[i].size()){//check if next element is in ith row or not
                //if yes then push into minheap
                node *next = new node(arr[i][j+1], i , j+1);
                minheap.push(next);
            }
        }
        
        return ans;
        
        
    }
};