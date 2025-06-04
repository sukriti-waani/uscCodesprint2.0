/*    Next Smaller Element After Next Greater Element
Description:
Given an array of integers, for each element, find the next greater element to its right. Then, starting from that next greater element's position, find the next smaller element to its right.
Return an array where each element is the value of this next smaller element after the next greater element for the corresponding input element. If either the next greater or the next smaller element does not exist, return -1 for that position.
Input:
An integer n representing the size of the array.
An array of integers of size n.
Output:
An array of integers where each element is the next smaller element after the next greater element of the corresponding input element, or -1 if it does not exist.

Example:
Input:
n = 6
arr = [5, 1, 9, 2, 5, 1]

Step-by-step Explanation:
For element 5 (index 0):
Next greater element is 9 at index 2.
Next smaller element after 9 is 2 at index 3.
So, result for index 0 is 2.
For element 1 (index 1):
Next greater element is 9 at index 2.
Next smaller element after 9 is 2 at index 3.
So, result for index 1 is 2.
For element 9 (index 2):
No next greater element.
Result is -1.
For element 2 (index 3):
Next greater element is 5 at index 4.
Next smaller element after 5 is 1 at index 5.
Result for index 3 is 1.
For element 5 (index 4):
No next greater element.
Result is -1.
For element 1 (index 5):
No next greater element.
Result is -1.

Output:
2 2 -1 1 -1 -1


*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> findNextGreater(vector<int> &arr)
{
  int n = arr.size();
  vector<int> nextGreater(n, -1);
  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    while (!s.empty() && arr[s.top()] < arr[i])
    {
      nextGreater[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  return nextGreater;
}

vector<int> findNextSmaller(vector<int> &arr, vector<int> &nextGreater)
{
  int n = arr.size();
  vector<int> ans(n, -1);

  for (int i = 0; i < n; i++)
  {
    int ngIdx = nextGreater[i];

    if (ngIdx != -1)
    {
      for (int j = ngIdx + 1; j < n; j++)
      {
        if (arr[j] < arr[ngIdx])
        {
          ans[i] = arr[j];
          break;
        }
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter elements: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  vector<int> nextGr = findNextGreater(arr);
  vector<int> res = findNextSmaller(arr, nextGr);

  cout << "Result: ";
  for (int i = 0; i < n; i++)
  {
    cout << res[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}