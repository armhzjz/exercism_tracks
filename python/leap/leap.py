"""Given a year, report if it is a leap year."""
def leap_year(year:int) -> bool:
    """ Calculate if the given year is a Leap year
    
        The tricky thing here is that a leap year in the Gregorian calendar occurs:
        on every year that is evenly divisible by 4
        except every year that is evenly divisible by 100
        unless the year is also evenly divisible by 400
        For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.
        
        The following boolean table is helpful to find out the formula used in this implementation:
        E.D. = "Evenly Divisible"
        
        E.D.        E.D.        E.D.            is Leap?
        by 4        by 100      by 400
        1           0           0               1
        1           1           0               0
        1           0           1               1
        1           1           1               1
        0           X           X               0
        
        The formula:
        E.D.4 & [(E.D.100 ^ E.D.400) || E.D.400]

    Args:
        year (int):     The year 

    Returns:
        bool:   True:   The year is/was/will be a leap year
                False:  The year is not /was not/will not be a leap year
    """
    div_by_4 = not bool(year % 4)
    div_by_100 = not bool(year % 100)
    div_by_400 = not bool(year % 400)
    mid_term = int(div_by_100) == int(div_by_400)
    return div_by_4 and (mid_term or div_by_400)
