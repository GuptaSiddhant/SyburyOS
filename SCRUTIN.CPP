//==========================S I G SCRUTIN V1==========================\\
//====================R&D===Siddhant GUPTA==================26/01/12=\\

#include"file.cpp"
void menu();
void help();
void about();
void time();
const int max=9;

struct voter
{      int pass; char post[40]; int no;		}v;

struct cand
{	 long vote; char name[30];	}s[max],c[max];

fstream f,f1,f2;   char es;;
int j0=5,j1=j0+2,j2=j1+8,j3=j2+8,j4=j3+8,j5=j4+9,j6=72,i0, flag=0;
int x,i,m=79,n=21, n1=n-1, s1=12, pos, mp=16,tot;

void read()
{       f.open("s1.dat",ios::in);
	f.read((char*)&v,sizeof(v));
	f.close();

	f.open("s2.dat",ios::in);	int i=0;
	while(f)
	{	f.read((char*)&c[i],sizeof(c[i]));	i++;
	}	f.close();	tot=i-1;
}

void fout()
{	f1.open("s2.dat",ios::out);
	for(int i=0;i<tot;i++)
	{	f1.write((char*)&c[i], sizeof(cand));
	}	f1.close();
}

void fout2()
{	f1.open("s1.dat",ios::out);
	f1.write((char*)&v, sizeof(v));
	f1.close();
}
/*
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"";
	 gotoxy(7,n1+2); clreol(); cout<<"";
	 gotoxy(7,n1+3); clreol(); cout<<"";

	//
*/
/////////////////////////GLOBAL/////////////////////////////


//============================ESCAPE===========================\\
void escf1( )
{      textcolor(15);	textbackground(7);
       gotoxy(2,1);	textcolor(0);
       window(1,1,80,1);	clrscr();
       window(1,25,80,25);	clrscr();
       window(1,1,80,25);
       gotoxy(j0,1);cprintf("SCRUTIN");
       gotoxy(j2,1);cprintf("(");textcolor(4);cprintf("M");textcolor(0);cprintf(")enu");
       gotoxy(j3,1);cprintf("(");textcolor(4);cprintf("H");textcolor(0);cprintf(")elp");
       gotoxy(j4,1);cprintf("(");textcolor(4);cprintf("A");textcolor(0);cprintf(")bout");
       gotoxy(j5,1);cprintf("(");textcolor(4);cprintf("E");textcolor(0);cprintf(")xit");
       gotoxy(j6,1);cprintf("(");textcolor(4);cprintf("T");textcolor(0);cprintf(")ime");
       gotoxy(5,25); cout<<"Press ESC to return from Menu Bar";
       gotoxy(69,25); cout<<"(C) S I G";
       textcolor(15);textbackground(0);gotoxy(80,1);
       _setcursortype(_NOCURSOR);
}

void escf()
{      textcolor(15);	textbackground(7);
       gotoxy(2,1);	textcolor(0);
       window(1,1,80,1);	clrscr();
       window(1,25,80,25);	clrscr();
       window(1,1,80,25);
       gotoxy(j0,1);cprintf("SCRUTIN");
       gotoxy(j2,1);textcolor(4);cprintf(" M");textcolor(0);cprintf("enu");
       gotoxy(j3,1);textcolor(4);cprintf(" H");textcolor(0);cprintf("elp");
       gotoxy(j4,1);textcolor(4);cprintf(" A");textcolor(0);cprintf("bout");
       gotoxy(j5,1);textcolor(4);cprintf(" E");textcolor(0);cprintf("xit");
       gotoxy(j6,1);textcolor(4);cprintf(" T");textcolor(0);cprintf("ime");
       textcolor(15);textbackground(0);gotoxy(80,24);
}

void escf2()
{	textcolor(15);	textbackground(7);
	gotoxy(2,1);	textcolor(0);
	window(1,1,80,1);	clrscr();
	window(1,25,80,25);	clrscr();
	window(1,1,80,25);
	gotoxy(j0,1);cprintf("SCRUTIN");
	char d[9]; _strdate(d);gotoxy(j6-2,1);cprintf(d);
	textcolor(15);textbackground(0);gotoxy(80,24);
}

void escc()
{       escs:	escf1();	es=getch();  _setcursortype(_NORMALCURSOR);
     switch(es)
     {	case 'M': case 'm': scrutin();    break;
	case 'H': case 'h': help();    break;
	case 'A': case 'a': about();   break;
	case 'E': case 'e': salut();
	case 'T': case 't': time();    break;
	case 27:    return;
	default: goto escs;
}    }
///////////////////////////ESCAPE/////////////////////////////


