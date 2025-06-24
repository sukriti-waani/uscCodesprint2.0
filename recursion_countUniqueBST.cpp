/*                       Count Number of Unique Binary Search Trees
You are given an integer n representing the number of distinct nodes labeled from 1 to n.
Your task is to compute how many structurally unique Binary Search Trees (BSTs) can be formed using all these nodes.

The number of unique BSTs that can be formed with n nodes is given by the n-th Catalan number:
Number of BSTs = (1/ n + 1) * (2n C n)
where 2n C n is the binomial coefficient : "2n choose n".

Examples
Example 1
Input:
n = 3
Output:
5
Explanation:
There are 5 unique BSTs that can be formed with 3 nodes:
  1         3     3      2      1
   \       /     /      / \      \
    2     2     1      1   3      3
     \   /       \
      3 1         2
Example 2
Input:
n = 1
Output:
1
Explanation:
Only one BST can be formed when there is just one node.

Example 3
Input:
n = 4
Output:
14
Explanation:
14 unique BSTs can be formed with 4 nodes.

Constraints
0 <= n <= 30 (for safe unsigned long long results; for larger n, big integers are needed)
*/

#include <iostream>
#include <vector>
using namespace std;

unsigned long long binomial(int n, int r)
{
  unsigned long long res = 1;

  if (r > n - r)
    r = n - r;

  for (int i = 0; i < r; i++)
  {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

unsigned long long numTrees(int n)
{
  unsigned long long c = binomial(2 * n, n);

  return c / (n + 1);
}

int main()
{
  int n;
  cout << "Enter the number of nodes: ";
  cin >> n;
  cout << "Number of unique BSTs: " << numTrees(n) << endl;
  return 0;
}