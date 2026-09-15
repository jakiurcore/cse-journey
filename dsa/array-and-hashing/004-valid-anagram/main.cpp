#include <cstdio>
#include <iostream>

using namespace std;

bool isAnagram(string s, string t) {
    int len1 = s.length();
    int len2 = t.length();

    if (len1 != len2) {
        return false;
    }

    int arr1[26] = {0};
    int arr2[26] = {0};

    for (int i = 0; i < len1; i++) {
        arr1[s[i] - 97]++;
        arr2[t[i] - 97]++;
    }

    for (int j = 0; j < 26; j++) {
        if (arr1[j] != arr2[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    string s, t;

    cin >> s >> t;

    printf("%d", isAnagram(s, t));

    return 0;
}
