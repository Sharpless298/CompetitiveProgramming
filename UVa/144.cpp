#include <iomanip>
#include <iostream>
#include <queue>

using namespace std;

bool f = false;
int n, k, temp = 0, cur;
int stu[30];
queue<int> que;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n >> k && n) {
		cur = 0;
		temp = 0;
		f = false;
		for (int i = 1; i <= n; i++)
			que.push(i);
		fill(stu, stu + n + 1, 40);

		while (!que.empty()) {
			if (!f) {
				cur = (cur + 1) % (k + 1);
				if (cur == 0)
					cur++;
				temp = cur;
			}
			f = false;
			int i = que.front();
			if (stu[i] < temp) {
				cout << setw(3) << i;
				que.pop();
				temp -= stu[i];
				f = true;
			} else {
				stu[i] -= temp;
				if (stu[i] == 0)
					cout << setw(3) << i;
				else
					que.push(i);
				que.pop();
			}
		}
		cout << '\n';
	}
}
