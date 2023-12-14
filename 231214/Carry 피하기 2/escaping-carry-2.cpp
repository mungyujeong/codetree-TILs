#include <iostream>
#include <string>
#include <climits>

#define MAX_N 20

using namespace std;

int n;
int answer = -1;
string arr[MAX_N];

bool IsCarry(string s1, string s2, string s3) {
    int len = INT_MAX;
    len = min(len, (int)s1.size());
    len = min(len, (int)s2.size());
    len = min(len, (int)s3.size());
    
    for (int i = 0; i < len; i++) {
        if ((s1[s1.size() - i - 1] - '0') + (s2[s2.size() - i -1] - '0') + (s3[s3.size() - i - 1] - '0') >= 10)
            return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 2; i++) 
        for (int j = i + 1; j < n - 1; j++) 
            for (int k = j + 1; k < n; k++) 
                if (!IsCarry(arr[i], arr[j], arr[k])) 
                    answer = max(answer, stoi(arr[i]) + stoi(arr[j]) + stoi(arr[k]));
                
    cout << answer;
    return 0;
}