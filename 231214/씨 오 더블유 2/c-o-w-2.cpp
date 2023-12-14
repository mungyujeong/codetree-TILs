#include <iostream>
#include <string>

using namespace std;

int n, count;
string str;

int main() {
    cin >> n;
    cin >> str;

    for (int i = 0; i < n - 2; i++) 
        for (int j = i + 1; j < n - 1; j++) 
            for (int k = j + 1; k < n; k++) 
                if (str[i] == 'C' && str[j] == 'O' && str[k] == 'W')
                    count++;
        
    cout << count;
    return 0;
}