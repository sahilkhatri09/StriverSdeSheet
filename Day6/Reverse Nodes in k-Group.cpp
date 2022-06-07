class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check = head;
        for(int i=0; i<k; i++){
            if(check == NULL)return head;
            check = check -> next;
        }
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nex = head;
        
        for(int i=0; i<k; i++){
            nex = nex -> next;
            cur -> next = pre;
            pre = cur;
            cur = nex;
        }
        head -> next = reverseKGroup(cur,k);
        return pre;
    }
};