#include <vector>
//lev.krainov@gmail.com
#include <string>
#include <iostream>
class MyMatrix{
	int _dim;
	std::vector<std::vector<float>> vecvec;
	public:
	MyMatrix(bool ones, int dim){
		std::vector<float> vec1(dim,0);
		//(n,std::vector<int>(n,0))
		for(int i; i < dim; i++){
			vecvec.push_back(vec1);
		}
		if(ones == true ){
			for(int i; i < dim; i++){
				vecvec[i][i]=1;
			}
		}
		_dim = vecvec.size();
	}
	MyMatrix(int dim) : MyMatrix(false,dim){}
	MyMatrix(std::vector<std::vector<float>> vec){
		vecvec = vec;
		_dim = vecvec.size();
	}
	int dim() const{
		return _dim;
	}
	float readMe(int y, int x) const{
		return vecvec[y][x];
	}
	void changeMe(int y,int x,float mdata){
		vecvec[y][x] = mdata;
	}
	void operator+=(const MyMatrix &b){
		for(int i = 0; i < _dim; i++){
			for(int j = 0; j < _dim; j++){
				int tmp=(vecvec[i][j]+b.readMe(i,j));
				vecvec[i][j]=tmp;
			}
		}
	}
        void operator-=(const MyMatrix &b){
                for(int i = 0; i < _dim; i++){
                        for(int j = 0; j < _dim; j++){
                                int tmp=(vecvec[i][j]-b.readMe(i,j));
                                vecvec[i][j]=tmp;
                        }
                }
        }
        void operator*=(const MyMatrix &b){
		int tmp = 0;
		std::vector<float> vectmp(dim,0);
		for(int k = 0; k < _dim; k++){
			for(int l = 0; l < _dim; l++){
				vectmp[l] = vecvec[k][l];
			}//TODO
			for(int i = 0; i < _dim; i++){
        	                for(int j = 0; j < _dim; j++){
        	        	        tmp+=(vectmp[j]+b.readMe(j,i));
        	                }
				vecvec[k][i]=tmp;
				tmp=0;
        	        }
		}
        }


};
//std::vector<std::vecto<int>>
int main(){
	
}
