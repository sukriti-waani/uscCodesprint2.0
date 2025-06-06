/*    Number of Students Unable to Eat Lunch
Description:
In a school cafeteria, there is a queue of students and a stack of sandwiches. Each student prefers either a circular sandwich (0) or a square sandwich (1).

The rules are:
The student at the front of the queue checks the top sandwich.
If the sandwich matches the student’s preference, the student takes it and leaves the queue.
If it does not match, the student moves to the end of the queue.
If none of the students in the current queue want the sandwich on top, the process stops.
Your task is to determine the number of students who are unable to eat because their preferred sandwich is no longer available.

Input Format:
An integer n — the number of students.
An array pref[0..n-1] — the preference of each student (0 or 1).
An array sand[0..n-1] — the sandwich types in stack order (first element is on top).
Constraints:
1 ≤ n ≤ 1000
pref[i] and sand[i] are either 0 or 1
Output:
Print the number of students who cannot eat.

Example:
Input:
Enter the number of students: 5
Enter preferences (0 or 1) for each student:
1 1 0 0 1
Enter sandwich types (0 or 1) for each position:
0 1 0 1 1
Output:
Number of students unable to eat: 0

Explanation:
Student 0 (prefers 1), sandwich is 0 → goes to back
Student 1 (prefers 1), sandwich is 0 → back
Student 2 (prefers 0), sandwich is 0 → eats
Now sandwich is 1, student 3 (prefers 0) → back
Student 4 (prefers 1), sandwich is 1 → eats
Continue until all students get their matching sandwich.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int studentUnableToEat(vector<int> &pref, vector<int> &sand)
{
  queue<int> q;
  for (int n : pref)
  {
    q.push(n);
  }

  int count = 0, idx = 0;

  while (!q.empty() && count < q.size())
  {
    if (q.front() == sand[idx])
    {
      q.pop();
      idx++;
      count = 0;
    }
    else
    {
      q.push(q.front());
      q.pop();
      count++;
    }
  }
  return q.size();
}

int main()
{
  int n;
  cout << "Enter the number of students: ";
  cin >> n;

  vector<int> pref(n);
  vector<int> sand(n);

  cout << "Enter preferences (0 or 1) for each student: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> pref[i];
  }

  cout << "Enter sandwich types (0 or 1) for each position: \n";
  for (int i = 0; i < n; i++)
  {
    cin >> sand[i];
  }

  int rem = studentUnableToEat(pref, sand);
  cout << "Number of students unable to eat: " << rem << endl;

  return 0;
}