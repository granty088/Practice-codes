/* DE GUZMAN M-3L*/

#include <stdio.h>
#include <stdlib.h>   /* for exit() */

#define SIZE 10          
#define PASSING_SCORE 75 
#define MIN_SCORE 0      
#define MAX_SCORE 100    

/* Clears leftover characters in the input buffer (e.g., letters typed by mistake) */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* keep reading until the end of the line */
    }
}

/* Error handling: keeps asking until a whole number from MIN_SCORE to MAX_SCORE is entered */
int readScore(int studentNumber) {
    int score;

    while (1) {
        printf("Enter score of Student %d (%d-%d): ", studentNumber, MIN_SCORE, MAX_SCORE);

        int result = scanf("%d", &score);   /* scanf returns 1 only if an integer was read */

        if (result == EOF) {                /* input stream closed: stop instead of looping forever */
            printf("\nError: no more input available. Exiting program.\n");
            exit(1);
        } else if (result != 1) {
            printf("  Error: invalid input. Please enter a whole number.\n");
            clearInputBuffer();
        } else if (score < MIN_SCORE || score > MAX_SCORE) {
            printf("  Error: score must be between %d and %d.\n", MIN_SCORE, MAX_SCORE);
            clearInputBuffer();
        } else {
            clearInputBuffer();
            return score;   /* valid score */
        }
    }
}

/* Traverses an array of student indices using pointer dereferencing: *(ptr + i) == ptr[i]
   'group' holds the index of each student, 'scores' is used to look up their score */
void traverseGroup(int *group, int count, int *scores) {
    if (count == 0) {
        printf("None.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        int studentIndex = *(group + i);                 /* dereference to get the student's index */
        printf("Student %2d: %d\n", studentIndex + 1, *(scores + studentIndex));
    }
}

int main(void) {
    int scores[SIZE] = {0};     /* scores of the 10 students (initialized to zeros) */
    int passed[SIZE] = {0};     /* indices of students who passed */
    int failed[SIZE] = {0};     /* indices of students who did not pass */
    int passedCount = 0;        /* how many slots of passed[] are used */
    int failedCount = 0;        /* how many slots of failed[] are used */
    int sum = 0;
    int highest, lowest;
    double average;

    /* number of elements = total bytes / bytes of one element */
    int arraySize = sizeof(scores) / sizeof(scores[0]);

    /* ---------- INPUT ---------- */
    printf("=== Student Score Recorder ===\n");
    for (int i = 0; i < arraySize; i++) {
        scores[i] = readScore(i + 1);
    }

    /* ---------- PROCESSING ---------- */
    highest = scores[0];        /* start with the first score, then compare */
    lowest = scores[0];

    for (int i = 0; i < arraySize; i++) {
        sum += scores[i];
        if (scores[i] > highest) highest = scores[i];
        if (scores[i] < lowest)  lowest = scores[i];

        /* sort each student into the passed or failed array */
        if (scores[i] >= PASSING_SCORE) {
            passed[passedCount++] = i;
        } else {
            failed[failedCount++] = i;
        }
    }
    average = (double) sum / arraySize;   /* cast so the division keeps decimals */

    /* ---------- OUTPUT ---------- */
    printf("\n=== All Scores Entered ===\n");
    for (int i = 0; i < arraySize; i++) {
        printf("Student %2d: %d\n", i + 1, scores[i]);
    }

    printf("\nAverage score : %.2f\n", average);
    printf("Highest score : %d\n", highest);
    printf("Lowest score  : %d\n", lowest);

    printf("\n=== Students Who Passed (>= %d) ===\n", PASSING_SCORE);
    traverseGroup(passed, passedCount, scores);

    printf("\n=== Students Who Did Not Pass (< %d) ===\n", PASSING_SCORE);
    traverseGroup(failed, failedCount, scores);

    return 0;
}