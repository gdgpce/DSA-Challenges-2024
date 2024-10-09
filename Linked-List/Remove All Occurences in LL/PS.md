#### Problem: You're given the head of a linked list and a specific integer value val. The task is to remove every node in the linked list that contains the valuevaland return the updated list's head.

<b>Example 1:</b>

<b>Input:</b>
head = [1, 2, 6, 3, 4, 5, 6], val = 6

<b>Explanation:</b>
All nodes with the value 6 are removed, so the final linked list is [1, 2, 3, 4, 5].

You will receive a linked list represented by its head node and an integer value val to remove from the list. The Structure of the Linked list is :
```C++
class Node{
public:
    int val;
    Node* next;

    Node(int s){
        val = s;
        next = NULL;
    }
};
Return the head of the modified linked list, where all nodes with the value val have been removed. If the list becomes empty, return an empty list.
```
