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

void solve(int a, int b, int l, int r) {
    int ans = 0;
    int a1 = b;
    int a2 = a-1;
    int b1 = a+b;
    vector<int> s;
    vector<bool> used(26, false);
    if (b >= a) {
        for (int i = 0; i < a; i++) {
            s.push_back(i);
        }
        for (int i = 0; i < b; i++) {
            s.push_back(s.back());
        }
        for (int i = 0; i < a-1; i++) {
            s.push_back(i);
        }
        s.push_back(a+1);
        for (int i = 0; i < b; i++) {
            s.push_back(s.back());
        }
        if (r-l >= 2*b1 - 1) {
            ans = a+1;
        } else {
            l = (l-1)%(2*b1);
            r = (r-1)%(2*b1);
            while (l-1 != r) {
                if (l > 2*b1-1) {
                    l = 0;
                }
                if (!used[s[l]]) {
                    ans++;
                }
                used[s[l]] = true;
                l++;
            }
        }
    } else {
        for (int i = 0; i < a; i++) {
            s.push_back(i);
        }
        for (int i = 0; i < b; i++) {
            s.push_back(s.back());
        }
        for (int i = 0; i < b; i++) {
            s.push_back(i);
        }
        for (int i = 0; i < a-b; i++) {
            s.push_back(i+a);
        }
        for (int i = 0; i < b; i++) {
            s.push_back(s.back());
        }
        if (r-l >= 2*b1 - 1) {
            ans = 2*a -b;
        } else {
            l = (l-1)%(2*b1);
            r = (r-1)%(2*b1);
            while (l-1 != r) {
                if (l > 2*b1-1) {
                    l = 0;
                }
                if (!used[s[l]]) {
                    ans++;
                }
                used[s[l]] = true;
                l++;
            }
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    struct timeval start,end;
    long long span;
    int a, b, l, r;

    gettimeofday(&start,NULL);

    std::cin >> a >> b >> l >> r;
    solve(a, b, l, r);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
