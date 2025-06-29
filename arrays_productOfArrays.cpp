/*                       Product of Array Except Self (Without Division)
You are given an array of integers where each element represents the energy value of a magical crystal. Your task is to transform the array such that:
Each element in the output array is the product of all the elements in the input array except the one at that index.

Important Conditions:
You must not use division.
Your algorithm must run in O(n) time.
You can use (n) extra space.

Input Format:
First line: Integer n, the number of elements in the array.
Second line: n space-separated integers representing the energy values.
Output Format:
A single line with n space-separated integers — the transformed array.

Constraints:
2 ≤ n ≤ 10^5
-10^4 ≤ energy[i] ≤ 10^4

Example 1:
Input:
Enter the number of elements: 5
Enter values:
1 2 3 4 5
Output:
Transformed energy values: 120 60 40 30 24
Explanation:
Output[0] = 2×3×4×5 = 120
Output[1] = 1×3×4×5 = 60
Output[2] = 1×2×4×5 = 40
Output[3] = 1×2×3×5 = 30
Output[4] = 1×2×3×4 = 24
*/

#include <iostream>
#include <vector>
using namespace std;

vector<long long> compute(vector<long long> &e)
{
  int n = e.size();
  vector<long long> prefix(n, 1), suffix(n, 1), res(n);

  for (int i = 1; i < n; i++)
  {
    prefix[i] = prefix[i - 1] * e[i - 1];
  }

  for (int i = n - 2; i >= 0; i--)
  {
    suffix[i] = suffix[i + 1] * e[i + 1];
  }

  for (int i = 0; i < n; i++)
  {
    res[i] = prefix[i] * suffix[i];
  }
  return res;
}

int main()
{
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  vector<long long> e(n);
  cout << "Enter values: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> e[i];
  }

  vector<long long> res = compute(e);
  cout << "Transformed enery values: ";
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i];
    if (i != res.size() - 1)
      cout << " ";
  }
  cout << endl;
  return 0;
}