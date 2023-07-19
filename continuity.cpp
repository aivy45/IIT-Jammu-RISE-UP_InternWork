#include <iostream>
#include <vector>
using namespace std;
// Function to solve the continuity equation iteratively
void solveContinuityEquation(vector<double> &density, double velocity, double dt, double dx, int numTimeSteps)
{
    int numPositions = density.size();

    // Create a temporary vector to store the updated density values
    vector<double> newDensity(numPositions);

    // Iterate over the time steps
    for (int step = 0; step < numTimeSteps; ++step)
    {
        // Update the density at each position
        for (int i = 1; i < numPositions - 1; ++i)
        {
            newDensity[i] = density[i] - (dt / dx) * (density[i + 1] * velocity - density[i - 1] * velocity);
        }

        // Assign the updated density values back to the original vector
        density = newDensity;
        int c = 1;
        cout << c << endl;
        c++;
    }
}

int main()
{
    // Set up the parameters and initial conditions
    double dt = 0.01;       // Time step size
    double dx = 0.1;        // Spatial step size (space)
    int numTimeSteps = 100; // Number of time steps
    int numPositions = 10;  // Number of positions

    // Initialize the density vector with initial values
    vector<double> density(numPositions, 0.0);

    // Set the initial density values
    density[numPositions / 2] = 1.0; // Set the density to 1.0 at the middle position

    // Constant velocity
    double velocity = 0.5;

    // Solve the continuity equation
    solveContinuityEquation(density, velocity, dt, dx, numTimeSteps);

    // Print the resulting density at each position
    for (int i = 0; i < numPositions; ++i)
    {
        cout << "Density at position " << i << ": " << density[i] << endl;
    }

    return 0;
}
