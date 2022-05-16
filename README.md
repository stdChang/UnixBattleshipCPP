# UnixBattleshipCPP
A recreation of the Battleship Game, created with C++ with a heavy emphasis on object oriented programming theory. Has a versus Player and versus AI game mode. The AI also contains 3 ranks of difficulty if you want to have a little fun. This was created over the course of several weeks during June 2021.

### Boards and Ships
- Board size
- Ship size
- Ship Placement

The board can be a varied amount of sizes as inputted by the user. Ship size as well as placement can also be manipulated allowing for all types of difficulties. For ex. a sparse map with large grid area and small ships provides an interesting and long game. Quicker rounds can be accomplished with smaller maps and bigger ships, so at the end of the day, customization has been implemented for user to experiment with all kinds of combinations. 

### Players
There is Player vs Player in the form of local co-op i.e "Couch Gaming" where users can pass and play on the same device. Online play has not yet been implemented.
If lacking nearby individuals to play with, my AI will serve as a proper substitute.

### AI
The AIs have been implemented with simple checks and decision-making. Though primitive, I might migrate this code to Python when I've learned Machine Learning via TensorFlow/Pytorch to provide an authentic experience fighting against AI.

For now this project contains:
- Random AI that picks areas to shoot using only a generator seeded with time. Whether hit or miss, the AI will continue to use our generator to make shots.
- A hunt and destroy AI utilizes the random generator until it finds a hit, which it then makes smart decisions to take out nearby spots that may or may not contain the ship. Storing via a list, this AI will prioritize and make better decisions than Random AI.
- The cheating AI knows where all ships are. Meant for humor, this is more of a challenge for the human player, but is not impossible to combat if careful planning is done during the decision making process.

### The Game
Same Ruleset as traditional Battleship game. Players will have a personal board for placing their own ships. Each will also have a blank copy of a board portraying the enemy's field, ships not denoted. The game will start with a player inputting an area to shoot via Row and Column number. They will be notified of a hit or miss and the program will mark it accordingly. The following player will do the same. This continues until all of the ships of one player has been destroyed. Typically in a board game setting, both players will mark their boards after each move, but this program streamlines it so that only viewing and responding to attacks is necessary. There is less confusion, thus no need to repeat coordinates if your rival makes a mistake in marking their own board.

### Running the Game
In order to run the code, clearing the cmake-build-debug might be required. Compile it via CLION or your prefered IDE and execute this program in the terminal. Enjoy!

### About This Project
This project spanned several weeks and really taught me the importance of encapsulating objects for Object Oriented Programming. I was constantly challenged with logical and syntactic obstacles. Sometimes types did not match and other times I wracked my head over which headers to include. Isolating general use functions was a huge playmaker as the project progressed. There were times when I needed to brush up on functions from the native C library to streamline development. I organized all of my information on a Google Document, meticulously using high level abstraction to state what I wanted before actually translating it to C++. This document also prevented me from accidentally recreating general-use and c-library functions. Overall, my diligent work on this project yielded high marks in the ECS 36B course and opened my eyes to the complexity/volatility of large scale projects. I feel more confident and prepared to take on projects like this in the future.

For further information on this project or the UCD Computer Science Department, please contact me at steven.chang878@gmail.com.
