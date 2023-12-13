#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_N 100

string input;
int answer;

int main() {
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(') {
            for (int j = i; j < input.size(); j++) {
                if (input[j] == ')') 
                    answer++;
            }
        }
    }

    cout << answer;
    return 0;
}