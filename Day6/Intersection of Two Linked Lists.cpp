class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode* temp1 = headA , *temp2 = headB;
        while(temp1 || temp2){
            if(temp1){
                n1++;
                temp1 = temp1 -> next;
            }
            if(temp2){
                n2++;
                temp2 = temp2 -> next;
            }
        }
        if(n1 >= n2){
            temp1 = headA;
            temp2 = headB;
        }
        else{
            temp1 = headB;
            temp2 = headA;
        }
        int diff = abs(n1 - n2);
        while(diff--) temp1 = temp1 -> next;
        while(temp1){
            if(temp1 == temp2)return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return temp1;
    }
};