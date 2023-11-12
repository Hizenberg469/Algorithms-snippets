int fast_multiply(int a,int b,int c){
	int res=0;
	while(b){
		if(b&1)res+=a,res%=c;
		a+=a,a%=c;
		b>>=1;
	}
	return res;
}