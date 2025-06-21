#include <iostream>
#include <string>
using namespace std;

int num_of_courses;
float grade, credit_hours;
float  total_grade_points = 0.0;
float total_credit_hours = 0.0;
float old_cgpa;
float old_credits;
int semester;
float gpa, cgpa;

void data_input() {

	cout<<endl << "Enter your semester : ";
	cin >> semester;

	if (semester == 8) {
		cout << "Congratulations! You are in your final semester.\n";
		cout << "You have completed your degree.\n";
	}
	
	else if (semester == 1) {
		cout << "Enter the number of courses : ";
		cin >> num_of_courses;

		for (int i = 0; i < num_of_courses; i++) {

			cout << endl << "Emter the grade points for course " << i + 1 << " : ";
			cin >> grade;

			cout << endl << "Enter the credit hours for course " << i + 1 << ": ";
			cin >> credit_hours;

			total_grade_points += grade * credit_hours;
			total_credit_hours += credit_hours;

			cout << endl << "Total grade points = " << total_grade_points << endl;
			cout << endl << "Total credit hours = " << total_credit_hours << endl;

			cout << endl;
		}
	}

	else if (semester > 1 && semester < 8) {
		for (int i = 0;i < semester - 1;i++) {
			cout << "Enter the old CGPA : ";
			cin >> old_cgpa;
			cout << "Enter the old credits : ";
			cin >> old_credits;
		}

		cout << "Enter the current semester number of courses : ";
		cin >> num_of_courses;

		for (int i = 0; i < num_of_courses; i++) {

			cout << endl << "Emter the grade points for course " << i + 1 << " : ";
			cin >> grade;

			cout << endl << "Enter the credit hours for course " << i + 1 << ": ";
			cin >> credit_hours;

			total_grade_points += grade * credit_hours;
			total_credit_hours += credit_hours;

			cout << endl << "Total grade points = " << total_grade_points << endl;
			cout << endl << "Total credit hours = " << total_credit_hours << endl;

			cout << endl;
		}

	}
}


float cgpa_calculator() {
 
if (semester == 1) {

	cgpa = gpa = total_grade_points / total_credit_hours;
}
else if (semester > 1 && semester < 8) {
	
		cgpa = (total_grade_points + (old_cgpa * old_credits)) / (total_credit_hours + old_credits);
	
}
else if (semester == 8) {
	cout << "You have completed your degree.\n";
}
else {
	cout << "Invalid input\n";
}

cout << "Your CGPA is : " << cgpa << endl;
return cgpa;
}

int main() {
	
	while (true) {
		cout << "==========  Welcome to CGPA Calculator  ==========\n";
		data_input();
		if (semester >= 1 && semester <= 7) {
			cgpa_calculator();
		}
		else {
			cout << "Exiting the program.\n";
			break;
		}
	}
	
	return 0;
}