#include"file.cpp"
				 int clbc;
void abtclb()
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
		gotoxy(5,2);cprintf("COLOUR BOOK");
		gotoxy(5,3);cprintf("-----------");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("A Game for Simple ArtWork.");
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
void clbhelp(int l)
{                         int lo=l+18;
	char buh[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,15);
	gettext(l-1,2,lo,5,buh);
	window(l-1,2,lo,5);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);                                       cout<<"--------------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout ColourBook";
		gotoxy(2,3);textcolor(12);cprintf("- H");textcolor(15);cout<<"elp";
		gotoxy(1,4);textcolor(15);                         cout<<"____________________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(l-1,2,lo,5,buh);
		window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': abtclb();      break;
		case'h':case'H': //srhel();  	break;
		default:break;
	}
}


int skc=0;             char skname[20];
void skupname()
{   	textcolor(15);
	window(2,3,79,3);
	textbackground(0);	clrscr();
	gotoxy(5,1);
	if(skc==0) cout<<"New Document";
	else puts(strupr(skname));
}

void calear()
{       window(1,1,80,25);
	textcolor(15);
	window(2,3,79,24);
	textbackground(0);	clrscr();
	skupname();
	window(3,4,78,23);
	textbackground(7); textcolor(0);clrscr();
	window(3,4,78,23);
}

		void skesc();

void sksave() //(3,4,78,23)
{       char in[10000],sf;          _setcursortype(_NORMALCURSOR);
	gettext(3,4,78,23,in);
	window(16,11,44,15);
	{	textcolor(15); textbackground(1);   clrscr();
		cout<<"=======================SAVE==";
gotoxy(1,2);    cout<<" Enter the File Name";
		gotoxy(3,3); textbackground(4);
		cprintf("                    ");cout<<" .CLB";
		textbackground(1);
		gotoxy(1,5); cout<<"=============================";
		gotoxy(3,3);
		textcolor(0);gets(skname);
		strcat(skname,".CLB");
		if(strcmpi(skname,".CLB")==0) strcpy(skname,"NONAME.CLB");
	gotoxy(10,5);cout<<"FILE SAVED";
	}                                    _setcursortype(_NOCURSOR);
	fstream fs; fs.open(skname,ios::out);
	fs.write((char*)in,10000);
	fs.close();

	  getch();     skc=1;     skupname();
	  //skesc();
	  puttext(3,4,78,23,in);
	  return;
}
					 char skcho;

void sknew()
{       window(3,24,33,24);
	textbackground(0);    textcolor(15);   clrscr();
	gotoxy(2,1);  cout<<"Do you want to Save the Document (Y/N) : ";
	 skcho=getch();
	window(3,4,78,23);
	if(skcho=='y'||skcho=='Y') sksave();
	textbackground(7);   clrscr();
	sketch();
}

int skx,sky;

void skquit()       //(3,4,78,23)
{       window(3,24,33,24);                   char skch;
	textbackground(0);    textcolor(15);   clrscr();
	gotoxy(2,1);  cout<<"Do you want to Save the Document (Y/N) : "; skch=getch();
	window(3,4,78,23);
	//window(16,22,44,22);
	//textbackground(0);   clrscr();
	if(skch=='y'||skch=='Y') sksave();
		textbackground(7);   clrscr();
	salut();   //Direct to SALUT
}
		int sknopen;
