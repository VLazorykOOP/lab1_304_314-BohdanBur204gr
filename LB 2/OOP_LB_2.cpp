#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "string"
#include <fstream>
#include <time.h>

using namespace std;

//----------------------------------------------task 1
int multiplay(int a, int b) {
	bool negativeN = false;
	if ((a >> 31) ^ (b >> 31)) negativeN = true;
	a = ((a >> 31) & 1) ? ~a + 1 : a;
	b = ((b >> 31) & 1) ? ~b + 1 : b;
	int res = 0;
	while (b | 0) {
		(b & 1) ? res += a: 0;
		a <<= 1;
		b >>= 1;
	}
	return negativeN ? ~res : res;
}

int divide(int a, int b) {
	if ((a == 0) || (b == 0)) return 0;
	bool negativeN = false;
	if ((a >> 31) ^ (b >> 31)) negativeN = true;
	a = ((a >> 31) & 1) ? ~a + 1 : a;
	b = ((b >> 31) & 1) ? ~b + 1 : b;
	int res = 0;
	while (a >= b) {
		res += 1;
		a += ~b + 1;
	}
	return negativeN ? ~res + 1 : res;
}

void task1() {
	cout << "Task 1" << endl;
	int n[4];
	cout << "Input a,b,c and d: ";
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	cout << "a = " << n[0] 
		<< " ,b = " << n[1] 
		<< " ,c = " << n[2] 
		<< " ,d = " << n[3] 
		<< endl;
	int fraction = divide( multiplay(17, n[0]) +  multiplay(312, n[2]) , 32);
	int res = fraction - (multiplay(n[1], 120) + multiplay(n[3], 127));
	cout << "Result this expression\n\n(17 * " << n[0] << " + 312 * " << n[2] << " / 32) - " << n[1] << " * 120 + " << n[3] << " * 127 = " << res << endl;
}

//----------------------------------------------task 2
void task2() {
	const int sizeS = 2;
	cout << "Task 2-3\n";
	class encodeDataLine {
	public:
		unsigned short nl : 3; // number line
		unsigned short ps : 3; // position symbol in line
		unsigned short bp : 1; // bit pair first line
		unsigned short nac: 8; // ascii code symbol
		unsigned short bpl: 1; // bit pair last line
	};

	encodeDataLine e[8][8];

	string line;

	ifstream file("r.dat", ios::out | ios::binary | ios::app);
	ofstream fileW("w.dat");

	if (file.is_open()) {
		short n = 0;
		cout << "Reading and encode data from file 'r.dat' and write in file 'w.dat'\n-------------------------------------\n";
		fileW << "Encode data\n-------------------------------------\n";
		while (getline(file, line)) {
			if (line.size() < 8) {
				for (int i = line.size() - 1; i < 7; i++) {
					line += ' ';
				}
			}
			for (int i = 0; i < 8; i++) {
				short temp = int(line[i]);
				short pair = i+1 % 2 ? 1 : 0;
				cout << char(temp ^ ~(i+1 << n >> pair));
				e[n][i].nl = n;
				e[n][i].ps = i;
				e[n][i].bp = pair;
				e[n][i].nac = temp ^ (i + 1 << n >> pair);
				e[n][i].bpl = !pair ? 1 : 0;
				fileW << char(e[n][i].nac);
			}
			fileW << endl;
			n++;
			cout << endl;
		}
	}
	cout << endl << "Decode data\n-------------------------------------\n";

	for (int n = 0; n < 8; n++) {
		for (int i = 0; i < 8; i++) {
			cout << char(e[n][i].nac ^ (e[n][i].ps + 1 << e[n][i].nl >> e[n][i].bp));
		}
		cout << endl;
	}

	fileW.close();
	file.close();
}

//----------------------------------------------task 4
void task4() {
	cout << "Task 4\n";
	short mask = 00110000;

	string line;

	ifstream file("r.dat", ios::out | ios::binary | ios::app);
	ofstream fileW("w2.dat");

	if (file.is_open()) {
		short n = 0;
		cout << "Reading and encode data from file 'r.dat' and write in file 'w2.dat'\n-------------------------------------\n";
		fileW << "Encode data\n-------------------------------------\n";
		while (getline(file, line)) {
			for (int i = 0; i < line.size(); i++) {
				short temp = int(line[i]);
				cout << char(temp ^ ~mask);
				fileW << char(temp ^ ~mask);
			}
			cout << endl;
			fileW << endl;
		}
	}


	fileW.close();
	file.close();
}

char task;
int switcher() {
	cout << "input nuber task from 1 to 4 (or 'q' for exit from app): ";
	cin >> task;
	switch (task)
	{
	case '1':
		system("cls");
		task1();
		break;
	case '2':
		system("cls");
		task2();
		break;
	case '3':
		system("cls");
		task2();
		break;
	case '4':
		system("cls");
		task4();
		break;
	default:
		return -1;
		break;
	}
}

int main()
{
    while (true) {
		if (switcher() == -1) break;
    }

}
