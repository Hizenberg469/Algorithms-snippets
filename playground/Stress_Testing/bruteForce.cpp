#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 9;

int n, k, h;
int need = int(1e9);
int cnt[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        h = max(h, x);
        need = min(need, x);
        ++cnt[x];
    }
    
    int pos = N - 1;
    int res = 0;
    long long sum = 0;
    int c = 0;
    while(true){
        long long x = sum - c * 1LL * (pos - 1);
        if(x > k){
            ++res;
            h = pos;
            sum = pos * 1LL * c;
        }   
    
        --pos;
        if(pos == need) break;
        c += cnt[pos];
        sum += cnt[pos] * 1LL * pos;
    }
    
    if(h != need) ++res;
    
    cout << res << endl;
}