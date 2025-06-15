/*          Count Pairs with First Greater than Second
Problem Statement:
You are given an array of integers containing N elements. Your task is to count the total number of ordered pairs (i, j) such that:
i ≠ j
arr[i] > arr[j]
In other words, you need to count how many pairs exist in the array where the first element is strictly greater than the second element.
Note: The pair count should be based on element values, not their indices.

Input Format:
The first line contains an integer N — the number of elements in the array.
The second line contains N space-separated integers — the elements of the array.
Output Format:
Output a single integer — the total number of such pairs.

Constraints:
1 ≤ N ≤ 10^5
1 ≤ arr[i] ≤ 10^9

Example Input:
5
3 1 2 2 4
Explanation:
All valid pairs where first element is greater than second element are:
(3, 1)
(3, 2) → two times because 2 appears twice
(4, 3)
(4, 2) → two times
(4, 1)
Total pairs = 1 (for 3>1) + 2 (for 3>2) + 1 (for 4>3) + 2 (for 4>2) + 1 (for 4>1)
Total = 7

Output:
7
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

long long calPairs(unordered_map<long long, long long> &freq)
{
  vector<long long> uniqueNum;

  for (auto &p : freq)
  {
    uniqueNum.push_back(p.first);
  }
  sort(uniqueNum.begin(), uniqueNum.end());

  long long res = 0, sum = 0;

  for (auto num : uniqueNum)
  {
    res += freq.at(num) * sum;
    sum += freq.at(num);
  }
  return res;
}

int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;

  unordered_map<long long, long long> freq;
  cout << "Enter elements: \n";
  for (int i = 0; i < n; i++)
  {
    long long num;
    cin >> num;
    freq[num]++;
  }

  long long res = calPairs(freq);

  cout << res << endl;
  return 0;
}