#include <iostream>
#include <string>

using namespace std;

string str = "ABC";
string tmp = "ABC";
int n;
int arr[3] = {};
int answer = 0;

void UpdateRanking() {
    int max_value = arr[0];
    string result = "A";

    for (int i = 1; i < 3; i++) {
        if (max_value == arr[i]) {
            result.push_back(i + 'A');
        } else if (max_value < arr[i]) {
            result = i + 'A';
            max_value = arr[i];
            // cout << "max_value < arr: " << result << endl;
        }
    }

    str = result;
    // cout << str << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int score;
        cin >> c >> score;
        arr[c - 'A'] += score;

        UpdateRanking();

        if (str != tmp) {
            tmp = str;
            answer++;
        }
    }

    cout << answer;
    return 0;
}