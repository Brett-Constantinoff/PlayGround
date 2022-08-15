CC=g++ -std=c++11 -Wall
LIBS= -lglfw -lglew -lfreetype -framework OpenGL

#recursivly finds all cpp files in src
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
ALL_SRC_CPP := $(call rwildcard,src/,*.cpp)

all: app

app: $(ALL_SRC_CPP) 
	$(CC)  -o $@ $^  $(LIBS) 

clean:
	$(RM) app
	$(RM) *.o