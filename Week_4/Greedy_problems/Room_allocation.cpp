// url : https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<tuple<ll, ll, ll>> bookings(n);
    for (ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        bookings[i] = {a, b, i};
    }

    sort(bookings.begin(), bookings.end());

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    ll room_count = 0;
    vector<ll> ans(n);

    for (auto [start, end, idx] : bookings) {
        if (!pq.empty() && pq.top().first < start) {
            auto [prev_end, room] = pq.top(); pq.pop();
            ans[idx] = room;
            pq.push({end, room});
        } else {
            ++room_count;
            ans[idx] = room_count;
            pq.push({end, room_count});
        }
    }

    cout << room_count << "\n";
    for (ll i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
