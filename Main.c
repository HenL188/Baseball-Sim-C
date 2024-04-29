#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Main.h"
#include "GlobalVariables.h"

int main() {
	
	printf("Calculating...\n");
	while (teamOuts > 0)
	{
		while (teamOuts > 24) {
			Hitter();
		}
		while (teamOuts > 21) {
			Hitter();
		}
		while (teamOuts > 18) {
			Hitter();
		}
		while (teamOuts > 15) {
			Hitter();
		}
		while (teamOuts > 12) {
			Hitter();
		}
		while (teamOuts > 9) {
			Hitter();
		}
		while (teamOuts > 6) {
			Hitter();
		}
		while (teamOuts > 3) {
			Hitter();
		}
		while (teamOuts <= 3  && teamOuts > 0) {
			Hitter();
		}
	}
	printf("Score:%d", score);
}

bool Walk(float f) {
	bool walk = false;
	srand(time(0));
	int walkRate = rand() % 100;

	if (walkRate <= f) {
		walk = true;
		return walk;
	}

	return walk;
}

bool Hit(float f) {
	bool hit = false;
	srand(time(0));
	int hitRate = rand() % 100;

	if (hitRate <= f) {
		hit = true;
		return hit;
	}

	return hit;
}

bool Double(float f) {
	bool doubleHit = false;
	srand(time(0));
	int doubleRate = rand() % 100;

	if (doubleRate <= f && firstBase == true) {
		thirdBase = true;
		secoundBase = true;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate <= f && firstBase == true && secoundBase == true) {
		thirdBase = true;
		secoundBase = true;
		score += 1;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate <= f && firstBase == true && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		firstBase = false;
		score += 2;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate <= f && firstBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		score += 1;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate <= f && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		firstBase = false;
		score += 2;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate <= f) {
		secoundBase = true;
		doubleHit = true;
		return doubleHit;
	}
	else {
		return doubleHit;
	}
}

bool Triple(float f) {
	bool triple = false;
	srand(time(0));
	int tripleRate = rand() % 100;

	if (tripleRate <= f && firstBase == true) {
		thirdBase = true;
		score += 1;
		triple = true;
		return triple;
	}
	else if (tripleRate <= f && firstBase == true && secoundBase == true) {
		thirdBase = true;
		score += 2;
		triple = true;
		return triple;
	}
	else if (tripleRate <= f && firstBase == true && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		score += 3;
		triple = true;
		return triple;
	}
	else if (tripleRate <= f && firstBase == true && thirdBase == true) {
		thirdBase = true;
		score += 2;
		triple = true;
		return triple;
	}
	else if (tripleRate <= f && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		score += 2;
		triple = true;
		return triple;
	}
	else if (tripleRate == true) {
		thirdBase = true;
		triple = true;
		return triple;
	}
	else {
		return triple;
	}
}

bool HomeRun(float f) {
	bool homeRun = false;
	srand(time(0));
	int homeRate = rand() % 100;

	if (homeRate <= f && firstBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && firstBase == true && secoundBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && firstBase == true && secoundBase == true && thirdBase == true) {
		score += 4;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && firstBase == true && thirdBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && secoundBase == true && thirdBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && secoundBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f && thirdBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate <= f) {
		score += 1;
		homeRun = true;
		return homeRun;
	}
	else {
		return homeRun;
	}
}

bool StrikeOut(float f) {
	bool strikeout = false;
	srand(time(0));
	int strikeOutRate = rand() % 100;
	if (strikeOutRate <= f) {
		teamOuts -= 1;
		strikeout = true;
		return strikeout;
	}
	return strikeout;
}

bool GroundOut(float f) {
	bool groundOut = false;
	srand(time(0));
	int groundOutRate = rand() % 100;
	srand(time(0));
	int ground = rand() % 10;

	if (groundOutRate <= f) {

		if (firstBase == true && ground <= 1) {
			firstBase = false;
			teamOuts -= 2;
			groundOut = true;
			return groundOut;
			teamOuts -= 1;
		}
		return groundOut;
	}
}

bool FlyOut(float f) {
	bool flyOut = false;
	srand(time(0));
	int flyout = rand() % 100;

	if (flyout <= f && firstBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && firstBase == true && secoundBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		thirdBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && firstBase == true && secoundBase == true && thirdBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		thirdBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && firstBase == true && thirdBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && secoundBase == true) {
		teamOuts -= 1;
		thirdBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && thirdBase == true) {
		teamOuts -= 1;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f && thirdBase == true && secoundBase == true) {
		teamOuts -= 1;
		thirdBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout <= f) {
		teamOuts -= 1;
		flyOut = true;
		return flyOut;
	}
	return flyOut;
}

bool PopUp(float f) {
	bool popOut = false;
	srand(time(0));
	int popOutRate = rand() % 100;

	if (popOutRate <= f) {
		teamOuts -= 1;
		popOut = true;
		return popOut;
	}
	return popOut;
}


void Hitter() {
	bool walk = Walk(8);
	bool hit = Hit(26.6);

	if (walk == true) {
		firstBase = true;
		printf("Walk!\n");
	}
	if (hit == true) {
		bool doubleHit = Double(1.5);
		bool triple = Triple(1.5);
		bool homeRun = HomeRun(1.5);
		if (doubleHit == true) {
			printf("Double!\n");
		}
		else if (triple == true) {
			printf("Triple!\n");
		}
		else if (homeRun == true) {
			printf("Home Run!\n");
		}
		else
		{
			printf("Hit!\n");
			if (firstBase == true) {
				secoundBase = true;
				firstBase = true;
			}
			else if (firstBase == true && secoundBase == true) {
				thirdBase = true;
				firstBase = true;
			}
			else if (firstBase == true && secoundBase == true && thirdBase == true) {
				firstBase = true;
				secoundBase = true;
				thirdBase = true;
				score += 1;
			}
			else if (firstBase == true && thirdBase == true) {
				firstBase = true;
				secoundBase = true;
				score += 1;
			}
			else if (secoundBase == true && thirdBase == true) {
				thirdBase = true;
				score += 1;
			}
		}
		
		}
	else {
		bool strike = StrikeOut(21.8);
		if (strike == true) {
			printf("Strike :(\n");
		}
		else if (strike == false) {
			bool ground = GroundOut(32.8);
			if (ground == true) {
				printf("Ground Out :(\n");
			}
		}
		else if (strike == false) {
			bool fly = FlyOut(21.3);
			if (fly == true) {
				printf("Fly Out :(\n");
			}
		}
		else if (strike == false) {
			bool pop = PopUp(3.3);
			if (pop == true) {
				printf("Popup :(\n");
			}

		}
		else {
			printf("Line Drive :(\n");
			teamOuts -= 1;
		}
	}
}
