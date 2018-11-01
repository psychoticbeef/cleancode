CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=
LDLIBS_TEST=-L/usr/local/lib -lgtest -lgtest_main -lgmock -lgmock_main -lpthread

SHARED_SRCS=businesslogic.cc stopwords.cc ui.cc wordcount.cc
SRCS=main.cc $(SHARED_SRCS)
OBJS=$(subst .cc,.o,$(SRCS))

SRCS_TEST=test.cc $(SHARED_SRCS)
OBJS_TEST=$(subst .cc,.o,$(SRCS_TEST))

all: wordcount test

wordcount: $(OBJS)
	$(CXX) $(LDFLAGS) -o wordcount $(OBJS) $(LDLIBS)

test: $(OBJS_TEST)
	$(CXX) $(LDFLAGS) -o test $(OBJS_TEST) $(LDLIBS) $(LDLIBS_TEST)

clean:
	$(RM) $(OBJS) $(OBJS_TEST) wordcount test

