class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(-1);
        temp ->next =head;
        ListNode* slow = temp;
        ListNode* fast = head;
        while(n--){
            fast = fast -> next;
        }
        while(fast!=NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow ->next = slow->next->next;
        return temp -> next;
    }
};