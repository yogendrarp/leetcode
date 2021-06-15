#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

map<string, string> tokenize(string input)
{
    map<string, map<string, string> > parser;
    map<string, string> tokensmap;

    bool firstspace = false;

    vector<string> tokens;
    string tk = "";

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        if (ch == ' ' || ch == '>')
        {
            firstspace = true;
            if (!tk.empty() && tk != "=")
                tokens.push_back(tk);
            tk = "";
        }
        else if (firstspace == false)
            continue;
        else if (ch != '\"')
        {
            tk += ch;
        }
    }

    for (int i = 0, j = 1; j < tokens.size(); i = i + 2, j = j + 2)
    {
        tokensmap.insert(make_pair(tokens[i], tokens[j]));
    }
    return tokensmap;
}

pair<string, map<string, string> > getmap(string line, string &present_key)
{

    string firsttoken = line.substr(0, line.find(' '));
    if (firsttoken.find('>') != string::npos)
    {
        firsttoken = line.substr(0, firsttoken.size() - 1);
    }

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
        return make_pair(present_key, tokenize(line));
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
    map<string, string> bl;
    return make_pair("", bl);
}

int main()
{
    int n, q;
    cin >> n >> q;

    map<string, map<string, string> > tokens;

    string present_key = "";
    for (int i = 0; i <= n; i++)
    {
        string _temp;
        getline(cin, _temp);
        tokens.insert(getmap(_temp, present_key));
    }

    for (int i = 0; i < q; i++)
    {
        string _temp;
        getline(cin, _temp);
        int sub_key_pos = _temp.find('~');
        string main_key = _temp.substr(0, sub_key_pos);
        string sub_key = _temp.substr(sub_key_pos + 1, (_temp.size() - sub_key_pos));
        map<string, map<string, string> >::iterator it = tokens.find(main_key);
        if (it != tokens.end())
        {
            map<string, string> sub_map = it->second;
            map<string, string>::iterator sub_map_it = sub_map.find(sub_key);
            if (sub_map_it != sub_map.end())
            {
                cout << sub_map_it->second << endl;
            }
            else
            {
                cout << "Not Found!" << endl;
            }
        }
        else
        {
            cout << "Not Found!" << endl;
        }
    }

    return 0;
}
