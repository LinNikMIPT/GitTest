#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


template <class T> class DataStruct {

public:
	DataStruct() {}

	virtual void showFigureType() {};

	~DataStruct() {};
};

template <class T> class Stack: public DataStruct <T> {
	vector <T> s;

public:
	Stack() {};

	void push(T x) {
		s.push_back(x);
	}

	void pop() {
		s.pop_back();
	}

	T peek() {
		return s[s.size() - 1];
	}

	~Stack() {};
};

template <class T> class Queue : public DataStruct <T> {
	vector <T> q;

public:
	Queue() {};

	void enqueue(T x) {
		q.push_back(x);
	};

	void dequeue() {
		q.pop_back();
	}

	~Queue() {};
};

DataStruct <double> *DataStructFactory(char s) {
	if (s == 's'){
		return new Stack<double>;
	}

	if (s == 'q') {
		return new Queue<double>;
	}
}


int main() {
	char s;

	cin >> s;
	DataStruct <double> *f = DataStructFactory(s);

	cout << typeid(*f).name() << endl;

	system("pause");
	return	0;
}