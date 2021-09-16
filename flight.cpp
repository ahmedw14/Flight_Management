#include <string>
#include "Flight.h"
#include "main.h"
#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

void Flight::read_file (const char *f){
	ifstream in_file;
	in_file.open (f);
	
	if (in_file.fail()){
		cout << "Error, Cannot open file" << endl;
		exit(1);
	}
	in_file>> flight_name>> t_rows>> t_columns;
	string line;
	int i=0;
	while (getline (in_file,line)){
		p.resize(i);
		
		if (i>0)
			p.at(i-1).read_line(line);
		i++;	
	}
	in_file.close();
}




void Flight::add_passenger(){
	p.resize(p.size()+1);
	int size =p.size();
	int i =0;
	int user_ID=0;
	cout << "Please enter the passenger ID: ";
	cin >> user_ID;
	while (cin.fail()){
		cout << "Please enter a valid ID number (no more than 10 numbers): ";
		cin.clear();
		CleanStandardInput();
		cin >> user_ID;
	}
	while ( i<size){
		if (user_ID==p.at(i).get_id()){
			cout << "This ID is already being used please insert a different ID: ";
			cin.clear();
			CleanStandardInput();
			cin >>user_ID;
		if (cin.fail()){
			cout << "Please enter a valid ID number (no more than 10 characters): ";
			cin.clear();
			CleanStandardInput();
			cin >>user_ID;
				}
			i=0;
			continue;
			}
		i++;	
	}

	p.at(size-1).set_id (user_ID);
	CleanStandardInput();
	string user_fname;
    cout << "Please enter your first name:"; 
    getline(cin, user_fname);
	i=0;
	int fn_size = user_fname.length();
	while ( i<fn_size){
		if (!((user_fname[i] >= 'A' && user_fname[i] <= 'Z') || (user_fname[i] >= 'a'
		&& user_fname[i] <= 'z' )|| user_fname[i] == '-' ||user_fname[i] == ' '))
		{
			cout << "Please enter a valid first name: ";
			getline(cin,user_fname);
			fn_size = user_fname.length();
			i=0;
			continue;
			}
		i++;	
		}

	p.at(size-1).set_f_name(user_fname);

	string user_lname;
    cout << "Please enter your last name:"; 
    getline(cin, user_lname);
	i=0;
	int ln_size = user_lname.length();
	while ( i<ln_size){
		if (!((user_lname[i] >= 'A' && user_lname[i] <= 'Z') || (user_lname[i] >= 'a'
		&& user_lname[i] <= 'z' )|| user_lname[i] == '-' ||user_lname[i] == ' '))
		{
			cout << "Please enter a valid last name: ";
			getline(cin,user_lname);
			ln_size = user_lname.length();
			i=0;
			continue;
			}
		i++;	
		}
	p.at(size-1).set_l_name(user_lname);
	

	string user_num;
	cout << "Please enter the passenger phone number (XXX XXX XXXX): ";
	getline (cin, user_num);
	i=0;
	int num_size = user_num.length();
	while (i<num_size){
		if ( !(isdigit(user_num[0])) || !(isdigit(user_num[1]))|| !(isdigit(user_num[2]))
		|| user_num[3] != ' ' || !(isdigit(user_num[4]))|| !(isdigit(user_num[5]))||
		!(isdigit(user_num[6]))|| user_num[7] != ' '||!(isdigit(user_num[8]))||!(isdigit(user_num[9])) 
		||!(isdigit(user_num[10]))||!(isdigit(user_num[11])) || num_size != 12 ){
			cout << "Please enter a valid number (XXX XXX XXXX): ";
			getline(cin,user_num);
			num_size = user_num.length();
			i=0;
			continue;
			}
		i++;
	}
	
	i=0;
	p.at(size-1).set_num(user_num);
	string user_row;
	cout << "Please enter the passenger's desired row (from 1 to " <<t_rows<< "):";
	cin >> user_row;
	
	while (i<int(user_row.length())){
		if ( !((user_row[i] >= '0' && user_row[i] <= '9') ) || (int(stoi(user_row)) <1 || int(stoi(user_row))>(t_rows) )){
			cout <<"Please enter a valid row:";
			cin >> user_row;
			i=0;
			continue;
		}
	i++;
}

int u_row = stoi(user_row);
i=0;
string user_column;
char a = 'A';
cout << "Please enter the passenger's desired column from A to " <<char(a+t_columns-1)<<" (use Capital letters):";
	cin >> user_column;
	while (i<int(user_column.length())){
		if ( !((user_column[i] >= 'A' && user_column[i] <= 'Z'))  || int(user_column.length())!=1 || user_column[i]-64 > t_columns){
			cout <<"Please enter a valid column (use Capital letters):";
			cin >> user_column;
			i=0;
			continue;
		}
	i++;
}
char c = user_column[0];
i=0;
int j=0;
while (j<int (p.size())){
	if (char(user_column[0])==p.at(j).get_seat_col() && int (stoi(user_row)) == p.at(j).get_seat_row()){
		cout<<"sorry this seat is already taken" << endl;
		cout <<"Please enter a valid row:";
		cin >> user_row;
			while (i<int(user_row.length())){
				if ( !((user_row[i] >= '0' && user_row[i] <= '9') ) || (int(stoi(user_row)) <1 || int(stoi(user_row))>(t_rows) )){
						cout <<"Please enter a valid row:";
						cin >> user_row;
						i=0;
						continue;
					}
				i++;
			}
		
			i=0;
		
		
			cout << "Please enter the passenger's desired column from A to " <<char(a+t_columns-1)<<" (use Capital letters):";
			cin >> user_column;
			while (i<int(user_column.length())){
				if ( !((user_column[i] >= 'A' && user_column[i] <= 'Z'))  || int(user_column.length())!=1 || user_column[i]-64 > t_columns){
					cout <<"Please enter a valid column (use Capital letters):";
					cin >> user_column;
					i=0;
					continue;
				}
			i++;
		}
	j=0;
	continue;
	}
	j++;
}
u_row = stoi(user_row);
c = user_column[0];
p.at(size-1).set_seat_row(u_row);
p.at(size-1).set_seat_col(c);
}




