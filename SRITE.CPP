#include"file.cpp"
  //(16,6,44,20)

int c1=0;             char fname[20];
void upname()
{   	textcolor(15);
	window(15,4,45,4);
	textbackground(0);	clrscr();
	gotoxy(3,1);
	if(c1==0) cout<<"New Document";
	else puts(strupr(fname));
}

void abtsrp()
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
		gotoxy(5,2);cprintf("Srite PAD");
		gotoxy(5,3);cprintf("---------");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("A simple Text Editor based on DOS.");
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

void clear()
{ 	textcolor(15);
	window(15,4,45,22);
	textbackground(0);	clrscr();
	upname();
	window(15,5,45,21);
	textbackground(7); textcolor(0);
	clrscr();   window(16,6,44,20);
}

		void sresc();

void srsave()
{       char in[5000],sf;          _setcursortype(_NORMALCURSOR);
	window(1,1,80,25);
	gettext(16,6,44,20,in);
	window(16,11,44,15);
	{	textcolor(15); textbackground(1);   clrscr();
		cout<<"=======================SAVE==";
gotoxy(1,2);    cout<<" Enter the File Name";
		gotoxy(3,3); textbackground(4);
		cprintf("                    ");cout<<" .SRP";
		textbackground(1);
		gotoxy(1,5); cout<<"=============================";
		gotoxy(3,3);
		textcolor(0);gets(fname);
		strcat(fname,".SRP");
		if(strcmpi(fname,".SRP")==0) strcpy(fname,"NONAME.SRP");
	gotoxy(10,5);cout<<"FILE SAVED";
	}                                    _setcursortype(_NOCURSOR);
	fstream fs,fsr; fs.open(fname,ios::out);
	//fsr.open("SROPEN.SRP",ios::app);
	fs.write((char*)in,5000);
	fs.close();    c1=1;     upname();
	//fsr<<fname<<" ";
	  getch();
	  window(1,1,80,25);
	  puttext(16,6,44,20,in);   //    fsr.close();
	  window(16,6,44,20);
	  return;
}
					 char cho;

void srnew()
{       window(15,21,45,22);
	textbackground(0);    textcolor(15);   clrscr();
	gotoxy(2,1);  cout<<"Do you want to Save the";
	gotoxy(2,2);  cout<<"Document (Y/N) : "; cho=getche();
	window(16,21,44,21);
	textbackground(7);   clrscr();
	window(16,22,44,22);
	textbackground(0);   clrscr();
	if(cho=='y'||cho=='Y') srsave();
	srite();
}

int srx,sry;

void srquit()
{       window(15,21,45,22);
	textbackground(0);    textcolor(15);   clrscr();
	gotoxy(2,1);  cout<<"Do you want to Save the";
	gotoxy(2,2);  cout<<"Document (Y/N) : "; cho=getche();
	window(16,21,44,21);
	textbackground(7);   clrscr();
	window(16,22,44,22);
	textbackground(0);   clrscr();
	if(cho=='y'||cho=='Y') srsave();
	salut();   //Direct to SALUT
}
		int nopen;
void sropen()
{   	char in[1000],out[1000],sf;          _setcursortype(_NORMALCURSOR);
	gettext(16,6,44,20,in);
	window(16,11,44,15);
	{    	textcolor(15); textbackground(1);   clrscr();
		cout<<"=======================OPEN==";
gotoxy(1,2);    cout<<" Enter the File Name";
		gotoxy(3,3); textbackground(4);
		cprintf("                    ");cout<<" .SRP";
		textbackground(1);
		gotoxy(1,5); cout<<"=============================";
		gotoxy(3,3);          	fstream fs;
		textcolor(0);gets(fname);
		strcat(fname,".SRP");
		if(strcmpi(fname,".SRP")==0)
		{            puttext(16,6,44,20,in);  return;}
		 fs.open(fname,ios::in);
		_setcursortype(_NOCURSOR);
		if(!fs)
		{   	fs.close();	gotoxy(8,5);cout<<"FILE NOT FOUND";
			getch();
			puttext(16,6,44,20,in);
			nopen=0;
		}
		else
		{       window(16,11,44,15);
			fs.read((char*)out,1000);	fs.close();
			gotoxy(8,5);	cout<<"PRESS ANY KEY...";
			//getch();
			nopen=1;
			c1=1;     upname();	puttext(16,6,44,20,out);

		}
	}
	  return;
}


