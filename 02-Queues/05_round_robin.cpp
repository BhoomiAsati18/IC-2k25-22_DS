
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    int id;
    int remaining;
};

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of processes\n";
        return 0;
    }

    vector<int> burst(n);
    cout << "Enter burst times: ";

    for (int i = 0; i < n; i++) {
        cin >> burst[i];
        if (burst[i] <= 0) {
            cout << "Burst times must be positive\n";
            return 0;
        }
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    if (quantum <= 0) {
        cout << "Time quantum must be positive\n";
        return 0;
    }

    queue<Process> q;

    for (int i = 0; i < n; i++)
        q.push({i + 1, burst[i]});

    int currentTime = 0;

    cout << "\nExecution order:\n";

    while (!q.empty()) {
        Process p = q.front();
        q.pop();

        int runTime = (p.remaining < quantum)
                      ? p.remaining : quantum;

        currentTime += runTime;
        p.remaining -= runTime;

        cout << "P" << p.id
             << " runs for " << runTime
             << " units; time = " << currentTime << '\n';

        if (p.remaining > 0)
            q.push(p);
        else
            cout << "P" << p.id << " completed\n";
    }

    cout << "Total execution time: "
         << currentTime << '\n';

    return 0;
}
