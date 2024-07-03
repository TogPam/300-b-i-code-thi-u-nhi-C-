//Input: s = "anagram", t = "nagaram"
//Output: true
#include <iostream>
#include <map>

bool validAnagram(std::string a, std::string b)
{
	std::map<char, int> s1;
	std::map<char, int> s2;
	
	for(char i : a) s1[i]++;
	for(char i : b) s2[i]++;

	if(s1 == s2) return true;
	else return false;
}

int main()
{
	std::string a = "a";
	std::string b = "a";
	std::cout<<a<<"\n";
	std::cout<<b<<"\n";
	if(validAnagram(a,b)) std::cout<<"DUNG";
	else std::cout<<"SAI"; 
	
    return 0;
}