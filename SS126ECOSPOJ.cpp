#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& a, int n, long long m, int mid) {
    long long sum = 0;          // ✅ long long to prevent overflow
    for (int i = 0; i < n; i++)
        if (a[i] > mid)
            sum += a[i] - mid;
    return sum >= m;
}

int main() {
    int n;
    long long m;                // ✅ m can also be large
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int lb = 0, ans = 0;
    int ub = *max_element(a.begin(), a.end());

    while (lb <= ub) {
        int mid = (lb + ub) / 2;
        if (solve(a, n, m, mid)) {
            ans = mid;
            lb = mid + 1;
        } else {
            ub = mid - 1;
        }
    }
    cout << ans;
    return 0;
}