int operator%(string& a , int b){

    int sz = (int)a.size();
    int val = 0;
    for(int idx = 0 ; idx < sz ; idx++ ){
        val = 10*val + (a[idx]-'0');
        val %= b;
    }

    return val;
}