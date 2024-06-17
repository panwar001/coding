// 0/1 knapsack
#include <bits/stdc++.h>

using namespace std;

// 0 1 Knapsack ->> pattern - take or not take 
int knapsack(vector<int> weight, vector<int> values, int n, int maxWeight) {
    if (n == 0 || maxWeight <= 0) {
        return 0;
    }

    // Take 
    if (weight[n-1] <= maxWeight) {
      return max(values[n-1] + knapsack(weight, values, n-1, maxWeight-weight[n-1]) ,
             knapsack(weight, values, n-1, maxWeight));
    } // not take
    else {
       return knapsack(weight, values, n-1, maxWeight);
    }
    
}

int main() {
    std::cout << "0/1 Knapsack problem" << std::endl;

    vector<int> weight{ 1, 2, 4, 5};
    vector<int> values{ 5, 4, 8, 6};
    int maxWeight = 5;
    int n = 4;
    int value = 0;

    int maxValue = knapsack(weight, values, n-1, maxWeight);
    cout << "max value possible - " << maxValue;
    
    return 0;
}
