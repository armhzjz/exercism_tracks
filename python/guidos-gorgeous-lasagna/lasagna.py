"""Functions used in preparing Guido's gorgeous lasagna.

Learn about Guido, the creator of the Python language:
https://en.wikipedia.org/wiki/Guido_van_Rossum

This is a module docstring, used to describe the functionality
of a module and its functions and/or classes.
"""


#TODO: define the 'EXPECTED_BAKE_TIME' constant.
EXPECTED_BAKE_TIME=40


#TODO: Remove 'pass' and complete the 'bake_time_remaining()' function below.
def bake_time_remaining(elapsed_bake_time:int) -> int:
    """Calculate the bake time remaining.

    :param elapsed_bake_time: int - baking time already elapsed.
    :return: int - remaining bake time (in minutes) derived from 'EXPECTED_BAKE_TIME'.

    Function that takes the actual minutes the lasagna has been in the oven as
    an argument and returns how many minutes the lasagna still needs to bake
    based on the `EXPECTED_BAKE_TIME`.
    """
    return EXPECTED_BAKE_TIME - elapsed_bake_time


#TODO: Define the 'preparation_time_in_minutes()' function below.
# You might also consider using 'PREPARATION_TIME' here, if you have it defined.
def preparation_time_in_minutes(number_of_layers:int) -> int:
    """ Calculate amount of needed minutes to cook number_of_layers layers
    
    :param number_of_layers: int - number of layers you want to add to the lasagna
    :return: int - Amount of minutes youi would spend making the layers.
    
    Function that takes the amount of layers you want to add to the lasagna and calculate
    the amount of minutes it would take to cook them. Assume each layer t akes 2 minutes
    to prepare
    """
    return 2 * number_of_layers



#TODO: define the 'elapsed_time_in_minutes()' function below.
# Remember to add a docstring (you can copy and then alter the one from bake_time_remaining.)
def elapsed_time_in_minutes(number_of_layers:int, elapsed_bake_time:int) -> int:
    """ Calculate total elapsed coooking time (prep + bake) in minutes
    :param number_of_layers: int - number of layers added to the lasagna
    :param elapsed_bake_time: int - number of minutes the lasagna has been baking in the oven
    :return: int - total number of minutes you've been cooking.
    
    Function calculates the sum of your preparation time and the time the lasagna has already
    spent baking in the oven.
    """
    return preparation_time_in_minutes(number_of_layers) + elapsed_bake_time
