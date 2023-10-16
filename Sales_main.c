/* @Author: Liam Aga
 * KU ID: 3050093
 * Created: 10/14/23
 * Last Edited: 10/15/23 6:00pm
 * Lab 5 Sales Report: Reads monthly sales from an input file, displays a detailed report with sales statistics,
 * calculates the six-month moving average, and lists monthly sales from highest to lowest.
 */

#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

// Define constant array to hold month names
const char *months[MONTHS] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
};

// Function prototypes
void readSales(double sales[]);
void displaySalesReport(const double sales[]);
double getMinimumSales(const double sales[], int *index);
double getMaximumSales(const double sales[], int *index);
double getAverageSales(const double sales[]);
void displayMovingAverage(const double sales[]);
void displaySortedSales(const double sales[]);

int main() {
    double sales[MONTHS];
    int minIndex, maxIndex;
    double minSales, maxSales, averageSales;

    // Read sales from input file
    readSales(sales);

    // Display the sales report
    displaySalesReport(sales);

    // Compute minimum, maximum, and average sales
    minSales = getMinimumSales(sales, &minIndex);
    maxSales = getMaximumSales(sales, &maxIndex);
    averageSales = getAverageSales(sales);

    // Print the sales summary
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, months[minIndex]);
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, months[maxIndex]);
    printf("Average sales: $%.2lf\n", averageSales);

    // Display the six-month moving average
    displayMovingAverage(sales);

    // Display sales sorted from highest to lowest
    displaySortedSales(sales);

    return 0;
}

// Function to read sales data from input.txt
void readSales(double sales[]) {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }
    fclose(file);
}

// Function to display sales for each month
void displaySalesReport(const double sales[]) {
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", months[i], sales[i]);
    }
}

// Function to compute and return minimum sales
double getMinimumSales(const double sales[], int *index) {
    double min = sales[0];
    *index = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            *index = i;
        }
    }
    return min;
}

// Function to compute and return maximum sales
double getMaximumSales(const double sales[], int *index) {
    double max = sales[0];
    *index = 0;
    for (int i = 1; i < MONTHS; i++) {
        if (sales[i] > max) {
            max = sales[i];
            *index = i;
        }
    }
    return max;
}

// Function to compute and return average sales
double getAverageSales(const double sales[]) {
    double sum = 0;
    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];
    }
    return sum / MONTHS;
}

// Function to compute and display six-month moving averages
void displayMovingAverage(const double sales[]) {
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s - %s $%.2lf\n", months[i], months[i + 5], sum / 6);
    }
}

// Function to sort and display sales in descending order
void displaySortedSales(const double sales[]) {
    double sortedSales[MONTHS];
    const char *sortedMonths[MONTHS];
    int i, j;

    // Copy sales data to sorted arrays
    for (i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    // Use Bubble Sort to sort the sales data in descending order
    for (i = 0; i < MONTHS - 1; i++) {
        for (j = 0; j < MONTHS - i - 1; j++) {
            if (sortedSales[j] < sortedSales[j + 1]) {
                double tempSale = sortedSales[j];
                sortedSales[j] = sortedSales[j + 1];
                sortedSales[j + 1] = tempSale;

                const char *tempMonth = sortedMonths[j];
                sortedMonths[j] = sortedMonths[j + 1];
                sortedMonths[j + 1] = tempMonth;
            }
        }
    }

    // Print the sorted sales data
    printf("\nSales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (i = 0; i < MONTHS; i++) {
        printf("%-10s $%.2lf\n", sortedMonths[i], sortedSales[i]);
    }
}
