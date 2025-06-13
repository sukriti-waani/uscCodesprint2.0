/*        Vaccine Distribution Problem
You are given two arrays:
vaccines[ ] of size N — each element represents the strength of available vaccines.
patients[ ] of size N — each element represents the severity level of each patient.
A vaccine can only cure a patient if its strength is strictly greater than the patient's severity level.
You need to determine whether it's possible to assign one vaccine to each patient such that all patients are cured.

Input Format:
First line contains an integer N — number of patients.
Second line contains N integers — strengths of vaccines.
Third line contains N integers — severity levels of patients.
Output Format:
Print "Yes" if all patients can be cured.
Otherwise, print "No".
Constraints:
1 ≤ N ≤ 10^5
1 ≤ vaccines[i], patients[i] ≤ 10^9

Example Input 1:
4
7 2 5 10
1 2 3 5
Example Output 1:
Yes
Explanation:
After sorting both arrays:
vaccines = [2, 5, 7, 10]
patients = [1, 2, 3, 5]

Now:
2 > 1
5 > 2
7 > 3
10 > 5
Since every vaccine strength is greater than patient severity → answer is Yes.

Example Input:
3
5 2 8
3 4 5
Example Output:
No
Explanation:
After sorting both arrays:
vaccines = [2, 5, 8]
patients = [3, 4, 5]
2 ≤ 3 ❌ → can't cure 1st patient. So answer is No.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canCure(vector<long long> &vaccines, vector<long long> &patients, int n)
{
  for (int i = 0; i < n; i++)
  {
    if (vaccines[i] <= patients[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
  cout << "Enter number: ";
  cin >> n;

  vector<long long> vaccines(n), patients(n);

  cout << "Enter vaccines: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> vaccines[i];
  }

  cout << "Enter patients: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> patients[i];
  }

  sort(vaccines.begin(), vaccines.end());
  sort(patients.begin(), patients.end());

  if (canCure(vaccines, patients, n))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}