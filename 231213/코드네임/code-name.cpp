#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_VALUE 100
int min_index;
int min_value = MAX_VALUE;

class Agent {
public:
    string code_name;
    int score;

    Agent(string code_name, int score) {
        this->code_name = code_name;
        this->score = score;
    }
    
    Agent() {}
};

int main() {
    Agent agent[5];
    for (int i = 0; i < 5; i++) {
        cin >> agent[i].code_name >> agent[i].score;
        if (min_value > agent[i].score) {
            min_index = i;
            min_value = agent[i].score;
        }
    }

    cout << agent[min_index].code_name << " " << agent[min_index].score;
    return 0;
}