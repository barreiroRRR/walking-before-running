#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section

struct Race {
    int number_of_laps;
    int current_Lap;
    char *first_place_driver_name;
    char *first_place_race_car_color;
};
struct RaceCar {
    char *driver_name;
    char *race_car_color;
    int total_lap_time;
};

// Print functions section
void print_intro(void) {
    printf("Welcome to Formula C!\nThe best event in programming sports!\n");
}
void print_count_down(void) {
    printf("Racers Ready! In...\n5\n4\n3\n2\n1\nCode!\n");
}
void print_first_place_after_lap(struct Race race) {
    printf("After lap number %i\nFirst Place Is: %s in the %s race car!", race.current_Lap, race.first_place_driver_name, race.first_place_race_car_color);
}
void print_congratulations(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a goodnight!\n", race.first_place_driver_name, race.first_place_race_car_color);
}

// Logic functions section
int calculate_time_to_complete(void) {
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
}
void update_race_car(struct RaceCar *raceCar) {
    raceCar->total_lap_time += calculate_time_to_complete();
}
void update_first_place(struct Race *race, struct RaceCar *race_car1, struct RaceCar *race_car2) {
    if (race_car1->total_lap_time <= race_car2->total_lap_time) {
        race->first_place_driver_name = race_car1->driver_name;
        race->first_place_race_car_color = race_car1->race_car_color;
    } else {
        race->first_place_driver_name = race_car2->driver_name;
        race->first_place_race_car_color = race_car2->race_car_color;
    }
}
void start_race(struct RaceCar *race_car1, struct RaceCar *race_car2) {
    struct Race race = {5, 1, "", ""};
    for (int i = 0; i < race.number_of_laps; i++) {
        update_race_car(race_car1);
        update_race_car(race_car2);
        update_first_place(&race, race_car1, race_car2);
        race.current_Lap++;
        print_first_place_after_lap(race);
        }
    print_congratulations(race);
} 

// Main function

int main(void) {
	srand(time(0));
    print_count_down();
    struct RaceCar race_car1 = {"El Rulas", "black", 0};
    struct RaceCar race_car2 = {"YOY", "python", 0};
    start_race(&race_car1, &race_car2);
    
    return (0);
};