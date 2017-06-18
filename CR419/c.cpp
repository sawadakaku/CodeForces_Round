#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>

using namespace std;

void solve(int n, int m, vector< vector<int> > mat) {
    vector< vector<int> > tmp(m, vector<int>(n));
    bool flaga = false;
    if (n > m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[j][i] = mat[i][j];
            }
        }
        mat = tmp;
        int t = n;
        n = m;
        m = t;
        flaga = true;
    }
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        int minel = *min_element(mat[i].begin(), mat[i].end());
        for (int j = 0; j < m; j++) {
            mat[i][j] -= minel;
        }
        for (int k = 0; k < minel; k++) {
            string s = "row ";
            if (flaga) {
                s = "col ";
            }
            s += to_string(i+1);
            ans.push_back(s);
        }
    }
    for (int i = 0; i < m; i++) {
        int minel2 = 600;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] < minel2) {
                minel2 = mat[j][i];
            }
        }
        for (int j = 0; j < n; j++) {
            mat[j][i] -= minel2;
        }
        for (int k = 0; k < minel2; k++) {
            string s = "col ";
            if (flaga) {
                s = "row ";
            }
            s += to_string(i+1);
            ans.push_back(s);
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (0 != *max_element(mat[i].begin(), mat[i].end())) {
            flag = false;
        }
    }
    if (flag) {
        std::cout << ans.size() << std::endl;
        while (!ans.empty()) {
            std::cout << ans.back() << std::endl;
            ans.pop_back();
        }
    } else {
        std::cout << "-1" << std::endl;
    }
}

int main() {
    struct timeval start,end;
    long long span;
    int n, m;

    gettimeofday(&start,NULL);

    std::cin >> n >> m;
    vector< vector<int> > mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> mat[i][j];
        }
    }
    solve(n, m, mat);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}
