/*              Check if a Number is a Power of Two
Write a recursive function that determines whether a given integer n is a power of two.
The function should return true if n is a power of two.
The function should return false otherwise.
The function should handle edge cases such as 0 or negative numbers by returning false.
A number is said to be a power of two if it can be expressed as 2^k where k is a non-negative integer (e.g. 1, 2, 4, 8, 16, ...).
Constraints
-10^9 <= n <= 10^9

Example 1
Input:
n = 8
Output:
true
Explanation:
8 = 2^3 → It is a power of two.

Example 2
Input:
n = 10
Output:
false
Explanation:
10 is not a power of two.
*/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
  if (n == 1)
  {
    return true;
  }

  if (n < 1 || n % 2 != 0)
  {
    return false;
  }

  return isPowerOfTwo(n / 2);
}

int main()
{
  int n;
  cout << "Enter an integer: ";
  cin >> n;

  bool res = isPowerOfTwo(n);
  cout << (res ? "true" : "false");

  return 0;
}