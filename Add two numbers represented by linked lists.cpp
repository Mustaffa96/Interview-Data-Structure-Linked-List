/*
Given two numbers represented by two linked lists of size N and M. The task is to return a sum list.

The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

Constraints:
1 <= N, M <= 5000
*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node * reverse(Node *head)
    {
        Node *p = head , *q = NULL , *r = NULL;
        while(p!=NULL)
        {
            r=p->next;
            p->next=q;
            q=p;
            p=r;
            
        }
        return q;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first =  reverse(first);
        second = reverse(second);
        Node *h1=first , *h2=second , *tail =NULL ;
        Node *head = new Node (-1) ;
        int sum = 0 , rem = 0 , carry =0 ;
        tail=head;
        while(h1!=NULL && h2!=NULL)
        {
            sum = h1->data + h2-> data + carry;
            
            if(sum > 9)
            {
                rem = sum % 10;
                carry = sum /10;
            }
            else
            {
                rem=sum;
                carry = 0;
            }
            
            if(head->data == -1)
                head -> data = rem;
                
            else
            {
                Node *temp = new Node (rem);
                tail->next = temp ;
                tail = tail -> next;
            }
            
            h1 = h1->next;
            h2 = h2->next ;
                
        }
        
        
        if(h1 == NULL)
        {
           while(h2 != NULL)
           {
                sum =  h2-> data + carry;
            
                if(sum > 9)
                {
                    rem = sum % 10;
                    carry = sum /10;
                }
                else
                {
                    rem=sum;
                    carry = 0;
                }
                
                if(head->data == -1)
                    head -> data = rem;
                    
                else
                {
                    Node *temp = new Node (rem);
                    tail->next = temp ;
                    tail = tail -> next;
                }
                
                h2 = h2->next ;
           }
            if (carry == 1)
            {
                Node *temp = new Node (carry);
                tail->next = temp ;
                tail = tail -> next;
            }
                
        }
            
        else
        {
            while(h1 != NULL)
           {
                sum =  h1-> data + carry;
            
                if(sum > 9)
                {
                    rem = sum % 10;
                    carry = sum /10;
                }
                else
                {
                    rem=sum;
                    carry = 0;
                }
                
                if(head->data == -1)
                    head -> data = rem;
                    
                else
                {
                    Node *temp = new Node (rem);
                    tail->next = temp ;
                    tail = tail -> next;
                }
                
                h1 = h1->next ;
           }
            if (carry == 1)
            {
                Node *temp = new Node (carry);
                tail->next = temp ;
                tail = tail -> next;
            }
        }
           
            
        head = reverse(head);
        return head;
        
    }
