/* @Author: Liam Aga
 * KU ID: 3050093
 * Created: 10/14/23
 * Last Edited: 10/15/23 5:45pm
 * Lab 5 NFL: Give all possibilities of scoring in the NFL when user inputs a whole number integer.
 */

#include <stdio.h>

#define TD_2PT 8    // Touchdown + 2-point conversion
#define TD_1PT 7    // Touchdown + 1-point field goal
#define TD 6        // Touchdown without extra point
#define FG 3        // Field goal
#define SAFETY 2    // Safety

int main() {
    int score;
    int result; // Used to capture scanf result

    // Main loop to keep asking user for scores
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        result = scanf("%d", &score);

        // Check if the input is not an integer
        if (result == 0) {
            printf("Error: Please enter a whole number integer.\n");

            // Clear the input buffer
            while (getchar() != '\n');

            continue;
        }

        // Exit condition
        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays for %d:\n", score);

        // Loop through each possible count of TD + 2-point conversions
        for (int td_2pt = 0; td_2pt * TD_2PT <= score; td_2pt++) {
            // Loop through each possible count of TD + 1-point field goals
            for (int td_1pt = 0; td_1pt * TD_1PT <= score; td_1pt++) {
                // Loop through each possible count of TDs
                for (int td = 0; td * TD <= score; td++) {
                    // Loop through each possible count of field goals
                    for (int fg = 0; fg * FG <= score; fg++) {
                        // Loop through each possible count of safeties
                        for (int safety = 0; safety * SAFETY <= score; safety++) {
                            // Check if current combination matches the desired score
                            if (td_2pt * TD_2PT + td_1pt * TD_1PT + td * TD + fg * FG + safety * SAFETY == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td_2pt, td_1pt, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
