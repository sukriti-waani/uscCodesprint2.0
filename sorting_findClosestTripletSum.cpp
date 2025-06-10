/*      Closest Triplet Sum
Given an array of integers arr of size n and an integer target, your task is to find the sum of the triplet (i.e., three different elements in the array) such that the sum is closest to the target.
If there are multiple such triplets with the same closest difference, return the one with the greater sum.

Input Format:
The first line contains an integer n — the number of elements in the array. (n ≥ 3)
The second line contains n integers — the elements of the array.
The third line contains an integer target — the target value.
Output Format:
Print a single line with the closest triplet sum to the target.

Constraints:
3 ≤ n ≤ 1000
-10⁴ ≤ arr[i] ≤ 10⁴
-10⁴ ≤ target ≤ 10⁴

Example Input:
diff
Copy
Edit
6
-1 2 1 -4 5 3
1
Example Output:
2

Explanation:
Triplets and their sums close to 1:
(-1, 2, 1) → sum = 2 (closest to 1)
(-1, -4, 5) → sum = 0
So, 2 is closest.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int findClosestTriplet(vector<int> &arr, int target)
{
  int n = arr.size();
  int sum = 0;
  int minDiff = INT_MAX;

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1, right = n - 1;

    while (left < right)
    {
      int currsum = arr[i] + arr[left] + arr[right];
      int diff = abs(currsum - target);

      if (diff < minDiff || (diff == minDiff && currsum > sum))
      {
        minDiff = diff;
        sum = currsum;
      }

      if (currsum < target)
      {
        left++;
      }
      else if (currsum > target)
      {
        right--;
      }
      else
      {
        return currsum;
      }
    }
  }
  return sum;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int target;
  cout << "Enter target: ";
  cin >> target;

  int res = findClosestTriplet(arr, target);

  cout << "Closest Triplet Sum is: " << res << endl;

  return 0;
}