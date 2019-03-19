#include <iostream>
#include <string>

using namespace std;

class Person {
	int age;
	string name;
	
public:
	Person() {};

	Person(int age_, string name_) {
		age = age_;
		name = name_;
	}

	int Get_age() {
		return age;
	};

	string Get_name() {
		return name;
	};
	
	~Person() {};
};

class Sport {
	string spotr_name;

public:
	Sport() {};

	Sport(string sn) {
		spotr_name = sn;
	}

	string Get_sport_name() {
		return spotr_name;
	};

	~Sport() {};

};

class Student: public Person, public Sport {
	double aver_mark; // The average student's mark

public:
	Student(): Person(), Sport() {};

	Student(int age, string name, string sport, double am): Person(age, name), Sport(sport) {
		aver_mark = am;
	}

	double Get_aver_mark() {
		return aver_mark;
	};

	~Student() {};
};

class Professor: public Person, public Sport {
	int num_publ; // The number of professor's publications

public:
	Professor(): Person(), Sport() {};

	Professor(int age, string name, string sport, int nb): Person(age, name), Sport(sport) {
		num_publ = nb; 
	};

	int Get_num_publ() {
		return num_publ;
	};

	~Professor() {};
};

int main() {
	Student fiztech(19, "Nikita", "volleyball", 4.3);
	Professor prf(53, "Kloss", "golf", 100);

	cout << "Student:" << endl;
	cout << fiztech.Get_age() << endl;
	cout << fiztech.Get_name() << endl;
	cout << fiztech.Get_sport_name() << endl;
	cout << fiztech.Get_aver_mark() << endl;
	cout << endl;

	cout << "Professor:" << endl;
	cout << prf.Get_age() << endl;
	cout << prf.Get_name() << endl;
	cout << prf.Get_sport_name() << endl;
	cout << prf.Get_num_publ() << endl;

	system("pause");
	return 0;
}