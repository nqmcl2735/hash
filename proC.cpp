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
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int a[maxn];
int b[maxn];
int invb[maxn];
ll hash_b[maxn];
ll hash_a[maxn];
ll hashinv_b[maxn];
ll mu[maxn];
ll M = MOD;
ll M2 = M*M;
ll res[maxn];
ll n;
ll cnt = 0;
ll coso = 100007;
ll get_hash(ll arr[], int u, int v)
{
    return (arr[v] - arr[u - 1] * mu[v - u + 1] + M2) % MOD;
}
void nhap() {
    fi >> n;
    for (int i = 1; i <= n; i ++)
        fi >> a[i];
    for (int i = 1; i <= n; i ++) {
        fi >> b[i];
        invb[n - i + 1] = b[i];
    }
}
bool check(int k)
{
    if(hash_b[n - k + 1] != get_hash(hash_a, k, n)) return 0;
    if ((n - k + 1)%2 == 0) return (hash_a[k - 1] == get_hash(hash_b, n - k + 2, n));
    else return (hash_a[k -1] == hashinv_b[k - 1]);
}
int main() {
    nhap();
    //
    mu[0] = 1;
    for (int i = 1; i <= n; i ++)
        mu[i] = (mu[i - 1] * coso) % MOD;
    //
    hash_a[0] = 0;
    hash_b[0] = 0;
    hashinv_b[0] = 0;
    for (int i = 1; i <= n; i ++) {
        hash_a[i] = (hash_a[i - 1] * coso + a[i]) % MOD;
        hash_b[i] = (hash_b[i - 1] * coso + b[i]) % MOD;
        hashinv_b[i] = (hashinv_b[i - 1] * coso + invb[i]) % MOD;
    }
    for (int k = 1; k <= n; k ++)
    if(check(k))res[++ cnt] = k;
    fo << cnt << "\n";
    for (int i = 1; i <= cnt; i ++)
        fo << res[i] << " ";

}
