#include <iostream>
#include <queue>
#include <vector>

#define MAX_N 100
#define MAX_M 100
using namespace std;

int N, M;
int arr[MAX_N][MAX_M], cost[MAX_N][MAX_M];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string str;
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> str;
        for (int j = 0; j < M; ++j) {
            if (str[j] == '0') {
                arr[i][j] = 0;
            } else if (str[j] == '1') {
                arr[i][j] = 1;
            }
            cost[i][j] = 0;
        }
    }

    q.push({0, 0});
    cost[0][0] = 1;
    int cnt = 1;

    while (!q.empty()) {
        for (int i = 0; i < 4; ++i) {
            int parent_x = q.front().first;
            int parent_y = q.front().second;

            int x = parent_x + dir[i][0];
            int y = parent_y + dir[i][1];

            if (x >= 0 && x < N && y >= 0 && y < M) {
                if (arr[x][y] == 1 && cost[x][y] == 0) {
                    q.push({x, y});
                    cost[x][y] = cost[parent_x][parent_y] + 1;
                }
            }
        }
        q.pop();
    }

    cout << cost[N - 1][M - 1] << "\n";

    return 0;
}
