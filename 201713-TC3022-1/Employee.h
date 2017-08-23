#pragma once
#include <string>

class Employee
{


private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;


public:
	Employee(int _id, std::string _firstName, std::string _lastName, int _salary);
	int GetID();
	std::string GetLastName();
	std::string GetFirstName();
	std::string GetName();
	int GetSalary();
	void SetSalary(int salary);
	int GetAnnualSalary();
	int RaiseSalary(int percent);
	std::string Print();
};