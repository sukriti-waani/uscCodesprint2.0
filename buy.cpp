#include<iostream>
#include<vector>
using namespace std;

bool canBuyIceCream(int budget, vector<int> &prices) {
  for(int i = 0; i < prices.size(); i++) {
    if(prices[i] == budget) {
      return true;
    }
	}
    return false;
}

int main() {
  int budget;
  cout << "Enter the budget" << endl;
  cin >> budget;

  int n;
  cout << "Enter the number of prices" << endl;
  cin >> n; 

  vector<int> prices(n);

  cout << "Enter the prices" <<endl;
  for(int i = 0; i < n; i++) {
    cin >> prices[i];
	}
	  if(canBuyIceCream(budget, prices)) {
	    cout << "true" << endl;
	  }
	  else {
	    cout << "false" << endl;
	  }
  return 0;
}
