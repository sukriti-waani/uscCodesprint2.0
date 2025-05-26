/*    Cycle Detection and Removal in Delivery Tracking System
You are given a singly linked list that may contain a loop. Your task is to:
Detect whether a loop exists.
If a loop exists, remove it without losing any nodes.
Return true if a loop was present and removed, otherwise false.
Finally, print the list after loop removal.

🔢 Example:
Input:
Number of nodes: 6
Node values: 1 2 3 4 5 6
Loop position: 3
This means the next pointer of node 6 should point to node 3, creating a cycle:

1 → 2 → 3 → 4 → 5 → 6
              ↑     ↓
              ←←←←←←←
Expected Output:
true
1 2 3 4 5 6

*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

bool detectAndRemoveLoop(Node *head)
{
  if (head == NULL || head->next == NULL)
    return false;

  Node *slow = head, *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      break;
    }
  }

  if (slow != fast)
    return false;
  slow = head;

  if (slow == fast)
  {
    while (fast->next != slow)
      fast = fast->next;
    fast->next = NULL;
  }
  else
  {
    while (slow->next != fast->next)
    {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
  return true;
}

void printList(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  int n, pos;
  cout << "Enter the number of nodes: " << endl;
  cin >> n;

  if (n <= 0)
  {
    cout << "true \n";
    return 0;
  }

  Node *head = NULL, *tail = NULL;

  cout << "Enter node values: " << endl;
  for (int i = 1; i <= n; i++)
  {
    int val;
    cin >> val;
    Node *newNode = new Node(val);
    if (!head)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
  }
  cout << "Enter position: ";
  cin >> pos;

  if (pos > 0)
  {
    Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
    {
      temp = temp->next;
    }
    if (temp != NULL)
    {
      tail->next = temp;
    }
  }

  bool res = detectAndRemoveLoop(head);
  cout << (res ? "true" : "false") << endl;
  printList(head);
  return 0;
}