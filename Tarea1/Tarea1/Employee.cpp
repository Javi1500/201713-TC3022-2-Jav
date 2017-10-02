/***************************
Materia:Gráficas Computacionales Gráficas
Fecha: 02/10/2017
Autor: A01374356 Garcia Roque Javier Antonio
*****************************/
#include "Employee.h"

Employee::Employee(){
	_id = 0;
	_firstName = "Javier";
	_lastName = "Garcia";
	_salary = 1000000;
}

Employee::Employee(int id, std::string firstName, std::string lastName, int salary){
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_salary = salary;
}

int Employee::GetID(){
	return _id;
}

int Employee::GetSalary(){
	return _salary;
}

int Employee::GetAnnualSalary(){
	return _salary*12;
}

float Employee::RaiseSalary(float percent){
	return _salary+_salary*(percent / 100);
}

std::string Employee::GetFirstName(){
	return std::string(_firstName);
}

std::string Employee::GetLastName() {
	return std::string(_lastName);
}

std::string Employee::GetName() {
	return std::string(_firstName+" "+_lastName);
}

std::string Employee::Print()
{
	return std::string(_firstName+" "+" "+_lastName) +" Salario: "+std::to_string(_salary)+" Salario Anual: "+ std::to_string(_salary*12);
}

void Employee::SetSalary(int salary){
	_salary = salary;
}


