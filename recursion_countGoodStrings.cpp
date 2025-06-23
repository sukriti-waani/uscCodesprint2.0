/*                  Count Number of Good Strings
You are given an integer n, representing the length of a string.
A string is called good if:
At even indices (0-based), you can choose from 5 different characters.
At odd indices (0-based), you can choose from 4 different characters.
Your task is to compute the total number of good strings of length n.

Input
A single integer n (1 <= n <= 20), the length of the string.
Output
A single integer representing the number of good strings of length n.

Example 1
Input:
2
Output:
20
Explanation:
Index 0 (even): 5 choices
Index 1 (odd): 4 choices
Total = 5 * 4 = 20
*/

#include <iostream>
using namespace std;

int countGoodStrings(int n, int idx)
{
  if (idx == n)
  {
    return 1;
  }

  if (idx % 2 == 0)
  {
    return 5 * countGoodStrings(n, idx + 1);
  }
  else
  {
    return 4 * countGoodStrings(n, idx + 1);
  }
}

int main()
{
  int n;
  cout << "Enter the length of the string: ";
  cin >> n;

  int res = countGoodStrings(n, 0);
  cout << "Number of good strings: " << res << endl;

  return 0;
}