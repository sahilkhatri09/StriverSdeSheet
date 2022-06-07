class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return head;
       
        int llSize = 1;
        ListNode* temp = head;
        while(temp->next != NULL ){
            temp = temp->next;
            llSize++;
        }
        
        int rotations = k % llSize;
        if(rotations == 0)return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        rotations = llSize - rotations;
        while(rotations--){
            dummy = dummy->next;
        }
        temp->next = head;
        head = dummy->next;
        dummy->next = NULL;
        
        return head;
        
        
    }
};