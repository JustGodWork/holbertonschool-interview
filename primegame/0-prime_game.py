#!/usr/bin/python3
"""
Prime Game: Maria and Ben take turns picking
primes and removing them and their multiples.
"""


def isWinner(x, nums):
    """
    Determines the winner of the Prime Game
    played between Maria and Ben.

    In each round, players take turns picking
    a prime number from a set of numbers 1 to n,
    removing that prime and all its multiples
    from the set. The player who cannot make a move loses.
    The function simulates x rounds,
    each with a different n from the nums list.

    Args:
        x (int): The number of rounds to play.
        nums (list of int): List of n values for each round.

    Returns:
        str or None: The name of the player
                with the most wins ("Maria" or "Ben").
                    Returns None if there is a tie or if input is invalid.
    """
    if not nums or x < 1:
        return None
    n = max(nums)
    # Sieve of Eratosthenes to count primes up to n
    is_prime = [True for _ in range(n + 1)]
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    # Count primes up to each i
    primes_count = [0] * (n + 1)
    for i in range(1, n + 1):
        primes_count[i] = primes_count[i - 1] + (1 if is_prime[i] else 0)
    maria = 0
    ben = 0
    for num in nums:
        if primes_count[num] % 2 == 1:
            maria += 1
        else:
            ben += 1
    if maria > ben:
        return "Maria"
    if ben > maria:
        return "Ben"
    return None
