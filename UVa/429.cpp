#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool vis[205];
int dis[205];
vector<string> G[205];

bool check(int len, string a, string b) {
	int cnt = 0;

	for (int i = 0; i < len; i++)
		if (a[i] != b[i])
			cnt++;

	if (cnt == 1)
		return true;
	return false;
}

int BFS(int len, int start, string end) {
	int v;
	queue<int> q;

	q.push(start);
	vis[start] = true;
	dis[start] = 0;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		if (G[len][v] == end)
			return dis[v];

		for (int i = 0; i < (int)G[len].size(); i++) {
			if (!vis[i] && check(len, G[len][v], G[len][i])) {
				q.push(i);
				vis[i] = true;
				dis[i] = dis[v] + 1;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, len, start, space, f = 0;
	string temp, a, b;

	cin >> t;
	cin.ignore();

	while (t--) {
		if (f++)
			cout << '\n';

		while (getline(cin, temp)) {
			if (temp == "*")
				break;
			else
				G[temp.size()].push_back(temp);
		}

		while (getline(cin, temp)) {
			if (temp == "")
				break;

			memset(vis, 0, sizeof(vis));

			space = (int)temp.find(" ");
			a = temp.substr(0, space);
			b = temp.substr(space + 1);
			len = (int)a.size();
			for (int i = 0; i < (int)G[len].size(); i++) {
				if (a == G[len][i]) {
					start = i;
					break;
				}
			}

			cout << a << ' ' << b << ' ' << BFS(len, start, b) << '\n';
		}
	}
}
