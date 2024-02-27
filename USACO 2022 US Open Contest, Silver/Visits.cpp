#include <string>
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define endl '\n'
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double ld;
#define pii pair<int,int>
#define sz(x) ((ll)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define frev(a,b,c) for(int a=c; a>=b; a--)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
#define done(x) {cout << x << endl;return;}
#define mini(x,y) x = min(x,y)
#define maxi(x,y) x = max(x,y)
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
//const int mod = 998244353;
const int mod = 1e9 + 7;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef map<int, int> mii;
typedef set<int> si;
typedef set<pair<int,int>> spii;
typedef queue<int> qi;
uniform_int_distribution<int> rng(0, 1e9);

// DEBUG FUNCTIONS START
void __print(int x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void deb() {cerr << "\n";}
template <typename T, typename... V> void deb(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; deb(v...);}
// DEBUG FUNCTIONS END


const int N = 1e5 + 5;

vi g[N];
int a[N];
int vis[N];
vi path;
si visited;
bool cycle_found;



void dfs(int v)
{
    //deb(v);
    vis[v] = 1;
    path.pb(v);
    visited.insert(v);

    for(int to : g[v])
    {
        if(vis[to])
        {
            if(visited.count(to))
            {
                path.pb(to);
                cycle_found = 1;
                return;
            }

            path.pop_back();
            return;
        }

        dfs(to);

        if(cycle_found)
            return;
    }

    path.pop_back();
}


void solve(){
    
    
    int n, ans = 0;
    cin >> n;

    fr(i,1,n)
    {
        int to, value;
        cin >> to >> value;

        g[i].pb(to);
        a[i] = value;
        ans += value;
    }
    

    fr(i,1,n)
    {
        if(!vis[i])
        {
            cycle_found = 0;
            visited.clear();
            path.clear();

            dfs(i);
            //deb(path, cycle_found);

            if(cycle_found)
            {
                reverse(all(path));

                while(path.back() != path[0])
                    path.pop_back();

                int x = infl;

                for(int v : path)
                {
                    mini(x, a[v]);
                }

                ans -= x;
            }  
        }
    }


    cout << ans << endl;

}




signed main(){
    
    ios_base::sync_with_stdio(0), cin.tie(0);
    cout << fixed << setprecision(15);
    int t = 1;
    //cin >> t;

    while (t--)
        solve();
    return 0;
}

int powm(int a, int b){
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
