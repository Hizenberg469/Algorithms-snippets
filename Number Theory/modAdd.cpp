template<typename T>
T modAdd(T a,T b,T M=(T)1e9+7){
	return ((M+a%M)%M+(M+b%M)%M)%M;
}
