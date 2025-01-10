BUILD_DIR = build
OBJS_DIR = $(BUILD_DIR)/objs

SOLUTION_BINARY = $(BUILD_DIR)/solution
BRUTEFORCE_BINARY = $(BUILD_DIR)/$(notdir Stress_Testing/bruteForce)
GENERATOR_BINARY = $(BUILD_DIR)/$(notdir Stress_Testing/generator)
CODEDIRS = . ./Stress_Testing
INCDIRS = . ./include


CXX = g++
DEPFLAGS = -MP -MMD
CXXFLAGS = -Wall -Wextra -g \
        $(foreach D,$(INCDIRS), -I$(D)) \
        $(DEPFLAGS)

CXXFILES = $(foreach D, \
        $(CODEDIRS), \
        $(wildcard $(D)/*.cpp))

OBJECTS = $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(notdir $(CXXFILES)))
DEPFILES = $(patsubst %.cpp, $(OBJS_DIR)/%.d, $(notdir $(CXXFILES)))

all: $(SOLUTION_BINARY) \
     $(GENERATOR_BINARY) \
     $(BRUTEFORCE_BINARY)


$(SOLUTION_BINARY): $(OBJS_DIR)/solution.o | $(OBJS_DIR)
	$(CXX) -o $@ $<

$(GENERATOR_BINARY): $(OBJS_DIR)/generator.o | $(OBJS_DIR)
	$(CXX) -o $@ $<

$(BRUTEFORCE_BINARY): $(OBJS_DIR)/bruteForce.o | $(OBJS_DIR)
	$(CXX) -o $@ $<


$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJS_DIR)/%.o: Stress_Testing/%.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
clean:
	rm -f $(SOLUTION_BINARY) \
	       $(BRUTEFORCE_BINARY) \
	       $(GENERATOR_BINARY) \
	       $(OBJECTS) \
	       $(DEPFILES)

help:
	@echo "make clean: To remove executable, objects and dependency files."
	@echo "make $(SOLUTION_BINARY): To build $(SOLUTION_BINARY) only."
	@echo "make all: To build for Stress_Testing."

-include $(DEPFILES)

.PHONY: clean help all
