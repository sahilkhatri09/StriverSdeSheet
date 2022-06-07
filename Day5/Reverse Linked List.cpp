// Approach 1 Recursion
class Solution {
public:
    ListNode* reverse(ListNode* head,ListNode* pre){
        if(head == NULL) return pre;
        
        ListNode* temp = head -> next;
        head -> next = pre;
        return reverse(temp, head);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};

// Approach 2 iteration
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nex = head;
        while(nex != NULL){
            nex = nex -> next;
            cur -> next = pre;
            pre = cur;
            cur = nex ;
        }
        return pre;
    }
};