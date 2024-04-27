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

float Rate() {
	float array[] = { 1.0, 1.25, 1.5, 1.75, 2.0, 2.25, 2.5, 2.75, 3.0, 3.25, 3.5, 3.75, 4.0 };
	srand(time(0));
	int index = rand() % 13;
	float rate = array[index];
	return rate;
}

bool Walk(float f) {
	bool walk = false;
	float walkRate = Rate();

	if (walkRate < f) {
		walk = true;
		return walk;
	}

	return walk;
}

bool Hit(float f) {
	bool hit = false;
	float hitRate = Rate();

	if (hitRate < f) {
		hit = true;
		return hit;
	}

	return hit;
}

bool Double(float f) {
	float doubleRate = Rate();
	bool doubleHit = false;

	if (doubleRate < f && firstBase == true) {
		thirdBase = true;
		secoundBase = true;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate < f && firstBase == true && secoundBase == true) {
		thirdBase = true;
		secoundBase = true;
		score += 1;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate < f && firstBase == true && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		firstBase = false;
		score += 2;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate < f && firstBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		score += 1;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate < f && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		secoundBase = true;
		firstBase = false;
		score += 2;
		doubleHit = true;
		return doubleHit;
	}
	else if (doubleRate < f) {
		secoundBase = true;
		doubleHit = true;
		return doubleHit;
	}
	else {
		return doubleHit;
	}
}

bool Triple(float f) {
	float tripleRate = Rate();
	bool triple = false;

	if (tripleRate < f && firstBase == true) {
		thirdBase = true;
		score += 1;
		triple = true;
		return triple;
	}
	else if (tripleRate < f && firstBase == true && secoundBase == true) {
		thirdBase = true;
		score += 2;
		triple = true;
		return triple;
	}
	else if (tripleRate < f && firstBase == true && secoundBase == true && thirdBase == true) {
		thirdBase = true;
		score += 3;
		triple = true;
		return triple;
	}
	else if (tripleRate < f && firstBase == true && thirdBase == true) {
		thirdBase = true;
		score += 2;
		triple = true;
		return triple;
	}
	else if (tripleRate < f && secoundBase == true && thirdBase == true) {
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
	float homeRate = Rate();
	bool homeRun = false;

	if (homeRate < f && firstBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && firstBase == true && secoundBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && firstBase == true && secoundBase == true && thirdBase == true) {
		score += 4;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && firstBase == true && thirdBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && secoundBase == true && thirdBase == true) {
		score += 3;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && secoundBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f && thirdBase == true) {
		score += 2;
		homeRun = true;
		return homeRun;
	}
	else if (homeRate < f) {
		score += 1;
		homeRun = true;
		return homeRun;
	}
	else {
		return homeRun;
	}
}

bool StrikeOut(float f) {
	float strikeOutRate = Rate();
	bool strikeout = false;
	if (strikeOutRate < f) {
		teamOuts -= 1;
		strikeout = true;
		return strikeout;
	}
	return strikeout;
}

bool GroundOut(float f) {
	float groundOutRate = Rate();
	bool groundOut = false;
	srand(time(0));
	int ground = rand() % 10;

	if (groundOutRate < f) {

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
	float flyout = Rate();
	bool flyOut = false;

	if (flyout < f && firstBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && firstBase == true && secoundBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		thirdBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && firstBase == true && secoundBase == true && thirdBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		thirdBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && firstBase == true && thirdBase == true) {
		teamOuts -= 1;
		secoundBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && secoundBase == true) {
		teamOuts -= 1;
		thirdBase = true;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && thirdBase == true) {
		teamOuts -= 1;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f && thirdBase == true && secoundBase == true) {
		teamOuts -= 1;
		thirdBase = true;
		score += 1;
		flyOut = true;
		return flyOut;
	}
	else if (flyout < f) {
		teamOuts -= 1;
		flyOut = true;
		return flyOut;
	}
	return flyOut;
}

bool PopUp(float f) {
	float popOutRate = Rate();
	bool popOut = false;

	if (popOutRate < f) {
		teamOuts -= 1;
		popOut = true;
		return popOut;
	}
	return popOut;
}

bool LineDrive(float f) {
	float  lineDriveRate = Rate();
	bool lineDrive = false;

	if (lineDriveRate < f) {
		teamOuts -= 1;
		lineDrive = true;
		return lineDrive;
	}
	return lineDrive;
}

void Hitter() {
	bool walk = Walk(1);
			bool hit = Hit(2.66);

			if (walk == true) {
				firstBase = true;
				printf("Walk!\n");
			}
			else if (hit == true) {
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
					firstBase = true;
					printf("Hit!\n");
				}
			}
			else if (hit == false) {
				bool strike = StrikeOut(2.18);
				if (strike == true) {
					printf("Strike :(\n");
				}
				bool ground = GroundOut(3.28);
				if (strike == false && ground == true) {
					printf("Ground Out :(\n");
				}
				bool fly = FlyOut(2.13);
				if (fly == true && strike == false && ground == false) {
					printf("Fly Out :(\n");
				}
				bool line = LineDrive(3.28);
				if (line == true && strike == false && fly == false && ground == false) {
					printf("Line Drive :(\n");
				}
				bool pop = PopUp(0.33);
				if (pop == true && strike == false && fly == false && line == false && ground == false) {
					printf("Popup :(\n");
				}
			}
}

