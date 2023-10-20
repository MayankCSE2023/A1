# Assignment-1

# Investment Value Estimation Programs

This repository contains two programs: one for Indian bank investments and another for Spanish bank investments.

## Building and Running Programs

### Indian Bank Investment Program

To build and run the Indian bank investment program, follow these steps:

1. Open a terminal or command prompt.
2. Navigate to the directory containing the source code and the Makefile.
3. Run the following commands:

**make debug_india** # Build debug version        
**make optimize_india** # Build optimized version

or

**make india** # Build debug version and Build optimized version simultaneously


4. Run the program using the following commands:

**./indian_bank** # Run debug version    
**./indian_bank_optimised** # Run optimized version

5. Follow the prompts to enter the investment amount and investment year.


### Spanish Bank Investment Program

To build and run the Spanish bank investment program, follow similar steps:

1. Open a terminal or command prompt.
2. Navigate to the directory containing the source code and the Makefile.
3. Run the following commands:

**make debug_spain** # Build debug version     
**make optimize_spain** # Build optimized version

or

**make spain** # Build debug version and optimized version simultaneously


4. Run the program using the following commands:

**./spain_bank** # Run debug version     
**./spain_bank_optimised** # Run optimized version



5. Follow the prompts to enter the investment amount and investment year.

## Input Data File Format

For both programs, the input data file should be a comma-separated values (CSV) file with the columns: sno, year, interest-rate, inflation-rate.

Example format:

sno: Serial number
year: Investment year
interest-rate: Interest rate for the year
inflation: Inflation rate for the year
government
continent

example of the format:

sno,year,interest-rate,inflation,government,continent      
0,1960,1.0,1.77987784677379,Constitutional-Republic,Asia
.
.
.
.





