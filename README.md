# Free Fall: Low-Cost Experimental Setup for Physics Education

This repository provides all the necessary resources to build and implement a low-cost experimental setup for investigating free fall motion using an Arduino Uno, infrared photogate, and spreadsheet-based data acquisition via PLX-DAQ. Designed with a strong educational focus, this hands-on project supports a STEM-oriented approach to teaching kinematics.


## Repository Contents

- `Free_Fall.ino`: Arduino sketch responsible for real-time time-stamp acquisition during the fall.
- `Free Fall.xlsm`: Excel spreadsheet with embedded macros and a custom PLX-DAQ interface for visualization and analysis.
- `Supplementary material.pdf`: Construction details for the photogate, circuit diagrams, experimental procedures, and additional documentation.

## Requirements

- **Software**
  - Arduino IDE
  - Microsoft Excel (with macro support)
  - Modified PLX-DAQ (integrated into `Free Fall.xlsm`)

##  Assembly and Setup

1. **Build the Photogate**  
   Use a U-shaped acrylic piece to mount the IR LED and phototransistor. See *Supplementary material.pdf*, Figure S1 (page 1), for detailed dimensions and wiring.

2. **Connect the Circuit**  
   Wire the components as described in the electrical schematic (Figure S2, page 2). The photogate output goes to pin D2 of the Arduino.

3. **Upload the Code**  
   Open `Free_Fall.ino` in the Arduino IDE and upload it to the board.

4. **Run the Experiment**
   - Launch Excel and open `Free Fall.xlsm`.
   - Connect to the correct COM port.
   - Press the control buttons ("A", "B", "C", "D") to run, clear, or compare datasets.
   - Drop the flag through the photogate vertically (see Figure S5 for proper alignment).

##  Data Analysis

The spreadsheet automatically generates time vs. distance plots. Using curve fitting tools in Excel, students can verify the quadratic relationship of free fall motion and confirm the constancy of gravitational acceleration.

##  Educational Benefits

This experiment encourages:
- Conceptual conflict resolution (misconceptions about mass and gravity)
- Engagement through real-time feedback
- Integration of physics and technology (Arduino, programming, data visualization)

##  Customization

The Excel interface allows users to:
- Adjust measurement parameters
- Modify labels and input values via the **Settings** sheet
- Trigger custom commands via macro buttons

##  License

This project is open-source and free to use for educational and research purposes. Contributions are welcome!
