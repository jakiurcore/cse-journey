#include <bits/stdc++.h>
#include <string>

using namespace std;

// int ascii(string str) {
//     int x = 0;
//     for (auto i : str) {
//         x += (int)i;
//     }
//
//     return x;
// }

/**
 * First i was trying to ascii count
 * But ascii count can same of the two string so i have go for sort
 */

// vector<vector<string>> groupAnagrams(vector<string> &strs) { // this m * n
// log n
//     unordered_map<string, vector<string>> um;
//     for (auto s : strs) {
//         string x = s;
//         sort(x.begin(), x.end());
//         um[x].push_back(s);
//     }
//
//     vector<vector<string>> vs;
//     for (auto m : um) {
//         vs.push_back(m.second);
//     }
//
//     return vs;
// }

/**
 * I have also tried the O(m * n log n ) solution with sorting
 * We can do it better in O(m * n) using counting method here it is the below
 */
vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> um;

    for (const auto &s : strs) {
        vector<int> v(26, 0);
        for (char i : s) {
            v[i - 'a']++;
        }

        string p;
        for (int c : v) {
            p += to_string(c);
            p += '#';
        }

        um[p].push_back(s);
    }

    vector<vector<string>> vs;
    for (auto &m : um) {
        vs.push_back(std::move(m.second)); // used move for better performance
                                           // moving is faster than copying it
    }

    return vs;
}

int main() {
    vector<string> str;
    int size;
    cin >> size;

    while (size--) {
        string s;
        cin >> s;
        str.push_back(s);
    }

    vector<vector<string>> g = groupAnagrams(str);

    for (auto p : g) {
        for (auto s : p) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
