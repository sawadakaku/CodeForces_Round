#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

void solve(int c, int v0, int v1, int a, int l) {
    int ans = 1;
    c -= v0;
    while (c > 0) {
        c -= min(v1 - l, v0 + (ans*a) - l);
        ans++;
    }
    std::cout << ans << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int c, v0, v1, a, l;

    gettimeofday(&start,NULL);

    std::cin >> c >> v0 >> v1 >> a >> l;
    solve(c, v0, v1, a, l);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
