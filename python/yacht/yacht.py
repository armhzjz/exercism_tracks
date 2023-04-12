"""The dice game Yacht is from the same family as Poker Dice,
Generala and particularly Yahtzee, of which it is a precursor.
In the game, five dice are rolled and the result can be entered
in any of twelve categories. The score of a throw of the dice
depends on category chosen.
"""
from collections import Counter


# pylint: disable=unnecessary-lambda-assignment
YACHT = lambda x: 50 if len(set(x)) == 1 else 0
ONES = lambda x: x.count(1)
TWOS = lambda x: x.count(2) * 2
THREES = lambda x: x.count(3) * 3
FOURS = lambda x: x.count(4) * 4
FIVES = lambda x: x.count(5) * 5
SIXES = lambda x: x.count(6) * 6
FULL_HOUSE = lambda x: sum(x) if sorted(Counter(x).values()) == [2,3] else 0
FOUR_OF_A_KIND = lambda x: sum(sorted(Counter(x).elements())[1:]) \
                            if sorted(Counter(x).values()) == [1,4] or sorted(Counter(x).values()) == [5] else 0
LITTLE_STRAIGHT = lambda x: 30 if sorted(x) == [1,2,3,4,5] else 0
BIG_STRAIGHT = lambda x: 30 if sorted(x) == [2,3,4,5,6] else 0
CHOICE = lambda x: sum(x)  # pylint: disable=unnecessary-lambda


def score(dice:tuple, category) -> int:
    """Return the score of the given dices
    values and the  given category.

    Args:
        dice (tuple):   The fice dices values
        category:       The chosen category used to calculate the score. 

    Returns:
        int: Score
    """
    return category(dice)
