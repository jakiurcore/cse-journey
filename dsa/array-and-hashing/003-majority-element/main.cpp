// Trying to solve this in O(n) and O(1) - My algorithm skip the vector space
#include <algorithm>
#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int size = nums.size();

    int mx = 0, cnt = 1, number = 0;

    if (size < 2) {
        return nums[0];
    }

    for (int i = 1; i < size; i++) {
        if (nums[i - 1] == nums[i]) {
            cnt++;
        } else {
            cnt = 1;
        }

        if (cnt > mx) {
            mx = cnt, number = nums[i - 1];
        }
    }

    return number;
}

int main() {
    int t;

    cin >> t;

    vector<int> v(t);

    for (int i = 0; i < t; i++) {
        cin >> v[i];
    }

    printf("%d", majorityElement(v));
}
