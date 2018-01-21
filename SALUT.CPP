#include"FILE.CPP"
int sax,say;    char sac[10000];    char chs;

void abtsal()
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
		gotoxy(5,2);cprintf("SALUT");
		gotoxy(5,3);cprintf("-----");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("The Desktop for SYBURY OS..");
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

void salhelp(int l)
{                         int lo=l+13;
	char buh[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,15);
	gettext(l-1,2,lo,5,buh);
	window(l-1,2,lo,5);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);                                       cout<<"---------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout SALUT";
		gotoxy(2,3);textcolor(12);cprintf("- H");textcolor(15);cout<<"elp";
		gotoxy(1,4);textcolor(15);                         cout<<"_______________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(l-1,2,lo,5,buh);
		window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': abtsal();      break;
		case'h':case'H': //srhel();  	break;
		default:break;
	}
}




void saesc()
{	mbar();
	gotoxy(8,1);cprintf("SALUT");
	gotoxy(17,1);cprintf("Help");
	gotoxy(24,1);cprintf("Go");
}
void saesc1()
{       sax=wherex();   say=wherey();
	gettext(1,2,80,25,sac);

	mbar1();  textcolor(15);
	gotoxy(8,1);cprintf("SALUT");
	gotoxy(17,1);textcolor(12);cprintf("H");textcolor(15);cprintf("elp");
	gotoxy(24,1);textcolor(12);cprintf("G");textcolor(15);cprintf("o");
	again:
	chs=getch();
	switch(chs)
	{	case's':case'S': sfunc();      break;
		case'h':case'H': salhelp(17);   break;
		case'g':case'G': sgo(24);     break;
		case 27: break;
		default: goto again;
	}

	bgd(3);	saesc();
	_setcursortype(_NORMALCURSOR);
	window(1,2,80,25);
	puttext(1,2,80,25,sac);

	  gotoxy(sax,say);
}
void sas()
{	window(27,8,54,17);
	textcolor(7);
	textbackground(0);

	window(28,8,53,9); clrscr();
	window(27,12,54,13); clrscr();
	{gotoxy(9,1);  cout<<"= SYBURY OS =";
	 gotoxy(9,2); cout<<"Siddhant GUPTA";
	}
	window(28,16,53,17); clrscr();

	window(27,9,30,12); clrscr();
	window(27,15,30,16); clrscr();
	window(51,9,54,10); clrscr();
	window(51,13,54,16); clrscr();
}

void sicon(int x, int y, char *n)
{
	wn(x,y,x+9,y+2);    //Area
	tc(0); tb(7); clrscr();
	//gotoxy(1,1);cout<<"ษออออออออป";
       //	gotoxy(1,2);cout<<"บ        บ";
	//gotoxy(1,3);cout<<"ศออออออออผ";
	//------------------------------------------
	if(strlen(n)<=8)
	{gt(2,2); puts(n);}
	else if(strlen(n)<=10)
	{gt(1,2); puts(n);}
	else
	{gt(1,2); puts(n);}

}


