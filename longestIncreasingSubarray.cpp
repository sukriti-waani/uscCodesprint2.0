// Find Longest Strictly Increasing Temperature Subarray : 
// Input :   8
//        15 16 17 13 14 15 16 12
// Output : 4
// explanantion : The longest striclty increasing subarray is : [13, 14, 15, 16] which has length of 4.


#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubarray(vector<int> &arr)
{
  int maxLen = 1, currLen = 1;

  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] > arr[i - 1])
    {
      currLen++;
      maxLen = max(maxLen, currLen);
    }
    else
    {
      currLen = 1;
    }
  }
  return maxLen;
}

int main()
{
  int n;
  cout << "Enter number of days: " << endl;
  cin >> n;

  vector<int> arr(n);
  cout << "Enter temperature readings: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  int ans = longestIncreasingSubarray(arr);
  cout << "Length of longest increasing subarray: " << ans << endl;

  return 0;
}