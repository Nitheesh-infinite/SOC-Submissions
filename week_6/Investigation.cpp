#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const ll INF = 1e17;
const ll modb = 1e9+7;
const int MAXN = 1e5+1;
vector<vector<pair<int,int>>> g(MAXN);
vector<ll> cost(MAXN);
vector<ll> route(MAXN);
vector<ll> min_f(MAXN);
vector<ll> max_f(MAXN);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(ll i = 0; i <m; ++i){
		ll u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	for(ll i = 2; i <= n; ++i){
		cost[i] = INF;
	}
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;
	pq.push({0,1});
	cost[1] = 0;
	route[1] = 1;
	while(!pq.empty()){
		ll d = pq.top().first;
		ll u = pq.top().second;
		pq.pop();
		if(d > cost[u]) continue;
		for(auto e: g[u]){
			ll v = e.first;
			ll c = e.second;
			if(c+d > cost[v]) continue;
			if(c+d == cost[v]) {
				route[v] += route[u];
				route[v] %= modb;
				min_f[v] = min(min_f[u]+1, min_f[v]);
				max_f[v] = max(max_f[u]+1, max_f[v]);
			}
			if(c+d < cost[v]){
				cost[v] = c+d;
				route[v] = route[u];
				min_f[v] = min_f[u]+1;
				max_f[v] = max_f[u]+1;
				pq.push({cost[v],v});
			}
		}
	}
	cout << cost[n] <<" " <<route[n] <<" "<<min_f[n] <<" "<<max_f[n] << endl;
}