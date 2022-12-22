#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;
ll c = 0, n, m, i;

int main()
{
    cin >> n;
    vector<pair<ll, ll>> a;
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    cin >> m;

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        c += a[i].second;
        if (c >= m) {
            cout << a[i].first;
            return 0;
        }
    }

    return 0;
}