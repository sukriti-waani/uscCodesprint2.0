/*                Convert Sorted Array to Height-Balanced BST and Print Level Order
You are given a sorted array of integers (in ascending order).
Your task is to:
Build a height-balanced binary search tree (BST) from this array.
Print the level-order traversal of the BST (also known as breadth-first traversal).
If a node is missing at a level, print "NULL" at that position.
Remove any trailing "NULL" values from the output for a cleaner display.
A height-balanced BST is defined as a BST where the depth of the two subtrees of every node never differs by more than 1.

Input Format
A single line containing space-separated integers — the sorted array.
Output Format
A single line containing the level-order traversal of the BST.
Each node value or "NULL" is printed, separated by spaces.

Example
Example 1
Input:
2 4 6
Output:
4 2 6
Explanation:
The height-balanced BST is:
    4
   / \
  2   6
Level-order traversal: 4 2 6

Example 2
Input:
1 3 5 7 9
Output:
5 1 7 NULL 3 NULL 9
Explanation:
The height-balanced BST is:
      5
     / \
    1   7
     \    \
      3    9
Level-order traversal: 5 1 7 NULL 3 NULL 9

Constraints
1 ≤ number of elements ≤ 10⁴
The array is sorted in ascending order.
*/

#include <iostream>
#include <vector>
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

Node *sortedArrayToBST(vector<int> &nums, int left, int right)
{
  if (left > right)
    return NULL;
  int mid = left + (right - left) / 2;
  Node *root = new Node(nums[mid]);
  root->left = sortedArrayToBST(nums, left, mid - 1);
  root->right = sortedArrayToBST(nums, mid + 1, right);
  return root;
}

vector<string> levelOrder(Node *root)
{
  vector<string> res;
  if (!root)
    return res;

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    Node *node = q.front();
    q.pop();
    if (node)
    {
      res.push_back(to_string(node->val));
      q.push(node->left);
      q.push(node->right);
    }
    else
    {
      res.push_back("NULL");
    }
  }

  while (!res.empty() && res.back() == "NULL")
  {
    res.pop_back();
  }
  return res;
}

int main()
{
  cout << "Enter sorted integers: \n";
  string s;
  getline(cin, s);

  istringstream iss(s);
  vector<int> nums;
  int x;
  while (iss >> x)
  {
    nums.push_back(x);
  }

  Node *root = sortedArrayToBST(nums, 0, nums.size() - 1);
  vector<string> output = levelOrder(root);

  cout << "Level order of BST: \n";
  for (string &val : output)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}