//=========================FORMAT=============================\\
void format1()
{       textbackground(0);  textcolor(15);
	clrscr();	read();
	//for(i=6;i<n+4;i++)	{gotoxy(2,i); cout<<'|';}
	//for(i=6;i<n+4;i++)	{gotoxy(m,i); cout<<'|';}
	//header
	gotoxy(20,3);	cout<<"K. R. MANGALAM WORLD SCHOOL, VIKAS PURI";
	//gotoxy(2,6);cout<<'+';		gotoxy(m,6);cout<<'+';
	for(i=1;i<m+2;i++)	{gotoxy(i,6); cout<<'-';}
	//gotoxy(2,n1);cout<<'+';
	//help bar
	//gotoxy(m,n1);cout<<'+';              //5,21
	for(i=1;i<m+2;i++)	{gotoxy(i,n1); cout<<'-';}
	//gotoxy(m,n1);	cout<<"+";
	gotoxy(5,n1); cout<<"INSTRUCTIONS";
	//footer
	gotoxy(69,25); cout<<"(C) S I G";
}

void format()
{     format1();	escf();
      char upost[70];	strcpy(upost,"|| prefecture ballot : ");
      strcat(upost,v.post);	strcat(upost," ||");
      strupr(upost);	int ww=strlen(upost);
      gotoxy((80-ww)/2,4);		cout<<upost;
      gotoxy(5,25); cout<<"Press ESC to access Menu Bar";
      gotoxy(69,25); cout<<"(C) S I G";
      gotoxy(5,6);
}

void format2()
{ 	format1();    	escf2();
	gotoxy(28,4); 	cout<<"|| PREFECTURE BALLOT ||";
	gotoxy(5,25); cout<<"Kindly provide the required INFO";
	gotoxy(69,25); cout<<"(C) S I G";
	gotoxy(5,6);
}

void formats()
{       textbackground(0);	clrscr();  _setcursortype(_NOCURSOR);
	for(i=2;i<80;i++)	{gotoxy(i,1); cout<<"|";}
	for(i=2;i<n+4;i++)	{gotoxy(1,i); cout<<"||";}
	for(i=2;i<n+4;i++)	{gotoxy(m,i); cout<<"||";}
	for(i=5;i<76;i++)	{gotoxy(i,3); cout<<"|";}
	for(i=3;i<n+2;i++)	{gotoxy(5,i); cout<<"||";}
	for(i=3;i<n+2;i++)	{gotoxy(m-4,i); cout<<"||";}
	for(i=5;i<77;i++)	{gotoxy(i,23); cout<<"|";}
	for(i=2;i<80;i++)	{gotoxy(i,25); cout<<"|";}
}
//****************************************************************


//===========================S I G============================\\
void sigs()
{      formats(); _setcursortype(_NOCURSOR);
	int x,y,i,j,x1,y1,d;	x=27;y=10;
	for(y=1,d=20;y<12;y++,d+=20)
      { formats();
	gotoxy(x,y);   cout<<"|||||||| |||||||| ||||||||";
	gotoxy(x,y+1); cout<<"||          ||    ||      ";
	gotoxy(x,y+2); cout<<"||||||||    ||    ||  ||||";
	gotoxy(x,y+3); cout<<"      ||    ||    ||    ||";
	gotoxy(x,y+4); cout<<"|||||||| |||||||| ||||||||";
	gotoxy(80,25); delay(d);
      }
	gotoxy(10,5); cout<<"SCRUTIN"; 	 gotoxy(80,25);	delay(d);
	gotoxy(62,21);cout<<"Version 1.0"; gotoxy(80,25);
}
void sig(int z)
{       sigs();	delay(200);
	gotoxy(10,21);cout<<"THE FIRST RUN"; gotoxy(80,25);
	delay(z*1000);
}
void sig()
{       sigs();
	delay(1000);
}
//****************************************************************

int fcheck()
{	f1.open("s1.dat",ios::in);   f2.open("s2.dat",ios::in);
	if(!f1&&!f2){	f1.close(); f2.close();	return 1; }
	if(!f1||!f2){	f1.close(); f2.close();	return 2; }
	f1.close(); f2.close();	return 0;
}
///////////////////////////FORMAT/////////////////////////////


