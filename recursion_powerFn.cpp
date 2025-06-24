/*                    Implement Power Function (x^n)
You are given a double-precision number x and an integer n.
Your task is to compute x raised to the power n (i.e., x^n) and return the result.

Constraints:
-100.0 < x < 100.0
-2³¹ ≤ n ≤ 2³¹ - 1 (i.e., n fits in a 32-bit signed integer)
The result must be accurate within standard double-precision floating point limits.

Example 1
Input:
x = 2.0
n = 10
Output:
1024.0
Explanation:
2.0 ^ 10 = 1024.0
*/

#include <iostream>
#include <cmath>
using namespace std;

double myPow(double x, long long n)
{
  if (n == 0)
  {
    return 1.0;
  }

  if (n < 0)
  {
    x = 1.0 / x;
    n = -n;
  }

  if (n % 2 == 0)
  {
    double half = myPow(x, n / 2);
    return half * half;
  }
  else
  {
    return x * myPow(x, n - 1);
  }
}

int main()
{
  double x;
  int n;

  cout << "Enter the value of x and n: ";
  cin >> x >> n;

  cout << myPow(x, (long long)n) << endl;
  return 0;
}