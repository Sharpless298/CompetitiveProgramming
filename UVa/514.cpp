#include <iostream>
using namespace std;

const int MAXN = 10000;

int stk[MAXN], ary[MAXN], top = -1, k;

void push(int data) {
	stk[++top] = data;
}

void pop() {
	if(top==-1)
		return;
	top--;
}

int query() {
	if(top==-1) return -1;
	return stk[top];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;

	while(cin >> n) {
		if(n==0) {
			cin.ignore();
			break;
		}
		while(cin >> k) {
			if(k==0) {
				cout << '\n';
				break;
			}
			ary[0] = k;
			for(int i=1; i<n; i++)
				cin >> ary[i];

			for(int i=1, j=0; i<=n; i++) {
				push(i);
				while(query()==ary[j]) {
					pop();
					j++;
				}
			}
			if(query()==-1)
				cout << "Yes\n";
			else 
				cout << "No\n";
			top = -1;
		}
	}
}
	
