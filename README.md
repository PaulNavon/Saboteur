<font color="#609">

# Saboteur Space Edition Project

<img src="images/README/StartScreen.png" alt="Game First Screen" width="50%" height="100%"/>

## Welcome to Saboteur Space Edition

Spending an evening with friends and no one knows what to do? 
Or an afternoon with family and everyone's bored? 
Why not try a game of Saboteur? 
It's a great way to pass the time while ensuring you all have fun together!

You can adjust your game settings, such as resolution, fps, and full-screen mode, in Settings.

When you start a game, you'll first need to specify the number of players, from 3 to 5. 
Use the slider to select, but you must click on the possible positions of the slider to actually choose a number.

After selecting the number of players, you can enter your username using the keyboard (only letters and numbers are allowed).

<img src="images/README/ConfigPlayer.png" alt="Settings" width="50%" height="100%"/>

You can also choose your astronaut character.

<table>
  <tr>
    <th>Superman</th>
    <th>Skateboarder</th>
    <th>Dreamer</th>
    <th>Burger Lover</th>
    <th>Sushi Man</th>
  </tr>
  <tr>
    <td><img src="images/Character/Character%201.png" alt="Superman" style="max-width: 100px; max-height: 100px;"></td>
    <td><img src="images/Character/Character%202.png" alt="Skateboarder" style="max-width: 100px; max-height: 100px;"></td>
    <td><img src="images/Character/Character%203.png" alt="Dreamer" style="max-width: 100px; max-height: 100px;"></td>
    <td><img src="images/Character/Character%204.png" alt="Burger Lover" style="max-width: 100px; max-height: 100px;"></td>
    <td><img src="images/Character/Character%205.png" alt="Sushi Man" style="max-width: 100px; max-height: 100px;"></td>
  </tr>
</table>

Afterward, you can choose the number of games you would like to play.

<img src="images/README/NBRounds.png" alt="NBRounds" width="50%" height="100%"/>

The game begins, and for each player, since it is a local game, we added a pause where you need to press a key on the keyboard to proceed.
Occasionally, the key press may not be registered, so ensure you're still focused on the game window by clicking on it with your mouse.

<img src="images/README/Break.png" alt="Break" width="50%" height="100%"/>

CAPTAIN can initiate the game, and you'll see the board you'll be interacting with.
In the top-left corner, you'll find the cards that CAPTAIN can use.

In the top-right corner, there is the deck along with a white astronaut. 
The white astronaut can be used to end your turn, either if there's nothing left to do or if a bug occurs.
If all players have ended their turns using the white astronaut, the round concludes.

On the left, you can see the players, and the current player's card is displayed to help them recall their role if necessary.
The board features a starting line with Earth and three hidden planets with crystals on the right.
Any debuffs applied to you will appear in the 'PLAYERS DEBUFF' section.

<img src="images/README/Gameplay.png" alt="Gameplay" width="50%" height="100%"/>

Finally, at the end of the round, you will discover who was the saboteur during the round.

<img src="images/README/Who.png" alt="WhoWasWho" width="50%" height="100%"/>

After all rounds are completed, you'll see the final ranking and the winner will be announced.

<img src="images/README/Rank.png" alt="Ranking" width="50%" height="100%"/>

--- 

## Rules

### **Game Story :**

Players take on the role of either an astronaut trying to reach a planet or an alien trying to block their path. Roles are hidden, and teams must work together while guessing each other's identities.

- **Astronauts win**: They must build a path to the planet to earn galactic crystals.
- **Aliens win**: If astronauts fail, aliens earn the crystals instead.

The player with the most crystals at the end of all rounds wins the game.

### **Game Setup :**
- Each player receives a hidden role (astronaut or alien), distributed based on the number of players:
    - **3 players**: 1 alien, 2 astronauts
    - **4 players**: 1 alien, 3 astronauts
    - **5 players**: 2 aliens, 3 astronauts
- Roles remain secret until the end of the round.

#### **Card Distribution:**
- **3 to 4 players** → 6 cards in hand.
- **5 to 8 players** → 5 cards in hand.
- Remaining cards form a face-down draw pile.

