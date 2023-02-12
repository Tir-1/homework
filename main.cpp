#include <iostream>
#include <iterator> 
#include <map>
using namespace std;
int question(){
	cout << "Available functions" << endl;
	cout << "Press 0 to find out the number of residents of the house" << endl;
	cout << "Press 1 to add a new home" << endl;
	cout << "Press 2 to delete the house" << endl;
	int answer;
	cin >> answer;
	return answer;
}
void answer(map<int, int> houses, int n) {
	int logic = question();
	if (logic == 0) {
		cout << "Enter the house number" << endl;
		int num;
		cin >> num;
		if (num > 0 and num < n + 1) {
			cout << "In this house lives " << houses[num] << " people." << endl;
		}
		else {
			cout << "Incorrect input" << endl;
		}
	}
	if (logic == 1) {
		cout << "How many people live in this house?" << endl;
		int a; cin >> a;
		n += 1;
		houses[n] = a;
		cout << "OK" << endl;
	}
	if (logic == 2) {
		cout << "Enter the house number you want to delete" << endl;
		int b; cin >> b;
		if (b > 0 and b < n + 1) {
			map<int, int>::iterator iter;
			iter = houses.find(b);
			houses.erase(iter);
			if (b != n) {
				for (int i = b + 1; i < n + 1; ++i) {
					int peoples = houses[i];
					iter = houses.find(i);
					houses.erase(iter);
					houses[i - 1] = peoples;
				}
			}
			n -= 1;
			cout << "The object has been deleted. Numbering changed" << endl;
				}
		else {
			cout << "Incorrect input";
		}
	}
	answer(houses, n);
}

int main() {
	map<int, int> houses;
	int n;
	cout << "How many houses are there on the street?" << endl;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << "How many people live in house number " << i + 1 << "?" << endl;
		int k;
		cin >> k;
		houses[i + 1] = k;
	}
	answer(houses, n);
}