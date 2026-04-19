CXX = g++
CXXFLAGS = $(shell pkg-config --cflags ibsimu-1.0.6dev)
LIBS = ~/lib/libibsimu-1.0.6dev.a $(shell pkg-config --libs ibsimu-1.0.6dev | sed 's/-libibsimu-1.0.6dev//')

%: %.cpp
	$(CXX) -o $@ $< $(CXXFLAGS) $(LIBS)
