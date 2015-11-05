#goo.gl/g75tSZ
#$(subst xx,yy)
#$(patsubst %.x,%.y)
#$(NAME,.x=.y)
#$(strip lisnieprobeli)
#$(filter)
#$(filter out)
hello: hello.cpp
	g++ $^ -o $@
.PHONY: clean
clean:
	rm -f removeme
%.o:%.cpp
	g++ $^ -c -o $@
SRC:=*.cpp
OBJ:=$(patshbst %.cpp,%.o,$()SRC))
