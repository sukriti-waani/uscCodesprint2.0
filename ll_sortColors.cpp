/*    Aarav and the Package Color Sorting
You are given a singly linked list where each node contains an integer value that is either 0, 1, or 2. Your task is to sort the linked list such that all 0s appear first, followed by all 1s, and then all 2s.
You are not allowed to use arrays or count sort logic. Instead, you should rearrange the nodes themselves (not just the data inside them) using constant extra space.
🔍 Example:
Input:
Enter number of nodes: 7
Enter value for node 1 (0, 1 or 2): 1
Enter value for node 2 (0, 1 or 2): 2
Enter value for node 3 (0, 1 or 2): 0
Enter value for node 4 (0, 1 or 2): 1
Enter value for node 5 (0, 1 or 2): 0
Enter value for node 6 (0, 1 or 2): 2
Enter value for node 7 (0, 1 or 2): 1
Output:
rust
Copy
Edit
Sorted List:
0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2
Explanation:
Original list: 1 → 2 → 0 → 1 → 0 → 2 → 1
After sorting by grouping: all 0s (0 → 0), then 1s (1 → 1 → 1), then 2s (2 → 2)
Final result: 0 → 0 → 1 → 1 → 1 → 2 → 2
*/

#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(NULL) {}
};

Node *sortColors(Node *head)
{
  if (!head || !head->next)
    return head;

  Node *zeroNode = new Node(0), *oneNode = new Node(0), *twoNode = new Node(0);
  Node *zero = zeroNode, *one = oneNode, *two = twoNode;

  Node *curr = head;
  while (curr != NULL)
  {
    if (curr->data == 0)
    {
      zero->next = curr;
      zero = zero->next;
    }
    else if (curr->data == 1)
    {
      one->next = curr;
      one = one->next;
    }
    else
    {
      two->next = curr;
      two = two->next;
    }
    curr = curr->next;
  }

  zero->next = oneNode->next ? oneNode->next : twoNode->next;
  one->next = twoNode->next;
  two->next = NULL;

  head = zeroNode->next;

  delete zeroNode;
  delete oneNode;
  delete twoNode;

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

Node *createList(int n)
{
  if (n <= 0)
    return NULL;

  int val;
  cout << "Enter value for node 1(0, 1 or 2): ";
  cin >> val;
  Node *head = new Node(val);
  Node *curr = head;

  cout << "Enter value for node: ";
  for (int i = 2; i <= n; i++)
  {
    cin >> val;
    curr->next = new Node(val);
    curr = curr->next;
  }
  return head;
}

int main()
{
  int n;
  cout << "Enter number of nodes: ";
  cin >> n;

  Node *head = createList(n);

  head = sortColors(head);
  cout << "Sorted List: " << endl;
  printList(head);

  return 0;
}