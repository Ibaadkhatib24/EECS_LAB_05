#include <stdio.h>

// functions
void monthly_sales_report(double sales[]);
void sales_summary_report(double sales[]);
void six_month_moving_average_report(double sales[]);
void sales_report_high_to_low(double sales[]);

int main() {
    double sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 
                        60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 
                        80950.34, 95225.22};

    // making reports
    monthly_sales_report(sales);
    sales_summary_report(sales);
    six_month_moving_average_report(sales);
    sales_report_high_to_low(sales);

    return 0;
}

// print monthly sales 
void monthly_sales_report(double sales[]) {
    printf("Monthly Sales Report for 2024\n");
    for (int i = 0; i < 12; i++) {
        printf("Month %d: $%.2f\n", i + 1, sales[i]);
    }
    printf("\n");
}

// print sales summary 
void sales_summary_report(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;

    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        sum += sales[i];
    }
    printf("Sales Summary Report:\n");
    printf("Minimum: $%.2f\n", min);
    printf("Maximum: $%.2f\n", max);
    printf("Average: $%.2f\n\n", sum / 12);
}

// print the report
void six_month_moving_average_report(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= 6; i++) {
        double sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("Month %d-%d: $%.2f\n", i + 1, i + 6, sum / 6);
    }
    printf("\n");
}

// print sales report from high to low
void sales_report_high_to_low(double sales[]) {
    double sorted_sales[12];
    for (int i = 0; i < 12; i++) {
        sorted_sales[i] = sales[i];  // Copy sales array
    }

    // sort sales in leastt order
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                double temp = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp;
            }
        }
    }

    printf("Sales Report (Highest to Lowest):\n");
    for (int i = 0; i < 12; i++) {
        printf("Sale: $%.2f\n", sorted_sales[i]);
    }
    printf("\n");
}
