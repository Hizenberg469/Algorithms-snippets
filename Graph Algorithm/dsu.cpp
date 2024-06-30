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