//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define F first
#define S second
#define MOD 1000000007
#define maxn 1000006
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proA"
using namespace std;
//ifstream fi(Task".inp");
//ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
string a, b;
int n, m;
vector <int> res;
ll mu[maxn], sumb[maxn];
ll suma;
int coso = 101;
ll M = MOD;
ll M2 = M * M;
void nhap() {
    cin >> a;
    cin >> b;
}
ll get_hash(int u, int v)
{
    return (sumb[v] - sumb[u - 1] * mu[v - u + 1] + M2) % MOD;
}
int main() {
    nhap();
    n = sz(a);
    m = sz(b);
    a.insert(0, 1, '0');
    b.insert(0, 1, '0');
    //
    mu[0] = 1;
    for (int i = 1; i <= m; i ++)
        mu[i] = (mu[i - 1] * coso) % MOD;
    //
    sumb[0] = 0;
    for (int i = 1; i <= m; i ++)
        sumb[i] = (sumb[i - 1] * coso + b[i]) % MOD;
    //
    suma = 0;
    for (int i = 1; i <= n; i ++)
    suma = (suma * coso + a[i]) % MOD;
    //
    for (int i = 1; i <= m - n + 1; i ++)
        if(get_hash(i, i + n - 1) == suma)
            res.PB(i);
    cout << sz(res) << "\n";
    for (int i = 0; i < sz(res); i ++)
        cout << res[i] << " ";

}
