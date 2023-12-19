#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
bool visited[9];
int n;

void Print() {
    for (auto i : answer)
        cout << i << " ";
    cout << endl;
}

void ReversePermutation(int depth) {
    if (depth == n + 1) {
        Print();
        return;
    }

    for (int i = n; i >= 1; i--) {
        if(visited[i]) continue;
        visited[i] = true;
        answer.push_back(i);
        ReversePermutation(depth + 1);
        visited[i] = false;
        answer.pop_back();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < 9; i++)
        visited[i] = false;
    
    ReversePermutation(1);

    return 0;
}