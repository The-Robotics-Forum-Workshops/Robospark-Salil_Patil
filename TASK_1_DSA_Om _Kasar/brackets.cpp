
#include<iostream>
#include<stack>
#include<string>
using namespace std;

 

bool Pair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool BalancedParanthesis(string str1)
{
	stack<char>  S1;
	for(int i =0;i<str1.length();i++)
	{
		if(str1[i] == '(' || str1[i] == '{' || str1[i] == '[')
			S.push(str1[i]);
		else if(str1[i] == ')' || str1[i] == '}' || str1[i] == ']')
		{
			if(S.empty() || !Pair(S.top(),str1[i]))
				return false;
			else
				S.pop();
		}
	}
	return S1.empty() ? true:false;
}

int main()
{
	
	
	string str;
	cout<<"Enter an expression:  "; 
	cin>>str;
	
	if(BalancedParantheses(str))
		cout<<"Parantheses are Balanced\n";
	
	else
		cout<<"Parantheses are not Balanced\n";
}

