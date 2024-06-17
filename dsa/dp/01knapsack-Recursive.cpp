#include <bits/stdc++.h>

using namespace std;

// 0 1 Knapsack 
int knapsack(vector<int> weight, vector<int> values, int n, int maxWeight) {
    if (n == 0 || maxWeight <= 0) {
        return 0;
    }

    // not taken
    int notTaken = knapsack(weight, values, n-1, maxWeight);
    
    // taken
    int taken = 0;
    if (weight[n-1] <= maxWeight) {
      taken = values[n-1] + knapsack(weight, values, n-1, maxWeight-weight[n-1]);
    } 

    return max(taken, notTaken);
    
}

int main() {
    std::cout << "0/1 Knapsack problem" << std::endl;

    // weight
    vector<int> weight{ 1, 2, 4, 5};
    vector<int> values{ 5, 4, 8, 6};
    int maxWeight = 5;
    int n = 4;
    int value = 0;
    // values

    // pattern - take or not take

    int maxValue = knapsack(weight, values, n-1, maxWeight);
    cout << "max value possible - " << maxValue;
    
    return 0;
}
