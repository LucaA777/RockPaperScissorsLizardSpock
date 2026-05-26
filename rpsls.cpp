/*
A text based version of Rock Paper Scissors Lizard Spock by Sam Kass featured in The Big Bang Theory

Author: Luca Ardanaz
*/

#include <iostream>
#include <random>

using namespace std;

enum Play {
	ROCK = 0,
	LIZARD,
	SPOCK,
	SCISSORS,
	PAPER
};

enum Result {
	TIE = 0,
	P1,
	P2
};

Play randomMove() {
	//setup random number
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 4);

	//pick a random play
	return static_cast<Play>(distr(gen));
}

Result getResult(Play p1, Play p2) {
	//using modular arithmetic to calculate the result
	int result = (p1 - p2) % 5;

	//result meaning:
	//0: tie
	//1-2: p1 wins
	//3-4: p2 wins 
	return static_cast<Result>((result + 1) / 2);
}

int main() {
	
	enum Play p1, p2;
	enum Result result;

	p1 = randomMove();
	p2 = randomMove();

	cout << "P1: " << p1 << endl;		
	cout << "P2: " << p2 << endl;		
	
	result = getResult(p1, p2);

	cout << "Result: " << result << endl;
	
	return 0;
}



