#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class Map_cl {
	map <string, string> mp;

public:
	Map_cl() {};

	void insert(string key, string vol) {
		mp[key] = vol;
	}

	void delete_(string s) {
		map <string, string> :: iterator full_name;
		full_name = mp.find(s); 
		mp.erase(full_name);           
	}

	~Map_cl() {};
};

class ProxiedMap {
	string access;
	Map_cl m;

public:
	ProxiedMap(string s) {
		access = s;
	};

	void insert(string key, string vol, string ac) {
		if (ac == "IDR" || ac == "ID" || ac == "IR" || ac == "I") {
			m.insert(key, vol);
		}
		else {
			cout << "Access denied" << endl;
		}
	}

	void delete_(string s, string ac) {
		if (ac == "IDR" || ac == "ID" || ac == "DR" || ac == "D") {
			m.delete_(s);
		}
		else {
			cout << "Access denied" << endl;
		}
	}

	void read(string ac) {
		if (ac == "IDR" || ac == "IR" || ac == "DR" || ac == "R") {
			m.read();
		}
		else {
			cout << "Access denied" << endl;
		}
	}

	~ProxiedMap() {};
};


int main() {
	string ac;
	string s1, s2, s3;

	cout << "Enter access code " << endl;
	cin >> ac;

	ProxiedMap PrMa(ac);
	cout << "Enter key and vol " << endl;
	cin >> s1 >> s2;
	PrMa.insert(s1, s2, ac);

	cout << "Enter element you want to delete " << endl;
	cin >> s3;
	PrMa.delete_(s3, ac);

	system("pause");
	return	0;
}