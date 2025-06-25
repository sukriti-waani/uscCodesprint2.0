/*                Find Maximum Depth of a Binary Tree
You are given a binary tree in the form of a level-order input (where "NULL" represents a missing node).
Your task is to build the tree from this input and compute the maximum depth of the tree.
The maximum depth of a binary tree is the length of the longest path from the root node down to the farthest leaf node.

Input Format
A single line containing space-separated values representing the level-order traversal of the binary tree.
"NULL" represents a missing (null) node.
Output Format
A single integer representing the maximum depth of the tree.

Example
Input:
3 9 20 NULL NULL 15 7
Output:
3
Explanation:
The tree structure is:
      3
     / \
    9  20
       / \
      15  7
The maximum depth is 3.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<string> &nodes)
{
  if (nodes.empty() || nodes[0] == "NULL")
    return NULL;

  TreeNode *root = new TreeNode(stoi(nodes[0]));
  queue<TreeNode *> q;
  q.push(root);
  int i = 1;

  while (i < nodes.size())
  {
    TreeNode *curr = q.front();
    q.pop();

    if (nodes[i] != "NULL")
    {
      curr->left = new TreeNode(stoi(nodes[i]));
      q.push(curr->left);
    }
    i++;
    if (i >= nodes.size())
      break;

    if (nodes[i] != "NULL")
    {
      curr->right = new TreeNode(stoi(nodes[i]));
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

int maxDepth(TreeNode *root)
{
  if (!root)
    return 0;

  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return max(leftDepth, rightDepth) + 1;
}

int main()
{
  string s;
  getline(cin, s);

  istringstream iss(s);
  vector<string> nodes;
  string token;
  while (iss >> token)
  {
    nodes.push_back(token);
  }

  TreeNode *root = buildTree(nodes);

  cout << maxDepth(root) << endl;

  return 0;
}