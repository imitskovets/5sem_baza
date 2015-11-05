#include <iostream>
#include <string>

using std::string;

bool PolyndromChecker(string target){
	int length = target.size();
	int length2 = length/2 + 1;
	bool result=true;
	string newstr;
	for (int i = 0 ;i < length2; i++ ){
		if (target[i] != target[length-i-1]){
			result = false;
			break;
		}
	}
	return result;
};

int main(int argc, char* argv[]){
	string target;
	for(;;){
		std::cout << "Enter string:" << std::endl;
		std::cin >> target;
		std::cout << PolyndromChecker(target);
		std::cout << std::endl;
	}
}		
