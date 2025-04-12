#include <cstring>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef long long int lli;

const int MAXN = 1e6 + 5;
const int INF = 1e7;

int n, t, k, id;
string s;
bool inq[10005];
int team[1000005];
queue<lli> q;
queue<lli> cur[10005];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n) {
		memset(inq, 0, sizeof(inq));
		memset(team, 0, sizeof(team));
		while (!q.empty())
			q.pop();
		for (int i = 0; i < 10005; i++)
			while (!cur[i].empty())
				cur[i].pop();

		cout << "Line #" << ++id << '\n';

		for (int i = 1; i <= n; i++) {
			cin >> t;
			for (int j = 0; j < t; j++) {
				cin >> k;
				team[k] = i;
			}
		}

		while (cin >> s) {
			if (s[0] == 'S')
				break;
			else if (s[0] == 'E') {
				cin >> t;

				if (t >= 1000000 || team[t] == 0)
					q.push(10000 + t);
				else {
					if (!inq[team[t]]) {
						q.push(team[t]);
						inq[team[t]] = true;
					}
					cur[team[t]].push(t);
				}
			} else {
				if (q.front() >= 10000) {
					cout << q.front() - 10000 << '\n';
					q.pop();
				} else {
					cout << cur[q.front()].front() << '\n';
					cur[q.front()].pop();
					if (cur[q.front()].empty()) {
						inq[q.front()] = false;
						q.pop();
					}
				}
			}
		}
	}
}
