class LIFT{
    vll tin, tout;
    ll timer=0;
    int LOG;
    vector<vll> ancestor;

    void dfs(int v, int p=-1){
        tin[v] = ++timer;
        ancestor[v][0] = p;
        for (int i = 1; i <= LOG; ++i)
            ancestor[v][i] = ancestor[ancestor[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }

        tout[v] = ++timer;
    }
public:
    int n;
    LIFT(){cout<<"Use other constructor and pass n and root\n";}
    LIFT(int n, int root){
        this->n = n;
        build(root);
    }
    void build(int root){
        LOG = log2(n)+1;
        tin = vll(n+1);
        tout = vll(n+1);
        ancestor = vector<vll> (n+1, vll(LOG+1));
        dfs(root,root);
    }
    bool is_ancestor(int u, int v){
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v){
        if(is_ancestor(u,v))
            return u;
        if(is_ancestor(v,u))
            return v;

        for(int i=LOG;i>=0;i--){
            if(!is_ancestor(ancestor[u][i],v))
                u=ancestor[u][i];
        }

        return ancestor[u][0];
    }
};
// usage: define adj list globally.
// pass number of vertices and root to constructor
