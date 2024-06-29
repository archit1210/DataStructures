#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r)
{
    int ans = 1;

    for (int i = 0; i < r; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    return ans;
}

int main()
{
    int n, r;

    cout << "Enter the value of N : " << endl;
    cin >> n;

    cout << "Enter the value of R : " << endl;
    cin >> r;

    int ans = solve(n, r);

    cout << ans << endl;
    return 0;
}