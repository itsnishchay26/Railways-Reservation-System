//#########################################################################//
//-----------------------COMPUTER SCIENCE PROJECT--------------------------//
/*     PROJECT BY
		  NAME: NISHCHAY GUPTA AND SIDDHANT GUPTA
		  CLASS: XI
		  SECTION: A
		  UNDER GUIDANCE OF: MRS. RITU JAIN MA'AM
		  TOPIC: ONLINE RAILWAY RESERVATION PORTAL
		  TERM:FINAL TERM
		  SESSION: 2017-18

									  */
//-------------------------------------------------------------------------//
/*Header Files Used*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int seats=500;//global variable for seats
struct admode //admin mode
{

	char trn[20],brd[20],dst[20];
	int no,dist,time;
	float fare,atm,dtm;
}adm[100]={{"Rajdhani","Delhi","Kanpur",641,7,111,200,1200,8},
	   {"Taj Express","Agra","Kota",124,25146,12,2600,23,24}};
struct usmode//user mode
{
	int m,y,d,pnr,age;
	char from[20],to[20],pname[20],jrn[20];
	float atm,dtm;
}use;
//////////////////////////////////////////////////////////////////////////////
////////////////////////////////ADMIN MODE BEGINS///////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void t_display(int nor)//function to display trains
{
	 for(int i=0;i<nor;i++)
	 {
		cout<<"  "<<endl;
		cout<<"\n\n Train Name = "<<adm[i].trn<<endl
		<<" Train Number = "
		<<adm[i].no<<endl

		<<" Boarding Station = "
		<<adm[i].brd<<endl
		<<" Destination Station = "
		<<adm[i].dst<<endl
		<<" Arrival Time(24-hour format) = "
		<<adm[i].atm<<endl
		<<" Departure Time (24-hour format) = "
		<<adm[i].dtm<<endl
		<<" Distance Covered = "
		<<adm[i].dist<<endl
		<<" Per person Fare =Rs. "
		<<adm[i].fare<<endl
		<<" Travel Time (24-hour format) = "
		<<adm[i].time;
	cout<<"\n No. of seats = "<<seats;
	}
}


int t_input()
{
	 static int i=2;  //it will execute only once coz we have already input the train 1
	 int n;
	 cout<<"\n  Enter the no. of trains you want to create = ";
	 cin>>n;
	 for(int j=1;j<=n;j++)
	 {
		cout<<" Train Name = ";
		gets(adm[i].trn);
		cout<<" Train Number = ";
		cin>>adm[i].no;
		cout<<" Boarding Station = ";
		gets(adm[i].brd);
		cout<<" Destination Station = ";
		gets(adm[i].dst);
		cout<<" Arrival Time(24-hour format) = ";
		cin>>adm[i].atm;
		cout<<" Departure Time (24-hour format) = ";
		cin>>adm[i].dtm;
		cout<<" Covered Distance= ";
		cin>>adm[i].dist;
		cout<<" Per person Fare =Rs. ";
		cin>>adm[i].fare;
		cout<<" Travel Time (24-hour format) = ";
		cin>>adm[i].time;
		i++;
	 }
	 cout<<"\n  No. of seats = "<<seats;

	 return i;

}
int admin()//admin function
{
	 char str[20],pass[20]="admin@123",id[20];
	 int n,nor=1;
	 cout<<" Type User ID and Password to login into Admin Mode "<<endl<<endl;
	  cout<<" Username = ";
	 gets(id);
	 cout<<" Password = ";
	 gets(str);

	 if(strcmp(str,pass)==0)
	{
//		clrscr();
		 cout<<" Welcome Admin "<<id<<endl;
		 nor=t_input();//t-input will return the value of i ie the no. of trains and nor will catch the value of i
	 }
	 else
		cout<<"  Incorrect Password ";
	 return nor;
}
void del(admode adm[100] , &p)
{
	char str[25];
	int p;
	admode adm;
	cout<<"Enter the name of train to be Deleted = ";
	gets(str);
	for(int x=0;x<25;x++)
		if(strcmpi(adm[x].trn,str)==0);
			p=x;
	for(x=p;x<100;x++)
		adm[p-1]=adm[p];
	cout<<"Train"<<p<<"is deleted from record.";
}
////////////////////////////////////////////////////////////////////////////
///////////////////////////// USER MODE BEGINS /////////////////////////////
////////////////////////////////////////////////////////////////////////////
void pnr()
{

	randomize();

	for(int i=1;i<7;i++)
	{
		cout<<random(8);
	}
	getch();
}


void book()
{
	int rseats;
	cout<<" Enter the name = ";
	cin>>use.pname;
	cout<<" Enter the year of birth = ";
	cin>>use.y;
	cout<<" Enter the month of birth = ";
	cin>>use.m;
	cout<<" Enter the date of birth = ";
	cin>>use.d;
	cout<<" Enter the age = ";
	cin>>use.age;
	cout<<" Enter the date of journey = ";
	gets(use.jrn);
	cout<<" "<<endl;


	  cout<<"\n Ticket Booked Successfully "<<endl;



	   cout<<"\n Your PNR No. is : ";
	   pnr();//use of randomize

	   rseats=seats-1;
	   cout<<"\n Remaining Seats = "<<rseats;


}
/*void search()
{
		   int n;
		   for(int i=0;i<=n;i++)
		   {
		cout<<" Train Name =  "<<adm[i].trn<<
		" Train No. =  "<<adm[i].no
		<<" Arrival Time =  "<<adm[i].atm<<
		" Departure Time =  "<<adm[i].dtm
		<<" Travel Time(24 hour format) = "<<adm[i].time
		<<" Covered Distance(in km) = "<<adm[i].dist
		<<" Fare per person = Rs.  "<<adm[i].fare;
		  }

}*/

 void core(int nor)//user function
{
		static int i=2;

		char ch[4],yes[4]="y",no[4]="n";
		cout<<" Enter the Boarding Station = ";
		gets(use.from);
		cout<<" Enter the Destination Station = ";
		gets(use.to);
		int found=0;
		for(int j=0;j<nor+1;j++)
		{

		if(strcmpi(use.from,adm[j].brd)==0 && strcmpi(use.to,adm[j].dst)==0)
		{
			cout<<" Train Name =  "<<adm[j].trn<<endl
		  <<" Train No. =  "<<adm[j].no<<endl
		<<" Arrival Time =  "<<adm[j].atm<<endl
		   <<	" Departure Time =  "<<adm[j].dtm<<endl
		<<" Travel Time(24 hour format) = "<<adm[j].time<<endl
		<<" Covered Distance(in km) = "<<adm[j].dist<<endl
		<<" Fare per person = Rs.  "<<adm[j].fare<<endl;
		cout<<" \n Seats Available "<<seats<<endl;

		cout<<"\n\n Do you want to book tickets ?? "<<endl;
		cout<<" Type y or n "<<endl;
		cout<<" Enter the choice -->> ";
		gets(ch);
		if(strcmp(yes,ch)==0)
		  book();
		else if(strcmp(no,ch)==0)
		cout<<"Thank you for Visiting ";

		else
		cout<<"Invalid Choice ";
		i++;
		found++;

		}

		 }
		 if(found==0)
		cout<<" Train not found";

}
////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void main()
{
	clrscr();
	int ch,nor=1;

	while(1)
	{

		clrscr();

	cout<<"\n\n              WELCOME TO ONLINE RAILWAY RESERVATION PORTAL "<<endl<<endl;

	cout<<"  1.Admin Mode \n"
	"  2.Display Trains \n"
	"  3.User Mode \n"
	"  4.Delete Trains\n"
	"  5.Exit the portal \n\n"
	"  Enter your choice -->> ";
		  cin>>ch;
		clrscr();
	switch(ch)
	{
		case 1: nor=admin();
			break;
		case 2: if (nor!=0)
			t_display(nor);
			  break;
		  case 3: core(nor);
			break;
		  case 4: delete();
			break;
		case 5: exit(0);
			break;
	       default: cout<<"Invalid Choice ";
			break;
	}
	getch();
	}

}
