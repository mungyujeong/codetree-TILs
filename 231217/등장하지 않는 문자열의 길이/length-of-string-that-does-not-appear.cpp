#include <iostream>
#include <string>
#include <climits>

using namespace std;

int n, answer = INT_MAX;
string input;

int main() {
    cin >> n;
    cin >> input;
    // cout << input.substr(0, 2) <<endl;


    for (int length = 1; length <= n; length++) {
        bool check = false;
        for (int start = 0; start <= n - length; start++) {
            string findStr = input.substr(start, length);
            
            for (int i = start; i <= n - length; i++) {
                if (i == start) continue;
                // cout << "start, i, length: " << start << " " << i << " " << length << endl;
                // cout << findStr << "  " << input.substr(i, length) << endl;
                if (findStr == input.substr(i, length)) 
                    check = true;
            }
            if (check) break;
        }
        if (!check)
            answer = min(answer, length);
    }
    cout << answer;
    
    return 0;
}