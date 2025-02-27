/*
 * Copyright (c) 2020 YuQing <384681@qq.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include "common_define.h"

typedef struct sorted_array_context
{
    int element_size;
    bool allow_duplication;
    int (*compare_func)(const void *, const void *);
} SortedArrayContext;

#ifdef __cplusplus
extern "C" {
#endif

    /** init the context for sorted array
     *  parameters:
     *      ctx: the context to init
     *      element_size: the size of one array element
     *      allow_duplication: if allow duplication
     *      compare_func: the compare function (comparator)
     *  return: none
     */
    void sorted_array_init(SortedArrayContext *ctx,
            const int element_size, const bool allow_duplication,
            int (*compare_func)(const void *, const void *));


    /** insert an element into the sorted array
     *  parameters:
     *      ctx: the context for sorted array
     *      base: the pointer of the sorted array (the first array element)
     *      count: the count of the sorted array (for input and output)
     *      elt: the element to insert
     *  return: 0 for success, != 0 for error
     */
    int sorted_array_insert(SortedArrayContext *ctx,
            void *base, int *count, const void *elt);


    /** delete an element from the sorted array
     *  parameters:
     *      ctx: the context for sorted array
     *      base: the pointer of the sorted array (the first array element)
     *      count: the count of the sorted array (for input and output)
     *      elt: the element to delete
     *  return: 0 for success, != 0 for error
     */
    int sorted_array_delete(SortedArrayContext *ctx,
            void *base, int *count, const void *elt);


    /* comparator for 64 bits integer */
    int sorted_array_compare_int64(const int64_t *n1, const int64_t *n2);

    /* comparator for 32 bits integer */
    int sorted_array_compare_int32(const int32_t *n1, const int32_t *n2);


#define sorted_i64_array_init(ctx, allow_duplication) \
    sorted_array_init(ctx, sizeof(int64_t), allow_duplication, \
            (int (*)(const void *, const void *))sorted_array_compare_int64)

#define sorted_i32_array_init(ctx, allow_duplication) \
    sorted_array_init(ctx, sizeof(int32_t), allow_duplication, \
            (int (*)(const void *, const void *))sorted_array_compare_int32)


#ifdef __cplusplus
}
#endif

#endif
