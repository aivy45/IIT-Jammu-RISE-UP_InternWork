#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
// Constants
const double deltaX = 0.1;     // Grid spacing
const double deltaT = 0.01;    // Time step
const double tolerance = 3;    // Convergence tolerance
const int maxIterations = 100; // Maximum number of iterations
const int lambda = 111;
const int c_p = 20;

// Function to solve the SIMPLE algorithm for energy equation
void solveSIMPLE()
{
    // Define variables
    int numCells = 10;            // Number of cells
    double rho[numCells];         // Density
    double u[numCells];           // Velocity
    double P[numCells];           // Pressure
    double Pcorrection[numCells]; // Pressure correction
    double T[numCells];           // Temperature
    bool converged = false;       // Convergence flag

    // Initialize variables
    for (int i = 0; i < numCells; i++)
    {
        rho[i] = 1.0; // Initial density
        u[i] = 1.0;   // Initial velocity
        P[i] = 4.0;   // Initial pressure
        // Pcorrection[i] = 3.0; // Initial pressure correction
        T[i] = 6.0; // Initial temperature
    }

    // Main loop
    for (int iteration = 0; iteration < maxIterations; iteration++)
    {
        // Predictor step: solve momentum equation
        for (int i = 1; i < numCells - 1; i++)
        {
            // double uStar = u[i] - (deltaT / (rho[i] * deltaX)) * (P[i + 1] - P[i]);

            // Calculate temperature advection term
            double advTerm = u[i] * (T[i] - T[i - 1]) / deltaX;

            // Calculate temperature diffusion term
            double diffTerm = (deltaT * lambda / (rho[i] * c_p * deltaX * deltaX)) * (T[i + 1] - 2.0 * T[i] + T[i - 1]);

            // Calculate temperature source term (if applicable)
            // double sourceTerm = Q[i] * deltaT / (rho[i] * c_p);

            // Temperature prediction
            T[i] = T[i] - advTerm + diffTerm;
        }

        // Pressure correction equation
        for (int i = 1; i < numCells - 1; i++)
        {
            Pcorrection[i] = (deltaX * deltaX / deltaT) * ((u[i] - u[i - 1]) / deltaX - (u[i + 1] - u[i]) / deltaX);

            // Continuity equation (optional if density is constant)
            rho[i] = rho[i] - (deltaT / deltaX) * (rho[i] * u[i] - rho[i - 1] * u[i - 1]);
        }

        // Update pressure
        for (int i = 1; i < numCells - 1; i++)
        {
            P[i] += Pcorrection[i];
        }

        // Corrector step: update velocity and temperature
        for (int i = 1; i < numCells - 1; i++)
        {
            u[i] = u[i] - (deltaT / (rho[i] * deltaX)) * (P[i + 1] - P[i]);

            // Calculate temperature advection term
            double advTerm = u[i] * (T[i] - T[i - 1]) / deltaX;

            // Calculate temperature diffusion term
            double diffTerm = (deltaT * lambda / (rho[i] * c_p * deltaX * deltaX)) * (T[i + 1] - 2.0 * T[i] + T[i - 1]);

            // Calculate temperature source term (if applicable)
            // double sourceTerm = Q[i] * deltaT / (rho[i] * c_p);

            // Temperature correction
            T[i] = T[i] - advTerm + diffTerm;
        }

        // Check for convergence
        double maxChange = 0.0;
        for (int i = 1; i < numCells - 1; i++)
        {
            double change = abs(Pcorrection[i]);
            if (change > maxChange)
            {
                maxChange = change;
            }
        }

        if (maxChange < tolerance)
        {
            converged = true;
            break;
        }
    }

    // Print results
    if (converged)
    {
        cout << "Convergence achieved!" << endl;
    }
    else
    {
        cout << "Convergence not achieved!" << endl;
    }

    cout << "Temperature: ";
    for (int i = 0; i < numCells; i++)
    {
        cout << T[i] << " ";
    }
    cout << endl;

    cout << "Velocity: ";
    for (int i = 0; i < numCells; i++)
    {
        cout << u[i] << " ";
    }
    cout << endl;

    cout << "Pressure: ";
    for (int i = 0; i < numCells; i++)
    {
        cout << P[i] << " ";
    }
    cout << endl;
}

int main()
{
    solveSIMPLE();

    return 0;
}
