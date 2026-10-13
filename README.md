# Week-9-OODP-Assignment
# Week 9 – Abstraction, Interface, Class vs Interface

**Language:** C++

## Question 1: Movie Ticket Counter

### Algorithm
1. Start the program.
2. Create an abstract base class `Ticket` that defines the common ticket operations.
3. Create derived classes for Regular, Premium, and Recliner tickets.
4. Assign the appropriate ticket price to each seat category.
5. Read the seat category and number of tickets from the user.
6. Calculate the total amount by adding the convenience fee to the ticket price and multiplying by the number of tickets.
7. If the seat category is invalid, display an error message.
8. Display the total ticket cost.
9. Stop the program.

## Question 2: Parcel Shipping Desk

### Algorithm
1. Start the program.
2. Create an abstract base class for parcel shipping.
3. Implement derived classes for Standard, Express, and Fragile shipping services.
4. Read the parcel type, weight, and insurance details.
5. Calculate the shipping charge according to the selected service and parcel weight.
6. If insurance is selected, calculate the applicable insurance charge using the declared value.
7. Add the shipping charge and insurance charge to obtain the final amount.
8. Display the total shipping cost.
9. Stop the program.

## Question 3: College Fee Counter

### Algorithm
1. Start the program.
2. Create an abstract base class for college fee calculation.
3. Create derived classes for Day Scholar, Hosteller, and Scholar categories.
4. Read the student's category.
5. Calculate the tuition fee according to the selected category.
6. Add the applicable hostel fee or bus fee according to the category's rules.
7. Calculate the total college fee.
8. Display the total fee payable.
9. Stop the program.

## Question 4: City Cab Fare Meter

### Algorithm
1. Start the program.
2. Create an abstract base class `Cab` containing the travel distance and a virtual fare-calculation function.
3. Create derived classes for Mini, Sedan, and SUV cabs.
4. Read the number of cab bookings.
5. For each booking, read the cab type, travel distance, and time category.
6. Calculate the fare using the applicable base fare and per-kilometre rate.
7. Apply the minimum fare and night surcharge rules as required by the assignment.
8. Display the fare for each valid booking.
9. Add each calculated fare to the total fare.
10. Display the total fare for all bookings.
11. Stop the program.

## Question 5: Home Appliance Energy Report

### Algorithm
1. Start the program.
2. Create an abstract base class `Appliance` with common properties such as power rating and hours of usage.
3. Define virtual functions to calculate energy units, check saver-mode support, and return the appliance name.
4. Create derived classes for Fridge, AC, TV, and Washer.
5. Assign the power ratings:
   - Fridge: 150 W
   - AC: 1500 W
   - TV: 100 W
   - Washer: 500 W
6. Read the number of appliances and the details of each appliance, including usage hours and optional saver mode.
7. Calculate energy consumption using:

   **Units (kWh) = Power (W) × Hours ÷ 1000**

8. For AC and Washer, reduce energy consumption by 25% if saver mode is enabled.
9. If saver mode is requested for Fridge or TV, display `saver mode not supported` instead of calculating the cost for that appliance.
10. Calculate electricity cost using:

    **Cost = Units × 8**

11. Display the energy units and cost for each supported calculation.
12. Add the individual costs and display the total electricity cost.
13. Stop the program.

---

## Concepts Used

- Abstraction
- Abstract classes
- Inheritance
- Virtual functions
- Function overriding
- Runtime polymorphism
- Encapsulation
