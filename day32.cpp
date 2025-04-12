LEETCODE 25
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL,*curr = head;
        while(curr) {
            ListNode* Next= curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || ! head->next) return head;
        if(left>=right) return head;

        // break list in 3 parts -> 1 to left -1 and left to right and right+1 to end
        // reverse left to right

        ListNode* temp= head;
        ListNode* a=NULL,*b=NULL,*c=NULL,*d=NULL;
        int i=1;
        while(temp) {
            if(i== left-1) a = temp;
            if(i==left) b = temp;
            if(i==right) c= temp;
            if(i== right+1) d= temp;
            i++;
            temp = temp->next;   
        }
        if(c) c-> next = NULL;
        ListNode* reversedhead= reverse(b);
        if(a) a-> next = reversedhead; 
        else head = reversedhead;
        b-> next =d;
        return head;
        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;
        ListNode* temp = head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevTail = dummy;

        
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        while(temp) {
            
            ListNode* check = temp;
            int count = 0;
            while (check && count < k) {
                check = check->next;
                count++;
            }
            if (count < k) break;

            a= temp;
            int i=1;
            b= temp;
            while(i<k) {
                b = b -> next;
                i++;
            }
            
            

           c= b-> next;
           b-> next = NULL;
            ListNode* d= reverseBetween(a,1,k);
            prevTail->next = d;
            prevTail = a;
            a-> next = c;
            temp = c;
            

        }
        return  dummy->next;

        
    }
};


LEETCODE 82

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        // bool flag = false;
        // if(head== NULL || head -> next == NULL) return head;
        // if(head-> next -> val == head-> val) flag = true;
        
        // while(temp->next  && temp-> next->next) {
        //     if((temp -> next ->next -> val) == temp->next-> val ) {
        //         temp->next = temp-> next-> next->next;
        //     }
        //     else {
        //         temp = temp-> next;
        //     }
        // }
        // if(flag) {
        //     if(head-> val == head-> next -> val) return head-> next -> next;
        //     else return head-> next;
        // }
        unordered_map<int,int> mp;

        while(temp) {
            if(mp.find(temp-> val) != mp .end()) mp[temp->val]++;
            else mp[temp->val]=1;
            temp = temp -> next;

        }
        ListNode* dummy = new ListNode(0);
        ListNode* a = dummy;
        temp = head;
        while(temp) {
            if(mp[temp->val] == 1) {
                a-> next= temp;
                a = a-> next;
            }
            temp= temp-> next;
        }
        a-> next =NULL;
        return dummy -> next;
        
        
    }
};
