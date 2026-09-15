#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    vector<pair<int, int>> n;

    int t, target;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int x;
        cin >> x;
        n.push_back(make_pair(i, x));
    }

    cin >> target;

    sort(n.begin(), n.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.second < b.second;
         });

    int left = 0;
    int right = n.size() - 1;

    while (left < right) {
        int sum = n[left].second + n[right].second;

        if (sum == target) {
            printf("%d %d\n", n[left].first, n[right].first);
            return 0;
        }

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
}
