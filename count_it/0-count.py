#!/usr/bin/python3
"""Module that queries the Reddit API and counts keyword occurrences
in hot article titles for a given subreddit.

The main entrypoint is the function `count_words(subreddit, word_list)`.
"""

import requests


def count_words(subreddit, word_list, after=None, counts=None, freq=None):
    """Query the Reddit API recursively and count occurrences of words.

    subreddit: name of subreddit to query
    word_list: list of keywords (strings) to count (case-insensitive)

    The function can be called with only `subreddit` and `word_list`.
    It uses recursion to walk through all pages of hot posts. Matching is
    performed by splitting titles on spaces and comparing tokens exactly
    (case-insensitive). Tokens with punctuation attached (e.g. "java.")
    will not match "java".
    """
    if counts is None:
        counts = {}

    if freq is None:
        # Normalize word list and prepare frequency/mapping structures
        freq = {}
        for w in word_list:
            lw = w.lower()
            freq[lw] = freq.get(lw, 0) + 1
            counts.setdefault(lw, 0)

    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-Agent': 'python:count_words:v1.0 (by /u/yourname)'}
    params = {'limit': 100}
    if after:
        params['after'] = after

    try:
        res = requests.get(url, headers=headers, allow_redirects=False,
                           params=params)
    except Exception:
        return None

    if res.status_code != 200:
        return None

    try:
        data = res.json().get('data', {})
    except Exception:
        return None

    children = data.get('children', [])
    for child in children:
        title = child.get('data', {}).get('title', '')
        tokens = title.split()
        for token in tokens:
            t = token.lower()
            if t in counts:
                counts[t] += 1

    after_key = data.get('after')
    if after_key:
        return count_words(subreddit, word_list, after=after_key,
                           counts=counts, freq=freq)

    # We're at the end; prepare final totals applying duplicate keywords
    final = {}
    for k, raw in counts.items():
        total = raw * freq.get(k, 1)
        if total > 0:
            final[k] = total

    if not final:
        return None

    # Sort by count descending, then alphabetically ascending
    for k, v in sorted(final.items(), key=lambda x: (-x[1], x[0])):
        print("{}: {}".format(k, v))

    return None
