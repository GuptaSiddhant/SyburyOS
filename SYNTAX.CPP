#include"file.cpp"


int m0=4,m1=m0+4,m2=m1+10,m3=m2+8,m4=m3+8,m5=m4+9,m6=72;
void mbar()
{ 	window(1,1,80,1);
	textbackground(8);
	textcolor(15);
	clrscr();
	gotoxy(m0,1);cprintf("S");
	gotoxy(m1,1);cprintf("S");
	//_setcursortype(_NOCURSOR);
	char d[9],t[9];
	_strdate(d); _strtime(t);
	gotoxy(62,1); cout<<d<<"  "<<t;

}


void mbar1()
{       _setcursortype(_NOCURSOR);
	window(1,1,80,1);textbackground(8);textcolor(15);clrscr();
	textcolor(12);
	gotoxy(m0,1);cprintf("S");
	textcolor(15);
	gotoxy(m1,1);//cprintf("S");
	char d[9],t[9];
	_strdate(d); _strtime(t);
	gotoxy(62,1); cout<<d<<"  "<<t;
}

void abtos()
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
		gotoxy(5,2);cprintf("SYBURY OS");
		gotoxy(5,3);cprintf("---------");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("It's a Virtual OS designed in DOS.");
		//gotoxy(2,6);cprintf("Version 1.0");
		gotoxy(5,7);cprintf("R & D :: Siddhant GUPTA");
		//gotoxy(,8);cprintf("");
		gotoxy(27,9);cprintf("Version 1.0");
		getch();
	}
	window(1,1,80,25);
	puttext(21,8,60,18,buffer);
	window(1,2,80,25);

}


void sfunc()
{	char buffer[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,25);
	gettext(3,2,18,9,buffer);
	window(3,2,18,9);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"----------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout OS";
		gotoxy(2,5);textcolor(12);cprintf("- L");textcolor(15);cout<<"og Out";
		gotoxy(5,4);textcolor(15);cout<<"--------";
		gotoxy(2,3);textcolor(12);cprintf("- P");textcolor(15);cout<<"references";
		gotoxy(2,6);textcolor(12);cprintf("- R");textcolor(15);cout<<"estart";
		gotoxy(2,7);textcolor(12);cprintf("- S");textcolor(15);cout<<"hut Down";
		gotoxy(1,8);textcolor(15);cout<<"________________";
		sf=getch();
	}
	window(1,1,80,25);
	puttext(3,2,18,9,buffer);
	window(1,2,80,25);
	switch(sf)
	{	case's':case'S': exit(0);
		case'l':case'L': logout();
		case'r':case'R': main();
		case'p':case'P': sett();
		case'a':case'A': abtos();
		default:break;
	}
}
	   char sgobu[1000];      int sg;
void gmenu(int gx,int gy)
{       window(1,1,80,25);	char gbuff[1000], ch;
	gettext(gx,gy,gx+13,gy+3,gbuff);
	window(gx,gy,gx+13,gy+3);
		textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"--------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"nswerMe";
		gotoxy(1,4);textcolor(15);cout<<"______________";
		gotoxy(2,3);textcolor(12);cprintf("- C");textcolor(15);cout<<"olourBook";
	    //	gotoxy(2,4);textcolor(12);cprintf("- T");textcolor(15);cout<<"icTacToe";
	      //	gotoxy(2,5);textcolor(12);cprintf("- D");textcolor(15);cout<<"riveTest";

		switch(getch())
		{	case'c':case'C': window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				puttext(gx,gy,gx+13,gy+3,gbuff);
				window(1,2,80,25);clean();sketch();  	break;
			case'a':case'A': window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				puttext(gx,gy,gx+13,gy+3,gbuff);
				window(1,2,80,25);clean();answer();  	break;
			default: break;
		}
	window(1,1,80,25);
	puttext(gx,gy,gx+13,gy+3,gbuff);
	puttext(sg,2,sg+14,12,sgobu);
}

void sgo(int st)
{       sg=st-1;
	char sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,25);
	gettext(sg,2,sg+14,12,sgobu);
	window(sg,2,sg+14,12);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"---------------";
		gotoxy(2,2);textcolor(12);cprintf("- D");textcolor(15);cout<<"esktop";
		gotoxy(4,4);textcolor(15);cout<<"--------";
		gotoxy(2,3);textcolor(12);cprintf("- P");textcolor(15);cout<<"eferences";
		gotoxy(2,5);textcolor(12);cprintf("- N");textcolor(15);cout<<"ote Pad";
		gotoxy(2,6);textcolor(12);cprintf("- S");textcolor(15);cout<<"crutin";
		gotoxy(2,7);textcolor(12);cprintf("- W");textcolor(15);cout<<"ordFinder";
		gotoxy(2,8);textcolor(12);cprintf("- C");textcolor(15);cout<<"alculator";
		gotoxy(4,9);textcolor(15);cout<<"--------";
		gotoxy(2,10);textcolor(12);cprintf("- G");textcolor(15);cout<<"ames     >";
		//gotoxy(2,11);textcolor(12);cprintf("- A");textcolor(15);cout<<"rtPAD";
		gotoxy(1,11);textcolor(15);cout<<"_______________";
		sf=getch();   }

	switch(sf)
	{	case'd':case'D': window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				window(1,2,80,25);salut();	break;
		case'n':case'N': window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				window(1,2,80,25);clean();srite();break;
		case'p':case'P':window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				window(1,2,80,25);clean();sett();	break;
		case's':case'S': scrutin();  	break;
		case'w':case'W': //window(1,1,80,25);
				//puttext(sg,2,sg+14,12,sgobu);
				//window(1,2,80,25);clean();search();  	break;
		case'g':case'G': gmenu(sg+15,10);break;
		/*
		case'c':case'C': window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				//window(1,2,80,25);clean();
				calc();  	break;
		  */
		default:	window(1,1,80,25);
				puttext(sg,2,sg+14,12,sgobu);
				window(1,2,80,25);break;
	}
}

void bgd(int n)
{      	textbackground(0);
	clrscr();
	mbar();
	window(1,2,80,25);
	textbackground(n);
	textcolor(15);
	clrscr();
	window(1,2,80,25);
}