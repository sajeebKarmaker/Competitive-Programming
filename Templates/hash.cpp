#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << " , " << #y << "=" << y << endl

typedef pair<int, int>ii;
typedef pair<ll, ll>pl;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<ii>vii;
typedef vector<pl>vll;
typedef vector<pl>vll;
typedef vector<vi>vvi;
typedef vector<vl>vvl;

const int N = 1e5+5, M = N;
//87  33
//0 115 999998921 500011786 749876552 126296567 15

const ll mod1 = 2e9+87, base1 = 1e9+33, base2 = 1e9+21, mod2 = 2e9+63;
ll h[N], pw[N], slen, mod=1, base=1;
char s[N];

void pw_calc()
{
	pw[0] = 1;
	for(ll i=1 ; i<=N ; i++) pw[i] = (pw[i-1]*base)%mod;
}

void hash_init()
{
	h[0] = s[0]%mod;

	for(int i=1 ; s[i] != '\0' ; i++)	h[i] = (h[i-1]*base + s[i])%mod;
}

ll get_hash(ll l, ll r)
{
	ll hsh;

	if(l == 0) hsh = h[r]%mod;
	else hsh = (h[r] - h[l-1]*pw[r-1+1])%mod;

	if(hsh < 0) hsh += mod;

	return hsh;
}

void solve()
{
    ll n, m;
    cin >> s;
    slen = strlen(s);

    hash_init();

    for(int i=0 ; i<slen ; i++) printf("%lld ",h[i]);
}


int main()
{
	int t = 1;

    scanf("%d",&t);

    while(t--)
    {
        solve();
    }

    return 0;
}