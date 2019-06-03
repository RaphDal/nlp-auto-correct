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
#include <stdlib.h>
#include <stdio.h>
#include "algorithms.h"

static int append_list(char ***res_ptr, size_t *nb_elems, char *word)
{
    char **words = *res_ptr;

    if ((*nb_elems)%1000 == 0)
        fprintf(stderr, "\r%lu words extracted !", *nb_elems);
    if ((*nb_elems)%dico_inc_buff == 0) {
        words = malloc(sizeof(char *) * ((*nb_elems) + dico_inc_buff + 1));
        if (!words)
            return (-1);
        if (*res_ptr) {
            memcpy(words, *res_ptr, (*nb_elems) * sizeof(char *));
            free(*res_ptr);
        }
        *res_ptr = words;
    }
    if (!(words[*nb_elems] = malloc(sizeof(char) * (strlen(word) + 1))))
        return (-1);
    memcpy(words[*nb_elems], word, strlen(word));
    words[*nb_elems][strlen(word)] = '\0';
    (*nb_elems)++;
    return (0);
} 

char **get_dico(char *filepath)
{
    FILE *dico = fopen(filepath, "r");
    size_t size = 0;
    char **res = NULL;
    char *line = NULL;
    size_t nb_elem = 0;
    int ret = 0;

    if (!dico)
        return (NULL);
    while (ret != -1) {
        size = 0;
        if ((ret = getline(&line, &size, dico)) == -1) {
            free(line);
            break;
        }
        line[ret - 1] = '\0';
        if (append_list(&res, &nb_elem, line))
            return (NULL);
        free(line);
        line = NULL;
    }
    res[nb_elem] = NULL;
    fclose(dico);
    return (res);
}
