#include <bits/stdc++.h>

using namespace std;

int binary_multiplication(int a , int b,int M=(int)1e9+7){
    int res = 0;
    while( b ){
        if( b&1 ) res += a , res %= M;
        a = 2 * a ; a %= M:
        b >>= 1;
    }

    return res;
}

int main(){

    return 0;
}
