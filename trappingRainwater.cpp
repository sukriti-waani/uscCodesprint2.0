/*      Trapping Rain Water
You are given an array of non-negative integers where each element represents the height of a bar at that position. Imagine vertical bars of unit width placed next to each other — after it rains, water is trapped between some of the bars. Your task is to compute how much water can be trapped between the bars.
Write a function to return the total units of trapped water.

Example
Input:
height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output:
6
Explanation:
Water is trapped in the dips between bars.

Total water trapped = 6 units.

Constraints:
1 <= height.length <= 10^5
0 <= height[i] <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &h)
{
  int n = h.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;

  while (left <= right)
  {
    if (h[left] <= h[right])
    {
      if (h[left] >= maxLeft)
      {
        maxLeft = h[left];
      }
      else
      {
        res += maxLeft - h[left];
      }
      left++;
    }
    else
    {
      if (h[right] >= maxRight)
      {
        maxRight = h[right];
      }
      else
      {
        res += maxRight - h[right];
      }
      right--;
    }
  }
  return res;
}

int main()
{
  int n;
  cout << "Enter the number of elements in the height array: ";
  cin >> n;

  vector<int> h(n);
  cout << "Enter the height values: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  cout << "The water that can be trapped is " << trap(h) << endl;

  return 0;
}