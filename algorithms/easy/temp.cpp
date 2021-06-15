#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

int main()
{

    // vector<vector<int> > vectors_collection;
    // int rowlength, queries;
    // cin >> rowlength;
    // cin >> queries;
    // for (int i = 0; i < rowlength; i++)
    // {
    //     int size;
    //     cin >> size;
    //     vector<int> v1;
    //     int temps;
    //     for (int i = 0; i < size; i++)
    //     {
    //         cin >> temps;
    //         v1.push_back(temps);
    //     }

    //     vectors_collection.push_back(v1);
    // }
    // for (int i = 0; i < queries; i++)
    // {
    //     int row, col;
    //     cin >> row;
    //     cin >> col;
    //     cout << vectors_collection[row][col] << endl;
    // }

    // string a, b;
    // cin >> a;
    // cin >> b;
    // cout<<a.length()<<" "<<b.length()<<endl;
    // cout << (a + b) << endl;
    // char temp = a[0];
    // a[0] = b[0];
    // b[0] = temp;
    // cout << a << " " << b << endl;

    // int size;
    // cin >> size;
    // vector<int> v1;
    // int temps;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> temps;
    //     v1.push_back(temps);
    //}

    // int first_pos, second_start, second_end;
    // cin >> first_pos;
    // cin >> second_start;
    // cin >> second_end;

    // v1.erase(v1.begin() + first_pos-1);
    // v1.erase(v1.begin() + second_start, v1.begin() + second_end);

    // cout << v1.size() << endl;
    // for (int i = 0; i < v1.size(); i++)
    // {
    //     cout << v1[i] << " ";
    // }

    // int queries;
    // cin >> queries;

    // for (int i = 0; i < queries; i++)
    // {
    //     int key;
    //     cin >> key;
    //     vector<int>::iterator lower;
    //     lower = lower_bound(v1.begin(), v1.end(), key);
    //     if (*lower == key)
    //     {
    //         cout << "Yes "
    //              << (lower - v1.begin() + 1) << '\n';
    //     }
    //     else
    //     {
    //         cout << "No "
    //              << (lower - v1.begin() + 1) << '\n';
    //     }
    // }

    // set<int> s;
    // int queries;
    // cin >> queries;
    // for (int i = 0; i < queries; i++)
    // {
    //     int operation, value;
    //     cin >> operation;
    //     cin >> value;
    //     if (operation == 1)
    //     {
    //         s.insert(value);
    //     }
    //     else if (operation == 2)
    //     {
    //         s.erase(value);
    //     }
    //     else if (operation == 3)
    //     {
    //         set<int>::iterator itr = s.find(value);
    //         if (itr == s.end())
    //         {
    //             cout<<"No\n";
    //         }
    //         else
    //         {
    //             cout<<"Yes\n";
    //         }
    //     }
    // }

    // map<string, int> m;
    // int queries;
    // cin >> queries;
    // for (int i = 0; i < queries; i++)
    // {
    //     int operation, value;
    //     string key;
    //     cin >> operation;

    //     if (operation == 1)
    //     {
    //         cin >> key;
    //         cin >> value;
    //         m[key] = m[key] + value;
    //     }
    //     else if (operation == 2)
    //     {
    //         cin >> key;
    //         m.erase(key);
    //     }
    //     else if (operation == 3)
    //     {
    //         cin >> key;
    //         cout << m[key] << endl;
    //     }
    // }

    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while (T--)
    {
        double A;
        cin >> A;
        double B;
        cin >> B;
        double C;
        cin >> C;
        cout << std::hex << std::nouppercase << std::left << std::showbase;
        cout << (int)A << endl;

        cout << std::dec << std::right << std::setw(15) << std::setfill('_') << std::showpos << std::fixed << std::setprecision(2);
        cout << B << endl;

        cout << std::scientific << std::uppercase << std::noshowpos << std::setprecision(9);
        cout << C << endl;
    }

    return 0;
}