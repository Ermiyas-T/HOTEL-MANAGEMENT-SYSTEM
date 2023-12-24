#include<iostream>
#include<iomanip>
#include "hotel.cpp"
using namespace std;

int main()
{
int option;
that:
system("cls");
do
{
system("cls");
cout.setf(ios_base::right);
cout<<setfill('=');
cout<<setw(27)<<"  Hotel Management "<<setw(8)<<'='<<endl;
cout<<setw(35)<<'='<<endl;
cout.unsetf(ios::right);

cout.setf(ios_base::left);
cout<<setfill(' ');
cout<<setw(34)<<"|  1. Resturant Management      ";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(35)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(34)<<"|  2. Bar Management";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(35)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(34)<<"|  3. Room Management ";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(35)<<"-"<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(34)<<"|  4. Exit ";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(35)<<"-"<<endl;

cout<<"\n Enter Your Option: ";
cin>>option;

try{
       if(option>4 || option<1){
              throw option;
       }
}
catch(int ex){
       cout<<"Invalid option: please insert number from (1-4)";
       getch();
}
switch(option)
{
case 1:
        manageResturant();
        break;
case 2:
      manageBar();
      goto that;
      break;
case 3:
      RoomManagement();
       break;
case 4:
   cout<<"------ Thank you for using this system! --------";
       break;
default:
       cout<<"\nInvalid Option,Please Enter correct option ";
break;
}
} while(option!=4);
getch();
}

