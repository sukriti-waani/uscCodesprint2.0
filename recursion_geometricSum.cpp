/*              Geometric Sum
Write a C++ program to compute the sum of the first n terms of a geometric progression (G.P.) where:
The first term a = 1
The common ratio r = 1/3
The number of terms n is provided by the user
Use a user-defined function geometricSum(a, r, n) that returns the sum using the formula:

Sn = a ((1−r^n) / (1 - r)) ,       if r != 1

𝑆𝑛 = 𝑎 × 𝑛,       if  𝑟 = 1

Output the sum rounded to 5 decimal places.

Example
Input:
Enter number of terms (n): 4
Output:
Sum = 1.48148
Explanation:
The series is: 1, 1/3, 1/9, 1/27
Sum = 1 + 0.33333 + 0.11111 + 0.03704 ≈ 1.48148
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double geometricSum(double a, double r, int n)
{
  if (r == 1.0)
  {
    return a * n;
  }
  else
  {
    return a * (1 - pow(r, n)) / (1 - r);
  }
}

int main()
{
  double a = 1.0;
  double r = 1.0 / 3.0;
  int n;
  cout << "Enter number of terms (n): ";
  cin >> n;

  double sum = geometricSum(a, r, n);
  cout << "Sum = " << sum << endl;
  return 0;
}