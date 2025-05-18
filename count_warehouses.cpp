// Count Overstocked Warehouses : Count how many warehouses have at least 3 products with stock greater than or equal to 100. 
// input:   3  5
//   120 80 150 130 90
//   95 60 40 50 70
//   100 105 110 95 115
// output: 2

#include <iostream>
using namespace std;

int countOW(int row, int col, int stock[100][100])
{
  int osCount = 0;

  for (int i = 0; i < row; i++)
  {
    int count = 0;
    for (int j = 0; j < col; j++)
    {
      if (stock[i][j] >= 100)
      {
        count++;
      }
    }
    if (count >= 3)
    {
      osCount++;
    }
  }
  return osCount;
}

int main()
{
  int row, col;

  cout << "Enter the number of warehouses: " << endl;
  cin >> row;

  cout << "Enter the number of product types: " << endl;
  cin >> col;

  int stock[100][100];

  cout << "Enter the stock values: " << endl;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      cin >> stock[i][j];
    }
  }
  int ans = countOW(row, col, stock);

  cout << "Number of overstocked warehouses: " << ans << endl;

  return 0;
}