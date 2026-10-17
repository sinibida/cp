#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cout << ' ' << H;
    dbg_out(T...);
}
template <typename A>
void dbg_arr_out(A arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        cout << ' ' << arr[i];
    }
    cout << endl;
}
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define dbg_arr(arr, len) cout << "(" << #arr << "[:" << len << "]):", dbg_arr_out(arr, len)
#else
#define dbg(...)
#define dbg_arr(arr, len)
#endif

#define min(x,y) (x) <= (y) ? (x) : (y)
#define max(x,y) (x) >= (y) ? (x) : (y)
typedef long long llong;

#define N_MAX 200000

int main()
{
    llong t;
    llong n;
    llong keys[N_MAX];
    pair<llong, llong> triads[N_MAX];

    cin >> t;
    for (size_t tc = 0; tc < t; tc++)
    {
        cin >> n;
        for (size_t i = 0; i < n; i++)
        {
            cin >> keys[i];
        }
        for (size_t i = 0; i < n - 4; i++)
        {
            triads[i] = make_pair(i, keys[i] + keys[i + 2] - keys[i + 4]);
        };
        sort(triads, triads + (n - 4), [](pair<llong, llong> a, pair<llong, llong> b)
             { return a.second == b.second ? a.first < b.first : a.second < b.second; });
        llong from = 0;
        llong to = 0;
        auto last = triads[0];
        llong total_cnt = 0;
        for (size_t i = 1; i < n - 4 + 1; i++)
        {
            auto cur = triads[i % (n-4)];
            if (i == (n-4) || last.second != cur.second) {
                to = i;

                llong size = to - from;
                if (size >= 2) {
                    llong cnt = size * (size-1) / 2;
                    for (size_t j = from; j < to; j++)
                    {
                        llong end = min(j+5, to);
                        for (size_t k = j+1; k < end; k++)
                        {
                            if (triads[j].first+2 == triads[k].first ||
                            triads[j].first+4 == triads[k].first) {
                                cnt--;
                            }
                        }
                        dbg(from, to, end, j, cnt);
                    }
                    total_cnt += cnt;
                }

                from = to;
            }
            last = cur;
        }
        cout << total_cnt << '\n';
        dbg_arr(triads, n-4);
    }
}
