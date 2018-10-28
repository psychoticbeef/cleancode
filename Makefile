CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=
LDLIBS_TEST=-L/usr/local/lib -lgtest -lgtest_main -lgmock -lgmock_main -lpthread

SRCS=main.cc
OBJS=$(subst .cc,.o,$(SRCS))

SRCS_TEST=test.cc
OBJS_TEST=$(subst .cc,.o,$(SRCS_TEST))

all: stopwords test

stopwords: $(OBJS)
	$(CXX) $(LDFLAGS) -o stopwords $(OBJS) $(LDLIBS)

test: $(OBJS_TEST)
	$(CXX) $(LDFLAGS) -o test $(OBJS_TEST) $(LDLIBS) $(LDLIBS_TEST)

clean:
	$(RM) $(OBJS) $(OBJS_TEST)

