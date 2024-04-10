class String_hash{

	public:
	
	vector<int> p = {31,33};
	
	vector<int> prime = { 1000000007, 1000000009 };
	
	int sz;
	
	//For Storing the hash value of the prefix string.
	vector<vector<int>> hash;
	//For storing the power of p(constant) for polynomial function.
	vector<vector<int>> power_p;
	//For storing the inverse of the power of p 
	vector<vector<int>> inv_power_p;
	
	String_hash(string a, int num){
		sz = num;
		
		hash.resize(sz);
		power_p.resize(sz);
		inv_power_p.resize(sz);
		string s = a;
		int n = (int)s.size();
		
		//Pre-Calculating power.
		for(int i = 0 ; i < sz ; i++ ){
			
			power_p[i].resize(n);
			power_p[i][0] = 1;
			
			for(int j = 1 ; j < n ; j++ ){
				power_p[i][j] = ( power_p[i][j-1] * p[i] ) % prime[i];
			}
		}
		
		//Pre-Calculating inverse power.
		for(int i = 0 ; i < sz ; i++ ){
			
			inv_power_p[i] = invs(power_p[i] , prime[i] );
			
		}
		
		//Calculating prefix-hash of the given string.
		for(int i = 0 ; i < sz ; i++ ){
			
			hash[i].resize(n);
			
			for(int j = 0 ; j < n ; j++ ){
				hash[i][j] = ( ( s[j] - 'a' + 1LL ) * power_p[i][j] ) % prime[i];
				hash[i][j] = ( hash[i][j] + ( j-1 >= 0 ? hash[i][j-1] : 0LL ) ) % prime[i];
			}
		}	
	}
	
	vector<int> invs( vi& a , int m ){
		int n = (int)a.size();
		
		if( n == 0 ) return {};
		
		vector<int> b(n);
		
		int v = 1;
		for(int i = 0 ; i < n ; i++ ){
			b[i] = v;
			v = ((long long)v * a[i] ) % m; 
		}
		
		int x = power( v , m - 2 , m ) ;
		
		x = (x % m + m ) % m;
		
		for(int i = n - 1 ; i >= 0 ; i-- ){
			b[i] = x * b[i] %m;
			x = x * a[i] % m;
		}
		
		return b;
	}
	
	void add_char_back(char c ){

		
		for(int i = 0 ; i < sz ; i++ ){
			
			//power of p for new character adding at the back.
			power_p[i].pb( power_p[i].back() * p[i] );
			hash[i].pb( (hash[i].back()) + ( c - 'a' + 1LL ) * (power_p[i].back())  % prime[i]);
		}
	}
	
	
	void add_char_front(char c ){
		
		for(int i = 0 ; i < sz ; i++ ){
			
			//power of p for new character adding at the back.
			power_p[i].pb( power_p[i].back() * p[i] );
			hash[i].pb( (hash[i].back()) * (power_p[i].back()) + ( c - 'a' + 1LL )   % prime[i]);
		}
	}
	
	vector<int> subStringHash(int l , int r ){ //log 1e9+7
		
		vector<int> new_hash(sz);
		for(int i = 0 ; i < sz ; i++ ){
			
			int val1 = ( l-1 >= 0 ? hash[i][l-1] : 0LL );
			int val2 = hash[i][r];
			
			new_hash[i] = modMul( modSub( val2 , val1 , prime[i]) , inv_power_p[i][l] , prime[i] ) ;   
		}
		
		return new_hash;
	}
	
	bool compareSubString( int l1 , int r1 , int l2 , int r2 ){
		
		if( l1 > l2 ){
			swap(l1,l2);
			swap(r1,r2);
		}
		
		for(int i = 0 ; i < sz ; i++ ){
			
			int val1 = modSub( hash[i][r1] , ( l1 - 1 >= 0 ? hash[i][l1-1] : 0LL ), prime[i] );
			int val2 = modSub( hash[i][r2] , ( l2 - 1 >= 0 ? hash[i][l2-1] : 0LL ), prime[i] );
			
			if( modMul( val1 ,power_p[i][l2-l1] , prime[i] ) != val2 ){
				return false;
			} 
		}
		return true;
	}
	
};