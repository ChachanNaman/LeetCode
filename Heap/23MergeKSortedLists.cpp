//Merge k Sorted Lists
//https://leetcode.com/problems/merge-k-sorted-lists/?envType=problem-list-v2&envId=heap-priority-queue

#include <queue>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    class compare{
        public:
        bool operator()(ListNode *a , ListNode*b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode * , vector<ListNode*> , compare>minheap;

        //step-1 -> push all first element of K LLs in minheap
        int k = lists.size();
        for(int i = 0 ; i<k; i++){
            if(lists[i] != NULL){  //check if theres value , if there push
                minheap.push(lists[i]);
            }
        }
        //step-2->point head and tail to first element of minheap then move tail forward 
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(minheap.size()>0){
            ListNode* top = minheap.top();
            minheap.pop();
            
             if(top->next != NULL){
                    minheap.push(top->next);
             }//general that if something there then push
            if(head == NULL){//now pointing head , initially it is null soo first head will minheap.top tail also then 
                head = top;
                tail = top;//first case first node case
            }
            else{//first node made now tail moves forward and head stays there
                tail ->next = top;  //moves to next 
                tail = top;
            }
        }
        return head;
    }
};