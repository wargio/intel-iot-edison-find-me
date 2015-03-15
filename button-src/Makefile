CXX 	= $(shell ls *.cxx | cut -d . -f1)
OBJ	= $(addsuffix .o, $(CXX))
EXEC	= $(notdir $(CURDIR))
CX	= g++

all:	$(OBJ)
	$(CX) -o $(EXEC) $(OBJ) -lmraa

clean:
	rm -rf $(OBJ) $(EXEC)

$(OBJ): %.o: %.cxx
	$(CX) -c -o $@ $<

.PHONY: all clear
