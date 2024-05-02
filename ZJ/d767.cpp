#include <iostream>
#include <vector>
using namespace std;

int t, N, Q, lgN, ans, a, b;
int ac[16][30005], in[30005], out[30005];
vector<int> G[30005];

int pow(int x, int y) {
	int res = 1;
	for(int i=0; i<y; i++) res*=x;
	return res;
}

bool ancestor(int u, int v) {
	if(in[u]<=in[v] && out[u]>=out[v]) return true;
	return false;
}

void DFS(int u) {
	in[u] = ++t;
	for(int i:G[u]) 
		ac[0][i] = u, DFS(i);
	out[u] = t;
}

int LCA(int u, int v) {
	if(ancestor(u, v)) return u;

	for(int i=lgN; i>=0; i--) 
		if(!ancestor(ac[i][u], v)) u = ac[i][u], ans+=pow(2, i);
	ans++;
	return ac[0][u];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> Q;
	for(int i=1, k; i<=N; i++) 
		while(cin>>k && k) G[i].push_back(k);
	
	lgN = __lg(N);
	ac[0][1] = 1;
	DFS(1);
	for(int i=1; i<=lgN; i++)
		for(int j=1; j<=N; j++)
			ac[i][j] = ac[i-1][ac[i-1][j]];

	for(int i=0, lca; i<Q; i++) {
		ans = 0;

		cin >> a >> b;
		
		lca = LCA(a, b);
		for(int j=lgN; j>=0; j--)
			if(!ancestor(ac[j][b], lca)) b = ac[j][b], ans+=pow(2, j);
		if(b != lca) ans++;

		cout << lca << ' ' << ans << '\n';
	}
}
