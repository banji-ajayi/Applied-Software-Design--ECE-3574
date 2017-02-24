io: io.cpp
	$(CXX) -o $@ $<
io_init: io_init-expr.cpp
	$(CXX) -o $@ $<
io_over: io_overloading.cpp
	$(CXX) -o $@ $<
io_over1: io_overloading1.cpp
	$(CXX) -o $@ $<
io_over2: io_overloading2.cpp
	$(CXX) -fpermissive -o $@ $<
all: io io_init io_over io_over1 io_over2
	
clean:
	$(RM) io io_init io_over io_over1 io_over2

