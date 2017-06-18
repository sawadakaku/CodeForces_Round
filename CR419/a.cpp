#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

string clock(string s) {
    s[4]++;
    if (s[4] != ':') {
        return s;
    } else {
        s[4] = '0';
        s[3]++;
        if (s[3] != '6') {
            return s;
        } else {
            s[3] = '0';
            s[1]++;
            if (s[0] == '2' && s[1] == '4') {
                s[0] = '0';
                s[1] = '0';
                return s;
            } else if (s[1] == ':')     {
                s[1] = '0';
                s[0]++;
                return s;
            } else {
                return s;
            }
        }
    }
}

void solve(string s) {
    int n = 0;
    while (true) {
        if (s[0] == s[4] && s[1] == s[3]) {
            std::cout << n << std::endl;
            break;
        } else {
            n++;
            s = clock(s);
        }
    }
}

int main() {
    struct timeval start,end;
    long long span;
    string s;

    gettimeofday(&start,NULL);

    std::cin >> s;
    solve(s);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
