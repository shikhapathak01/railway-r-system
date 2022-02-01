#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct trains
{
	int train_no;
	char train_name[30];
	char from[30];
	char to[30];
	int fac_fare;
	int sac_fare;
	};
	struct passenger
	{
 int s_no;
 char p_name[30];
 char gender;
 char class[20];
 char address[30];
 int age;
 int ticket_no;
 char mob_no[30];
 int train_no;
 };
void main()
{
 void enter_details();
 void view_trains();
 void book_ticket();
 void all_bookings();
 void search_ticket();
 void cancel_ticket();
char pass[30],original[30],old[30],username[30],ch;
int i,choice;
FILE*fp;
window(1,1,80,25);
textbackground(YELLOW);
 clrscr();
window(20,10,60,15);
textbackground(BLACK);
 clrscr();
gotoxy(6,3);
textcolor(WHITE);
cprintf("RAILWAY RESERVATION SYSTEM");
gotoxy(6,4);
textcolor(WHITE+BLINK);
cprintf("enter username:");
i=0;
while(1)
{
ch=getch();
if(ch==13)
{
username[i]='\0';
break;
}
username[i++]=ch;
printf("-");
}
fp=fopen("username.da","r");
fgets(original,30,fp);
fclose(fp);
if(!strcmp(original,username)==0)
{
printf("incorect username");
printf("\n press any key");
getch();
exit(0);
}
else{
gotoxy(6,4);
textbackground(BLACK);}
cprintf("enter password:");
i=0;
while(1)
{
ch=getch();
if(ch==13)
{
pass[i]='\0';
break;
}
pass[i++]=ch;
printf("*");
}
fp=fopen("pass.da","r");
fgets(old,30,fp);
fclose(fp);
if(!strcmp(old,pass)==0)
{
printf("incorect password");
printf("\n press any key");
getch();
exit(0);
}
else{
window(1,1,80,25);
textbackground(11);
clrscr();
}
window(18,5,60,22);
while(1)
{
textbackground(BLACK);
clrscr();
textcolor(RED);
gotoxy(18,2);
cprintf("MAIN MENUE");
gotoxy(16,3);
cprintf("------------------");
textcolor(WHITE);
gotoxy(5,5);
cprintf("1: add trains");
gotoxy(5,6);
cprintf("2: view trains");
gotoxy(5,7);
cprintf("3: book ticket");
gotoxy(5,8);
cprintf("4: view all bookings ");
gotoxy(5,9);
cprintf("5: search ticket ");
gotoxy(5,10);
cprintf("6: cancel ticket");
gotoxy(5,11);
cprintf("7: Quit");
gotoxy(5,12);
cprintf("------------------------");
gotoxy(5,13);
textcolor(RED+BLINK);
cprintf("enter your choice");
choice=getche();
switch(choice)
{
case '1':
	  enter_details();
	  clrscr();
	  break;
case '2':
	  view_trains();
	  break;
case '3':
	book_ticket();
	break;
case '4':
	all_bookings();
	break;
case '5':
	search_ticket();
	break;
case '6':
	cancel_ticket();
	break;
case '7':
	exit(0);
	break;
default:
   cprintf("you entered wrong choice");
	break;
}
}
}
void enter_details(struct trains t)
{
	FILE*fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	printf("adding train details");
	printf("\n --------------------------------");
	fflush(stdin);
	printf("enter train number");
	scanf("%d",&t.train_no);
	fflush(stdin);
	printf("enter train name");
	gets(t.train_name);
	fflush(stdin);
	printf("enter from");
	gets(t.from);
	fflush(stdin);
	printf("enter to");
	gets(t.to);
	fflush(stdin);
	printf("enter first ac fare");
	scanf("%d",&t.fac_fare);
	fflush(stdin);
	printf("enter second ac fare");
	scanf("%d",&t.sac_fare);
	fflush(stdin);
	fp=fopen("train.txt","ab");
	fwrite(&t,sizeof(t),1,fp);
	fclose(fp);
	textcolor(BLUE+BLINK);
	cprintf("\n successfully saved, press any key....");
	getch();

}
void view_trains(struct trains t)
{
	FILE*fp;
	int i;
	window(1,1,80,25);
	textbackground(YELLOW);
	textcolor(RED);
	clrscr();
	 gotoxy(34,1);
	printf("LIST OF TRAINS");
	printf("\n");
	for(i=0;i<80;i++)
	{
		printf("-");
	}
	gotoxy(1,3);
	printf("t_no.");
	gotoxy(8,3);
	printf("t_name");
	gotoxy(20,3);
	printf("from");
	gotoxy(40,3);
	printf("to");
	gotoxy(50,3);
	printf("fAC_fare");
	gotoxy(60,3);
	printf("sAC_fare");
	printf("\n");
	for(i=0;i<80;i++)
	{
	printf("-");
}
	fp=fopen("train.txt","rb");
	i=5;
	while(fread(&t,sizeof(t),1,fp)!=NULL)
	{
		gotoxy(1,i);
		printf("%d",t.train_no);
		gotoxy(8,i);
		printf("%s",t.train_name);
		gotoxy(20,i);
		printf("%s",t.from);
		gotoxy(40,i);
		printf("%s",t.to);
		gotoxy(50,i);
		printf("%d",t.fac_fare);
		gotoxy(60,i);
		printf("%d",t.sac_fare);
		i++;
}
fclose(fp);
textcolor(RED+BLINK);
printf("\n");
cprintf("press any key");
getch();
}
void book_ticket(struct passenger t1)
{
	 FILE*fp;
	window(1,1,80,25);
	textbackground(WHITE);
	textcolor(BLACK);
	clrscr();
	printf("enter serial number");
	scanf("%d",&t1.s_no);
	fflush(stdin);
	printf("enter passenger name");
	gets(t1.p_name);
	fflush(stdin);
	printf("\nenter gender(m/f)");
	scanf("%c",&t1.gender);
	fflush(stdin);
	printf("enter train number");
	scanf("%d",&t1.train_no);
	fflush(stdin);
	printf("enter travelling class");
	gets(t1.class);
	fflush(stdin);
	printf("enter age");
	scanf("%d",&t1.age);
	fflush(stdin);
	printf("enter ticket number");
	scanf("%d",&t1.ticket_no);
	fflush(stdin);
	printf("enter mobile number");
	gets(t1.mob_no);
	fflush(stdin);
	fp=fopen("ticket.txt","ab");
	fwrite(&t1,sizeof(t1),1,fp);
	fclose(fp);
	textcolor(BLUE+BLINK);
	cprintf("\n successfully booked, press any key....");
	getch();
}
void all_bookings(struct passenger t1)
{
	FILE*fp;
	int i;
	window(1,1,80,25);
	textbackground(YELLOW);
	textcolor(RED);
	clrscr();
	gotoxy(34,1);
	printf("DETAILS OF PASSENGERS");
	printf("\n");
	for(i=0;i<80;i++)
	{
		printf("-");
	}
	gotoxy(1,3);
	printf("s_no.");
	gotoxy(8,3);
	printf("name");
	gotoxy(20,3);
	printf("gender");
	gotoxy(30,3);
	printf("t_name");
	gotoxy(40,3);
	printf("class");
	gotoxy(50,3);
	printf("age");
	gotoxy(60,3);
	printf("t_no");
	gotoxy(70,3);
	printf("mob_no,");
	printf("\n");
	for(i=0;i<80;i++)
	{
	printf("-");
}
	fp=fopen("ticket.txt","rb");
	i=7;
	while(fread(&t1,sizeof(t1),1,fp)!=NULL)
	{
		gotoxy(1,i);
	   printf("%d",t1.s_no);
		gotoxy(8,i);
		printf("%s",t1.p_name);
		gotoxy(20,i);
		printf("%c",t1.gender);
		gotoxy(30,i);
		printf("%d",t1.train_no);
		gotoxy(40,i);
		printf("%s",t1.class);
		gotoxy(50,i);
		printf("%d",t1.age);
		gotoxy(60,i);
		printf("%d",t1.ticket_no);
		gotoxy(70,i);
		printf("%s",t1.mob_no);
		i++;
}
fclose(fp);
textcolor(RED+BLINK);
printf("\n");
printf("press any key");
getch();
}
void search_ticket(struct passenger t1)
{
int sn,flag=0;
FILE*fp;
window(1,1,80,25);
textbackground(BLACK);
textcolor(WHITE);
clrscr();

fp=fopen("ticket.txt","rb");
if(fp==NULL)
{
printf("file cant open");
}
printf("enter the ticket number which you want to find");
scanf("%d",&sn);
while(fread(&t1,sizeof(t1),1,fp)!=NULL)
{
  if(t1.ticket_no==sn)
  {
  flag=1;
  printf("record is found\n");
  printf("%d \n%s \n%c \n%d \n%s \n%d \n%s",t1.s_no,t1.p_name,t1.gender,t1.train_no,t1.class,t1.age,t1.mob_no);
  }
  }
  if(flag==0)
  {
  printf("record not found");
  }
  fclose(fp);
  getch();
  }
  void cancel_ticket(struct passenger t1)
{
char name[30];
unsigned flag=0;
FILE*fp,*fp1;
window(1,1,80,25);
textbackground(BLACK);
textcolor(WHITE);
fopen("ticket.txt","rb");
if(fp==NULL)
{
printf("error:cant open the file");
return;
}
printf("enter passenger name which you want to delete");
scanf("%s",&name);
fp1=fopen("new.txt","ab");
while(fread(&t1,sizeof(t1),1,fp)==1)
{
if(strcmp(name,t1.p_name)!=0)
{
printf("\n record deleted successfully");
fwrite(&t1,sizeof(t1),1,fp1);
}
else
{
flag=1;
}
if(flag==0)
{
printf("\n record not found");
}
fclose(fp);
fclose(fp1);
remove("ticket.txt");
rename("new.txt","ticket.txt");
printf("updated record");
getch();
}
}







