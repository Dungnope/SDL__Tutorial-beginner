# Khai báo các biến để dễ quản lý và thay đổi sau này
CXX = g++
COMMON_FLAGS = -std=c++14 -m64 -Wall -I include
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_image

# Thư mục chứa kết quả
DEBUG_OUT = bin/debug/main
RELEASE_OUT = bin/release/main

# Mặc định khi chỉ gõ 'make' sẽ chạy bản debug
all: debug

# --- CẤU HÌNH DEBUG ---
# Sử dụng cờ -g để bắt lỗi (Debug)
debug:
	@mkdir -p bin/debug
	$(CXX) -c src/*.cpp $(COMMON_FLAGS) -g
	$(CXX) *.o -o $(DEBUG_OUT) $(LDFLAGS)
	@rm -f *.o
	./$(DEBUG_OUT)

# --- CẤU HÌNH RELEASE ---
# Sử dụng -O3 để tối ưu tốc độ và -s để nén nhỏ file (Strip symbols)
release:
	@mkdir -p bin/release
	$(CXX) -c src/*.cpp $(COMMON_FLAGS) -O3
	$(CXX) *.o -o $(RELEASE_OUT) -s $(LDFLAGS)
	@rm -f *.o
	./$(RELEASE_OUT)

# Lệnh dọn dẹp các file rác
clean:
	rm -rf bin/debug/main bin/release/main
	rm -f *.o