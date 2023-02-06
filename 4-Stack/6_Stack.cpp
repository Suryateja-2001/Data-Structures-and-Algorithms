// stack using STL (Standarad Template Library)

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);

    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}