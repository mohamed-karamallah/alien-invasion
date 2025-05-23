# Alien Invasion Game

A C++ strategy game simulation that pits Earth's forces against an alien invasion. The game simulates battles between different types of units from both Earth and Alien armies.

## Project Overview

This project is a battle simulation system that manages different types of military units from both Earth and Alien forces. It implements various data structures and algorithms to handle unit management, battle mechanics, and game state.

## Features

- **Multiple Unit Types**:
  - Earth Forces:
    - Soldiers
    - Tanks
    - Gunnery
    - Heal Units
  - Alien Forces:
    - Soldiers
    - Monsters
    - Drones

- **Advanced Data Structures**:
  - Priority Queues for unit management
  - Linked Lists for efficient data handling
  - Stacks for special operations
  - Custom node implementations

- **Battle Mechanics**:
  - Turn-based combat system
  - Unit health and damage calculations
  - Healing mechanics
  - Priority-based targeting

## Project Structure

```
Project1/
├── main.cpp                 # Entry point of the application
├── game.h/cpp              # Main game logic and state management
├── Earth Forces/
│   ├── EarthArmy.h/cpp     # Earth army management
│   ├── EarthSoldiers.h/cpp # Earth soldier units
│   ├── EarthTanks.h/cpp    # Earth tank units
│   ├── EarthGunnery.h/cpp  # Earth gunnery units
│   └── HealUnit.h/cpp      # Healing unit implementation
├── Alien Forces/
│   ├── AlienArmy.h/cpp     # Alien army management
│   ├── AlienSoldiers.h/cpp # Alien soldier units
│   ├── AlienMonsters.h/cpp # Alien monster units
│   └── AlienDrones.h/cpp   # Alien drone units
└── Data Structures/
    ├── priQueue.h          # Priority queue implementation
    ├── LinkedQueue.h       # Linked list queue
    ├── LinkedStack.h       # Linked list stack
    └── Node.h              # Node implementations
```


## Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/mohamed-karamallah/alien-invasion.git
   ```

2. Open the solution file `Project1.sln` in Visual Studio

3. Build the solution (F7 or Build > Build Solution)

4. Run the program (F5 or Debug > Start Debugging)

## Input/Output

The game uses text files for input and output:
- Input files contain initial game state and parameters
- Output files contain battle results and statistics



## License

This project is open source and available under the MIT License.

## Author

Mohamed Karamallah 
