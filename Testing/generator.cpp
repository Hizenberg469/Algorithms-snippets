#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){

	int n = atoi(argv[1]);
    // cin>>n;

    int arr[n];
    for(int i = 1 ; i <= n ; i++ )
        arr[i-1] = i;

    int idx = 0;
    int cnt = 1;

    int elemLeft = n;

    cout << "Operation:\n";

    while( true ){
        // cout << "Size : " << elemLeft << '\n';
        if( elemLeft <= 0 )
            break;

        if( cnt%2 == 0 ){
            while( arr[idx] == -1 )
                idx = (idx+1)%n;
 
            cout << arr[idx] << ' ';
            arr[idx] = -1;

            elemLeft--;
            if( elemLeft <= 0 )break;

            while( arr[idx] == -1 )
                idx = (idx+1)%n;
            cnt = 1;

            // idx = (idx+1)%n;
            continue;
        }

        idx = (idx+1)%n;
        cnt++;
    }
    cout << '\n';
	return 0;
}