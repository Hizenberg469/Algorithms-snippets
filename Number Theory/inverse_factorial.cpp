int invFac[MAX_N];
void inverse_factorial(){

	invFac[0] = invFac[1] = 1;

	for(int i = 2 ; i <= MAX_N ; i++ ){
		invFac[i] = (inverse(i)*invFac[i-1])%M;
	}
}