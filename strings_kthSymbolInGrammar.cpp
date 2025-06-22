/*                    Find the k-th Symbol in Grammar
Consider a special binary grammar that generates rows of symbols as follows:
Row 1: 0
For each row, generate the next row by replacing:
Every 0 with 0 1
Every 1 with 1 0

For example:
Row 1: 0
Row 2: 0 1
Row 3: 0 1 1 0
Row 4: 0 1 1 0 1 0 0 1
...
Your task is to find the symbol at position k (1-based index) in row n without constructing the entire row.

Input
An integer n (1 ≤ n ≤ 30) — the row number.
An integer k (1 ≤ k ≤ 2^(n-1)) — the position in that row (1-based index).
Output
Print the symbol at position k in row n. The symbol will be either 0 or 1.

Example
Input:
4 5
Output:
1
Explanation
The rows are:
Row 1: 0
Row 2: 0 1
Row 3: 0 1 1 0
Row 4: 0 1 1 0 1 0 0 1
The 5th symbol in row 4 is 1.
*/

#include <iostream>
using namespace std;

int findValue(int n, int k)
{
  int res = 0;

  while (k > 1)
  {
    if (k % 2 == 0)
    {
      res = 1 - res;
    }
    k = (k + 1) / 2;
  }
  return res;
}

int main()
{
  int n, k;

  cout << "Enter the value of n and k: \n";
  cin >> n >> k;
  cout << findValue(n, k) << endl;
  return 0;
}