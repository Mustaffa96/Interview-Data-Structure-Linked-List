/*
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in decreasing order.

Input:
First line of input contains number of testcases T. For each testcase, first line of input conatains length of both linked lists N and M respectively. Next two lines contains N and M elements of two linked lists.

Output:
For each testcase, print the merged linked list which is in non-increasing order.

User Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Constraints:
1 <=T<= 50
1 <= N, M <= 1000

Example:
Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4

Output:
40 20 15 10 5 3 2
4 2 1 1 

Explanation:
Testcase 1: After merging the two lists in decreasing order, we have new lists as 40->20->15->10->5->3->2.
*/

struct Node * mergeResult(Node *node1,Node *node2)
{
  if(node1==NULL) return node2;
  if(node2==NULL) return node1;
  
  Node *tail=NULL,*head=NULL;
  if(node1->data<=node2->data)
  {
      tail=head=node1;
      node1=node1->next;
  }else{
      tail=head=node2;
      node2=node2->next;
  }
  while(node1!=NULL&&node2!=NULL)
  {
      if(node1->data<=node2->data)
      {
          tail->next=node1;
          tail=node1;
          node1=node1->next;
      }else{
          tail->next=node2;
          tail=node2;
          node2=node2->next;
      }
  }
  if(node1==NULL) tail->next=node2;
  if(node2==NULL) tail->next=node1;
  Node *temp=head;
  stack<int>s;
  while(temp!=NULL)
  {
      s.push(temp->data);
      temp=temp->next;
  }
  temp=head;
  while(temp!=NULL)
  {
      temp->data=s.top();
      s.pop();
      temp=temp->next;
  }
  return head;
}
