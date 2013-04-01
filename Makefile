RM := rm -f

INCLUDE_DIRS := include /home/ubuntu/work/src/cpp-netlib
CXXFLAGS      = -std=gnu++11 -Wall -g $(addprefix -I,$(INCLUDE_DIRS))
SRC           = $(wildcard src/*.cpp)
OBJ           = $(subst .cpp,.o,$(SRC))
CLEANLIST     = bin/world $(OBJ)
LDFLAGS       = -lboost_system -lboost_filesystem

all : bin/server

.PHONY : all cuke clean

clean :
	$(RM) $(CLEANLIST)

cuke : bin/server
	bundle exec cucumber

bin/server : src/server.o
	$(CXX) $+ -o $@ $(LDFLAGS)
