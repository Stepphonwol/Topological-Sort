#include "Bulletin.h"

void Bulletin::arrange()
{
	for (int i = 0; i < courses.size(); ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl;
	/*cout << "Semester 1 : " << endl;
	for (int i = 0; i < 4; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 2: " << endl;
	for (int i = 6; i < 10; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 3: " << endl;
	for (int i = 10; i < 16; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 4: " << endl;
	for (int i = 16; i < 22; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 5: " << endl;
	for (int i = 22; i < 23; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 6: " << endl;
	for (int i = 23; i < 25; ++i) {
		cout << courses[i]->name << "|";
	}
	cout << endl << "Semester 7: " << endl;
	for (int i = 25; i < 27; ++i) {
		cout << courses[i]->name << "|";
	}*/
}