EXECUTABLE = bench


SOURCES_DIRECTORY = sources
SOURCES = bench.cpp \
					observator/observator.cpp \
					interactor/interactor.cpp \
					universe/universe.cpp 

BUILD_DIRECTORY = build
OBJECTS = $(addprefix $(BUILD_DIRECTORY)/, $(SOURCES:.cpp=.o))

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

INCLUDES_FLAGS = -Iincludes

all: $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(COMPILER_FLAGS) ${INCLUDES_FLAGS} $(OBJECTS) $(LINKER_FLAGS) -o $(EXECUTABLE)

$(OBJECTS):  $(BUILD_DIRECTORY)/%.o : $(SOURCES_DIRECTORY)/%.cpp | $(BUILD_DIRECTORY)
	$(CC) $(INCLUDES_FLAGS) -c $< -o $@

$(BUILD_DIRECTORY):
	for object in $(OBJECTS); do \
		mkdir -p `dirname $$object`; \
	done

clean:
	rm -rf $(BUILD_DIRECTORY)

fclean: clean
	rm -f $(EXECUTABLE)

re: clean all
