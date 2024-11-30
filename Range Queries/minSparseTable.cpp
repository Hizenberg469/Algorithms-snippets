#include <bits/stdc++.h>

using namespace std;


//Sparse Table for minimum value query.

vector<vector<int>> table;

void precomputeSparseTable(int n, vector<int>& arr){

	int lPower = log2(n);

	table.resize(n+1,vector<int>(lPower+1));

	for(int p = 0 ; p <= lPower ; p++ ){
		for(int i = 0 ; i + pow(2,p) - 1 <= n ; i++ ){
			if( p == 0 ){
				table[i][p] = arr[i];
				continue;
			}

			table[i][p] = min(table[i][p-1],table[i+pow(2,p-1)][p-1]);
		}
	}

	// for(int i = 0 ; i <= n ; i++ ){
	// 	cout << i << " : ";
	// 	for(int p = 0 ; p <= lPower ; p++ ){
	// 		cout << table[i][p] << " ";
	// 	}
	// 	cout << endl;
	// }
}

int main(int argc,char* argv[]){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,q;
	cin>>n>>q;

	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++ ){
		cin>>arr[i];
	}

	precomputeSparseTable(n,arr);
}