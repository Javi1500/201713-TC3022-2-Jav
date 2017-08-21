#pragma once
#include <string>

class Employee {
public:
	Employee();
	Employee(int id, std::string firstName, std::string lastName, int salary);
	
	int GetID();
	int GetSalary();
	int GetAnnualSalary();
	float RaiseSalary(float percent);
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetName();
	std::string Print();

	void SetSalary(int salary);

private:
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _salary;
};