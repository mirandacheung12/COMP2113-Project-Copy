
FLAGS = -pedantic-errors -std=c++11


SOURCES = main.cpp battle.cpp pointCol.cpp inventory.cpp skillUnlock.cpp minigame.cpp GAME_SAVE.cpp drawEnemy.cpp


OUTPUT = main


all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	g++ $(FLAGS) $(SOURCES) -o $(OUTPUT)


run: $(OUTPUT)
	./$(OUTPUT)


clean:
	rm -f $(OUTPUT)


tar:
	tar -czvf game_project.tgz $(SOURCES)


.PHONY: all clean run tar
