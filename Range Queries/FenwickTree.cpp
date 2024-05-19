#include <bits/stdc++.h>

using namespace std;



class Fenwick_Tree{

public:

	// 1 based indexing...
	vector<int> tree;
	int sz;

	void init(int n, const vector<int>& arr){
		tree.resize(n+1,0);

		this->sz = n;

		for(int i = 1 ; i <= sz ; i++ ){

			update(i, arr[i-1]);
		}
	}

	int sum(int k){
		int s = 0;

		while(k >= 1){

			s += tree[k];

			k -= k & -k;
		}

		return s;
	}

	void update(int k, int val){

		while( k <= sz ){
			tree[k] += val;

			k += k & -k;
		}
	}

	void print(){

		for(int i = 1 ; i <= sz ; i++ ){
			cout << tree[i] << ' ';
		}
		cout << '\n';
	}


};


int main(){

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);




	return 0;
}