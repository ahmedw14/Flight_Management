#ifndef passenger
#define passenger
#include <string>
#include "seat.h"

using namespace std;
class passengers{
	private:
		string f_name;
		string l_name;
		string num;
		int id;
	public:
		seat s;
		// each vector element of passenger will contain the 
		//class object of seat
		void read_line (string line);
		// requires:
			//  a string line with proper format that contains first name,
			// last name, phone number, seat row and column, and id number
		// promises:
			// assigns the proper information to id, num, f_name, and l_name
		const string get_f_name ();
		// promises:
			// returns the first name for a specific passenger element 
		const string get_l_name ();
		// promises:
			// returns the last name for a specific passenger element 
		const string get_num ();
		// promises:
			// returns the phone number for a specific passenger element 
		const int get_seat_row ();
		// promises:
			// returns the seat row for a specific passenger element 
		const char get_seat_col();
		// promises:
			// returns the seat column for a specific passenger element 
		const int get_id ();
		// promises:
			// returns the id for a specific passenger element 
		void set_f_name (string user_fname);
		//promises:
			// set the first name f_name of the passenger of a certain 
			//vector element to user_fname
		void set_l_name (string user_lname);
		//promises:
			// set the last name l_name of the passenger of a certain 
			//vector element to user_lname
		void set_num (string user_num);
		//promises:
			// set the phone number num of the passenger of a certain 
			//vector element to user_num
			// also inserts dashes at element 3 and element 7
		void set_id(int x);
		//promises:
			// set the id number of the passenger of a certain 
			//vector element to x
		void set_seat_col(char c);
		//promises:
			// set the id number of the passenger of a certain 
			//vector element to x
		void set_seat_row(int r);
		//promises:
			// sets the row of the passenger to r
};
#endif
