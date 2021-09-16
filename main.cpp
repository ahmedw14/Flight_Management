#include <iostream>
using namespace std;
#include "flight.h"
#include "main.h"

int main (){
Flight f;
displayHeader();
f.read_file("flight_info.txt");
int choice;
 while((choice = menu())){
		 switch(choice){
		 case 1:
			 f.show_seat_map();
			 CleanStandardInput();
			 pressEnter();
			 break;
		 case 2:
			 f.display();
			 CleanStandardInput();
			 pressEnter();
			 break;
		 case 3:
			 f.add_passenger();
			 CleanStandardInput();
			 pressEnter();
			 break;
		 case 4:
			 f.remove_passenger();
			 CleanStandardInput();
			 pressEnter();
			 break;
		 case 5:
			 f.save_infor("flight_info.txt");
			 CleanStandardInput();
			 pressEnter();
			 break;
		 case 6:
			 cout<< "Program Terminated";
			 exit(1);
			break;

	 }
 }

 return 0;
}
void displayHeader(){
	cout<< "Version: 1.0" <<endl;
	cout << "Term Project - Flight Mnagement Program in C++" << endl;
	cout << "Produced by: Ahmed Waly"<<endl;
	pressEnter();
	}

int menu(){
	int choice;
	cout << endl;
	cout << "Please select one of the following options: ";
	cout << "\n\n";
	cout << "1. Display Flight Seat Map." <<endl;
	cout << "2. Display Passengers Information." <<endl;
	cout << "3. Add a New Passenger."<<endl;
	cout << "4. Remove an Existing Passenger" <<endl;
	cout << "5. Save Data"<<endl;
	cout << "6. Quit"<< endl;
	cout <<"\n"<<endl;
	cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
	cin >> choice;
	while (cin.fail()){
		cin.clear();
		CleanStandardInput();
		cout << "Enter your choice: (1, 2, 3, 4, 5, or 6) ";
		cin >> choice;
	}
	return choice;
	}
void pressEnter()
{
 cout << "\n<<< Press Return to Continue>>>>\n";
 cin.get();
}
void CleanStandardInput (void)
{
 int leftover;
 do {

	leftover = cin.get();

 } while (leftover !='\n' && leftover != EOF);

}
