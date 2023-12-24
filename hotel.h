#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<conio.h>
#define MAX 100
using namespace std;
int menu_size=0;
int drink_list=0;

    class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
int booking_id;
};

class Food {
private:
    string name;
    double price;
public:
 int food_id; 
 Food food(string,double);
        string getName();
        double getPrice();
         };
class Drink {
private:
    string name;
    double price;
public:
 int drink_id; 
Drink drink(string,double);
        string getName();
        double getPrice();
         };
class Resturant {
public:
    fstream myfile;
    int count();
    void addFood(int);
    void displayMenu();
    void orderFood(int);
    };
class Bar {
public:
    fstream file;
    int Dcount();
    void addDrink(int);
    void displaylist();
    void orderDrink(int);
    void remove();
       };
class Room
{
public:
int roomTypeChoice;
int roomNumber;
int status;
float rent;
class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void bookIn();
void availableRoom(Room);
void findAvailRoom();
void room_user_list();
};

