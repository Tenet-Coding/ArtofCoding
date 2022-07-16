#!/usr/bin/env python3
"""
Title: Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase
letters and removing all non-alphanumeric characters, it reads the same forward
and backward. Alphanumeric characters include letters and numbers.

Task: Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    • Input: s = "A man, a plan, a canal: Panama"
    • Output: true
    • Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
    • Input: s = "race a car"
    • Output: false
    • Explanation: "raceacar" is not a palindrome.

Example 3:
    • Input: s = " "
    • Output: true
    • Explanation: s is an empty string "" after removing non-alphanumeric characters.
      Since an empty string reads the same forward and backward, it is a palindrome.

source: https://leetcode.com/problems/valid-palindrome/
"""

import string
import unittest


# Time Complexity:  O(n)
def valid_palindrome(s: str) -> bool:
    """Returns True if s is a valid palindrome, or otherwise False."""
    s = s.lower().replace(" ", "")
    s = s.translate(s.maketrans("", "", string.punctuation))
    return s == s[::-1]


class TestPalindrome(unittest.TestCase):
    """Unittest to prove the correctness of the valid_palindrome function."""

    def setUp(self) -> None:
        """Setup test_samples for the unittest."""
        self.test_samples = (
            ("A man, a plan, a canal: Panama", True),
            ("", True),
            ("Murder for a jar of red rum.", True),
            ("UFO tofu?", True),
            ("Yo, banana boy!", True),
            ("Ed, I saw Harpo Marx ram Oprah W. aside.", True),
            ("Eva, can I see bees in a cave?", True),
            ("race a car", False),
            ("Complexity Analysis for Valid Palindrome", False),
            ("This is not a palindrome!", False),
            ("The Art of Coding!", False),
            ("Google IT Automation", False),
            ("Geeks for Geeks, Codewars, Codechef", False),
            ("Race care", False),
        )

    def test_valid_palindrome(self):
        """
        Sample is passed to function. Test passes if the function returns 
        the "expected" result.
        """
        for sample, expected in self.test_samples:
            self.assertEqual(valid_palindrome(sample), expected)


if __name__ == "__main__":
    unittest.main()  # PASSED  [100%]
