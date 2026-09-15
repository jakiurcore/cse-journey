#include <cstddef>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> mp;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        auto it = mp.find(nums[i]);

        if (it != mp.end()) {
            return true;
        } else {
            mp.insert({nums[i], 1});
        }
    }

    return false;
}

int main() {
    int t;

    cin >> t;

    vector<int> v(t);

    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    printf("%d", containsDuplicate(v));
}
