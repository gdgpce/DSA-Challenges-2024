### Brute Force Approach
1. Traverse the entire linked list to identify nodes with target value.
2. For each node with a matching value, traverse again from the start to remove the node.
3. Repeat until all nodes with the target value are removed.

### Optimal Approach
1. Create a temp node to handle head node removals.
2. Use a single traversal to check each node.
3. Skip over nodes that match the target value by updating the prev->next pointer.

### Solution:
```C++
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

Node* removeElements(Node* head, int val) {
    Node* temp = new Node(0); 
    temp->next = head; 
    Node* current = head;
    Node* prev = temp;

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
        } else {
            prev = current;
        }
        current = current->next;
    }

    Node* newHead = temp->next;
    delete temp;
    return newHead;
}

Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val;
        if (current->next != NULL) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, val;
    cout << "Enter the number of elements in the list: ";
    cin >> n;
    if (n <= 0) {
        cout << "The list should have at least one element." << endl;
        return 0;
    }
    int arr[n];
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value to remove from the list: ";
    cin >> val;
    
    Node* head = createLinkedList(arr, n);
    cout << "Original List: ";
    printLinkedList(head);

    head = removeElements(head, val);
    cout << "Updated List: ";
    printLinkedList(head);

    return 0;
}
```
<b>Time Complexity</b><br>
O(n) because entire entire linked list is traversed only once checking the targte value (val).
