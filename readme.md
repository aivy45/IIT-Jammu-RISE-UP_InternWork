# This is my work as a RISE UP Intern in IIT Jammu under Dr. Harish Pothukuchi !

#### It is a summer research Intern where I have to work on One Dimensional subchannel analysis on two fluid model in two phases in PVR.

#### Mainly I am converting 3D equations of Navier Stokes Equations in two fluid model in 1D by using SIMPLE (Semi - Implicit Method for Pressure Linked Equations) method.

### There are total three equations:

## 1. Continuity Equation

#### The continuity equation in one dimension is:

- The continuity equation is based on conservation of mass
- The law of conservation of mass states that mass cannot be created or destroyed.
- means that the total mass of a fluid must remain constant over time.
- The continuity equation is a fundamental equation in fluid dynamics.

  - ∂ρ/∂t + (∂(ρv) )/∂x = 0
    - ρ is the density of the fluid
    - v is the velocity of the fluid
    - t is the time
    - x is the spatial coordinate

## Momentum Equation

- It represents a form of the Navier-Stokes equation, which is a fundamental equation governing the motion of fluid.
- This specific equation is a simplified form that describes the conservation of momentum in the x-direction for an incompressible fluid.

- The momentum equation in one dimension is:

  - ρ [ ∂(u)/∂t+ u∂(u)/∂x ]= - ∂(P)/∂x +( μ ∂^2 u )/(∂x^2 )+ ρg

    - ρ=density of the fluid
    - P= Pressure
    - u=velocity component along x axis,
    - μ= dynamic viscosity of fluid
    - t= time

## Energy Equation

- It represents a form of the Navier-Stokes equation, which is a fundamental equation governing the motion of fluid.
- The rate of change of energy in a system is equal to the sum of the work done by the pressure, the heat flux and any other sources of energy.

- The Energy equation in one dimension is:

  - ρc_p [ ∂(T)/∂t+ u∂(T)/∂x ]= -P ∂(u)/∂x +∂/∂x(k\*∂(T)/∂x) + q

    -     ρ:        Density of the material
    -     Cp:      Specific heat capacity of the material
    -     T:        Temperature of the material
    -     t:         Time
    - u: Velocity of the fluid (in the x-direction)
    - x: Spatial coordinate (in the x-direction)
    -     P:       Pressure gradient in the x-direction
    - k: Thermal conductivity of the material
    - q: Heat source term
