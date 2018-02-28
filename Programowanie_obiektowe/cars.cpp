/*
	Baza danych przechowuj¹ca dane samochodów w tablicy dynamicznej

	Zgodnie z zaleceniami nie u¿ywam wejœcia od u¿ytkownika z wyj¹tkiem prostego menu
	Reszta mo¿e zostaæ zaimplementowana jako np. interfejs graficzny

	Nie ma odczytu i wczytywania do pliku, robienie tego w standardowej bibliotece
	jest drog¹ przez mêkê i nigdy mi nie dzia³a

	Szymon Cichy 235093
	27/02/2018 Wroclaw
*/



#include <iostream>
#include <string>
#include <vector>

const size_t MAX_SIZE = 20;
using std::ostream;	using std::istream;
using std::vector;

struct car {
	std::string model;
	int year;
	std::string color;
	// in km
	double mileage;
};


bool valid_year(int year);
bool position_empty(car car);
void fill_database(vector<car> * table);
car example_car();
void print_table(vector<car>* table);
void menu(vector <car> * table);
//TODO file io
ostream& operator<< (ostream& os, const car& per) {
	os << per.color << ';';
	os << per.mileage << ';';
	os << per.model << ';';
	os << per.year << '%' << std::endl;
	return os;
}

istream& operator>> (istream& is, car& per) {
	is >> per.color;
	is >> per.mileage;
	is >> per.model;
	is >> per.year;
	return is;
}



int nmain() {
	vector <car> database;
	fill_database(&database);

	menu(&database);
	
	return 0;
}

bool valid_year(int year) {
	//TODO current year
	if (year >= 1886 && year <= 2018) return true;
	else return false;
}
bool position_empty(car car) {
	if (car.color.empty() && car.model.empty() &&
		!valid_year(car.year) && car.mileage <= 0 && car.mileage == NULL)
		return true;
	else return false;
}



void fill_database(vector <car> * table) {
	car temp_car;
	for (size_t i = 0; i < MAX_SIZE; i++) {
		temp_car.model = "model " + std::to_string(i);
		temp_car.year = 1950 + i;
		temp_car.color = "color " + std::to_string(i);
		temp_car.mileage = 100000.0 + (double)i * 123;
		table->push_back(temp_car);
		
	}
}




car example_car() {
	car example_car;
	example_car.mileage = 200000.0;
	example_car.model = "Example Model";
	example_car.year = 1999;
	example_car.color = "Red";
	return example_car;
}

void print_table(vector<car> * table) {
	vector<car>::const_iterator it;
	for (it = table->begin(); it != table->end(); it++) {
		std::cout << "Model: " << it->model << std::endl
			<< "Year: " << it->year << std::endl
			<< "Color: " << it->color << std::endl
			<< "Mileage: " << it->mileage << std::endl << std::endl;
	}
}

void menu(vector<car> * database) {
	int choice = -1;
	int index;

	car carone = example_car();
	//TODO what is new car? User input, GUI, whatever
	car newcar;
	vector<car>::const_iterator c_it;

	std::cout << "Menu\
		\n1. New car\
		\n2. Delete car\
		\n3. Print database\
		\n4. Save\
		\n5. Open file\n";
	while (std::cin >> choice) {
		switch (choice)
		{
		case 1: index = choice;
			database->push_back(newcar);
			break;
		case 2: index = choice;
			c_it = database->begin();
			database->erase(c_it+index);
			break;
		case 3: print_table(database); 
			break;
		case 4: 
			//TODO make me
			break;
		case 5: 
			//TODO make me
			break;
		default:
			break;
		}
	}
}