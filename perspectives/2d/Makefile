LIBRARY = 2D.so

SOURCES_DIRECTORY = sources
SOURCES = 2D.cpp

INCLUDES = includes ../../includes/observator/

BUILD_DIRECTORY = build
OBJECTS = $(addprefix $(BUILD_DIRECTORY)/, $(SOURCES:.cpp=.o))

CC = g++

all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	$(CC) -shared -Wl,-soname,libshared.so -o $(LIBRARY) $(OBJECTS)

$(OBJECTS):  $(BUILD_DIRECTORY)/%.o : $(SOURCES_DIRECTORY)/%.cpp | $(BUILD_DIRECTORY)
	$(CC) -fPIC $(addprefix -I, $(INCLUDES)) -c $< -o $@

$(BUILD_DIRECTORY):
	mkdir $(BUILD_DIRECTORY)

clean:
	rm -rf ${BUILD_DIRECTORY}

fclean: clean
	rm -f $(LIBRARY)

re: clean all
