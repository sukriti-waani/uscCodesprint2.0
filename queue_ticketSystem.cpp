/*    Queue Ticket System
There is a ticket counter with a single queue. Each person in the queue needs a certain number of tickets. The counter gives only one ticket at a time to the person at the front of the queue.
After receiving a ticket, if a person still needs more, they go to the end of the queue.
This continues until the person at position k (0-based index) has received all their tickets.

Your task is to calculate how many seconds it will take for the person at position k to complete buying all their tickets.
Each ticket takes 1 second to issue.

Input Format
n             // number of people in the queue
t1 t2 t3 ... tn   // tickets needed by each person (n integers)
k             // index (0-based) of the target person
Output Format
Total time taken: <time_in_seconds> seconds

Sample Input
4
2 3 2 1
2
Sample Output
Total time taken: 8 seconds
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int buyTickets(vector<int> &tic, int k)
{
  queue<pair<int, int>> q;
  for (int i = 0; i < tic.size(); i++)
  {
    q.push({i, tic[i]});
  }

  int timeElapsed = 0;
  while (!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop();

    curr.second -= 1;
    timeElapsed += 1;

    if (curr.first == k && curr.second == 0)
    {
      break;
    }

    if (curr.second > 0)
    {
      q.push(curr);
    }
  }
  return timeElapsed;
}

int main()
{
  int n, k;
  cout << "Enter number of visitors in queue: ";
  cin >> n;

  vector<int> tic;
  cout << "Enter number of tickets each visitor wants: \n";
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    tic.push_back(x);
  }

  cout << "Enter the position of the target visitor: ";
  cin >> k;

  int res = buyTickets(tic, k);
  cout << res << endl;

  return 0;
}