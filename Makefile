#
 # 337614747
 # racoeffic@gmail.com
 #


CXX = g++
CXXFLAGS = -std=c++17 -g

MAIN_EXEC = main
TEST_EXEC = test


all: $(MAIN_EXEC) $(TEST_EXEC)


$(MAIN_EXEC): main.o Board.o Place.o Corner.o Player.o Game.o DevelopmentCard.o
	$(CXX) $(CXXFLAGS) -o $(MAIN_EXEC) main.o Board.o Place.o Corner.o Player.o Game.o DevelopmentCard.o


$(TEST_EXEC): test.o Board.o Place.o Corner.o Player.o Game.o DevelopmentCard.o
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) test.o Board.o Place.o Corner.o Player.o Game.o DevelopmentCard.o


main.o: main.cpp Board.hpp Game.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp


test.o: test.cpp Board.hpp Game.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp


Board.o: Board.cpp Board.hpp Place.hpp Corner.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Board.cpp


Place.o: Place.cpp Place.hpp
	$(CXX) $(CXXFLAGS) -c Place.cpp


Corner.o: Corner.cpp Corner.hpp
	$(CXX) $(CXXFLAGS) -c Corner.cpp


Player.o: Player.cpp Player.hpp Board.hpp Game.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp


Game.o: Game.cpp Game.hpp Player.hpp Board.hpp DevelopmentCard.hpp
	$(CXX) $(CXXFLAGS) -c Game.cpp


DevelopmentCard.o: DevelopmentCard.cpp DevelopmentCard.hpp Game.hpp Player.hpp
	$(CXX) $(CXXFLAGS) -c DevelopmentCard.cpp


clean:
	rm -f *.o $(MAIN_EXEC) $(TEST_EXEC)

.PHONY: all clean
