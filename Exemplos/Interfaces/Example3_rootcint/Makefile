# Compilador e flags
CXX = g++
CXXFLAGS = -O2 -Wall -fPIC
ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --glibs)
INCLUDES = -I$(ROOTSYS)/include

# Fontes e objetos
CLASS_SRCS = MyParticle.cc MyEvent.cc
CLASS_OBJS = $(CLASS_SRCS:.cc=.o)
DICT_SRCS = eventdict.cc
DICT_OBJS = $(DICT_SRCS:.cc=.o)
OBJS = $(CLASS_OBJS) $(DICT_OBJS)
LIB = libMyEvent.so

# Alvo principal
all: $(LIB)

# Gerar dicionário
$(DICT_SRCS): MyParticle.h MyEvent.h LinkDef.h
	rootcint -f $@ -c $(INCLUDES) MyParticle.h MyEvent.h LinkDef.h

# Compilar objetos
%.o: %.cc
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDES) -c $<

# Compilar dicionário
$(DICT_OBJS): $(DICT_SRCS)
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDES) -c $<

# Criar biblioteca compartilhada
$(LIB): $(OBJS)
	$(CXX) -shared -o $@ $^ $(ROOTLIBS)

# Limpar
clean:
	rm -f $(OBJS) $(LIB) $(DICT_SRCS) eventdict.h

