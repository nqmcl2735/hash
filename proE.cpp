//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <ll,ll>
#define vi vector <int>
#define F first
#define S second
#define mp make_pair
#define maxn 1000005
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
string a, b;
ll n, m, ans;
ll hash_a[maxn], hash_b[maxn];
ll mu[maxn];
pii hash_ans[maxn];
ll M = MOD;
ll M2 = M * M;
ll coso = 311;
ll get_hash(ll arr[], int u, int v)
{
    return (arr[v] - arr[u - 1] * mu[v - u + 1] + M2) % MOD;
}
bool chk(ll x, int i, ll pos)
{
    for (int j = 1; j <= x; j ++)
        if(a[pos + j - 1] != b[i + j - 1]) return 0;
    return 1;
}
pii check(ll k)
{
    for (int i = 1; i <= m; i ++) hash_ans[i] = mp(get_hash(hash_a, i, i + k - 1), i);
    sort(hash_ans + 1, hash_ans + m + 1);
    for (int i = 1; i <= m; i ++)
    {
        pii p = mp(get_hash(hash_b, i, i + k - 1), 0);
        ll pos1 = lower_bound(hash_ans + 1, hash_ans + m + 1, p) - hash_ans;
        if (hash_ans[pos1].F != p.F) continue;
        p.S = m;
        ll pos2 = upper_bound(hash_ans + 1, hash_ans + m + 1, p) - hash_ans;
        while (pos1 < pos2) {
            ll pos = hash_ans[pos1].S;
            if(chk(k, i, pos)) return {pos, i};
            pos1 ++;
        }
    }
    return {0, 0};
}
void nhap() {
    cin >> a >> b;
    m = sz(a);
    n = 2 * m;
    a += a;
    b += b;
    a.insert(0,1,'0');
    b.insert(0,1,'0');
}
int main() {
    nhap();
    //
    mu[0] = 1;
    for (int i = 1; i <= n/2; i ++)
        mu[i] = (mu[i - 1] * coso) % MOD;
    //
    hash_a[0] = 0;
    for (int i = 1; i <= n; i ++)
        hash_a[i] = (hash_a[i - 1] * coso + a[i]) % MOD;

    hash_b[0] = 0;
    for (int i = 1; i <= n; i ++)
        hash_b[i] = (hash_b[i - 1] * coso + b[i]) % MOD;
    //
    ll l = 0;
    ll r = m;
    while (l <= r)
    {
        ll mid = (l + r)/2;
        pii x = check(mid);
        if(x.F)
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}
