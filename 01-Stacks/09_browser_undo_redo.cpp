
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Browser {
private:
    stack<string> backStack;
    stack<string> forwardStack;
    string current;

public:
    explicit Browser(const string& homepage) {
        current = homepage;
    }

    void visit(const string& url) {
        backStack.push(current);
        current = url;

        while (!forwardStack.empty()) {
            forwardStack.pop();
        }

        cout << "Visited: " << current << '\n';
    }

    void goBack() {
        if (backStack.empty()) {
            cout << "No previous page\n";
            return;
        }

        forwardStack.push(current);
        current = backStack.top();
        backStack.pop();

        cout << "Current page: " << current << '\n';
    }

    void goForward() {
        if (forwardStack.empty()) {
            cout << "No next page\n";
            return;
        }

        backStack.push(current);
        current = forwardStack.top();
        forwardStack.pop();

        cout << "Current page: " << current << '\n';
    }

    void showCurrent() const {
        cout << "Current page: " << current << '\n';
    }
};

int main() {
    Browser browser("google.com");

    browser.visit("github.com");
    browser.visit("openai.com");

    browser.goBack();
    browser.goBack();
    browser.goForward();

    browser.visit("wikipedia.org");
    browser.goForward();

    browser.showCurrent();

    return 0;
}
