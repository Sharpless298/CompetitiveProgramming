//By Koios1143
#include<iostream>
using namespace std;
int R, ans, Case=1;
int arr[9][9], small_sq[9][10], row[9][10], col[9][10], nxt_x[90], nxt_y[90];

// 先計算三種情況每個數字出現的數量
// 順便先判斷出一開始即不符合的情況
bool check(){
	bool res=true;
	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<10 ; j++){
			small_sq[i][j] = row[i][j] = col[i][j] = 0;
		}
	}
	
	for(int i=0 ; i<9 ; i++){
		for(int j=0 ; j<9 ; j++){
			if(arr[i][j] != 0){
				// 3*3 方格從左至右、從上至下依序編號 1~9
				small_sq[3*(i/3)+(j/3)][arr[i][j]]++;
				row[i][arr[i][j]]++;
				col[j][arr[i][j]]++;
				if(small_sq[3*(i/3)+(j/3)][arr[i][j]]>1 || row[i][arr[i][j]] > 1 || col[j][arr[i][j]] > 1)
					res=false;
			}
		}
	}
	return res;
}

void DFS(int depth){
	if(depth == R){
		ans++;
		if(ans > 1){
			return;
		}
	}
	int i = nxt_x[depth];
	int j = nxt_y[depth];
	for(int k=1 ; k<=9 ; k++){
		if(small_sq[3*(i/3)+(j/3)][k]>0 || row[i][k] > 0 || col[j][k] > 0)
			continue;
		small_sq[3*(i/3)+(j/3)][k]++;
		row[i][k]++;
		col[j][k]++;
		DFS(depth+1);
		small_sq[3*(i/3)+(j/3)][k]--;
		row[i][k]--;
		col[j][k]--;
	}
}

int main(){
	while(cin>>arr[0][0]){
		// R 記錄空格子的數量
		// nxt_x, nxt_y 記錄空格的座標
		if(arr[0][0] == 0) nxt_x[0]=0, nxt_y[0]=0, R = 1;
		else R = 0;
		ans=0;
		for(int i=0 ; i<9 ; i++){
			for(int j=0 ; j<9 ; j++){
				if(i==0 && j==0) continue;
				cin>>arr[i][j];
				if(arr[i][j] == 0) nxt_x[R]=i, nxt_y[R]=j, R++;
			}
		}
		if(check() == false){
			cout<<"Case "<<Case++<<": Illegal.\n";
		}
		else{
			DFS(0);
			if(ans == 1){
				cout<<"Case "<<Case++<<": Unique.\n";
			}
			else if(ans > 1){
				cout<<"Case "<<Case++<<": Ambiguous.\n";
			}
			else{
				cout<<"Case "<<Case++<<": Impossible.\n";
			}
		}
	}

	return 0;
}

