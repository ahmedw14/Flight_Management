#ifndef flight_seat
#define flight_seat
#include <iostream>			
class seat{
		private:
			int row;
			char column;
		public:
			void set_column (char c);
			// promises:
				// sets the column to c for a specified passenger
			void set_row (int r);
			// promises:
				// sets the row to r for a specified passenger
			const int get_row ();
			// promises:
				// returns the seat row for a specified passenger
			const char get_col();
			// promises:
				// returns the seat column for a specified passenger
		};
#endif
