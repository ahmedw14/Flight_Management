#include "seat.h"
void seat::set_column (char c){column=c;}

void seat::set_row (int r){row=r;}

const int seat::get_row() {return row;}

const char seat::get_col() {return column;}
