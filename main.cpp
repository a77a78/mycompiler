#include <iostream>
using namespace std;

#include "compiler.h"

const char* TEST1 = "12345*12*(2+3*(2+1))*(3-2)+12-123";
const char* TEST2 = "-12345*12*(-2+3*(2+1))*(-(3-2))+12-123";
const char* TEST3 = "-2*2-2";
const char* TEST4 = "-1-2-3";

int main(void)
{
	cout<<TEST4<<'=';
	try
	{
		cout<<expr(TEST4)<<endl;
	}
	catch(const string& err)
	{
		cerr<<err<<endl;
	}
	return 0;
}
