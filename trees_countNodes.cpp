/*                    Count Nodes in a Complete Binary Tree Efficiently
You are given a binary tree represented as level-order input (where "NULL" represents a missing node).
Your task is to build the tree and compute the total number of nodes in the tree.
The binary tree is guaranteed to be a complete binary tree — that means:
All levels are fully filled except possibly the last.
The last level is filled from left to right.
Your solution should work efficiently, better than O(N) time, by leveraging the properties of a complete binary tree.

Input Format
A single line containing space-separated values representing the level-order traversal of the binary tree.
Each value is either an integer (node’s value) or "NULL" for a missing node.
Output Format
A single integer representing the total number of nodes in the tree.

Examples
Example 1
Input:
1 2 3 4 5 6
Output:
Number of nodes: 6
Explanation:
The tree structure is:
      1
     / \
    2   3
   / \  /
  4  5 6
This tree has 6 nodes.

Example 2
Input:
1 2 3 4 5
Output:
Number of nodes: 5
Explanation:
The tree structure is:
      1
     / \
    2   3
   / \
  4  5
This tree has 5 nodes.

Constraints
Number of nodes ≤ 10⁴
Node values are integers or "NULL"
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct Node
{
  int val;
  Node *left;
  Node *right;
  Node(int x) : val(x), left(NULL), right(NULL) {}
};

int getDepth(Node *node)
{
  int d = 0;
  while (node)
  {
    d++;
    node = node->left;
  }
  return d;
}

int countNodes(Node *root)
{
  if (!root)
    return 0;

  int leftD = getDepth(root->left);
  int rightD = getDepth(root->right);

  if (leftD == rightD)
  {
    return (1 << leftD) + countNodes(root->right);
  }
  else
  {
    return (1 << rightD) + countNodes(root->left);
  }
}

Node *buildTree(vector<string> &nodes)
{
  if (nodes.empty() || nodes[0] == "NULL")
    return NULL;

  Node *root = new Node(stoi(nodes[0]));
  queue<Node *> q;
  q.push(root);
  int i = 1;

  while (!q.empty() && i < nodes.size())
  {
    Node *curr = q.front();
    q.pop();

    if (nodes[i] != "NULL")
    {
      curr->left = new Node(stoi(nodes[i]));
      q.push(curr->left);
    }
    i++;
    if (i >= nodes.size())
      break;

    if (nodes[i] != "NULL")
    {
      curr->right = new Node(stoi(nodes[i]));
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

int main()
{
  cout << "Enter tree nodes in level-order: " << endl;
  string s;
  getline(cin, s);

  istringstream iss(s);
  vector<string> nodes;
  string token;
  while (iss >> token)
  {
    nodes.push_back(token);
  }

  Node *root = buildTree(nodes);
  cout << "Number of nodes: " << countNodes(root) << endl;
  return 0;
}