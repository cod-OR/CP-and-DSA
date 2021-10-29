
// Solution to TREUPS problem on codechef, from October Lunchtime 2021
// Link: https://www.codechef.com/problems/TREUPS

// To find the minimum value, we need to do subset-dp here, but the constraints are too high for that
// So, instead of following the standard method, we use bitset of size 1e5 + 1

// So,

/*

for(int i=100000;i>=0;i--){
  if(dp[i] and i+x<=100000)
    dp[i+x]=1;
}

This becomes

dp |= (dp<<x);

Easy Peasy.

*/


#include <bits/stdc++.h>
using namespace std;
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#define ll              long long
#define ull             unsigned long long
#define ld              long double
#define ttime           {cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';}
#define helpUs          template<typename T = ll , typename U = ll>
#define helpMe          template<typename T = ll>
#define pb              push_back
#define sz(x)           (int)((x).size())
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

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// order_of_key and find_by_order

const long long INF=1e18;
const long long N=200005;
const long long mod=1000000007;                    // 998244353, 2971215073, 1000050131, 433494437

#define endl "\n"
#define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
typedef vector<ll> vll;

ll n,k,tt=1;
vector<vll> adj;
vll odds;

void dfs(int x, int p, int d){
    ll child=0;
    for(auto it:adj[x]){
        if(it!=p){
            child++;
            dfs(it,x,d+1);
        }
    }
    if(d&1){
        if(child==0)odds.pb(1);
        else if(child>1)odds.pb(child-1);
    }
}

void solve(){
    
    ll q;
    cin>>n>>q;
    
    adj = vector<vll> (n+1);
    odds.clear();

    for(int i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1,0,1);

    ll mx=0, mn=INF;

    bitset<100001> dp(1);

    for(auto it:odds){
        mx+=it;
        dp |= (dp<<it);
    }
    
    for(int i=0;i<=100000;i++){
        if(dp[i])
        mn=min(mn, abs(mx-2*i));
    }

    if(q==1)cout<<mx<<endl;
    else cout<<mn<<endl;

}
           
signed main(){
    fast;
    ll t=1;
    #ifndef ONLINE_JUDGE
        sub;    
    #endif
    // clock_t clk = clock();
    // pre();

    cin>>t;
    while(t--)
        solve();
    // ttime;
    return 0;
}
