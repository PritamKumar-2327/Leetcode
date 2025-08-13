class Solution {
public:
    // Function to remove all nodes with a specific value from a linked list.
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that serves the purpose of an anchor for the new list without the given value.
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
      
        // Initialize a pointer that will traverse the list, starting from the dummy node.
        ListNode* current = dummyNode;
      
        // Iterate through the list until the end is reached.
        while (current->next) {
            // Check if the next node's value matches the value to be removed.
            if (current->next->val == val) {
                // If a match is found, skip over the node with the matching value.
                current->next = current->next->next;
            } else {
                // Otherwise, move to the next node.
                current = current->next;
            }
        }
      
        // Return the next node of dummy as it is the new head of the modified list.
        return dummyNode->next;
    }
};