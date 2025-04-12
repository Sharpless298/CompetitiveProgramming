#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool vis[1024];
int dis[1024];
vector<int> primes;
vector<int> prime_factors[1005];

int BFS(int start, int end) {
	if (start == end)
		return 0;
	if (start == 1 || start > end)
		return -1;

	int v, nxt;
	queue<int> q;

	q.push(start);
	vis[start] = true;
	dis[start] = 0;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		if (v == end)
			return dis[v];

		for (int i : prime_factors[v]) {
			nxt = v + i;
			if (nxt <= end && !vis[nxt]) {
				q.push(nxt);
				vis[nxt] = true;
				dis[nxt] = dis[v] + 1;
			}
		}
	}

	return -1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	bool f;
	int id = 1, S, T;

	primes.push_back(2);
	primes.push_back(3);
	for (int i = 4; i <= 1000; i++) {
		f = false;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				f = true;
				break;
			}
		}
		if (!f)
			primes.push_back(i);
	}
	for (int i = 2; i <= 1000; i++)
		for (int j = 0; j < 168 && primes[j] < i; j++)
			if (i % primes[j] == 0)
				prime_factors[i].push_back(primes[j]);

	while (cin >> S >> T && S) {
		memset(vis, 0, sizeof(vis));

		cout << "Case " << id++ << ": " << BFS(S, T) << '\n';
	}
}
