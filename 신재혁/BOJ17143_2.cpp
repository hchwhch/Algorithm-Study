#include <iostream>
#include <cstring>
#define max_n 104
using namespace std;
struct shark{
    int y, x, s, dir, z, death; //상어의 위치, 상어의 속력, 상어의 방향, 상어의 크기, 상어가 죽었는가
}a[max_n*max_n];
int shark[max_n][max_n], r, c, m, ret, temp[max_n][max_n];
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
        a[i].y--; //modular 연산을 위해서 0부터 시작한다
        a[i].x--;
        a[i].dir--;

        if (a[i].dir <= 1) a[i].s %= (2 * (r - 1));
        else a[i].s %= (2 * (c - 1));
        shark[a[i].y][a[i].x] = i;
    }

    //낚시왕이 상어를 잡는다
    for (int t = 0; t < c; t++) {
        for (int y = 0; y < r; y++) {
            if (shark[y][t]) {
                a[shark[y][t]].death = 1;
                ret += a[shark[y][t]].z;
                shark[y][t] = 0;
                break;
            }
        }
        memset(temp, 0, sizeof(temp));
        //상어가 움직인다!!
        for (int i = 1; i <= m; i++) {
            if (a[i].death) continue;

            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir;
            int ny, nx;

            while (1) {
                //벽을 2번 부딪히는 상황 방지
                ny = y + s * dy[d];
                nx = x + s * dx[d];
                if (0 <= ny && ny < r && 0 <= nx && nx < c) break;
                if (d <= 1) {
                    if (ny < 0) {
                        s -= y;
                        y = 0;
                    }
                    else {
                        s -= r - 1 - y;
                        y = r - 1;
                    }
                }
                else {
                    if (nx < 0) {
                        s -= x;
                        x = 0;
                    }
                    else {
                        s -= c - 1 - x;
                        x = c - 1;
                    }
                }
                d ^= 1; //0->1, 2->3으로 변환
            }
            //한 칸에 상어가 2마리 있을 시에 크기가 큰 상어가 나머지 상어를 잡는다
            if (temp[ny][nx]) {
                if (a[temp[ny][nx]].z < a[i].z) {
                    a[temp[ny][nx]].death = 1;
                    temp[ny][nx] = i;
                }
                else {
                    a[i].death = 1;
                }
            }
            else {
                temp[ny][nx] = i;
            }
            a[i].y = ny;
            a[i].x = nx;
            a[i].dir = d;
        }
        memcpy(shark, temp, sizeof(temp)); //temp를 shark에 저장!
    }
    cout << ret << '\n';
    return 0;
}

