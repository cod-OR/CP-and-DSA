struct node {
    // ll lazy=0;
    // ll min=0;
    ll sum=0;
};
vector<node> tree;
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
        tree[x].sum= ar[l] ; // global array, be cf
        return;
    }

    build(l,m,lc);
    build(m,r,rc);

    tree[x].sum=(tree[lc].sum + tree[rc].sum);   // change this
}

void change(ll l, ll r, ll x, ll id, ll val){
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

    change(l,m,lc,id,val);
    change(m,r,rc,id,val);

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
