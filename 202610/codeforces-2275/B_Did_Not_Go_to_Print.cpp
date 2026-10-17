#include <iostream>
#include <string>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define N_MAX 200000

int main() {
    int t;
    int n;
    string s;
    int stack[N_MAX];
    int stack_len = 0;
    char ch;
    bool printed[N_MAX];
    int not_printed_cnt;

    cin >> t;
    for (size_t tc = 0; tc < t; tc++)
    {
        stack_len = 0;
        not_printed_cnt = 0;
        cin >> n;
        cin.get(); // \n
        for (size_t i = 0; i < n; i++)
        {
            printed[i] = false;
        }
        for (size_t i = 0; i < n; i++)
        {
            cin.get(ch);
            switch (ch)
            {
            case '1':
                stack[stack_len++] = i;
                dbg(ch, stack_len);
                break;
            case '2':
                if (stack_len > 0) {
                    printed[stack[--stack_len]] = true;
                } else {
                    printed[i] = true;
                }
                dbg(ch, stack_len);
                break;
            case '3':
                printed[i] = true;
                break;
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            if (!printed[i]) not_printed_cnt++;
        }
        cout << not_printed_cnt << "\n";
        for (size_t i = 0; i < n; i++)
        {
            if (!printed[i]) cout << i+1 << " ";
        }
        cout << "\n";
    }
}