void skopen()
{   	char in[1000],out[10000],sf;          _setcursortype(_NORMALCURSOR);
	gettext(16,6,44,20,in);skop:
	window(16,11,44,15);
	{    	textcolor(15); textbackground(1);   clrscr();
		cout<<"=======================OPEN==";
gotoxy(1,2);    cout<<" Enter the File Name";
		gotoxy(3,3); textbackground(4);
		cprintf("                    ");cout<<" .CLB";
		textbackground(1);
		gotoxy(1,5); cout<<"=============================";
		gotoxy(3,3);
		textcolor(0);gets(skname);
		strcat(skname,".CLB");
		if(strcmpi(skname,".CLB")==0) goto skop;//strcpy(skname,"NONAME.CLB");
		fstream fs; fs.open(skname,ios::in);
		_setcursortype(_NOCURSOR);
		if(!fs)
		{   	fs.close();	gotoxy(8,5);cout<<"FILE NOT FOUND";
			getch(); 	puttext(16,6,44,20,in);
			sknopen=0;
		}
		else
		{       window(16,11,44,15);
			fs.read((char*)out,10000);	fs.close();
			gotoxy(8,5);	cout<<"PRESS ANY KEY...";
			getch();  sknopen=1;
			skc=1;     skupname();	puttext(3,4,78,23,out);

		}
	}
	  return;
}


void skesc()
{	mbar();
	gotoxy(8,1);cprintf("ColourBOOK");
	gotoxy(22,1);cprintf("File");
	gotoxy(29,1);cprintf("Colours");
	gotoxy(39,1);cprintf("Help");
	gotoxy(46,1);cprintf("Go");
}


char skch;	char skbu[5000];

void skfile()
{
	char skbuer[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,25);
	gettext(21,2,30,8,skbuer);
	window(21,2,30,8);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"----------";
		gotoxy(2,2);textcolor(12);cprintf("- N");textcolor(15);cout<<"ew";
		gotoxy(2,3);textcolor(12);cprintf("- O");textcolor(15);cout<<"pen";
		gotoxy(2,5);textcolor(15);cout<<"--------";
		gotoxy(2,4);textcolor(12);cprintf("- S");textcolor(15);cout<<"ave";
		gotoxy(2,6);textcolor(12);cprintf("- Q");textcolor(15);cout<<"uit";
		gotoxy(1,7);textcolor(15);cout<<"__________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(21,2,30,8,skbuer); window(1,2,80,25);
	switch(sf)
	{	case's':case'S': sksave();      break;
		case'n':case'N': sknew();  	break;
		case'o':case'O': skopen();	break;
		case'q':case'Q': skquit();
		default:break;
	}
}
void ccolor()  //28
{
	char skbuer[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,25);
	gettext(28,2,43,20,skbuer);
	window(28,2,43,20);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"----------------";
		//gotoxy(1,2);cout<<"-Dark-Colors----";
		gotoxy(2,2);textcolor(12);cprintf("- 0.");textcolor(15);cout<<"White";
		gotoxy(2,3);textcolor(12);cprintf("- 1.");textcolor(15);cout<<"Black";
		gotoxy(2,4);textcolor(12);cprintf("- 2.");textcolor(15);cout<<"Blue";
		gotoxy(2,5);textcolor(12);cprintf("- 3.");textcolor(15);cout<<"Green";
		gotoxy(2,6);textcolor(12);cprintf("- 4.");textcolor(15);cout<<"Cyan";
		gotoxy(2,7);textcolor(12);cprintf("- 5.");textcolor(15);cout<<"Red";
		gotoxy(2,8);textcolor(12);cprintf("- 6.");textcolor(15);cout<<"Magenta";
		gotoxy(2,9);textcolor(12);cprintf("- 7.");textcolor(15);cout<<"Brown";
		gotoxy(2,10);textcolor(12);cprintf("- 8.");textcolor(15);cout<<"Grey";
		gotoxy(1,11);cout<<"-Light-Colors---";
		gotoxy(2,12);textcolor(12);cprintf("- 9.");textcolor(15);cout<<"Blue";
		gotoxy(2,13);textcolor(12);cprintf("- A.");textcolor(15);cout<<"Green";
		gotoxy(2,14);textcolor(12);cprintf("- B.");textcolor(15);cout<<"Cyan";
		gotoxy(2,15);textcolor(12);cprintf("- C.");textcolor(15);cout<<"Red";
		gotoxy(2,16);textcolor(12);cprintf("- D.");textcolor(15);cout<<"Magenta";
		gotoxy(2,17);textcolor(12);cprintf("- E.");textcolor(15);cout<<"Yellow";
		gotoxy(2,18);textcolor(12);cprintf("- F.");textcolor(15);cout<<"Grey";
		gotoxy(1,19);textcolor(15);cout<<"________________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(28,2,43,20,skbuer); window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': clbc=10;      break;
		case'b':case'B': clbc=11;      break;
		case'c':case'C': clbc=12;      break;
		case'd':case'D': clbc=13;      break;
		case'e':case'E': clbc=14;      break;
		case'f':case'F': clbc=7;       break;

		case'0': clbc=15;     break;
		case'1': clbc=0;      break;
		case'2': clbc=1;      break;
		case'3': clbc=2;      break;
		case'4': clbc=3;      break;
		case'5': clbc=4;      break;
		case'6': clbc=5;      break;
		case'7': clbc=6;      break;
		case'8': clbc=8;      break;
		case'9': clbc=9;      break;


		default:break;
	}

}
void skesc1()
{       skx=wherex();   sky=wherey();   sknopen=0;

	again:
	mbar1();  textcolor(15);
	gotoxy(8,1);cprintf("ColourBOOK");
	gotoxy(22,1);textcolor(12);cprintf("F");textcolor(15);cprintf("ile");
	gotoxy(29,1);textcolor(12);cprintf("C");textcolor(15);cprintf("olours");
	gotoxy(39,1);textcolor(12);cprintf("H");textcolor(15);cprintf("elp");
	gotoxy(46,1);textcolor(12);cprintf("G");textcolor(15);cprintf("o");

	skch=getch();
	switch(skch)
	{	case's':case'S': sfunc();      break;
		case'f':case'F': skfile();     break;
		case'c':case'C': ccolor();     break;
		case'h':case'H': clbhelp(39);     break;
		case'g':case'G': sgo(46);     break;
		case 27: break;
		default: goto again;
	}

	skesc();
	textbackground(7); textcolor(0);
	_setcursortype(_NORMALCURSOR);
	//puttext(15,6,44,20,skbu);
	window(3,4,78,23);
	//if(sknopen==0)
	  gotoxy(skx,sky);

}

