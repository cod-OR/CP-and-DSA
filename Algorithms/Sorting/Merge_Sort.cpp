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

void merge(std::vector<ll> &ar, ll st1,ll en1,ll st2,ll en2){
    int i=st1,j=st2;
    std::vector<ll> v;
    while(i<=en1 && j<=en2){
        if(ar[i]<=ar[j]){
            v.pb(ar[i]);
            i++;
        }
        else{
            v.pb(ar[j]);
            j++;
        }
    }
    while(j<=en2){
        
        v.pb(ar[j]);
        j++;
    
    }
    while(i<=en1){
        v.pb(ar[i]);
        i++;
    }
    ll cnt=0;
    for(int i=st1;i<=en1;i++){
        ar[i]=v[cnt];cnt++;
    }
    for(int i=st2;i<=en2;i++){
        ar[i]=v[cnt];cnt++;
    }
}

void merge_sort(std::vector<ll> &ar, ll st,ll en){
    if(st>=en)return;
    ll p=(st+en)/2;
    merge_sort(ar,st,p);
    merge_sort(ar,p+1,en);
    merge(ar,st,p,p+1,en);
}

void solve(){
    ll n;
    cin>>n;
    std::vector<ll> ar(n);
    input(ar,n);
    merge_sort(ar,0,n-1);
    for(auto it:ar)cout<<it<<" ";cout<<endl;
}


int main(){     
    sub;    
    fast;
        int t=1;
    // cin>>t;
    while(t--){
        solve();
        }
    return 0;
}        

                                // Mischief Managed //    
