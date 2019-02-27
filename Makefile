.SUFFIXES:
.PHONY: default all clean mrproper indent zip run doc

include Makefile_config.mak

CC_FILES	:= $(shell find [^_]* -type f -iname '*.cc' ! -iname 'lisp.*.cc')
HH_FILES	:= $(shell find [^_]*  -type f -iname '*.hh' ! -iname 'lisp.*.hh')
O_FILES	:= $(CC_FILES:%.cc=%.o)

O_READER_FILES	:= Reader/lisp.yy.o Reader/lisp.tab.o

HELPER_FILES	:= $(wildcard Makefile* *.mak)

DIRS	:= $(sort $(dir $(HH_FILES)))
CCFLAGS	:= -W -Wall -std=gnu++14 $(DIRS:%=-I %)

TARGET	:= main

###########################################################

default: all

all: $(TARGET)

$(TARGET): $(O_FILES) $(O_READER_FILES) $(HELPER_FILES) 
	$(CC) $(O_FILES) $(O_READER_FILES) -o $@

$(O_FILES): %.o: %.cc $(HH_FILES) $(HELPER_FILES)
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	-rm -f $(O_FILES) $(TARGET) */*.o 
	-rm Reader/lisp.*.cc Reader/lisp.*.hh
	-rm -r _Doxydoc

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

$(O_READER_FILES): Reader/lisp.lex Reader/lisp.ypp
	bison --defines=Reader/lisp.tab.hh -o Reader/lisp.tab.cc Reader/lisp.ypp
	flex -o Reader/lisp.yy.cc Reader/lisp.lex 
	g++ $(CCFLAGS) -Wno-unused-function -c Reader/lisp.yy.cc -o Reader/lisp.yy.o 
	g++ $(CCFLAGS) -Wno-unused-function -c Reader/lisp.tab.cc -o Reader/lisp.tab.o
