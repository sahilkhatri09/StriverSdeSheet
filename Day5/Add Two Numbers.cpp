class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int sum = 0;
        int carry = 0;
        while(l1 || l2){
            sum = 0;
            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            temp -> next = new ListNode(sum);
            temp = temp ->next;
            
        }
        
        if(carry != 0)temp -> next = new ListNode (carry);
        
        return dummy -> next;
    }
};