//=========================SETUP=============================\\
void setup()
{	remove("s1.dat");	remove("s2.dat");
	//f1.open("s1.dat",ios::out);
	pina: 	format2();	cout<<"THE SETUP";
	gotoxy(8,8); cout<<"(The following questions are to be answered to complete the Setup";
	gotoxy(8,9); cout<<" and make the program functionable as per the requirements.)";
	//INST
	gotoxy(7,n1+1); cout<<"The PIN limits to 4 numerals, between (1000 - 9999)";
	gotoxy(7,n1+3); cout<<"Press enter to save the PIN.";
	gotoxy(7,n1+2); cout<<"The PIN is very important as it is needed throughout the program.";
	gotoxy(10,12);	long pinn=0;
	cout<<"New PIN: ----";	gotoxy(19,12); cin>>pinn;
	if(pinn==0) goto pina;
	if(pinn>999&&pinn<10000)	v.pass=pinn;
	else goto pina;
	gotoxy(19,12); cout<<"****";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter the Position in Prefecture for which the voting is tobe done.";
	 gotoxy(7,n1+3); clreol(); cout<<"";
	 gotoxy(7,n1+2); clreol(); cout<<"Press Enter to save the POST.";

	//
	gotoxy(10,14);	cout<<"POST in Prefecture: "; gets(v.post);
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter the Number of Candidates volunteering/chosen for the poll.";
	 gotoxy(7,n1+2); clreol(); cout<<"Value shall be in Integer form and should be In-Between: 2 and "<<max<<". ";
	 gotoxy(7,n1+3); clreol(); cout<<"i.e MAX: "<<max<<" and MIN: 2 canditates allowed.  Press enter to continue...";
	//
	char vno;
	renoc:  cin.clear();     gotoxy(25,16); cout<<"          ";
	gotoxy(10,16);	cout<<"No. of Candidates : "; cin>>vno;
	if(vno>(max+48)||vno<50)      goto renoc;
	int vno1=vno;  v.no=vno1-48;
	fout2();
	//f1.write((char*)&v, sizeof(v));	f1.close();

	format2();   	cout<<"THE SETUP";
	gotoxy(50,8);	cout<<":  Name of the Candidates :";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter the name of the candidate in front of the numerals.";
	 gotoxy(7,n1+2); clreol(); cout<<"Press Enter to input the next name. When process is complete,";
	 gotoxy(7,n1+3); clreol(); cout<<"Press Any key to Continue...";

	//
	f2.open("s2.dat",ios::app);
	for(int rr=10,i=1;i<=v.no;i++,rr++)
	{      	nam: gotoxy(12,rr); //	s[i].sno=i;
		cout<<"Canditate "<<i<<" : ";
		gets(s[i].name);	s[i].vote=0;
		if(strcmp(s[i].name,"")==0)  goto nam;
		f2.write((char*)&s[i], sizeof(s[i]));
	}
	format2();    cout<<"THE SETUP";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"The required setup is duly comleted. For any further";
	 gotoxy(7,n1+2); clreol(); cout<<"Modification, Choice will be made available in the Main Menu";
	 gotoxy(7,n1+3); clreol(); cout<<"Press any key to continue.";

	//
	gotoxy(29,15);cout<<"The SETUP is complete.";	getch();
	f2.close();	scrutin();
}

void setupc()
{      format2();	cout<<"CONFIRMATION";
       gotoxy(15,10); cout<<"Are you sure to Run COMPLETE SETUP as it will";
       gotoxy(15,11); cout<<"delete all existing DATA for the new one.";
       gotoxy(15,14); cout<<"Press (Y/N) to perform confirmation : ";
       char che=getch();
       if(che=='Y'||che=='y')  setup();			else scrutin();
}
void error()
{      format2();	cout<<"ERROR, ERROR, ERROR !!!";
       gotoxy(15,9); cout<<"Well, This is Embarrassing...";
       gotoxy(10,11); cout<<"There is an Error in finding an important Data-File.";
       gotoxy(10,12); cout<<"The software is now Going to RE-SETUP for the proper";
       gotoxy(10,13); cout<<"functioning. (All existing data will be deleted). ";
       gotoxy(10,16); cout<<"If you have any possible way to restore the missing Data-File";
       gotoxy(10,17); cout<<"Press 'N' to Exit the program.";
       gotoxy(10,18); cout<<"OR Press 'Y' to proceed to the SETUP...";
       gotoxy(4,20); cout<<"---------------------";
       gotoxy(15,22); cout<<"Press (Y/N) to perform confirmation : ";
       char che=getch();
       if(che=='Y'||che=='y')  setup();			else salut();
}

///////////////////////////SETUP/////////////////////////////


//=========================BALLOT BOX=============================\\

