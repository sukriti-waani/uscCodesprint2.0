/*      Remove Target from Doubly Linked List
Write a C++ program to:
Create a doubly linked list from user input.
Remove all nodes whose values match a given target value.
Print the final linked list after deletions.

Input Format:
First line: An integer n, the number of elements in the list.
Second line: n space-separated integers (the elements of the list).
Third line: An integer target, the value to be removed from the list.
Output Format:
A single line containing space-separated integers of the modified list after all occurrences of target are removed.
If the list becomes empty, output nothing.

Example:
Input:
6
4 2 5 2 7 2
2
Output:
4 5 7
*/

#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *prev;
  Node *next;
  Node(int x) : val(x), prev(NULL), next(NULL) {}
};

Node *insert(Node *head, int x)
{
  Node *n = new Node(x);
  if (!head)
    return n;
  Node *temp = head;
  while (temp->next)
    temp = temp->next;
  temp->next = n;
  n->prev = temp;
  return head;
}

void print(Node *head)
{
  Node *temp = head;
  while (temp)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *removeTarget(Node *head, int target)
{
  Node *curr = head;
  while (curr)
  {
    if (curr->val == target)
    {
      Node *del = curr;
      Node *p = curr->prev;
      Node *n = curr->next;

      if (p)
        p->next = n;
      else
        head = n;

      if (n)
        n->prev = p;
      curr = n;
      delete del;
    }
    else
    {
      curr = curr->next;
    }
  }
  return head;
}

int main()
{
  Node *head = NULL;
  int n, x, target;

  cout << "Enter the number of elements: " << endl;
  cin >> n;

  cout << "Enter the elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    head = insert(head, x);
  }

  cout << "Enter target to remove: " << endl;
  cin >> target;

  head = removeTarget(head, target);
  print(head);

  return 0;
}