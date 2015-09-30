#include <vector>
//lev.krainov@gmail.com
#include <string>
#include <iostream>
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
		return vecvec[y][x];
	}
	void put(int y, int x, float mdata){
		vecvec[y][x] = mdata;
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
	
}
