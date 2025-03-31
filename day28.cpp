LEETCODE 876
  TC O(N)
  SC O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head== NULL|| head -> next == NULL) return head;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};

LEETCODE 141 
   TC O(N)
  SC O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast -> next !=NULL) {
           
            slow = slow ->next;
            fast = fast-> next -> next;
            if(slow==fast) return true;
        }
        return false;
        
    }
};
