#include <bits/stdc++.h>

using namespace std;

void deletemiddle(stack<char> *st, int middle)
{
    if (middle == 1)
    {
        st->pop();
        return;
    }
    char temp = st->top();
    st->pop();
    deletemiddle(st, middle - 1);
    st->push(temp);
}

int main()
{
    stack<char> st;
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');
    st.push('6');
    st.push('7');

    int middle = (st.size() / 2) + 1;
    deletemiddle(&st, middle);

    int _middle = (st.size() / 2) + 1;
    deletemiddle(&st, _middle);

    cout << endl;
}