#!/usr/bin/python3

"""
Reads stdin line by line and computes metrics for log parsing.
"""

import sys

status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
total_size = 0
code_counts = {code: 0 for code in status_codes}
line_count = 0


def print_stats():
    """Prints the accumulated statistics."""
    print("File size: {:d}".format(total_size))
    for code in status_codes:
        if code_counts[code]:
            print("{}: {:d}".format(code, code_counts[code]))


if (__name__ == "__main__"):
    try:
        for line in sys.stdin:
            line_count += 1
            parts = line.rstrip().split()
            if len(parts) >= 7:
                code = parts[-2]
                size = parts[-1]
                if code in status_codes:
                    try:
                        code_counts[code] += 1
                    except Exception:
                        pass
                try:
                    total_size += int(size)
                except Exception:
                    pass
            if line_count % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
