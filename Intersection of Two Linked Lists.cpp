/*
Given two linked lists, the task is to complete the function findIntersection(), that returns the intersection of two linked lists. Each of the two linked list contains distinct node values.

Example 1:

Input:
LinkedList1: 9->6->4->2->3->8
LinkedList2: 1->2->8->6
Output: 6 2 8
Your Task:
You task is to complete the function findIntersection() which takes the heads of the 2 input linked lists as parameter and returns the head of intersection list. Returned list will be automatically printed by driver code.
Note: The order of nodes in this list should be same as the order in which those particular nodes appear in input list 1.

Constraints:
1 <= n,m <= 104

Expected time complexity: O(m+n)
Expected auxiliary space: O(m+n)
*/

/* structure of list node:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution{
  public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        unordered_map<int,int>m;
        Node *tmp=head2,*newHead=NULL,*prev=NULL;
        while(tmp)
        {
            m[tmp->data]++;
            tmp=tmp->next;
        }
        tmp=head1;
        while(tmp)
        {
            if(m.find(tmp->data)!=m.end())
            {
                Node *newNode=new Node(tmp->data);
                if(!newHead)
                {
                    newHead=newNode;
                }
                else
                {
                    prev->next=newNode;
                }
                prev=newNode;
                if(m[tmp->data]==1)
                {
                    m.erase(tmp->data);
                }
                else
                {
                    m[tmp->data]--;
                }
            }
            tmp=tmp->next;
        }
        return newHead;
    }
};
