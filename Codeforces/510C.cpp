#include <iostream>
using namespace std;

bool vis[32], e[32][32];
string s[105];

int get(char c) {
	if(c == ' ') return 0;
	return c - 'a' +1;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s[i];
		s[i] += ' ';
	}
	for(int i=1; i<=26; i++)
		e[0][i] = true;

	for(int i=0; i<n-1; i++) {
		int j = 0;
		while(s[i][j] == s[i+1][j]) j++;
		e[get(s[i][j])][get(s[i+1][j])] = true;
	}
	
	for(int k=0; k<=26; k++)
		for(int i=0; i<=26; i++)
			for(int j=0; j<=26; j++)
				e[i][j] |= e[i][k] & e[k][j];

	bool f = false;
	for(int i=0; i<=26; i++)
		f |= e[i][i];

	if(f) 
		cout << "Impossible\n";
	else {
		for(int i=0; i<=26; i++) {
			int now = 0;

			for(int j=0; j<=26; j++) {
				f = !vis[j];
				for(int k=0; k<=26; k++) 
					if(e[k][j] && !vis[k]) f = false;
				if(f) {
					now = j;
					break;
				}
			}
			
			if(i > 0) cout << (char)('a'+now-1);
			vis[now] = true;
		}
		cout << '\n';
	}
}
