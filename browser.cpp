#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    cout << "Initial top page: " << history.top() << endl;

    for (int i = 0; i < 2; i++) {
        if (!history.empty())
            history.pop();
    }

    if (!history.empty())
        cout << "Top page after two Back presses: "
             << history.top() << endl;
    else
        cout << "No pages in history.\n";

    return 0;
}
