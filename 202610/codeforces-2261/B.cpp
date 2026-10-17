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
    llong arr[N_MAX];

    cin >> t;
    for (size_t tc = 0; tc < t; tc++)
    {
        cin >> n;
        llong or_sum = 0;
        llong m = 100000000000;
        llong M = 0;
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
            or_sum |= arr[i];
            m = min(m, arr[i]);
            M = max(M, arr[i]);
        }

        llong at = 1;
        while (at <= or_sum)
        {
            if ((or_sum & at) == 0)
            {
                llong target = m | at;
                if (target <= M)
                {
                    or_sum |= at;
                }
            }

            at <<= 1;
        }

        cout << or_sum << "\n";
    }
}