#### **Board Setup:**
- **1 starting card** (showing Earth).
- **3 arrival cards** (planets).
- Players must create a path from the starting card to one of the planets.

#### **Gameplay:**

On each turn, the player can:

- Place a card on the game board.
- Place an action card on one of the players.
- Draw a new card into their hand.

Or,
- Discard 3 cards and end your turn

When a player places a card, the game will automatically draw a new one from the deck.
Their turn then ends, and it becomes the next player's turn.
Path cards must always be placed adjacent to another path card.
Furthermore, all paths extending from a card must align and continue in the same direction on the adjacent card.

### **End Game:**
The game ends if all players are unable to place cards on the board or if all players' hands are empty.
Additionally, players can choose to surrender if the path to all the cards appears impossible.

### To your spaceships!

---

## Launch the game on your computer

To play the game, you will need a version of MinGW compatible with the Allegro 5 library used in the project. 
The Allegro library is provided as a zip file in the GitHub repository.

First, you'll need to install [MinGW Installation Manager ](https://sourceforge.net/projects/mingw/) to get "mingw32-base bin" and "mingw32-gcc-g++ bin".

<img src="images/README/MinGW.png" alt="MinGW" width="50%" height="100%"/>

MinGW will be installed at the root of your computer. On Windows, you can find it at the path C:\MinGW.

As you unpack the library, you will get three folders: include, bin, and lib. 
You will need to merge these folders with the existing ones in the MinGW directory.

And that's it, you're ready to go!

I haven't tested this on other operating systems, but I know we encountered some issues on macOS. 
In this case, the CMakeLists file will need to be updated to be functional.

## Sub-files, folders and utilities

In this folder, you will find the following subfolders:

* `main.c` :  <br />
* `Subfolder "fonts"` : Contains the font  <br />
* `Subfolder "images"` : <p align="justify"> Contains all the bitmaps (Subfolder (Card_Action (players' actions), Card_board (movement cards), Card_ending (arrival cards with treasures), Card_Player (Astronaut/Saboteur), Title_Screen (Menu/Option))) <br />
* `Subfolder "src"` : Contains the `.c` and `.h` subfiles  <br />

Within these subfolders, you will find the following sub-subfolders:

* `Sub-subfolder "bandeson"` : Contains the game music  <br />
* `Sub-subfolder "board"` : Contains all the functions that manage the display on the screen <br />
* `Sub-subfolder "card_suffle"` : Contains all the functions that manage the card draw <br />
* `Sub-subfolder "initialization"` : Contains all the functions that initialize the player's hand, the game board, etc. <br />
* `Sub-subfolder "structures"` : Contains all the structures (card information, player information)  <br />
* `Sub-subfolder "title_screen"` : Contains all the functions that allow resizing the window  <br />
* `Sub-subfolder "player_turn"` : Contains all the functions that manage the player's turn <br />
* `Sub-subfolder "Rules"` : Contains all the functions that manage the rules (positions)  <br />
* `Sub-subfolder "AlphabetPourLesNuls"` : Contains a transformation of the ASCII table with the ALLEGRO table to retrieve key inputs <br />

## Problems and improvements

The game currently experiences issues with loading saved progress, so we advise against quitting with the intention of resuming later.
You can adjust the game's resolution, but please note that playing in full screen mode may cause lag and disrupt the proper functioning of game mechanics.

## Context

The group is composed of 3 first-year students from ECE-Lyon: <br />

<table>
  <tr>
    <td><a href="https://github.com/PaulNavon">NAVON Paul</a></td>
    <td><a href="https://github.com/hugoscatena">SCATENA Hugo  </a></td>
    <td><a href="https://github.com/jonathan971">VELIN Jonathan</a></td>
  </tr>
</table>

Over the course of approximately 2-3 weeks, while balancing our regular classes, we dedicated our time to bringing this project to life. We extend our sincere gratitude to our computer science teacher, Mr. Hintzy (<a href="https://github.com/antoinehintzy">GitHub</a>), for his invaluable assistance and guidance throughout this project.

</font>
