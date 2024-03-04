#define MAX_N 5000001
bool is_prime[MAX_N];

bool is_sieve_eval = false;

void sieve_erathosis(){
	if( is_sieve_eval ) return;
	is_sieve_eval = true;
	memset(is_prime,0,sizeof(is_prime));
	is_prime[0] = true , is_prime[1] = true;
	for(int num = 2 ; num*num < MAX_N ; num++ ){
		if( !is_prime[num] ){
			for(int val = num*num ; val < MAX_N ; val += num ){
				is_prime[val] = true;
			}
		}
	}
}