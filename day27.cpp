// GFG -> DELETE IN A DOUBLY LINKED LIST
SC O(1)
TC O(N)

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        
        if(head== NULL) return head;
        
        if(x==1) {
            head= head -> next;
            if(head != NULL) head-> prev = NULL;
            
            return head;
        }
        int y= 1;
        Node * temp = head;
        while(y<x-1 && temp != NULL) {
            temp = temp-> next;
            y++;
        }
        
        if (temp == NULL || temp->next == NULL) return head;
        
        
        temp -> next = temp -> next -> next;
        //  AB TEMP UPDATE HO GEYA HAI ALREADY SO DIRECT CHECK TEMP -> NEXT, NOT TEMP -> NEXT -> NEXT
        if(temp -> next != NULL) temp -> next -> prev = temp;
        return head;
        
    }
};




// GFG -> Reverse a Doubly Linked List
SC O(1)
TC O(N)




class Solution {
  public:
    
    DLLNode* reverseDLL(DLLNode* head) {
        if(head == NULL) return head;
        DLLNode* temp = head;
       
        while(temp  != NULL) {
            // DLLNode * ptr = temp -> next;
            // temp -> next = temp -> prev;
            // temp -> prev = ptr;
            
            swap(temp -> next, temp -> prev);
            head = temp;  // head ko sath ke satha age leja rahe hai taaki in end direct head hi vapis krde
            temp = temp -> prev;
            
            ///   After swapping, temp->prev is actually the next node in the original list
        }
        
        
        return head;  
    }
};
