#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Matrix
{
public:
    vector<vector<int> > a;

    Matrix operator+(const Matrix &m1)
    {
        Matrix sum(*this);
        for (size_t i = 0; i < a.size(); i++)
        {
            for (size_t j = 0; j < a[i].size(); j++)
            {
                sum.a[i][j] += m1.a[i][j];
            }
        }
        return sum;
    }
};

using namespace std;
int main()
{
    // map<string, map<string, string> > parser;
    // map<string, string> tokensmap;

    // bool firstspace = false;

    // vector<string> tokens;
    // string tk = "";
    // string input = "<tag1 value = \"HelloWorld\" apple = \"mango\" banana = \"grape\">";
    // for (int i = 0; i < input.length(); i++)
    // {
    //     char ch = input[i];
    //     if (ch == ' ' || ch == '>')
    //     {
    //         firstspace = true;
    //         if (!tk.empty() && tk != "=")
    //             tokens.push_back(tk);
    //         tk = "";
    //     }
    //     else if (firstspace == false)
    //         continue;
    //     else if (ch != '\"')
    //     {
    //         tk += ch;
    //     }
    // }

    // for (int i = 0, j = 1; j < tokens.size(); i = i + 2, j = j + 2)
    // {
    //     tokensmap.insert(make_pair(tokens[i], tokens[j]));
    // }

    // string key = "tag1.tag2~name";
    // int sub_key_pos = key.find('~');
    // string main_key = key.substr(0, sub_key_pos);
    // string sub_key = key.substr(sub_key_pos + 1, (key.size() - sub_key_pos));
    // cout << main_key << endl;
    // cout << sub_key << endl;

    // cout << endl;
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++)
    {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++)
        {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++)
            {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        cout << x.a.size() << endl;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}