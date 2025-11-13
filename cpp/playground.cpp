#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>
using std::string;

int standard_library() {
  int x, y;
  std::cout <<"2 nums:\n";
  std::cin >> x >> y;
  int sum = x + y;
  std::cout << "sum is " << sum << std::endl;
  // std::cout << "Hello, Clang!" <<endl;
  return 0;
}

int fund_types(){
  enum Menu {BigMac = 1, Fries = 0, Shake = 2};
  Menu order = Fries;
  std::cout << "lemme get a number " << order << std::endl;

  return 0;
}


int pointers(){
  int x = 8;
  int* p = &x;

  *p = 9;

  int y = 21;
  void* q = &y;
  int* sy = static_cast<int*>(q);


  std::cout << *sy << std::endl;


  return 0;

}


int strings(){
  string greeting = "hello";
  greeting += " clang!";

  std::cout << greeting << std::endl;

  return 0;
}

int structs(){
  enum Menu {BigMac = 1, Fries = 0, Shake = 2};
  struct Order {
    int orderNumber;
    Menu item;
    bool mcDAppUser;
  };

  Order ord = {1, BigMac, true};
  std::cout << ord.orderNumber << std::endl;
  return 0;
}

int dynamic_memory(){
  enum Menu {BigMac = 1, Fries = 0, Shake = 2};
  struct Order {
    int orderNumber;
    Menu item;
    bool mcDAppUser;
  };

  Order* p;
  p = new Order;
  p->item = BigMac;

  std::cout << p->item << std::endl;

  delete p;

  return 0;
}

int references(){
  int x = 8;
  int& y = x;
  y = 9;
  std::cout << x <<std::endl;
  return 0;
}

int casting(){
  int x = 8;
  float y = float(x);

  float z = static_cast<float>(x);

  std::cout << typeid(z).name() << std::endl;
  
  
  
  
  
  return 0;
}


int arrayreturn(int* p){ // Accepts int pointer
  p[0] = 8;
  return 0;
}


int main(){
  // standard_library();
  // fund_types();
  // pointers();
  // strings();
  // structs();
  // dynamic_memory();
  // references();
  // casting();
  
  // int arr[2];
  // arr[0] = 2;
  // std::cout << arr[0] << std::endl;
  // arrayreturn(arr); // pass as pointer
  // std::cout << arr[0] << std::endl;

  
}
