#include"file.cpp"
int seex,sey,color;            char sebu[3000], sec; char logpass[25],logpass1[25];
//	window(12,8,59,20);  textcolor(15);
  //	textbackground(1); clrscr();

void abtset()
{	char buffer[2000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,25);
	gettext(21,8,60,18,buffer);
	window(21,8,60,18);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(19,1);cprintf("ABOUT");
		gotoxy(2,11);cprintf("Press any key...");
		window(22,9,59,17);
		textcolor(0); textbackground(7);   clrscr();
		//gotoxy(,1);cprintf("");
		gotoxy(5,2);cprintf("SETTINGS");
		gotoxy(5,3);cprintf("--------");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("The Preference Panel of SYBURY OS.");
		//gotoxy(2,6);cprintf("Version 1.0");
		gotoxy(5,7);cprintf("R & D :: Siddhant GUPTA");
		//gotoxy(,8);cprintf("");
		gotoxy(27,9);cprintf("Version 1.0");
		getch();
	}
	window(1,1,80,25);
	puttext(21,8,60,18,buffer);
	window(1,2,80,25);        _setcursortype(_NORMALCURSOR);
}
void sethelp(int l)
{                         int lo=l+16;
	char buh[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,15);
	gettext(l-1,2,lo,5,buh);
	window(l-1,2,lo,5);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);                                       cout<<"------------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout Settings";
		gotoxy(2,3);textcolor(12);cprintf("- H");textcolor(15);cout<<"elp";
		gotoxy(1,4);textcolor(15);                         cout<<"__________________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(l-1,2,lo,5,buh);
		window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': abtset();      break;
		case'h':case'H': //srhel();  	break;
		default:break;
	}
}



void scw()
{       ofstream set; set.open("COL.SOS",ios::out);
	set<<color;
	set.close();
}
void spw()
{	ofstream set; set.open("SOSL.DAT",ios::out);
	set.write(logpass,25);
	set.close();
}
void spr()
{	ifstream set; set.open("SOSL.DAT");
	set.read(logpass,25);
	set.close();
}

void seesc()
{  	mbar();
	gotoxy(8,1);cprintf("SETTINGS");
	gotoxy(20,1);cprintf("Help");
	gotoxy(27,1);cprintf("Go");
}
void seesc1()
{       seex=wherex();   sey=wherey();

	mbar1();  textcolor(15);
	gotoxy(8,1);cprintf("SETTINGS");
	gotoxy(20,1);textcolor(12);cprintf("H");textcolor(15);cprintf("elp");
	gotoxy(27,1);textcolor(12);cprintf("G");textcolor(15);cprintf("o");
	again:
	sec=getch();
	switch(sec)
	{	case's':case'S': sfunc();      break;
		case'h':case'H': sethelp(20);   break;
		case'g':case'G': sgo(27);     break;
		case 27: break;
		default: goto again;
	}

	seesc();
	_setcursortype(_NORMALCURSOR);
	window(17,8,59,20);
	  gotoxy(seex,sey);
}


void chbgs()
{  	window(12,9,59,20);  textcolor(15);
	textbackground(1); clrscr();
	cout<<" = Background Options =";
	gotoxy(10,4); cout<<"Choose a Color for Background";

	window(20,14,51,17);int lc,rc,col;
	textbackground(0); clrscr();
	for(col=1;col<7;col++)
	{gotoxy((5*col)-1,4);cout<<col;}
	for(col=1,lc=21,rc=25;col<7;col++,lc+=5,rc+=5)
	{ window(lc,15,rc,16);  textbackground(col); clrscr();	}

	window(21,15,50,16); selcol:
	seex=wherex();  sey=wherey();
	switch(getch())
	{	case 27: seesc1(); break;

		case'1': color=1; scw(); salut();
		case'2': color=2; scw(); salut();
		case'3': color=3; scw(); salut();
		case'4': color=4; scw(); salut();
		case'5': color=5; scw(); salut();
		case'6': color=6; scw(); salut();

		case 13:
		{     for(lc=1,rc=5,col=1;col<7;col++,lc+=5,rc+=5)
			if(seex>=lc&&seex<=rc) { color=col;}
			 scw(); salut();
		}

		case 0:     //(20,14,51,17)
		{char ar=getch();
		switch(ar)
		{
		case 75: if(seex>1);gotoxy(seex-1,sey); break;
		case 72: if(sey>1);gotoxy(seex,sey-1);  break;
		case 80: if(sey<4);gotoxy(seex,sey+1); break;
		case 77: if(seex<32);gotoxy(seex+1,sey); break;
		case 'S':break;
		}
		break;
		}

		default: break;
	}
	goto selcol;
}

