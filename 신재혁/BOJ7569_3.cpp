#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int dy[] = { -1, 0, 1, 0, 0, 0 };
const int dx[] = { 0, 1, 0, -1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, 1, -1 };
queue<pair<pair<int, int>, int>> q;
int m, n, h, visited[102][102][102], board[102][102][102], ret=0;
void bfs() {
    while (q.size()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int z = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + dz[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || nz < 0 || nz >= h) continue;
            if (visited[ny][nx][nz] >= 0) continue;
            visited[ny][nx][nz] = visited[y][x][z] + 1;
            q.push({ {ny, nx}, nz });
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1) {
                    //익은 토마토일 경우
                    q.push({ {i, j}, k });
                }
                if (board[i][j][k] == 0) {
                    //익지 않은 토마토
                    visited[i][j][k] = -1;
                }
            }
        }
    }
    bfs();
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j][k] == -1) {
                    cout << -1 << '\n';
                    return 0;
                }
                ret = max(ret, visited[i][j][k]);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

