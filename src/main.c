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

#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "algorithms.h"

size_t list_size(char **arr)
{
    size_t i = 0;

    while (arr[i])
        i++;
    return (i);
}

int loop(char **dico)
{
    char *line = NULL;
    char **tokens;
    size_t size;
    int res;
    size_t dico_size = list_size(dico);

    while (1) {
        size = 0;
        res = getline(&line, &size, stdin);
        if (res == -1) {
            free(line);
            return (EXIT_SUCCESS);
        }
        line[res - 1] = 0;
        if (!(tokens = tokenize(line)))
            return (EXIT_FAILURE);
        exploit(tokens, dico, dico_size);
        free(line);
        line = NULL;
    }
    return (EXIT_SUCCESS);
}


int main(int argc, char **argv)
{
    char **dico;
    int back;

    if (argc < 2 || !(dico = get_dico(argv[1]))) {
        fprintf(stderr, "I need a dictionnary to compare the words !\n");
        return (EXIT_FAILURE);
    }
    fprintf(stderr, "\n");
    back = loop(dico);
    for (size_t i = 0; dico[i]; i++)
        free(dico[i]);
    free(dico);
    return (back);
}
