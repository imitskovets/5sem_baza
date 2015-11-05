#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

class A;

int my_abs(int x){
	return x > 0 ? x : - x;
}
int my_abs(short x){
	return 0;
}

int main(int argc,char* argv[])
{	
	//std::cout << setrecision(15); символов после запятой
	std::cout << "Enter your name" << std::endl;
	std::string name;
	getline (std::cin, name);
	std::string a("hi");
	//a.push_back(15);
	std::cout << argv[1] <<std::endl;
	std::cout << a << std::endl;
	std::vector<int> b(100);
	//auto c = a.size();		//определяет тип левой части
	//std::vector <int>::size_type;
	for(auto i = 0; i < a.size(); i++){
		std::cout << i << std::endl;	
	}
	struct Point {
		double x;
		double y;
	};
	Point c;
	c.x = 20.0;
	c.y = -1;
//fstream
	std::cout << '=';
	std::cin >> a;
	ifstream my_file;
	my_file.open("bla.txt");
	my_file >> a;//until space 
	while(my_file >> a){
	}
	my_file.close();

}
class A{
};