void sresc()
{	mbar();
	gotoxy(8,1);cprintf("SritePAD");
	gotoxy(20,1);cprintf("File");
	gotoxy(27,1);cprintf("Help");
	gotoxy(34,1);cprintf("Go");
}


char che;	char buff[5000];

void srfile()
{
	char srbuf[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,89,25);
	gettext(19,2,28,8,srbuf);
	window(19,2,28,8);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"----------";
		gotoxy(2,2);textcolor(12);cprintf("- N");textcolor(15);cout<<"ew";
		gotoxy(2,3);textcolor(12);cprintf("- O");textcolor(15);cout<<"pen";
		gotoxy(2,5);textcolor(15);cout<<"--------";
		gotoxy(2,4);textcolor(12);cprintf("- S");textcolor(15);cout<<"ave";
		gotoxy(2,6);textcolor(12);cprintf("- Q");textcolor(15);cout<<"uit";
		gotoxy(1,7);textcolor(15);cout<<"__________";
		sf=getch();
	}       window(1,1,80,25);
	puttext(19,2,28,8,srbuf);
		window(1,2,80,25);
	switch(sf)
	{	case's':case'S': srsave();      break;
		case'n':case'N': srnew();  	break;
		case'o':case'O': sropen();	break;
		case'q':case'Q': srquit();
		default:break;
	}
}
void srhelp()
{
	char srbuh[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,15);
	gettext(25,2,38,5,srbuh);
	window(25,2,38,5);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);cout<<"--------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout sPad";
		gotoxy(2,3);textcolor(12);cprintf("- H");textcolor(15);cout<<"elp";
		gotoxy(1,4);textcolor(15);cout<<"______________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(25,2,38,5,srbuh);
		window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': abtsrp();      break;
		case'h':case'H': //srhel();  	break;
		default:break;
	}
}


void sresc1()
{       srx=wherex();   sry=wherey();   nopen=0;
	//gettext(15,6,44,20,buff);
	again:
	mbar1();  textcolor(15);
	gotoxy(8,1);cprintf("SritePAD");
	gotoxy(20,1);textcolor(12);cprintf("F");
	textcolor(15);cprintf("ile");
	gotoxy(27,1);textcolor(12);cprintf("H");textcolor(15);cprintf("elp");
	gotoxy(34,1);textcolor(12);cprintf("G");textcolor(15);cprintf("o");

	che=getch();
	switch(che)
	{	case's':case'S': sfunc();      break;
		case'f':case'F': srfile();     break;
		case'h':case'H': srhelp();     break;
		case'g':case'G': sgo(34);     break;
		case 27: break;
		default: goto again;
	}

	sresc();
	textbackground(7); textcolor(0);
	_setcursortype(_NORMALCURSOR);
	//puttext(15,6,44,20,buff);
	window(16,6,44,20);
	//if(nopen==0)
	  gotoxy(srx,sry);

}

void srite()
{       char ch;   c1=0;
	clear();
	sresc();  window(16,6,44,20);
	textbackground(7); textcolor(0);
	srt:
	_setcursortype(_NORMALCURSOR);
	ch=getch();
	srx=wherex();  sry=wherey();
	switch(ch)
	{       case 27: sresc1();	      break;
		case 13: if(wherey()==15)     break;
			 cprintf("\r\n");	break;

		case  8: if(srx==1) {gotoxy(29,sry-1); cout<<" \b";  break;   }
			 else if(sry<16&&sry>0&&srx<31&&srx>1) cout<<"\b \b";
			    break;

		case  9: if(sry<16&&sry>0&&srx<30&&srx>0)cout<<"\t";	      break;

		case 0:
		{char ar=getch();
		switch(ar)
		{
		case 75: if(srx>1);gotoxy(srx-1,sry); break;
		case 72: if(sry>1);gotoxy(srx,sry-1);  break;
		case 80: if(sry<12);gotoxy(srx,sry+1); break;
		case 77: if(srx<18);gotoxy(srx+1,sry); break;
		case 'S':
			if(sry<16&&sry>0&&srx<30&&srx>0)	cout<<" ";
			if(wherex()==30) cout<<'\b'; break;
		}
		break;
		}

		default:
		if(sry==15&&srx==30) break;
		if(srx==30){  cprintf("\r\n"); cout<<ch;      }
		if(sry<16&&sry>0&&srx<30&&srx>0)
		{      cout<<ch;
		 }

	}

	goto srt;
}