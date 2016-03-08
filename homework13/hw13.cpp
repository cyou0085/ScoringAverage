/*
*Carlos Young
*3/6/12
*Homework 13
*Program Description: s. Each student should be represented by a class object that has private
*members for the name and three test scores. The average score should be calculated by a member
*function. You will then need to modify the sorting algorithm so that it sorts based on the average test
*scores. Finally, your program should calculate the average of all the test score and display those results
*appropriately (see the output below). You may use either pointer or array notation when traversing the
*arrays. The program should display the sorted list of scores with appropriate headings.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"

using namespace std;

//Function
void bubbleSort(double *a,string *b,int *c, int *d, int *e, int count);
void showScores(Student *ptr,string *a,int *score1,int *score2,int *score3,double *avScores,
				double avgTest1,double avgTest2,double avgTest3,int count);
//Const Variable
const int NUMOFTEST = 3;


int main(){

	//Variable
	int size;
	double Avg1;
	double Avg2;
	double Avg3;

	//Prompt 
	cout << "How many names/test score pairs will you enter? ";
	cin >> size;

	//Dynamically Allocated Values
	Student *ptr = new Student[size];
	string  *ptName = new string[size];
	int     *ptScore1 = new int[size];
	int     *ptScore2 = new int[size];
	int     *ptScore3 = new int[size];
	double  *ptAvg =    new double[size];
	cin.ignore();

	for(int i = 0; i < size; i++){
		cout << "Enter name " << i + 1 << ": ";
		(ptr+i)->getName(ptName+i);

		cout << "Enter test score 1: ";
		(ptr+i)->getScores(ptScore1,i);

		cout << "Enter test score 2: ";
		(ptr+i)->getScores(ptScore2,i);

		cout << "Enter test score 3: ";
		(ptr+i)->getScores(ptScore3,i);
		cin.ignore();
		//Average Function stores in an Array
		*(ptAvg+i)= (ptr+i)->Average(ptScore1+i,ptScore2+i,ptScore3+i,NUMOFTEST);
	}
	
	//Find the test Average of 1,2 and 3 for everyone
	Avg1=ptr->testAverage(ptScore1,size);
	Avg2=ptr->testAverage(ptScore2,size);
	Avg3=ptr->testAverage(ptScore3,size);

	//Sort Function
	bubbleSort(ptAvg,ptName,ptScore1,ptScore2,ptScore3,size);
	cout << endl;

	//Show Grades Function
	showScores(ptr,ptName,ptScore1,ptScore2,ptScore3,ptAvg,Avg1,Avg2,Avg3,size);

	//Delete Memory
	delete [] ptr;
	delete [] ptName;
	delete [] ptScore1;
	delete [] ptScore2;
	delete [] ptScore3;
	delete [] ptAvg;

	ptr = NULL;
	ptName = NULL;
	ptScore1 = NULL;
	ptScore2 = NULL;
	ptScore3 = NULL;
	ptAvg = NULL;
	return 0;
}

//Function: bubbleSort
//take an Array of Averages and sort them in desending around. Assorts
//parrelel arrays into the new order as the order of the New Averages
void bubbleSort(double *a,string *b,int *c, int *d, int *e, int count){

	bool swap;
	do{
		swap = false;
		for(int i = 0; i < (count-1); i++){

			if(*(a+i) < *(a+1+i)){
				//Swaps All First Values into Temp
				double temp = *(a+i);
				string sTemp = *(b+i);
				int temp1 = *(c+i);
				int temp2 = *(d+i);
				int temp3 = *(e+i);

				//Puts Second Value in Arrays into the First slot
				*(a+i) = *(a+1+i);
				*(b+i) = *(b+1+i);
				*(c+i) = *(c+1+i);
				*(d+i) = *(d+1+i);
				*(e+i) = *(e+1+i);
				
				//Put the value saved in temp in the second slot
				*(a+1+i) = temp;
				*(b+1+i) = sTemp;
				*(c+1+i) = temp1;
				*(d+1+i) = temp2;
				*(e+1+i) = temp3;

				swap = true;
			}		
		}

	} while(swap == true);
}

//Function: showScores
//Prints out the name and score in desending order
void showScores(Student *ptr,string *a,int *score1,int *score2,int *score3,double *avScores,
				double avgTest1,double avgTest2,double avgTest3,int count){

		cout << "Name" << setw(27) << "Test 1" << setw(9) 
	   		 << "Test 2" << setw(9) << "Test 3" << setw(10) << "Average" << endl;
		cout <<"------------------------------------------------------------" << endl;
		cout << left;	
		for(int j = 0; j < count ; j++){
			cout << setw(25) << *(a+j) << setw(9) << *(score1+j); 
			cout << setw(9)  << *(score2+j) << setw(9) << *(score3+j);
			cout << *(avScores+j) << endl;
		}
		
		cout <<"------------------------------------------------------------" << endl;
		cout << setw(25) << "Averages" << setw(8) << avgTest1 << " " << setw(8) << avgTest2;
		cout << " " << setw(9) << avgTest3 << ptr->avgAverage(avScores,count) << endl;

}


