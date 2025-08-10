/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/*class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) {
            return head;
        }
        Node* curr = head;
        while(head!= NULL) {
            if(curr->child!= NULL) {
                Node*next = curr->next;
                curr->next= flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                if(next!= NULL) {
                    curr-> next = next;
                    next -> prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};
        
        /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* curr = head;

        while (curr != NULL) {
            if (curr->child != NULL) {
                Node* nextNode = curr->next;

                // Flatten the child list
                Node* childHead = flatten(curr->child);

                // Connect curr to child
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;

                // Move curr to the tail of the child list
                Node* childTail = childHead;
                while (childTail->next != NULL) {
                    childTail = childTail->next;
                }

                // Connect tail to the original next
                if (nextNode != NULL) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
