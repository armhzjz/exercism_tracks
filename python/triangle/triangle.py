""" Functiosn to determine the type of triangle given its sides """

# pylint: disable=invalid-name
def equilateral(sides:tuple) -> bool:
    """ Determine if a triangle is equilateral
    
    :param sides: a tuple of 3 numbers (int)
    :return: True if all sides are of equal size
    
    An equilateral triangle has all three sides the same length.
    """
    a,b,c = sides
    return bool(a == b == c and 0 != a * b * c)


def isosceles(sides:tuple) -> bool:
    """ Determine if a triangle is an isosceles triangle
    
    :param sides: a tuple of 3 numbers (int)
    :return: True if at leats two sides are of equal size
    
    An isosceles triangle has at least two sides the same length.
    (It is sometimes specified as having exactly two sides the
    same length, but for the purposes of this exercise
    we'll say at least two.)
    """
    a,b,c = sides
    return bool( (a == b or b == c or c == a) and 0 != a * b * c and a+b >= c and b+c >= a and c+a >= b)


def scalene(sides:tuple) -> bool:
    """ Determine if a triangel is scalene
    
    :param sides: a tuple of 3 numbers (int)
    :return: True if all sides are of different size
    
    A scalene triangle has all sides of different lengths.
    """
    a,b,c = sides
    return bool(a != b and b != c and c != a and 0 != a * b * c and a+b >= c and b+c >= a and c+a >= b)
