# ################################################################################
# # The targets in this file are used in .gitlab-ci.yml and  the files created
# # are found in the .gitignore
# ################################################################################
# # Changing any names below can change the target names which will require that
# # you update .gitlab_ci.yml and .gitignore
# ################################################################################

# ################################################################################
# # Variable definitions
# ################################################################################

# # Executable names
# PROJECT = cardGame

# GTEST = test_${PROJECT}

# # Compilation command and flags
# CXX=g++
# CXXVERSION= -std=c++17
# CXXFLAGS= ${CXXVERSION} -g
# CXXWITHCOVERAGEFLAGS = ${CXXFLAGS} -fprofile-arcs -ftest-coverage
# LINKFLAGS= -lgtest -lgmock

# LINKFLAGS_LOCAL = -L /usr/local/lib/oatpp-1.3.0
# LINKFLAGS_APP =  $(LINKFLAGS_LOCAL) -loatpp
# LINKFLAGS_TEST = $(LINKFLAGS_APP) -loatpp-test

# # Directories
# SRC_DIR = src
# PROJECT_SRC_DIR = src/project
# GTEST_DIR = test
# SRC_INCLUDE = include
# COVERAGE_DIR = coverage
# COVERAGE_RESULTS = results.coverage
# INCLUDE = -I ${SRC_INCLUDE}/controller -I ${SRC_INCLUDE}/view -I ${SRC_INCLUDE}/model
# SRC_DIR_TESTS = test
# SRC_DIR_SERVICE_BLACKJACK = src/controller
# TEST_SERVER = testServer
# OATPP_INCLUDE_LIB = /usr/local/include/oatpp-1.3.0/oatpp
# OATPP_INCLUDE = -I src -I $(OATPP_INCLUDE_LIB)

# # Tool variables
# STATIC_ANALYSIS = cppcheck
# # STYLE_CHECK = cpplint --recursive ${SRC_DIR} ${PROJECT_SRC_DIR} ${SRC_INCLUDE}
# STYLE_CHECK = cpplint --recursive ${SRC_DIR} ${PROJECT_SRC_DIR}
# GCOV = gcov
# LCOV = lcov
# COVERAGE_RESULTS = results.coverage
# COVERAGE_DIR = coverage
# DOXY_DIR = docs/code

# ################################################################################
# # Targets
# ################################################################################

# # Default goal
# .DEFAULT_GOAL := compileProject

# ################################################################################
# # Clean-up targets
# ################################################################################
# .PHONY: clean-cov
# clean-cov:
# 	rm -rf *.gcov *.gcda *.gcno ${COVERAGE_RESULTS} ${COVERAGE_DIR}

# .PHONY: clean-docs
# clean-docs:
# 	rm -rf docs/code/html

# .PHONY: clean-exec
# clean-exec:
# 	rm -rf ${PROJECT} ${GTEST} ${PROJECT}.exe ${GTEST}.exe testServer

# .PHONY: clean-obj
# clean-obj:
# 	rm -rf ${SRC}/*.o

# .PHONY: clean-temp
# clean-temp:
# 	rm -rf *~ \#* .\#* \
# 	${SRC_DIR}/*~ ${SRC_DIR}/\#* ${SRC_DIR}/.\#* \
# 	${GTEST_DIR}/*~ ${GTEST_DIR}/\#* ${GTEST_DIR}/.\#* \
# 	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#* \
# 	${PROJECT_SRC_DIR}/*~ ${PROJECT_SRC_DIR}/\#* ${PROJECT_SRC_DIR}/.\#* \
# 	${DESIGN_DIR}/*~ ${DESIGN_DIR}/\#* ${DESIGN_DIR}/.\#* \
# 	*.gcov *.gcda *.gcno 

# .PHONY: clean
# clean: clean-cov clean-docs clean-exec clean-obj clean-temp

# ################################################################################
# # Compilaton targets
# ################################################################################

# # default rule for compiling .cc to .o
# %.o: %.cpp
# 	${CXX} ${CXXFLAGS} -c $< -o $@

# # Compilation targets
# # compilation for making the project
# # using the files in include, src, and src/project
# ${PROJECT}: ${SRC_DIR} ${PROJECT_SRC_DIR} clean-exec
# 	${CXX} ${CXXWITHCOVERAGEFLAGS} -o ${PROJECT} ${OATPP_INCLUDE} \
# 	${SRC_DIR}/controller/*.cpp \
# 	${SRC_DIR}/model/*.cpp \
# 	${SRC_DIR}/view/*.cpp \
# 	${PROJECT_SRC_DIR}/*.cpp \
# 	$(LINKFLAGS_APP)

