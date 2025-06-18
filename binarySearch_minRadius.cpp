/*        Heaters and Minimum Radius
You are given the positions of houses and heaters on a 1D line. All the houses can only be warmed by heaters within a certain radius.
Each heater warms every house within its radius on both sides (i.e., from heater - radius to heater + radius).
Your task is to find the minimum radius required so that every house is within the warming range of at least one heater.

Input Format:
First line: Integer n – number of houses
Second line: n space-separated integers – positions of the houses
Third line: Integer m – number of heaters
Fourth line: m space-separated integers – positions of the heaters
Output Format:
A single integer – the minimum radius required for the heaters

💡 Constraints:
1 ≤ n, m ≤ 10^5
House and heater positions are integers in the range [1, 10^9]
The positions of houses and heaters may not be sorted

Example 1:
Input:
3
1 2 3
1
2
Output:
1
Explanation:
Heater is at position 2.
House 1 is 1 unit away → needs radius ≥ 1
House 2 is 0 units away → already covered
House 3 is 1 unit away → needs radius ≥ 1
So the minimum radius = 1

Example 2:
Input:
2
1 5
1
2
Output:
3
Explanation:
Heater is at position 2.
House 1 is 1 unit away → OK
House 5 is 3 units away → So radius must be ≥ 3
Hence, minimum radius = 3
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minRadius(vector<int> &houses, vector<int> &heaters)
{
  sort(heaters.begin(), heaters.end());
  int minRad = 0;

  for (int h : houses)
  {
    int l = 0, r = heaters.size() - 1;
    int dis = INT_MAX;

    while (l <= r)
    {
      int mid = l + (r - l) / 2;
      dis = min(dis, abs(heaters[mid] - h));

      if (heaters[mid] < h)
      {
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }
    minRad = max(minRad, dis);
  }
  return minRad;
}

int main()
{
  int n, m;
  cout << "Enter number of houses: ";
  cin >> n;

  vector<int> houses(n);
  cout << "Enter positions of houses: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> houses[i];
  }

  cout << "Enter number of heaters: \n";
  cin >> m;

  vector<int> heaters(m);
  cout << "Enter positions of heaters: \n";
  for (int i = 0; i < m; i++)
  {
    cin >> heaters[i];
  }

  int res = minRadius(houses, heaters);
  cout << "Minimum radius needed: " << res << endl;

  return 0;
}