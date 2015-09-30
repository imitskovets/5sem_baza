#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

bool myCmp(std::string str1,std::string str2){
	bool result = false;
	if (str1.size()!=str2.size()){
		return str1.size() > str2.size();
	}
	else{
		for(int i = 0 ; i < str1.size() ; i++){
			if( str1[i] < str2[i] ){
				return false;
			}
		}
	}
	return result;
}

int main(){
	std::vector <std::string> vec;
	std::ifstream my_file;
	my_file.open("bla.txt");
	std::string tmp;
	int n;
	for(int i = 0; my_file >> tmp ; i++ ){
		vec.push_back(tmp);
		std::cout << vec[i] << "  ";
		n++;
	}
	my_file.close();
	std::cout << std::endl << "_______________________________________________________________________________" << std::endl;
	std::sort(vec.begin(), vec.end(),myCmp);
	for(int i = 0; i < n ; i++){
		std::cout << vec[i] << "  ";
	}
	std::cout << std::endl;
}
