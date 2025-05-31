/*    Reverse a Segment of a Linked List of Strings
You are given a singly linked list of n strings. Your task is to reverse the nodes of the linked list from position left to position right (1-indexed), and then print the resulting linked list.

Input Format:
The first line contains an integer n, the number of items in the linked list.
The second line contains n space-separated strings representing the values of the nodes in the linked list in order.
The third line contains two integers left and right, representing the positions in the linked list to reverse between.
Output Format:
Print the linked list after reversing the nodes from position left to right. The node values should be separated by -> arrows.

Constraints:
1 ≤ n ≤ 1000
1 ≤ left ≤ right ≤ n
Each string consists of lowercase letters only.

Sample Input:
5
milk eggs bread butter cheese
2 4
Sample Output:
milk -> butter -> bread -> eggs -> cheese
Explanation:
The segment from position 2 to 4 is reversed. Originally it was eggs -> bread -> butter, after reversing it becomes butter -> bread -> eggs.
*/

#include <iostream>
using namespace std;

struct Node
{
  string val;
  Node *next;
  Node(string x) : val(x), next(NULL) {}
};

Node *reversePos(Node *head, int left, int right)
{
  if (!head || left == right)
    return head;

  Node *dummy = new Node("");
  dummy->next = head;
  Node *prev = dummy;

  for (int i = 1; i < left; i++)
  {
    prev = prev->next;
  }

  Node *curr = prev->next;

  for (int i = 0; i < right - left; i++)
  {
    Node *temp = curr->next;
    curr->next = temp->next;
    temp->next = prev->next;
    prev->next = temp;
  }

  head = dummy->next;
  delete dummy;
  return head;
}

void insertNode(Node *&head, string val)
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
  for (Node *temp = head; temp != NULL; temp = temp->next)
  {
    cout << temp->val;
    if (temp->next)
      cout << " -> ";
  }
  cout << endl;
}

int main()
{
  Node *head = NULL;
  int n;
  cout << "Enter number of items: " << endl;
  cin >> n;

  cout << "Enter items: \n";
  for (int i = 0; i < n; i++)
  {
    string val;
    cin >> val;
    insertNode(head, val);
  }

  int left, right;
  cout << "Enter positions to reverse from: " << endl;
  cin >> left >> right;

  head = reversePos(head, left, right);

  print(head);
  return 0;
}