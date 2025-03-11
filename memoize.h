#ifndef MEMOIZE_H
#define MEMOIZE_H

#include "piece_values.h"

typedef struct {
  PieceLengthValue *data;
  int size;
  int capacity;
  int dbg_flag;
} memoize_cache_pv;

memoize_cache_pv *memoize_init(int capacity, int dbg_flag);
void memoize_free(memoize_cache_pv *cache);

int memoize_check(memoize_cache_pv *cache, PieceLengthValue data);

int memoize_insert(memoize_cache_pv *cache, PieceLengthValue data);

int memoize_cache_size(memoize_cache_pv *cache);

int memoize_cache_capacity(memoize_cache_pv *cache);

int memoize_debug_flag(memoize_cache_pv *cache);

void memoize_print_cache(memoize_cache_pv *cache);

#endif