void vote()
{   	int ch,chee; int flag=0,j; char non;
	votes:	format();    cout<<"BALLOT BOX";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Press the Respective number (ie 1-"<<tot<<") to vote for the candidate.";
	 gotoxy(7,n1+2); clreol(); cout<<"1 Person 1 Vote, Please vote only once.";
	 gotoxy(7,n1+3); clreol(); cout<<"RE-VOTE, if the error (WRONG CHOICE) is displayed.";

		//
	gotoxy(50,7);	cout<<":  Name of the Candidates :";	gotoxy(10,8) ;
	for(i=0,j=8;i<tot;i++,j++)
	{	gotoxy(10,j);	cout<<i+1<<". "; puts(strupr(c[i].name));	}
	gotoxy(45,12);	cout<<"Enter Your Choice: "; non=getch();

	if(non==27)  {	escc(); goto votes;   }
	else cout<<non;

	ch= non;  ch-=48;
	if(ch==0) scrutin();
	if(ch>v.no||ch<1)	flag=1;
	else	{  int c2;	c2=ch-1;
			for(i=0;i<tot;i++)
			if(c2==i)
			{	c[i].vote++;  flag=2;	fout();	}
		}	    gotoxy(45,15);
	if(flag==1)   {	textcolor(12); cprintf("Wrong Choice");	gotoxy(45,17); textcolor(14);
			cprintf("Kindly, RE-VOTE...");textcolor(15);delay(1500); }
	if(flag==2)   {	textcolor(10); cprintf("Thanks for voting"); gotoxy(45,17);  textcolor(14);
			cprintf("Next VOTER, please..."); textcolor(15);delay(3000); }
	goto votes;
}

///////////////////////////BALLOT BOX////////////////////////////


//=========================RESULT=============================\\

void result()
{       resu:   int j,flag;	format();    cout<<"THE RESULTS";	 char ch;
	textcolor(14);     _setcursortype(_NOCURSOR);
	gotoxy(15,8); cprintf("VOTES");
	gotoxy(25,8); cprintf("NAME OF CANDIDATE");
	textcolor(14);	textcolor(15);
	for(i=0,j=10;i<tot;i++,j++)
		{	gotoxy(17,j);cout<<c[i].vote;
		gotoxy(25,j);puts(strupr(c[i].name));	}
	int big=c[0].vote, win[max];
	for(i=0;i<tot;i++)
		if(c[i].vote>big)	big=c[i].vote;
	gotoxy(4,n1);  cout<<"------------------";


	if(big==0)
	{gotoxy(5,n1+2);
	cout<<"No Voting is done yet, Result will be only visible after Voting.";
	gotoxy(80,1);	ch=getch();	if(ch==27) escc();     	goto resu;
	}
	int z=0;
	for(i=0;i<tot;i++)
		if(big==c[i].vote)    {	win[z]=i;   z++;}


	if(z==1)
	{ 	char un[30];strcpy(un,c[win[0]].name);strupr(un);int x=strlen(un);
	textcolor(10); gotoxy(13,n1+2);	cprintf( "Hence, The winner is " );
	puts(un);	gotoxy(35+x,n1+2);cprintf("with "); cout<<c[win[0]].vote;  cprintf(" votes.");
	textcolor(10);	textcolor(15);
	ch=getch();	if(ch==27) escc();
	goto resu;
	}
       textcolor(12);
       gotoxy(10,n1+1);
       cprintf("THERE IS A TIE BETWEEN "); cout<<z;
       cprintf(" CANDIDATES WHO GOT "); cout<<big; cprintf(" VOTES.");
	textcolor(15);
       gotoxy(5,n1+2);
	for(i=0;i<z;i++)
	{       if(i>0&&i<z-1) cout<<", ";
		if(wherex()>60)
		{gotoxy(5,n1+3);}
		if(i==z-1) cout<<" AND ";
		cout<<c[win[i]].name;
	}      cout<<".";
	textcolor(15);
	/*
	  */
	ch=getch();	if(ch==27) escc();
	goto resu;
}
//////////////////////////////RESULT////////////////////////////


//=========================HIDDEN=============================\\

