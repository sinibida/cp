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

#define min(x, y) ((x) <= (y) ? (x) : (y))
#define max(x, y) ((x) >= (y) ? (x) : (y))
typedef long long llong;

#define N_MAX 200000

int main()
{
    llong t;
    llong n;

    cin >> t;
    for (size_t tc = 0; tc < t; tc++)
    {
        cin >> n;
        int m = 10000;
        int M = 0;
        int cnt = 0;
        string s;
        cin >> s;
        for (size_t i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                m = min(m, i);
                M = max(M, i);
                cnt += 1;
            }
        }
        if (cnt == 2)
        {
            cout << 1 << "\n";
            continue;
        }
        cout << M - m << "\n";
    }
}

// Wrong on 2?
