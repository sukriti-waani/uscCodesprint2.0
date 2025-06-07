/*      Maximum Score in a Jump Game
You are given an array nums of integers, where each element represents the score you get by landing on that position. You start from the first index (index 0) and your goal is to reach the last index (index n-1) with the maximum possible total score.
From index i, you can jump to any index j such that i < j <= i + k. In other words, you can jump forward up to k steps. You cannot jump backward.
Write a function to return the maximum score you can get by reaching the last index.

Input:
An integer n – number of elements in the array.
A list of integers nums of length n, where nums[i] is the score at index i.
An integer k – the maximum number of steps you can jump forward from any index.
Output:
An integer representing the maximum score achievable to reach the last index.

Constraints:
1 <= n <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= n - 1

Example:
Input:
Enter the number of elements in the array: 6
Enter the elements of the array:
1 -2 -5 7 -6 4
Enter the value of k: 2

Output:
Max path score: 6

Explanation:
Start at index 0 → value: 1
From index 0, jump to index 1 (-2) or index 2 (-5)
Best path: 0 → 1 → 3 → 5
1 + (-2) + 7 + 4 = 10
But better path: 0 → 3 → 5
1 + 7 + 4 = 12
Final path chosen by the algorithm gives maximum score = 6 (via optimal jump choices)

*/

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int maxScore(vector<int> &nums, int k)
{
  int n = nums.size();
  vector<long long> dp(n);
  dp[0] = nums[0];
  deque<int> dq;
  dq.push_back(0);

  for (int i = 1; i < n; i++)
  {
    while (!dq.empty() && dq.front() < i - k)
    {
      dq.pop_front();
    }
    dp[i] = nums[i] + dp[dq.front()];

    while (!dq.empty() && dp[dq.back()] <= dp[i])
    {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  return dp[n - 1];
}

int main()
{
  int n, k;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  vector<int> nums(n);
  cout << "Enter the elements of the array: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << "Enter the value of k: ";
  cin >> k;

  cout << "Max path score: " << maxScore(nums, k) << endl;

  return 0;
}