#include <iostream>
#include <unordered_set>
#include <string>

#define MAX_N 500
#define MAX_M 50

using namespace std;

int n, m;
char arr_a[MAX_N][MAX_M];
char arr_b[MAX_N][MAX_M];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr_a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr_b[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < m - 2; i++) {
        for (int j = i + 1; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {

                bool possible = true;
                unordered_set<string> set;

                for (int t = 0; t < n; t++) {
                    string tmp;
                    tmp.push_back(arr_a[t][i]);
                    tmp.push_back(arr_a[t][j]);
                    tmp.push_back(arr_a[t][k]);
                    set.insert(tmp);
                    // cout << tmp << " ";
                }
                // cout << endl;

                for (int t = 0; t < n; t++) {
                    string tmp;
                    tmp.push_back(arr_b[t][i]);
                    tmp.push_back(arr_b[t][j]);
                    tmp.push_back(arr_b[t][k]);

                    // cout << tmp << endl;

                    if (set.find(tmp) != set.end()) {
                        possible = false;
                        break;
                    }
                }

                if (possible) answer++;
            }

        }
    }

    cout << answer;

    return 0;
}