# 变量定义
CXX = g++
CXXFLAGS = -Wall -std=c++11

ifeq ($(OS),Windows_NT)
    RM = del /Q
    EXE = .exe
else
    RM = rm -f
    EXE =
endif

TARGET = hello$(EXE)
SRC = hello_world.cpp

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# 清理目标
clean:
	$(RM) $(TARGET)
