#ifndef LAB01_H
#define LAB01_H

#include <string>

class Lab01{

private: 
	/*We have nothing that we need to keep private for this lab.*/

public:
	/*
		Find the largest integer value in an integer array. 
		In this question, we will pass the integer array and
		an integer capacity for the array. You are to return
		the integer that has the maximum value amongst all
		values in the array. In the even that you cannot find
		the maximum value, you should return -10000.
	*/
	int question1a(int array[], int arraySize);

	/*
		Write a method that prints out only the even numbers
		in the range from A to B (exclusive), one per line.
		Note that this means that A and B must be parameters
		to your method.
	*/
	void question2(int start, int finish);

	/*
		Write code to find the smallest common multiple of two
		positive integers. The parameters for this method 
		should be the two integers. In the event that no such
		multiple exists you should return -1.
	*/
	int question3(int first, int second);

	/*
		Write a method to reverse a string. You should use C++
		style strings in order to preform this task.
	*/
	std::string question4(std::string the_string);

	/*
		Write a method that prints the numbers from 1 to 100,
		one per line. For multiples of four, instead of the
		number, print the word Fizz. Similarly, for multiples
		of seven, print the word Buzz. For numbers that are
		multiples of both four and seven, write the word
		FizzBuzz. Note that capitalization matters, reproduce
		these words exactly.
	*/
	void question5();

	/*
		Write a method that will print the grade-school
		multiplication table up to 12. Mark the upper left-hand
		entry of the table with an X and separate the 
		entries with a tab character.
	*/
	void question6();
};

#endif /* LAB01_H */
