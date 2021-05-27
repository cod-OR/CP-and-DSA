ll power(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if (b & 1)res = (res * a) % mod;
        b >>= 1;
        a *= a; a %= mod;
    }
    return res;
}
std::vector<ll> fac(1000005),inv(1000005);
void pre(){
    fac[0] = 1; inv[0] = 1;
    for (int i = 1;i < 1000003;i++){
        fac[i] = fac[i - 1] * i;fac[i] %= mod;
        inv[i] = power(fac[i] , mod - 2);
    }
}
ll ncr(ll x, ll y){
    if (x < 0 or y < 0 or x < y) return 0;
    ll q = fac[x];
    q *= inv[x - y]; 
    q %= mod;
    q *= inv[y]; 
    q %= mod;
    return q;
}

