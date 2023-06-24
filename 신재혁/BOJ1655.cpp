#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
//1. 최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 크다
//2. 최대 힙의 최대 원소는 최소 힙의 최소 원소보다 작거나 같다
//이 2 규칙에 어긋나면 최대 힙, 최소 힙의 가장 위의 값을 swap 해준다->항상 최대 힙의 top값이 중간값
int n, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> num;

		//1번 규칙
		if (max_heap.empty()) {
			max_heap.push(num);
		}
		else if (max_heap.size() == min_heap.size()) {
			max_heap.push(num);
		}
		else min_heap.push(num);

		//2번 규칙
		if (!max_heap.empty() && !min_heap.empty() && !(max_heap.top() <= min_heap.top())) {
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}
		cout << max_heap.top() << '\n';
	}
	return 0;
}

