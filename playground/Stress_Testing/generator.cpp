#include <bits/stdc++.h>

using namespace std;

int rnd(int a,int b){
    return a + rand() % ( b - a + 1 );
}

int main(int argc, char* argv[]){

	int seed = atoi(argv[1]);
    
    srand(seed);

    int n = rnd(1,20);

    int k = rnd(20, 40);

    cout << n << ' ' << k << '\n';

    int val = 0;
    for(int i = 0 ; i < n ; i++ ){

        val = rnd(0,50);

        cout << val << ' ';
    }
    
    cout << '\n';
	return 0;
}