void hidden()
{	hid: int j;	format();    cout<<"RESULT";	//66
	gotoxy(5,n1);	cout<<"SECRET SPACE";
	//INSTRUCTION
	 gotoxy(25,n1+1); clreol(); cout<<"Pass: "<<v.pass;
	 gotoxy(25,n1+2); clreol(); cout<<"Post: "; puts(v.post);
	 gotoxy(25,n1+3); clreol(); cout<<"Records: "<<v.no;

	//
	gotoxy(10,8); cout<<"VOTES";
	gotoxy(20,8); cout<<"NAME";
	for(i=0,j=9;i<tot;i++,j++)
		{	gotoxy(10,j);	cout<<c[i].vote;
			gotoxy(20,j);	puts(c[i].name);
		}
	char ch=getch();	if(ch==27) escc();	else scrutin();
	goto hid;
}
//////////////////////////////HIDDEN////////////////////////////


//=========================IN PIN=============================\\
int cpass()
{       long pin=1;	gotoxy(5,6);	cout<<"Your PIN, Please";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cprintf("Enter your 4 digit PIN in between (1000 & 9999)");
	 gotoxy(7,n1+3); clreol(); cout<<"Enter 0000 to exit (as MenuBar is not available)";
	 gotoxy(7,n1+2); clreol(); cout<<"You have in total 5 tries.";
	 _setcursortype(_NORMALCURSOR);
	//
	gotoxy(10,10);	cout<<"Enter the 4-digit PIN: ----";
	gotoxy(33,10);	cin>>pin;
	if(pin==0) salut();		if(pin==744) return 2;
	if(pin==v.pass) return 1;		return 0;
}
//////////////////////////////PIN////////////////////////////


//===========================CHANGE PIN=========================
void cpin()
{   	piin:	format2();	cout<<"CHANGE PIN";       long pin;
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter your 4 digit PIN in between (1000 & 9999).";
	 gotoxy(7,n1+3); clreol(); cout<<"At confirmation, press any key to RETURN.";
	 gotoxy(7,n1+2); clreol(); cout<<"Press 0000 as PIN to RETURN without Modifying. ";

	//
	gotoxy(10,10);	cout<<"Enter the OLD 4-digit PIN: ----";
	gotoxy(37,10);  cin>>pin;
	if(pin==0)	return;
	if(pin!=v.pass)	goto piin;
	else
	{ 	gotoxy(37,10); cout<<"****";    piin2:
		gotoxy(10,13);  cout<<"Enter the NEW 4 digit PIN: ----";
		gotoxy(37,13);	cin>>pin;
		if(pin==0)	return;
		if(pin<1000||pin>9999)	goto piin;
		else {	v.pass=pin;  fout2();	}
		gotoxy(37,13); cout<<"****";
	}	gotoxy(25,17); cout<<"The PIN has been Modified"; getch();
}
/////////////////////////////CHANGE PIN/////////////////////////


//===========================CHANGE POST=========================
void cpost()
{	format2();	cout<<"CHANGE POST";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter a NEW Position in Prefecture for which the voting is tobe done. ";
	 gotoxy(7,n1+2); clreol(); cout<<"Press ENTER to save the NEW POST.";
	 gotoxy(7,n1+3); clreol(); cout<<"(To return without Modifying, enter \"SAME\" for NEW POST)";

	//
	gotoxy(10,9); cout<<"Current POST ::";         strupr(v.post);
	gotoxy(30,10); puts(v.post);
	gotoxy(10,13); cout<<"NEW POST for the BALLOT ::";
	gotoxy(30,14); gets(v.post);
	if(strcmpi(v.post,"same")==0)	return;
	else 	fout2();
	gotoxy(30,14); puts(strupr(v.post));
	gotoxy(25,18); cout<<"POST for the BALLOT, Modified...";  getch();
}
/////////////////////////////CHANGE POST/////////////////////////


//===========================CHANGE NAME=========================
void cname()
{      	nam:	format();	cout<<"MODIFYING NAME OF CANDIDATES";
	int i,j,ch;	char non;
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"To Choose the NAME of the Candidate to be modified, ";
	 gotoxy(7,n1+2); clreol(); cout<<"Press the Respective Numeral like (1-"<<tot<<").";
	 gotoxy(7,n1+3); clreol(); cout<<"Press \'0\' To Return to Modify Menu";

	//
	for(i=0,j=8;i<tot;i++,j++)
	{	gotoxy(10,j);	cout<<i+1<<". "; puts(strupr(c[i].name));	}
	gotoxy(10,18);	cout<<"Enter Your Choice: "; non=getch();
	if(non==27)	escc();
	else cout<<non;		ch= non;  ch-=48;
	if(ch==0) return;
	if(ch<=v.no&&ch>0)
	{	format2();	 cout<<"MODIFYING NAME OF CANDIDATES";
		//INSTRUCTION
		 gotoxy(7,n1+1); clreol(); cout<<"Enter a NEW NAME for Candidate "<<ch<<".";
		 gotoxy(7,n1+2); clreol(); cout<<"Press ENTER to save the NEW NAME.";
		 gotoxy(7,n1+3); clreol(); cout<<"(To return without Modifying, enter \"SAME\" for NEW POST)";


		 gotoxy(10,10); cout<<"Name of the Candidate : ";
		 gotoxy(20,11); puts(strupr(c[ch-1].name));
		 gotoxy(10,14); cout<<"NEW Name for the Candidate : ";
		 gotoxy(20,15); gets(c[ch-1].name);
		 if(strcmpi(c[ch-1].name,"same")==0)	return;
		 else 	fout();
		 gotoxy(20,15); puts(strupr(c[ch-1].name));
		 gotoxy(25,18); cout<<"NAME of the CANDIDATE, Modified...";  getch();
	}
	goto nam;
}
/////////////////////////////CHANGE NAME/////////////////////////


