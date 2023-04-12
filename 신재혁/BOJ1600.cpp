#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int k, w, h;
int board[201][201], visited[201][201][31];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int dy2[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int dx2[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
queue < pair<pair<int, int>, int>> q; //h, w, cnt, k값 저장
int bfs() {
    visited[0][0][k] = 1;
    q.push({ {0, 0}, k });

    while (q.size()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int k = q.front().second;

        q.pop();

        if (y == h - 1 && x == w - 1) {
            return visited[y][x][k]-1;
        }

        if (k > 0) {
            //말의 움직임으로 옮기고 싶을 때
            for (int i = 0; i < 8; i++) {
                int ny = y + dy2[i];
                int nx = x + dx2[i];

                if (ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == 1) continue;
                if (visited[ny][nx][k-1]) continue;
                visited[ny][nx][k - 1] = visited[y][x][k] + 1;
                q.push({ { ny, nx }, k -1});
            }
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w || board[ny][nx] == 1) continue;
            if (visited[ny][nx][k]) continue;
            visited[ny][nx][k] = visited[y][x][k] + 1;
            q.push({ {ny, nx}, k });
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs() << '\n';
    return 0;
}

