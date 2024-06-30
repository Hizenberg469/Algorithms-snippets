#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int>& v1 , vector<int>& v2 ){
	return v1[0] > v2[0];
}

class Solution{

public:

	class dsu{
	public:
		vector<int> parent;
		vector<int> size;

		dsu(int sz){
			parent.resize(sz);
			size.resize(sz);

			for(int i = 0 ; i < sz ; i++ )
				parent[i] = i , size[i] = 1;
		}

		int find(int n){
			if( parent[n] == n ) return n;

			return parent[n] = find( parent[n] );
		}

		int find_iterative( int n ){
			while( parent[n] != n ){
				n = parent[n];
			}
			return n;
		}

		void unite(int a, int b){

			int par_a = find(a);
			int par_b = find(b);

			if( par_a == par_b )
				return;

			if( size[par_a] < size[par_b] ) swap(par_a, par_b);

			size[par_a] += size[par_b];

			parent[par_b] = par_a;
		}

		bool isSame(int a , int b){
			return find(a) == find(b);
		}
	};



	//Solution function template...
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort( edges.begin() , edges.end() , comp );


    }

};

int main( int argc, char* argv[] ){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	Solution sol;

	//solution function call...
	

	//Extract result and print the solution..

	
	return 0;
}