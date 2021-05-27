// Task -
//   You are given two arrays, sorted in non-decreasing order. 
//   For each element of the second array, find the number of elements in the first array strictly less than it

#include <bits/stdc++.h>
#define sub   freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
using namespace std;
#define ll long long
#define ld long double
#define ttime cerr << '\n'<<"Time (in s): " << double(clock() - clk) * 1.0 / CLOCKS_PER_SEC << '\n';
#define pb push_back
#define endl "\n"
#define unq(a) sort(all(a));a.resize(unique(all(a)) - a.begin())
#define sz(x) (int)((x).size())
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
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
const long long mod=1000000007;
typedef pair<ll,ll> pairll;
typedef map<ll,ll> mapll;
bool comp(ll a,ll b){
    return a>b;
}
ll n,k;
void solve(){
    //string s;
    ll m;
    cin>>n>>m;  // sizes of arrays
    std::vector<ll> a(n),b(m);
    std::vector<ll> v;
    rep(i,0,n)cin>>a[i];
    rep(i,0,m)cin>>b[i];

    int i=0, j=0, cnt=0;

    while(i<n && j<m){
        if(a[i]<b[j]){
            i++;
        }
        else{
            cout<<i<<" ";
            j++;
        }
    }

    while(j<m){
        cout<<n<<" ";
            j++;
    }
    cout<<endl;
    
    

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
