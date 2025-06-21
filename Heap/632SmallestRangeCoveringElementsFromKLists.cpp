//632. Smallest Range Covering Elements from K Lists
//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/?envType=problem-list-v2&envId=heap-priority-queue

#include <queue>
class Solution {

    class node{
        public:
        int data ;
        int row; 
        int col;
        node(int data , int i , int j){
            this->data = data;
            row = i;
            col = j;

        }
    };
    class compare{
        public :
        bool operator()(node* a , node* b){
            return a->data > b->data;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX , maxi = INT_MIN;
        priority_queue<node* , vector<node*> , compare> minheap;
        for(int i = 0; i<k;i++){
            int element = nums[i][0];
            mini = min(mini , element);
            maxi = max(maxi , element);
            minheap.push(new node(element, i, 0));
        }
        int start = mini , end = maxi;

        while(!minheap.empty()){
            node *temp = minheap.top();
            minheap.pop();
            mini = temp->data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            if(temp->col+1 <nums[temp->row].size()){
                maxi = max(maxi , nums[temp->row][temp->col+1]);
                minheap.push(new node(nums[temp->row][temp->col+1], temp->row , temp->col+1));
            }
            else {
                break;
            }
        }
        return {start, end};
    }
};