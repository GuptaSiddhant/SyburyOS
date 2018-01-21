#include"file.cpp"

void start()

{       randomize();
	window(1,1,80,25);
	textcolor(7);
	textbackground(7); clrscr();
	window(27,8,54,17);
	textcolor(7);	textbackground(0);

	window(28,5,53,6); clrscr();  	//top
	window(27,9,54,10); clrscr();  //m
	window(28,13,53,14); clrscr();  //bo
	window(27,6,30,8); clrscr();   //tl
	window(27,12,30,13); clrscr();  //bl
	window(51,6,54,7); clrscr();    //tr
	window(51,11,54,13); clrscr();  //br

	_setcursortype(_NOCURSOR);
	textcolor(0);     textbackground(7);
	window(27,17,54,17);
	gotoxy(10,1);cprintf("LOADING...");
	window(27,18,54,18);
	textcolor(0);     textbackground(0);   int d,d1;

	for(d=10,d1=28;d1>=0;d1--,d=10*random(d1))
	{ delay(d); cprintf(" "); if(d1==0) break;}

	delay(500);
	//getch();
	_setcursortype(_NORMALCURSOR);
	window(1,1,80,25);
	//getch();//return;
}





			 char logpas[25];
void login()
{
	window(1,1,80,25);
	textcolor(7);
	textbackground(7); clrscr();
	window(27,8,54,17);
	textcolor(7);	textbackground(0);

	window(28,5,53,6); clrscr();  	//top
	window(27,9,54,10); clrscr();  //m
	window(28,13,53,14); clrscr();  //bo
	window(27,6,30,8); clrscr();   //tl
	window(27,12,30,13); clrscr();  //bl
	window(51,6,54,7); clrscr();    //tr
	window(51,11,54,13); clrscr();  //br

	ifstream set; set.open("SOSL.DAT");
	set.read(logpas,25);   set.close();
	_setcursortype(_NORMALCURSOR);  int co=0;
	loga:  if(co==3) exit(0);
	//window(27,17,54,20);textbackground(7); clrscr();
	char logpas1[25];
	textcolor(15);     textbackground(0);
	window(27,17,54,20);         clrscr();
	gotoxy(3,1);  cprintf("LOGIN :: PASSWORD PLEASE");
	window(28,19,53,19);
	textcolor(0);     textbackground(7);  clrscr();
	gets(logpas1);
	if(strcmpi(logpas,logpas1)==0)
	salut();
	else {co++; goto loga;   }
}

void login2()
{       window(1,1,80,25);
	textcolor(7);
	textbackground(7); clrscr();
	window(27,8,54,17);
	textcolor(7);	textbackground(0);

	window(28,5,53,6); clrscr();  	//top
	window(27,9,54,10); clrscr();  //m
	window(28,13,53,14); clrscr();  //bo
	window(27,6,30,8); clrscr();   //tl
	window(27,12,30,13); clrscr();  //bl
	window(51,6,54,7); clrscr();    //tr
	window(51,11,54,13); clrscr();  //br

	textcolor(0);     textbackground(15);
	window(27,17,54,18);         clrscr();
	//gotoxy(2,1);  cprintf("TO LOGIN");
	gotoxy(4,2); cprintf("Press any key TO LOGIN");
	window(1,1,80,25);
	gotoxy(65,25);	cprintf("ESC : Shut Down");
	switch (getch())
	{	case 27: exit(0);
		default: salut();
	}
}


void logout()
{      ifstream ma; ma.open("SOSL.DAT");
	if(!ma)
       { login2();	}
       else
       { login();	}
}


int main()
{
	start();
	ifstream ma; ma.open("SOSL.DAT");
	if(!ma)
	{ ma.close();	salut();  }
	else
	{	ma.close();
		login();
	}
	return 0;
}
