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

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static const int inc_buff = 4;

static bool is_word_char(char c)
{
    return (c == '-' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static void jump_escape(char **content)
{
    while (!is_word_char(**content) && **content)
        (*content)++;
}

static char *dup_word(char **line)
{
    size_t len;
    char *res;

    for (len = 0; is_word_char((*line)[len]) && (*line)[len]; len++);
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    memcpy(res, *line, len);
    res[len] = 0;
    (*line) += len;
    return (res);
}

static int add_element(char ***tokens_ptr,
size_t *nb_elems, char **line_ptr)
{
    char **new_tokens = *tokens_ptr;

    if ((*nb_elems)%inc_buff == 0) {
        new_tokens = malloc(sizeof(char *) * ((*nb_elems) + inc_buff));
        if (!new_tokens)
            return (-1);
        if (*tokens_ptr) {
            memcpy(new_tokens, *tokens_ptr, (*nb_elems) * sizeof(char *));
            free(*tokens_ptr);
        }
        *tokens_ptr = new_tokens;
    }
    if (!(new_tokens[*nb_elems] = dup_word(line_ptr)))
        return (-1);
    (*nb_elems)++;
    return (0);
}

char **tokenize(char *line)
{
    char **tokens = NULL;
    size_t nb_elems = 0;

    jump_escape(&line);
    while (*line) {
        if (add_element(&tokens, &nb_elems, &line))
            return (NULL);
        jump_escape(&line);
    }
    return (tokens);
}
