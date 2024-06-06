#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-6;

struct Edge {
	int u, w;
};

int n, m;
int G[1005][1005], dis[1005];

double Prim(int t) {
	int res = 0;

	dis[0] = 0;
	for(int i=0; i<n; i++) {
		v = -1;
		for(int j=0; j<n; j++) 
			if(!vis[j] && (v == -1 || dis[j] < dis[v]))
				v = j;

		if(dis[v] == INF) {
			cout << "NO MST\n";
			return;
		}

		vis[v] = true;
		res += dis[v];
		cout << v << ' ' << dis[v] << '\n';

		for(int j=0; j<n; j++) 
			dis[j] = min(dis[j], G[v][j]);
	}

	return res;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	

	while(cin >> n >> m) {
		memset(dis, 0x3f, sizeof(dis));

		double l = 0, r = 1<<32, m;

		while(r-l < EPS) {
			m = (l+r)/2;

			if(Prim(m) > 0) l = m;
			else r = m;
		}
	}
}

