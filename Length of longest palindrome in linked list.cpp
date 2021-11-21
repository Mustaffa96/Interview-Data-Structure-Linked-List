/*
Given a linked list, the task is to complete the function maxPalindrome() which returns an integer denoting  the length of the longest palindrome list that exist in the given linked list.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the size of the linked list . Then in the next line are N space separated values of the given linked list.

Output:
For each test case output will be the required max length of the palindrome present in the given linked list.

User Task:
The task is to complete the function maxPalindrome() which should count the length of longest palindrome in the given list and return it.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
7
2 3 7 3 2 12 24
5
12 4 4 3 14

Output:
5
2

Explanation:
Testcase 1: 2 -> 3 -> 7 -> 3 -> 2 is the linked list whose nodes leads to a palindrome as 2 3 7 3 2.
*/

int max(int a, int b){
    return(a>b?a:b);
}
int countpalindrome(Node *a,Node *b){
    int c=0;
    for(;a&&b;a=a->next,b=b->next){
        if(a->data==b->data)
            c++;
    else break;        
    }
    return c;
}
/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    Node *prev=NULL;
    int res=0;
    while(head){
       Node *nxt=head->next;
        head->next=prev;
        res=max(res,2*countpalindrome(prev,nxt)+1);
        res=max(res,2*countpalindrome(head,nxt));
        prev=head;
        head=nxt;
    }
    return res;
}
