.SUFFIXES:
.PHONY: default all clean mrproper indent zip run doc

include Makefile_config.mak

CC_FILES	:= $(shell find [^_]* -type f -iname '*.cc' ! -iname 'lisp.*.cc')
HH_FILES	:= $(shell find [^_]*  -type f -iname '*.hh' ! -iname 'lisp.*.hh')
O_FILES	:= $(CC_FILES:%.cc=%.o)

O_READER_FILES	:= include/Reader/lisp.yy.o include/Reader/lisp.tab.o

HELPER_FILES	:= $(wildcard Makefile* *.mak)

DIRS	:= $(sort $(dir $(HH_FILES)))
CCFLAGS	:= -Wall -Wextra -Wno-unused-parameter -Wno-ignored-qualifiers -Wno-return-type -g -std=gnu++14 $(DIRS:%=-I %)

TARGET	:= main

###########################################################

default: all

all: $(TARGET)

$(TARGET): $(O_FILES) $(O_READER_FILES) $(HELPER_FILES)
	$(CC) $(O_FILES) $(O_READER_FILES) -o $@

$(O_FILES): %.o: %.cc $(HH_FILES) $(HELPER_FILES)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	-rm *.o
	-rm */*.o
	-rm */*/*.o
	-rm include/Reader/lisp.*.cc include/Reader/lisp.*.hh
	-rm r- _Doxydoc

mrproper: clean
	-rm $(TARGET)

indent: clean
	-clang-format -verbose -style=Google -i $(CC_FILES) $(HH_FILES)

run: $(TARGET)
	rlwrap ./main

zip: all clean
	zip -r lisp.zip $(CC_FILES) $(HH_FILES) \
		$(SOURCE_READER_FILES) $(HELPER_FILES)

doc: clean
	doxygen Doxyfile
	$(OPEN) _Doxydoc/html/index.html

###########################################################

$(O_READER_FILES): include/Reader/lisp.lex include/Reader/lisp.ypp
	bison --defines=include/Reader/lisp.tab.hh -o include/Reader/lisp.tab.cc include/Reader/lisp.ypp
	flex -o include/Reader/lisp.yy.cc include/Reader/lisp.lex
	g++ $(CCFLAGS) -Wno-unused-function -c include/Reader/lisp.yy.cc -o include/Reader/lisp.yy.o
	g++ $(CCFLAGS) -Wno-unused-function -c include/Reader/lisp.tab.cc -o include/Reader/lisp.tab.o
