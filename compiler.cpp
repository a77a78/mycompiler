#include <iostream>
using namespace std;

#include <string>

int expr(const string&);

bool isNum(const char ch)
{
	return ch>='0' && ch<='9';
}

int toNum(const string& s)
{
	if(s[0] == '-')
	{
//		We need expr not toNum here, for situations like -(-a)
		return -expr(s.substr(1, s.length()));
	}

	int res = 0;

	for(size_t i = 0; i < s.length(); i++)
	{
		if(isNum(s[i]))
		{
//			(s[i]-'0') converts char to int
			res = res*10 + s[i]-'0';
		}
		else
		{
			throw "Can't read a number " + s;
		}
	}

	return res;
}

int getOperatorPos(const string& s)
{
	int currentlyFound = -1;
	int openedParentheses = 0;

//	(-) and (/) are left-associative so we need to go from
//	the end to divide expression into operands correctly
	for(size_t i = s.length(); i > 0; i--)
	{
		switch (s[i])
		{
			case '(':
				if(openedParentheses == 0)
				{
					throw "There are more closed than opened parentheses in " + s;
				}
				openedParentheses++;
				break;
			case ')':
				openedParentheses--;
				break;
			case '+':
				if(openedParentheses == 0)
				{
					return i;
				}
				break;
			case '-':
//				Special case for unary minus - it is not operation but a part of number
				if(openedParentheses == 0 && !(i == 0 || s[i-1] == '('))
				{
					return i;
				}
				break;
			case '*':case '/':
				if(openedParentheses == 0 && currentlyFound == -1)
				{
					currentlyFound = i;
				}
				break;
			default: break;
		}
	}

	return currentlyFound;
}

const string removeOuterParentheses(const string& s)
{
	if(s[0] == '(' && s[s.length()-1] == ')')
	{
		int openedNum = 1;
		for(size_t i = 1; i < s.length()-1; i++)
		{
			if(s[i] == '(')
			{
				openedNum++;
			}
			else if(s[i] == ')')
			{
				openedNum--;
				if(openedNum == 0)
				{
					return s;
				}
			}

		}
		return s.substr(1, s.length()-2);
	}
	else
	{
		return s;
	}
}

int expr(const string& s1)
{
	string s = removeOuterParentheses(s1);
//	cout<<s<<endl;

	if(getOperatorPos(s) == -1)
	{
		return toNum(s);
	}

	int leftOperand = expr(s.substr(0, getOperatorPos(s)));
	int rightOperand = expr(s.substr(getOperatorPos(s)+1, s.length()));

	switch (s[getOperatorPos(s)])
	{
		case '+': return leftOperand + rightOperand;
		case '-': return leftOperand - rightOperand;
		case '*': return leftOperand * rightOperand;
		case '/': return leftOperand / rightOperand;
	}

//	Actually we will never come here
	return -1;
}
