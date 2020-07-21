#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define Time srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#define OJ \
freopen("input.txt", "r", stdin); \
freopen("output.txt", "w", stdout);
void solve() {
cout<<"hello World\n";
int i, j, n, m;
}
int main()
{
    OJ
    int i=3;
    int **j;
    cout<<"Address"<<&i<<endl;
    cout<<"Reference"<<*(&i)<<endl;
    j=&&i;
    cout<<"&j"<<&j<<endl;
    cout<<"*j"<<*j<<endl;
    cout<<"j"<<j<<endl;

return 0;
}