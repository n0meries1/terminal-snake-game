#include <iostream>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <string>


bool gameover = false;
int fruitX, fruitY, snakeX, snakeY;
int score = 0;
int tailX[100], tailY[100];
int tail = 1;

void setup() {
	system("cls");
	bool gameover = false;
	

	for (int a = 0; a < 20; a++) //draw top boundaries
		std::cout << "#";


	for (int x = 0; x < 10; x++) { // draw left and right boundaries
		std::cout << std::endl;

		for (int n = 0; n < 20; n++) {
			if (n == 0 or n == 19) {
				std::cout << "#";
			}
		

			else if (n == fruitX && x == fruitY) // draw fruit by taking in fruit position
				std::cout << "X";

			else if (n == snakeX && x == snakeY) // draw snake by taking in snake position
				std::cout << "O";



			else
			{
				bool print = false;
				for (int a = 0; a < tail; a++) {
					
					if (tailX[a] == n && tailY[a] == x) {
						print = true;
						std::cout << "o";

					}
				}
				if (print == false) {
					std::cout << " "; // draw empty spaces to represent empty spaces
				}
			}
		}
	}

	std::cout << '\n'; // draw bottom boundaries
	for (int n = 0; n < 20; n++)
		std::cout << "#";

	std::cout << "\nScore "<< score << std::endl; // show score



}

void draw() {

	if (snakeX == fruitX && snakeY == fruitY) { //generates a new fruit when one is eaten and adds to score
		fruitX = rand() % 19 + 1;
		fruitY = rand() % 9 + 0;
		score += 10;
		tail += 1;

	}

	
	


}



void logic() {
	
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = snakeX;
	tailY[0] = snakeY;
	

	for (int n = 1; n < tail; n++) {
		prev2X = tailX[n];
		prev2Y = tailY[n];
		tailX[n] = prevX;
		tailY[n] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		

	}
	


	if ((snakeX == 0 || snakeX == 20) || (snakeY == -1 || snakeY == 10)) {
		gameover = true;
	}
	
	for (int n = 1; n < tail; n++) {
		if (snakeX == tailX[n] && snakeY == tailY[n])
			gameover = true;
	}
	
	
}

void input() {

	if (_kbhit) { // takes in WASD input which then changes snake head coordinates
		switch (_getch())
		{
		case 'w':
			snakeY--;
			break;
		case 'a':
			snakeX--;
			break;
		case 's':
			snakeY++;
			break;
		case 'd':
			snakeX++;
			break;

		}
	}


}


int main() {
	
	srand(time(NULL)); // include randomness
	
	fruitX = rand() % (19 + 1); // generate first fruit coordinates
	fruitY = rand() % (9 + 0);
	snakeX = 9;
	snakeY = 5;

	while (!gameover) {
		
		draw();

		setup();
		

		
		
		input();
		logic();


	}
}