/*                     Check if a Binary Tree is Symmetric
You are given a binary tree represented as a level-order input (where "NULL" represents a missing node).
Your task is to build the binary tree and determine whether it is symmetric.
A binary tree is called symmetric if it is a mirror of itself around its center.
That means the left subtree is a mirror reflection of the right subtree.

Input Format
A single line containing space-separated values representing the level-order traversal of the binary tree.
"NULL" represents a missing (null) node.
Output Format
Output "true" if the tree is symmetric, otherwise "false".

Example
Input:
1 2 2 3 4 4 3
Output:
true
Explanation:
The tree is:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
This tree is symmetric.
*/

#include <iostream>
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
  queue<TreeNode *> q;
  TreeNode *root = new TreeNode(stoi(nodes[0]));
  q.push(root);

  int i = 1;
  while (!q.empty() && i < nodes.size())
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

bool isMirror(TreeNode *t1, TreeNode *t2)
{
  if (!t1 && !t2)
    return true;
  if (!t1 || !t2)
    return false;
  return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(TreeNode *root)
{
  if (!root)
    return true;
  return isMirror(root->left, root->right);
}

int main()
{
  string s;
  getline(cin, s);
  vector<string> nodes;
  string temp;
  for (char c : s)
  {
    if (c == ' ')
    {
      if (!temp.empty())
      {
        nodes.push_back(temp);
        temp.clear();
      }
    }
    else
    {
      temp += c;
    }
  }

  if (!temp.empty())
    nodes.push_back(temp);

  TreeNode *root = buildTree(nodes);
  cout << (isSymmetric(root) ? "true" : "false") << endl;
  return 0;
}