GEEKFORGEEK  -> Doubly linked list Insertion at given position
TC O(N)
  SC O(1)


class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int p, int data) {
        Node* temp= new Node(data);
        if(head==NULL) return temp;
        int x=0;
        Node* newhead= head;
        while(x<p && head != NULL) {
            x++;
            head = head ->next;
        }
        temp -> next = head -> next ;
        head -> next = temp;
        if(temp -> next != NULL) temp -> next -> prev = temp;
        temp -> prev = head;
        return newhead;
        
        
        
        
    }
};



GEEKFORGEEK -> SEARCH IN A LINKED LIST
TC O(N)
SC O(1)

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> data == key) return true;
            temp = temp -> next;
        }
        return false;
        
    }
};
