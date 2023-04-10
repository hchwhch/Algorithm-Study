#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<int> route[200001];
int n, l, s, e, ret, v;
int dist[200001];
queue<int> q;
int bfs(int here) {
    dist[here] = 0;
    q.push(here);

    while (q.size()) {
        int here = q.front();
        q.pop();

        if (here == e) {
            ret = dist[here] - 1>0?dist[here]-1:0;
            return ret;
        }
        for (int there : route[here]) {
            //역과 역 사이의 거리는 관심 X
            if (dist[there] > -1) continue;
            if (there > 100000) dist[there] = dist[here] + 1;
            else dist[there] = dist[here];
            q.push(there);
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= l; i++) {
        while (true) {
            cin >> v;
            if (v == -1) break;
            //다른 정점 혹은 노선과 겹치지 않게 10만을 더함
            route[v].push_back(i + 100000);
            route[i + 100000].push_back(v);
        }
    }
    cin >> s >> e;
    cout << bfs(s) << '\n';
    return 0;
}

