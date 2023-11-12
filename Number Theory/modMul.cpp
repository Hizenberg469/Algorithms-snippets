template<typename T>
T modMul(T a,T b,T M=(int)1e9+7){
	return ((a%M)*(b%M))%M;
}