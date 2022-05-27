#include <bits/stdc++.h>
using namespace std;
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
    sort(m.begin(), m.end());
    int ct[n], wt[n], tat[n];
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ct[i] = m[i].first + bt[m[i].second - 1];
        else
            ct[i] = max(m[i].first, ct[i - 1]) + bt[m[i].second - 1];
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
    cout << "Average Waiting Time : " << accumulate(wt, wt + n, 0.0) / n << endl;
    cout << "Average Turnaround Time : " << accumulate(tat, tat + n, 0.0) / n << endl;
    return 0;
}