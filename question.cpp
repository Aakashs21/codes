#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<ll>
#define vvi vector<vi>
#define pb push_back
#define pi pair<ll, ll>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define abs std::abs
#define fi first
#define se second
#define sq(a) ((a) * (a))
#define sz(a) (ll) a.size()
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int nc2(long long int n){
    return (n*(n-1))/2;
}

void solve() {
    long long int k,s;
    cin>>k>>s;
    if(k<s){
        cout<<nc2(s+2)-(3*nc2(s-6))<<endl;
    }
    else{
        cout<<nc2(s+2)<<endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("io/input.txt", "r", stdin);
        freopen("io/output.txt", "w", stdout);
        freopen("io/error.txt", "w", stderr);
    #endif


        solve();

    cerr << "Time:" << 1000 * ((double) clock()) / (double) CLOCKS_PER_SEC << "ms\n";

    return 0;
}