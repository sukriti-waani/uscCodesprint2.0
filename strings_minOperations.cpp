/*           Minimum Operations to Make All 0's Before 1's
You are given a binary string (a string that contains only characters '0' and '1') of length N.
Your task is to rearrange the string so that all 0s appear before all 1s.
You are allowed to perform operations where, in one operation, you can change a 0 to a 1 or a 1 to a 0.
Determine the minimum number of operations required to make the string valid such that no 1 appears before a 0.

Input Format:
Line 1: An integer N — the length of the string
Line 2: A binary string S of length N
Output Format:
A single integer — the minimum number of operations required
Constraints:
1 ≤ N ≤ 10^5
String S consists only of characters '0' and '1'

Example:
Input:
Enter input length: 6
Enter string: 110100
Output:
2

Explanation:
To make all 0s before all 1s:
One possible transformation: 000111 → Requires 2 operations:
Change 1st '1' to '0'
Change 3rd '1' to '0'
Other transformations may work, but the minimum operations required is 2.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int op(string &s)
{
  int n = s.length();

  int cnt = count(s.begin(), s.end(), '1');
  int prefixOnes = 0, minOp = 0;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      prefixOnes++;
    }

    int mis1 = prefixOnes;
    int mis0 = (n - i - 1) - (cnt - prefixOnes);
    int currOp = max(mis1, mis0);
    minOp = max(minOp, currOp);
  }
  return minOp;
}

int main()
{
  int n;
  string s;
  cout << "Enter input length: ";
  cin >> n;

  cout << "Enter string: \n";
  cin >> s;

  cout << op(s) << endl;
  return 0;
}