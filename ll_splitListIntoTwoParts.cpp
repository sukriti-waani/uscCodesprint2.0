/*    Split Linked List into K Parts
You are given a singly linked list with n nodes, where each node contains an integer value. Your task is to split this linked list into k consecutive parts such that:
The length of each part is as equal as possible.
The first few parts may have one extra node if n is not divisible by k.
If there are fewer nodes than k, some parts will be empty (i.e., NULL).
Write a program to:
Create a linked list from the input integers.
Split the linked list into k parts as described.
Print each part in the format shown below.

Input Format:
First line: An integer n — the number of nodes in the linked list.
Second line: n space-separated integers — the values of the nodes.
Third line: An integer k — the number of parts to split the list into.

Output Format:
Print the k parts of the linked list.
Each part should be printed inside square brackets [] with node values separated by commas and spaces.
Separate the parts themselves by commas and spaces.

Example:
Input:
7
1 2 3 4 5 6 7
3
Output:
[1 , 2 , 3] , [4 , 5] , [6 , 7]
Explanation:
The linked list is: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
Length n = 7, parts k = 3
Each part size = 7 / 3 = 2 nodes, remainder = 1
So, first part has 3 nodes, next two parts have 2 nodes each.
*/

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node
{
  int val;
  Node *next;
  Node(int x) : val(x), next(NULL) {}
};

Node *createList(int val[], int n)
{
  if (n == 0)
    return NULL;

  Node *head = new Node(val[0]);
  Node *tail = head;
  for (int i = 1; i < n; i++)
  {
    tail->next = new Node(val[i]);
    tail = tail->next;
  }
  return head;
}

void print(Node *parts[], int k)
{
  for (int i = 0; i < k; i++)
  {
    cout << "[";
    Node *curr = parts[i];
    while (curr)
    {
      cout << curr->val;
      if (curr->next)
        cout << " , ";
      curr = curr->next;
    }
    cout << "]";
    if (i != k - 1)
      cout << " , ";
  }
  cout << endl;
}

void splitList(Node *head, int k, Node *parts[])
{
  int len = 0;
  for (Node *curr = head; curr != NULL; curr = curr->next)
    len++;

  int base = len / k;
  int rem = len % k;

  Node *curr = head;
  for (int i = 0; i < k; i++)
  {
    parts[i] = curr;
    int partsSize = base + (rem > 0 ? 1 : 0);
    if (rem > 0)
      rem--;

    for (int j = 1; j < partsSize && curr; j++)
    {
      curr = curr->next;
    }
    if (curr)
    {
      Node *nextPart = curr->next;
      curr->next = NULL;
      curr = nextPart;
    }
  }
}

int main()
{
  int n;
  cout << "Enter the number of nodes: " << endl;
  cin >> n;

  int val[1000];
  cout << "Enter elements : " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
  }

  int k;
  cout << "Enter the number of parts: " << endl;
  cin >> k;

  Node *head = createList(val, n);

  Node **parts = new Node *[k];
  for (int i = 0; i < k; i++)
    parts[i] = NULL;

  splitList(head, k, parts);
  print(parts, k);

  return 0;
}