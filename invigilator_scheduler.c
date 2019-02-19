#include <stdio.h>
#include <stdlib.h>

void main() {

    int i, j, k,m;
    int day[5], time[10];
    int assistant[4] = { 0,0,0,0 };
    int x, y, z;

    printf("	-----Welcome to invigilator scheduler-----\n\n");

    // Number of exams
    printf("Enter the number of exams: ");
    scanf("%d", &i);
    printf("\n");
    
    // Days and times for exams
    for (j = 0; j < i; j++) {
        printf("Which day is exam #%d?  ", j + 1);
        scanf("%d", &day[j]);
        printf("What time is exam #%d?  ", j + 1);
        scanf("%d", &time[j]);
        printf("\n");

        // Check the days and times. Days must be between 1-5 and time 9-18
        if (day[j] < 1 || day[j] > 5 || time[j] < 9 || time[j] > 18){
            printf("Day should be 1-5 and time should be 9-18\n\n");
            j -= 1;	// It will show an error message and return back to exam day and time.
        }

        // Check the exam times whether they conflict. Each exam takes 2 hours.
        for (k = 1; k < i; k++){ // i = number of exams
            if ((j > 0) && (day[j] == day[j - 1]) && ((-2 < time[j] - time[j - k]) && (time[j] - time[j - k] < 2))){
                printf("Entered exam time conflicts with another exam.\n\n");
                j -= 1;		// It will show an error message and return back to exam day and time.
            }
        }
    }
    
    y = 1;

    for (j = 0; j < i; j++){		 // i = number of exams
        printf("\nInvigilators for the exam #%d at day #%d %d:00: ", j + 1, day[j], time[j]);
        for (z = 1; z <= 3; z++){
            if (y == 5) { y = 1; }
            if (z == 2) { printf(", Assistant #%d and ", y); }
            else        { printf("Assistant #%d", y); }
            assistant[y-1] += 1;
            y++;
        }
    }

    printf("\n\nNumber of duties :\n");
    for (y = 0, x = 0; y < 4, x < 4; y++, x++){
        printf("Assistant #%d: %d\n", x + 1, assistant[y]);
    }
}