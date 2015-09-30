#include <vector>
#include <string>
#include <iostream>
#include <fstream>
//lev.krainov@gmail.com

class MyMatrix{
	int _dim;
	std::vector<std::vector<float>> vecvec;
	public:
	MyMatrix(bool ones, int dim){
		std::vector<float> vec1((unsigned long) dim,0);
		for(int i = 0; i < dim; i++){
			vecvec.push_back(vec1);
		}
		if(ones){
			for(int i = 0; i < dim; i++){
				vecvec[i][i]=1;
			}
		}
		_dim = (int) vecvec.size();
	}
	MyMatrix(int dim) : MyMatrix(false,dim){

	}
	MyMatrix(std::vector<std::vector<float>> vec){
		vecvec = vec;
		_dim = (int) vecvec.size();
	}
	unsigned long dim() {
		return (unsigned long) _dim;
	}
	float get(int y, int x) const{
		float tmp = vecvec[y][x];
		return tmp;
	}
	void put(int y, int x, float data){
		vecvec[y][x] = data;
	}
	void operator+=(const MyMatrix &b){
		for(int i = 0; i < _dim; i++){
			for(int j = 0; j < _dim; j++){
				int tmp= (int) (vecvec[i][j]+ b.get(i, j));
				vecvec[i][j]=tmp;
			}
		}
	}
	void operator-=(const MyMatrix &b){
		for(int i = 0; i < _dim; i++){
			for(int j = 0; j < _dim; j++){
				int tmp= (int) (vecvec[i][j]- b.get(i, j));
				vecvec[i][j]=tmp;
			}
		}
	}
	void operator*=(const MyMatrix &b){
		int tmp = 0;
		std::vector<float> temporalVector((unsigned long) _dim,0);
		for(int k = 0; k < _dim; k++){
			for(int l = 0; l < _dim; l++){
				temporalVector[l] = vecvec[k][l];
			}
			for(int i = 0; i < _dim; i++){
				for(int j = 0; j < _dim; j++){
					tmp += temporalVector[j] + b.get(j, i);
				}
				vecvec[k][i]=tmp;
				tmp=0;
			}
		}
	}


};

int main(){
	std::ifstream inputA;
	std::ifstream inputB;
	std::ifstream inputDim;
	inputA.open("matrixA.txt");
	inputB.open("matrixB.txt");
	inputDim.open("dim.txt");
	std::vector<float> vec((unsigned long) 5,0);
	float tmp = 0;
	std::string tmps;
	int dim;
	inputDim >> dim;
	MyMatrix A(dim);
	MyMatrix B(dim);
	MyMatrix C(true,dim);
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			inputA >> tmps;
			tmp = std::stof(tmps);
			A.put(j, i, tmp);
		}
	}
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			inputB >> tmps;
			tmp = std::stof(tmps);
			B.put(j, i, tmp);
		}
	}
	std::cout << "Matrix A:" << std::endl;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			tmp = A.get(j,i);
			std::cout << tmp << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Matrix B:" << std::endl;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			tmp = B.get(j,i);
			std::cout << tmp << " ";
		}
		std::cout << std::endl;
	}
	B *= A;
	std::cout << "Matrix B*=A:" << std::endl;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			tmp = B.get(j,i);
			std::cout << tmp << " ";
		}
		std::cout << std::endl;
	}
	std::cout << B.get(0,1);
	inputA.close();
	inputB.close();
	inputDim.close();
	
}
