CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = antClass.o asphaltClass.o finalMain.o grassClass.o homeClass.o menuClass.o playerClass.o puddleClass.o spaceClass.o

SRCS = antClass.cpp asphaltClass.cpp finalMain.cpp grassClass.cpp homeClass.cpp menuClass.cpp playerClass.cpp puddleClass.cpp spaceClass.cpp

HEADERS = antClass.hpp asphaltClass.hpp grassClass.hpp homeClass.hpp menuClass.hpp playerClass.hpp puddleClass.hpp spaceClass.hpp

antSim: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} ${SRCS} -o final

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

.PHONY: clean

clean:
	rm -f ${OBJS} final
