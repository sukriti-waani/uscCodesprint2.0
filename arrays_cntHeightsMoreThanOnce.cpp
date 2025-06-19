/*            Count Heights that Appear More Than Once
In a class, each student has a specific height (also called highness). You are given the heights of all n students. Your task is to count how many unique height values appear more than once in the list.
Write a program that:
Takes the number of students n as input.
Then takes n integers, each representing the height of a student.
Outputs the number of heights that occur more than once.

Input Format:
First line: An integer n — the number of students.
Next n lines: Each line contains a single integer — the height of a student.
Output Format:
A single integer: the number of distinct heights that occur more than once.

Example:
Input:
Enter number of students: 6
Enter highness values of students:
Student 1: 160
Student 2: 170
Student 3: 160
Student 4: 180
Student 5: 150
Student 6: 170
Output:
Number of heights that appear more than once: 2
Explanation:
Height 160 appears 2 times
Height 170 appears 2 times
Other heights (180, 150) appear only once
So, 2 unique heights (160 and 170) appear more than once.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countHeights(vector<int> &h)
{
  vector<int> freq(10001, 0);
  int count = 0;

  for (int i = 0; i < h.size(); i++)
  {
    freq[h[i]]++;
  }

  for (int i = 0; i < freq.size(); i++)
  {
    if (freq[i] > 1)
    {
      count++;
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter number of students: ";
  cin >> n;

  vector<int> h(n);
  cout << "Enter highness values of students: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> h[i];
  }
  int res = countHeights(h);

  cout << "Number of that appear more than once: " << res << endl;

  return 0;
}