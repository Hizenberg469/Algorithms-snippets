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