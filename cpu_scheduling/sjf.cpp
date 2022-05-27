// c++ program for shortest job first cpu scheduling algortihm
#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &a,
         const pair<int, int> &b)
{
    return (a.second < b.second);
}
int main()
{
    int n, p = 1;
    cout << "Enter the number of processes : ";
    cin >> n;
    vector<pair<int, int>> m;
    cout << "Enter the arrival time of each process : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << p << " : ";
        int a;
        cin >> a;
        m.push_back({a, p});
        p++;
    }
    p = 1;
    int bt[n];
    cout << "Enter the burst time of each process : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << p << " : ";
        cin >> bt[i];
        p++;
    }
    vector<pair<int, int>> m1;
    for (int i = 0; i < n; i++)
        m1.push_back({m[i].first, bt[i]});
    sort(m1.begin(), m1.end());
    int ct[n], wt[n], tat[n];
    int j = 0;
    while (!m1.empty())
    {
        ct[j] = m1[j].first + m1[j].second;
        m1.erase(m1.begin() + 0);
        sort(m1.begin(), m1.end(), cmp);
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        ct[i] = m[i].first + bt[m[i].second - 1];
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - m[i].first;
        wt[i] = tat[i] - bt[m[i].second - 1];
    }
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "p" << m[i].second << "\t" << m[i].first << "\t\t" << bt[m[i].second - 1] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t" << wt[i] << endl;
    }
    return 0;
}