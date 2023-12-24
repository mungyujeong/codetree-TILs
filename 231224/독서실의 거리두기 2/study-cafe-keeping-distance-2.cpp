#include <iostream>
#include <climits>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;

    int answer = 0;
    string str_c = str;
    for (int i = 0; i < n; i++) {
        str_c = str;
        if (str_c[i] == '1') continue;
        str_c[i] = '1';
        
        int dist = INT_MAX;
        for (int j = 0; j < n - 1; j++) {
            if (str_c[j] == '1') {
                for (int k = j + 1; k < n; k++) {
                    if (str_c[k] == '1') {
                        dist = min(dist, k - j);
                        // cout << dist << " " << k << " " << j << endl;
                        break;
                        // cout << dist << " " << k  << " "<< j << endl;
                    }
                }
            }
        }
        answer = max(answer, dist);
        // cout << str_c << ": " << dist << endl;
    }

    cout << answer;
    return 0;
}