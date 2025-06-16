/*          Search Insert Position
You are given a sorted array of distinct integers and a target value.
If the target is found in the array, return its index.
If not found, return the index where it would be inserted in order to maintain the sorted order.

Input Format:
First line: Integer n (size of array)
Second line: n space-separated integers (the sorted array)
Third line: Target value to insert.
Output Format:
Output one integer — the index to insert the target.


Question 1 — Target lies in between
Input:
5
1 3 5 6 9
7
Output:
4
Explanation:
7 lies between 6 and 9.
So, it should be inserted at index 4 (0-based index).
*/

#include <iostream>
#include <vector>
using namespace std;

int insertEle(vector<int> &nums, int target)
{
  int left = 0, right = nums.size() - 1;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return left;
}

int main()
{
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter sorted elements: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  int target;
  cout << "Enter the  target number to insert: ";
  cin >> target;

  int res = insertEle(nums, target);
  cout << "Insert position for " << target << " is: " << res << endl;

  return 0;
}