//Binary Search Jump.
int ans = n;
for(int b = n/2 ; b >= 1 ; b/=2 ){
	while(check(ans - b))ans -= b;
}
cout << ans << endl;