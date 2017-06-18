#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

void solve(int n, int k, int q, vector<int> s, vector<int> f, vector<pair<int, int> > qs) {
    vector<int> a(200001, 0);
    sort(s.begin(), s.end(), greater<int>());
    sort(f.begin(), f.end(), greater<int>());
    int b = 0;
    int c = 0;
    a[0] = 0;
    for (int i = 1; i < 200001; i++) {
        while (i == s.back()) {
            b++;
            s.pop_back();
        }
        while (i-1 == f.back()) {
            b--;
            f.pop_back();
        }
        if (b >= k) {
            c = 1;
        } else {
            c = 0;
        }
        a[i] = a[i-1] + c;
    }
    for (int i = 0; i < q; i++) {
        int ans = a[qs[i].second] - a[qs[i].first - 1];
        std::cout << ans << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int n, k, q;

    gettimeofday(&start,NULL);

    std::cin >> n >> k >> q;
    vector<int> s(n);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i] >> f[i];
    }
    vector<pair<int, int> > qs(q);
    for (int i = 0; i < q; i++) {
        std::cin >> qs[i].first >> qs[i].second;
    }
    solve(n, k, q, s, f, qs);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
