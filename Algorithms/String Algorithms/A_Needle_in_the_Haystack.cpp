
// Problem Link - https://www.spoj.com/problems/NHAY/

#include <bits/stdc++.h>
using namespace std;
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#define ll              long long
#define ld              long double
#define ttime           cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
#define pb              push_back
#define unq(a)          sort(all(a));(a).resize(unique(all(a)) - (a).begin())
#define sz(x)           (int)((x).size())
#define input(arr,n)    for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x)          (x).begin(),(x).end()
#define rep(i,a,b)      for(ll i=a;i<b;i++)
#define pr(x)           cout << #x " = " << (x) << "\n"
#define mp              make_pair
#define ff              first
#define ss              second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
#define ppc             __builtin_popcount
#define ppcll           __builtin_popcountll

const long long INF=1e18;
const long long A=2000005;
const long long mod=1000000007;                    // 2971215073, 1000050131, 433494437

#define endl "\n"
// #define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
bool comp(ll a,ll b){
    return a>b;
}

ll n,k,tt=1;
vector<ll> power(A);
void pre(){
    power[0]=1;
    for(int i=1;i<A;i++){
        power[i]=power[i-1]*31;
        power[i]%=mod;
    }
}

ll hashof(string &s){
    int n=s.size();
    ll h=0;
    for(int i=0;i<n;i++){
        h+=(s[i]-'a'+1)*power[i];
        h%=mod;
    }

    return h;
}

void solve(){
    string s1,s2;
    ll n,m;
    cin>>s1>>s2;
    ll m=s1.size(), n=s2.size();

    ll h1=hashof(s1), h2=0;
    vector<ll> hashes(n+1);

    for(int i=0;i<n;i++){
        h2+=(s2[i]-'a'+1)*power[i];
        h2%=mod;
        hashes[i]=h2;

        if(i==m-1 && h1==h2){
            cout<<i-m+1<<endl;
            continue;
        }

        if(i>=m)
        if((h2-hashes[i-m]+mod)%mod== (h1*power[i-m+1])%mod){       // for substring s[i...j], (hashes[j]-hashes[i-1]) should be equal to h*power[i]
            cout<<i-m+1<<endl;
            continue;
        }
    }

    cout<<endl;
    

}

signed main(){ 
    // sub;    
    fast;
    pre();
    // clock_t clk = clock();
    ll t=1;
    // cin>>t;
    while(cin>>n){
        solve();
    }
    // ttime;
    return 0;
}       
                                
