#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    // User input for iteration count.
    int iter_cnt;
    // success count for sampled P(Hit).
    int success_cnt = 0;

    double rx;
    double ry;
    double p_hit;
    double pi_est;
    double accepted_range;
    double pi_min;
    double pi_max;

    // pi value for additonal options.
    const double pi = 3.1415926535897;

    // declare ofstream type variable.
    ofstream file;

    cout << endl << "---MC Estimation---" << endl;
    cout << "Enter an iteration count: ";
    cin >> iter_cnt;

    // Create text file.
    file.open("output.txt");
    srand(time(0));
    for (int i = 0; i < iter_cnt; i++) {
        // Value of pi can be calculated as 4 * P(hit) where P(hit) is the
        // probability of hitting a quarter circle with radius r within a
        // square with length r.

        // To sample P(hit) create two random variables that take values from
        // 0 to r and compare if it is less than or equal to r.

        // Note that since your sample range and success threshold is r we can
        // simplify this to just take values from 0 to 1.
        rx = rand() / double(RAND_MAX);
        ry = rand() / double(RAND_MAX);

        // if P(Hit) increase success_cnt.
        if ( rx*rx + ry*ry <= 1 ) {
            success_cnt++;
        }

        // Write random values to output.txt.
        file << rx << "\t" << ry << "\n";
    }

    // Calculate the sampled success rate.
    // Cast one integer as double to allow for decimal value.
    p_hit = success_cnt / (double)iter_cnt;
    pi_est = 4 * p_hit;
    cout << "The MC sampled estimate of pi is: " << pi_est << endl << endl;

    cout << "---Option---" << endl;
    // Reset iteration count, success count, and pi estimation.
    iter_cnt = 0;
    success_cnt = 0;
    pi_est = 0;

    // Ask user for acceptable +- range estimate of pi.
    cout << "Enter an acceptable +- range estimate for pi: ";
    cin >> accepted_range;

    // Not sure if we're allowed to use abs function so just check for user
    // negative input.
    if ( accepted_range < 0 ) {
        pi_min = pi + accepted_range;
        pi_max = pi - accepted_range;
    } else {
        pi_min = pi - accepted_range;
        pi_max = pi + accepted_range;
    }

    // Calculate pi_est until withing acceptable_range.
    while ( pi_est >= pi_max or pi_est <= pi_min ) {
        iter_cnt++;
        rx = rand() / double(RAND_MAX);
        ry = rand() / double(RAND_MAX);

        // if P(Hit) increase success_cnt.
        if ( rx*rx + ry*ry <= 1 ) {
            success_cnt++;
        }
        p_hit = success_cnt / (double)iter_cnt;
        pi_est = 4 * p_hit;
    }
    cout << "It took " << iter_cnt << " tries to estimate pi within +-" << accepted_range << endl;


    return 0;
}

