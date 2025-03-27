// LEETCODE 237
TC O(1)
SC O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next =node -> next -> next;
    }
};


// GEEKFORGEEK  LINKED LIST INSERTION AT END

TC O(N)
SC O(1)
  

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node * temp = new Node(x);
        
        if(head== NULL) return temp;
        
        Node * newhead = head;
        
        
        while(head -> next != NULL)  {
            head = head ->next;
        }
        head -> next= temp;
        // Code here
        return newhead;
    }
};