# # compilation for performing testing
# # using the files in include, src, and test, but not src/project
# ${GTEST}: ${GTEST_DIR} ${SRC_DIR} clean-exec
# 	${CXX} ${CXXWITHCOVERAGEFLAGS} -o ${GTEST} ${INCLUDE} ${OATPP_INCLUDE} \
# 	${GTEST_DIR}/*.cpp \
# 	${SRC_DIR}/controller/*.cpp \
# 	${SRC_DIR}/model/*.cpp \
# 	${SRC_DIR}/view/*.cpp \
# 	${LINKFLAGS}

# ################################################################################
# # Test targets
# ################################################################################

# # To perform all tests
# all: ${GTEST} coverage docs static style

# # To perform the memory checks
# # memcheck: ${GTEST}
# # 	valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./${GTEST}

# # To perform the code coverage checks
# coverage: clean-exec clean-cov ${GTEST}
# 	./${GTEST} ${OATPP_INCLUDE}
# 	# Determine code coverage
# 	${LCOV} --capture --gcov-tool ${GCOV} --directory . --output-file \
# 	${COVERAGE_RESULTS} --rc lcov_branch_coverage=1
# 	# Only show code coverage for the source code files (not library files)
# 	${LCOV} --extract ${COVERAGE_RESULTS} */*/*/${SRC_DIR}/* -o \
# 	${COVERAGE_RESULTS}
# 	#Generate the HTML reports
# 	genhtml ${COVERAGE_RESULTS} --output-directory ${COVERAGE_DIR}
# 	#Remove all of the generated files from gcov
# 	make clean-temp

# # To perform the static check 
# static: ${SRC_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
# 	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${PROJECT_SRC_DIR} \
# 	${SRC_INCLUDE} --error-exitcode=1 --suppress=missingInclude --suppress=unknownMacro:src/dto/DTO.hpp --suppress=*:src/controller/Game.cpp

# # To test server/REST stuff
# $(TEST_SERVER): $(SRC_DIR_TESTS)
# 	$(CXX) $(CXXFLAGS) -o $(TEST_SERVER) $(OATPP_INCLUDE) \
# 	$(SRC_DIR_TESTS)/*.cpp $(SRC_DIR_SERVICE_BLACKJACK)/*.hpp $(LINKFLAGS_TEST) \
# 	${SRC_DIR}/controller/*.cpp \
# 	${SRC_DIR}/model/*.cpp \
# 	${SRC_DIR}/view/*.cpp

# # # To perform the style check
# # style: ${SRC_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
# # 	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${SRC_INCLUDE}/* \
# # 	${PROJECT_SRC_DIR}/*
# # To perform the style check without the include directory
# style: ${SRC_DIR} ${PROJECT_SRC_DIR}
# 	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${PROJECT_SRC_DIR}/*

# docs: ${SRC_INCLUDE}
# 	doxygen ${DOXY_DIR}/doxyfile

################################################################################
# The targets in this file are used in .gitlab-ci.yml and  the files created
# are found in the .gitignore
################################################################################
# Changing any names below can change the target names which will require that
# you update .gitlab_ci.yml and .gitignore
################################################################################

################################################################################
# Variable definitions
################################################################################

# Executable names
PROJECT = cardGame

GTEST = test_${PROJECT}

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++17
CXXFLAGS= ${CXXVERSION} -g
CXXWITHCOVERAGEFLAGS = ${CXXFLAGS} -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest -lgmock

LINKFLAGS_LOCAL = -L /usr/local/lib/oatpp-1.3.0
LINKFLAGS_APP =  $(LINKFLAGS_LOCAL) -loatpp
# LINKFLAGS_TEST = $(LINKFLAGS_APP) -loatpp-test -loatpp-web -loatpp-swagger -loatpp-codegen
LINKFLAGS_TEST = $(LINKFLAGS_APP) -loatpp-test
# -loatpp-web -loatpp-swagger -loatpp-codegen -loatpp-core


# Directories
SRC_DIR = src
PROJECT_SRC_DIR = src/project
GTEST_DIR = test
SRC_INCLUDE = include
COVERAGE_DIR = coverage
COVERAGE_RESULTS = results.coverage
INCLUDE = -I ${SRC_INCLUDE}/controller -I ${SRC_INCLUDE}/view -I ${SRC_INCLUDE}/model
SRC_DIR_TESTS = test
SRC_DIR_SERVICE_BLACKJACK = src/controller
TEST_SERVER = testServer
OATPP_INCLUDE_LIB = /usr/local/include/oatpp-1.3.0/oatpp
OATPP_INCLUDE = -I src -I $(OATPP_INCLUDE_LIB)

# Tool variables
STATIC_ANALYSIS = cppcheck
# STYLE_CHECK = cpplint --recursive ${SRC_DIR} ${PROJECT_SRC_DIR} ${SRC_INCLUDE}
STYLE_CHECK = cpplint --recursive ${SRC_DIR} ${PROJECT_SRC_DIR}
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage
DOXY_DIR = docs/code

