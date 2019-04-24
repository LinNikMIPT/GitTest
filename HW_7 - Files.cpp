#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char ch, L, l;
	
	ifstream mystream1("Old");
	ofstream mystream2("New");

	if (!mystream1) {
		cout << "Can’t open 'Old' file" << endl;
		return	1;
	}

	if (!mystream2) {
		cout << "Can’t open 'New' file" << endl;
		return	1;
	}

	while (!mystream1.eof()) {
		mystream1.get(ch);
		if (!mystream1.eof())
			cout << ch;

		if (ch != toupper(ch))
		{
			L = toupper(ch);
			mystream2 << L;
		}
		else
		{
			l = tolower(ch);
			mystream2 << l;
		}
	} 

	mystream1.close();
	mystream2.close();

	system("pause");
	return	0;
}

//-----------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Stack {
	ofstream fout;

public:
	Stack(string s) {
		fout.open("tetx.txt");
		fout << s;
		fout.close();
	}

	~Stack() {};
};

int main() {
	string s;
	cin >> s;

	Stack MyText(s);

	system("pause");
	return	0;
}