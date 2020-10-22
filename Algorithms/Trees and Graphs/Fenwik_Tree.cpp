            //    I solemnly swear that I am upto no good //

#include <bits/stdc++.h>
#define sub   freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ff first
#define ss second
#define NN cout<<"NO"<<endl;
#define YY cout<<"YES"<<endl;
#define ub upper_bound
#define lb lower_bound
#define A 1000001
#define make(a,b,c) make_pair(a,make_pair(b,c)) 
bool comp(ll a,ll b){
    return a>b;
}
ll n;
std::vector<ll> BIT(A);
void update(int x, int val){
    for(;x<=n;x+=(x&-x)){
        BIT[x]+=val;
    }
}
ll query(int x, int val){    
    ll sum=0;
    for(;x>0;x-=(x&-x)){
        sum+=BIT[x];
    }
    return sum;
}

void solve(){
    ll q;
    cin>>n>>q;
    std::vector<int> ar(n);
    input(ar,n+1); // one indexed
    
    for(int i=1;i<=n;i++){
        update(i,ar[i]);
    }

    while(q--){
        int a,x,y;
        cin>>a>>x>>y;
        if(a==1){
            // update 
            ar[x]=y;
            update(x,y); // position x element y
        }
        else{
            // Query
            cout<<query(x,y)<<endl; // sum from x to y inclusive
        }
    }
}

int main(){ 
    sub;    
    fast;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}        

                        // Mischief Managed //    