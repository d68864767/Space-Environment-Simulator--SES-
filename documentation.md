# Space Environment Simulator (SES) - Documentation

This document provides a comprehensive guide to the Space Environment Simulator (SES), a device designed to simulate various space environmental conditions on Earth. The SES is primarily intended for testing space-bound electronic components and can also be used for educational demonstrations.

## Schematic Design

The schematic design of the SES includes circuits for temperature control, radiation simulation, and sensor integration. A microcontroller unit (MCU) is also included to control and monitor the system. The schematic design file can be found as `schematic_design.sch`.

## PCB Design

The PCB design of the SES is a multi-layer design that accommodates the control circuits. The design accounts for thermal management and radiation shielding. The PCB design file can be found as `pcb_design.kicad_pcb`.

## Custom Components and Libraries

The SES uses custom components like specialized sensors or radiation sources. Custom symbols and footprints for these components are created and can be found in the `custom_components.lib` file.

## Simulation and Testing

The SES undergoes extensive simulation and testing to ensure its functionality and safety. The simulation and testing procedures are documented in the `simulation_testing.md` file.

## Bill of Materials (BOM)

The BOM includes all the components used in the SES. It provides details about each component, including its specifications and quantity used. The BOM is as follows:

- Temperature Control Circuit Components
- Radiation Simulation Circuit Components
- Sensor Integration Circuit Components
- Microcontroller Unit (MCU)
- PCB Materials
- Custom Components (as per `custom_components.lib`)

## User Manual

The user manual provides a step-by-step guide on how to operate the SES. It includes instructions on how to control the temperature, simulate radiation, and create a vacuum. It also provides guidelines on how to interpret the sensor readings and troubleshoot common issues.

## Challenges and Considerations

The design and development of the SES involve several challenges and considerations. These include ensuring the safety and reliability of the simulator under extreme conditions and integrating the electronic controls with the physical components like the vacuum chamber and thermal elements. These challenges and considerations are documented in the `challenges_considerations.md` file.

## MCU Code

The MCU code controls and monitors the system. It includes code for controlling the temperature, simulating radiation, creating a vacuum, and reading sensor data. The MCU code can be found in the `mcu_code.c` file.

## Final Steps

After the design, simulation, and testing phases, the SES is ready for use. It can be used for testing and validating space-bound electronics or as an educational tool to demonstrate space conditions.
