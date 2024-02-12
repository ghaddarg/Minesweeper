CXX	= g++
AR	= ar
##################################################################################
SRCDIR	= src
APP		= minesweeper

MKDIR	= mkdir -p
OUTDIR	= exe
LIBDIR  = lib

SRCEXT	= cpp
OBJEXT	= o
##################################################################################
#                                   SQLITE
##################################################################################
CPPSRCS := \
	$(SRCDIR)/$(APP).$(SRCEXT)

OBJS := $(CPPSRCS:.$(SRCEXT)=.$(OBJEXT))

%.o: %.$(SRCEXT)
	$(CXX) $(CXXFLAGS) -c $^ -o $@
##################################################################################
#                                   GXX FLAGS
##################################################################################
CXXFLAGS := \
	-fexceptions -Wall -Wextra -Werror -O0 -g -std=c++14

LDFLAGS := 
##################################################################################
#                              MAIN MAKEFILE
##################################################################################
.PHONY: all
all: dir $(APP)

lib$(APP).a: $(OBJS)
	$(AR) rcs $(LIBDIR)/lib$(APP).a $(OBJS)

$(APP): lib$(APP).a
	$(CXX) $(CXXFLAGS) $(SRCDIR)/$@.cpp -o $(OUTDIR)/$@ $(LIBDIR)/lib$(APP).a $(LDFLAGS)

dir: dir_lib
	${MKDIR} ${OUTDIR}

dir_lib:
	${MKDIR} ${LIBDIR}

check:
	./$(OUTDIR)/$(APP)

clean:
	rm -rf $(OUTDIR) \
		rm -rf ${LIBDIR} \
		$(SRCDIR)/*.$(OBJEXT)