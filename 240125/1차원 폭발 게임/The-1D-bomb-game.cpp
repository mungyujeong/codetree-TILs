#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100

using namespace std;

int n, m;
int bomb[MAX_N];

bool is_possible() {
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (bomb[i] == bomb[i + 1]) cnt++;
        else if (cnt >= m) return true;
        else cnt = 1;
    }
    if (cnt >= m) return true;
    return false;
}

void update() {
    vector<pair<int, int>> v;
    int st, en;
    st = en = 0;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {
        if (bomb[i] == bomb[i + 1]) {
            cnt++;
            en++;
        }
        else {
            if (cnt < m) v.push_back({st, en});
            cnt = 1;
            st = en = i + 1;
        }
    }
    if (cnt < m) v.push_back({st, en});

    int idx = 0;
    int tmp[MAX_N];
    for (int i = 0; i < v.size(); i++) {
        tie(st, en) = v[i];
        // cout << st << ' ' << en << endl;
        for (int j = st; j <= en; j++) 
            tmp[idx++] = bomb[j];
    }

    for (int i = 0; i < idx; i++) 
        bomb[i] = tmp[i];
    
    n = idx;

    // cout << "===============\n";
    // cout << "n: " << n << endl;
    // for (int i = 0; i < n; i++)
    //     cout << bomb[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> bomb[i];
    
    while (is_possible()) {
        update();
    }

    // cout << "result=======\n";
    cout << n << '\n';
    for (int i = 0; i < n; i++)
        cout << bomb[i] << '\n';
}