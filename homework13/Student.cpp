#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

//Constructor
Student::Student(){

}

//member function: getname
//get the Name from user input and stores value in a pointer
string Student::getName(string *pointer){
	getline(cin,name);
	*pointer = name;
	return name;
}
//member function: getScores
//Allows user to enter in score and sotres the value you in
//an array of pointers
void Student::getScores(int *test,int curr){
	cin >> scores[curr];
	*(test+curr) = scores[curr];
}



//member function:Average
//calulates each students average and returns it to the function
double Student::Average(int *a,int *b,int *c, int count){

	double sum = *a + *b + *c;

	cout << fixed << showpoint << setprecision(2);
	double total = sum / count;

	return total;
}

//Member Function:testAverage
//Takes the scores of each test and calulates the average
double Student::testAverage(int *a,int count){
	int sum = 0;
	for(int i = 0; i < count; i++){
		sum += *a;
		a++;
	}

	cout << fixed << showpoint << setprecision(2);
	double total = static_cast<double>(sum) / count;

	return total;
}

//Member Function: avgAverage
//Takes the average of all the averages to calculate
//total average and returns it to the function
double Student::avgAverage(double *a,int count){
	double sum = 0;
	for(int i = 0;i < count; i++){
		sum += *a;
	}

	double total=sum/count;
	return total;
}




