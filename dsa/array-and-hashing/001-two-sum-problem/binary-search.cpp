#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int binary_search(vector<pair<int, int>> &a, int start, int end, int target) {
    while (start < end) {
        int mid = (start + end) / 2;
        if (a[mid].second == target) {
            return a[mid].first;
        } else if (a[mid].second < target) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return -1;
}

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

    int size = n.size();

    for (int i = 0; i < size - 1; i++) {
        int complement = target - n[i].second;

        int j = binary_search(n, i, size, complement);

        if (n[i].first == j) {
            continue;
        }

        if (j != -1) {
            printf("\n%d %d", n[i].first, j);
            return 0;
        }
    }

    return 0;
}
