#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 5;

template <class T> class Stack {
	T stack[N];
	int now;

public:
	Stack() {
		now = -1;
	};

	Stack(T stack_0) {
		stack[0] = stack_0;
		now = 0;
	}

	void Put_element(T stack_next) {
		try {
			stack[now + 1] = stack_next;
			now++;
		}
		catch(T stack_next) {
			cout << "Something went wrong whith putting " << stack_next << " in the stack!" << endl;
		}
	}

	void Get_element(int n) {
		if (n != now) {
			cout << "You can't take the " << n << " element cause the index of the last element is " << now << endl;
		}
		else {
			 cout << stack[n] << endl;
		}
	}

	~Stack() {};
};

int main()
{
	Stack<int> st(10);
	st.Put_element(4);
	st.Get_element(1);

	Stack<string> st2;
	st2.Put_element("first string");
	st2.Get_element(0);

	Stack<double> st3(23);
	for (int i = 0; i < 4; i++) {
		st3.Put_element(i);
	}
	st3.Get_element(4);

	system("pause");
	return 0;
}


