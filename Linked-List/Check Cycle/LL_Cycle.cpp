#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int s) {
        val = s;
        next = NULL;
    }
};

// Function to detect a cycle in the linked list
bool hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    Node* slow = head;        // Tortoise
    Node* fast = head->next;  // Rabbit

    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;  // Reached the end, no cycle
        }
        slow = slow->next;         // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps
    }

    return true;  // Cycle detected
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next;
    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list!" << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);
    if (hasCycle(head1)) {
        cout << "Cycle detected in the linked list!" << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
