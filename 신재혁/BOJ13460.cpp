#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, visited[15][15][15][15], ret;
char board[15][15];
struct marble {
    int ry, rx; //빨간 구슬 좌표
    int by, bx; //파란 구슬 좌표
    int d; //기울인 횟수
};
marble start;
queue<marble> q;
int bfs() {
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    q.push(start);

    while (q.size()) {
        marble cur = q.front();
        q.pop();

        if (cur.d > 10) break;
        if (board[cur.ry][cur.rx] == 'O' && board[cur.by][cur.bx] != 'O') {
            ret = cur.d;
            return ret;
        }
        for (int i = 0; i < 4; i++) {
            int nry = cur.ry;
            int nrx = cur.rx;
            int nby = cur.by;
            int nbx = cur.bx;

            while (true) {
                if (board[nry][nrx] != '#' && board[nry][nrx] != 'O') {
                    nry += dy[i];
                    nrx += dx[i];
                }
                else {
                    if (board[nry][nrx] == '#') {
                        nry -= dy[i];
                        nrx -= dx[i];
                    }
                    break;
                }
            }
            while (true) {
                if (board[nby][nbx] != '#' && board[nby][nbx] != 'O') {
                    nby += dy[i];
                    nbx += dx[i];
                }
                else {
                    if (board[nby][nbx] == '#') {
                        nby -= dy[i];
                        nbx -= dx[i];
                    }
                    break;
                }
            }
            if (nry == nby && nrx == nbx) {
                //같은 위치일때
                if (board[nry][nrx] != 'O') {
                    //구멍에 동시에 빠지면 -1
                    int red_dist = abs(nry - cur.ry) + abs(nrx - cur.rx);
                    int blue_dist = abs(nby - cur.by) + abs(nbx - cur.bx);
                    if (red_dist > blue_dist) {
                        nry -= dy[i];
                        nrx -= dx[i];
                    }
                    else {
                        nby -= dy[i];
                        nbx -= dx[i];
                    }
                }
            }
            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = 1;
                marble next;
                next.ry = nry;
                next.rx = nrx;
                next.by = nby;
                next.bx = nbx;
                next.d = cur.d + 1;
                q.push(next);
            }
        }
        
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j] = str[j];
            if (board[i][j] == 'R') {
                start.ry = i;
                start.rx = j;
            }
            if (board[i][j] == 'B') {
                start.by = i;
                start.bx = j;
            }
        }
    }
    start.d = 0;
    cout << bfs() << '\n';
    return 0;

    

}
