#include <iostream>
#include <vector>

#define ll long long int
#define DEPTH (ll)13

using namespace std;

ll ans = (ll)1e16+1;

ll intersection(int l1, int r1, int l2, int r2){
	return 1LL * ( min( r1, r2) - max(l1 , l2) );
}

ll total_intersection(vector<pair<int,int>>& list1, vector<pair<int,int>>& list2){
	int n = (int)list1.size();
	ll I = 0;
	for(int i = 0 ; i < n ; i++ )
		I += intersection(list1[i].first , list1[i].second, list2[i].first, list2[i].second );

	return I;
}

void move(vector<pair<int,int>>& list1, vector<pair<int,int>>& list2, int k, ll total_moves){

	int n = (int)list1.size();
	
	ll I = 0;
	for(int i = 0 ; i < n ; i++ )
		I += max( 0LL , intersection(list1[i].first , list1[i].second, list2[i].first, list2[i].second ) );

	// cout << "I: " << I << '\n';
	if( I >= k ){
		ans = min( ans , total_moves );
		return;
	}

	if( total_moves > DEPTH )
		return;

	// cout << "total_moves: " << total_moves << '\n';

	int curr_I = total_intersection(list1,list2);
	int imprv_I = 0;
	for(int i = 0 ; i < n ; i++ ){

		list1[i].first--;

		imprv_I = total_intersection(list1,list2);
		
		if( imprv_I > curr_I )
			move(list1, list2, k, total_moves + 1);
		list1[i].first++;

		list1[i].second++;

		imprv_I = total_intersection(list1,list2);

		if( imprv_I > curr_I )
			move(list1, list2, k, total_moves + 1);
		list1[i].second--;

		list2[i].first--;

		imprv_I = total_intersection(list1,list2);

		if( imprv_I > curr_I )
			move(list1, list2, k, total_moves + 1);
		list2[i].first++;

		list2[i].second++;

		imprv_I = total_intersection(list1,list2);

		if( imprv_I > curr_I )
			move(list1, list2, k, total_moves + 1);
		list2[i].second--;


		list1[i].first--, list2[i].first--;

		imprv_I = total_intersection(list1,list2);

		if( imprv_I > curr_I )
			move(list1, list2, k , total_moves+2);
		list1[i].first++, list2[i].first++;

		list1[i].second++, list2[i].second++;

		imprv_I = total_intersection(list1, list2);

		if( imprv_I > curr_I )
			move(list1, list2, k ,total_moves+2);

		list1[i].second--, list2[i].second--;

	}
}

int main(){

	int t;
	cin >> t;

	int n, k, l1, r1, l2, r2;

	while(t--){
		cin >> n >> k;
		cin >> l1 >> r1;
		cin >> l2 >> r2;

		vector<pair<int,int>> list1, list2;

		for(int i = 0 ; i < n ; i++ )
			list1.push_back({l1,r1});

		for(int i = 0 ; i < n ; i++ )
			list2.push_back({l2,r2});

		move(list1, list2, k, 0);

		cout << ans << '\n';
	}
	
	return 0;
}