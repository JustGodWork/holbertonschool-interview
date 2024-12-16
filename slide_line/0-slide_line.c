#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers containing size elements
 * @size: Number of elements in the array
 * @direction: Direction to slide and merge (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return (0);

    if (direction == SLIDE_LEFT)
    {
        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (j < i)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
        for (i = 0; i < size - 1; i++)
        {
            if (line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
                i++;
            }
        }
        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (j < i)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (j > i)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j--;
            }
        }
        for (i = size - 1; (int)i > 0; i--)
        {
            if (line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
                i--;
            }
        }
        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (j > i)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j--;
            }
        }
    }

    return (1);
}
