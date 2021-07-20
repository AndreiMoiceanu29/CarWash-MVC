CC=g++
COMPILE_FLAGS=-Wall -Wextra  -Wstrict-aliasing -pedantic  -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option -g -c
# COMPILE_FLAGS=-Wall -Wextra -Werror
INC_DIRECTORY=inc
INCLUDE_FLAG=-I$(INC_DIRECTORY)
BUILD_DIRECTORY=build
OUTPUT_FILE=main
FLAGS=$(COMPILE_FLAGS) $(INCLUDE_FLAG)
COMPILE=$(CC) $(FLAGS)

# TEST SECTION
REPORT_FILE=report.info
TEST_OUTPUT_FILE=main_test
TEST_DIRECTORY=tests
TEST_FILES=TestCar.cpp TestCarWash.cpp TestEntity.cpp TestMemoryRepository.cpp TestService.cpp TestValidator.cpp TestCSVFileRepository.cpp
TEST_COMPILE_FILES=$(TEST_FILES:%.cpp=$(TEST_DIRECTORY)/%.cpp)
TEST_COMPILE_FILES_WITH_MAIN=$(TEST_COMPILE_FILES) $(TEST_DIRECTORY)/$(TEST_MAIN_FILE)
TEST_MAIN_FILE = main_test.cpp
TEST_MODEL_DIR = $(MODEL_DIRECTORY)
REPORT_DIRECTORY=Report
TEST_COMPILE=$(CC) $(INCLUDE_FLAG) -fprofile-arcs -ftest-coverage
TEST_OBJECTS=$(TEST_FILES:%.cpp=%.o) $(TEST_MAIN_FILE:%.cpp=%.o)
GCDA_TEST_OBJECTS=$(TEST_OBJECTS:%.o=%.gcda)
GCNO_TEST_OBJECTS=$(TEST_OBJECTS:%.o=%.gcno)
GCDA_OBJECTS=$(OBJECTS:%.o=%.gcda)
GCNO_OBJECTS=$(OBJECTS_WITH_MAIN:%.o=%.gcno)
COVERAGE_FILES=$(GCDA_TEST_OBJECTS) $(GCNO_TEST_OBJECTS) $(GCDA_OBJECTS) $(GCNO_OBJECTS) $(REPORT_FILE)
TEST_COMPILE_OBJECT_FILES=$(TEST_OBJECTS:%.o=$(BUILD_DIRECTORY)/%.o)
TEST_LINK = $(CC) -lgcov --coverage $(TEST_COMPILE_OBJECT_FILES) $(COMPILE_OBJECT_FILES) -o $(BUILD_DIRECTORY)/$(TEST_OUTPUT_FILE)

# SOURCE FILES
MAIN_FILE=main.cpp

VALIDATOR_DIRECTORY=Validator
VALIDATOR_FILES=Validator.cpp
COMPILE_VALIDATOR_FILES=$(VALIDATOR_FILES:%.cpp=$(VALIDATOR_DIRECTORY)/%.cpp)

MODEL_DIRECTORY=Model
MODEL_FILES=Entity.cpp Car.cpp CarWash.cpp
COMPILE_MODEL_FILES=$(MODEL_FILES:%.cpp=$(MODEL_DIRECTORY)/%.cpp) 

SERVICE_DIRECTORY=Service
SERVICE_FILES=Service.cpp
COMPILE_SERVICE_FILES=$(SERVICE_FILES:%.cpp=$(SERVICE_DIRECTORY)/%.cpp) 

VIEW_DIRECTORY=View
VIEW_FILES=Console.cpp
COMPILE_VIEW_FILES=$(VIEW_FILES:%.cpp=$(VIEW_DIRECTORY)/%.cpp) 

OBJECTS=$(MODEL_FILES:%.cpp=%.o) $(SERVICE_FILES:%.cpp=%.o) $(VIEW_FILES:%.cpp=%.o) $(VALIDATOR_FILES:%.cpp=%.o)
OBJECTS_WITH_MAIN=$(OBJECTS) $(MAIN_FILE:%.cpp=%.o)
COMPILE_OBJECT_FILES=$(OBJECTS:%.o=$(BUILD_DIRECTORY)/%.o)
COMPILE_OBJECT_FILES_MAIN=$(OBJECTS_WITH_MAIN:%.o=$(BUILD_DIRECTORY)/%.o)
COMPILE_FILES=$(COMPILE_MODEL_FILES) $(COMPILE_SERVICE_FILES) $(COMPILE_VIEW_FILES) $(COMPILE_VALIDATOR_FILES) $(MAIN_FILE)

LINK=$(CC) $(COMPILE_OBJECT_FILES_MAIN) -o $(BUILD_DIRECTORY)/$(OUTPUT_FILE)


build_and_run:clean_all build run

# TEST AND COVERAGE
test_coverage:clean_all test_build run_test generate_info generate_html move_lcov_files open_firefox

test_build: build_objects_coverage test_build_objects test_link test_clean

open_firefox:
	firefox $(REPORT_DIRECTORY)/index.html

generate_info:
	lcov -c -o $(REPORT_FILE) -b . -d .

generate_html:
	genhtml $(REPORT_FILE) -o $(REPORT_DIRECTORY)

move_lcov_files:
	mv $(COVERAGE_FILES) $(REPORT_DIRECTORY)/

run_test:
	./$(BUILD_DIRECTORY)/$(TEST_OUTPUT_FILE)

test_clean:
	rm -f $(TEST_COMPILE_OBJECT_FILES)

test_link:
	$(TEST_LINK)

test_build_objects: test_compile_objects move_test_objects

move_test_objects:
	mv $(TEST_OBJECTS) build/

test_compile_objects:
	$(TEST_COMPILE) $(TEST_COMPILE_FILES_WITH_MAIN) -c 


# BUILD AND REBUILD

rebuild: clean_all build
build: build_objects link clean

run:
	./$(BUILD_DIRECTORY)/$(OUTPUT_FILE)

build_objects_coverage: compile_objects_coverage move_objects
build_objects: compile_objects move_objects

compile_objects_coverage:
	$(COMPILE) $(COMPILE_FILES) -fprofile-arcs -ftest-coverage -c
compile_objects:
	$(COMPILE) $(COMPILE_FILES) -c

move_objects:
	mv $(OBJECTS_WITH_MAIN) build/

link:
	$(LINK)

# CLEANING
	
clean:
	rm -f $(COMPILE_OBJECT_FILES_MAIN)

clean_all:
	rm -f $(COMPILE_OBJECT_FILES_MAIN) 
	rm -f $(BUILD_DIRECTORY)/$(OUTPUT_FILE)
	rm -f $(BUILD_DIRECTORY)/$(TEST_OUTPUT_FILE)
	rm -rf $(REPORT_DIRECTORY)