#include <iostream>
using namespace std;

#include "compiler.h"

const char* TEST1 = "12345*12*(2+3*(2+1))*(3-2)+12-123";
const char* TEST2 = "-12345*12*(-2+3*(2+1))*(-(3-2))+12-123";
const char* TEST3 = "-2*2-2";

int main(void)
{
	cout<<TEST3<<endl;
	try
	{
		cout<<expr(TEST3)<<endl;
	}
	catch(const string& err)
	{
		cerr<<err<<endl;
	}
	return 0;
}
