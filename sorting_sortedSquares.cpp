/*        Sorted Squares of a Sorted Array
You are given a sorted array of integers (which may contain both negative and positive numbers).
Your task is to return a new array containing the squares of each number, sorted in non-decreasing order.

Input Format:
First line contains an integer N — the size of the array.
Second line contains N space-separated integers — the elements of the array.
Output Format:
Output N space-separated integers — the squares of the elements in sorted order.
Constraints:
1 ≤ N ≤ 10^5
-10^4 ≤ nums[i] ≤ 10^4

Example 1:
5
-7 -3 0 2 5
Output:
0 4 9 25 49
Explanation:
Original array: [-7, -3, 0, 2, 5]
Squares: [49, 9, 0, 4, 25]
After sorting: [0, 4, 9, 25, 49]
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSq(vector<int> &nums)
{
  int n = nums.size();
  vector<int> res(n);
  int left = 0, right = n - 1, idx = n - 1;

  while (left <= right)
  {
    int leftSq = nums[left] * nums[left];
    int rightSq = nums[right] * nums[right];

    if (leftSq > rightSq)
    {
      res[idx] = leftSq;
      left++;
    }
    else
    {
      res[idx] = rightSq;
      right--;
    }
    idx--;
  }
  return res;
}

int main()
{
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  vector<int> nums(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  vector<int> res = sortedSq(nums);

  cout << "Sorted Squares: " << endl;
  for (int num : res)
  {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}