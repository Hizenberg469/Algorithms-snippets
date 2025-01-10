#include <iostream>

#define NPRINT_VAR
#define var_name(arg) #arg


#ifdef NPRINT_VAR
    #define   var_value(arg)   ((void)0)
#else
    #define var_value(arg) cout << var_name(arg) << ": " << arg << endl;
#endif

#define ll long long int

using namespace std;

int main(){

	int t;
	cin >> t;

	ll n , k , al , ar, bl , br , value , extend, cover
		, factor , min_step ;

	ll new_ans = 0 , ans = 0 , I = 0 , adder;

	while( t-- ){
		ans = 0;
		new_ans = 0;
		adder = 0;
		cin >> n >> k >> al >> ar >> bl >> br;
 
		I = 1LL * n * ( min(ar , br) - max(al , bl) );

		var_value(I);

		if( I >= k ){
			cout << ans << '\n';
			continue;
		}

		value = k;

		if( I > 0 )
			value -= I;

		var_value(value);

		extend = (max(al , bl) - min(al , bl)) + 
				 (max(ar , br) - min(ar , br));

		var_value(extend);

		cover = max(ar , br) - min(al , bl);

		if( I > 0 )
			cover -= I / n;

		var_value(cover);

		if( cover > 0 )			
			factor = value / cover;
		else
			factor = n + 1;

		var_value(factor);

		ans += extend * min(factor,n);

		var_value(ans);

		if( min(factor,n) * cover == value ){
			cout << ans << '\n';
			continue;
		} 

		value -= min(factor,n) * cover;

		var_value(value);

		if( factor < n && factor > 0 )
			adder = 2 * (value);
		else
			adder = (ll)1e17+1;

		var_value(adder);

		if( n > factor ){
			
			min_step = value - (( min(ar,br) - max(al,bl) ) - max(I/n,0LL));

			new_ans = ans + min_step;
			
			var_value(new_ans);

			ans = min(new_ans, ans + adder);
		}
		else{
			ans += 2 * value;
		}

		cout << ans << '\n';
	}

	return 0;
}