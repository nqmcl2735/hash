//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define MOD 1000000007
#define F first
#define S second
#define maxn 2000005
#define reset(x) memset(x,0,sizeof(x))
#define sz(x) int(x.size())
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
string a;
ll n;
string res, ans;
ll coso = 311;
ll cnt = 0;
ll m;
ll mu[maxn];
ll M = MOD;
ll M2 = M * M;
ll hash_a[maxn];
ll hash_y[maxn];
ll get_hash(string a)
{
    ll suma = 0;
    for (int i = 1; i <= sz(a) - 1; i ++)
        suma = (suma * coso + a[i]) % MOD;
    return suma;
}
void nhap() {
    cin >> a;
    n = sz(a);
    m = n/2 + 1;
    if (!(n % 2)) {
        cout << "NOT POSSIBLE";
        exit(0);
    }
    a.insert(0,1,'0');
}
ll get_hash(ll arr[], int u, int v)
{
    if (u > v) return 0;
    return (arr[v] - arr[u - 1] * mu[v - u + 1] + M2) % MOD;
}
void xet1()
{
    string x = a.substr(1, n/2), y = a.substr(n/2 + 1, n/2 + 1);
    ans = x;
    x = "0" + x;
    y = "0" + y;
    ll hash_x = get_hash(hash_a, 1, m - 1);
    for(int i = 1; i <= m; i++)
        hash_y[i] = (hash_y[i-1] * coso + y[i]) % MOD;
    for(int i = 1; i <= m; i++){
        ll s = (hash_y[i-1] * mu[m-i] + get_hash(hash_y, i+1, m)) % MOD;
        if(s == hash_x) {
            cnt ++;
            res = ans;
            return ;
        }
    }
}
void xet2()
{
    reset(hash_y);
    string y = a.substr(1, n/2 + 1), x = a.substr(n/2 + 2, n/2);
    ans = x;
    x = "0" + x;
    y = "0" + y;
    ll hash_x = get_hash(hash_a, m + 1, n);
    for(int i = 1; i <= m; i++)
        hash_y[i] = (hash_y[i-1] * coso + y[i]) % MOD;
    for(int i = 1; i <= m; i++){
        ll s = (hash_y[i-1] * mu[m-i] + get_hash(hash_y, i+1, m)) % MOD;
        if(s == hash_x) {
            cnt ++;
            if (cnt > 1 && ans != res) {
                cout << "NOT UNIQUE";
                exit(0);
            }
            res = ans;
            return ;
        }
    }
}
int main() {
    nhap();
    //
    mu[0] = 1;
    for (int i = 1; i <= n; i ++)
        mu[i] = (mu[i - 1] * coso) % MOD;
    //
    hash_a[0] = 0;
    for (int i = 1; i <= n; i ++)
        hash_a[i] = (hash_a[i - 1] * coso + a[i]) % MOD;
    //
    xet1();
    xet2();
    //
    if(!cnt) {
        cout << "NOT POSSIBLE";
        return 0;
    }
    //
    cout << res;
    //
}
