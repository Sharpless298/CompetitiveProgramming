#include <iostream>
#include <queue>
using namespace std;

int ary[128];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	while (cin >> n && n) {
		queue<int> q;

		for (int i = 1; i <= n; i++)
			q.push(i);

		for (int i = 0; i < n - 1; i++) {
			ary[i] = q.front();
			q.pop();
			q.push(q.front());
			q.pop();
		}

		cout << "Discarded cards:";
		for (int i = 0; i < n - 1; i++) {
			if (i)
				cout << ',';
			cout << ' ';
			cout << ary[i];
		}
		cout << '\n';
		cout << "Remaining card: " << q.front() << '\n';
	}
}
