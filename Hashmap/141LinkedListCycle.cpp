//141. Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/description/?envType=problem-list-v2&envId=hash-table

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
        map<ListNode * , bool > visited;    
        ListNode * temp = head;

        while(temp != NULL){
            if(visited[temp]==true){
                return true;   //if caught to be true already then get marked true
            }
            visited[temp]= true;  //marked here true for every node
            temp = temp->next;

        }
        return false;
    }
};