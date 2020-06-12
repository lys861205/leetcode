CXX=g++
CXXFLAGS=-g -std=c++11
GO=go
GOFLAGS=build -gcflags '-N -l'

SRCS=$(wildcard *.cc)
BINS=$(patsubst %.cc, %, $(SRCS))
go_SRCS=$(wildcard *.go)
go_BINS=$(patsubst %.go, %, $(go_SRCS))


all:$(BINS) $(go_BINS)

$(BIN):%:%.cc
	$(CXX) $< $(CXXFLAGS) -o $@ 

$(go_BINS):%:%.go
	$(GO) $(GOFLAGS) -o $@ $< 

clean:
	rm -f $(BINS) $(go_BINS)
