/*                  Explore the Kingdom
A kingdom is represented as a network of castles connected by roads. There are n castles, numbered from 0 to n-1. The roads are bidirectional, meaning if there is a road between castle u and castle v, you can travel both ways.
You are the royal explorer starting from castle 0, and your goal is to visit all the reachable castles using Breadth-First Search (BFS) strategy. Print the order in which the castles are visited.

Write a program to:
Read the number of castles (n) and roads (m).
Read the m pairs of integers representing roads between castles.
Perform BFS starting from castle 0.
Output the order in which castles are visited.

Input Format
First line: an integer n representing the number of castles.
Second line: an integer m representing the number of roads.
Next m lines: two space-separated integers u and v representing a road between castle u and castle v.
Output Format
A single line containing the space-separated order of visiting castles starting from castle 0.

Constraints
1 <= n <= 1000
0 <= u, v < n
Roads are bidirectional and there are no duplicate roads.

Example
Input:
Enter the number of castles: 5
Enter the number of roads: 5
Enter the roads between castles:
0 1
0 2
1 3
2 3
3 4
Output:
Order of visiting castles: 0 1 2 3 4
Explanation:
Starting from castle 0:
First visit: 0
From 0, go to 1 and 2
From 1, go to 3 (already added from 2 as well)
From 3, go to 4
Final visit order using BFS: 0 → 1 → 2 → 3 → 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kingdom(int n, vector<vector<int>> &adj)
{
  vector<int> v;
  vector<bool> visited(n, false);
  queue<int> q;

  visited[0] = true;
  q.push(0);

  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    v.push_back(curr);

    for (int neighbor : adj[curr])
    {
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
  return v;
}

int main()
{
  int n, m;
  cout << "Enter the number of castles: ";
  cin >> n;

  cout << "Enter the number of roads: ";
  cin >> m;

  vector<vector<int>> adj(n);

  cout << "Enter the roads between castles: " << endl;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> order = kingdom(n, adj);

  cout << "Order of visiting castles: ";
  for (int castle : order)
  {
    cout << castle << " ";
  }
  cout << endl;
  return 0;
}