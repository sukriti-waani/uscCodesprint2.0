/*    Minimum Length Subarray for Calorie Goal
You are given an array of positive integers and a target value.
Your task is to find the length of the smallest contiguous subarray whose sum is greater than or equal to the target value.
If no such subarray exists, return 0.

Sample Input :
Enter number of elements:
6
Enter the elements of the array:
2 3 1 2 4 3
Enter the target sum:
7
Sample Output :
Minimum length of subarray with sum >= 7 is: 2
Explanation:
The subarray [4, 3] has a sum of 7 and is the smallest such subarray with required sum.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minLenSubarray(vector<int> &nums, int target)
{
  int minLen = INT_MAX;
  int sum = 0, left = 0;

  for (int r = 0; r < nums.size(); r++)
  {
    sum += nums[r];

    while (sum >= target)
    {
      minLen = min(minLen, r - left + 1);
      sum -= nums[left];
      left++;
    }
  }

  if (minLen == INT_MAX)
    return 0;
  return minLen;
}

int main()
{
  int n, target;

  cout << "Enter number of elements: " << endl;
  cin >> n;

  vector<int> nums(n);

  cout << "Enter the elements of the array: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << "Enter the target sum: " << endl;
  cin >> target;

  int ans = minLenSubarray(nums, target);
  cout << "Minimum length of subarray with sum >= " << target << " is: " << ans << endl;

  return 0;
}