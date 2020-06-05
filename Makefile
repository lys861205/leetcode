CXX=g++
CXXFLAGS=-g -std=c++11

SRCS=$(wildcard *.cc)
BINS=$(patsubst %.cc, %, $(SRCS))


all:$(BINS) 

$(BIN):%:%.cc
	$(CXX) $< $(CXXFLAGS) -o $@ 

clean:
	rm -f $(BINS)
