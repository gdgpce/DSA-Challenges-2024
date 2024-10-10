from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def odd_even_list(head: Optional[ListNode]) -> Optional[ListNode]:
    # If the list is empty or has only one node, return the head as it is
    if not head or not head.next:
        return head

    # Initialize pointers for odd and even nodes
    odd = head
    even = head.next
    even_head = even  # Store the head of the even list to attach later

    # Rearrange the odd and even nodes
    while even and even.next:
        odd.next = even.next  # Link the next odd node
        odd = odd.next        # Move to the next odd node
        even.next = odd.next  # Link the next even node
        even = even.next      # Move to the next even node

    # After all odd nodes are linked, attach the even list to the end
    odd.next = even_head
    return head
