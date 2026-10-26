
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
using namespace std;

class FreqStack {
private:
    unordered_map<int, int> frequency;
    unordered_map<int, vector<int>> group;
    int maxFrequency = 0;

public:
    void push(int x) {
        int f = ++frequency[x];

        if (f > maxFrequency) {
            maxFrequency = f;
        }

        group[f].push_back(x);
    }

    int pop() {
        if (maxFrequency == 0) {
            throw runtime_error("Frequency stack is empty");
        }

        int x = group[maxFrequency].back();
        group[maxFrequency].pop_back();

        --frequency[x];

        if (group[maxFrequency].empty()) {
            --maxFrequency;
        }

        return x;
    }
};

int main() {
    FreqStack fs;

    fs.push(5);
    fs.push(7);
    fs.push(5);
    fs.push(7);
    fs.push(4);
    fs.push(5);

    cout << "Popped: " << fs.pop() << '\n';
    cout << "Popped: " << fs.pop() << '\n';
    cout << "Popped: " << fs.pop() << '\n';
    cout << "Popped: " << fs.pop() << '\n';

    return 0;
}
