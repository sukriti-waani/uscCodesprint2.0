/*    Three Sum Check
Given an array of integers and a target value, determine if there exist any three numbers in the array whose sum is equal to the target value.

Input:
First line: An integer n (number of elements in the array).
Second line: n space-separated integers (the elements of the array).
Third line: An integer target (the sum to check for among any three elements).
Output:
Output true if there exists a triplet (i, j, k) such that nums[i] + nums[j] + nums[k] == target, where i != j != k.
Otherwise, output false.

Example:
Input:
6
12 3 4 1 6 9
24
Output:
true
Explanation:
There exists a triplet (12, 3, 9) in the array such that their sum is 12 + 3 + 9 = 24, which is equal to the target.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sum(vector<int> &nums, int target)
{
  int n = nums.size();

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1, right = n - 1;

    while (left < right)
    {
      int currSum = nums[i] + nums[left] + nums[right];

      if (currSum == target)
      {
        return true;
      }
      else if (currSum < target)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }
  return false;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  vector<int> nums(n);
  cout << "Enter elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  int target;
  cout << "Enter target: ";
  cin >> target;

  if (sum(nums, target))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
  return 0;
}