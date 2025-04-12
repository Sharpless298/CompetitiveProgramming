#include <iostream>
using namespace std;

bool f;
int v[100];
string a[10], b[10], c[10];

int cmp(int k) {
	int len = a[k].size();
	int va = 0, vb = 0;
	for (int i = 0; i < len; i++) {
		va += v[a[k][i] - 'A'];
		vb += v[b[k][i] - 'A'];
	}
	return va - vb;
}

int w(int k) {
	if (c[k] == "even")
		return 0;
	else if (c[k] == "up")
		return 1;
	else
		return -1;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 3; i++)
			cin >> a[i] >> b[i] >> c[i];
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 12; k++)
					v[k] = 0;
				if (j == 0)
					v[i] = 1;
				else
					v[i] = -1;
				f = true;
				for (int k = 0; k < 3 && f; k++) {
					if (cmp(k) != w(k)) {
						f = false;
					}
				}
				if (f) {
					cout << (char)('A' + i) << " is the counterfeit coin and it is ";
					if (v[i] == 1)
						cout << "heavy.\n";
					else
						cout << "light.\n";
				}
			}
		}
		if (f)
			continue;
	}
}
