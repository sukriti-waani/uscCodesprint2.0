/*              Find the Missing Number
You are given an array of size n containing n distinct numbers in the range 0 to n.
One number from the range is missing. Write a function to find and return the missing number.

Input Format:
First line: integer n — size of the array.
Second line: n space-separated integers — the elements of the array.
Output Format:
Print the missing number.

Sample Input:
4
0 1 3 4
Sample Output:
2
Explanation:
The array should have numbers from 0 to 4, but 2 is missing.
*/

#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> &arr)
{
  int xor1 = 0, xor2 = 0;
  int n = arr.size();

  for (int i = 0; i < n; i++)
  {
    xor2 = xor2 ^ arr[i];
    xor1 = xor1 ^ i;
  }

  xor1 = xor1 ^ n;
  return xor1 ^ xor2;
}

int main()
{
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << "The missing number is: " << missingNumber(arr) << endl;
  return 0;
}