class Solution {
public:
    ListNode* reverse(ListNode* prev,ListNode* head){
        if(head == NULL) return prev;
        
        ListNode* temp = head->next;
        head -> next = prev;
        return reverse(head,temp);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 =reverse(NULL,slow);
        cout<<head2->val;
        while( head2 ){
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};