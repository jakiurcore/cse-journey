#include <bits/stdc++.h>
#include <climits>

using namespace std;

int maxProfit(vector<int> &prices) {
    int minPrice = INT_MAX, best = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        best = max(best, p - minPrice);
    }
    return best;
}

int main() {
    int size;
    vector<int> prices;

    cin >> size;

    while (size--) {
        int x;
        cin >> x;
        prices.push_back(x);
    }

    cout << maxProfit(prices);

    return 0;
}
