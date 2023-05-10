#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> alphas = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string w;
    cin >> w;

    for (auto alpha : alphas) {
        while (true) {
            int pos = w.find(alpha);
            if (pos == string::npos) break;
            w.replace(pos, alpha.size(), "1");
        }
    }
    cout << w.size() << '\n';
    return 0;
}

