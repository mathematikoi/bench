EXECUTABLE = bench

SOURCES = sources/bench.cpp \
					sources/observator/observator.cpp \
					sources/universe/universe.cpp \
					sources/universe/Something.cpp


CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

INCLUDES_FLAGS = -Iincludes

all: $(EXECUTABLE)

$(EXECUTABLE) : $(SOURCES)
	$(CC) $(COMPILER_FLAGS) ${INCLUDES_FLAGS} $(SOURCES) $(LINKER_FLAGS) -o $(EXECUTABLE)

clean:
	rm -f ${EXECUTABLE}

re: clean all
