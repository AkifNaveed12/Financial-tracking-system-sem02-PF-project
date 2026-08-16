# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = financial_system

# List all source files (without headers)
SOURCES = \
    LoginPage.cpp \
    financial_advisory_file.cpp \
    tax_management_system.cpp

# List all header files
HEADERS = \
    advisory_module.h \
    tax_module.h

# Default target (run 'make' to build)
all: $(TARGET)

# Link all object files into executable
$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean build artifacts (run 'make clean')
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean