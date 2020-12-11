#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;
int transferStringToInt(string s)
{
    stringstream ss(s);
    int rs = 0;
    ss >> rs;
    return rs;
}
int sumStack(stack<int> s)
{

    int a = s.top();
    s.pop();
    int b = s.top();
    s.push(a);
    return a + b;
}
int baseballGame(vector<string> s)
{
    stack<int> cnt;
    for (int i = 0; i < s.size(); i++)
    {

        if (s.at(i) == "+")
        {
            cnt.push(sumStack(cnt));
        }

        else if (s.at(i) == "C")
        {
            cnt.pop();
        }
        else if (s.at(i) == "D")
        {
            int c = cnt.top();
            cnt.push(c * 2);
        }
        else
        {
            cnt.push(transferStringToInt(s.at(i)));
        }
    }
    int rs = 0;
    while (!cnt.empty())
    {
        rs = rs + cnt.top();
        cnt.pop();
    }
    return rs;
}
int main()
{
    vector<string> s = {"2", "10", "D", "C", "D", "+", "13", "-1"};

    printf("%d", baseballGame(s));
    return 0;
}