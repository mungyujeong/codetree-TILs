#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

string input;
int operate_size = 0;
int alpha_size = 0;
vector<char> v;
vector<int> selected_number;
int answer = INT_MIN;
int alpha_count[6] = {0, };
int alpha_recursive[6] = {0, };
vector<int> expression;

int operate(int a, int b, char o) {
    if (o == '+') {
        return a + b;
    } else if (o == '-') {
        return a - b;
    } else {
        return a * b;
    }
}

int GetCount() {
    // for (auto i : selected_number)
    //     cout << i << " ";
    // cout << endl;

    // cout << "alpha count: ";
    // for (int i = 0; i < 6; i++)
    //     cout << alpha_count[i] << " ";
    // cout << endl;

    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        if (alpha_count[i] > 0) {
            alpha_recursive[i] = selected_number[cnt++];
        }
    }

    // cout << "recursive: ";
    // for (int i = 0; i < 6; i++) {
    //     cout << alpha_recursive[i] << " ";
    // }
    // cout << endl;
    // cout << expression[0] << " " << expression[1] << endl;
    int a = alpha_recursive[expression[0]];
    int b = alpha_recursive[expression[1]];
    int result = operate(a, b, v[0]);
    // cout << result << " " << expression[2] << " ";

    for (int i = 1; i < v.size(); i++) {
        int a = result;
        int b = alpha_recursive[expression[i + 1]];
        result = operate(a, b, v[i]);
    }
    // cout << "result: " << result << endl;

    return result;
}

void Recursive(int depth) {
    if (depth == alpha_size) {

        answer = max(answer, GetCount());
        return;
    }

    for (int i = 1; i <= 4; i++) {
        selected_number.push_back(i);
        Recursive(depth + 1);
        selected_number.pop_back();
    }
}

int main() {
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] < 'a' || input[i] > 'f') 
            v.push_back(input[i]);
        else {
            alpha_count[input[i] - 'a']++;
            expression.push_back(input[i] - 'a');
        }
    }
    operate_size = v.size();

    for (int i = 0; i < 6; i++)
        if (alpha_count[i] > 0)
            alpha_size++;

    Recursive(0);

    cout << answer;
    return 0;
}