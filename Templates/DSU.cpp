
vector<ll> par;

void make_set(int v) {
    par.resize(v+1);
    par[v] = v;
}

int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        par[b] = a;
}
