
struct tree_node {
    ll lazy=0;
    ll val=0;
};
class seg_tree{
    vector<tree_node> tree;
    ll n;
    vll ar;
    tree_node extremNode;

    tree_node merge(const tree_node &left, const tree_node &right){
        tree_node res;
        res.val = left.val + right.val;
        return res;
    }
    void build_node(ll arrayIndex, ll treeIndex){
        // update here. is it really required?
        tree[treeIndex].val = ar[arrayIndex];
    }
    void update_node(ll treeIndex, ll L, ll R, ll val){
        // index treeIndex corresponds to range [L,R); use val and update.
        tree[treeIndex].val = val;
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
    
    void update(ll l, ll r, ll x, ll L, ll R, ll val){
        ll m,lc,rc;
        m=(l+r)/2;
        lc=2*x+1;
        rc=2*x+2;
        
        if(r<=l)
            return;
        
        if(R<=l || L>=r)   // complete outside
            return;

        if(L<=l and r<=R){  // complete inside
            update_node(x,L,R,val);
            return;
        }
        update(l,m,lc,L,R,val);
        update(m,r,rc,L,R,val);

        tree[x].val = merge(tree[lc], tree[rc]).val;  // comment this if not required

    }
    
    tree_node query(ll l, ll r, ll x, ll L , ll R){
        ll m,lc,rc;
        m=(l+r)/2;
        lc=2*x+1;
        rc=2*x+2;
        if(R<=l || L>=r)        // complete outside
            return extremNode;
        if(L<=l &&  r<=R)       // complete inside  
            return tree[x];
        tree_node res = merge(query(l,m,lc,L,R), query(m,r,rc,L,R));

        return res;
    }

public:

    seg_tree(ll size){
        tree = vector<tree_node> (size*4);
        this-> n = size;
        //extremNode.val = 0;
    }

    seg_tree(ll size, vll &ar){
        tree = vector<tree_node> (size*4);
        this-> n = size;
        this->ar = ar;
        //extremNode.val = 0;
    }

    void update(ll L, ll R, ll val){
        update(0,this->n,0,L,R,val);
    }

    tree_node query(ll L, ll R){
        return query(0,this->n,0,L,R);
    } 

    void build(){
       build(0,this->n,0);
    }

};

