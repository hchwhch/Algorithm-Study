#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int visited[54][54], a[54][54], n, l, r, sum, cnt;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
void dfs(int y, int x, vector<pair<int, int>>& v) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
        if (abs(a[ny][nx] - a[y][x]) >= l && abs(a[ny][nx] - a[y][x]) <= r) {
            visited[ny][nx] = 1;
            v.push_back({ ny, nx });
            sum += a[ny][nx];
            dfs(ny, nx, v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (true) {
        bool flag = 0; //인구 이동 check!!
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    v.clear();
                    v.push_back({ i, j });
                    sum = a[i][j];
                    dfs(i, j, v);
                    if (v.size() == 1) continue;
                    for (pair<int, int> b : v) {
                        a[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag) break;
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}

