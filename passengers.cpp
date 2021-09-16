#include <string>
#include "Flight.h"
#include <vector>
#include "passengers.h"

#include <iostream>
using namespace std;

void passengers::read_line(string x){	
	f_name = x.substr(0,20);
	l_name = x.substr (20,20);
	num = x.substr (40,20);
	int passenger_row =0;
	char passenger_column;
	
	string passenger_seat = x.substr(60,4);
	for (int i=0; i<int(passenger_seat.length());i++)
		if (passenger_seat[i] >= '0' && passenger_seat[i] <= '9')
			passenger_row = passenger_row*10 + (passenger_seat[i] - '0');
		else if ((passenger_seat[i] >= 'a' && passenger_seat[i] <= 'z') ||(passenger_seat[i] >= 'A' && passenger_seat[i] <= 'Z')){
			passenger_column = passenger_seat[i];
			break;
		}
	s.set_row(passenger_row);
	s.set_column(passenger_column);
	string i = x.substr (64,10);
	id =stoi (i);
	}


const string passengers::get_f_name(){return f_name;}
const string passengers::get_l_name(){return l_name;}
const string passengers::get_num(){return num;}
const int passengers::get_seat_row(){return s.get_row();}
const char passengers:: get_seat_col(){return s.get_col();}
void passengers::set_seat_row(int r){
	s.set_row(r);}
void passengers:: set_seat_col(char c){s.set_column(c);}

const int passengers::get_id(){return id;}

void passengers::set_f_name(string user_fname){f_name = user_fname.substr(0,20);}

void passengers::set_l_name(string user_lname){l_name = user_lname.substr(0,20);}

void passengers::set_num(string user_num){
	num = user_num.substr(0,20);
	num[3] = '-';
	num[7] = '-';}

void passengers::set_id(int x){id=x;}

