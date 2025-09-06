// no global variables (constants are okay)
// no strings, only cstrings/char arrays
// include iostream, use new and delete
#include <iostream>
#include <thread> // for pausing instructions, does making an entire thread sleep halt its instructions on other programs?
#include <chrono> // for counting time
#include <cmath> // for rounding
#include <cstdlib> // for srand
#include <ctime> // for time, which is used as a seed

using namespace std;

void wait(int ms) {
  // wrapper with fancy visuals
  ms = std::round(ms / 3);
  for (int i = 0; i < 3; i++) {
    std::cout << "." << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
  }

  return;
}

int main(){
  char input2 = 'y';
    while (input2 == 'y'){ // while they want to play
    srand(time(NULL));
    int num = rand() % 100 + 1; // generate a random number 1-100
    int input = 0;
    int guesses = 1;
    while (num != input){
      guesses++;
      cout << "Guess a number (1-100): ";
      cin >> input;
      wait(1000);
      cout << "\n";
      if (num < input){ // too high
	cout << "Too high!";
      }
      else if (num > input){ // too low
	cout << "Too  low!";
      }
      else {
	cout << "You got it! " << num << "!\n"; // correct guess
	cout << "Attempts: " << guesses; // guess count
      }
      cout << "\n";
    }
    cout << "Want to play again? (y): ";
    cin >> input2;
  }
  cout << "Goodbye!\n";
  return 0;
}
    



