/*
 * Race Simulator
 *
 * Simulates a two-car digital race using C structures.
 * Prints an intro and countdown, runs 5 laps, announces the leader after each lap,
 * and congratulates the winner at the end.
 * Each lap time is randomized as the sum of speed, acceleration, and nerves (1–3 each).
 * Data types: struct Race (race state) and struct RaceCar (driver, car color, totalLapTime).
 * Entry flow: printIntro() → printCountDown() → startRace(&car1, &car2).
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section

struct Race {
    int numberOfLaps;
    int currentLap;
    char *firstPlaceDriverName;
    char *firstPlaceRaceCarColor;
};
struct RaceCar {
    char *driverName;
    char *raceCarColor;
    int totalLapTime;
};

// Print functions section

void printIntro(void) {
    printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}
void printCountDown(void) {
    printf("Racers Ready! In...\n5\n4\n3\n2\n1\n");
}
void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %d\nFirst Place is: %s in the %s race car\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToComplete(void) {
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
}
void updateRaceCar(struct RaceCar *raceCar) {
    raceCar->totalLapTime += calculateTimeToComplete();
}
void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        race->firstPlaceDriverName = raceCar1->driverName;
        race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    } else {
        race->firstPlaceDriverName = raceCar2->driverName;
        race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2) {
    struct Race race = {5, 1, "", ""};
    for (int i = 0; i < race.numberOfLaps; i++) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    }
    printCongratulation(race);
}

int main() {
	srand(time(0));
    printIntro();
    printCountDown();
    
    struct RaceCar raceCar1 = {"Barreiro", "Navy Blue", 0};
    struct RaceCar raceCar2 = {"Castro", "Barbie Pink", 0};
    
    startRace(&raceCar1, &raceCar2);
    return 0;
};