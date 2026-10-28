
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
    int id;
    int retriesLeft;
    vector<int> outcomes;
    int attempt = 0;
};

struct Compare {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.id > b.id;
    }
};

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    if (n <= 0) {
        cout << "No tasks to process\n";
        return 0;
    }

    priority_queue<Task, vector<Task>, Compare> tasks;

    for (int i = 0; i < n; i++) {
        Task t;
        int outcomeCount;

        cout << "Enter task name, priority, max retries, "
             << "number of outcomes: ";
        cin >> t.name >> t.priority >> t.retriesLeft >> outcomeCount;

        if (t.retriesLeft < 0 || outcomeCount <= 0) {
            cout << "Invalid retry count or outcomes\n";
            return 0;
        }

        t.id = i;
        cout << "Enter outcomes (1=success, 0=failure): ";

        for (int j = 0; j < outcomeCount; j++) {
            int result;
            cin >> result;

            if (result != 0 && result != 1) {
                cout << "Outcomes must be 0 or 1\n";
                return 0;
            }
            t.outcomes.push_back(result);
        }

        tasks.push(t);
    }

    cout << "\nTask execution:\n";

    while (!tasks.empty()) {
        Task t = tasks.top();
        tasks.pop();

        t.attempt++;
        int result = t.outcomes[
            min(t.attempt - 1, (int)t.outcomes.size() - 1)
        ];

        cout << t.name << " attempt " << t.attempt << ": ";

        if (result == 1) {
            cout << "Success\n";
        } else if (t.retriesLeft > 0) {
            cout << "Failed; retrying later\n";
            t.retriesLeft--;
            tasks.push(t);
        } else {
            cout << "Failed; retries exhausted\n";
        }
    }

    return 0;
}
