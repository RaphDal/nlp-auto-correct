// The MIT License (MIT)

// Copyright (c) 2019 Raphael DALMON

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include <string.h>
#include <unistd.h>

size_t minimum(size_t matrix[], size_t n, size_t i, size_t j)
{
    size_t diag = (i - 1) * n + (j - 1);
    size_t top = (i - 1) * n + j;
    size_t left = i * n + (j - 1);
    size_t minimum = matrix[diag];

    if (matrix[top] < minimum)
        minimum = matrix[top];
    if (matrix[left] < minimum)
        minimum = matrix[left];
    return (minimum);
}

size_t levenshtein_distance(char *word, char *compared)
{
    size_t m = strlen(word) + 1;
    size_t n = strlen(compared) + 1;
    size_t matrix[m][n];

    for (size_t i = 0; i < m; i++)
        matrix[i][0] = i + (*word != *compared);
    for (size_t i = 1; i < n; i++)
        matrix[0][i] = i + (*word != *compared);
    for (size_t i = 1; i < m; i++) {
        for (size_t j = 1; j < n; j++)
            matrix[i][j] = minimum(matrix, n, i, j) + (word[i - 1] != compared[j - 1]);
    }
    return (matrix[m - 1][n - 1]);
}
