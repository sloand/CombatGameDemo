CXX = g++

CXXFLAGS = -std=c++0x

SRCS = Dice.cpp Character.cpp Goblin.cpp Barbarian.cpp Reptile.cpp BlueMen.cpp  Shadow.cpp QueueList.cpp StackList.cpp Main.cpp

HDRS = Dice.hpp Character.hpp Goblin.hpp Barbarian.hpp Reptile.hpp BlueMen.hpp  Shadow.hpp QueueList.hpp StackList.hpp

combat:
	$(CXX) $(CXXFLAGS) $(SRCS) $(HDRS) -o tourn

clean:
	rm tourn
