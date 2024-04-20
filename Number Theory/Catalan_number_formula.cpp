typedef long long int ll;

ll mod = 998244353;

vector<ll> factorial;
void calculateFactorial(ll n){
	factorial.resize(n+1);

	factorial[0] = factorial[1] = 1;

	for( ll i = 2 ; i <= n ; i++ ){
		factorial[i] = ( factorial[i-1] * i ) % mod;
	}
}

template<typename T>
T modMul(T a,T b,T M=(ll)1e9+7){
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

/* Using Fermat little Theorem */
ll inverse(ll n ){
	return power( n , mod - 2 , mod );
}

vector<ll> inverse_factorial;
void calculateInverseFactorial(ll n){

	inverse_factorial.resize(n+1);
	inverse_factorial[0] = inverse_factorial[1] = 1;

	for( ll i = 2 ; i <= n ; i++ ){
		inverse_factorial[i] = (inverse(i)*inverse_factorial[i-1])%mod;
	}
}

ll nCr( ll n , ll r ){

	// 	-- 		n!       -- 
	// |   -------------   | % mod
	//  -- n! * (n - r)! --

	return ( ( ( factorial[n] * inverse_factorial[r] ) % mod
		) * inverse_factorial[n-r] ) % mod;
}

/* Catalan Number */
ll Cn( ll n ){

	//	--	  	2n!			--	
	// |	---------------	  | % mod
	// 	--	n! * n! * (n+1)	--

	return ( ( ( ( ( factorial[2*n] * inverse_factorial[n] ) % mod )
		* inverse_factorial[n] ) % mod ) * inverse( n + 1 ) ) % mod;
}