void sketch() //(3,4,78,23)
{       char ch;         skc=0;
	calear();  skupname();
	skesc();  window(3,4,78,23); gotoxy(2,2);
	textbackground(7); clbc=0;
	skt:               textcolor(clbc);
	_setcursortype(_SOLIDCURSOR);
	ch=getch();
	skx=wherex();  sky=wherey();
	switch(ch)
	{       case 27: skesc1();	      break;
		case 13: if(wherey()==20)     break;
			 gotoxy(skx,sky+1);	break;

		case 32:if(sky<21&&sky>0&&skx<77&&skx>0)    cout<<" ";
			if(wherex()==77) cout<<'\b'; break;

		case  8: if(skx==1) {gotoxy(76,sky-1); cout<<" \b";  break;   }
			 else if(sky<21&&sky>0&&skx<77&&skx>1) cout<<"\b \b";
			    break;

		case 0:
		{char ar=getch();
		switch(ar)
		{
		case 75: if(skx>0);gotoxy(skx-1,sky); break;
		case 72: if(sky>0);gotoxy(skx,sky-1);  break;
		case 80: if(sky<21);gotoxy(skx,sky+1); break;
		case 77: if(skx<77);gotoxy(skx+1,sky); break;
		case 'S':
			if(sky<21&&sky>0&&skx<77&&skx>0)    cout<<" ";
			if(wherex()==77) cout<<'\b'; break;
		}
		break;

		}

		default:         //(3,4,78,23)    (76,20)
		if(sky==20&&skx==76) break;
		if(skx==77){  gotoxy(1,sky+1); cprintf("|");     }
		if(sky<21&&sky>0&&skx<77&&skx>0)
		{   cprintf("Û");// cprintf("Ü");  //putc(ch,stdout);
		      // Ü  Û
		}

	}

	goto skt;
}