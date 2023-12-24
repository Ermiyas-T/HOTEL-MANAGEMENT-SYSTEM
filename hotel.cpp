#include<iostream>
#include "hotel.h"

#define MAX 100

// Food Food::food(string foodName,double foodPrice)
//     {
//         name = foodName;
//         price= foodPrice;
//         return food(foodName,foodPrice);
//     }
//     //this funtion is used to get the food name from the user 
string Food::getName()
    {
       cout<<"please enter the food's name: \n";
       cin>>name;
       return name;
    }
    //this funtion is used to get the food price from the user 
double Food::getPrice() 
    {
      cout<<"please enter the food's price: \n";
      cin>>price;
      return price;
    }
Drink Drink::drink(string drinkName,double drinkPrice)
    {
        name = drinkName;
        price= drinkPrice;
        return drink(drinkName,drinkPrice);
    }
    //this funtion is used to get the drink name from the user 
string Drink::getName()
    {
       cout<<"please enter the drink's name: \n";
       cin>>name;
       return name;
    }
    //this funtion is used to get the drink price from the user 
double Drink::getPrice() 
    {
      cout<<"please enter the drink's price: \n";
      cin>>price;
      return price;
    }

// this function is used to count foods in the menu file
int Resturant::count(){

        fstream myfile;
        Food food;
        myfile.open("FOOD.txt",ios::in);
        string line;
        while (!myfile.eof())
              {
               menu_size++;
               getline(myfile, line);
              }
         menu_size-=1;
        return menu_size;
    }

//this function is used add new foods in the menu file
void  Resturant::addFood(int menu_size) {  
        int num;
        Food food;
        Resturant menu;
        fstream myfile;
            myfile.open("FOOD.txt",ios::out | ios::app);
    if(myfile.is_open()){
               cout<<"enter number of food to add into menu: \n";
               cin>>num;
               for(int i=0;i<num;i++){
                     system("cls");
                    cout<<"FOOD_ID:"<<menu_size+1<<endl;
                  myfile <<(menu_size+1)<<"."<<food.getName()<< "--------------";
                  myfile << food.getPrice()<<" BIRR"<<endl;
                  menu_size++;
    }
     cout<<"the food added successfully to the menu!\n";
 getch();
}
     myfile.close();
}
   //this function is important to order food from the menu  
void Resturant::orderFood(int food_id) {
        ifstream file;
        try{
            if(food_id<=0)
              {
                throw(food_id);
              }}
        catch(int exp)
              {
                cout<<"Error: please enter the correct food_id.";
              }
        file.open("FOOD.txt",ios::in);
        try{
            if (file.fail())
              {
                throw "The menu file failed to open,try again!";
              }}
        catch(const char *exp)
              {
                cout<<exp;
              }
        int current_line=0;
        string line;
        while (!file.eof())
              {
               current_line++;
               getline(file, line);
            if(current_line == food_id) break;
               }
            if(current_line <food_id)
              {
               cout<<"The food is not found!"<<endl;
               cout<<"Food menu contains "<<current_line;
               cout<<" foods only."<<endl;
              }
              else
            cout<<line<<" is ordered successfully."<<endl;
            file.close();
        getch();
    }

//this function displays all the available foods in the menu
 void Resturant::displayMenu() {
        fstream myfile;
        myfile.open("FOOD.txt",ios::in);
        string line;
        while (!myfile.eof())
              {
                ++menu_size;
               getline(myfile, line);
              } 
        if(menu_size==0)
          {
           cout<<"Sorry there is no available food in the menu!";
           getch();
          }
        else{
        fstream myfile;
         cout << "------- MENU -------" << endl;
         cout << "FOOD NAME--------------PRICE" << endl;
          myfile.open("FOOD.txt",ios::in);
           if(myfile.is_open()){
              string line;
              while(getline(myfile,line)){
                   cout<< line <<endl;
                  }
                  getch();
                  menu_size=0;
             myfile.close();
           }
        }
    }
