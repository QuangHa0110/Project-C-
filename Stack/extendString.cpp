#include <iostream>
#include <stack>
#include <sstream>
using namespace std;
int chuyenStringToInt(stack<char> cnt)
{
    string s = "";
    cnt.pop();
    while (!cnt.empty())
    {
        s = cnt.top() + s;
        cnt.pop();
    }

    stringstream ss(s);
    int x = 0;
    ss >> x;
    return x;
}
void freeStack(stack<char> &cnt)
{
    while (!cnt.empty())
    {
        cnt.pop();
    }
}
string addString(string& rs, int count, string s)
{
    for (int i = 0; i < count; i++)
    {
        rs = rs + s;
    }
    return rs;
}
string extendString(string s)
{
    stack<char> cnt;
    string rs = "";
    string xau = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ('0' <= s[i] and s[i] < '9' and s[i] == '{')
            cnt.push(s[i]);
        else
        {
            if (s[i - 1] == '{')
                xau = xau + s[i];
            if (s[i] == '}')
            {
                rs = addString(rs, chuyenStringToInt(cnt), xau);
                xau = "";
                freeStack(cnt);
            }
            else rs=rs+s[i];
        }
    }
    return rs;
}
int main()
{   string s="4a";
    printf("%s", addString(s,4,"a"));
    return 0;
}