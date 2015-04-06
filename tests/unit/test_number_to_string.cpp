/* Copyright 2014-2015 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <math.h>
#include <string.h>

#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "jrt.h"

/**
 * Unit test's main function.
 */
int
main (int __attr_unused___ argc,
      char __attr_unused___ **argv)
{
  const ecma_char_t* zt_strings[] =
  {
    (const ecma_char_t*) "1",
    (const ecma_char_t*) "0.5",
    (const ecma_char_t*) "12345",
    (const ecma_char_t*) "12345.123",
    (const ecma_char_t*) "1e-45",
    (const ecma_char_t*) "-2.5e+38",
    (const ecma_char_t*) "NaN",
    (const ecma_char_t*) "Infinity",
    (const ecma_char_t*) "-Infinity",
    (const ecma_char_t*) "0",
    (const ecma_char_t*) "0",
  };

  const ecma_number_t nums[] =
  {
    (ecma_number_t) 1.0,
    (ecma_number_t) 0.5,
    (ecma_number_t) 12345.0,
    (ecma_number_t) 12345.123,
    (ecma_number_t) 1.0e-45,
    (ecma_number_t) -2.5e+38,
    (ecma_number_t) NAN,
    (ecma_number_t) INFINITY,
    (ecma_number_t) -INFINITY,
    (ecma_number_t) +0.0,
    (ecma_number_t) -0.0
  };

  for (uint32_t i = 0;
       i < sizeof (nums) / sizeof (nums[0]);
       i++)
  {
    ecma_char_t zt_str[64];

    ecma_number_to_zt_string (nums[i], zt_str, sizeof (zt_str));

    if (strcmp ((char*)zt_str, (char*)zt_strings [i]) != 0)
    {
      return 1;
    }
  }

  return 0;
} /* main */