# Sudoku 

Sudoku is a puzzle game based on logical number placement. It's first appereance was in France in the 1900s.

## How to play

For the time being, the game is hosted on my [GitHub page](https://github.com/grozeageorge/Sudoku-cpp).

The goal in Sudoku is to fill the 9x9 grid with digits but with a twist. Each column and each row need to contain all of the digits from 1 to 9. Also, each 9x9 subgrid ("blocks") should contain all of the digits from 1 to 9.

To make it more interesting I added a 5 minutes time limit which should make the game more competitive.

## Installation

Visual Studio with C++ 14 is needed, which you can get from the [Microsoft page]("https://visualstudio.microsoft.com/downloads/").

After that, simply cloning the repository and opening the solution with Visual Studio then pressing F5 (to debug or run the release) should do the trick.

## Usage

### Main Menu
Firstly, when you run the game there is a Main Menu with buttons: Play, Help, Leaderboard, Quit.

    By pressing the play button, you would go to the Play State.
    The help button opens a new window in which the rules are explained.
    After pressing the button Leaderboard the locally saved scores are shown.
    The quit button exits the game.
    In the Help and Leaderboard menu there are Back buttons to go back to the Main Menu.

### Play State

After pressing Play in the Main Menu we jump into the Play State. The Play State contains the 9x9 tipical Sudoku grid and a Timer.

    In each grid there should be put digits respecting the game rules.
    The timer automatically stops at 300 seconds.
    There is currently only 1 level.
    If the level is complete or the time runs out we are going in the Game Over Menu.

### Game Over Menu

In the Game Over Menu there are 3 buttons: Retry, Save Progress, Quit.

    By pressing Retry we return to the Play State and play the game again.
    The Save Progress button opens a new Save Game Menu.
    After the quit button is pressed the game quits.

### Save Game Menu

In the Save Game Menu there is displayed your time record, a text box and a save button.

    In the text box you can write your username.
    By pressing save your name and time are saved in the locally stored .txt file that will be displayed in the Leaderboard Menu and the player will go back to the Main Menu.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
    
