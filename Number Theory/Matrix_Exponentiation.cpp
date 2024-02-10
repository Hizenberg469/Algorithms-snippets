#include <bits/stdc++.h>
#define ll long long int

using namespace std;

const int M = (int)1e9+7;
struct Mat{
    ll m[2][2];

    Mat(){
        memset(m,0,sizeof(m));
    }

    void identity(){
        for(int idx = 0 ; idx < 2 ; idx++ ){
            m[idx][idx] = 1;
        }
    }
};

Mat operator* (Mat m1,Mat m2){
    Mat res;

    for(int i = 0 ; i < 2 ; i++ ){
        for(int j = 0 ; j < 2 ; j++ ){
            for(int k = 0 ; k < 2 ; k++ ){
                res.m[i][j] += m1.m[i][k]*m2.m[k][j];
                res.m[i][j] %= M;
            }
        }
    }

    return res;
}

Mat power(Mat X,ll n){
    Mat res;
    res.identity();

    ll b = n;
    while(b){
        if( b&1 ) res = res*X;
        X = X*X;
        b >>= 1;
    }

    return res;
}

ll fibo(ll n){

    if( n < 2 ) return n;
    Mat res;

    Mat X;
    X.m[0][1] = 1 , X.m[1][0] = 1 , X.m[1][1] = 1;

    res = power(X,n);

    ll fn[2][1];
    fn[0][0]=0,fn[1][0]=1;

    ll fn1[2][1];

    for(int i = 0 ; i < 2 ; i++ ){
        for(int j = 0 ; j < 1 ; j++ ){
            for(int k = 0 ; k < 2 ; k++ ){
                fn1[i][j] = res.m[i][k]*fn[k][j];
                fn1[i][j]%=M;
            }
        }
    }

    return fn1[0][0];
}

ll modSub(ll a,ll b){
    return ((a%M)-(b%M)+M)%M;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        cout << modSub(fibo(m+2),fibo(n+1)) << '\n';
    }
    return 0;
}
