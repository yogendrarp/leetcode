#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

pair<string, string> getpair(string line, string &present_key)
{

    string firsttoken = line.substr(0, line.find(' '));

    if (firsttoken.find("</") == string::npos)
    {
        firsttoken.erase(std::remove(firsttoken.begin(), firsttoken.end(), '<'), firsttoken.end());
        if (present_key.empty())
        {
            present_key = firsttoken;
        }
        else
        {
            present_key += ("." + firsttoken);
        }

        return make_pair(present_key, line);
    }
    else
    {
        int index_pos = present_key.find_last_of('.');
        if (index_pos == -1)
        {
            present_key = "";
        }
        else
        {
            present_key = present_key.substr(0, index_pos);
        }
    }
    return make_pair("", "");
}

void display_key_if_found(map<string, string> &tokens, string key)
{
    int tilda_pos = key.find_first_of('~');
    string main_key = key.substr(0, tilda_pos);
    map<string, string>::iterator it = tokens.find(main_key);
    if (it == tokens.end())
        cout << "Not Found!" << endl;
    else
    {
        string attribs = it->second;
        string sub_key = key.substr(tilda_pos + 1, key.length() - 1);
        string sub_key_with_eq = sub_key + " = ";
        int index_pos = attribs.find(sub_key_with_eq);
        int end_pos_1 = attribs.find("\" ");
        int end_pos_2 = attribs.find("\">");
        
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, string> tokens;

    string present_key = "";
    for (int i = 0; i <= n; i++)
    {
        string _temp;
        getline(cin, _temp);
        tokens.insert(getpair(_temp, present_key));
    }

    for (int j = 0; j < q; j++)
    {
        string _temp;
        getline(cin, _temp);
        display_key_if_found(tokens, _temp);
    }

    return 0;
}
