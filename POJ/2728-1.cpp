#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

#define abs(x) (x < 0 ? -(x) : (x))

struct Node {
	int x, y, z;
};

const double EPS = 1e-6;

bool vis[1005];
int n;
double dis[1005];
Node G[1005];

double f(int u, int v) {
	return sqrt(1.0 * (G[u].x - G[v].x) * (G[u].x - G[v].x) + 1.0 * (G[u].y - G[v].y) * (G[u].y - G[v].y));
}

double Prim(double t) {
	int v;
	double res = 0;

	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
		dis[i] = abs(G[i].z - G[0].z) - f(i, 0) * t;

	vis[0] = true;
	for (int i = 0; i < n - 1; i++) {
		v = -1;
		for (int j = 0; j < n; j++)
			if (!vis[j] && (v == -1 || dis[j] < dis[v]))
				v = j;

		vis[v] = true;
		res += dis[v];

		for (int j = 0; j < n; j++)
			if (!vis[j])
				dis[j] = min(dis[j], abs(G[j].z - G[v].z) - f(j, v) * t);
	}

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed << setprecision(3);

	while (cin >> n && n) {
		for (int i = 0; i < n; i++)
			cin >> G[i].x >> G[i].y >> G[i].z;

		double l = 0, r = 100, m;
		while (r - l > EPS) {
			m = (l + r) / 2;

			if (Prim(m) < 0)
				r = m;
			else
				l = m;
		}

		cout << l << '\n';
	}
}
