#include <bits/stdc++.h>
using namespace std;
const int numGridPoints = 10; // Number of grid points
const double deltaX = 1.0;    // Grid spacing in the x-direction
const double deltaT = 0.1;    // Time step size

void solveMomentumEquation(double u[])
{
    double uNew[numGridPoints] = {}; // Array to store the updated velocity values

    // Constants
    const double rho = 1.0; // Density
    const double mu = 0.1;  // Dynamic viscosity

    // Define the pressure gradient
    const double dP_dx = 0.1; // Pressure gradient

    // Update the velocity at each grid point
    for (int i = 1; i < numGridPoints - 1; i++)
    {
        // Calculate the convective term
        double convective_term = rho * (u[i] * (u[i] - u[i - 1])) / deltaX;

        // Calculate the diffusive term
        double diffusive_term = mu * (u[i + 1] - 2 * u[i] + u[i - 1]) / (deltaX * deltaX);

        // Update the velocity using the equation
        uNew[i] = u[i] + (deltaT * (convective_term + diffusive_term - dP_dx)) / rho;
    }

    // Update the velocity array with the new values
    for (int i = 1; i < numGridPoints - 1; i++)
    {
        u[i] = uNew[i];
    }
}

int main()
{
    // Initialize velocity array
    double u[numGridPoints] = {0.0}; // Initial velocity

    // Solve the momentum equation iteratively
    for (int n = 0; n < 10; n++) // Number of time steps
    {
        solveMomentumEquation(u);
    }

    // Print the final velocity values
    cout << "Final Velocity Values:" << endl;
    for (int i = 0; i < numGridPoints; i++)
    {
        cout << "u[" << i << "] = " << u[i] << endl;
    }

    return 0;
}
