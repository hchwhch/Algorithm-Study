#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<long long> q;
vector<long long> v;
int n;
void func(int target) {
    for (int i = 0; i <= 9; i++) {
        q.push(i);
        v.push_back(i);
    }

    while (q.size()) {
        long long num = q.front();
        q.pop();

        int last = num % 10;
        for (int i = 0; i < last; i++) {
            long long ret = num * 10 + i;
            q.push(ret);
            v.push_back(ret);
        }
    }
    if (target >= v.size()) {
        cout << -1 << '\n';
    }
    else cout << v[target] << '\n';

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    func(n-1);
    return 0;
}