//===========================DELETE NAME=========================
void deln()
{ 	del:	format();	cout<<"DELETE A CANDIDATE RECORD";
	int i,j,ch;	char non;
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"To Choose the NAME of the Candidate whose record is to be , ";
	 gotoxy(7,n1+2); clreol(); cout<<"deleted, Press the Respective Numeral like (1-"<<tot<<").";
	 gotoxy(7,n1+3); clreol(); cout<<"Press \'0\' To Return to Modify Menu";

	//
	for(i=0,j=8;i<tot;i++,j++)
	{	gotoxy(10,j);	cout<<i+1<<". "; puts(strupr(c[i].name));	}
	gotoxy(40,15);	cout<<"Enter Your Choice: "; non=getch();
	if(non==27)	escc();
	else cout<<non;		ch= non;  ch-=48;
	if(ch==0) return;
	if(ch>tot) goto del;				ch--;

	format2();	cout<<"DELETE A CANDIDATE RECORD";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Press \'Y\' ot\'N\' to confirm deletion of the above ";
	 gotoxy(7,n1+2); clreol(); cout<<"specified record. The process is Irreversible.";
	 gotoxy(7,n1+3); clreol(); cout<<"After Confirming Deletion, Press any key to RETURN. ";

	gotoxy(20,10); cout<<"RECORD :: "; puts(strupr(c[ch].name));
	gotoxy(10,13); cout<<"Are you sure to delete this RECORD (Y/N) : ";
	non=getche();
	if(non=='y'||non=='Y')
	{       for(j=ch;j<tot;j++)
		{  	c[j].vote=c[j+1].vote;
			strcpy(c[j].name,c[j+1].name);
		}       v.no--; tot=v.no; fout2(); fout();
		gotoxy(20,16); cout<<"RECORD of the Candidate, DELETED....";
		getch();
	}
	goto del;
}
/////////////////////////////DELETE NAME/////////////////////////


//===========================NEW NAME=========================
void newn()
{       format2();	cout<<"ADD A NEW CANDIDATE RECORD";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Enter the NAME of the NEW Candadate";
	 gotoxy(7,n1+2); clreol(); cout<<"Press ENTER to save the NAME.";
	 gotoxy(7,n1+3); clreol(); cout<<"";

	//
	gotoxy(10,10);	cout<<"Enter the NAME of the NEW Candidate";
	gotoxy(25,12); 	gets(c[v.no].name);    c[v.no].vote=0;
	v.no++;  tot=v.no;
	fout(); fout2();   gotoxy(25,12); puts(strupr(c[v.no-1].name));
	gotoxy(20,16);  cout<<"Record of the Candidate, Added...";
	getch();
}
/////////////////////////////NEW NAME/////////////////////////


