/*
    Topic: Meet in the Middle
    Question link: https://www.spoj.com/problems/SUBSUMS/
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define ll long long int

using namespace std;

vector<ll> subsetSums;
vector<ll> firstHalf;
vector<ll> secondHalf;

void printVector(vector<ll> &v){

    int sz = (int)v.size();
    for( int i = 0 ; i < sz ; i++ )
        cout << v[i] << ' ';

    cout << '\n';
}

void recursiveApproach(int curIdx, ll currSum, int N, vector<int> &S){

    //Base case...
    if( curIdx == N ){
        subsetSums.push_back(currSum);
        return;
    }

    recursiveApproach(curIdx + 1, currSum + S[curIdx], N, S);
    recursiveApproach(curIdx + 1, currSum, N, S);

}

void bitmaskApproach(int startIdx, int N, vector<int> &S){

    ll currSum = 0;
    for(int mask = 0 ; mask < pow(2, N) ; ++mask ){
        currSum = 0;
        for(int i = 0 ; i < N ; ++i){
            if( mask & (1<<i) ){
                currSum += S[i + startIdx];
            }
        }

        subsetSums.push_back(currSum);
    }
}

void generateAllSubsetSum(vector<int> &S){

    // // Using Recursive Approach...
    // subsetSums.clear();
    // recursiveApproach(0, 0LL, (int)S.size()/2, S);
    // firstHalf = subsetSums; // deep copy

    // subsetSums.clear();
    // recursiveApproach((int)S.size()/2, 0LL, (int)S.size(), S);
    // secondHalf = subsetSums; // deep copy

    // Using Bitmask Approach...
    subsetSums.clear();
    bitmaskApproach(0, (int)S.size()/2, S);
    firstHalf = subsetSums; // deep copy

    subsetSums.clear();
    bitmaskApproach((int)S.size()/2, (int)S.size() - S.size()/2, S);
    secondHalf = subsetSums; // deep copy

} 

int main(){

    int N, A, B;
    ll noOfSubset = 0LL;
    
    cin >> N >> A >> B;
    
    vector<int> S(N);

    for(int i = 0 ; i < N ; i++ )
        cin >> S[i];

    
    generateAllSubsetSum(S);

    // printVector(firstHalf);
    // printVector(secondHalf);

    sort(secondHalf.begin(), secondHalf.end());

    int sz = (int)firstHalf.size();
    int a = 0;
    for(int i = 0 ; i < sz ; ++i){
        noOfSubset += upper_bound(secondHalf.begin(), secondHalf.end(), B - firstHalf[i])
                    -
                    lower_bound(secondHalf.begin(), secondHalf.end(), A - firstHalf[i]);
    }

    cout << noOfSubset << '\n';
    return 0;
}