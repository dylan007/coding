
# Set the command for your C++ compiler, and specify any compiler flags you
# want to use (e.g. -g -Werror).
CXX		= g++
CXXFLAGS	= -ggdb -Wall

# The driver outputs TAP (Test Anything Protocol), so it can also be used with
# any TAP test harness (e.g. prove).  Set the path to your test harness here,
# then use the `prove' target to run the tests with that harness.
PROVE		= prove
PROVEFLAGS	= -e ""


ifeq ($(OS),Windows_NT)
EXEEXT = .exe
endif


all: driver$(EXEEXT)

clean:
	rm -f driver$(EXEEXT)

distclean: clean
	rm -f ColorfulCoinsEasy

run: all
	./driver$(EXEEXT)

test: all
	./driver$(EXEEXT) --abort-on-fail

prove: all
	$(PROVE) $(PROVEFLAGS) ./driver$(EXEEXT)


%$(EXEEXT): %.cc
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

driver$(EXEEXT): ColorfulCoinsEasy.cc

.PHONY: all clean distclean run test prove

# vim:ft=make:noet:ts=8
