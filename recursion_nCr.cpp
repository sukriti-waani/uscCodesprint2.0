/*       Compute nCr using recursion
Write a C++ program that computes the value of n choose r (nCr) using recursion.
The formula for nCr is:
nCr = n! / (r! * (n-r)!)
or recursively:
      nCr = (n-1)C(r-1) + (n-1)C(r)
with base cases:abortnCr = 1       if r = 0 or r = n

If r > n, the program should output 0.
If n or r is negative, the program should display an error message.

Example 1
Enter n and r:
5 2
10
Explanation: 5C2 = 10

Example 2
Enter n and r:
6 6
1
Explanation: 6C6 = 1
*/

#include <iostream>
using namespace std;

long long nCr(int n, int r)
{
  if (r == 0 || r == n)
    return 1;

  return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int main()
{
  int n, r;
  cout << "Enter n and r: " << endl;
  cin >> n >> r;

  cout << nCr(n, r) << endl;

  return 0;
}