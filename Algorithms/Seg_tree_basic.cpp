
// This is the most basic Segment Tree -
//  Queries-
//   1 i v: set the element with index i to v
//   2 l r: calculate the sum of elements with indices from l to r−1
//   (Zero indexed)

#include <bits/stdc++.h>
#define sub             freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
using namespace std;
#define ll              long long
#define ld              long double
#define ttime           cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
#define pb              push_back
#define unq(a)          sort(all(a));a.resize(unique(all(a)) - a.begin())
#define sz(x)           (int)((x).size())
#define input(arr,n)    for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast            ios_base::sync_with_stdio(false);cin.tie(0);
#define all(x)          x.begin(),x.end()
#define rep(i,a,b)      for(ll i=a;i<b;i++)
#define PR(x)           cout << #x " = " << (x) << "\n"
#define mp              make_pair
#define ff              first
#define ss              second
#define YY              cout<<"Yes"<<endl
#define NN              cout<<"No"<<endl
#define ppc             __builtin_popcount
#define ppcll           __builtin_popcountll

const long long INF=1e18;
const long long A=200005;
const long long mod=1000000007;

#define endl "\n"
// #define int ll

typedef pair<ll,ll> pairll;
typedef map<ll,ll>  mapll;
typedef map<char,ll> mapch;
bool comp(ll a,ll b){
    return a>b;
}

ll n,k,tt=1;
std::vector<ll> ar(A);


struct node {
    ll lazy=0;
    ll min=0;
    ll sum=0;
};
vector<node> tree;
// Check bound on A
// global tree, make sure you clear it, if tc are there
// zero indexed, [0,n)
// make sure value of n is increased to nearest power of 2

void build(ll l, ll r, ll x){
    ll m,lc,rc;
    m=(l+r)/2;
    lc=2*x+1;
    rc=2*x+2;
    if(r<=l)return;
    if(r-l==1){
        tree[x].sum= ar[l] ;
        return;
    }

    build(l,m,lc);
    build(m,r,rc);

    tree[x].sum=(tree[lc].sum + tree[rc].sum);   // change this
}

void sett(ll l, ll r, ll x, ll id, ll val){
    ll m,lc,rc;
    m=(l+r)/2;
    lc=2*x+1;
    rc=2*x+2;
    if(r<=l)return;
    if(id<l || id>=r)return;
    if(r-l==1){
        tree[x].sum= val ;
        ar[id]= val;
        return;
    }

    sett(l,m,lc,id,val);
    sett(m,r,rc,id,val);

    tree[x].sum=(tree[lc].sum + tree[rc].sum);   // change this
}

ll query(ll l, ll r, ll x, ll L , ll R){
    ll m,lc,rc;
    m=(l+r)/2;
    lc=2*x+1;
    rc=2*x+2;

    if(R<=l || L>=r)return 0; // change this
    if(L<=l &&  r<=R){
        return tree[x].sum;  // this too
    }
    ll b=query(l,m,lc,L,R);
    b+=query(m,r,rc,L,R);

    return b; // this too
}


void solve(){
    //string s,t;
    ll m,q,x,y;
    cin>>n>>q; 
    input(ar,n);
    while(ppcll(n)!=1)n++;
    tree.resize(2*n + 2);
    build(0,n,0);

    while(q--){
        ll op, i,j;
        cin>>op>>i>>j;

        if(op==1){
            sett(0,n,0,i,j);
        }
        else{
            cout<<query(0,n,0, i, j)<<endl;
        }

    }
    

}

signed main(){ 
    // sub;    
    fast;
    // pre();
    // clock_t clk = clock();
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    // ttime;
    return 0;
}        

                                // Mischief Managed //   
                                         
