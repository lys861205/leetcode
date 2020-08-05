ifneq ($(compile), )
CXX=$(compile)
CXXFLAGS=-g -Wreturn-type -std=c++11
else
CXX=g++
CXXFLAGS=-g -std=c++11
endif

GO=go
GOFLAGS=build -gcflags '-N -l'

SRCS=$(wildcard *.cc greedy/*.cc)
#BINS=$(addprefix bin/, $(patsubst %.cc, %, $(notdir $(SRCS))))
BINS=$(addprefix bin/, $(patsubst %.cc, %, $(SRCS)))
go_SRCS=$(wildcard *.go)
go_BINS=$(addprefix bin/, $(patsubst %.go, %, $(go_SRCS)))


all:$(BINS) $(go_BINS)

$(BINS):bin/%:%.cc
	$(CXX) $< $(CXXFLAGS) -o $@
	@echo "CXX" $@

$(go_BINS):bin/%:%.go
	$(GO) $(GOFLAGS) -o $@ $<

clean:
	rm -f $(BINS) $(go_BINS)
