#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 100

using namespace std;

int n;
int arr[MAX_N];
int answer = INT_MAX;
vector<int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (int i = 0; i < n; i++) {
        arr[i] *= 2;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) 
                if (j != k)
                    v.push_back(arr[k]);
            

            for (int k = 0; k < n - 2; k++)  
                sum += abs(v[k] - v[k + 1]);
            
            answer = min(answer, sum);
        }
        
        arr[i] /= 2;
        v.clear();
    }

    cout << answer;
    return 0;
}