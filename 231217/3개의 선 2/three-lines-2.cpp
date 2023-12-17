#include <iostream>

#define MAX_N 20
using namespace std;

int n, answer = 0;
int x[MAX_N];
int y[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> x[i] >> y[i];
    

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = j + 1; k <= 10; k++) {
                
                int arr[3] = {i, j, k};
                int checked[MAX_N] = {0, };

                for (int l = 0; l <= 3; l++) {
                    int x_time = l;
                    int y_time = 3 - l;
                    
                    if (x_time) {
                        for (int xt = 0; xt < x_time; xt++) {
                            for (int t = 0; t < n; t++) {
                                if (x[t] == arr[xt])
                                    checked[t] = 1;
                            }
                        }
                    }
                    if (y_time) {
                        for (int yt = x_time; yt < 3; yt++) {
                            for (int t = 0; t < n; t++)
                                if (y[t] == arr[yt])
                                    checked[t] = 1;
                        }
                    }
                    int count = 0;

                    for (int t = 0; t < n; t++) {
                        if (checked[t])
                            count++;
                    }
                    if (count == n)
                        answer = 1;
                }
            }
        }
    }
    cout << answer;
    return 0;
}