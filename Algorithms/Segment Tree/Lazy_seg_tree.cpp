
// Queries-
//   1 l r v: add the value v to the segment from l to r−1
//   2 i: find the value of the element with index i (0≤ i <n)
//     (Zero Indexed)


#include <bits/stdc++.h>
#define sub   freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
using namespace std;
#define ll long long
#define ld long double
#define ttime cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
#define pb push_back
// #define endl "\n"
#define unq(a) sort(all(a));a.resize(unique(all(a)) - a.begin())
#define sz(x) (int)((x).size())
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define ff first
#define ss second
#define YY cout<<"Yes"<<endl
#define NN cout<<"No"<<endl
#define ub upper_bound
#define lb lower_bound
#define A 1000001
const long long INF=1e18;
typedef pair<ll,ll> pairll;
typedef map<ll,ll> mapll;
bool comp(ll a,ll b){
    return a>b;
}
ll n,k,a;
// map<int,int> m;
vector<ll> tree(A), st(A);
std::vector<ll> ans(A);
// 5 1 2 2 3 1 3 4 5 4

void build(int l, int r, int x, int L , int R, ll v){
    if(R<=l || L>=r)return ;
    // cout<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    if(L<=l &&  r<=R){
        // cout<<" ## "<<tree[x]<<endl;
        tree[x]+=v;
        return ;

    }
    build(l, (l+r)/2 , 2*x+1 ,L,R, v);
    build((l+r)/2 , r , 2*x+2 ,L,R, v);
    // tree[x]=tree[2*x+1]+tree[2*x+2];

}

ll find(int l, int r, int x, int p){
    ll a=0;
    if(l>=r)return 0;
    if(p<l || r<=p)return 0;
    a+=tree[x];
    // cout<<l<<" "<<r<<" "<<p<<endl;
    if(r-l==1)return a;
    a+=find(l, (l+r)/2, 2*x+1, p);
    a+=find((l+r)/2, r, 2*x+2, p);
    // tree[x]=tree[2*x+1]+tree[2*x+2];
    return a;
}



void solve(){
    //string s;
    ll m;
    cin>>n>>m;
    // k=2*n;
    while(__builtin_popcount(n)!=1)n++;
    while(m--){
        ll op;
        cin>>op;
        if(op==1){
            ll l,r,v;
            cin>>l>>r>>v;
            build(0,n,0,l,r,v);
            // for(int i=1;i<2*n ; i++){

            //     cout<<tree[i-1]<<" ";
            //     if(__builtin_popcount(i+1)==1)cout<<"\n";
            // }
        }
        else{
            int i;
            cin>>i;
            cout<<find(0,n,0,i)<<endl;
        }
    }
    
    

}

int main(){ 
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
