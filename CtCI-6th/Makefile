CXX=g++
CXXFLAGS=-g -std=c++11
GO=go
GOFLAGS=build -gcflags '-N -l'

SRCS=$(wildcard Ch*/*.cc)
BINS=$(addprefix bin/, $(patsubst %.cc, %, $(SRCS)))

#vpath %.cc Ch9:.

all:$(BINS)

$(BINS):bin/%:%.cc
	$(CXX) $< $(CXXFLAGS) -o $@


clean:
	rm -f $(BINS)
