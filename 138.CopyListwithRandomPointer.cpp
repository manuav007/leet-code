/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* temp = new Node(data);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        Node* original = head;
        Node* clone = cloneHead;
        while (original != NULL && clone != NULL) {
            Node* nextOriginal = original->next;
            Node* nextClone = clone->next;

            original->next = clone;
            clone->next = nextOriginal;

            original = nextOriginal;
            clone = nextClone;
        }
        original = head;
        while (original != NULL) {
            if (original->next != NULL) {
                original->next->random = (original->random != NULL) ? original->random->next : NULL;
            }
            original = original->next->next;
        }
        original = head;
        clone = cloneHead;
        while (original != NULL && clone != NULL) {
            original->next = clone->next;
            original = original->next;

            if (original != NULL) {
                clone->next = original->next;
            }
            clone = clone->next;
        }

        return cloneHead;
    }
};
