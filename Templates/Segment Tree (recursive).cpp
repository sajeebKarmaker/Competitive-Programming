#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define lft				(node*2)
#define rgt				(node*2 + 1)

/*
	Summation Segment Tree
	Tested : CSES 1648
*/

const ll N = 1e5;
ll ar[N+5], tree[4*N];

void build(ll l, ll r, ll node)
{
	if(l == r)
	{
		tree[node] = ar[l];
		return;
	}
	ll mid = (l+r)/2;
	build(l, mid, lft);
	build(mid+1, r, rgt);
	tree[node] = tree[lft] + tree[rgt];
	return;
}

ll query(ll l, ll r, ll node, ll x, ll y)
{
	if(x > y) return 0LL;
	if(l>=x && r<=y) return tree[node];
	ll mid = (l+r)/2;
	ll a = query(l, mid, lft, x, min(mid, y)) , b = query(mid+1, r, rgt, max(x, mid+1), y);
	return a + b;
}

void update(ll l, ll r, ll node, ll idx)
{
	if(l == r)
	{
		tree[node] = ar[idx];
		return;
	}
	ll mid = (l+r)/2;
	if(idx <= mid) update(l, mid, lft, idx);
	else update(mid+1, r, rgt, idx);
	tree[node] = tree[lft] + tree[rgt];
}


