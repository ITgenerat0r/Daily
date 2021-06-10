#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>




class Date {
public:
	Date() {};
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		month = new_month;
		day = new_day;
	}

	int GetYear() const {
		return year;
	};
	int GetMonth() const {
		return month;
	};
	int GetDay() const {
		return day;
	};


	bool Is_next_sumbol_number(std::istream& c) {
		// cout << " Is_next_sumbol_number: " << c.peek() << " " << (char)c.peek() << endl;
		if (c.peek() > 47 && c.peek() < 58 || c.peek() == 45 || c.peek() == 43) {
			return true;
		}
		return false;
	};

	bool ValidDate(const std::string& date) {
		std::stringstream ss(date);
		int day, month, year;
		if (ss && Is_next_sumbol_number(ss)) {
			ss >> year;
			if (ss && ss.peek() == 45) {
				ss.ignore(1);
				if (ss && Is_next_sumbol_number(ss)) {
					ss >> month;
					if (ss && ss.peek() == 45) {
						ss.ignore(1);
						if (ss && Is_next_sumbol_number(ss)) {
							ss >> day;
							if (ss.peek() == -1) {
								if (month < 1 || month > 12) {
									//cout << "Month value is invalid: " << month << endl;
									return false;
								}
								if (day < 1 || day > 31) {
									//cout << "Day value is invalid: " << day << endl;
									return false;
								}
								return true;
							}
						}
					}
				}
			}
		}
		//cout << "Wrong date format: " << date << endl;
		return false;
	};

	bool setDatefromString(const std::string& date) {
		if (ValidDate(date)) {
			std::stringstream ss(date);
			ss >> year;
			ss.ignore(1);
			ss >> month;
			ss.ignore(1);
			ss >> day;
			return true;
		}
		return false;
	};

	// bool operator<(const Date& date){
 //    if(GetYear()<date.GetYear()){
 //        return true;
 //    } else if (GetYear()<date.GetMonth()){
 //        return true;
 //    } else if (GetYear() < date.GetDay()){
 //        return true;
 //    }
 //    return false;
	// };

private:
	int year;
	int month;
	int day;
};



// bool operator< (const Date& lhs, const Date& rhs) {
// 	return lhs.GetYear() * 372 + lhs.GetMonth() * 31 + lhs.GetDay() < rhs.GetYear() * 372 + rhs.GetMonth() * 31 + rhs.GetDay();
// };




class Database {
public:
	void AddEvent(const Date& date, const std::string& event) {
		base[date].insert(event);
	};

	bool DeleteEvent(const Date& date, const std::string& event) {
		if (base.count(date) > 0) {
			if (base[date].count(event)) {
				base[date].erase(event);
				return true;
			}
		}
		return false;
	};

	int  DeleteDate(const Date& date) {
		if (base.count(date) > 0) {
			int r = base[date].size();
			base.erase(date);
			return r;
		}
		return 0;
	};

	void Find(const Date& date) const {
		if (base.count(date)) {
			for (const std::string& ev : base.at(date)) {
				//cout << ev << endl;
			}
		}
	};

	//void Print() const {
	//	for (const auto& k : base) {
	//		for (const string& event : k.second) {
	//			cout << k.first << " " << event << endl;
	//		}
	//	}
	//};

private:
	std::map<Date, std::set<std::string>> base;
};