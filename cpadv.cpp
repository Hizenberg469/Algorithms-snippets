#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

// template<typename T>
// using indexed_multiset = tree<T , null_type ,  less_equal<T> , rb_tree_tag ,
            // tree_order_statistics_node_update>;
// template<typename T>
// using indexed_set=tree<T,null_type,less<T>,rb_tree_tag,
            // tree_order_statistics_node_update>;

#define ld             long double
#define ll             long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define sll               set <ll>
#define vi             vector <int>
#define vll               vector <ll>
#define pii            pair <int, int>
#define pll               pair <ll,ll>
#define vpi            vector <pii>
#define vpl               vector <pll>
#define mii            map <int, int>
#define mll               map <ll,ll>
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define que_max        priority_queue <int>
#define que_max_ll     priority_queue <ll>
#define que_min        priority_queue <int, vi, greater<int>>
#define que_min_ll     priority_queue <ll , vll, greater<ll>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(i,a,x,y)  for(auto i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define scan(s,e,a)    for(auto i = s ; i <= e ; i++ ) cin>>a[i]
#define loop(i,s,e,weight)      for(auto i = s ; (weight>=0? i <= e : i >= e ) ; i+=weight )
#define read(n)           ll n; cin>>n
#define endl           '\n'
#define ALGO_START      clock_t z = clock()
#define ALGO_END        cout << "RUN TIME : " << fixed << setprecision(6) << ((double)(clock() - z))/CLOCKS_PER_SEC

//endl -> cout << '\n' << flush;//hence,slower.
//for interactive problem.
// cout << flush; //for cin cout
// fflush(stdout); //for scanf printf.

//In Mathematics section of cp course.

template<typename T>
T modMul(T a,T b,T M=(int)1e9+7){
    return ((a%M)*(b%M))%M;
}

template<typename T>
inline T power(T a, T b, T M)
{
    T x = 1;
    while (b)
    {
        if (b & 1) x = modMul(x,a,M);
        a = modMul(a,a,M);
        b >>= 1;
    }
    return x;
}

template <typename T>
inline T pwr(T a, T b)
{
    T x = 1;
    while (b)
    {
        if (b & 1) x = x*a;
        a = a*a;
        b >>= 1;
    }
    return x;
}

//Square root using advanced binary search.
template <typename T>
ld sq_root(T x){

    ld err = 1e-6;

    ld ans;
    ld low = 1.0 , high = x;
    for(int i = 1 ; i <= 40 ; i++ ){
        ld mid = low + (high - low)/2.0;

        if( mid*mid <= x ){
            ans = mid;
            low = mid + err;
        }
        else{
            high = mid - err;
        }
    }

    return ans;
}


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << "  "; __f (comma + 1, args...);
}

/*******************************************************************Debugging tools *************************************************/
#define dbg(x...) cerr << #x << " "; _print(x); cerr << endl;
#define debug(x,y...) cerr << #x << " -> "; _print(y); cerr << endl;
#define crndl cerr << "\n";

template <typename T> void _print (T t) { cerr << t; }
void _print() {return;}

template <class T> void _print(T a[], int n) { cerr << "[ "; for(int i = 0; i < n; i++) { _print(a[i]); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto &i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(deque <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(queue <T> q) {cerr << "[ "; while (!q.empty()) {_print(q.front()); cerr << " "; q.pop();} cerr << "]";}
template <class T> void _print(stack <T> s) {cerr << "[ "; stack<T> t; while (!s.empty()) {t.push(s.top()); s.pop();} while (!t.empty()) {_print(t.top()); cerr << " "; t.pop();} cerr << "]";}
template <class T> void _print(priority_queue <T> pq) {cerr << "[ "; while (!pq.empty()) {_print(pq.top()); cerr << " "; pq.pop();} cerr << "]";}
template <class T> void _print(priority_queue<T, vector<T>, greater<T>> pq) {cerr << "[ "; while (!pq.empty()) {_print(pq.top()); cerr << " "; pq.pop();} cerr << "]";}

template <class T, class... V> void _print(T t, V... v) {_print(t); if(sizeof...(v)) {cerr<<", "; _print(v...);}}
// template <class T> void _print(oset<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/************************************************************************************************************************************/

const int N = 200005;
/**********************Solve Here*********************/

void solve(){

}

/**********************Solve Here*********************/
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // clock_t z = clock();

/***********************Test cases********************/


    int t = 1;
//      cin >> t;
    // int i=1;
    while (t--){
     // cout << "Case#" << i << endl;
     solve();
     // i++;
    }



/***********************Test cases********************/
    // cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    //cerr= c error.
    return 0;
}
