/*    Merge Two Sorted Linked Lists
You are given two sorted singly linked lists. Your task is to merge them into a single sorted linked list that includes duplicate values (i.e., do not remove duplicates).
You must take input for both linked lists from the user and print the merged sorted linked list.

Input Format:
First line: An integer n1 — number of elements in the first sorted linked list.
Second line: n1 space-separated integers — the elements of the first list in increasing order.
Third line: An integer n2 — number of elements in the second sorted linked list.
Fourth line: n2 space-separated integers — the elements of the second list in increasing order.
Output Format:
A single line containing the merged sorted linked list (space-separated integers).

Sample Input :
3
1 2 4
3
1 3 4
Sample Output :
1 1 2 3 4 4
*/

#include <iostream>
using namespace std;

struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

void insertNode(Node *&head, int val)
{
  Node *newNode = new Node(val);
  if (!head)
  {
    head = newNode;
    return;
  }
  Node *temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void print(Node *head)
{
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

Node *mergeTwoLists(Node *l1, Node *l2)
{
  Node dummy(0);
  Node *curr = &dummy;

  while (l1 && l2)
  {
    if (l1->val <= l2->val)
    {
      curr->next = l1;
      l1 = l1->next;
    }
    else
    {
      curr->next = l2;
      l2 = l2->next;
    }
    curr = curr->next;
  }

  curr->next = (l1) ? l1 : l2;

  return dummy.next;
}

int main()
{
  Node *l1 = NULL, *l2 = NULL;
  int n1, n2, val;

  cout << "Enter number of elements in first sorted list: " << endl;
  cin >> n1;
  cout << "Enter elements in sorted order: \n";
  for (int i = 0; i < n1; i++)
  {
    cin >> val;
    insertNode(l1, val);
  }

  cout << "Enter number of elements in second sorted list: " << endl;
  cin >> n2;
  cout << "Enter elements in sorted order: \n";
  for (int i = 0; i < n2; i++)
  {
    cin >> val;
    insertNode(l2, val);
  }

  Node *ml = mergeTwoLists(l1, l2);
  print(ml);
  return 0;
}