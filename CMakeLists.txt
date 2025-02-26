cmake_minimum_required(VERSION 3.17)
project(Saboteur C)

set(CMAKE_C_STANDARD 99)

add_executable(Saboteur
        main.c
        src/title_screen/title_screen.c src/title_screen/title_screen.h
        src/board/board.c src/board/board.h
        src/structures/structures.h
        src/bandeson/BandeSon.c src/bandeson/BandeSon.h
        src/initialization/initialization.c src/initialization/initialization.h
        src/card_shuffle/card_shuffle.c src/card_shuffle/card_shuffle.h
        src/Rules/Rules.c src/Rules/Rules.h
        src/player_turn/player_turn.h src/player_turn/player_turn.c
        src/AlphabetPourLesNUls/Alphabet.c src/AlphabetPourLesNUls/Alphabet.h
        src/board/DrawPlayersBoard.c src/board/DrawPlayersBoard.h src/save/save.c src/save/save.h)


IF(WIN32)
    target_link_libraries(Saboteur -lmingw32 -lallegro-5.0.10-monolith-md-debug)
ELSE()
    INCLUDE_DIRECTORIES(/usr/local/include)
    LINK_DIRECTORIES(/usr/local/lib)
    file(GLOB LIBRARIES "/usr/local/lib/liballegro*.dylib")
    message("LIBRARIES = ${LIBRARIES}")
    TARGET_LINK_LIBRARIES(Saboteur ${LIBRARIES})
ENDIF(WIN32)