/*                  Evaluate a Fraction Expression
Problem Statement:
You are given a mathematical expression consisting of fractions (in the form a/b) connected by + and - operators. Your task is to:
Parse the expression.
Perform arithmetic operations (addition and subtraction).
Return the result as a reduced fraction (p/q), where p and q are coprime integers and q > 0.

Input:
A single string containing the expression with one or more fractions.
Each fraction is of the form numerator/denominator.
The numerator and denominator are integers (can be negative or positive, except denominator ≠ 0).
The expression contains only + or - as operators between fractions.
The expression is well-formed, i.e., no invalid characters or malformed fractions.
Output:
A single reduced fraction representing the final result of the expression.
Constraints:
Each numerator and denominator fits within a 64-bit signed integer.
Denominators are non-zero.
Up to 100 fractions in the expression.

Examples:
Example 1:
Edit
Input:
-1/2+1/3+1/4
Output:
-1/12
Explanation:
-1/2 + 1/3 = -1/6
-1/6 + 1/4 = -1/12
Example 2:
Input:
1/2-3/4+5/6
Output:
5/12
Explanation:
1/2 - 3/4 = -1/4
-1/4 + 5/6 = 5/12
*/

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

pair<long long, long long> parseFrac(const string &f)
{
  int slash = f.find('/');
  long long n = stoll(f.substr(0, slash));
  long long den = stoll(f.substr(slash + 1));
  return {n, den};
}

long long lcm(long long a, long long b)
{
  return abs(a * b) / gcd(a, b);
}

pair<long long, long long> evaluate(string &ex)
{
  long long n = 0, den = 1;
  size_t i = 0;

  while (i < ex.size())
  {
    int sign = 1;
    if (ex[i] == '+' || ex[i] == '-')
    {
      if (ex[i] == '-')
        sign = -1;
      i++;
    }
    size_t start = i;
    while (i < ex.size() && ex[i] != '+' && ex[i] != '-')
    {
      i++;
    }

    auto [currNum, currDen] = parseFrac(ex.substr(start, i - start));
    currNum *= sign;

    long long comDen = lcm(den, currDen);
    n = n * (comDen / den) + currNum * (comDen / currDen);
    den = comDen;

    long long g = gcd(abs(n), den);
    n /= g;
    den /= g;
  }

  if (den < 0)
  {
    n = -n;
    den = -den;
  }
  return {n, den};
}

int main()
{
  string s;
  cout << "Enter a fraction expression: ";
  getline(cin, s);

  auto [resNum, resDen] = evaluate(s);
  cout << "Result: " << resNum << "/" << resDen << endl;

  return 0;
}