// this function is used to count drinks in the drink list file
    int Bar::Dcount(){
        fstream file;
        Drink drink;
        file.open("DRINK.txt",ios::in);
        string line;
        while (!file.eof())
              {
               drink_list++;
               getline(file, line);
              }
         drink_list-=1;
         return drink_list;
    }
//this function is used add new drinks in to the drink list file
void  Bar::addDrink(int drink_list) {  
        int num;
        Drink drink;
        fstream file;
      file.open("DRINK.txt",ios::out | ios::app);
      if(file.is_open()){
          cout<<"enter number of drinks to add into list: \n";
          cin>>num;
          for(int i=0;i<num;i++){
              system("cls");
              cout<<"DRINK_ID:"<<drink_list+1<<endl;
              file <<(drink_list+1)<<"."<<drink.getName()<< "--------------";
              file << drink.getPrice()<<" BIRR"<<endl;
              drink_list++;
    }
     cout<<"the drink added successfully to the list!\n";
 getch();
}
    
    file.close();
}
     
//this function is used to order drinks from the drink list
void Bar::orderDrink(int drink_id) {
        try{
            if(drink_id<=0)
              {
                throw(drink_id);
              }}
        catch(int exp)
              {
                cout<<"Error: please enter the correct drink_id.";
              }
        file.open("DRINK.txt",ios::in);
        try{
            if (file.fail())
              {
                throw "The drink list file failed to open,try again!";
              }}
        catch(const char *exp){
                cout<<exp;
              }
        int current_line=0;
        string line;
        while (!file.eof())
              {
               current_line++;
               getline(file, line);
            if(current_line == drink_id) break;
               }
            if(current_line <drink_id)
              {
               cout<<"The drink is not found!"<<endl;
               cout<<"The Drink list contains "<<current_line;
               cout<<" drinks only."<<endl;
              }
              else
            cout<<line<<" is ordered successfully."<<endl;
            file.close();
        getch();
    }

//this function displays all the available drinks in the drink list file
 void Bar::displaylist() {
        Bar list;
        list.Dcount();
        if(drink_list==0){
            cout<<"Sorry!!,there is no available drink.";
        }
        else
        {
         cout << "----- DRINK LIST ------" << endl;
         cout << "DRINK NAME--------------PRICE" << endl;
          file.open("DRINK.txt",ios::in);
           if(file.is_open()){
              string line;
              while(getline(file,line)){
                   cout<< line <<endl;
                  }
             file.close();
             drink_list=0;
           }
        }
        getch();
        }
      //Global declaration
class Room rooms[MAX];
int count=0;

//  this function used to add rooms with their information 
Room Room::addRoom(int rno){
                class Room room;
                 room.roomNumber=rno;
               come:
                system("cls");
                 try{
                cout<<"\nRoom Type \n1.VIP\n2.Couple's\n3.single's\n4.twin's \n";
                cout<<"selected your room choice: \n";
                 cin>>room.roomTypeChoice;
                  if((room.roomTypeChoice>4)||(room.roomTypeChoice)<1)
                    {
                    throw room.roomTypeChoice;
                    }
                }
                  catch(int type)
                       {
                  cout<<"Invalid choice:please enter your room type choice correctly \n";
                    getch();
                   goto come;
                       }
                cout<<"\nDaily rent : ";
                 cin>>room.rent;
                 room.status=0;
                 count++;
                cout<<"\n Room Added Successfully!";
             getch();
            return room;
}
//this function is used to search rooms with their room number

