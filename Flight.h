#ifndef final_project
#define final_project
#include <string>
#include <vector>
#include <iostream>
#include "seat.h"
#include "passengers.h"
using namespace std;
typedef vector <vector<string>> map;
class Flight{	
	private:
	string flight_name;
	int t_rows;
	int t_columns;
	
	public:
	vector <passengers> p;
	void read_file (const char* p);
	// Requires:
		// For the char to be pointing at a proper file that has a
		// proper format
	//Promises:
		// To store flight name in flight_name, 
		//total rows in t_rows, 
		//and total columns in t_columns
		//also passes each line in the file to read_line
	void add_passenger ();
	// Requires (from user input):
		// an unused id number (less than 10 numbers)
		// if characters are inserted after the ID, the buffer will only
		// take in the ID entered and ignore the characters
		// but if characters are inserted first, ID will be invalid
		// a proper formated phone number (format provided)
		// no characters outside the english for first and last name
		// alphabet (dashes and spaces are allowed)
		// for the names any amount of characters are accepted, but only 
		// the first 20 characters will be accepted and displayed
		// an available seat in the aircraft
		// any invalid input, user will be asked to re-enter input
	//Promises:
		// append the passenger vector and store all required information
		// in the proper spot
		// This function is also responsible for getting valid information 
		// from the user input and passing it on to the setters of class seat
		// and class passenger
	void remove_passenger();
	// requires:
		// an ID that was used
	// promises:
		// Remove the passenger information and shrink the vector size
		// if characters are inserted after the id, the buffer will only
		// take in the ID entered and ignore the characters
		// but if characters are inserted first, ID will be invalid, and 
		// user will be asked to insert another ID 
	void display ();
	// promises:
		// display all the passenger information in a proper formated table
		// by using the getter functions for class seat and passengers
	void show_seat_map();
	//Promises:
		// prints out the seat map of the aircraft
		// the spots that are taken by passengers are marked with an X
	void save_infor(const char* f);
	// Requires:
		// For the char to be pointing at a proper file
	//Promises:
		// to save the information to the file provided in proper format
};
#endif
