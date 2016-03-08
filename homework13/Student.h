//Student Class
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
	private:
		string name;
		int scores[3];

	public:
	Student();
	double Average(int *a,int *b,int *c, int count);
	double testAverage(int *a,int count);
	double avgAverage(double *a,int count);
	string getName(string *pointer);
	void Student::getScores(int *test,int curr);
	void showScores(Student *ptr,string *a,int *score1,int *score2,int *score3,double *avScores,
					double avgTest1,double avgTest2,double avgTest3,int count);

};
#endif