void Room::searchRoom(int rno){
           int i,found=0;
           for(i=0;i<count;i++){
              if(rooms[i].roomNumber==rno){
                found=1;
              break;
                } }
           if(found==1){
              cout<<"Room Details\n";
              if(rooms[i].status==1){
                 cout<<"\nRoom is Reserved";
                }
              else {
                  cout<<"\nRoom is available";
                   }
             availableRoom(rooms[i]);
             getch();
            }
            else {
               cout<<"\nRoom not found";
               getch();
            }
}
//this function is important to check available room
void Room::availableRoom(Room tempRoom){
                        cout<<"\nRoom Number: \t"<<tempRoom.roomNumber<<endl;
                        switch(tempRoom.roomTypeChoice)
                        {
                          case 1:
                            cout<<"Room Type: VIP.";
                            break;
                          case 2:
                            cout<<"Room Type: Couple's.";
                            break;
                          case 3:
                            cout<<"Room Type: single's.";
                            break;
                          case 4:
                            cout<<"Room Type: twin's.";
                            break;

                        }
                        cout<<"\nDaily rent :  "<<tempRoom.rent;
}
//this function used to bookin the room for the customer
void Room::bookIn(){
            class Room room;
           int i,found=0,rno,Total_rent;
           fstream rfile;
           cout<<"\nEnter Room number : "; //to check is the booked or not
           cin>>rno;
           try{
           if(rno>100 || rno <1){
                 throw rno;
                   }
                    }
               catch(int e){
            cout<<e<<" is Invalid number! The room number must be from (1-100)";
         getch();
           }
        for(i=0;i<count;i++){
              if(rooms[i].roomNumber==rno){
                found=1;
                break;
               }
               else{
                cout<<"the room is not found.\n";
                getch();
               }}
        if(found==1){
              if(rooms[i].status==1){
                 cout<<"\nRoom is already Booked";
                 getch();
            return;
                }
        rfile.open("customer.txt",ios::out | ios::app);
            if(rfile.is_open()){
               rfile<<"..............................\n";
               rfile<<"room_number:"<<rno<<endl;
              cout<<"\nEnter Customer Name : ";
               cin>>rooms[i].cust.name;
                rfile<<"Customer Name :"<<rooms[i].cust.name<<endl;
               cout<<"\nEnter Address : ";
              cin>>rooms[i].cust.address;
               rfile<<"Address :"<<rooms[i].cust.address<<endl;
                cout<<"\nEnter Phone: ";
               cin>>rooms[i].cust.phone;
              rfile<<"Phone Number :"<<rooms[i].cust.phone<<endl;
               cout<<"\nEnter From Date: ";
                cin>>rooms[i].cust.from_date;
                 rfile<<"Stay's from :"<<rooms[i].cust.from_date<<endl;
                cout<<"\nEnter to  Date: ";
               cin>>rooms[i].cust.to_date;
              rfile<<"Stay's to :"<<rooms[i].cust.to_date<<endl;
               rooms[i].status=1;
                cout<<"\n The room booked Successfully..";
               cout<<"\n...............................\n";
              rfile<<"\n..............................\n";
        getch();
            }
       }
}
// this function display's the available room
void Room::findAvailRoom(){
      int i,reserve=0;
      for(i=0;i<count;i++){
         if(rooms[i].status==0){
           availableRoom(rooms[i]);
           cout<<"\n\nPress enter for next room";
           reserve=0;
           getch();
          }
        }
      if(reserve==1){
         cout<<"\nAll rooms are reserved";
         getch();
        }
}

