LEETCODE 19
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || ! head-> next) return NULL;
        ListNode* temp = head;
        int size=0;
        while(temp) {
            temp = temp -> next;
            size++;
        }
        if(n== size) {
            return head-> next;
        }
        
        int i=1;
        temp= head;
        while(i<size-n) {
            temp = temp -> next;
            i++;
        }
        if(temp) temp-> next = temp -> next -> next;
        return head;
        
    }
};



LEETCODE 148
class Solution {
public:
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* n= new ListNode(0);
        ListNode* n2= n;
        while(h1 && h2) {
            if(h1-> val > h2-> val) {
                n-> next = h2;
                h2= h2-> next;
                n= n-> next;
            }
            else {
                n-> next = h1;
                h1= h1-> next;
                n= n-> next;
            }
        }
            if(!h1) {
                n-> next =h2;
            }
            else if(!h2) n-> next = h1;
        return n2-> next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || ! head-> next) return head;
        ListNode* slow= head, *fast= head;
        while(fast->next && fast-> next->next) {
            slow= slow-> next;
            fast = fast-> next-> next;
        }
        ListNode* head2= slow-> next;
        slow-> next =NULL;
       head= sortList(head);
        head2 = sortList(head2);
        return merge(head,head2);   
    }
};
