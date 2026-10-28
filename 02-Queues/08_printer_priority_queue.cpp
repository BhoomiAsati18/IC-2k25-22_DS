
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job {
    string name;
    int priority;
    int order;
};

struct Compare {
    bool operator()(const Job& a, const Job& b) const {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.order > b.order;
    }
};

int main() {
    priority_queue<Job, vector<Job>, Compare> printer;
    int n;

    cout << "Enter number of print jobs: ";
    cin >> n;

    if (n <= 0) {
        cout << "No jobs to process\n";
        return 0;
    }

    cout << "Enter job name and priority:\n";
    for (int i = 0; i < n; i++) {
        string name;
        int priority;
        cin >> name >> priority;

        printer.push({name, priority, i});
    }

    cout << "\nPrinting order:\n";
    while (!printer.empty()) {
        Job job = printer.top();
        printer.pop();

        cout << job.name
             << " (priority " << job.priority << ")\n";
    }

    return 0;
}
