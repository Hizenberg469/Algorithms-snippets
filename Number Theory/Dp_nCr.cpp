#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nCr;
void binomialCoefficient(int n,int k){

	nCr.resize(n+1,vector<int>(k+1,0));

	nCr[1][0] = nCr[1][1] = 1;

	for(int i = 2 ; i <= n ; i++ ){
		for(int j = 0 ; j <= min(i,k) ; j++ ){
			
			if( j == 0 ){
				nCr[i][j] = 1;
				continue;
			}

			if( j == 1 || j == 0 ){
				nCr[i][j] = i;
				continue;
			}

			nCr[i][j] = nCr[i-1][j]+nCr[i-1][j-1];
		}
	}
}

int main(int argc,char* argv[]){

	binomialCoefficient(5,5);

	for(int i = 0 ; i <= 5 ; i++ ){
		for(int j = 0 ; j <= 5 ; j++ ){
			cout << nCr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}