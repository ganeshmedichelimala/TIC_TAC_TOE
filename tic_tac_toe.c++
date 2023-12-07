#include<iostream>
#include<ctime>

// Function prototypes
void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
  // Declare a character array named 'spaces' with a size of 9 elements
  char spaces[9];

  // Use the 'fill' function to fill the elements of the 'spaces' array with the character ' '
  std::fill(spaces, spaces + 9, ' ');

  char player = 'X';
  char computer = 'O';
  bool running = true;

  drawBoard(spaces);

  while (running) {
    // Player's move
    playerMove(spaces, player);
    drawBoard(spaces);

    // Check if the player has won or if it's a tie
    if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
      running = false;
      break;
    }
    else if(checkTie(spaces)){
      running = false;
      break;
    }


    // Computer's move
    computerMove(spaces, computer);
    drawBoard(spaces);

    // Check if the computer has won or if it's a tie
    if (checkWinner(spaces, player, computer) || checkTie(spaces)) {
      running = false;
      break;
    }
    else if(checkTie(spaces)){
      running = false;
      break;
    }
    
  }
  return 0;
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(char *spaces) {
  std::cout << '\n';
  std::cout << "   |   |   " << '\n';
  std::cout << " " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << " " << '\n';
  std::cout << "___|___|___" << '\n';
  std::cout << "   |   |   " << '\n';
  std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << " " << '\n';
  std::cout << "___|___|___" << '\n';
  std::cout << "   |   |   " << '\n';
  std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << " " << '\n';
  std::cout << '\n';
}
// Function for player's move
void playerMove(char *spaces, char player) {
  int number;
  do {
    std::cout << "Enter a spot to place a marker (1-9): ";
    std::cin >> number;
    number--;
    if (spaces[number] == ' ') {
      spaces[number] = player;
      break;
    }
  } while (!number >= 0 || !number < 8);
}
// Function for computer's move
void computerMove(char *spaces, char computer) {
  int number;
  srand(time(0));
  while (true) {
    number = rand() % 9;
    if (spaces[number] == ' ') {
      spaces[number] = computer;
      break;
    }
  }
}
// Function to check for a winner
bool checkWinner(char *spaces, char player, char computer) {
  // Check all possible winning combinations
  // Update the message to be displayed based on whether the player or computer wins
  if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])) {
    spaces[0] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])) {
    spaces[3] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])) {
    spaces[6] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])) {
    spaces[0] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])) {
    spaces[1] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])) {
    spaces[0] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])) {
    spaces[0] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
    spaces[0] == player ? std::cout << "YOU WIN !" : std::cout << "YOU LOSE !";
  } else {
    return false;
  }

  return true;
}
// Function to check for a tie
bool checkTie(char *spaces) {
  for (int i = 0; i < 9; i++) {
    if (spaces[i] == ' ') {
      return false;
    }
  }
  std::cout << "It's a TIE!\n";
  return true;
}