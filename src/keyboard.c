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

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "system.h"

vector2ul_t set_vec2ul(size_t x, size_t y)
{
    vector2ul_t vec = {x, y};

    return (vec);
}

int set_azerty(system_t *sys)
{
    sys->keyboard['a' - 'a'] = set_vec2ul(0, 0);
    sys->keyboard['z' - 'a'] = set_vec2ul(1, 0);
    sys->keyboard['e' - 'a'] = set_vec2ul(2, 0);
    sys->keyboard['r' - 'a'] = set_vec2ul(3, 0);
    sys->keyboard['t' - 'a'] = set_vec2ul(4, 0);
    sys->keyboard['y' - 'a'] = set_vec2ul(5, 0);
    sys->keyboard['u' - 'a'] = set_vec2ul(6, 0);
    sys->keyboard['i' - 'a'] = set_vec2ul(7, 0);
    sys->keyboard['o' - 'a'] = set_vec2ul(8, 0);
    sys->keyboard['p' - 'a'] = set_vec2ul(9, 0);

    sys->keyboard['q' - 'a'] = set_vec2ul(0, 1);
    sys->keyboard['s' - 'a'] = set_vec2ul(1, 1);
    sys->keyboard['d' - 'a'] = set_vec2ul(2, 1);
    sys->keyboard['f' - 'a'] = set_vec2ul(3, 1);
    sys->keyboard['g' - 'a'] = set_vec2ul(4, 1);
    sys->keyboard['h' - 'a'] = set_vec2ul(5, 1);
    sys->keyboard['j' - 'a'] = set_vec2ul(6, 1);
    sys->keyboard['k' - 'a'] = set_vec2ul(7, 1);
    sys->keyboard['l' - 'a'] = set_vec2ul(8, 1);
    sys->keyboard['m' - 'a'] = set_vec2ul(9, 1);

    sys->keyboard['w' - 'a'] = set_vec2ul(0, 2);
    sys->keyboard['x' - 'a'] = set_vec2ul(1, 2);
    sys->keyboard['c' - 'a'] = set_vec2ul(2, 2);
    sys->keyboard['v' - 'a'] = set_vec2ul(3, 2);
    sys->keyboard['b' - 'a'] = set_vec2ul(4, 2);
    sys->keyboard['n' - 'a'] = set_vec2ul(5, 2);

    return (0);
}

int get_keyboard(char *type, system_t *sys)
{
    if (!strcmp(type, "azerty"))
        return (set_azerty(sys));
    fprintf(stderr, "Unknown keyboard type\n");
    return (-1);
}