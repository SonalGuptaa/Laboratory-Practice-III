#include<bits/stdc++.h>
using namespace std;

// Main greedy function to solve problem
double fractionalKnapsack(int W, vector<int> weights, vector<int> profits)
{
    int N = weights.size();
    vector<pair<double, int>> ratioToIndex;

    for (int i = 0; i < N; i++) {
        double ratio = (double)profits[i] / (double)weights[i];
        ratioToIndex.push_back(make_pair(ratio, i));
    }

     
    sort(ratioToIndex.rbegin(), ratioToIndex.rend());

    double finalValue = 0.0;

    for (int i = 0; i < N; i++) {
        int index = ratioToIndex[i].second;
        if (weights[index] <= W) {
            W -= weights[index];
            finalValue += profits[index];
        } else {
            finalValue += profits[index] * ((double)W / (double)weights[index]);
            break;
        }
    }

    return finalValue;
}

int main()
{
    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> weights(N);
    vector<int> profits(N);

    for (int i = 0; i < N; i++) {
        cout << "Enter weight and profit for item " << i + 1 << ": ";
        cin >> weights[i] >> profits[i];
    }

    // Function call
    cout << "Maximum profit: " << fractionalKnapsack(W, weights, profits) << endl;
    return 0;
}
 