// this function displays the room user's list from the file
void Room::room_user_list(){
          fstream rfile;
          string line;
          rfile.open("customer.txt",ios::in );
           if(rfile.is_open()){
            while(getline(rfile,line)){
              cout<<line<<endl;
            }

}
}
//managing rooms (adding and searching available rooms)
void RoomManagement()
{
class Room room;
int choice,rno,i,found=0,num;
do
{
system("cls");
cout.setf(ios_base::right);
cout<<setfill('#');
cout<<setw(30)<<" Rooms Management "<<setw(10)<<'#'<<endl;
cout<<setw(40)<<"#"<<endl;
cout.unsetf(ios::right);

cout.setf(ios_base::left);
cout<<setfill(' ');
cout<<setw(39)<<"|  1. Add Room";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  2. Search Room";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  3. Book In Room";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<"-"<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  4. Find Available Room";
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<"-"<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  5. Display room user's information.";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  6. Back to The Main";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout<<"\nEnter Option: ";
cin>>choice;

try{
  if(choice>6 || choice <1){
    throw choice;
  }
}
catch(int a){
cout<<a<<" is Invalid choice! please enter choice from (1-6)";
getch();
}

//switch statement
switch(choice)
{
case 1:
      cout<<"\nEnter Room Number: ";
      cin>>rno;
      for(i=0;i<count;i++){
         if(rooms[i].roomNumber==rno){
           found=1;
          }
        }
      if(found==1){
        cout<<"\nRoom Number is Present.\nPlease enter unique Number";
        found=0;
        getch();
      }
      else {
            rooms[count]=room.addRoom(rno);
           }
      break;
case 2:
      cout<<"\nEnter room number: ";
      cin>>rno;
      room.searchRoom(rno);
      break;
case 3:
      if(count==0){
        cout<<"\nRooms data is not available.\nPlease add the rooms first.";
        getch();
      }
     else{
        room.bookIn(); }
     break;
case 4:
 	  if(count==0){
        cout<<"\nRooms data is not available.\nPlease add the rooms first.";
        getch();
        }
      else
        room.findAvailRoom();
        break;
case 5:
system("cls");
      cout<<".....ROOM USER'S INFORMATION.....\n";
      room.room_user_list();
      getch();
 	     break;
case 6:
 	// nothing to write here
 	     break;
default:
cout<<"\nPlease Enter correct option";
break;
}
}while(choice!=6);
}

 /* The below function gives an option to the user about food related services
and relates the option with the specific function */
    void manageResturant()
{

class Resturant food;
int choice;
string name;
int food_id;
do
{
here:
system("cls");

cout.setf(ios_base::right);
cout<<setfill('%');
cout<<setw(30)<<" Resturant Management "<<setw(10)<<'%'<<endl;
cout<<setw(40)<<"%"<<endl;
cout.unsetf(ios::right);

cout.setf(ios_base::left);
cout<<setfill(' ');
cout<<setw(39)<<"|  1. Add Food";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  2. Available Food";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  3. Order Food";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<"-"<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  4. Back to The Main";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout<<"\n Enter your option: \n";
cin>>choice;

try{
  if(choice>4 || choice <1){
    throw choice;
  }
}
catch(int f){
cout<<f<<" is Invalid choice! please enter choice from (1-4).";
getch();
}
//switch statement
switch(choice)
{
case 1:
     food.count();
     food.addFood(menu_size);
     goto here;
     break;
case 2:
   food.displayMenu();
break;
case 3:
  cout<<"\nEnter food_id of the food: ";
  cin>>food_id;
food.orderFood(food_id);
break;
case 4:
  //no thing to write for existing
  break;
default:
	cout<<"\n Invalid number, try again...";
break;
}
}while(choice!=4);

}
   void manageBar()
{

class Bar drink;
int choice;
string name;
int drink_id;
do
{
there:
system("cls");
cout.setf(ios_base::right);
cout<<setfill('$');
cout<<setw(30)<<" Bar Management "<<setw(10)<<'$'<<endl;
cout<<setw(40)<<"$"<<endl;
cout.unsetf(ios::right);

cout.setf(ios_base::left);
cout<<setfill(' ');
cout<<setw(39)<<"|  1. Add Drink";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  2. Available Drink";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  3. Order Drink";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<"-"<<endl;

cout.unsetf(ios::right);
cout<<setfill(' ');
cout<<setw(39)<<"|  4. Back to The Main";
cout.setf(ios_base::right);
cout<<'|'<<endl;
cout<<setfill('-');
cout<<setw(40)<<'-'<<endl;

cout<<"Enter your option: \n";
cin>>choice;
try{
  if(choice>4 || choice <1){
    throw choice;
  }
}
catch(int d){
cout<<d<<" is Invalid choice! please enter choice from (1-4)";
getch();
}
//switch statement
switch(choice)
{
case 1:
      drink.Dcount();
      drink.addDrink(drink_list);
       goto there;
        break;
case 2:
      drink.displaylist();
       break;
case 3:
      cout<<"\nEnter food_id of the drink: ";
       cin>>drink_id;
        drink.orderDrink(drink_id);
         break;
case 4:

  //no thing to write for existing into the menu
  break;
default:
	cout<<"\n Invalid number, try again...";
break;
}
}while(choice!=4);
}
