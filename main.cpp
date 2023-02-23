#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
void chezar(map<string, int> first, map<int, string> second, int k, vector<string> str, int num) {
	for (int i = 0; i < num; i++) {
		int n = first[str[i]] + k;
		while (n > 32) { n -= 32; }
		cout << second[n];
	}
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	string alphabet[] = { "�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�","�" };
	map<string, int> first;
	map<int, string> second;
	for (int i = 0; i < 33; i++) {
		first[alphabet[i]] = i;
		second[i] = alphabet[i];
	}
	vector<string> name= { "�","�","�","�","�" };
	vector<string> surname = { "�","�","�","�","�","�","�","�" };
	vector<string> patronymic = { "�","�","�","�","�","�","�","�","�","�","�","�" };
	int k1 = 13;
	int k2 = 6;
	int k3 = 28;
	int num1 = 5;
	int num2 = 8;
	int num3 = 12;
	chezar(first, second, k1, name, num1);
	chezar(first, second, k2, surname, num2);
	chezar(first, second, k3, patronymic, num3);
}