// url : 

#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<ll,ll>>> g;
vector<vector<ll>> dist; 
const ll INF = 1e18;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    ll n, m, k;
	cin >> n >> m >> k;
	g.resize(n+1);
	dist.resize(n+1);
	for(ll i = 1; i <= n; i++){
		dist[i].resize(k);
		for(ll j = 0; j <k; ++j){
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
	for(ll i = 0; i < m; ++i){
		ll u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v,c});
	}
	priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; 
	pq.push({0,1});
	while(!pq.empty()){
		ll u = pq.top().second;
		ll d = pq.top().first;
		pq.pop();
		if(dist[u][k-1] < d) continue;
		for(auto e: g[u]){
			ll v = e.first;
			ll c = e.second;
			if(dist[v][k-1] > c+d) {
				dist[v][k-1] = c+d;
				pq.push({dist[v][k-1], v});
				sort(dist[v].begin(), dist[v].end());
			}
		}
	}
 
	for(int i = 0; i < k; ++i){
		cout << dist[n][i] << " ";
	}
}