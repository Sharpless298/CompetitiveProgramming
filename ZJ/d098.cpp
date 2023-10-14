#include <iostream>
#include <sstream>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	bool f;
	int ans;
	string s, t, k;
	stringstream ss;

	while(getline(cin, s)) {
		ss.str(s);
		ans = 0;
		while(ss >> t) {
			f = true;
			for(int i=0; i<(int)t.size(); i++)
				if(!(t[i]>='0' && t[i]<='9')) f = false;
			if(f) ans += stoi(t);
		}
		cout << ans << '\n';
		ss.clear();
	}
}