void setlogp()
{       again:
	window(12,9,59,20);  textcolor(15);
	{
	textbackground(1); clrscr();
	cout<<" = LOGIN Options =            New Password";
	gotoxy(5,5);
	cout<<"Enter your Desired Password  (MAX 25 char.)";
		gotoxy(10,8); textbackground(4);
		for(int teri=0;teri<25;teri++)
		cprintf(" ");

		gotoxy(20,12); cout<<"( Please, Do NOT press ESC )";
		gotoxy(10,8);
		textcolor(0);gets(logpass);

		if(strcmpi(logpass,NULL)==0) //strcpy(fname,"NONAME.TXT");
		goto again;
		spw();

		window(12,12,59,20);
	       {	 textbackground(1);      textcolor(15);
		 clrscr();   gotoxy(10,4);
		cprintf("PASSWORD CREATED     (Press any key)");
		}
	}
	getch();      salut();
}

void chalogp()
{	int cou=0;againc:          if(cou==3) sett();
	window(12,9,59,20);  textcolor(15);
	{
	textbackground(1); clrscr();
	cout<<" = LOGIN Options =           Change Password";
	gotoxy(5,5);
	cout<<"Enter your OLD Password  (Existing Password)";
		gotoxy(10,8); textbackground(4);
		for(int teri=0;teri<25;teri++)
		cprintf(" ");

		gotoxy(20,12); cout<<"( Please, Do NOT press ESC )";
		gotoxy(10,8);
		textcolor(0);gets(logpass1);
		spr();

		if(strcmpi(logpass,logpass1)==0)
		setlogp();

		if(strcmpi(logpass,NULL)==0)
		goto againc;

		if(strcmpi(logpass,logpass1)!=0)
		{ cou++; goto againc; }
	}
}


void dellogp()
{	int cou=0;againc:          if(cou==3) sett();
	window(12,9,59,20);  textcolor(15);
	{
	textbackground(1); clrscr();
	cout<<" = LOGIN Options =         Remove Password";
	gotoxy(5,5);
	cout<<"Enter your Password     (Existing Password)";
		gotoxy(10,8); textbackground(4);
		for(int teri=0;teri<25;teri++)
		cprintf(" ");

		gotoxy(20,12); cout<<"( Please, Do NOT press ESC )";
		gotoxy(10,8);
		textcolor(0);gets(logpass1);
		spr();

		if(strcmpi(logpass,logpass1)==0)
		{	remove("SOSL.DAT");	goto dend;}

		if(strcmpi(logpass,NULL)==0)
		goto againc;

		if(strcmpi(logpass,logpass1)!=0)
		{ cou++; goto againc; }
	}
	dend:
		window(12,12,59,20);
	       {	 textbackground(1);      textcolor(15);
		 clrscr();   gotoxy(10,4);
		cprintf("PASSWORD REMOVED     (Press any key)");
		}

	getch();    salut();
}

void logins()
{       loag:
	window(12,9,59,20);  textcolor(15);
	textbackground(1); clrscr();
	cout<<" = LOGIN Options =            Account Settings";

	gotoxy(6,5);
		      _setcursortype(_NOCURSOR);
	ifstream set; set.open("SOSL.DAT");
	if(!set)
	{	cout<<"1. Set LOGIN Password (Press 1)";
		set.close();
		switch(getch())
		{	case 27: seesc1(); break;
			case '1': setlogp();
		//ofstream set; set.open("SOSL.DAT");
		}
	}
	else
	{	cout<<"1. Change LOGIN Password";
		gotoxy(6,7);cout<<"2. Remove LOGIN Password";
		set.close();
		switch(getch())
		{	case 27: seesc1(); break;
			case'1': chalogp(); break;
			case'2': dellogp(); break;
			default: break;
		}
		goto loag;
	}
		      _setcursortype(_NORMALCURSOR);
	return;
}


void sett()             //bgcol,login,
{       seesc();
	set: 	_setcursortype(_NORMALCURSOR);
	window(11,6,60,21);  textcolor(15);
	textbackground(0); clrscr();
	gotoxy(17,2);cout<<"SYSTEM PREFERENCES";

	window(12,8,59,20);  textcolor(15);
	textbackground(1); clrscr();

	gotoxy(5,4);cout<<"1. Change Background colour";
	gotoxy(5,6);cout<<"2. Set LOGIN options";
	gotoxy(8,10);cout<<"Kindly choose your option (1,2): ";
	switch(getch())
	{	case 27:   seesc1();break;
		case '1':  chbgs();break;
		case '2':  logins();break;
		default: break;
	}
	goto set;
}