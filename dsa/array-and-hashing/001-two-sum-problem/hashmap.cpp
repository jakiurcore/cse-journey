#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> t;
    int size = nums.size();
    unordered_map<int, int> n;
    for (int i = 0; i < size; i++) {
        int complement = target - nums[i];

        auto it = n.find(complement);

        if (it != n.end()) {
            t.push_back(it->second);
            t.push_back(i);
            return t;
        }

        n.insert({nums[i], i});
    }

    return t;
}

int main() {
    int t, target;
    cin >> t;

    vector<int> v(t);
    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    cin >> target;

    vector<int> result = twoSum(v, target);

    printf("%d %d", result[0], result[1]);

    return 0;
}
