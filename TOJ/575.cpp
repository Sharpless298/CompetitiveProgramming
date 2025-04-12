#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;

int N, K, a, b;
vector<int> v[MAXN];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			if (j)
				cout << ' ';
			cout << v[i][j];
		}
		cout << '\n';
	}
}