void sacon()
{
	sicon(3,3,"SiddhanGupta");

	window(67,4,78,6);    //Srite
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บ SritePad บ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------

	window(67,8,78,10);    //Scrutin
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บ Scrutin  บ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------

	window(67,12,78,14);    //Settings
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บ Settings บ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------


	window(67,16,78,18);    //AnswerMe
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บ AnswerMe บ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------

	window(67,20,78,22);    //ColorBook
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บColourBookบ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------

							  /*

	window(67,16,78,18);    //
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บ AnswerMe บ";
	gotoxy(1,3);cout<<"ศออออออออออผ";
	//------------------------------------------      */
}
 /*
void sacon()
{	//Setting1,Srite1,Scrutin1,Search1,Calc1,Game1,Sketch0

	window(69,4,78,9);  //SritePAD
	textcolor(0); textbackground(7); clrscr();
	gotoxy(2,1);cout<<".______.";
	gotoxy(2,2);cout<<"| ---- |";
	gotoxy(2,3);cout<<"|  HI! |";
	gotoxy(2,4);cout<<"`------'";
	gotoxy(2,5);cout<<"SritePAD";
	gotoxy(1,6);cout<<"(Note Pad)";

	window(69,11,78,16);  //Scrutin
	textcolor(0); textbackground(7); clrscr();
	gotoxy(2,1);cout<<"  .__.";
	gotoxy(2,2);cout<<"._|SC|_.";
	gotoxy(2,3);cout<<"| |__| |";
	gotoxy(2,4);cout<<"|------|";
	gotoxy(2,5);cout<<"SCRUTIN";
	gotoxy(1,6);cout<<"(Vote Box)";

	window(69,18,78,23);  //Settings
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"  .____.  ";
	gotoxy(1,2);cout<<"  |SET.|  ";
	gotoxy(1,3);cout<<"  |____|  ";
	gotoxy(1,4);cout<<" /______\\";
	gotoxy(1,5);cout<<"          ";
	gotoxy(1,6);cout<<" SETTINGS ";
/*
	window(57,11,66,16);  //Calc             //(57,11,66,16)
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"  .____.  ";
	gotoxy(1,2);cout<<"  |====|  ";
	gotoxy(1,3);cout<<"  | +* | ";
	gotoxy(1,4);cout<<"  | -/ | ";
	gotoxy(1,5);cout<<"  `----'  ";
	gotoxy(1,6);cout<<"CALCULATOR";

	window(57,4,66,9);  //Games
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<" <GAMES>  ";
	gotoxy(1,2);cout<<"  -----   ";
	gotoxy(1,3);cout<<".AnswerMe ";
	gotoxy(1,4);cout<<".ColorBook";
	//gotoxy(1,5);cout<<".TicTacToe";
	//gotoxy(1,6);cout<<".DriveTest";
/*
	window(57,18,66,23);  //Search
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"________. ";
	gotoxy(1,2);cout<<"---(O)- | ";
	gotoxy(1,3);cout<<"----|-- | ";
	gotoxy(1,4);cout<<"--------' ";
	gotoxy(1,5);cout<<"  SEARCH  ";
	gotoxy(1,6);cout<<"WordFinder";


	window(55,11,66,13);    //
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออออป";
	gotoxy(1,2);cout<<"บColourBookบ";
	gotoxy(1,3);cout<<"ศออออออออออผ";

/*
	window(57,11,66,16);    //
	textcolor(0); textbackground(7); clrscr();
	gotoxy(1,1);cout<<"ษออออออออป";
	gotoxy(1,2);cout<<"บ        บ";
	gotoxy(1,3);cout<<"บ        บ";
	gotoxy(1,4);cout<<"บ        บ";
	gotoxy(1,5);cout<<"บ        บ";
	gotoxy(1,6);cout<<"ศออออออออผ";




}      */

void clean()
{
	ifstream set; set.open("COL.SOS",ios::in);
	if(!set)   bgd(2);
	else
	{ int ssa; set>>ssa;
	  bgd(ssa);
	}
	set.close();
	saesc();sas();
	window(1,2,80,25);
	sacon();            window(1,2,80,25);
	gotoxy(65,6);
}

void salut()
{       //read();
	clean();
	sal:
	_setcursortype(_SOLIDCURSOR);
	char ch=getch();
	 sax=wherex();  say=wherey();
	switch(ch)
	{       case 27: saesc1();	      break;

		case 13:
		       /* {  if(sax>68&&sax<79&&say>2&&say<9)//Srite(69,4,78,9);
			    {srite();    break; }
			    if(sax>68&&sax<79&&say>9&&say<16)//scrutin(69,11,78,16);
			    {scrutin();  break;  }
			    if(sax>56&&sax<67&say>11&&say<13)//Answer (57,13,66,13)
			    {answer();break;    }
			    if(sax>56&&sax<67&say>12&&say<14)//CBook (57,13,66,13)
			    {sketch();break;    }
			    if(sax>68&&sax<79&say>16&&say<23)//Setting (69,18,78,23)
			    {sett();break;        }
			    if(sax>56&&sax<67&&say>2&&say<9)//Calc(57,4,66,9);;
			    {calc();    break; }
			}                       */

			{      	if(sax>66&&sax<79&&say>2&&say<6)
				{srite();    break; }

				if(sax>66&&sax<79&&say>6&&say<10)
				{scrutin();    break; }

				if(sax>66&&sax<79&&say>10&&say<14)
				{sett();    break; }

				if(sax>66&&sax<79&&say>14&&say<18)
				{answer();    break; }

				if(sax>66&&sax<79&&say>18&&say<22)
				{sketch();    break; }

				break;
			       //	clean(); gotoxy(sax,say);
			}
		case 0:
		{char ar=getch();
		switch(ar)
		{
		case 75: if(sax>1);gotoxy(sax-1,say); break;
		case 72: if(say>1);gotoxy(sax,say-1);  break;
		case 80: if(say<12);gotoxy(sax,say+1); break;
		case 77: if(sax<18);gotoxy(sax+1,say); break;
		}break;
		}

		default:   break;
	}

	goto sal;
}