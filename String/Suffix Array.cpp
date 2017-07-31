#include <bits/stdc++.h>

using namespace std;

#define FOR(i, N) FORR(i, 0, N)
#define FORR(i, a, b) FOTR(i, a, b, 1)
#define FOTR(i, a, b, c) for(int i=(a);i<(b);i+=(c))

#define MEM(a, x) memset(a,x,sizeof(a))
#define pii pair<int, int>
#define MAX 100010   //Keep MAX as small as possible
#define MAXLG 17   //ceil(log2(MAX))

struct SuffixArray {
    pair<pii, int> L[MAX];
    int P[MAXLG + 1][MAX], n, stp, cnt, sa[MAX], lcp[MAX];
    char str[MAX];

    void Generate() {
        MEM(L, 0);
        n = strlen(str);
        FOR(i, n) P[0][i] = str[i] - 1;
        sa[0] = 0;
        for (stp = 1, cnt = 1; cnt < n; stp++, cnt <<= 1) {
            FOR(i, n) L[i] =
                 { {P[stp - 1][i], (i + cnt < n)? P[stp - 1][i + cnt] : -1}, i};
            sort(L, L + n);
            FOR(i, n)P[stp][L[i].second] =
                             i > 0 && L[i].first == L[i - 1].first ?
                             P[stp][L[i - 1].second] : i;
        }
        FOR(i, n)sa[i] = L[i].second;
    }

    int LcpXY(int x, int y) {  // LcpXY(i, j) = lcp of suffixes [i...j]
        x = sa[x], y = sa[y];
        int k, ret = 0;
        if (x == y)return n - x;
        for (k = stp - 1; k >= 0 && x < n && y < n; k--) {
            if (P[k][x] == P[k][y])
                x += 1 << k, y += 1 << k, ret += 1 << k;
        }
        return ret;
    }

    void LcpArray() {
        int i, j, k;
        int *ar = new int[MAX];

        FOR(i, n) ar[sa[i]] = i;

        for (k = 0, i = 0; i < n; i++, k ? k-- : 0) {
            if (ar[i] == (n - 1))k = 0;
            else {
                j = sa[ar[i] + 1];
                while ( ((i + k) < n) && ((j + k) < n) &&
                       (str[i + k] == str[j + k]) )
                    k++;
            }
            lcp[ar[i]] = k;
        }
        delete ar;
    }
} sa;

int main() {
    sprintf(sa.str, "%s", "abcabc");
    sa.Generate();
    sa.LcpArray();

    FOR(i, 6)cout << sa.sa[i] << " ";   //3 0 4 1 5 2
    cout << "\n\n";

    FOR(i, 5)cout << sa.lcp[i] << " ";  //3 0 2 0 1
    cout << "\n\n";

    cout << sa.LcpXY(0,2) << "\n";      // 0
    cout << sa.LcpXY(2,3) << "\n";      // 2
    cout << sa.LcpXY(0,1) << "\n";      // 3
    cout << sa.LcpXY(0,0) << "\n\n";    // 3
}

// SOLVED
/* SPOJ SARRAY - Suffix Array (80)
/* SPOJ SUBLEX - Lexicographical Substring Search
 * SPOJ DISUBSTR - Distinct Substrings */
// _SOLVED