#include <iostream>
#include <utility>
#include <tuple>

#define DIR_NUM 4
#define GRID_SIZE 100

using namespace std;

// 전역 변수 선언:
int n;

// 현재 드래곤 커브를 이루고 있는 점들의 위치를 나타내는 배열입니다.
bool dragon_point[GRID_SIZE + 1][GRID_SIZE + 1];

// 현재 세대에서 새롭게 그려지는 드래곤 커브 점들을 나타내는 배열입니다.
bool new_dragon_point[GRID_SIZE + 1][GRID_SIZE + 1];

// 최종적으로 그려지는 드래곤 커브들의 점들을 나타내는 배열입니다.
bool paper[GRID_SIZE + 1][GRID_SIZE + 1];

// (x, y)점을 (center_x, center_y)를 기준으로 
// 시계방향으로 90' 회전변환 했을 떄의 좌표값을 반환합니다.
pair<int, int> Rotate(int x, int y, int center_x, int center_y) {
    return make_pair(y - center_y + center_x, center_x - x + center_y);
}

// (center_x, center_y) 위치를 기준으로
// dragon point 점들을 전부 시계 방향으로
// 90' 회전변환 시켜 해당 위치에 점을 추가합니다.
void Simulate(int center_x, int center_y) {
    // 새로운 dragon point 값을 초기화 합니다.
    for(int i = 0; i <= GRID_SIZE; i++)
        for(int j = 0; j <= GRID_SIZE; j++)
            new_dragon_point[i][j] = false;
    
    for(int i = 0; i <= GRID_SIZE; i++)
        for(int j = 0; j <= GRID_SIZE; j++)
            if(dragon_point[i][j]) {
                int next_x, next_y;
                tie(next_x, next_y) = Rotate(i, j, center_x, center_y);
                
                new_dragon_point[next_x][next_y] = true;
            }
    
    // 새로운 dragon point들을 현재 dragon point에 추가합니다.
    for(int i = 0; i <= GRID_SIZE; i++)
        for(int j = 0; j <= GRID_SIZE; j++)
            if(new_dragon_point[i][j])
                dragon_point[i][j] = true;
}


void DrawDragonCurve(int x, int y, int d, int g) {
    // dragon_point 값을 초기화 합니다.
    for(int i = 0; i <= GRID_SIZE; i++)
        for(int j = 0; j <= GRID_SIZE; j++)
            dragon_point[i][j] = false;
    
    int dx[DIR_NUM] = {0, -1, 0, 1};
    int dy[DIR_NUM] = {1, 0, -1, 0};
    
    // 0차 드래곤 커브를 만듭니다.
    int start_x = x, start_y = y;
    int end_x = x + dx[d], end_y = y + dy[d];
    dragon_point[start_x][start_y] = true;
    dragon_point[end_x][end_y] = true;
    
    // g번에 걸쳐 드래곤 커브를 확장시킵니다.
    while(g--) {
        // 드래곤 커브를 확장시킵니다.
        Simulate(end_x, end_y);
        
        // 현재 드래곤 커브의 마지막 위치를 갱신합니다.
        tie(end_x, end_y) = Rotate(start_x, start_y, end_x, end_y);
    }
    
    // g차 드래곤 커브 점들을 paper에 전부 표시해줍니다.
    for(int i = 0; i <= GRID_SIZE; i++)
        for(int j = 0; j <= GRID_SIZE; j++)
            if(dragon_point[i][j])
                paper[i][j] = true;
}

int main() {
    // 입력:
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        DrawDragonCurve(x, y, d, g);
    }

    int ans = 0;
    
    // 4개의 꼭지점이 전부 드래곤 커브의
    // 일부인 칸의 개수를 셉니다.
    for(int i = 0; i < GRID_SIZE; i++)
        for(int j = 0; j < GRID_SIZE; j++)
            if(paper[i][j] && paper[i][j + 1] && 
               paper[i + 1][j] && paper[i + 1][j + 1])
                ans++;
    
    // 출력:
    cout << ans;

    return 0;
}