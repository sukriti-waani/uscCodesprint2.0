/*                      Traverse the Kingdom using DFS
A kingdom is represented as a set of n castles connected by m bidirectional roads. Each castle is numbered from 0 to n-1. You are a royal messenger who needs to explore the kingdom starting from castle 0 using a Depth-First Search (DFS) traversal strategy.
Write a program that:
Takes the number of castles and roads as input.
Accepts m pairs of integers representing roads between castles.
Performs a DFS traversal starting from castle 0.
Outputs the order in which castles are visited.

Input Format
First line: An integer n representing the number of castles.
Second line: An integer m representing the number of roads.
Next m lines: Two space-separated integers u and v denoting a road between castle u and castle v.
Output Format
A single line containing the space-separated order of castles visited in DFS traversal starting from castle 0.

Constraints
1 ≤ n ≤ 1000
0 ≤ u, v < n
Roads are bidirectional and there are no self-loops or multiple edges between the same pair.

Sample Input
Enter the number of castles: 5
Enter the number of roads: 5
Enter the roads between castles (u v):
0 1
0 2
1 3
2 4
3 4
Sample Output
Order of traversing castles: 0 1 3 4 2
Explanation
You start DFS from castle 0.
From 0, go to 1, then from 1 to 3, then 3 to 4.
Finally, backtrack and explore 2 from 0.
The traversal order depends on the order of neighbors in the adjacency list.
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order)
{
  visited[n] = true;
  order.push_back(n);

  for (int neighbor : adj[n])
  {
    if (!visited[neighbor])
    {
      dfs(neighbor, adj, visited, order);
    }
  }
}

vector<int> traverse(int n, vector<vector<int>> &adj)
{
  vector<bool> visited(n, false);
  vector<int> order;

  dfs(0, adj, visited, order);

  return order;
}

int main()
{
  int n, m;
  cout << "Enter the number of castles: ";
  cin >> n;

  cout << "Enter the number of nodes: ";
  cin >> m;

  vector<vector<int>> adj(n);

  cout << "Enter the roads between castles: \n";
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> traversal = traverse(n, adj);

  cout << "Order of traversing castles: \n";
  for (int castle : traversal)
  {
    cout << castle << " ";
  }
  cout << endl;
  return 0;
}