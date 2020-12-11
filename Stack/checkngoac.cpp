#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
bool check(char a, char b)
{
    if (a == '(' and b == ')')
        return true;
    return false;
}
int checkngoac(string s)
{   int count=0;
    stack<char> checkngoac;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            checkngoac.push(s[i]);
        else
        {
            if (check(checkngoac.top(), s[i])){
                count++;
                checkngoac.pop();
            }
              
        }
    }
    return count;
}
int main()
{  string s="()()((()))";
   printf("%d", checkngoac(s));

    return 0;
}