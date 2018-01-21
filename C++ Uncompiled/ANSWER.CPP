#include"file.cpp"
  //(16,6,44,22)
  const int pm=24;
  int anx,any,an,ani; char anbu[1000],a[pm];
  char peti[pm]="Let me ask you something";

void abtans()
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
		gotoxy(5,2);cprintf("ANSWER ME");
		gotoxy(5,3);cprintf("---------");
		//gotoxy(2,4);cprintf("");
		gotoxy(2,5);cprintf("A Game designed to Trick people.");
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
void anshelp(int l)
{                         int lo=l+15;
	char buh[1000],sf;          _setcursortype(_NOCURSOR);
	window(1,1,80,15);
	gettext(l-1,2,lo,5,buh);
	window(l-1,2,lo,5);
	{	textcolor(15); textbackground(0);   clrscr();
		gotoxy(1,1);                                       cout<<"-----------------";
		gotoxy(2,2);textcolor(12);cprintf("- A");textcolor(15);cout<<"bout ANSWERS";
		gotoxy(2,3);textcolor(12);cprintf("- H");textcolor(15);cout<<"elp";
		gotoxy(1,4);textcolor(15);                         cout<<"_________________";
		sf=getch();
	}	window(1,1,80,25);
	puttext(l-1,2,lo,5,buh);
		window(1,2,80,25);
	switch(sf)
	{	case'a':case'A': abtans();      break;
		case'h':case'H': //srhel();  	break;
		default:break;
	}
}





void anesc1()
{	mbar();
	gotoxy(8,1);cprintf("ANSWER ME");
	gotoxy(20,1);cprintf("Help");
	gotoxy(27,1);cprintf("Go");
}
void anesc()
{       anx=wherex();   any=wherey();
	//gettext(1,2,80,25,anbu);

	mbar1();  textcolor(15);
	gotoxy(8,1);cprintf("ANSWER ME");
	gotoxy(20,1);textcolor(12);cprintf("H");textcolor(15);cprintf("elp");
	gotoxy(27,1);textcolor(12);cprintf("G");textcolor(15);cprintf("o");
	again:
	char ch=getch();
	switch(ch)
	{	case's':case'S': sfunc();      break;
		case'h':case'H': anshelp(20);   break;
		case'g':case'G': sgo(27);     break;
		case 27: break;
		default: goto again;
	}

	//bgd(3);
		anesc1();
	_setcursortype(_NORMALCURSOR);
	window(1,2,80,25);
	//puttext(1,2,80,25,anbu);
			    window(16,5,44,22);
	  gotoxy(anx,any);
}



void anclear()
{       anesc1();
	textcolor(15);
	window(15,4,45,23);
	textbackground(0);	clrscr();
	gotoxy(12,1);cout<<"ANSWER ME";
	gotoxy(10,20);cout<<"HELP is always there.";

	window(16,5,44,22);
	textbackground(2);	clrscr(); textcolor(0);
	gotoxy(2,3);cout<<"PETITION:";
	gotoxy(3,4);for(ani=3;ani<28;ani++)cout<<"_";
	gotoxy(2,6);cout<<"QUESTION:";
	gotoxy(3,7);for(ani=3;ani<28;ani++)cout<<"_";
	gotoxy(3,8);for(ani=3;ani<28;ani++)cout<<"_";
	gotoxy(3,9);for(ani=3;ani<28;ani++)cout<<"_";
	gotoxy(3,10);for(ani=3;ani<28;ani++)cout<<"_";
	gotoxy(2,12);cout<<"ANSWER:";
	gotoxy(3,13);for(ani=3;ani<28;ani++)cout<<"_";

	gotoxy(1,16);for(ani=0;ani<29;ani++)cout<<"-";
	gotoxy(2,16);cout<<"Your PETITION:";
	gotoxy(3,17);cout<<"\"Let me ask you something\"";

	window(16,5,44,22);  gotoxy(3,4);
}

void answer()
{	ans:
char c;       int j=0,i=0;   strcpy(a," ");
	anclear();    randomize();
	_setcursortype(_SOLIDCURSOR);
	pet://PETITION
	while(wherex()!=27)
	{	c=getch();
		switch(c)
		{   	case 27: anesc();  break;

			case'.': cout<<peti[i];   //i++;
			for(j;wherex()!=27;j++)
			{	c=getch(); if(c==27) {anesc();continue;}
				i++;
				cout<<peti[i];
				if(c=='.')
				{ i++; goto pet;}
				else a[j]=c;
			}        break;

			case 13: break;

			case  8: if(wherex()==3) break;
				 else {cout<<"\b \b";  	 i--;break;
			      }
			default: cout<<c; i++;
		}
	}                            int answ;
	if(strcmpi(a," ")==0) answ=1;   else answ=0;

	//QUES
	gotoxy(3,7);
	que:
	char ch=getch();
	anx=wherex();  any=wherey();
	switch(ch)
	{       case 27:  anesc();      break;

		case'?': goto ques;
		case 13:    break;
		  //	 cprintf("\r\n");	break;

		case  8: if(anx==1) {gotoxy(27,any-1); cout<<" \b";  break;   }
			 else if(any<11&&any>6&&anx<28&&anx>2) cout<<"\b \b";
			    break;

		case  9:       break;

		case 0:
		{char an=getch();
		switch(an)
		{
		case 75: if(anx>2);gotoxy(anx-1,any); break;
		case 72: if(any>6);gotoxy(anx,any-1);  break;
		case 80: if(any<11);gotoxy(anx,any+1); break;
		case 77: if(anx<28);gotoxy(anx+1,any); break;
		case 'S': break;
			//if(any<16&&any>0&&anx<30&&anx>0)	cout<<" ";
			//if(wherex()==30) cout<<'\b'; break;
		}
		break;
		}

		default:
		if(any==15&&anx==30) break;
		if(anx==27){  gotoxy(3,any+1); cout<<ch;      }
		if(any<11&&any>6&&anx<28&&anx>2)
		{      cout<<ch;
		 }

	}   goto que;

	ques:
	//ANS
	gotoxy(2,12);
	if(answ==0){gotoxy(3,13);   cout<<a;  }
	if(answ==1)
	{	cout<<"NO ANSWER";
		gotoxy(3,13);
		switch(random(3))
	       {case 1:cout<<"I can't get in your mind.";    break;
		case 2:cout<<"You don't believe in me. ";    break;
		case 0:cout<<"You should try once more.";    break;
		}
	}
	textcolor(0); textbackground(2);
	gotoxy(3,15); cprintf("Press any key to go again");
	textcolor(15);
	c=getch();
	if(c==27) anesc();
	goto ans;
}
