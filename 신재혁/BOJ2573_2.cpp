#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n, m;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int board[301][301], visited[301][301], tmp[301][301];
queue<pair<int, int>> q;
void bfs(int y, int x) {
    visited[y][x] = 1;
    q.push({ y, x });

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m||board[ny][nx]==0) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
        }
    }
}
void melt() {
    memset(tmp, 0, sizeof(tmp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) continue;
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                if (board[ny][nx] == 0) cnt++;
            }
            int val = board[i][j] - cnt;
            if (val > 0) tmp[i][j] = val;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = tmp[i][j];
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int t = 0;
    while (true) {
        memset(visited, 0, sizeof(visited));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j);
                    count++;
                }
            }
        }

        if (count == 0) {
            cout << 0 << '\n';
            break;
        }
        else if (count >= 2) {
            cout << t << '\n';
            break;
        }
        t++;
        melt();
    }
    return 0;
}