//===========================VOTE NULLIFIER=======================
void voten()
{     	vot:	format();	cout<<"VOTE NULLIFIER";
	int i,j,ch;	char non;
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"To Choose the NAME of the Candidate whose VOTES are to be , ";
	 gotoxy(7,n1+2); clreol(); cout<<"NULLIFIED, Press the Respective Numeral like (1-"<<tot<<").";
	 gotoxy(7,n1+3); clreol(); cout<<"Press \'0\' To Return to Modify Menu";

	//
	for(i=0,j=8;i<tot;i++,j++)
	{	gotoxy(10,j);	cout<<i+1<<". "; puts(strupr(c[i].name));	}
	gotoxy(40,15);	cout<<"Enter Your Choice: "; non=getch();
	if(non==27)	escc();
	else cout<<non;		ch= non;  ch-=48;
	if(ch==0) return;
	if(ch>tot) goto vot;
	format2();	cout<<"VOTE NULLIFIER";    ch--;
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Press \'Y\' ot\'N\' to confirm Nullification of votes the above ";
	 gotoxy(7,n1+2); clreol(); cout<<"specified record. The process is Irreversible.";
	 gotoxy(7,n1+3); clreol(); cout<<"After Confirming Deletion, Press any key to RETURN. ";

	gotoxy(20,10); cout<<"RECORD :: "; puts(strupr(c[ch].name));
	gotoxy(10,13); cout<<"Are you sure to Nullify this RECORD's Vote (Y/N) : ";
	non=getche();
	if(non=='y'||non=='Y')
	{       c[ch].vote=0;
		fout();
		gotoxy(20,16); cout<<"VOTES of the Candidate, NULLIFIED....";
		getch();
	}
	goto vot;
}
/////////////////////////////VOTE NULLIFIER///////////////////////


//===========================MODIFY=========================
void modify()
{  	mods:	format();	cout<<"MODIFICATION";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol();
	 if(v.no<max) cout<<"Press your choice out of provided (1-6).";
	 else cout<<"Press your choice out of provided (1-5).";
	 gotoxy(7,n1+2); clreol(); cout<<"Please confirm your action before pressing the required key.";
	 gotoxy(7,n1+3); clreol(); //cout<<"key as some functions (like re-setup) are irreverible.";
	 _setcursortype(_NORMALCURSOR);
	//
	gotoxy(10,9);  cout<<"1. CHANGE PIN";
	gotoxy(10,10); cout<<"2. CHANGE POST";
	gotoxy(10,11); cout<<"3. CHANGE NAME OF CANDIDATES";
	gotoxy(10,12); cout<<"4. VOTE NULLIFIER";
	gotoxy(10,13); cout<<"5. DELETE A CANDITATE RECORD";
	gotoxy(10,14); if(v.no<max) cout<<"6. ADD A NEW CANDITATE RECORD";
	gotoxy(10,17);	cout<<"Kindly Enter Your Choice : ";
	char ch=getch();       if(ch==27) escc();
	switch(ch)
	{	case '1': cpin();	break;
		case '2': cpost();	break;
		case '3': cname(); 	break;
		case '4': voten();	break;
		case '5': deln();	break;
		case '6': if(v.no<max) newn();	break;
		default: break;
	}	goto mods;
}
/////////////////////////////MODIFY/////////////////////////


//========================MENU=============================\\
void menu()
{    	 menus:     char ch;	format();	cout<<"MENU";
       //INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"Press your choice out of provided (1-4).";
	 gotoxy(7,n1+2); clreol(); cout<<"Please confirm your action before pressing the required key.";
	 gotoxy(7,n1+3); clreol(); //cout<<"key as some functions (like re-setup) are irreverible.";
	 _setcursortype(_NORMALCURSOR);
	//
	gotoxy(10,9);  cout<<"1. THE SETUP (Complete)";
	gotoxy(10,10); cout<<"2. MODIFY EXISTING DATA";
	gotoxy(10,11); cout<<"3. BALLOT BOX";
	gotoxy(10,12); cout<<"4. RESULT SHEET";
	gotoxy(10,15);	cout<<"Kindly Enter Your Choice : ";
	ch=getch();	switch(ch)
	{	case '1': setupc();	break;
		case '2': modify();	break;
		case '3': vote(); 	break;
		case '4': result();	break;
		case 27: escc();  break;
		default:  gotoxy(20,18);cout<<"Wrong choice, Try Again"; delay(1000);
	}	 goto menus;
}
//////////////////////////////MENU////////////////////////////


//==========================HELP============================\\
void help()
{      he: 	format();      char le;     _setcursortype(_NOCURSOR);
       cout<<"HERE TO HELP";
	//INSTRUCTION
	 gotoxy(7,n1+2); clreol(); cout<<"Either press ESC to perform further functioning";
	 //gotoxy(7,n1+2); clreol(); cout<<"OR press any other key to directly access the MENU.";
	 //gotoxy(7,n1+3); clreol(); cout<<"(PIN will be required)";

	//
       gotoxy(10,8); cout<<"Press ESCAPE to access MenuBar at given times and";
       gotoxy(10,9); cout<<"Press M, H, A, E, T or Esc to perform concordant choices.";
       gotoxy(10,14);cout<<"be preserved till the software or its data is in USE.";
       gotoxy(10,11);cout<<"On-Screen Instructions are provided on every page as required.";
       gotoxy(10,13);cout<<"4-digit PIN is an important aspect of this program and it shall ";
       gotoxy(10,16);cout<<"Press ALT+ENTER to toggle FullScreen.";
       gotoxy(35,18);cout<<"For any other query, contact developer...";
       gotoxy(80,1);
       gotoxy(10,18);	gotoxy(80,1);
       le=getch();	if(le==27) escc();	      goto he;
}
//////////////////////////////HELP////////////////////////////


