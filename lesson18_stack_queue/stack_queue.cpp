#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    cout << "=== Lesson 18: stack, queue, priority_queue ===" << endl << endl;

    // stack
    cout << "【stack（LIFO）】" << endl;
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "スタックから取り出し: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl << endl;

    // queue
    cout << "【queue（FIFO）】" << endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "キューから取り出し: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;

    // priority_queue
    cout << "【priority_queue】" << endl;
    priority_queue<int> pq;
    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "優先度付きキューから取り出し: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;

    // 実用例：括弧のマッチング
    cout << "【実用例】括弧のマッチング" << endl;
    string expr = "{[()]}";
    stack<char> brackets;
    bool valid = true;

    for (char c : expr) {
        if (c == '{' || c == '[' || c == '(') {
            brackets.push(c);
        } else {
            if (brackets.empty()) {
                valid = false;
                break;
            }
            char top = brackets.top();
            brackets.pop();
            if ((c == '}' && top != '{') ||
                (c == ']' && top != '[') ||
                (c == ')' && top != '(')) {
                valid = false;
                break;
            }
        }
    }

    cout << "式 \"" << expr << "\" は " << (valid ? "有効" : "無効") << endl;

    return 0;
}
