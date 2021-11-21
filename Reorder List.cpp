/*
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.

Example 1:

Input:
LinkedList: 1->2->3
Output: 1 3 2
Example 2:

Input:
LinkedList: 1->7->3->4
Output: 1 4 7 3.
Your Task:
The task is to complete the function reorderList() which should reorder the list as required. The reorder list is automatically printed by the driver's code.

Note: Try to solve without using any auxilliary space.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 104
*/

#include<bits/stdc++.h>
Node* reverse(Node* head){
    Node* current = head;
    Node* prev = NULL, *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    return prev;
}

void reorderList(Node* head) {
   Node* fast = head->next;
    Node* slow = head;
    
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
          Node* head1 = head;
          Node* head2 = slow->next;
          slow->next = NULL;
    
    head2 = reverse(head2);
    
    Node* newH = new Node(0);
          while(head1 || head2){
              if(head1){
                  newH->next = head1;
                  head1 = head1->next;
                  newH = newH->next;
              }
              if(head2){
                  newH->next = head2;
                  head2 = head2->next;
                  newH = newH->next;
              }
          }
         head = newH->next;
}
