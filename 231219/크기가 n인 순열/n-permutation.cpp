#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> answer;
bool visited[9];

void Print() {
    for (auto i : answer) 
        cout << i << " ";
    cout << endl;
}

void Choose(int depth) {
    if (depth == n + 1) {
        Print();
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;
        
        answer.push_back(i);
        visited[i] = true;

        Choose(depth + 1);

        answer.pop_back();
        visited[i] = false;
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < 9; i++)
        visited[i] = false;

    Choose(1);

    return 0;
}