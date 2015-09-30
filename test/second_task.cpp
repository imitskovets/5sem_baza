#include <iostream>

int my_power(int a,int n){
	int result = 1;
	for (int i = n; i > 0; i = i / 2) {
           if ( i % 2 == 1) {
               result = a * result;
           }
           a = a * a;
       }
	return result;
}

int main(){
	int a;
	int n;
	std::cout << "a = " ;
	std::cin >> a;
	std::cout << "n = ";
	std::cin >> n;
	std::cout <<"a^n = " << my_power(a,n) << std::endl;
}
