CXX=g++
CXXFLAGS=-Iinclude -std=c++17 -Wall

all: app

app: src/main.cpp src/user.cpp
	$(CXX) src/main.cpp src/user.cpp -o app $(CXXFLAGS)

clean:
	rm -f app