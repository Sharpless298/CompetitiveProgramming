#include <iostream>
using namespace std;

int f(int x, int y) {
	return x*m + y;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				cin >> G1[i][j];

		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(i+1 < n) {
					G2[f(i, j)].push_back(f(i+1, j));
								
				}

			}
		}
	}
}
