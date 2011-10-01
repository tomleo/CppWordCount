###############################################################################
#	TOM LEO's DEFAULT MAKE SCRIPT											  #
#																			  #
#	This is a annoted makefile to copy and hack the crap out of				  #
###############################################################################

#CXX=g++  the default of CXX is 'g++'

#g++
#	-g		Produces debuggin information (usally for gdb)
#
#	-c		Compile or assemble the source files, but do not link.  The linking
#			stage simply is not done.  The ultimate output is in the form of an
#			object file for each source file.
#
#	        By default, the object file name for a source file is made by 
#	        replacing the suffix .c, .i, .s, etc., with .o.
#
#	-o		Place output in file file. This applies regardless to whatever sort
#			of output is being produced, whether it be an executable file, an
#			object file, an assembler file or preprocessed C code.
#
#	        If -o is not specified, 
#	        the default is to put an executable file in a.out
#

#flags for the c-preprocessor (used by c and c++)
CPPFLAGS=-g -c

#linker flags
LDFLAGS=-g

RM=rm -f

SOURCES=wordcount.cc
#OBJECTS=$(subst .cc, .o, $(SOURCES))
OBJECTS=wordcount.o

all:	wordcount

wordcount:	$(OBJECTS)
	$(CXX) $(LDFLAGS) -o wordcount $(OBJECTS)

wordcount.o:	wordcount.cc wordcount.h
	$(CXX) $(CPPFLAGS) wordcount.cc

clean:
	$(RM) $(OBJECTS)


#	$(CXX) $(CPPFLAGS) -c wordcount.cc 
