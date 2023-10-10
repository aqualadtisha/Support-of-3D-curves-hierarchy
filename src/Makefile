CXX= g++
CXXFLAGS=  -Wall -Werror -Wextra  -std=c++17
EXECUTABLE= figuresprint
MAINSRC=$(wildcard **/*.cc main.cc)
Vgrind= CK_FORK=no valgrind --vgdb=no\
				--leak-check=full --show-leak-kinds=all\
				--trace-children=yes --track-origins=yes\
				-v --verbose -q --quiet -s

all:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -rf $(EXECUTABLE)

VG:
	$(CXX) $(CXXFLAGS) $(MAINSRC) -o $(EXECUTABLE)
	$(Vgrind) ./$(EXECUTABLE)