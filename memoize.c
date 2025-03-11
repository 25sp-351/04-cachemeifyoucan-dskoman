#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memoize.h"
#include "piece_values.h"

#define NOT_CACHED -1

memoize_cache_pv *memoize_init(int capacity, int dbg_flag) {
  memoize_cache_pv *cache = malloc(sizeof(PieceLengthValue));
  cache->data = malloc(sizeof(PieceLengthValue) * capacity);

  for (int i = 0; i < capacity; i++) {
    PieceLengthValue empty_item = {0, 0};
    cache->data[i] = empty_item;
  }

  cache->size = 0;
  cache->capacity = capacity;
  cache->dbg_flag = dbg_flag;

  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: cache initialized\n");
  }
  return cache;
}

void memoize_free(memoize_cache_pv *cache) {
  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: freeing cache\n");
  }
  free(cache);
}

int memoize_check(memoize_cache_pv *cache, PieceLengthValue *data) {
  if (memoize_cache_size(cache) == 0) {
    if (memoize_debug_flag(cache) > 0) {
      printf("dbg: '%lld' not found; cache empty\n", data);
    }
    return NOT_CACHED;
  }

  for (int index = 0; index < memoize_cache_size(cache); index++) {
    if (cache->data[index].length == data->length) {
      if (memoize_debug_flag(cache) > 0) {
        printf("dbg: '%lld' is in the cache\n", data);
      }

      return index;
    }
  }
  if (memoize_debug_flag(cache) > 0) {
    printf("dbg: '%lld' not found\n", data);
  }
  return NOT_CACHED;
}

int memoize_insert(memoize_cache_pv *cache, PieceLengthValue *data) {
  int cache_check_index = memoize_check(cache, data->length);

  if (cache_check_index == NOT_CACHED) {
    cache->data[memoize_cache_size(cache)] = *data;
    cache->size++;
  }

  if (memoize_debug_flag(cache) > 0) {
    memoize_print_cache(cache);
  }

  return cache_check_index;
}

int memoize_cache_size(memoize_cache_pv *cache) { return cache->size; }

int memoize_cache_capacity(memoize_cache_pv *cache) { return cache->capacity; }

int memoize_debug_flag(memoize_cache_pv *cache) { return cache->dbg_flag; }

void memoize_print_cache(memoize_cache_pv *cache) {
  for (int index = 0; index < memoize_cache_size(cache); index++) {
    printf("%d. %lld\n", index, cache->data[index]);
  }
}