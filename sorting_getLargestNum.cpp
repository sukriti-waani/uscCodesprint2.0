/*       Largest Number From Array Elements
You are given an array of non-negative integers, and your task is to arrange them such that they form the largest possible number when concatenated.
You must return the number as a string since the result may be very large.

Input Format:
First line contains an integer n — the number of elements in the array.
Second line contains n space-separated strings, each representing a non-negative integer.
Output Format:
Output a single string — the largest possible number formed by arranging the array elements.

Sample Input 1:
5
3 30 34 5 9
Sample Output 1:
9534330
Sample Input 2:
4
0 0 0 0
Sample Output 2:
0
Explanation:
In Example 1, arranging the numbers as 9, 5, 34, 3, 30 gives the largest number: 9534330.
In Example 2, since all elements are 0, the output is simply "0" and not "0000".
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string &a, string &b)
{
  return a + b > b + a;
}

bool areAllZeros(vector<string> &nums)
{
  for (string &num : nums)
  {
    if (num != "0")
    {
      return false;
    }
  }
  return true;
}

string getLargestNum(vector<string> &nums)
{
  sort(nums.begin(), nums.end(), compare);
  if (areAllZeros(nums))
  {
    return "0";
  }

  string res;
  for (string &num : nums)
  {
    res += num;
  }
  return res;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<string> nums(n);
  cout << "Enter elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  string res = getLargestNum(nums);

  cout << res << endl;

  return 0;
}