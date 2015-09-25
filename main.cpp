#include <iostream>
using namespace std;

#include "compiler.h"

const char* TEST = "12345*12*(2+3*(2+1))*(3-2)+12-123";

int main(void)
{
	try
	{
		cout<<expr(TEST)<<endl;
	}
	catch(const string& err)
	{
		cerr<<err<<endl;
	}
	return 0;
}
