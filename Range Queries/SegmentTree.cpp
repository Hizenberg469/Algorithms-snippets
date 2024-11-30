#include <bits/stdc++.h>

using namespace std;

class SegmentTree{


	int sz;
	vector<int> tree;

public:

	SegmentTree(const vector<int>& arr){

		this->sz = arr.size();

		tree.resize(2*this->sz+1,0);

		init(arr);
		
	}

	void init(const vector<int>& arr){

		for(int i = sz-1 ; i >= 0 ; i-- )
			tree[i+sz] = arr[i];

		for(int i = sz - 1 ; i >= 1 ; i-- ){

			tree[i] = tree[2*i] + tree[2*i+1];

		}

	}


	void print(){

		cout << "Size : " << sz << '\n';

		for(int i = 0 ; i <= 2*sz ; i++ ){

			cout << tree[i] << ' ';
		}
		cout << '\n';
	}

	int sum( int a, int b){

		int s = 0;
		a += sz , b += sz;

		while( a <= b ){

			if( a%2 == 1 ) s += tree[a++];

			if( b%2 == 0 ) s += tree[b--];

			a /= 2 , b /= 2;
		}
		return s;
	}

	void add(int k, int x) {
		k += sz;
		tree[k] += x;
		for (k /= 2; k >= 1; k /= 2) {
			tree[k] = tree[2*k]+tree[2*k+1];
	}
}



};

int main(){

	vector<int> arr = {5,8,6,3,2,7,2,6};

	SegmentTree stree(arr);


	stree.print();

	stree.add(7,1);
	cout << "(2,7) : " << stree.sum(2,7) << '\n';

	return 0;
}