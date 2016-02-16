EXEC = sapin # [NOM DE L'EXE]
CXX = gcc
OPTION = -Wall -Wextra

#Path
PATH_INC = includes
PATH_SRC = src
PATH_OBJ = obj

#Directories
OBJ_DIR = obj

LIB_DEP = #-l[NOM DE LA LIBRAIRIE]

#Liste fichiers .cpp et .O
SRC = $(PATH_SRC)/main.c
OBJ = $(PATH_OBJ)/main.o

#Actions
all : $(EXEC)
	./$(EXEC)

debug : $(EXEC)
	gdb ./$(EXEC)


$(PATH_OBJ)/main.o : $(PATH_SRC)/main.c
	$(CXX) $(OPTION) -o $@ -c $< -I$(PATH_INC)

$(EXEC) : $(OBJ)
	@echo "\033[31m[Link] $(EXEC)\033[00m"
	$(CXX) $(OPTION) -o $@ $^


clean :
	@echo "Suppression des .o et fichiers temporaires"
	@find . -name '*.o' -exec rm  {} \;
	@find . -name '*~' -exec rm  {} \;

init :
	mkdir -p obj

.PHONY: clean init debug valgrind all