################################################################################
# Targets
################################################################################

# Default goal
.DEFAULT_GOAL := compileProject

################################################################################
# Clean-up targets
################################################################################
.PHONY: clean-cov
clean-cov:
	rm -rf *.gcov *.gcda *.gcno ${COVERAGE_RESULTS} ${COVERAGE_DIR}

.PHONY: clean-docs
clean-docs:
	rm -rf docs/code/html

.PHONY: clean-exec
clean-exec:
	rm -rf ${PROJECT} ${GTEST} ${PROJECT}.exe ${GTEST}.exe testServer

.PHONY: clean-obj
clean-obj:
	rm -rf ${SRC}/*.o

.PHONY: clean-temp
clean-temp:
	rm -rf *~ \#* .\#* \
	${SRC_DIR}/*~ ${SRC_DIR}/\#* ${SRC_DIR}/.\#* \
	${GTEST_DIR}/*~ ${GTEST_DIR}/\#* ${GTEST_DIR}/.\#* \
	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#* \
	${PROJECT_SRC_DIR}/*~ ${PROJECT_SRC_DIR}/\#* ${PROJECT_SRC_DIR}/.\#* \
	${DESIGN_DIR}/*~ ${DESIGN_DIR}/\#* ${DESIGN_DIR}/.\#* \
	*.gcov *.gcda *.gcno 

.PHONY: clean
clean: clean-cov clean-docs clean-exec clean-obj clean-temp

################################################################################
# Compilaton targets
################################################################################

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Compilation targets
# compilation for making the project
# using the files in include, src, and src/project
${PROJECT}: ${SRC_DIR} ${PROJECT_SRC_DIR} clean-exec
	${CXX} ${CXXWITHCOVERAGEFLAGS} -o ${PROJECT} ${OATPP_INCLUDE} \
	${SRC_DIR}/controller/*.cpp \
	${SRC_DIR}/model/*.cpp \
	${SRC_DIR}/view/*.cpp \
	${PROJECT_SRC_DIR}/*.cpp \
	$(LINKFLAGS_APP)

# compilation for performing testing
# using the files in include, src, and test, but not src/project
${GTEST}: ${GTEST_DIR} ${SRC_DIR} clean-exec
	${CXX} ${CXXWITHCOVERAGEFLAGS} -o ${GTEST} ${INCLUDE} ${OATPP_INCLUDE} \
	${GTEST_DIR}/*.cpp \
	${SRC_DIR}/controller/Game.cpp \
	${SRC_DIR}/model/*.cpp \
	${SRC_DIR}/view/*.cpp \
	${LINKFLAGS_TEST}

################################################################################
# Test targets
################################################################################

# To perform all tests
all: ${GTEST} coverage docs static style

# To perform the memory checks
# memcheck: ${GTEST}
# 	valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./${GTEST}

# To perform the code coverage checks
coverage: clean-exec clean-cov ${GTEST}
	./${GTEST} ${OATPP_INCLUDE}
	# Determine code coverage
	${LCOV} --capture --gcov-tool ${GCOV} --directory . --output-file \
	${COVERAGE_RESULTS} --rc lcov_branch_coverage=1
	# Only show code coverage for the source code files (not library files)
	${LCOV} --extract ${COVERAGE_RESULTS} */*/*/${SRC_DIR}/* -o \
	${COVERAGE_RESULTS}
	#Generate the HTML reports
	genhtml ${COVERAGE_RESULTS} --output-directory ${COVERAGE_DIR}
	#Remove all of the generated files from gcov
	make clean-temp

# To perform the static check 
static: ${SRC_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${PROJECT_SRC_DIR} \
	${SRC_INCLUDE} --error-exitcode=1 --suppress=missingInclude --suppress=unknownMacro:src/dto/DTO.hpp --suppress=*:src/controller/Game.cpp

# To test server/REST stuff
$(TEST_SERVER): $(SRC_DIR_TESTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_SERVER) $(OATPP_INCLUDE) \
	$(SRC_DIR_TESTS)/*.cpp $(SRC_DIR_SERVICE_BLACKJACK)/*.hpp $(LINKFLAGS_TEST) \
	${SRC_DIR}/controller/Game.cpp \
	${SRC_DIR}/model/*.cpp \
	${SRC_DIR}/view/*.cpp

# # To perform the style check
# style: ${SRC_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
# 	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${SRC_INCLUDE}/* \
# 	${PROJECT_SRC_DIR}/*
# To perform the style check without the include directory
style: ${SRC_DIR} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${PROJECT_SRC_DIR}/*

docs: ${SRC_INCLUDE}
	doxygen ${DOXY_DIR}/doxyfile

