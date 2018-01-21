#include<conio.h>
#include<fstream.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<iomanip.h>
#include<time.h>
#include<stdlib.h>

#define gt gotoxy
#define tc textcolor
#define tb textbackground
#define wn window
#define fw windoe(1,1,80,25);
#define ew windoe(1,2,80,25);

struct save
{	int bgc; char logp[25];
};


int main();             void clean();
int scrutin();		void srite();
void bgd(int);          void mbar();
void mbar1();           void sfunc();
void sgo(int); 		void sett();
void salut();           void calc();
void sketch();          void answer();
int scr(); 		void scw();
void start();           void logout();

