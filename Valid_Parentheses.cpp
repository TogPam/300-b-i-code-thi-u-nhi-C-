//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid./
#include <stack>
#include <bits/stdc++.h>
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=i+1;j<n;j++)
using namespace std;

bool valid(char x, char y)
{
    if(x=='(' && y==')') return true;
    if(x=='{' && y=='}') return true;
    if(x=='[' && y==']') return true;
    return false;
}

bool Parentheses(string s)
{
    stack<char> a;
    for(char c : s)
    {
        if(c == '(' ||c == '[' || c == '{')
            a.push(c);
        else
        {
            if(a.empty())
            {
                 if(c == ')' ||c == ']' || c == '}')
                    return false;
                 else if(c != ')' ||c != ']' || c != '}' || c != '(' ||c != '[' || c != '{') 
                    continue;
            }
            else if(valid(a.top(), c))
                a.pop();
        }
    }
    if(a.empty()) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    getline(cin,s);

    if(Parentheses(s)) cout<<"VALID!\n";
    else cout<<"WRONG!\n";

    return 0;
}
