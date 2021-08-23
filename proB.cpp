//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define maxn 1000006
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proB"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
ll n, m;
string a;
string b[maxn];
string st[maxn];
ll res[maxn];
ll coso = 311;
ll get_hash(string a)
{
    ll suma = 0;
    for (int i = 1; i <= n/m; i ++)
        suma = (suma * coso + a[i]) % MOD;
    return suma;
}
struct xau
{
    ll val;
    ll pos;
};
xau vb[maxn];
xau vst[maxn];
bool cmp1(xau a, xau b)
{
    if (a.val != b.val) return a.val < b.val;
    else return a.pos > b.pos;
}
bool cmp2(xau a, xau b)
{
    if (a.val != b.val) return a.val < b.val;
    else return a.pos < b.pos;
}
void nhap() {
    cin >> n >> m;
    cin >> a;
    a.insert(0, 1, '0');
    for (int i = 1; i <= m; i ++) {
        cin >> b[i];
        b[i].insert(0, 1, '0');
        vb[i].val = get_hash(b[i]);
        vb[i].pos = i;
    }
    for (int i = 1; i <= m; i ++) {
        st[i] = a.substr((i - 1)*n/m + 1, n/m);
        st[i].insert(0, 1, '0');
        vst[i].val = get_hash(st[i]);
        vst[i].pos = i;
    }
}
int main() {
    nhap();
    sort(vb + 1, vb + m + 1, cmp1);
    sort(vst + 1, vst + m + 1, cmp2);
    for (int i = 1; i <= m; i ++)
        res[vst[i].pos] = vb[i].pos;
    for (int i = 1; i <= m; i ++)
        cout << res[i] << " ";
}
