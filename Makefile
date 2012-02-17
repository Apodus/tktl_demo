DIRS = src src/graphics src/graphics/models src/graphics/shaders src/graphics/skybox src/graphics/frustum src/misc
INCLUDE_DIRS = -I src
OPENMP   = -fopenmp

PACKAGES = sdl gl glu libpng
CXXFLAGS = -pedantic -Wall -Werror -Wextra -fopenmp -lpthread -std=c++0x -O3 `pkg-config --cflags $(PACKAGES)` $(INCLUDE_DIRS)
LDLIBS   = -lSDL_mixer -L ./lib/ -lGLEW `pkg-config --libs $(PACKAGES)`
CXX      = g++

DEMO = bin/demo

all: $(DEMO)

debug: CXXFLAGS += -O0 -g
debug: LDLIBS += -g
debug: all

prof: CXXFLAGS += -pg
prof: LDLIBS += -pg
prof: all

obj = $(patsubst %.cpp,%.o, $(foreach dir,$(DIRS) + src/main,   $(wildcard $(dir)/*.cpp)))

dep = $(obj:.o=.d)
dep := $(sort $(dep))

.PHONY: all clean

$(DEMO): $(obj)
	$(CXX) $^ $(LDLIBS) -o $@

$(dep): %.d: %.cpp
	$(CXX) -MT "$(@:.d=.o) $@" -MM $(CXXFLAGS) $< > $@

clean:
	$(RM) $(DEMO) $(obj) $(dep)

ifneq ($(MAKECMDGOALS),clean)
  include $(dep)
endif

