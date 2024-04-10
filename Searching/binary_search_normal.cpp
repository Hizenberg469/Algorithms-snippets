//Binary Search Normal
int low = 0 , high = n , ans;

while( low <= high ){
	int mid = low + ( high - low)/2;
	
	if( check(mid) ){
		ans = mid;
		low = mid + 1;
	}
	else{
		high = mid - 1;
	}
}