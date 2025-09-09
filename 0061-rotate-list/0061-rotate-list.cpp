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

 int GetSize(ListNode* head){
    ListNode* temp = head ;
    int count = 0 ; 
    while(temp) {
        count++ ; 
        temp = temp->next ; 
    }
    return count ; 

 }
 ListNode*GetLastNode(ListNode*head){
    ListNode* temp = head ;
    
    while(temp->next) { 
        temp = temp->next ; 
    }
    return temp; 
 }
 ListNode*GetKthNode(ListNode*head , int k){
    ListNode* temp = head ;
    int count = 1 ; 
    while(temp){
        if(count == k){
            return temp ; 
        }
        count++ ; 
        temp = temp->next ; 

 }
 return nullptr ;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head ; 
        }
        int size = GetSize(head) ; 
        k = k % size ; 
        if(k == 0){
            return  head ; 
        }
        ListNode*tail = GetLastNode(head) ; 
        int diff  = size - k ; 
        ListNode*kthnode = GetKthNode(head,diff) ; 
        tail->next = head ; 
        head = kthnode->next ; 
        kthnode->next = nullptr ; 
        return head ; 
    }
};