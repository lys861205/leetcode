CXX=g++
CXXFLAGS=-g -std=c++11
GO=go
GOFLAGS=build -gcflags '-N -l'

SRCS=$(wildcard *.cc)
BINS=$(addprefix bin/, $(patsubst %.cc, %, $(SRCS)))
go_SRCS=$(wildcard *.go)
go_BINS=$(addprefix bin/, $(patsubst %.go, %, $(go_SRCS)))


all:$(BINS) $(go_BINS)

$(BINS):bin/%:%.cc
	$(CXX) $< $(CXXFLAGS) -o $@ 

$(go_BINS):bin/%:%.go
	$(GO) $(GOFLAGS) -o $@ $< 

clean:
	rm -f $(BINS) $(go_BINS)
