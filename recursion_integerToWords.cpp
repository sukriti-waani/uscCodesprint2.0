/*            Convert Integer to English Words
Given a non-negative integer n, write a program that converts the integer into its English words representation. Your program should handle numbers from 0 up to billions (within the 32-bit signed integer limit).
The function should return "Zero" if the input is 0.
The function should handle large numbers correctly by breaking them into billions, millions, thousands, hundreds, tens, and units.
Negative numbers are not supported.
Constraints
0 <= n <= 2,147,483,647 (32-bit signed int)

Example 1
Input:
1234567
Output:
One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven

*/

#include <iostream>
#include <string>
using namespace std;

const string belowTwenty[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                              "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
                              "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                              "Nineteen"};
const string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                       "Seventy", "Eighty", "Ninety"};
const string thousands[] = {"Billion", "Million", "Thousand", ""};
const int divisors[] = {1000000000, 1000000, 1000, 1};

string convertBelow1000(int n)
{
  if (n == 0)
    return "";
  if (n < 20)
    return belowTwenty[n];
  if (n < 100)
  {
    return tens[n / 10] + (n % 10 ? " " + convertBelow1000(n % 10) : "");
  }
  return belowTwenty[n / 100] + " Hundred" + (n % 100 ? " " + convertBelow1000(n % 100) : "");
}

string helper(int n, int idx = 0)
{
  if (idx >= 4)
    return "";

  if (n >= divisors[idx])
  {
    int part = n / divisors[idx];
    int res = n % divisors[idx];
    string result = convertBelow1000(part);
    if (!thousands[idx].empty())
      result += " " + thousands[idx];
    if (res != 0)
    {
      result += " " + helper(res, idx + 1);
    }
    return result;
  }
  else
  {
    return helper(n, idx + 1);
  }
}

string numToWords(int n)
{
  if (n == 0)
    return "Zero";
  return helper(n);
}

int main()
{
  int n;
  cout << "Enter an integer number: ";
  cin >> n;

  if (n < 0)
  {
    cout << "Negative numbers not supported." << endl;
  }
  else
  {
    cout << numToWords(n) << endl;
  }

  return 0;
}