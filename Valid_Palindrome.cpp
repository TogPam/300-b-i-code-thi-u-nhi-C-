//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//Given a string s, return true if it is a palindrome, or false otherwise.
#include <bits/stdc++.h>
#include <cctype>
#include <ios>
#define cc cout<<
using namespace std;

bool isPalindrome(string s)
{
    string fixed;
   for(auto c : s)
   {
        if(isalpha(c) || c == '0' || c == '1'|| c == '2'|| c == '3'|| c == '4'
                      || c == '5'|| c == '6'|| c == '7'|| c == '8'|| c == '9')

            fixed+= tolower(c);
   }
   int left = 0, right = fixed.length() - 1;

   while(left<=right)
   {
       if(fixed[left] != fixed[right]) return false;
       left++, right--;
   }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    getline(cin,s);
    if(isPalindrome(s)) cc"VALID!\n";
    else cc"WRONG!\n";
    return 0;
}
