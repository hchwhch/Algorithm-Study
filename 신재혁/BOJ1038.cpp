#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

		int last = num % 10; //마지막 수 뽑기
		for (int i = 0; i < last; i++) {
			long long ret = num * 10 + i;
			q.push(ret);
			v.push_back(ret);
		}
	}
	if (target >= v.size()) {
		//범위 초과할 때
		cout << -1 << '\n';
	}
	else {
		cout << v[target] << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	func(n);


}

