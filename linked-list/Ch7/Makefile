ifneq ($(compile), )
CXX=$(compile)
CXXFLAGS=-g -Wreturn-type -std=c++11
else
CXX=g++
CXXFLAGS=-g -std=c++11
LDFLAGS=-lpthread
endif

SRCS=$(wildcard *.cc)
BINS=$(patsubst %.cc, %, $(SRCS))

all:$(BINS) $(go_BINS)

$(BINS):%:%.cc
	@$(CXX) $< $(CXXFLAGS) -o $@ $(LDFLAGS)
	@echo "CXX" $@
	@echo "[RUN]" $@
	@./$@

clean:
	rm -f $(BINS)
