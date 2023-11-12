//Advanced Binary Seach.
int max_iter;
double low , high , ans;
double err ;
for(int i = 1 ; i <= max_iter ; i++ ){
	double mid = low + (high - low)/2;
	
	if( check(mid) ){
		ans = mid;
		low = mid + err;
	}
	else{
		high = mid - err;
	}
}