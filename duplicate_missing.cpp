/*      Set Mismatch
You are given an array of n integers called nums where:
The array contains all numbers from 1 to n (inclusive),
But one number is duplicated, And one number is missing.
Your task is to find: The duplicated number, And the missing number.

✨ Input Format:
First line: an integer n — total number of elements.
Second line: n space-separated integers — the elements of the array.
✨ Output Format:
Print the duplicated number and the missing number.

✨ Constraints:
2 <= n <= 10^4
Each element in nums lies in the range [1, n].
There is exactly one duplicated number and one missing number.

Example 1:
Input:
Enter number of elements: 4
Enter the elements:
1 2 2 4
Output:
Duplicated: 2 , Missing: 3

Example 2:
Input:
Enter number of elements: 5
Enter the elements:
3 1 2 5 3
Output:
Duplicated: 3 , Missing: 4
Explanation:
In example 1:
The correct sequence should be: 1 2 3 4.
But 2 is repeated, and 3 is missing.
Your code correctly detects both.

This problem is similar to LeetCode 645 — Set Mismatch
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findError(vector<int> &nums)
{
  int n = nums.size();
  long long sum = n * (n + 1LL) / 2;
  long long sumSq = n * (n + 1LL) * (2 * n + 1LL) / 6;
  long long actualSum = 0, actualSumSq = 0;

  for (int num : nums)
  {
    actualSum += num;
    actualSumSq += (long long)num * num;
  }

  long long diffSum = sum - actualSum;
  long long diffSq = sumSq - actualSumSq;

  long long sum_md = diffSq / diffSum;

  int missing = (diffSum + sum_md) / 2;
  int duplicate = missing - diffSum;

  return {duplicate, missing};
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter the elements: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<int> res = findError(nums);

  cout << "Duplicated: " << res[0] << " , Missing: " << res[1] << endl;

  return 0;
}