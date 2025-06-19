/*             Minimize the maximum sum of any group
You are given n boxes with weights, stored in an array. Your task is to divide them into at most k contiguous groups. Each group must have consecutive elements only, and your goal is to minimize the weight of the heaviest group after the division.
Write a program to find and print the minimum possible maximum group sum.

Example:
Input:
Enter number of elements: 5
Enter number of groups: 3
Enter weights:
1 2 3 4 5
What are we solving?
We want to split [1, 2, 3, 4, 5] into at most 3 contiguous groups such that the largest sum among any group is as small as possible.

Try all possible splits with 3 groups:
[1] [2] [3 4 5] → group sums = 1, 2, 12 → max = 12
[1 2] [3 4] [5] → group sums = 3, 7, 5 → max = 7
[1 2 3] [4] [5] → group sums = 6, 4, 5 → max = 6
[1 2 3 4] [5] (only 2 groups) → group sums = 10, 5 → max = 10
[1 2] [3] [4 5] → group sums = 3, 3, 9 → max = 9
[1] [2 3] [4 5] → group sums = 1, 5, 9 → max = 9
Best split: [1 2 3], [4], [5] → max sum = 6
🧾 Final Output:
Minimum possible maximum group sum is: 6

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(vector<int> &w, int k, int mid)
{
  int currSum = 0, count = 1;

  for (int i = 0; i < w.size(); i++)
  {
    if (currSum + w[i] <= mid)
    {
      currSum += w[i];
    }
    else
    {
      count++;
      currSum = w[i];
      if (count > k)
        return false;
    }
  }
  return true;
}

int box(vector<int> &w, int k)
{
  int low = *max_element(w.begin(), w.end());
  int high = 0;

  for (int i = 0; i < w.size(); i++)
  {
    high += w[i];
  }

  while (low < high)
  {
    int mid = low + (high - low) / 2;

    if (canDivide(w, k, mid))
    {
      high = mid;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}

int main()
{
  int n, k;

  cout << "Enter number of elements: ";
  cin >> n;
  cout << "Enter number of groups: ";
  cin >> k;

  vector<int> w(n);
  cout << "Enter weights: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> w[i];
  }
  int res = box(w, k);
  cout << "Minimum possible maximum group sum is: " << res << endl;

  return 0;
}