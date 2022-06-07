class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode* slow = head;
       ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }
        if(fast == NULL || fast->next == NULL)return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};


/*
length till  cycle = m;
length of cycle = n;
length  where slow and fast meet from start of loop = l
distance by slow = m + i*n +l;
distance by fast = m + j*n +l;
now slow * 2 = fast;
2m + 2i*n + 2l = m + j*n + l;
m = n*(j-2i) - l;
now j-2i is an integer so some cycle so m = n-l;
so slow and fast will meet at start of loop 

*/