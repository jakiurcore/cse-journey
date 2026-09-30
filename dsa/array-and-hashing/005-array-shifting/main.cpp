#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void duplicateZeros(vector<int> &arr) {
    int len = arr.size();
    int zero = count(arr.begin(), arr.end(), 0);

    for (int i = len - 1, j = len + zero - 1; i >= 0; i--) {
        if (j < len)
            arr[j] = arr[i];
        j--;
        if (arr[i] == 0 && j < len)
            arr[j] = arr[i];
        j--;
    }
}

int main() {
    vector<int> num = {1, 0, 2, 3, 0, 4, 5, 0};

    duplicateZeros(num);

    for (auto i : num) {
        cout << i << " ";
    }

    return 0;
}
