"""
Author: Alberto Angelo Arellano Gaona
Date: 1/18/2022
Description:
Work as a team to write a Python program named fitness.py that does the following:

Asks the user to enter four values:
gender
birthdate in this format: YYYY-MM-DD
weight in U.S. pounds
height in U.S. inches
Converts the weight from pounds to kilograms (1 lb = 0.45359237 kg).
Converts inches to centimeters (1 in = 2.54 cm).
Calculates age, BMI, and BMR.
Prints age, weight in kg, height in cm, BMI, and BMR.
"""
from datetime import datetime


def main():
    print("\nWelcome to the fitness app!")
    # Get the user's gender, birthdate, height, and weight.
    aaag_user_gender = input("Please enter your gender (M or F): ")
    aaag_user_birthdate = input("Enter your birthdate (YYYY-MM-DD): ")
    aaag_user_pounds_str = input("Enter your weight in U.S. pounds: ")
    aaag_user_height_str = input("Enter your height in U.S. inches: ")

    aaag_user_pounds = int(aaag_user_pounds_str)
    aaag_user_height = int(aaag_user_height_str)

    # Call the compute_age, kg_from_lb, cm_from_in,
    # body_mass_index, and basal_metabolic_rate functions
    # as needed.
    aaag_user_age = aaag_compute_age(aaag_user_birthdate)
    aaag_user_weight = aaag_kg_from_lb(aaag_user_pounds)
    aaag_user_height_cm = aaag_cm_from_in(aaag_user_height)
    aaag_bmi = aaag_body_mass_index(aaag_user_weight, aaag_user_height_cm)
    aaag_bmr = aaag_basal_metabolic_rate(
        aaag_user_gender, aaag_user_weight, aaag_user_height_cm, aaag_user_age)
    print(f"Age (years): {aaag_user_age}")
    print(f"Weight (kg): {aaag_user_weight:.2f}")
    print(f"Height (cm): {aaag_user_height_cm:.2f}")
    print(f"Body mass index: {aaag_bmi:.2f}")
    print(f"Basal metabolic rate (kcal/day): {aaag_bmr:.0f}")

    # Print the results for the user to see.
    pass


def aaag_compute_age(birth_str):
    """Compute and return a person's age in years.
    Parameter birth_str: a person's birthdate stored
        as a string in this format: YYYY-MM-DD
    Return: a person's age in years.
    """
    # Convert a person's birthdate from a string
    # to a date object.
    aaag_birthdate = datetime.strptime(birth_str, "%Y-%m-%d")
    aaag_today = datetime.now()

    # Compute the difference between today and the
    # person's birthdate in years.
    aaag_years = aaag_today.year - aaag_birthdate.year

    # If necessary, subtract one from the difference.
    if aaag_birthdate.month > aaag_today.month or \
        (aaag_birthdate.month == aaag_today.month and
            aaag_birthdate.day > aaag_today.day):
        aaag_years -= 1

    return aaag_years


def aaag_kg_from_lb(aaag_pounds):
    """Convert a mass in pounds to kilograms.
    Parameter pounds: a mass in U.S. pounds.
    Return: the mass in kilograms.
    """
    aaag_kilos = aaag_pounds * 0.45359237
    return aaag_kilos


def aaag_cm_from_in(aaag_inches):
    """Convert a length in inches to centimeters.
    Parameter inches: a length in inches.
    Return: the length in centimeters.
    """
    aaag_cm = aaag_inches * 2.54
    return aaag_cm


def aaag_body_mass_index(aaag_weight, aaag_height):
    """Compute and return a person's body mass index.
    Parameters
        weight: a person's weight in kilograms.
        height: a person's height in centimeters.
    Return: a person's body mass index.
    """
    aaag_bmi = (10000 * aaag_weight) / (aaag_height ** 2)
    return aaag_bmi


def aaag_basal_metabolic_rate(aaag_gender, aaag_weight, aaag_height, aaag_age):
    """Compute and return a person's basal metabolic rate.
    Parameters
        weight: a person's weight in kilograms.
        height: a person's height in centimeters.
        age: a person's age in years.
    Return: a person's basal metabolic rate in kcals per day.
    """
    if aaag_gender == "M":
        aaag_bmr = 88.362 + (13.397 * aaag_weight) + \
            (4.799 * aaag_height) - (5.677 * aaag_age)
    elif aaag_gender == "F":
        aaag_bmr = 447.593 + (9.247 * aaag_weight) + \
            (3.089 * aaag_height) - (4.330 * aaag_age)
    else:
        aaag_bmr = 0
    return aaag_bmr


if __name__ == "__main__":
    main()
