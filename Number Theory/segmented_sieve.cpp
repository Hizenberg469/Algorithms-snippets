#define MAX_N 33000
bool is_prime[MAX_N];

bool is_sieve_eval = false;

void sieve_erathosis(){
	if( is_sieve_eval ) return;
	is_sieve_eval = true;
	memset(is_prime,false,sizeof(is_prime));
	is_prime[0] = true , is_prime[1] = true;
	for(int num = 2 ; num*num < MAX_N ; num++ ){
		if( !is_prime[num] ){
			for(int val = num*num ; val < MAX_N ; val += num ){
				is_prime[val] = true;
			}
		}
	}
}

vector<bool> seg_prime;

void segmented_sieve(int m,int n){
    
    seg_prime.resize(n-m+1,false);
 
    if( m == 1 ){
        seg_prime[0] = true;
    }
 
    int sz = ceil(sqrt(n));
 
    int factor = 0;
    for(int i = 2 ; i < sz ; i++ ){
        if( !is_prime[i]){
            factor = ceil((1.0*m)/i);
            for(int num = (factor==1?2:factor) * i ; num < n + 1 ; num += i ){
                seg_prime[num-m] = true;
            }
        }
    }
 
    for(int i = 0 ; i < n-m+1 ; i++ ){
        if( !seg_prime[i] )
            cout << i+m << '\n';
    }
    cout << '\n';
 
    seg_prime.clear();
}