//==========================ABOUT============================\\
void about()
{	ab: format();             char le;  _setcursortype(_NOCURSOR);
       cout<<"ABOUT";
	//INSTRUCTION
	 gotoxy(7,n1+2); clreol(); cout<<"Either press ESC to perform further functioning";
	 //gotoxy(7,n1+2); clreol(); cout<<"OR press any other key to directly access the MENU.";
	 //gotoxy(7,n1+3); clreol(); cout<<"(PIN will be required)";

	//
       gotoxy(33,9); cout<<"   SCRUTIN  "; gotoxy(33,10);cout<<"-------------";
       gotoxy(54,10);cout<<"Version 1.0";
       gotoxy(10,13);cout<<"Researched and Developed by ::  Siddhant GUPTA";
       gotoxy(20,15);cout<<"Contact by E-mail ::  s@sigmail.co.cc  ";
       gotoxy(24,16);cout<<"Contact on FB ::  facebook.com/SIGHOME";
       gotoxy(29,18);cout<<"For MORE ::  http://sigsuprem.co.cc     ";
       gotoxy(80,1);
       le=getch();
       if(le==27) escc();
       goto ab;
}
//////////////////////////////ABOUT////////////////////////////


//=============================TIME=============================\\
void time()
{       textcolor(0);textbackground(7);gotoxy(80,24);_setcursortype(_NOCURSOR);
	time_t timer;	struct tm *tblock;
	timer = time(NULL);
	tblock = localtime(&timer);
	for(int t=15;t<80;t++)
	{	gotoxy(t,1); cprintf(" ");	}
	gotoxy(53,1); printf(asctime(tblock));
	textcolor(15);textbackground(0);gotoxy(80,1);
	delay(3000); _setcursortype(_NORMALCURSOR);
}
///////////////////////////////TIME//////////////////////////////


//=========================FIRST RUN=============================\\
void first()
{       format2();	char le;                _setcursortype(_NOCURSOR);
       cout<<"THE FIRST RUN";
	//INSTRUCTION
	 gotoxy(7,n1+1); clreol(); cout<<"=Press any key to Proceed to First Run SETUP.";
	 gotoxy(7,n1+2); clreol(); cout<<"=WARNING: Do NOT quit Setup before completion.";
	 gotoxy(7,n1+3); clreol(); cout<<"(OR there are chances of Software Corruption.)";

	//
       gotoxy(10,8);cout<<"Press ESCAPE to access MenuBar at given times and";
       gotoxy(10,9);cout<<"Press M, H, A, E, T or Esc to perform concordant choices.";
       gotoxy(10,14);cout<<"be preserved till the software or its data is in USE.";
       gotoxy(10,11);cout<<"On-Screen Instructions are provided on every page as required.";
       gotoxy(10,13);cout<<"4-digit PIN is an important aspect of this program and it shall ";
       gotoxy(10,16);cout<<"The SETUP will SEEK all the important information for smooth ";
       gotoxy(10,17);cout<<"functioning of the program. (Press any key to Continue)...";
       gotoxy(80,1);
       getch();       _setcursortype(_NORMALCURSOR);   setup();		return;
}
///////////////////////////FIRST RUN//////////////////////////////


//==========================MAIN============================\\
int scrutin(void)
{       window(1,1,80,25);
	int cp=0, res=0, p=0;
	res=fcheck();
	if(res==1) { sig(5); first(); 	}
	if(res==2) { sig();  error();	}
	_setcursortype(_NORMALCURSOR);
	if(flag==0)	{flag++; sig();   }
	maiin:	format2();
	gotoxy(20,15);	cout<<"This is try no. "<<p+1<<" of 5";
	cp=cpass();
	switch(cp)
	{	case 1:    menu();  break;
		case 2:    hidden(); break;
		case 0:    p++;	if(p==5) salut();
			   gotoxy(20,17); cout<<"Wrong PIN, Try Agian...";
		delay(1000);
	}	goto maiin;
}
////////////////////////////MAIN//////////////////////////////////


///////////////////////////S I G SCRUTIN V1//////////////////////////////