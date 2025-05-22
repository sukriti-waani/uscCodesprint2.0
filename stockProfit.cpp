/*    Maximize Stock Profit with Minimum Threshold
You are given an array of stock prices where prices[i] is the price of a stock on day i.
Your task is to find the maximum profit you can achieve by buying on one day and selling on another later day.
But there's a condition:
Return the profit only if it's at least 2, otherwise return 0.

Example:
Input:
prices = [7, 1, 5, 3, 6, 4]

Explanation:
Buy on day 1 at price 1
Sell on day 4 at price 6
Profit = 6 - 1 = 5   (valid, ≥ 2)

Output:
5
*/

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
  int minPrice = prices[0];
  int maxProfit = 0;

  for (int i = 1; i < prices.size(); i++)
  {
    int currPrice = prices[i];
    int profit = currPrice - minPrice;

    if (profit > maxProfit)
    {
      maxProfit = profit;
    }

    if (currPrice < minPrice)
    {
      minPrice = currPrice;
    }
  }

  if (maxProfit >= 2)
  {
    return maxProfit;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n;
  cout << "Enter the number of days: " << endl;
  cin >> n;

  vector<int> prices(n);
  cout << "Enter the prices: " << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }

  int ans = maxProfit(prices);
  cout << ans << endl;

  return 0;
}