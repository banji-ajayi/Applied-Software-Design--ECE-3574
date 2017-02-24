hello_c: hello.c
	$(CC) -o $@ $<
hello_cpp: hello.cpp
	$(CXX) -o $@ $<
hello_ns: hello_ns.cpp
	$(CXX) -o $@ $<
hello_comment: hello_comment.cpp
	$(CXX) -o $@ $<
all: hello_c hello_cpp hello_ns hello_comment
	
clean:
	$(RM) -f hello_c hello_cpp hello_ns hello_comment 

