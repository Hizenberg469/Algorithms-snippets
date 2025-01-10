#include <bits/stdc++.h>

using namespace std;

int rnd(int a,int b){
    return a + rand() % ( b - a + 1 );
}

int main(int argc, char* argv[]){

	int seed = atoi(argv[1]);
    
    srand(seed);

    int n = rnd(1,3);

    int k = rnd(1,6);

    int l1 = rnd(1,4);

    int r1 = rnd(l1,8);

    int l2 = rnd(l1, 8);

    int r2 = rnd(l2,10);

    if( rand() % 2 == 0 ){
        swap(l1,l2);
        swap(r1,r2);
    }

    cout << 1 << '\n';
    cout << n << ' ' << k << '\n';
    cout << l1 << ' ' << r1 << '\n';
    cout << l2 << ' ' << r2 << '\n';
    
    // cout << '\n';
	return 0;
}