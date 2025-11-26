#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>

class Person{
  private:
    std::string name;
    int birthYear;

  public:
    Person(const std::string name, const int birthYear);
    void print();
};

class Student: public Person{
  private:
    std::string school;

  public:
    Student(const std::string name, const int birthYear, const std::string school);
    void print();
};

Person::Person(const std::string name, const int birthYear) 
  : name(name), birthYear(birthYear) {

  }

Student::Student(const std::string name, const int birthYear, const std::string school) 
  : Person(name, birthYear), school(school) {
    
  }


void Person::print() {
  std::cout << "Name: " << name << std::endl;
}

void Student::print() {
  Person::print();
  std::cout << "School: " << school << std::endl;
}

int main(){
  Student student("Michael", 2003, "NYU");
  Person person("Ipek", 2002);
  student.print();
  person.print();


  return 0;
}
