#include <iostream>
#include <algorithm>
using namespace std;
const int dy[] = { 0, -1, 0, 1 };
const int dx[] = { -1, 0, 1, 0 };
int visited[51][51], a[51][51], cnt, compSize[2504], n, m, mx, big;
int dfs(int y, int x, int cnt) {
    if (visited[y][x]) return 0; //visited[ny][nx] continue와 같다
    visited[y][x] = cnt;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        if (!(a[y][x] & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                cnt++; //각 영역에 id부여
                compSize[cnt] = dfs(i, j, cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + 1 < m) {
                //overflow check!!
                int a = visited[i + 1][j]; //벽 부순것!
                int b = visited[i][j];
                if (a != b) {
                    //다른 영역이구나!!
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
            if (j + 1 < n) {
                //overflow check!!
                int a = visited[i][j + 1];
                int b = visited[i][j];
                if (a != b) {
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }
    cout << cnt << '\n' << mx << '\n' << big << '\n';
    return 0;
}

