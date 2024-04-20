#include <bits/stdc++.h>

using namespace std;

/* cantalan Number using Iterative dp */
int catalanNumber( int n ){

	vector<int> dp(n+1);

	dp[0] = dp[1] = 1;

	for(int i = 2 ; i <= n ; i++ ){

		for(int j = 0 ; j <= i ; j++ ){

			dp[i] += dp[j-1]*dp[i-j];
		}
	}

	return dp[n];	
}

/*
	Formula for Catalan Number
	(2n-C-n)/(n+1)
*/

int main(int argc, char* argv[] ){

	cout << catalanNumber(2) << '\n';
	return 0;
}