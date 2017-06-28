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

void solve(int n, int a) {
    int nume = (a*n)/180;
    if (abs(static_cast<double>(180*nume)/n - a) > abs(static_cast<double>(180*(nume+1))/n - a)) {
        nume++;
    }
    if (nume==0) {
        nume++;
    }
    if (nume > n-2) {
        nume = n-2;
    }
    std::cout << 1 << ' ' << n << ' ' << nume+1 << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int n, a;

    gettimeofday(&start,NULL);

    std::cin >> n >> a;
    solve(n, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
