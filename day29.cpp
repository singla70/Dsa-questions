// GFG FIND LENGTH OF LOOP
TC O(N)
SC O(1)
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* slow = head, *fast=head;
        bool flag = false;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if( slow == fast) {
                flag = true;
                break;
            }
        }
        Node* temp = head;
        if(flag == true) {
            while(temp != slow) {
                slow = slow ->next;
                temp = temp ->next;
            }
             
        int count =1;
        slow = slow -> next;
        while(slow != temp) {
            count ++;
            slow = slow -> next;
        }
        return count;
        }
        return 0;     
    }
};





// LEETCODE 234 
SC O(N)
TC O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || ! (head -> next)) return true;
        ListNode* temp = head;
        vector<int> v;
        while(temp) {
            v.push_back(temp-> val);
            temp = temp -> next;
        }
        int i=0,j=v.size()-1;
        while(i<j) {
            if(v[i++] != v[j--]) return false;
        }
        return true;
        
    }
};
