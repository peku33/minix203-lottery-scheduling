#include <lottery.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ArgC, char ** ArgV)
{
	
	int MyPriority = 0;
	int MyPid;
	int ChangeResult;
	unsigned int I, J;
	if(ArgC != 2)
	{
		printf("Uzycie: %s <priorytet tej aplikacji>\n", ArgV[0]);
		return 1;
	}
	
	MyPriority = atoi(ArgV[1]);
	MyPid = getpid();
	
	if(MyPriority < 1 || MyPriority > 20)
	{
		printf("");
	}
	
	printf("== Zmieniam sobie (%d) priorytet na: %d\n", MyPid, MyPriority);
	ChangeResult = setlot(MyPid, MyPriority);
	printf("== Wynik operacji zmiany biletow: %d\n", ChangeResult);
	MyPriority = getlot(MyPid);
	printf("== Po zmianie mam: %d\n", MyPriority);
	
	for(I = 0; I < 16; I++)
	{
		for(J = 0; J < 65535 * 256; J++) {}
		printf("== Petla z priorytetem %d konczy obrot: %d\n", MyPriority, I + 1);
	}
	
	printf("== Koncze: %d\n", MyPriority);

	return 0;
}
