#include <iostream>
#include <stack>

using namespace std;

string x, y, ans;
stack<char> stk;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;

    int xi, yi;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == '1') {
            xi = i;
            break;
        }
    }

    for (int i = 0; i < y.size(); ++i) {
        if (y[i] == '1') {
            yi = i;
            break;
        }
    }

    x = x.substr(xi);
    y = y.substr(yi);

    string temp = "";
    if (x.size() < y.size()) {
        for (int i = 0; i < y.size() - x.size(); ++i) {
            temp += "0";
        }
        x = temp + x;
    } else if (x.size() > y.size()) {
        for (int i = 0; i < x.size() - y.size(); ++i) {
            temp += "0";
        }
        y = temp + y;
    }

    bool flag = false;
    for (int j = x.size() - 1; j >= 0; --j) {
        if (x[j] == '0' && x[j] == y[j]) {
            if (flag) {
                stk.push('1');
                flag = false;
            } else {
                stk.push('0');
            }
        } else if (x[j] == '1' && x[j] == y[j]) {
            if (flag) {
                stk.push('1');
            } else {
                stk.push('0');
                flag = true;
            }
        } else if (x[j] != y[j]) {
            if (flag) {
                stk.push('0');
            } else {
                stk.push('1');
            }
        }
    }

    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    if (flag) {
        ans = "1" + ans;
    }

    cout << ans << "\n";

    return 0;
}