void Flight::save_infor (const char *f){
	ofstream out_file;
	out_file.open (f,ofstream::out | ofstream::trunc);
	if (out_file.fail()){
		cout<< "Could not find File to save information";
		exit(1);
	}
	out_file << flight_name << setw(5) << t_rows << setw(5) <<t_columns <<endl;
	for (int i=0; i<int (p.size());i++){
	string s = to_string(p.at(i).get_seat_row());
	s.push_back(p.at(i).get_seat_col());
	out_file<<left<<setw(20)<<p.at(i).get_f_name()<<setw(20)<< p.at(i).get_l_name()<<setw(20)<<p.at(i).get_num()<<setw(4)<<s<<
	setw(10)<<p.at(i).get_id() << endl;
}
	out_file.close();
}
	
void Flight::display (){	
cout <<"\n"<<left<<setw(20) <<"First Name"<<setw(20)<<"Last Name"<<setw(20)<<"Phone"<<setw(10)
<<"Row" <<setw(10) <<"Seat"<< setw(10)<<"ID";
cout <<"\n------------------------------------------------------------------------------------" <<endl;
for (int i=0; i<int (p.size());i++){
	cout<<setw(20)<<p.at(i).get_f_name()<<setw(20) << p.at(i).get_l_name()<<setw(20)<<p.at(i).get_num()<<setw(12)<<p.at(i).get_seat_row()<<setw(7)<<p.at(i).get_seat_col()<<
	setw(10)<<p.at(i).get_id();
	cout <<"\n------------------------------------------------------------------------------------" <<endl;
	}
}

void Flight::remove_passenger(){
	int remove;
	cout << "Please enter the ID of the passenger that needs to be removed:";
	cin >> remove;
	while (cin.fail()){
		cout << "Please enter a valid ID number of the passenger needed to be removed(no more than 10 numbers): ";
		cin.clear();
		CleanStandardInput();
		cin >> remove;
	}
	int size = p.size();
	int j=0;
	while (j<int (p.size())){
		if (p.at(j).get_id() == remove){
			p.erase (p.begin() +j);
			p.shrink_to_fit();
			break;
		}
		j++;
	}
	if (int (p.size()) == size)
		cout << "Passenger not found" << endl;
	else
		cout << "Passenger has been removed!" <<endl;
}

void Flight::show_seat_map(){
	int row_numbers=1;

	map m;
	int x=0;
	m.resize(t_rows*2 +1);
	for (int i =0; i<t_rows*2 +1;i++)
		m[i].resize(t_columns+1);
		
	for( int i= 0 ; i< int (m.size()) ; i++ ){
		for(int j = 0 ; j < t_columns+1 ; j++ ){
			x=0;
				if (i%2==0){
					if (j+1 == t_columns)
						m.at(i).at(j) = "+---+";
					else if(j<t_columns)
					m.at(i).at(j) = "+---";
					
				}else{
					for (x=0; x< int(p.size())-1; x++){
						if (p.at(x).get_seat_col() -64 == j && p.at(x).get_seat_row()*2 == i+1)
							break;
						}
					if (j+1 == t_columns)
						m.at(i).at(j) = "|   |";
					else if (j<t_columns)
						m.at(i).at(j) = "|   ";
					
					 if (p.at(x).get_seat_col() -64 == j && p.at(x).get_seat_row()*2 == i+1 && j==t_columns)
						m.at(i).at(j-1) = "| X |";
					 if (p.at(x).get_seat_col() -64 == j && p.at(x).get_seat_row()*2 == i+1 && j<t_columns)
						m.at(i).at(j-1) = "| X ";
				}
			}
	}
	cout << "Aircraft Seat Map" <<endl;
	char row_characters = 'A';
	int c =t_columns;
	cout<<right<<"     ";
		while (c--)
			cout<<setw(4)<<row_characters++;
	cout<<endl;
	for( int i= 0 ; i< int(m.size()) ; i++ ){
		if (row_numbers<t_rows+1 && i%2==1){
			cout <<setw(3)<<row_numbers++;
			cout <<setw(7);
			}
		if (i%2 ==0)
			cout<<setw(10);
		for( int j = 0 ; j < int (m.at(i).size() ); j++ ){
			cout <<m.at(i).at(j);
		}
		cout<<endl;
	}

	cout<<endl;
}
