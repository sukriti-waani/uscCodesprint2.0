/*        Sort Elements by Frequency and Value
You are given an array of integers. Your task is to sort the array based on the following rules:
Elements with higher frequency come first.
If two elements have the same frequency, the smaller element comes first.
Return the sorted array accordingly.

Input Format:
The first line contains an integer n — the number of elements in the array.
The second line contains n integers — the elements of the array.
Output Format:
Print the array sorted by the described criteria.
Constraints:
1 ≤ n ≤ 10⁵
-10⁴ ≤ arr[i] ≤ 10⁴

Example Input:
8
4 3 4 2 3 1 4 2
Example Output:
4 4 4 3 3 2 2 1
Explanation:
Frequencies:
4 → 3 times
3 → 2 times
2 → 2 times
1 → 1 time
4 has the highest frequency → appears first
3 and 2 both appear 2 times → 2 comes after 3 because 3 < 2 is false, so 3 appears before 2 (ascending order of value)
1 appears only once → last
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void sortByFreq(vector<int> &arr)
{
  unordered_map<int, int> freq;
  for (int num : arr)
  {
    freq[num]++;
  }

  sort(arr.begin(), arr.end(), [&](int a, int b)
       {
    if(freq[a] == freq[b]) {
      return a < b;
    }
    return freq[a] > freq[b]; });

  for (int num : arr)
  {
    cout << num << " ";
  }
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

  cout << "Sorted Frequency and value: ";
  sortByFreq(arr);

  return 0;
}