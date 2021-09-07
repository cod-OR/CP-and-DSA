vll ar;                
struct node {
    ll lazy=0;
    ll sum=0;
};
class seg_tree{
    node initNode;
    node extremNode;
    vector<node> tree;
    ll n;
    node merge(const node &left, const node &right){
        // merge the children and return
        node D;
        //  D.sum = left.sum+right.sum;
        return D;
    }

    void build_node(ll arrayIndex, ll treeIndex){
        // tree[treeIndex].sum = ar[arrayIndex];
        // for each node
    }
    void update_node(ll arrayIndex, ll treeIndex, ll val){
        // tree[treeIndex].sum= val ;
    }

    void build(ll l, ll r, ll x){
        ll m,lc,rc;
        m=(l+r)/2;
        lc=2*x+1;
        rc=2*x+2;

        if(r<=l)
            return;
        if(r-l==1){
            build_node(l,x);
            return;
        }
        build(l,m,lc);
        build(m,r,rc);
        tree[x] = merge(tree[lc], tree[rc]);
    }
    
    void update(ll l, ll r, ll x, ll id, ll val){
        ll m,lc,rc;
        m=(l+r)/2;
        lc=2*x+1;
        rc=2*x+2;
        if(r<=l)
            return;
        if(id<l || id>=r)
            return;
        if(r-l==1){
            update_node(l,x,val);
            return;
        }
        update(l,m,lc,id,val);
        update(m,r,rc,id,val);
        tree[x] = merge(tree[lc], tree[rc]);
    }
    
    node query(ll l, ll r, ll x, ll L , ll R){
        ll m,lc,rc;
        m=(l+r)/2;
        lc=2*x+1;
        rc=2*x+2;
    
        if(R<=l || L>=r)        // complete outside
            return extremNode;
        if(L<=l &&  r<=R)       // complete inside  
            return tree[x];
        return merge(query(l,m,lc,L,R), query(m,r,rc,L,R));
    }
public:
    seg_tree(ll size){
        tree = vector<node> (size*4);
        this-> n = size;
   
        // initNode   // for building or update build function
        // extremNode // for query or update query
    }

    void update(ll id, ll val){
        update(0,this->n,0,id,val);
    }

    node query(ll L, ll R){
        return query(0,this->n,0,L,R);
    } 

    void build(){
       build(0,this->n,0);
    }
};
