#include <vector>
#include <string>
#include <iostream>
#include <fstream>
//lev.krainov@gmail.com

float vectorMultiply(std::vector<float> a,std::vector<float> b){
	// a * b
	float c = 0.0;
	int dim = (int) a.size();
	for (int i = 0; i < dim; i++){
		c += a[i] * b[i];
	}
	return c;
}
std::vector<float> vectorSubtraction(std::vector<float> a, std::vector<float> b){	// return a-b
	std::vector<float> c(a.size(),0);
	for (int i = 0; i < (int)a.size() ; i++){
		c[i] = a[i] - b[i];
	}
	return c;
}

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
		std::vector<float> temporalVectorA((unsigned long) _dim,0);
		std::vector<float> temporalVectorB((unsigned long) _dim,0);
		for(int k = 0; k < _dim; k++){
			for(int l = 0; l < _dim; l++){
				//temporalVectorA[l] = vecvec[k][l];
				temporalVectorA = vecvec[k];
			}
			for(int i = 0; i < _dim; i++){
				for(int l = 0; l < _dim; l++){
					temporalVectorB[l] = b.get(l, i);
				}
				vecvec[k][i] = vectorMultiply(temporalVectorA, temporalVectorB);
			}
		}
	}
	void operator/(const MyMatrix &b){	// transpose
		for(int i = 0; i < _dim; i++){
			for(int j = 0; j < _dim; j++){
				vecvec[i][j] = b.get(j,i);
			}
		}
	}
	void operator^(const MyMatrix &b){	// ^(-1)	vecvec must be E
		for(int i = 0; i < _dim; i++){
			for(int j = 0; j < _dim; j++){
				vecvec[i][j] = b.get(j,i);
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
	float tmp = 0;
	std::string tmps;
	int dim;
	inputDim >> dim;
	MyMatrix A(dim);
	MyMatrix B(dim);
	//MyMatrix C(true,dim);
	// input begin
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
	// input end
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
	A / B;
	std::cout << "Matrix A/B:" << std::endl;
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			tmp = A.get(j,i);
			std::cout << tmp << " ";
		}
		std::cout << std::endl;
	}
	inputA.close();
	inputB.close();
	inputDim.close();
	return 0;
}
