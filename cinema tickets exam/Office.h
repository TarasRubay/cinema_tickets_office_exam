#pragma once
#include "cinema_hall.h"
#include "includet.h"
#include "viewer.h"
#include "regular_viewer.h"
#include "TimeTable.h"
#include "film.h"
class Office
{ 
	TimeTable Table;
public:
	void Emloyee(istream& in,ostream& out);
	void RegularV(istream& in, ostream& out);
	void Viever(istream& in, ostream& out);
};

 