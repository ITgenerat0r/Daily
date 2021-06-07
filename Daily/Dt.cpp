
#include "Dt.h"



bool operator< (const Date& lhs, const Date& rhs) {
	return lhs.GetYear() * 372 + lhs.GetMonth() * 31 + lhs.GetDay() < rhs.GetYear() * 372 + rhs.GetMonth() * 31 + rhs.GetDay();
};


// bool operator<(const Date& lhs, const Date& rhs){
// 	if(lhs.GetYear()<rhs.GetYear()){
// 		return true;
// 	} else if (lhs.GetMonth()<rhs.GetMonth()){
// 		return true;
// 	} else if (lhs.GetDay() < rhs.GetDay()){
// 		return true;
// 	}
// 	return false;
// };


//ostream& operator<<(ostream& stream, const Date& date) {
//	stream << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2) << setfill('0') << date.GetMonth() << '-' << setw(2) << setfill('0') << date.GetDay();
//	return stream;
//}


