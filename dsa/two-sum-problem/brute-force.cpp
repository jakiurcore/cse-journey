#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> n;

    int t, target;

    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        n.push_back(x);
    }

    cin >> target;

    int size = n.size();

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size - 1; j++) {
            if (n[i] + n[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}
