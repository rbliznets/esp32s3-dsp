#pragma once

#include <cstdio>
#include "esp_timer.h"
#include "mathlib_s3.h"
#define countof(x) (sizeof(x)/sizeof(x[0]))

#define ITER (1000)
#define TEST_SIZE (1024)

extern q15 in1[TEST_SIZE];
extern q15 in2[TEST_SIZE];
extern q15 out[TEST_SIZE];

int64_t getTime();
void printTime(const char* str, uint32_t n);