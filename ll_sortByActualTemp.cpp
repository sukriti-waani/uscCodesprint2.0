/*    Sort Linked List by Actual Temperature Values
You are given a singly linked list of integers representing actual temperature readings taken throughout a day. The list contains both negative and non-negative values.
Task:
Rearrange the linked list such that:
All the negative temperature readings appear first in reverse order of their original appearance.
Followed by all the non-negative temperature readings in their original order.
Return the head of the rearranged linked list.

Example:
Input:
Linked list:
-3 -> 5 -> -2 -> 0 -> 7 -> -1

Step-by-step rearrangement:
Extract negative numbers: -3, -2, -1
Reverse negatives: -1 -> -2 -> -3
Extract non-negative numbers: 5, 0, 7 (keep order)
Non-negatives remain: 5 -> 0 -> 7
Concatenate reversed negatives + non-negatives:
-1 -> -2 -> -3 -> 5 -> 0 -> 7

Output:
Rearranged linked list:
-1 -> -2 -> -3 -> 5 -> 0 -> 7

Explanation:
Negative nodes are collected and reversed during insertion.
Non-negative nodes are collected in original order.
Finally, reversed negatives and non-negatives are joined.
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

Node *sortListByActualTemp(Node *head)
{
  if (!head || !head->next)
    return head;

  Node negDummy(0), posDummy(0);
  Node *neg = NULL, *pos = &posDummy;

  Node *curr = head;

  while (curr)
  {
    Node *nextNode = curr->next;
    curr->next = NULL;
    if (curr->data < 0)
    {
      curr->next = neg;
      neg = curr;
    }
    else
    {
      pos->next = curr;
      pos = curr;
    }
    curr = nextNode;
  }

  if (!neg)
    return posDummy.next;

  Node *tailNeg = neg;
  while (tailNeg->next)
  {
    tailNeg = tailNeg->next;
  }
  tailNeg->next = posDummy.next;
  return neg;
}

Node *createList(int n)
{
  if (n <= 0)
    return NULL;

  int val;
  cout << "Enter value for node 1: " << endl;
  cin >> val;
  Node *head = new Node(val);
  Node *curr = head;

  cout << "Enter value for node: " << endl;
  for (int i = 2; i <= n; i++)
  {
    cin >> val;
    curr->next = new Node(val);
    curr = curr->next;
  }
  return head;
}

void printList(Node *head)
{
  while (head)
  {
    cout << head->data;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter number of nodes: " << endl;
  cin >> n;

  Node *head = createList(n);

  head = sortListByActualTemp(head);
  cout << "Sorted List by Actual Temperature: " << endl;
  printList(head);

  return 0;
}