#include <stdio.h>
#include <stdbool.h>

// Define the states using an enum
typedef enum {
    STATE_GREEN,
    STATE_YELLOW,
    STATE_RED
} State;

// Function to handle outputs based on the current state
void output_function(State current_state) {
    switch (current_state) {
        case STATE_GREEN:
            printf("Green Light ON\n");
            break;
        case STATE_YELLOW:
            printf("Yellow Light ON\n");
            break;
        case STATE_RED:
            printf("Red Light ON\n");
            break;
    }
}

// Function to determine the next state
State next_state_function(State current_state, bool timer_expired) {
    if (!timer_expired) {
        return current_state; // Stay in the current state if timer hasn't expired
    }

    switch (current_state) {
        case STATE_GREEN:
            return STATE_YELLOW;
        case STATE_YELLOW:
            return STATE_RED;
        case STATE_RED:
            return STATE_GREEN;
        default:
            return STATE_GREEN; // Fallback to initial state
    }
}

int main() {
    State current_state = STATE_GREEN; // Initial state
    bool timer_expired = false;
    int cycle_count = 0;
    const int cycles_per_state = 3; // Simulate time duration (3 cycles per state)

    printf("Starting Traffic Light Simulation...\n");

    // Simulate 15 clock cycles
    for (int i = 0; i < 15; i++) {
        printf("Cycle %d: ", i + 1);

        // Generate output based on current state
        output_function(current_state);

        // Simulate timer logic
        cycle_count++;
        if (cycle_count >= cycles_per_state) {
            timer_expired = true;
            cycle_count = 0; // Reset counter
        } else {
            timer_expired = false;
        }

        // Calculate next state (synchronous update)
        current_state = next_state_function(current_state, timer_expired);
    }

    return 0;
}