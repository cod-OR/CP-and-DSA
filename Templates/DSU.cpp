
// Disjoint-set class
// Usage - 
// DSU d1(number_of_vertices+1);

// const int N= 2e5
// #define ll long long

class DSU{
    vll par, rank;
    ll n;
public:
    DSU(ll n=N){
        par = vector<ll> (n);
        rank = vector<ll> (n);
        this-> n =n;
        clear();
    }
    void clear(){
        for(int i=0;i<n;i++)par[i]=i;
    }
    ll find(ll a){
        if(a==par[a])return a;
        else return par[a]=find(par[a]);
    }
    
    void unionn(ll a, ll b){
        a= find(a);
        b= find(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            par[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};
