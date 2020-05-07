/* Copyright (c) 2018, 2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_ISAX avx
#include <simde/x86/avx.h>
#include <test/x86/test-avx.h>

#if defined(SIMDE_X86_AVX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static simde_float32 u32_to_f32(uint32_t u32) {
  simde_float32 f32;
  memcpy(&f32, &u32, sizeof(f32));
  return f32;
}

static simde_float64 u64_to_f64(uint64_t u64) {
  simde_float64 f64;
  memcpy(&f64, &u64, sizeof(f64));
  return f64;
}

#define SIMDE_F32_ALL_SET (u32_to_f32(~UINT32_C(0)))
#define SIMDE_F64_ALL_SET (u64_to_f64(~UINT64_C(0)))

static MunitResult
test_simde_mm256_set_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int8_t a[32];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi8(a[31], a[30], a[29], a[28], a[27], a[26], a[25], a[24],
                             a[23], a[22], a[21], a[20], a[19], a[18], a[17], a[16],
                             a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
                             a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 16 ; i++) {
    int16_t a[16];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi16(a[15], a[14], a[13], a[12], a[11], a[10], a[ 9], a[ 8],
                              a[ 7], a[ 6], a[ 5], a[ 4], a[ 3], a[ 2], a[ 1], a[ 0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    int32_t a[8];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi32(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    int64_t a[4];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_epi64x(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 32 ; i++) {
    simde_float32 a[8];
    simde__m256 r;

    random_f32v(8, a);
    r = simde_mm256_set_ps(a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde_float64 a[4];
    simde__m256d r;

    random_f64v(4, a);
    r = simde_mm256_set_pd(a[3], a[2], a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128 a[2];
    simde__m256 r;

    random_f32v(8, (simde_float32*) a);
    r = simde_mm256_set_m128(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128d a[2];
    simde__m256d r;

    random_f64v(4, (simde_float64*) a);
    r = simde_mm256_set_m128d(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  for (size_t i = 0 ; i < 64 ; i++) {
    simde__m128i a[2];
    simde__m256i r;

    munit_rand_memory(sizeof(a), (uint8_t*) a);
    r = simde_mm256_set_m128i(a[1], a[0]);

    munit_assert_memory_equal(sizeof(a), a, &r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a;
    simde__m256i r;
  } test_vec[8] = {
    { 41,
      simde_mm256_set_epi8(INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41),
                           INT8_C(  41), INT8_C(  41), INT8_C(  41), INT8_C(  41)) },
    { -5,
      simde_mm256_set_epi8(INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5),
                           INT8_C(  -5), INT8_C(  -5), INT8_C(  -5), INT8_C(  -5)) },
    { -85,
      simde_mm256_set_epi8(INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85),
                           INT8_C( -85), INT8_C( -85), INT8_C( -85), INT8_C( -85)) },
    { 61,
      simde_mm256_set_epi8(INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61),
                           INT8_C(  61), INT8_C(  61), INT8_C(  61), INT8_C(  61)) },
    { -125,
      simde_mm256_set_epi8(INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125),
                           INT8_C(-125), INT8_C(-125), INT8_C(-125), INT8_C(-125)) },
    { -117,
      simde_mm256_set_epi8(INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117),
                           INT8_C(-117), INT8_C(-117), INT8_C(-117), INT8_C(-117)) },
    { 5,
      simde_mm256_set_epi8(INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5),
                           INT8_C(   5), INT8_C(   5), INT8_C(   5), INT8_C(   5)) },
    { -41,
      simde_mm256_set_epi8(INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41),
                           INT8_C( -41), INT8_C( -41), INT8_C( -41), INT8_C( -41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi8(test_vec[i].a);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT16_C( -7117),
      simde_mm256_set_epi16(INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117),
                            INT16_C( -7117), INT16_C( -7117), INT16_C( -7117), INT16_C( -7117)) },
    { INT16_C( -4832),
      simde_mm256_set_epi16(INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832),
                            INT16_C( -4832), INT16_C( -4832), INT16_C( -4832), INT16_C( -4832)) },
    { INT16_C( 20615),
      simde_mm256_set_epi16(INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615),
                            INT16_C( 20615), INT16_C( 20615), INT16_C( 20615), INT16_C( 20615)) },
    { INT16_C(-30117),
      simde_mm256_set_epi16(INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117),
                            INT16_C(-30117), INT16_C(-30117), INT16_C(-30117), INT16_C(-30117)) },
    { INT16_C( 32088),
      simde_mm256_set_epi16(INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088),
                            INT16_C( 32088), INT16_C( 32088), INT16_C( 32088), INT16_C( 32088)) },
    { INT16_C(-14076),
      simde_mm256_set_epi16(INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076),
                            INT16_C(-14076), INT16_C(-14076), INT16_C(-14076), INT16_C(-14076)) },
    { INT16_C( -9132),
      simde_mm256_set_epi16(INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132),
                            INT16_C( -9132), INT16_C( -9132), INT16_C( -9132), INT16_C( -9132)) },
    { INT16_C(-24801),
      simde_mm256_set_epi16(INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801),
                            INT16_C(-24801), INT16_C(-24801), INT16_C(-24801), INT16_C(-24801)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi16(test_vec[i].a);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT32_C( 1458307866),
      simde_mm256_set_epi32(INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866),
                            INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866), INT32_C( 1458307866)) },
    { INT32_C(-1231481357),
      simde_mm256_set_epi32(INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357),
                            INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357), INT32_C(-1231481357)) },
    { INT32_C( 1330347041),
      simde_mm256_set_epi32(INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041),
                            INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041), INT32_C( 1330347041)) },
    { INT32_C(-2031969158),
      simde_mm256_set_epi32(INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158),
                            INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158), INT32_C(-2031969158)) },
    { INT32_C(  138293031),
      simde_mm256_set_epi32(INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031),
                            INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031), INT32_C(  138293031)) },
    { INT32_C( -870589211),
      simde_mm256_set_epi32(INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211),
                            INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211), INT32_C( -870589211)) },
    { INT32_C( 1439279097),
      simde_mm256_set_epi32(INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097),
                            INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097), INT32_C( 1439279097)) },
    { INT32_C( -102725779),
      simde_mm256_set_epi32(INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779),
                            INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779), INT32_C( -102725779)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde__m256i r;
  } test_vec[8] = {
    { INT64_C( 5105791061004147197),
      simde_mm256_set_epi64x(INT64_C( 5105791061004147197), INT64_C( 5105791061004147197),
                             INT64_C( 5105791061004147197), INT64_C( 5105791061004147197)) },
    { INT64_C(-2078502026959165134),
      simde_mm256_set_epi64x(INT64_C(-2078502026959165134), INT64_C(-2078502026959165134),
                             INT64_C(-2078502026959165134), INT64_C(-2078502026959165134)) },
    { INT64_C( 3468007801991671414),
      simde_mm256_set_epi64x(INT64_C( 3468007801991671414), INT64_C( 3468007801991671414),
                             INT64_C( 3468007801991671414), INT64_C( 3468007801991671414)) },
    { INT64_C(-1026830878024479084),
      simde_mm256_set_epi64x(INT64_C(-1026830878024479084), INT64_C(-1026830878024479084),
                             INT64_C(-1026830878024479084), INT64_C(-1026830878024479084)) },
    { INT64_C(-5815393469667065909),
      simde_mm256_set_epi64x(INT64_C(-5815393469667065909), INT64_C(-5815393469667065909),
                             INT64_C(-5815393469667065909), INT64_C(-5815393469667065909)) },
    { INT64_C(-1858841878581774308),
      simde_mm256_set_epi64x(INT64_C(-1858841878581774308), INT64_C(-1858841878581774308),
                             INT64_C(-1858841878581774308), INT64_C(-1858841878581774308)) },
    { INT64_C( 6272125310275044670),
      simde_mm256_set_epi64x(INT64_C( 6272125310275044670), INT64_C( 6272125310275044670),
                             INT64_C( 6272125310275044670), INT64_C( 6272125310275044670)) },
    { INT64_C( 6393396529564376044),
      simde_mm256_set_epi64x(INT64_C( 6393396529564376044), INT64_C( 6393396529564376044),
                             INT64_C( 6393396529564376044), INT64_C( 6393396529564376044)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_set1_epi64x(test_vec[i].a);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m256 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(  -73.91),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91),
                         SIMDE_FLOAT32_C(  -73.91), SIMDE_FLOAT32_C(  -73.91)) },
    { SIMDE_FLOAT32_C(  953.36),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36),
                         SIMDE_FLOAT32_C(  953.36), SIMDE_FLOAT32_C(  953.36)) },
    { SIMDE_FLOAT32_C(  888.18),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18),
                         SIMDE_FLOAT32_C(  888.18), SIMDE_FLOAT32_C(  888.18)) },
    { SIMDE_FLOAT32_C(  232.71),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71),
                         SIMDE_FLOAT32_C(  232.71), SIMDE_FLOAT32_C(  232.71)) },
    { SIMDE_FLOAT32_C( -598.38),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38),
                         SIMDE_FLOAT32_C( -598.38), SIMDE_FLOAT32_C( -598.38)) },
    { SIMDE_FLOAT32_C(  762.88),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88),
                         SIMDE_FLOAT32_C(  762.88), SIMDE_FLOAT32_C(  762.88)) },
    { SIMDE_FLOAT32_C( -225.89),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89),
                         SIMDE_FLOAT32_C( -225.89), SIMDE_FLOAT32_C( -225.89)) },
    { SIMDE_FLOAT32_C( -115.32),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32),
                         SIMDE_FLOAT32_C( -115.32), SIMDE_FLOAT32_C( -115.32)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_set1_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_set1_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m256d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -494.25),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -494.25), SIMDE_FLOAT64_C( -494.25),
                         SIMDE_FLOAT64_C( -494.25), SIMDE_FLOAT64_C( -494.25)) },
    { SIMDE_FLOAT64_C(  610.20),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  610.20), SIMDE_FLOAT64_C(  610.20),
                         SIMDE_FLOAT64_C(  610.20), SIMDE_FLOAT64_C(  610.20)) },
    { SIMDE_FLOAT64_C( -471.35),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -471.35), SIMDE_FLOAT64_C( -471.35),
                         SIMDE_FLOAT64_C( -471.35), SIMDE_FLOAT64_C( -471.35)) },
    { SIMDE_FLOAT64_C( -211.28),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -211.28), SIMDE_FLOAT64_C( -211.28),
                         SIMDE_FLOAT64_C( -211.28), SIMDE_FLOAT64_C( -211.28)) },
    { SIMDE_FLOAT64_C(  -27.80),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -27.80),
                         SIMDE_FLOAT64_C(  -27.80), SIMDE_FLOAT64_C(  -27.80)) },
    { SIMDE_FLOAT64_C(  866.02),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  866.02), SIMDE_FLOAT64_C(  866.02),
                         SIMDE_FLOAT64_C(  866.02), SIMDE_FLOAT64_C(  866.02)) },
    { SIMDE_FLOAT64_C( -278.22),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -278.22), SIMDE_FLOAT64_C( -278.22),
                         SIMDE_FLOAT64_C( -278.22), SIMDE_FLOAT64_C( -278.22)) },
    { SIMDE_FLOAT64_C(  868.90),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  868.90), SIMDE_FLOAT64_C(  868.90),
                         SIMDE_FLOAT64_C(  868.90), SIMDE_FLOAT64_C(  868.90)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_set1_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  770.99), SIMDE_FLOAT32_C(  104.99),
                         SIMDE_FLOAT32_C( -101.89), SIMDE_FLOAT32_C( -513.24),
                         SIMDE_FLOAT32_C( -417.43), SIMDE_FLOAT32_C( -288.54),
                         SIMDE_FLOAT32_C(  266.43), SIMDE_FLOAT32_C( -560.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  587.57), SIMDE_FLOAT32_C( -411.17),
                         SIMDE_FLOAT32_C(  235.43), SIMDE_FLOAT32_C(  663.07),
                         SIMDE_FLOAT32_C( -931.58), SIMDE_FLOAT32_C( -273.94),
                         SIMDE_FLOAT32_C( -824.43), SIMDE_FLOAT32_C(  308.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1358.56), SIMDE_FLOAT32_C( -306.18),
                         SIMDE_FLOAT32_C(  133.54), SIMDE_FLOAT32_C(  149.83),
                         SIMDE_FLOAT32_C(-1349.01), SIMDE_FLOAT32_C( -562.48),
                         SIMDE_FLOAT32_C( -558.00), SIMDE_FLOAT32_C( -252.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -380.17), SIMDE_FLOAT32_C( -292.76),
                         SIMDE_FLOAT32_C(  -50.19), SIMDE_FLOAT32_C(  631.87),
                         SIMDE_FLOAT32_C(  407.07), SIMDE_FLOAT32_C(   82.94),
                         SIMDE_FLOAT32_C(  710.14), SIMDE_FLOAT32_C(  140.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  175.15), SIMDE_FLOAT32_C(  286.98),
                         SIMDE_FLOAT32_C(  813.95), SIMDE_FLOAT32_C( -881.68),
                         SIMDE_FLOAT32_C(  977.49), SIMDE_FLOAT32_C(  528.94),
                         SIMDE_FLOAT32_C(  994.01), SIMDE_FLOAT32_C(  529.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.02), SIMDE_FLOAT32_C(   -5.78),
                         SIMDE_FLOAT32_C(  763.76), SIMDE_FLOAT32_C( -249.81),
                         SIMDE_FLOAT32_C( 1384.56), SIMDE_FLOAT32_C(  611.88),
                         SIMDE_FLOAT32_C( 1704.15), SIMDE_FLOAT32_C(  669.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  160.16), SIMDE_FLOAT32_C(  875.39),
                         SIMDE_FLOAT32_C(  514.63), SIMDE_FLOAT32_C( -397.44),
                         SIMDE_FLOAT32_C(  299.15), SIMDE_FLOAT32_C( -674.71),
                         SIMDE_FLOAT32_C(  625.83), SIMDE_FLOAT32_C( -614.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -835.86), SIMDE_FLOAT32_C(  900.26),
                         SIMDE_FLOAT32_C(  485.80), SIMDE_FLOAT32_C( -508.14),
                         SIMDE_FLOAT32_C(  244.55), SIMDE_FLOAT32_C(  182.83),
                         SIMDE_FLOAT32_C(  -64.03), SIMDE_FLOAT32_C(    1.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -675.70), SIMDE_FLOAT32_C( 1775.65),
                         SIMDE_FLOAT32_C( 1000.43), SIMDE_FLOAT32_C( -905.58),
                         SIMDE_FLOAT32_C(  543.70), SIMDE_FLOAT32_C( -491.88),
                         SIMDE_FLOAT32_C(  561.80), SIMDE_FLOAT32_C( -613.60)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -699.57), SIMDE_FLOAT32_C(  489.63),
                         SIMDE_FLOAT32_C(  414.73), SIMDE_FLOAT32_C(  451.08),
                         SIMDE_FLOAT32_C( -926.15), SIMDE_FLOAT32_C( -146.45),
                         SIMDE_FLOAT32_C(  105.18), SIMDE_FLOAT32_C( -637.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -524.62), SIMDE_FLOAT32_C(   50.97),
                         SIMDE_FLOAT32_C(  -65.89), SIMDE_FLOAT32_C(  850.47),
                         SIMDE_FLOAT32_C(  952.97), SIMDE_FLOAT32_C( -408.81),
                         SIMDE_FLOAT32_C(  653.26), SIMDE_FLOAT32_C(  365.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1224.19), SIMDE_FLOAT32_C(  540.60),
                         SIMDE_FLOAT32_C(  348.84), SIMDE_FLOAT32_C( 1301.55),
                         SIMDE_FLOAT32_C(   26.82), SIMDE_FLOAT32_C( -555.26),
                         SIMDE_FLOAT32_C(  758.44), SIMDE_FLOAT32_C( -272.19)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  185.82), SIMDE_FLOAT32_C(  -69.85),
                         SIMDE_FLOAT32_C( -529.83), SIMDE_FLOAT32_C(    7.18),
                         SIMDE_FLOAT32_C(  181.46), SIMDE_FLOAT32_C( -392.96),
                         SIMDE_FLOAT32_C( -825.54), SIMDE_FLOAT32_C(  -73.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -863.74), SIMDE_FLOAT32_C(  538.93),
                         SIMDE_FLOAT32_C(  867.32), SIMDE_FLOAT32_C( -263.67),
                         SIMDE_FLOAT32_C(   54.32), SIMDE_FLOAT32_C(  185.31),
                         SIMDE_FLOAT32_C( -761.42), SIMDE_FLOAT32_C( -272.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -677.92), SIMDE_FLOAT32_C(  469.08),
                         SIMDE_FLOAT32_C(  337.49), SIMDE_FLOAT32_C( -256.49),
                         SIMDE_FLOAT32_C(  235.78), SIMDE_FLOAT32_C( -207.65),
                         SIMDE_FLOAT32_C(-1586.96), SIMDE_FLOAT32_C( -345.41)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  693.17), SIMDE_FLOAT32_C( -668.89),
                         SIMDE_FLOAT32_C(  -84.19), SIMDE_FLOAT32_C( -965.81),
                         SIMDE_FLOAT32_C(   87.16), SIMDE_FLOAT32_C( -403.06),
                         SIMDE_FLOAT32_C(  609.16), SIMDE_FLOAT32_C( -596.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -8.20), SIMDE_FLOAT32_C(  127.25),
                         SIMDE_FLOAT32_C( -585.64), SIMDE_FLOAT32_C( -146.63),
                         SIMDE_FLOAT32_C(  610.52), SIMDE_FLOAT32_C(  318.25),
                         SIMDE_FLOAT32_C( -951.82), SIMDE_FLOAT32_C(   72.45)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  684.97), SIMDE_FLOAT32_C( -541.64),
                         SIMDE_FLOAT32_C( -669.83), SIMDE_FLOAT32_C(-1112.44),
                         SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  -84.81),
                         SIMDE_FLOAT32_C( -342.66), SIMDE_FLOAT32_C( -524.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -894.89), SIMDE_FLOAT32_C(  538.71),
                         SIMDE_FLOAT32_C(  705.28), SIMDE_FLOAT32_C(  408.87),
                         SIMDE_FLOAT32_C(  595.54), SIMDE_FLOAT32_C(  916.74),
                         SIMDE_FLOAT32_C(  901.91), SIMDE_FLOAT32_C( -728.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -290.65), SIMDE_FLOAT32_C(  876.93),
                         SIMDE_FLOAT32_C(   99.14), SIMDE_FLOAT32_C(  948.23),
                         SIMDE_FLOAT32_C( -630.32), SIMDE_FLOAT32_C( -883.56),
                         SIMDE_FLOAT32_C(  844.54), SIMDE_FLOAT32_C(  507.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1185.54), SIMDE_FLOAT32_C( 1415.64),
                         SIMDE_FLOAT32_C(  804.42), SIMDE_FLOAT32_C( 1357.10),
                         SIMDE_FLOAT32_C(  -34.78), SIMDE_FLOAT32_C(   33.18),
                         SIMDE_FLOAT32_C( 1746.45), SIMDE_FLOAT32_C( -221.32)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  126.73), SIMDE_FLOAT32_C( -250.52),
                         SIMDE_FLOAT32_C( -981.38), SIMDE_FLOAT32_C(  834.39),
                         SIMDE_FLOAT32_C(  -38.78), SIMDE_FLOAT32_C(  -35.08),
                         SIMDE_FLOAT32_C(  480.59), SIMDE_FLOAT32_C(  503.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -239.82), SIMDE_FLOAT32_C(   81.48),
                         SIMDE_FLOAT32_C( -961.01), SIMDE_FLOAT32_C( -408.34),
                         SIMDE_FLOAT32_C(  705.38), SIMDE_FLOAT32_C(   10.31),
                         SIMDE_FLOAT32_C(  562.97), SIMDE_FLOAT32_C(  952.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -113.09), SIMDE_FLOAT32_C( -169.04),
                         SIMDE_FLOAT32_C(-1942.39), SIMDE_FLOAT32_C(  426.05),
                         SIMDE_FLOAT32_C(  666.60), SIMDE_FLOAT32_C(  -24.77),
                         SIMDE_FLOAT32_C( 1043.56), SIMDE_FLOAT32_C( 1456.36)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_add_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_add_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  303.85), SIMDE_FLOAT64_C(  912.11),
                         SIMDE_FLOAT64_C( -650.18), SIMDE_FLOAT64_C(  473.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.04), SIMDE_FLOAT64_C( -576.86),
                         SIMDE_FLOAT64_C( -110.30), SIMDE_FLOAT64_C(  423.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  194.81), SIMDE_FLOAT64_C(  335.25),
                         SIMDE_FLOAT64_C( -760.48), SIMDE_FLOAT64_C(  897.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  979.21), SIMDE_FLOAT64_C(  275.57),
                         SIMDE_FLOAT64_C(  499.36), SIMDE_FLOAT64_C( -638.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  988.55), SIMDE_FLOAT64_C( -838.17),
                         SIMDE_FLOAT64_C( -141.00), SIMDE_FLOAT64_C( -264.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1967.76), SIMDE_FLOAT64_C( -562.60),
                         SIMDE_FLOAT64_C(  358.36), SIMDE_FLOAT64_C( -902.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -601.88), SIMDE_FLOAT64_C(  830.35),
                         SIMDE_FLOAT64_C( -809.06), SIMDE_FLOAT64_C(  444.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.19), SIMDE_FLOAT64_C( -659.35),
                         SIMDE_FLOAT64_C(  783.96), SIMDE_FLOAT64_C( -941.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -844.07), SIMDE_FLOAT64_C(  171.00),
                         SIMDE_FLOAT64_C(  -25.10), SIMDE_FLOAT64_C( -497.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -183.86), SIMDE_FLOAT64_C( -913.99),
                         SIMDE_FLOAT64_C(  681.98), SIMDE_FLOAT64_C(  778.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -143.75), SIMDE_FLOAT64_C( -874.49),
                         SIMDE_FLOAT64_C(  158.94), SIMDE_FLOAT64_C(  168.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -327.61), SIMDE_FLOAT64_C(-1788.48),
                         SIMDE_FLOAT64_C(  840.92), SIMDE_FLOAT64_C(  946.49)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -46.65), SIMDE_FLOAT64_C( -996.47),
                         SIMDE_FLOAT64_C(  910.52), SIMDE_FLOAT64_C( -114.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  749.53), SIMDE_FLOAT64_C(  540.86),
                         SIMDE_FLOAT64_C(   64.91), SIMDE_FLOAT64_C( -347.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  702.88), SIMDE_FLOAT64_C( -455.61),
                         SIMDE_FLOAT64_C(  975.43), SIMDE_FLOAT64_C( -461.62)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -739.61), SIMDE_FLOAT64_C(  573.43),
                         SIMDE_FLOAT64_C(  552.79), SIMDE_FLOAT64_C( -374.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -947.01), SIMDE_FLOAT64_C(  120.02),
                         SIMDE_FLOAT64_C(  463.99), SIMDE_FLOAT64_C(   50.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1686.62), SIMDE_FLOAT64_C(  693.45),
                         SIMDE_FLOAT64_C( 1016.78), SIMDE_FLOAT64_C( -323.99)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -187.57), SIMDE_FLOAT64_C(  -62.04),
                         SIMDE_FLOAT64_C(  957.24), SIMDE_FLOAT64_C(  581.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  950.16), SIMDE_FLOAT64_C(  298.02),
                         SIMDE_FLOAT64_C(  203.94), SIMDE_FLOAT64_C( -826.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  762.59), SIMDE_FLOAT64_C(  235.98),
                         SIMDE_FLOAT64_C( 1161.18), SIMDE_FLOAT64_C( -245.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  612.20), SIMDE_FLOAT64_C(  556.68),
                         SIMDE_FLOAT64_C(  158.92), SIMDE_FLOAT64_C(  158.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   66.07), SIMDE_FLOAT64_C( -695.86),
                         SIMDE_FLOAT64_C(  940.17), SIMDE_FLOAT64_C(  935.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  678.27), SIMDE_FLOAT64_C( -139.18),
                         SIMDE_FLOAT64_C( 1099.09), SIMDE_FLOAT64_C( 1093.62)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_add_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_addsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.97), SIMDE_FLOAT32_C( -119.17),
                         SIMDE_FLOAT32_C(   98.44), SIMDE_FLOAT32_C( -870.79),
                         SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C(  168.23),
                         SIMDE_FLOAT32_C(  291.85), SIMDE_FLOAT32_C(  803.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  437.26), SIMDE_FLOAT32_C(  621.28),
                         SIMDE_FLOAT32_C(  727.27), SIMDE_FLOAT32_C( -902.73),
                         SIMDE_FLOAT32_C( -279.74), SIMDE_FLOAT32_C(  960.47),
                         SIMDE_FLOAT32_C( -437.81), SIMDE_FLOAT32_C(  516.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -228.71), SIMDE_FLOAT32_C( -740.45),
                         SIMDE_FLOAT32_C(  825.71), SIMDE_FLOAT32_C(   31.94),
                         SIMDE_FLOAT32_C(  435.32), SIMDE_FLOAT32_C( -792.24),
                         SIMDE_FLOAT32_C( -145.96), SIMDE_FLOAT32_C(  287.46)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.72), SIMDE_FLOAT32_C(  881.45),
                         SIMDE_FLOAT32_C(  512.79), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  709.10), SIMDE_FLOAT32_C(  130.51),
                         SIMDE_FLOAT32_C( -836.20), SIMDE_FLOAT32_C(  276.45)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -410.67), SIMDE_FLOAT32_C(  408.11),
                         SIMDE_FLOAT32_C( -371.59), SIMDE_FLOAT32_C( -135.76),
                         SIMDE_FLOAT32_C( -896.75), SIMDE_FLOAT32_C( -185.21),
                         SIMDE_FLOAT32_C( -154.35), SIMDE_FLOAT32_C( -995.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -852.39), SIMDE_FLOAT32_C(  473.34),
                         SIMDE_FLOAT32_C(  141.20), SIMDE_FLOAT32_C(  -65.24),
                         SIMDE_FLOAT32_C( -187.65), SIMDE_FLOAT32_C(  315.72),
                         SIMDE_FLOAT32_C( -990.55), SIMDE_FLOAT32_C( 1271.59)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  792.33), SIMDE_FLOAT32_C( -677.48),
                         SIMDE_FLOAT32_C(  -78.97), SIMDE_FLOAT32_C(  595.95),
                         SIMDE_FLOAT32_C(  441.86), SIMDE_FLOAT32_C(  221.91),
                         SIMDE_FLOAT32_C(  688.66), SIMDE_FLOAT32_C( -937.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  615.36), SIMDE_FLOAT32_C( -858.28),
                         SIMDE_FLOAT32_C(  102.87), SIMDE_FLOAT32_C( -380.97),
                         SIMDE_FLOAT32_C( -155.81), SIMDE_FLOAT32_C( -426.12),
                         SIMDE_FLOAT32_C( -862.23), SIMDE_FLOAT32_C( -891.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1407.69), SIMDE_FLOAT32_C(  180.80),
                         SIMDE_FLOAT32_C(   23.90), SIMDE_FLOAT32_C(  976.92),
                         SIMDE_FLOAT32_C(  286.05), SIMDE_FLOAT32_C(  648.03),
                         SIMDE_FLOAT32_C( -173.57), SIMDE_FLOAT32_C(  -45.90)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -493.40), SIMDE_FLOAT32_C( -257.06),
                         SIMDE_FLOAT32_C( -968.46), SIMDE_FLOAT32_C(  634.36),
                         SIMDE_FLOAT32_C( -600.69), SIMDE_FLOAT32_C( -769.31),
                         SIMDE_FLOAT32_C(  230.22), SIMDE_FLOAT32_C( -863.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -678.13), SIMDE_FLOAT32_C(  166.99),
                         SIMDE_FLOAT32_C(  125.37), SIMDE_FLOAT32_C( -846.30),
                         SIMDE_FLOAT32_C(  414.00), SIMDE_FLOAT32_C( -144.57),
                         SIMDE_FLOAT32_C(  -43.08), SIMDE_FLOAT32_C(  287.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1171.53), SIMDE_FLOAT32_C( -424.05),
                         SIMDE_FLOAT32_C( -843.09), SIMDE_FLOAT32_C( 1480.66),
                         SIMDE_FLOAT32_C( -186.69), SIMDE_FLOAT32_C( -624.74),
                         SIMDE_FLOAT32_C(  187.14), SIMDE_FLOAT32_C(-1151.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -449.73), SIMDE_FLOAT32_C( -350.27),
                         SIMDE_FLOAT32_C( -591.20), SIMDE_FLOAT32_C(  571.44),
                         SIMDE_FLOAT32_C(  787.95), SIMDE_FLOAT32_C(  514.78),
                         SIMDE_FLOAT32_C( -355.32), SIMDE_FLOAT32_C(  545.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  341.77), SIMDE_FLOAT32_C( -839.01),
                         SIMDE_FLOAT32_C(   -9.88), SIMDE_FLOAT32_C(  193.01),
                         SIMDE_FLOAT32_C(  871.45), SIMDE_FLOAT32_C( -840.06),
                         SIMDE_FLOAT32_C(  689.52), SIMDE_FLOAT32_C( -902.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -107.96), SIMDE_FLOAT32_C(  488.74),
                         SIMDE_FLOAT32_C( -601.08), SIMDE_FLOAT32_C(  378.43),
                         SIMDE_FLOAT32_C( 1659.40), SIMDE_FLOAT32_C( 1354.84),
                         SIMDE_FLOAT32_C(  334.20), SIMDE_FLOAT32_C( 1448.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -336.63), SIMDE_FLOAT32_C(  960.76),
                         SIMDE_FLOAT32_C(  657.64), SIMDE_FLOAT32_C( -548.45),
                         SIMDE_FLOAT32_C( -101.48), SIMDE_FLOAT32_C( -271.70),
                         SIMDE_FLOAT32_C(   23.46), SIMDE_FLOAT32_C(  562.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -564.95), SIMDE_FLOAT32_C( -418.72),
                         SIMDE_FLOAT32_C( -693.90), SIMDE_FLOAT32_C( -314.48),
                         SIMDE_FLOAT32_C( -760.76), SIMDE_FLOAT32_C(    7.61),
                         SIMDE_FLOAT32_C(  228.32), SIMDE_FLOAT32_C( -230.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -901.58), SIMDE_FLOAT32_C( 1379.48),
                         SIMDE_FLOAT32_C(  -36.26), SIMDE_FLOAT32_C( -233.97),
                         SIMDE_FLOAT32_C( -862.24), SIMDE_FLOAT32_C( -279.31),
                         SIMDE_FLOAT32_C(  251.78), SIMDE_FLOAT32_C(  792.77)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -451.91), SIMDE_FLOAT32_C( -184.14),
                         SIMDE_FLOAT32_C( -772.77), SIMDE_FLOAT32_C( -278.00),
                         SIMDE_FLOAT32_C( -640.89), SIMDE_FLOAT32_C(  -35.35),
                         SIMDE_FLOAT32_C( -518.18), SIMDE_FLOAT32_C( -851.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.24), SIMDE_FLOAT32_C(  636.58),
                         SIMDE_FLOAT32_C( -808.67), SIMDE_FLOAT32_C(  166.94),
                         SIMDE_FLOAT32_C( -359.45), SIMDE_FLOAT32_C( -888.48),
                         SIMDE_FLOAT32_C( -553.07), SIMDE_FLOAT32_C( -570.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -604.15), SIMDE_FLOAT32_C( -820.72),
                         SIMDE_FLOAT32_C(-1581.44), SIMDE_FLOAT32_C( -444.94),
                         SIMDE_FLOAT32_C(-1000.34), SIMDE_FLOAT32_C(  853.13),
                         SIMDE_FLOAT32_C(-1071.25), SIMDE_FLOAT32_C( -281.11)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.71), SIMDE_FLOAT32_C( -782.28),
                         SIMDE_FLOAT32_C(  533.36), SIMDE_FLOAT32_C(  848.42),
                         SIMDE_FLOAT32_C(  345.49), SIMDE_FLOAT32_C( -110.04),
                         SIMDE_FLOAT32_C( -550.91), SIMDE_FLOAT32_C(   -5.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  186.13), SIMDE_FLOAT32_C( -310.95),
                         SIMDE_FLOAT32_C(  742.56), SIMDE_FLOAT32_C( -943.39),
                         SIMDE_FLOAT32_C( -294.98), SIMDE_FLOAT32_C( -455.35),
                         SIMDE_FLOAT32_C(  262.46), SIMDE_FLOAT32_C(  299.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  182.42), SIMDE_FLOAT32_C( -471.33),
                         SIMDE_FLOAT32_C( 1275.92), SIMDE_FLOAT32_C( 1791.81),
                         SIMDE_FLOAT32_C(   50.51), SIMDE_FLOAT32_C(  345.31),
                         SIMDE_FLOAT32_C( -288.45), SIMDE_FLOAT32_C( -305.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_addsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_addsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  715.06), SIMDE_FLOAT64_C(  168.23),
                         SIMDE_FLOAT64_C(  291.85), SIMDE_FLOAT64_C(  803.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -279.74), SIMDE_FLOAT64_C(  960.47),
                         SIMDE_FLOAT64_C( -437.81), SIMDE_FLOAT64_C(  516.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  435.32), SIMDE_FLOAT64_C( -792.24),
                         SIMDE_FLOAT64_C( -145.96), SIMDE_FLOAT64_C(  287.46)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -665.97), SIMDE_FLOAT64_C( -119.17),
                         SIMDE_FLOAT64_C(   98.44), SIMDE_FLOAT64_C( -870.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  437.26), SIMDE_FLOAT64_C(  621.28),
                         SIMDE_FLOAT64_C(  727.27), SIMDE_FLOAT64_C( -902.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -228.71), SIMDE_FLOAT64_C( -740.45),
                         SIMDE_FLOAT64_C(  825.71), SIMDE_FLOAT64_C(   31.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  709.10), SIMDE_FLOAT64_C(  130.51),
                         SIMDE_FLOAT64_C( -836.20), SIMDE_FLOAT64_C(  276.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -896.75), SIMDE_FLOAT64_C( -185.21),
                         SIMDE_FLOAT64_C( -154.35), SIMDE_FLOAT64_C( -995.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -187.65), SIMDE_FLOAT64_C(  315.72),
                         SIMDE_FLOAT64_C( -990.55), SIMDE_FLOAT64_C( 1271.59)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -441.72), SIMDE_FLOAT64_C(  881.45),
                         SIMDE_FLOAT64_C(  512.79), SIMDE_FLOAT64_C( -201.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -410.67), SIMDE_FLOAT64_C(  408.11),
                         SIMDE_FLOAT64_C( -371.59), SIMDE_FLOAT64_C( -135.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -852.39), SIMDE_FLOAT64_C(  473.34),
                         SIMDE_FLOAT64_C(  141.20), SIMDE_FLOAT64_C(  -65.24)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  441.86), SIMDE_FLOAT64_C(  221.91),
                         SIMDE_FLOAT64_C(  688.66), SIMDE_FLOAT64_C( -937.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -155.81), SIMDE_FLOAT64_C( -426.12),
                         SIMDE_FLOAT64_C( -862.23), SIMDE_FLOAT64_C( -891.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  286.05), SIMDE_FLOAT64_C(  648.03),
                         SIMDE_FLOAT64_C( -173.57), SIMDE_FLOAT64_C(  -45.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  792.33), SIMDE_FLOAT64_C( -677.48),
                         SIMDE_FLOAT64_C(  -78.97), SIMDE_FLOAT64_C(  595.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  615.36), SIMDE_FLOAT64_C( -858.28),
                         SIMDE_FLOAT64_C(  102.87), SIMDE_FLOAT64_C( -380.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 1407.69), SIMDE_FLOAT64_C(  180.80),
                         SIMDE_FLOAT64_C(   23.90), SIMDE_FLOAT64_C(  976.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -600.69), SIMDE_FLOAT64_C( -769.31),
                         SIMDE_FLOAT64_C(  230.22), SIMDE_FLOAT64_C( -863.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  414.00), SIMDE_FLOAT64_C( -144.57),
                         SIMDE_FLOAT64_C(  -43.08), SIMDE_FLOAT64_C(  287.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -186.69), SIMDE_FLOAT64_C( -624.74),
                         SIMDE_FLOAT64_C(  187.14), SIMDE_FLOAT64_C(-1151.43)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -493.40), SIMDE_FLOAT64_C( -257.06),
                         SIMDE_FLOAT64_C( -968.46), SIMDE_FLOAT64_C(  634.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -678.13), SIMDE_FLOAT64_C(  166.99),
                         SIMDE_FLOAT64_C(  125.37), SIMDE_FLOAT64_C( -846.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1171.53), SIMDE_FLOAT64_C( -424.05),
                         SIMDE_FLOAT64_C( -843.09), SIMDE_FLOAT64_C( 1480.66)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_addsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -927.26), SIMDE_FLOAT32_C( -802.03),
                         SIMDE_FLOAT32_C( -266.41), SIMDE_FLOAT32_C(  -50.41),
                         SIMDE_FLOAT32_C( -309.19), SIMDE_FLOAT32_C( -707.19),
                         SIMDE_FLOAT32_C( -220.07), SIMDE_FLOAT32_C(  127.67)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -205.91), SIMDE_FLOAT32_C( -275.07),
                         SIMDE_FLOAT32_C(  -13.57), SIMDE_FLOAT32_C(  990.91),
                         SIMDE_FLOAT32_C( -167.84), SIMDE_FLOAT32_C(  346.85),
                         SIMDE_FLOAT32_C(  124.29), SIMDE_FLOAT32_C(  759.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.09), SIMDE_FLOAT32_C(   -2.13),
                         SIMDE_FLOAT32_C(   -8.07), SIMDE_FLOAT32_C(    3.03),
                         SIMDE_FLOAT32_C( -130.56), SIMDE_FLOAT32_C(    2.50),
                         SIMDE_FLOAT32_C(   54.02), SIMDE_FLOAT32_C(    2.96)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -39.85), SIMDE_FLOAT32_C(  325.28),
                         SIMDE_FLOAT32_C(  658.09), SIMDE_FLOAT32_C(  797.01),
                         SIMDE_FLOAT32_C( -512.38), SIMDE_FLOAT32_C( -352.93),
                         SIMDE_FLOAT32_C( -357.04), SIMDE_FLOAT32_C( -456.94)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -802.91), SIMDE_FLOAT32_C(  574.48),
                         SIMDE_FLOAT32_C( -277.42), SIMDE_FLOAT32_C(  470.68),
                         SIMDE_FLOAT32_C( -575.30), SIMDE_FLOAT32_C(  -85.17),
                         SIMDE_FLOAT32_C(  928.67), SIMDE_FLOAT32_C(  878.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -2.13), SIMDE_FLOAT32_C(    2.04),
                         SIMDE_FLOAT32_C(    2.01), SIMDE_FLOAT32_C(    3.05),
                         SIMDE_FLOAT32_C( -512.25), SIMDE_FLOAT32_C(  -80.17),
                         SIMDE_FLOAT32_C(    2.50), SIMDE_FLOAT32_C(    3.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  758.85), SIMDE_FLOAT32_C(  749.41),
                         SIMDE_FLOAT32_C(  129.33), SIMDE_FLOAT32_C( -389.28),
                         SIMDE_FLOAT32_C( -248.13), SIMDE_FLOAT32_C(  236.41),
                         SIMDE_FLOAT32_C(  416.63), SIMDE_FLOAT32_C( -413.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -615.54), SIMDE_FLOAT32_C(  496.18),
                         SIMDE_FLOAT32_C( -485.54), SIMDE_FLOAT32_C( -818.26),
                         SIMDE_FLOAT32_C( -139.14), SIMDE_FLOAT32_C(  955.99),
                         SIMDE_FLOAT32_C(  356.33), SIMDE_FLOAT32_C( -498.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  614.53), SIMDE_FLOAT32_C(    2.88),
                         SIMDE_FLOAT32_C(  128.27), SIMDE_FLOAT32_C(   -3.01),
                         SIMDE_FLOAT32_C( -136.13), SIMDE_FLOAT32_C(    3.69),
                         SIMDE_FLOAT32_C(  288.00), SIMDE_FLOAT32_C( -400.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.10), SIMDE_FLOAT32_C( -368.55),
                         SIMDE_FLOAT32_C(  657.24), SIMDE_FLOAT32_C(  939.62),
                         SIMDE_FLOAT32_C(  -50.98), SIMDE_FLOAT32_C(  313.56),
                         SIMDE_FLOAT32_C( -914.58), SIMDE_FLOAT32_C(  -29.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.92), SIMDE_FLOAT32_C( -475.65),
                         SIMDE_FLOAT32_C( -524.29), SIMDE_FLOAT32_C(  537.04),
                         SIMDE_FLOAT32_C( -280.43), SIMDE_FLOAT32_C(  379.54),
                         SIMDE_FLOAT32_C(  -38.50), SIMDE_FLOAT32_C( -188.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.04), SIMDE_FLOAT32_C( -336.52),
                         SIMDE_FLOAT32_C(  512.03), SIMDE_FLOAT32_C(  521.04),
                         SIMDE_FLOAT32_C(  -34.03), SIMDE_FLOAT32_C(  313.54),
                         SIMDE_FLOAT32_C(   -2.00), SIMDE_FLOAT32_C(  -10.75)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  159.88), SIMDE_FLOAT32_C( -559.41),
                         SIMDE_FLOAT32_C(  -99.24), SIMDE_FLOAT32_C( -420.50),
                         SIMDE_FLOAT32_C( -953.72), SIMDE_FLOAT32_C(  849.74),
                         SIMDE_FLOAT32_C(   80.27), SIMDE_FLOAT32_C(  -41.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  457.08), SIMDE_FLOAT32_C( -505.60),
                         SIMDE_FLOAT32_C( -390.51), SIMDE_FLOAT32_C( -524.68),
                         SIMDE_FLOAT32_C( -419.12), SIMDE_FLOAT32_C(  955.42),
                         SIMDE_FLOAT32_C(  180.08), SIMDE_FLOAT32_C(   33.67)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  132.50), SIMDE_FLOAT32_C(   -2.14),
                         SIMDE_FLOAT32_C(  -97.13), SIMDE_FLOAT32_C(   -2.03),
                         SIMDE_FLOAT32_C(   -3.00), SIMDE_FLOAT32_C(  785.16),
                         SIMDE_FLOAT32_C(   40.00), SIMDE_FLOAT32_C(   33.66)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  157.14), SIMDE_FLOAT32_C( -391.25),
                         SIMDE_FLOAT32_C( -362.22), SIMDE_FLOAT32_C( -137.98),
                         SIMDE_FLOAT32_C( -303.90), SIMDE_FLOAT32_C(  545.52),
                         SIMDE_FLOAT32_C( -383.06), SIMDE_FLOAT32_C(  973.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -973.80), SIMDE_FLOAT32_C(  457.53),
                         SIMDE_FLOAT32_C( -199.04), SIMDE_FLOAT32_C(  856.68),
                         SIMDE_FLOAT32_C( -830.67), SIMDE_FLOAT32_C( -121.42),
                         SIMDE_FLOAT32_C(  772.32), SIMDE_FLOAT32_C(  704.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.27), SIMDE_FLOAT32_C(  385.00),
                         SIMDE_FLOAT32_C( -133.03), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(   -2.12), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(    2.02), SIMDE_FLOAT32_C(  704.14)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.14), SIMDE_FLOAT32_C(  176.96),
                         SIMDE_FLOAT32_C(  525.37), SIMDE_FLOAT32_C(  924.18),
                         SIMDE_FLOAT32_C( -300.50), SIMDE_FLOAT32_C( -450.02),
                         SIMDE_FLOAT32_C(  708.11), SIMDE_FLOAT32_C(  742.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  647.68), SIMDE_FLOAT32_C(  632.57),
                         SIMDE_FLOAT32_C( -972.04), SIMDE_FLOAT32_C( -483.76),
                         SIMDE_FLOAT32_C(  274.26), SIMDE_FLOAT32_C(  570.79),
                         SIMDE_FLOAT32_C( -945.60), SIMDE_FLOAT32_C( -519.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  646.13), SIMDE_FLOAT32_C(    2.25),
                         SIMDE_FLOAT32_C(  524.04), SIMDE_FLOAT32_C(    3.52),
                         SIMDE_FLOAT32_C(  256.00), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C(  640.09), SIMDE_FLOAT32_C(  518.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  361.93), SIMDE_FLOAT32_C( -223.38),
                         SIMDE_FLOAT32_C(  -51.19), SIMDE_FLOAT32_C( -300.56),
                         SIMDE_FLOAT32_C(  363.29), SIMDE_FLOAT32_C(  804.04),
                         SIMDE_FLOAT32_C(   99.54), SIMDE_FLOAT32_C( -622.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  446.79), SIMDE_FLOAT32_C(  300.89),
                         SIMDE_FLOAT32_C(  727.13), SIMDE_FLOAT32_C( -671.93),
                         SIMDE_FLOAT32_C(  708.76), SIMDE_FLOAT32_C( -834.24),
                         SIMDE_FLOAT32_C( -881.82), SIMDE_FLOAT32_C(  430.54)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  296.79), SIMDE_FLOAT32_C(  150.38),
                         SIMDE_FLOAT32_C(    2.07), SIMDE_FLOAT32_C(   -2.10),
                         SIMDE_FLOAT32_C(    2.77), SIMDE_FLOAT32_C(  768.03),
                         SIMDE_FLOAT32_C(    3.06), SIMDE_FLOAT32_C(    2.30)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_and_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_and_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -309.19), SIMDE_FLOAT64_C( -707.19),
                         SIMDE_FLOAT64_C( -220.07), SIMDE_FLOAT64_C(  127.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -167.84), SIMDE_FLOAT64_C(  346.85),
                         SIMDE_FLOAT64_C(  124.29), SIMDE_FLOAT64_C(  759.96)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -130.56), SIMDE_FLOAT64_C(    2.50),
                         SIMDE_FLOAT64_C(   54.02), SIMDE_FLOAT64_C(    2.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -927.26), SIMDE_FLOAT64_C( -802.03),
                         SIMDE_FLOAT64_C( -266.41), SIMDE_FLOAT64_C(  -50.41)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.91), SIMDE_FLOAT64_C( -275.07),
                         SIMDE_FLOAT64_C(  -13.57), SIMDE_FLOAT64_C(  990.91)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -3.09), SIMDE_FLOAT64_C(   -2.13),
                         SIMDE_FLOAT64_C(   -8.07), SIMDE_FLOAT64_C(    3.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.38), SIMDE_FLOAT64_C( -352.93),
                         SIMDE_FLOAT64_C( -357.04), SIMDE_FLOAT64_C( -456.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -575.30), SIMDE_FLOAT64_C(  -85.17),
                         SIMDE_FLOAT64_C(  928.67), SIMDE_FLOAT64_C(  878.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.25), SIMDE_FLOAT64_C(  -80.17),
                         SIMDE_FLOAT64_C(    2.50), SIMDE_FLOAT64_C(    3.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -39.85), SIMDE_FLOAT64_C(  325.28),
                         SIMDE_FLOAT64_C(  658.09), SIMDE_FLOAT64_C(  797.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -802.91), SIMDE_FLOAT64_C(  574.48),
                         SIMDE_FLOAT64_C( -277.42), SIMDE_FLOAT64_C(  470.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.13), SIMDE_FLOAT64_C(    2.04),
                         SIMDE_FLOAT64_C(    2.01), SIMDE_FLOAT64_C(    3.05)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.13), SIMDE_FLOAT64_C(  236.41),
                         SIMDE_FLOAT64_C(  416.63), SIMDE_FLOAT64_C( -413.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -139.14), SIMDE_FLOAT64_C(  955.99),
                         SIMDE_FLOAT64_C(  356.33), SIMDE_FLOAT64_C( -498.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -136.13), SIMDE_FLOAT64_C(    3.69),
                         SIMDE_FLOAT64_C(  288.00), SIMDE_FLOAT64_C( -400.79)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  758.85), SIMDE_FLOAT64_C(  749.41),
                         SIMDE_FLOAT64_C(  129.33), SIMDE_FLOAT64_C( -389.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -615.54), SIMDE_FLOAT64_C(  496.18),
                         SIMDE_FLOAT64_C( -485.54), SIMDE_FLOAT64_C( -818.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  614.53), SIMDE_FLOAT64_C(    2.88),
                         SIMDE_FLOAT64_C(  128.27), SIMDE_FLOAT64_C(   -3.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -50.98), SIMDE_FLOAT64_C(  313.56),
                         SIMDE_FLOAT64_C( -914.58), SIMDE_FLOAT64_C(  -29.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -280.43), SIMDE_FLOAT64_C(  379.54),
                         SIMDE_FLOAT64_C(  -38.50), SIMDE_FLOAT64_C( -188.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -34.03), SIMDE_FLOAT64_C(  313.54),
                         SIMDE_FLOAT64_C(   -2.00), SIMDE_FLOAT64_C(  -10.75)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -131.10), SIMDE_FLOAT64_C( -368.55),
                         SIMDE_FLOAT64_C(  657.24), SIMDE_FLOAT64_C(  939.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -195.92), SIMDE_FLOAT64_C( -475.65),
                         SIMDE_FLOAT64_C( -524.29), SIMDE_FLOAT64_C(  537.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -131.04), SIMDE_FLOAT64_C( -336.52),
                         SIMDE_FLOAT64_C(  512.03), SIMDE_FLOAT64_C(  521.04)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_and_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_andnot_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1269691626), INT32_C(-1170050076), INT32_C( -309781764), INT32_C( -576457271),
                            INT32_C( -634907762), INT32_C( 2098123667), INT32_C( -562209537), INT32_C(    5131913)),
      simde_mm256_set_epi32(INT32_C( 1938996560), INT32_C( -950945230), INT32_C( 1149254280), INT32_C(   44378753),
                            INT32_C( 2057504516), INT32_C( -993118301), INT32_C( 1739559582), INT32_C( -627102775)),
      simde_mm256_set_epi32(INT32_C( 1132508224), INT32_C( 1158776850), INT32_C(       8192), INT32_C(   33819136),
                            INT32_C(  545457152), INT32_C(-2134891488), INT32_C(  562201088), INT32_C( -628022976)) },
    { simde_mm256_set_epi32(INT32_C( 1623231278), INT32_C( 1012862807), INT32_C(-1490329263), INT32_C( -978121763),
                            INT32_C( 1155479170), INT32_C( 1443672525), INT32_C(-2006927873), INT32_C(-1659310326)),
      simde_mm256_set_epi32(INT32_C( 1899349789), INT32_C( -971300838), INT32_C(-1615418151), INT32_C( 1727488659),
                            INT32_C( -760518716), INT32_C( -855193027), INT32_C(-1052461502), INT32_C( 1027044741)),
      simde_mm256_set_epi32(INT32_C(  288703505), INT32_C(-1040179192), INT32_C(  412388488), INT32_C(  574906370),
                            INT32_C(-1843379900), INT32_C(-1996338640), INT32_C( 1090781696), INT32_C(  539431045)) },
    { simde_mm256_set_epi32(INT32_C(-2122027976), INT32_C( -148145974), INT32_C(    -727916), INT32_C(  -26694351),
                            INT32_C(-1526957699), INT32_C( -878651731), INT32_C( 1530541127), INT32_C(-1559858122)),
      simde_mm256_set_epi32(INT32_C( -534865702), INT32_C(-2025680665), INT32_C(  838358535), INT32_C( 1081018378),
                            INT32_C(-1920205149), INT32_C( -965251235), INT32_C(  386054154), INT32_C(-2050252028)),
      simde_mm256_set_epi32(INT32_C( 1612353730), INT32_C(    4227109), INT32_C(     528899), INT32_C(     458762),
                            INT32_C(  151225986), INT32_C(   72821072), INT32_C(   67143688), INT32_C(   80315136)) },
    { simde_mm256_set_epi32(INT32_C(  677275617), INT32_C(-1590450048), INT32_C( 1228022027), INT32_C(-1869880241),
                            INT32_C( -606167369), INT32_C( 1388808224), INT32_C(  759425545), INT32_C(  885944499)),
      simde_mm256_set_epi32(INT32_C(  148370019), INT32_C(    1263704), INT32_C( -153021241), INT32_C( 1201345211),
                            INT32_C( 1277824171), INT32_C(-1597492935), INT32_C(  875204555), INT32_C(  494146139)),
      simde_mm256_set_epi32(INT32_C(    8491010), INT32_C(      16472), INT32_C(-1228860220), INT32_C( 1192235696),
                            INT32_C(   69206024), INT32_C(-1610075879), INT32_C(  271058370), INT32_C(  154141256)) },
    { simde_mm256_set_epi32(INT32_C(-1186629793), INT32_C(-1939451012), INT32_C( 1901741359), INT32_C(  320110090),
                            INT32_C(  759094695), INT32_C(-2033042315), INT32_C(-1537152402), INT32_C( -430790655)),
      simde_mm256_set_epi32(INT32_C(-1742460754), INT32_C(  244002796), INT32_C( 1060007632), INT32_C( 2113362450),
                            INT32_C( 1987282511), INT32_C(-1021964277), INT32_C(  124383649), INT32_C( -826572412)),
      simde_mm256_set_epi32(INT32_C(    2099360), INT32_C(   42544256), INT32_C(  237251280), INT32_C( 1826816016),
                            INT32_C( 1379992136), INT32_C( 1090781194), INT32_C(   50925953), INT32_C(  145293700)) },
    { simde_mm256_set_epi32(INT32_C( 1671320788), INT32_C(   16189529), INT32_C(-1485817573), INT32_C(  275783232),
                            INT32_C( -537268511), INT32_C(-1218162385), INT32_C(  832178136), INT32_C(-1011542055)),
      simde_mm256_set_epi32(INT32_C( 1761443736), INT32_C(   53908736), INT32_C(-1387734476), INT32_C(  460708168),
                            INT32_C( 1701279267), INT32_C( 1520265677), INT32_C(-1733909786), INT32_C(  106810720)),
      simde_mm256_set_epi32(INT32_C(  140585736), INT32_C(   50369792), INT32_C(  134791716), INT32_C(  184926472),
                            INT32_C(  537268226), INT32_C( 1217996992), INT32_C(-2010865626), INT32_C(   71878688)) },
    { simde_mm256_set_epi32(INT32_C( 1589201791), INT32_C(-1842375346), INT32_C(-2000660080), INT32_C( -325292371),
                            INT32_C(  507717673), INT32_C(-1795722597), INT32_C( -367442910), INT32_C(  -52157671)),
      simde_mm256_set_epi32(INT32_C(  948353791), INT32_C( -947869222), INT32_C( 1848909924), INT32_C( 1620600148),
                            INT32_C(-1789584398), INT32_C(-1352425263), INT32_C( 1123687286), INT32_C( -367624963)),
      simde_mm256_set_epi32(INT32_C(  537309312), INT32_C( 1166026896), INT32_C( 1714692196), INT32_C(        336),
                            INT32_C(-2129390638), INT32_C(  721453120), INT32_C(   14818132), INT32_C(   34757860)) },
    { simde_mm256_set_epi32(INT32_C(  296819835), INT32_C(  519012224), INT32_C( 1292929763), INT32_C( 1826612612),
                            INT32_C(-1166644367), INT32_C(-1218677893), INT32_C( 1596508105), INT32_C(  479196973)),
      simde_mm256_set_epi32(INT32_C(-1798100031), INT32_C( 1081570687), INT32_C( -734752872), INT32_C( 1848654589),
                            INT32_C(-1212254773), INT32_C( 1838985430), INT32_C( 1056167509), INT32_C(-1850230510)),
      simde_mm256_set_epi32(INT32_C(-2076040320), INT32_C( 1074790527), INT32_C(-1876687592), INT32_C(   35658361),
                            INT32_C(   92804234), INT32_C( 1216381060), INT32_C(  550703124), INT32_C(-2127558638)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castps_si256(simde_mm256_andnot_ps(simde_mm256_castsi256_ps(test_vec[i].a), simde_mm256_castsi256_ps(test_vec[i].b)));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_andnot_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-8439082616481350053), INT64_C(-1591722586538286382),
                             INT64_C( 1596940992066035921), INT64_C( 7218980746644065590)),
      simde_mm256_set_epi64x(INT64_C(-2889835723484335944), INT64_C( 5702037989414933855),
                             INT64_C(-7588441850660451968), INT64_C( 5622786757188964496)),
      simde_mm256_set_epi64x(INT64_C( 6126343173960302752), INT64_C(  432527267492795661),
                             INT64_C(-9182839637781772032), INT64_C(  720582821084942464)) },
    { simde_mm256_set_epi64x(INT64_C(-3971123103425330466), INT64_C(  247751845170013697),
                             INT64_C( 5585328925838094706), INT64_C(  530115277368604043)),
      simde_mm256_set_epi64x(INT64_C( 4478919331480512906), INT64_C( 7586040465456902581),
                             INT64_C(-3267189003236240754), INT64_C( 4065656935289916932)),
      simde_mm256_set_epi64x(INT64_C( 3893433775916460288), INT64_C( 7495967802570838452),
                             INT64_C(-7914921412211473780), INT64_C( 4045363244402936324)) },
    { simde_mm256_set_epi64x(INT64_C(-3585412687111992497), INT64_C( 6297904517919445636),
                             INT64_C( 3051626993143041669), INT64_C( 4507652791803794073)),
      simde_mm256_set_epi64x(INT64_C( 7790656180790731512), INT64_C(-2238278921609140434),
                             INT64_C(-3659407193774134076), INT64_C(-7376863833910103250)),
      simde_mm256_set_epi64x(INT64_C( 2306388938282574000), INT64_C(-6876986580769954518),
                             INT64_C(-4240666768871972800), INT64_C(-9142279579591991002)) },
    { simde_mm256_set_epi64x(INT64_C( 7999698065344811916), INT64_C(-7341244500866629440),
                             INT64_C(-7328850488568705697), INT64_C(-2323514350316525032)),
      simde_mm256_set_epi64x(INT64_C( -107804005911866164), INT64_C(  111123727598973975),
                             INT64_C(-1111380546027591655), INT64_C( 4764066650640007854)),
      simde_mm256_set_epi64x(INT64_C(-8034139356564159424), INT64_C(  108159439879631895),
                             INT64_C( 6958347297832099840), INT64_C(    7957580804685990)) },
    { simde_mm256_set_epi64x(INT64_C( 3459048579714364836), INT64_C(-3973289916381214951),
                             INT64_C(-7209230353107463172), INT64_C( 2930204184482970329)),
      simde_mm256_set_epi64x(INT64_C( 3010733025435453292), INT64_C( -745749005863907277),
                             INT64_C(-3524732567674843907), INT64_C(-5826758923945327044)),
      simde_mm256_set_epi64x(INT64_C(  704889912361353800), INT64_C( 3828781103108395042),
                             INT64_C( 4901042599637093377), INT64_C(-8718669257106881500)) },
    { simde_mm256_set_epi64x(INT64_C(-7592832401699875339), INT64_C(-8023654109997292762),
                             INT64_C(-2771476036962446296), INT64_C( 9102393041728593835)),
      simde_mm256_set_epi64x(INT64_C( 8663885080599503900), INT64_C(-7386785027439544145),
                             INT64_C( 8164489019718037552), INT64_C(  750237314916317106)),
      simde_mm256_set_epi64x(INT64_C( 7501880507188158472), INT64_C(  673462032523630729),
                             INT64_C( 2325549012813766672), INT64_C(   11611668710957072)) },
    { simde_mm256_set_epi64x(INT64_C(  845408412650914951), INT64_C(-8878005092884591737),
                             INT64_C( 8700006383250628168), INT64_C( 5164616504794613874)),
      simde_mm256_set_epi64x(INT64_C(-8091532354365363750), INT64_C(-8752462265867882388),
                             INT64_C( 4660987830245455204), INT64_C(-5583031631743087362)),
      simde_mm256_set_epi64x(INT64_C(-8934015756479190696), INT64_C(  144397281535078504),
                             INT64_C(     851058845950244), INT64_C(-5764308427349687156)) },
    { simde_mm256_set_epi64x(INT64_C( 2555908784249146521), INT64_C(-8475938792743727314),
                             INT64_C( 2225136272678261710), INT64_C( -363869634240011329)),
      simde_mm256_set_epi64x(INT64_C(-1884165091148513154), INT64_C(-7810796383227036924),
                             INT64_C(-3384871664970291123), INT64_C( 3413049808639883718)),
      simde_mm256_set_epi64x(INT64_C(-4286845753352634266), INT64_C( 1261025490606501888),
                             INT64_C(-4537798832575469567), INT64_C(  363824553704642624)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castpd_si256(simde_mm256_andnot_pd(simde_mm256_castsi256_pd(test_vec[i].a), simde_mm256_castsi256_pd(test_vec[i].b)));
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castps_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    17.89), SIMDE_FLOAT32_C(  -439.16),
                         SIMDE_FLOAT32_C(   198.42), SIMDE_FLOAT32_C(   352.58),
                         SIMDE_FLOAT32_C(   461.89), SIMDE_FLOAT32_C(  -105.28),
                         SIMDE_FLOAT32_C(   143.68), SIMDE_FLOAT32_C(   337.71)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    17.89), SIMDE_FLOAT32_C(  -439.16),
                         SIMDE_FLOAT32_C(   198.42), SIMDE_FLOAT32_C(   352.58),
                         SIMDE_FLOAT32_C(   461.89), SIMDE_FLOAT32_C(  -105.28),
                         SIMDE_FLOAT32_C(   143.68), SIMDE_FLOAT32_C(   337.71)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   104.39), SIMDE_FLOAT32_C(    34.20),
                         SIMDE_FLOAT32_C(   868.43), SIMDE_FLOAT32_C(  -354.71),
                         SIMDE_FLOAT32_C(    71.91), SIMDE_FLOAT32_C(  -620.66),
                         SIMDE_FLOAT32_C(  -727.46), SIMDE_FLOAT32_C(   516.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   104.39), SIMDE_FLOAT32_C(    34.20),
                         SIMDE_FLOAT32_C(   868.43), SIMDE_FLOAT32_C(  -354.71),
                         SIMDE_FLOAT32_C(    71.91), SIMDE_FLOAT32_C(  -620.66),
                         SIMDE_FLOAT32_C(  -727.46), SIMDE_FLOAT32_C(   516.70)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -937.39),
                         SIMDE_FLOAT32_C(  -902.27), SIMDE_FLOAT32_C(  -540.76),
                         SIMDE_FLOAT32_C(  -319.95), SIMDE_FLOAT32_C(   472.57),
                         SIMDE_FLOAT32_C(  -514.05), SIMDE_FLOAT32_C(  -395.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -937.39),
                         SIMDE_FLOAT32_C(  -902.27), SIMDE_FLOAT32_C(  -540.76),
                         SIMDE_FLOAT32_C(  -319.95), SIMDE_FLOAT32_C(   472.57),
                         SIMDE_FLOAT32_C(  -514.05), SIMDE_FLOAT32_C(  -395.89)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -289.46), SIMDE_FLOAT32_C(  -292.09),
                         SIMDE_FLOAT32_C(   300.75), SIMDE_FLOAT32_C(   515.47),
                         SIMDE_FLOAT32_C(  -443.08), SIMDE_FLOAT32_C(   738.56),
                         SIMDE_FLOAT32_C(   388.31), SIMDE_FLOAT32_C(  -979.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -289.46), SIMDE_FLOAT32_C(  -292.09),
                         SIMDE_FLOAT32_C(   300.75), SIMDE_FLOAT32_C(   515.47),
                         SIMDE_FLOAT32_C(  -443.08), SIMDE_FLOAT32_C(   738.56),
                         SIMDE_FLOAT32_C(   388.31), SIMDE_FLOAT32_C(  -979.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -416.84), SIMDE_FLOAT32_C(  -145.54),
                         SIMDE_FLOAT32_C(   814.92), SIMDE_FLOAT32_C(  -389.04),
                         SIMDE_FLOAT32_C(   271.28), SIMDE_FLOAT32_C(   795.75),
                         SIMDE_FLOAT32_C(   715.64), SIMDE_FLOAT32_C(  -282.83)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -416.84), SIMDE_FLOAT32_C(  -145.54),
                         SIMDE_FLOAT32_C(   814.92), SIMDE_FLOAT32_C(  -389.04),
                         SIMDE_FLOAT32_C(   271.28), SIMDE_FLOAT32_C(   795.75),
                         SIMDE_FLOAT32_C(   715.64), SIMDE_FLOAT32_C(  -282.83)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    36.85), SIMDE_FLOAT32_C(   358.48),
                         SIMDE_FLOAT32_C(  -119.62), SIMDE_FLOAT32_C(   444.11),
                         SIMDE_FLOAT32_C(   221.60), SIMDE_FLOAT32_C(  -300.30),
                         SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   969.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    36.85), SIMDE_FLOAT32_C(   358.48),
                         SIMDE_FLOAT32_C(  -119.62), SIMDE_FLOAT32_C(   444.11),
                         SIMDE_FLOAT32_C(   221.60), SIMDE_FLOAT32_C(  -300.30),
                         SIMDE_FLOAT32_C(   -48.26), SIMDE_FLOAT32_C(   969.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -242.13), SIMDE_FLOAT32_C(  -172.63),
                         SIMDE_FLOAT32_C(  -556.49), SIMDE_FLOAT32_C(  -637.53),
                         SIMDE_FLOAT32_C(    39.04), SIMDE_FLOAT32_C(  -822.45),
                         SIMDE_FLOAT32_C(  -881.86), SIMDE_FLOAT32_C(   639.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -242.13), SIMDE_FLOAT32_C(  -172.63),
                         SIMDE_FLOAT32_C(  -556.49), SIMDE_FLOAT32_C(  -637.53),
                         SIMDE_FLOAT32_C(    39.04), SIMDE_FLOAT32_C(  -822.45),
                         SIMDE_FLOAT32_C(  -881.86), SIMDE_FLOAT32_C(   639.51)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   262.21), SIMDE_FLOAT32_C(   189.91),
                         SIMDE_FLOAT32_C(  -147.18), SIMDE_FLOAT32_C(  -378.37),
                         SIMDE_FLOAT32_C(  -474.15), SIMDE_FLOAT32_C(   728.93),
                         SIMDE_FLOAT32_C(  -779.84), SIMDE_FLOAT32_C(  -836.44)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   262.21), SIMDE_FLOAT32_C(   189.91),
                         SIMDE_FLOAT32_C(  -147.18), SIMDE_FLOAT32_C(  -378.37),
                         SIMDE_FLOAT32_C(  -474.15), SIMDE_FLOAT32_C(   728.93),
                         SIMDE_FLOAT32_C(  -779.84), SIMDE_FLOAT32_C(  -836.44)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_castpd_ps(simde_mm256_castps_pd(test_vec[i].a));
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  866.38), SIMDE_FLOAT64_C( -294.05),
                         SIMDE_FLOAT64_C( -595.07), SIMDE_FLOAT64_C(   30.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  866.38), SIMDE_FLOAT64_C( -294.05),
                         SIMDE_FLOAT64_C( -595.07), SIMDE_FLOAT64_C(   30.82)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  967.90), SIMDE_FLOAT64_C(  598.86),
                         SIMDE_FLOAT64_C( -336.28), SIMDE_FLOAT64_C(  771.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  967.90), SIMDE_FLOAT64_C(  598.86),
                         SIMDE_FLOAT64_C( -336.28), SIMDE_FLOAT64_C(  771.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -949.57), SIMDE_FLOAT64_C( -900.42),
                         SIMDE_FLOAT64_C(  702.02), SIMDE_FLOAT64_C( -980.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -949.57), SIMDE_FLOAT64_C( -900.42),
                         SIMDE_FLOAT64_C(  702.02), SIMDE_FLOAT64_C( -980.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  969.39), SIMDE_FLOAT64_C(  513.49),
                         SIMDE_FLOAT64_C(  950.16), SIMDE_FLOAT64_C( -812.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  969.39), SIMDE_FLOAT64_C(  513.49),
                         SIMDE_FLOAT64_C(  950.16), SIMDE_FLOAT64_C( -812.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -507.62), SIMDE_FLOAT64_C( -207.64),
                         SIMDE_FLOAT64_C(  179.82), SIMDE_FLOAT64_C(   43.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -507.62), SIMDE_FLOAT64_C( -207.64),
                         SIMDE_FLOAT64_C(  179.82), SIMDE_FLOAT64_C(   43.82)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.29), SIMDE_FLOAT64_C(  530.93),
                         SIMDE_FLOAT64_C(   26.40), SIMDE_FLOAT64_C( -295.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.29), SIMDE_FLOAT64_C(  530.93),
                         SIMDE_FLOAT64_C(   26.40), SIMDE_FLOAT64_C( -295.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  195.05), SIMDE_FLOAT64_C( -631.18),
                         SIMDE_FLOAT64_C( -125.11), SIMDE_FLOAT64_C( -657.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  195.05), SIMDE_FLOAT64_C( -631.18),
                         SIMDE_FLOAT64_C( -125.11), SIMDE_FLOAT64_C( -657.02)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  839.46), SIMDE_FLOAT64_C( -787.94),
                         SIMDE_FLOAT64_C( -273.33), SIMDE_FLOAT64_C( -261.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  839.46), SIMDE_FLOAT64_C( -787.94),
                         SIMDE_FLOAT64_C( -273.33), SIMDE_FLOAT64_C( -261.67)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_castps_pd(simde_mm256_castpd_ps(test_vec[i].a));
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castps128_ps256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   351.31), SIMDE_FLOAT32_C(   331.36), SIMDE_FLOAT32_C(   112.22), SIMDE_FLOAT32_C(   -15.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   351.31), SIMDE_FLOAT32_C(   331.36),
                         SIMDE_FLOAT32_C(   112.22), SIMDE_FLOAT32_C(   -15.48)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   905.42), SIMDE_FLOAT32_C(  -224.21), SIMDE_FLOAT32_C(   -76.15), SIMDE_FLOAT32_C(   663.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   905.42), SIMDE_FLOAT32_C(  -224.21),
                         SIMDE_FLOAT32_C(   -76.15), SIMDE_FLOAT32_C(   663.18)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   830.23), SIMDE_FLOAT32_C(    -5.95), SIMDE_FLOAT32_C(   918.64), SIMDE_FLOAT32_C(   777.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   830.23), SIMDE_FLOAT32_C(    -5.95),
                         SIMDE_FLOAT32_C(   918.64), SIMDE_FLOAT32_C(   777.19)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -168.85), SIMDE_FLOAT32_C(  -871.57), SIMDE_FLOAT32_C(    40.10), SIMDE_FLOAT32_C(  -558.27)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -168.85), SIMDE_FLOAT32_C(  -871.57),
                         SIMDE_FLOAT32_C(    40.10), SIMDE_FLOAT32_C(  -558.27)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -791.93), SIMDE_FLOAT32_C(   293.41), SIMDE_FLOAT32_C(   390.85), SIMDE_FLOAT32_C(   476.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -791.93), SIMDE_FLOAT32_C(   293.41),
                         SIMDE_FLOAT32_C(   390.85), SIMDE_FLOAT32_C(   476.42)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   481.03), SIMDE_FLOAT32_C(  -319.83), SIMDE_FLOAT32_C(  -437.10), SIMDE_FLOAT32_C(  -775.98)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   481.03), SIMDE_FLOAT32_C(  -319.83),
                         SIMDE_FLOAT32_C(  -437.10), SIMDE_FLOAT32_C(  -775.98)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   193.26), SIMDE_FLOAT32_C(   702.14), SIMDE_FLOAT32_C(  -820.75), SIMDE_FLOAT32_C(  -158.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   193.26), SIMDE_FLOAT32_C(   702.14),
                         SIMDE_FLOAT32_C(  -820.75), SIMDE_FLOAT32_C(  -158.78)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -995.99), SIMDE_FLOAT32_C(   290.31), SIMDE_FLOAT32_C(  -219.12), SIMDE_FLOAT32_C(  -837.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -995.99), SIMDE_FLOAT32_C(   290.31),
                         SIMDE_FLOAT32_C(  -219.12), SIMDE_FLOAT32_C(  -837.21)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256_private r = simde__m256_to_private(simde_mm256_castps128_ps256(test_vec[i].a));
    simde__m256_private expected = simde__m256_to_private(test_vec[i].r);
    simde_assert_m128_equal(r.m128[0], expected.m128[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castps256_ps128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -556.83), SIMDE_FLOAT32_C(   534.45),
                         SIMDE_FLOAT32_C(   421.40), SIMDE_FLOAT32_C(   932.30),
                         SIMDE_FLOAT32_C(   169.92), SIMDE_FLOAT32_C(   399.10),
                         SIMDE_FLOAT32_C(  -742.08), SIMDE_FLOAT32_C(  -830.66)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   169.92), SIMDE_FLOAT32_C(   399.10), SIMDE_FLOAT32_C(  -742.08), SIMDE_FLOAT32_C(  -830.66)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   802.82), SIMDE_FLOAT32_C(   -21.64),
                         SIMDE_FLOAT32_C(  -298.77), SIMDE_FLOAT32_C(  -723.27),
                         SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(  -154.70),
                         SIMDE_FLOAT32_C(  -285.18), SIMDE_FLOAT32_C(  -881.89)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(    42.85), SIMDE_FLOAT32_C(  -154.70), SIMDE_FLOAT32_C(  -285.18), SIMDE_FLOAT32_C(  -881.89)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   606.40), SIMDE_FLOAT32_C(   978.13),
                         SIMDE_FLOAT32_C(   281.04), SIMDE_FLOAT32_C(   316.13),
                         SIMDE_FLOAT32_C(     8.74), SIMDE_FLOAT32_C(  -824.14),
                         SIMDE_FLOAT32_C(  -338.77), SIMDE_FLOAT32_C(  -977.64)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     8.74), SIMDE_FLOAT32_C(  -824.14), SIMDE_FLOAT32_C(  -338.77), SIMDE_FLOAT32_C(  -977.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   500.38), SIMDE_FLOAT32_C(  -378.47),
                         SIMDE_FLOAT32_C(  -151.95), SIMDE_FLOAT32_C(  -513.15),
                         SIMDE_FLOAT32_C(  -509.66), SIMDE_FLOAT32_C(   542.95),
                         SIMDE_FLOAT32_C(  -511.97), SIMDE_FLOAT32_C(   606.72)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -509.66), SIMDE_FLOAT32_C(   542.95), SIMDE_FLOAT32_C(  -511.97), SIMDE_FLOAT32_C(   606.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -156.57), SIMDE_FLOAT32_C(  -909.62),
                         SIMDE_FLOAT32_C(   457.12), SIMDE_FLOAT32_C(  -549.96),
                         SIMDE_FLOAT32_C(   250.75), SIMDE_FLOAT32_C(  -503.56),
                         SIMDE_FLOAT32_C(  -397.59), SIMDE_FLOAT32_C(   644.59)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   250.75), SIMDE_FLOAT32_C(  -503.56), SIMDE_FLOAT32_C(  -397.59), SIMDE_FLOAT32_C(   644.59)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   692.42), SIMDE_FLOAT32_C(   776.78),
                         SIMDE_FLOAT32_C(  -240.36), SIMDE_FLOAT32_C(  -615.28),
                         SIMDE_FLOAT32_C(  -428.59), SIMDE_FLOAT32_C(   807.96),
                         SIMDE_FLOAT32_C(  -867.86), SIMDE_FLOAT32_C(   511.34)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -428.59), SIMDE_FLOAT32_C(   807.96), SIMDE_FLOAT32_C(  -867.86), SIMDE_FLOAT32_C(   511.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   115.07), SIMDE_FLOAT32_C(  -200.05),
                         SIMDE_FLOAT32_C(  -278.17), SIMDE_FLOAT32_C(   321.78),
                         SIMDE_FLOAT32_C(   793.85), SIMDE_FLOAT32_C(   416.18),
                         SIMDE_FLOAT32_C(  -935.48), SIMDE_FLOAT32_C(  -637.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   793.85), SIMDE_FLOAT32_C(   416.18), SIMDE_FLOAT32_C(  -935.48), SIMDE_FLOAT32_C(  -637.83)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   951.45), SIMDE_FLOAT32_C(   803.49),
                         SIMDE_FLOAT32_C(  -646.03), SIMDE_FLOAT32_C(  -379.68),
                         SIMDE_FLOAT32_C(   433.22), SIMDE_FLOAT32_C(   128.68),
                         SIMDE_FLOAT32_C(   589.03), SIMDE_FLOAT32_C(   956.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   433.22), SIMDE_FLOAT32_C(   128.68), SIMDE_FLOAT32_C(   589.03), SIMDE_FLOAT32_C(   956.87)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm256_castps256_ps128(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castps_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1649031696), INT32_C(  834872153), INT32_C(  230986620), INT32_C( -480324866),
                            INT32_C( 1237553077), INT32_C(  596539913), INT32_C( -724550399), INT32_C( -685617130)),
      simde_mm256_set_epi32(INT32_C(-1649031696), INT32_C(  834872153), INT32_C(  230986620), INT32_C( -480324866),
                            INT32_C( 1237553077), INT32_C(  596539913), INT32_C( -724550399), INT32_C( -685617130)) },
    { simde_mm256_set_epi32(INT32_C( 2090398598), INT32_C( 2109187943), INT32_C( 2052808539), INT32_C(  748311192),
                            INT32_C( -177311449), INT32_C(  358911508), INT32_C( 1754057382), INT32_C(-1724435543)),
      simde_mm256_set_epi32(INT32_C( 2090398598), INT32_C( 2109187943), INT32_C( 2052808539), INT32_C(  748311192),
                            INT32_C( -177311449), INT32_C(  358911508), INT32_C( 1754057382), INT32_C(-1724435543)) },
    { simde_mm256_set_epi32(INT32_C(-1888707460), INT32_C(  492300795), INT32_C(-1881516103), INT32_C( 1522261816),
                            INT32_C(  516271628), INT32_C( 1619360533), INT32_C(  585952460), INT32_C(-1270838330)),
      simde_mm256_set_epi32(INT32_C(-1888707460), INT32_C(  492300795), INT32_C(-1881516103), INT32_C( 1522261816),
                            INT32_C(  516271628), INT32_C( 1619360533), INT32_C(  585952460), INT32_C(-1270838330)) },
    { simde_mm256_set_epi32(INT32_C(-1165169384), INT32_C(-2002996511), INT32_C(-1387036009), INT32_C(  730682044),
                            INT32_C( -504180431), INT32_C(-1682623046), INT32_C( 1968017036), INT32_C(  283253644)),
      simde_mm256_set_epi32(INT32_C(-1165169384), INT32_C(-2002996511), INT32_C(-1387036009), INT32_C(  730682044),
                            INT32_C( -504180431), INT32_C(-1682623046), INT32_C( 1968017036), INT32_C(  283253644)) },
    { simde_mm256_set_epi32(INT32_C( 1949666143), INT32_C( -888451700), INT32_C(  605916520), INT32_C(-1265057380),
                            INT32_C( 1158984758), INT32_C(  710723273), INT32_C( -342604717), INT32_C(-1218392316)),
      simde_mm256_set_epi32(INT32_C( 1949666143), INT32_C( -888451700), INT32_C(  605916520), INT32_C(-1265057380),
                            INT32_C( 1158984758), INT32_C(  710723273), INT32_C( -342604717), INT32_C(-1218392316)) },
    { simde_mm256_set_epi32(INT32_C(-1870151604), INT32_C(-2002713920), INT32_C(-1131057702), INT32_C(-1611852985),
                            INT32_C( 1725575775), INT32_C( -263968835), INT32_C(   26802813), INT32_C( -641556710)),
      simde_mm256_set_epi32(INT32_C(-1870151604), INT32_C(-2002713920), INT32_C(-1131057702), INT32_C(-1611852985),
                            INT32_C( 1725575775), INT32_C( -263968835), INT32_C(   26802813), INT32_C( -641556710)) },
    { simde_mm256_set_epi32(INT32_C(  938077299), INT32_C(    4161792), INT32_C( 1718084645), INT32_C( 1391219860),
                            INT32_C( 1311036795), INT32_C(  132407700), INT32_C(-1161361885), INT32_C( -462662147)),
      simde_mm256_set_epi32(INT32_C(  938077299), INT32_C(    4161792), INT32_C( 1718084645), INT32_C( 1391219860),
                            INT32_C( 1311036795), INT32_C(  132407700), INT32_C(-1161361885), INT32_C( -462662147)) },
    { simde_mm256_set_epi32(INT32_C(  987097256), INT32_C( -835194619), INT32_C(-1566547652), INT32_C(-1345603026),
                            INT32_C(  138933650), INT32_C(-1430090796), INT32_C(-1310267132), INT32_C( 1931451372)),
      simde_mm256_set_epi32(INT32_C(  987097256), INT32_C( -835194619), INT32_C(-1566547652), INT32_C(-1345603026),
                            INT32_C(  138933650), INT32_C(-1430090796), INT32_C(-1310267132), INT32_C( 1931451372)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castps_si256(simde_mm256_castsi256_ps(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-6436426043624243132), INT64_C( 2719911931068686329),
                             INT64_C(-3355851641471628446), INT64_C(-4058286728495258453)),
      simde_mm256_set_epi64x(INT64_C(-6436426043624243132), INT64_C( 2719911931068686329),
                             INT64_C(-3355851641471628446), INT64_C(-4058286728495258453)) },
    { simde_mm256_set_epi64x(INT64_C(-6993645949082966147), INT64_C( 4041637144880323460),
                             INT64_C( 2966258866008904789), INT64_C( 2735372768247448487)),
      simde_mm256_set_epi64x(INT64_C(-6993645949082966147), INT64_C( 4041637144880323460),
                             INT64_C( 2966258866008904789), INT64_C( 2735372768247448487)) },
    { simde_mm256_set_epi64x(INT64_C(-6467543300276167050), INT64_C(-7030233167547396539),
                             INT64_C(-5268215840490095714), INT64_C( 8140300440770855984)),
      simde_mm256_set_epi64x(INT64_C(-6467543300276167050), INT64_C(-7030233167547396539),
                             INT64_C(-5268215840490095714), INT64_C( 8140300440770855984)) },
    { simde_mm256_set_epi64x(INT64_C(-3250744318785917277), INT64_C( 2545355707516900387),
                             INT64_C( 2404409761557662509), INT64_C( 3863384403090649322)),
      simde_mm256_set_epi64x(INT64_C(-3250744318785917277), INT64_C( 2545355707516900387),
                             INT64_C( 2404409761557662509), INT64_C( 3863384403090649322)) },
    { simde_mm256_set_epi64x(INT64_C(-4992649395117694343), INT64_C( 2252708120662783492),
                             INT64_C(-3886485865609467666), INT64_C( 4133517733748490879)),
      simde_mm256_set_epi64x(INT64_C(-4992649395117694343), INT64_C( 2252708120662783492),
                             INT64_C(-3886485865609467666), INT64_C( 4133517733748490879)) },
    { simde_mm256_set_epi64x(INT64_C(-7084284413768371436), INT64_C(  727608602759940145),
                             INT64_C( 5594257850626695037), INT64_C(-7304190896383027628)),
      simde_mm256_set_epi64x(INT64_C(-7084284413768371436), INT64_C(  727608602759940145),
                             INT64_C( 5594257850626695037), INT64_C(-7304190896383027628)) },
    { simde_mm256_set_epi64x(INT64_C(-1886107943195258905), INT64_C(-7906247581446835510),
                             INT64_C( 9068725184054777835), INT64_C( 3330105325701476873)),
      simde_mm256_set_epi64x(INT64_C(-1886107943195258905), INT64_C(-7906247581446835510),
                             INT64_C( 9068725184054777835), INT64_C( 3330105325701476873)) },
    { simde_mm256_set_epi64x(INT64_C( 1390912152688035821), INT64_C(-4783191750990221778),
                             INT64_C(-4829331002619468971), INT64_C( 2643188978129753257)),
      simde_mm256_set_epi64x(INT64_C( 1390912152688035821), INT64_C(-4783191750990221778),
                             INT64_C(-4829331002619468971), INT64_C( 2643188978129753257)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castpd_si256(simde_mm256_castsi256_pd(test_vec[i].a));
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castsi128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1176995756), INT32_C(-1870675232), INT32_C(  996429243), INT32_C(  550488102)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1176995756), INT32_C(-1870675232), INT32_C(  996429243), INT32_C(  550488102)) },
    { simde_mm_set_epi32(INT32_C( 1022574086), INT32_C( -246750524), INT32_C(-1886376341), INT32_C(-1870907175)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1022574086), INT32_C( -246750524), INT32_C(-1886376341), INT32_C(-1870907175)) },
    { simde_mm_set_epi32(INT32_C( 1399644059), INT32_C(-2062431582), INT32_C(  861056404), INT32_C(-1456249685)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1399644059), INT32_C(-2062431582), INT32_C(  861056404), INT32_C(-1456249685)) },
    { simde_mm_set_epi32(INT32_C(-1357701315), INT32_C( -200201270), INT32_C(-2128732965), INT32_C( -971656840)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1357701315), INT32_C( -200201270), INT32_C(-2128732965), INT32_C( -971656840)) },
    { simde_mm_set_epi32(INT32_C( 1758025228), INT32_C(   19121992), INT32_C( 1973849856), INT32_C( -609470236)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1758025228), INT32_C(   19121992), INT32_C( 1973849856), INT32_C( -609470236)) },
    { simde_mm_set_epi32(INT32_C(-1315323340), INT32_C( 1995350243), INT32_C(-1725897434), INT32_C(  791183816)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1315323340), INT32_C( 1995350243), INT32_C(-1725897434), INT32_C(  791183816)) },
    { simde_mm_set_epi32(INT32_C(-2046705493), INT32_C(  441938624), INT32_C(  -46886380), INT32_C(  606821245)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-2046705493), INT32_C(  441938624), INT32_C(  -46886380), INT32_C(  606821245)) },
    { simde_mm_set_epi32(INT32_C( 1167221394), INT32_C(  739794596), INT32_C(  187704590), INT32_C( 1165304892)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1167221394), INT32_C(  739794596), INT32_C(  187704590), INT32_C( 1165304892)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_extractf128_si256(simde_mm256_castsi128_si256(test_vec[i].a), 0);
    simde__m128i e = simde_mm256_extractf128_si256(test_vec[i].r, 0);
    simde_assert_m128i_equal(r, e);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castsi256_si128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1033968789), INT32_C(  712909368), INT32_C(  -15382203), INT32_C(  726776461),
                            INT32_C( 1212968394), INT32_C( -910350077), INT32_C(-1401880553), INT32_C(-1640064659)),
      simde_mm_set_epi32(INT32_C( 1212968394), INT32_C( -910350077), INT32_C(-1401880553), INT32_C(-1640064659)) },
    { simde_mm256_set_epi32(INT32_C( -244971373), INT32_C( -839397474), INT32_C(-1281097070), INT32_C( 1259688200),
                            INT32_C(-1678523239), INT32_C(-1335997395), INT32_C( 1104214719), INT32_C(-1646552356)),
      simde_mm_set_epi32(INT32_C(-1678523239), INT32_C(-1335997395), INT32_C( 1104214719), INT32_C(-1646552356)) },
    { simde_mm256_set_epi32(INT32_C( 1339422473), INT32_C( -532071515), INT32_C(-1679156122), INT32_C( -104726847),
                            INT32_C( -189233938), INT32_C(-1476384511), INT32_C(   59015981), INT32_C( -574854746)),
      simde_mm_set_epi32(INT32_C( -189233938), INT32_C(-1476384511), INT32_C(   59015981), INT32_C( -574854746)) },
    { simde_mm256_set_epi32(INT32_C(  104804994), INT32_C(-1602912924), INT32_C(-1184587502), INT32_C( -929055139),
                            INT32_C(-1913020666), INT32_C( 1485870300), INT32_C( -930325282), INT32_C(  971511935)),
      simde_mm_set_epi32(INT32_C(-1913020666), INT32_C( 1485870300), INT32_C( -930325282), INT32_C(  971511935)) },
    { simde_mm256_set_epi32(INT32_C( -640493670), INT32_C( -513373085), INT32_C(  396752088), INT32_C( 1774159809),
                            INT32_C(-1068197323), INT32_C( -727216092), INT32_C( 2046795601), INT32_C( -954579053)),
      simde_mm_set_epi32(INT32_C(-1068197323), INT32_C( -727216092), INT32_C( 2046795601), INT32_C( -954579053)) },
    { simde_mm256_set_epi32(INT32_C(  968938230), INT32_C(  324986947), INT32_C( 1563795037), INT32_C( 1925209729),
                            INT32_C(-1635044296), INT32_C(  685246103), INT32_C( 1765586923), INT32_C( -978308891)),
      simde_mm_set_epi32(INT32_C(-1635044296), INT32_C(  685246103), INT32_C( 1765586923), INT32_C( -978308891)) },
    { simde_mm256_set_epi32(INT32_C(-1695851306), INT32_C(-2116140969), INT32_C(  146847367), INT32_C( -593023293),
                            INT32_C( 1573776318), INT32_C(-1046034616), INT32_C( -645014018), INT32_C( 1014255016)),
      simde_mm_set_epi32(INT32_C( 1573776318), INT32_C(-1046034616), INT32_C( -645014018), INT32_C( 1014255016)) },
    { simde_mm256_set_epi32(INT32_C( 1123223298), INT32_C( 1981751223), INT32_C( 1306799664), INT32_C(-1888445770),
                            INT32_C( 1502796782), INT32_C( 1707347280), INT32_C(  760982117), INT32_C( 1124914897)),
      simde_mm_set_epi32(INT32_C( 1502796782), INT32_C( 1707347280), INT32_C(  760982117), INT32_C( 1124914897)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_castsi256_si128(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castsi256_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1649031696), INT32_C(  834872153), INT32_C(  230986620), INT32_C( -480324866),
                            INT32_C( 1237553077), INT32_C(  596539913), INT32_C( -724550399), INT32_C( -685617130)),
      simde_mm256_set_epi32(INT32_C(-1649031696), INT32_C(  834872153), INT32_C(  230986620), INT32_C( -480324866),
                            INT32_C( 1237553077), INT32_C(  596539913), INT32_C( -724550399), INT32_C( -685617130)) },
    { simde_mm256_set_epi32(INT32_C( 2090398598), INT32_C( 2109187943), INT32_C( 2052808539), INT32_C(  748311192),
                            INT32_C( -177311449), INT32_C(  358911508), INT32_C( 1754057382), INT32_C(-1724435543)),
      simde_mm256_set_epi32(INT32_C( 2090398598), INT32_C( 2109187943), INT32_C( 2052808539), INT32_C(  748311192),
                            INT32_C( -177311449), INT32_C(  358911508), INT32_C( 1754057382), INT32_C(-1724435543)) },
    { simde_mm256_set_epi32(INT32_C(-1888707460), INT32_C(  492300795), INT32_C(-1881516103), INT32_C( 1522261816),
                            INT32_C(  516271628), INT32_C( 1619360533), INT32_C(  585952460), INT32_C(-1270838330)),
      simde_mm256_set_epi32(INT32_C(-1888707460), INT32_C(  492300795), INT32_C(-1881516103), INT32_C( 1522261816),
                            INT32_C(  516271628), INT32_C( 1619360533), INT32_C(  585952460), INT32_C(-1270838330)) },
    { simde_mm256_set_epi32(INT32_C(-1165169384), INT32_C(-2002996511), INT32_C(-1387036009), INT32_C(  730682044),
                            INT32_C( -504180431), INT32_C(-1682623046), INT32_C( 1968017036), INT32_C(  283253644)),
      simde_mm256_set_epi32(INT32_C(-1165169384), INT32_C(-2002996511), INT32_C(-1387036009), INT32_C(  730682044),
                            INT32_C( -504180431), INT32_C(-1682623046), INT32_C( 1968017036), INT32_C(  283253644)) },
    { simde_mm256_set_epi32(INT32_C( 1949666143), INT32_C( -888451700), INT32_C(  605916520), INT32_C(-1265057380),
                            INT32_C( 1158984758), INT32_C(  710723273), INT32_C( -342604717), INT32_C(-1218392316)),
      simde_mm256_set_epi32(INT32_C( 1949666143), INT32_C( -888451700), INT32_C(  605916520), INT32_C(-1265057380),
                            INT32_C( 1158984758), INT32_C(  710723273), INT32_C( -342604717), INT32_C(-1218392316)) },
    { simde_mm256_set_epi32(INT32_C(-1870151604), INT32_C(-2002713920), INT32_C(-1131057702), INT32_C(-1611852985),
                            INT32_C( 1725575775), INT32_C( -263968835), INT32_C(   26802813), INT32_C( -641556710)),
      simde_mm256_set_epi32(INT32_C(-1870151604), INT32_C(-2002713920), INT32_C(-1131057702), INT32_C(-1611852985),
                            INT32_C( 1725575775), INT32_C( -263968835), INT32_C(   26802813), INT32_C( -641556710)) },
    { simde_mm256_set_epi32(INT32_C(  938077299), INT32_C(    4161792), INT32_C( 1718084645), INT32_C( 1391219860),
                            INT32_C( 1311036795), INT32_C(  132407700), INT32_C(-1161361885), INT32_C( -462662147)),
      simde_mm256_set_epi32(INT32_C(  938077299), INT32_C(    4161792), INT32_C( 1718084645), INT32_C( 1391219860),
                            INT32_C( 1311036795), INT32_C(  132407700), INT32_C(-1161361885), INT32_C( -462662147)) },
    { simde_mm256_set_epi32(INT32_C(  987097256), INT32_C( -835194619), INT32_C(-1566547652), INT32_C(-1345603026),
                            INT32_C(  138933650), INT32_C(-1430090796), INT32_C(-1310267132), INT32_C( 1931451372)),
      simde_mm256_set_epi32(INT32_C(  987097256), INT32_C( -835194619), INT32_C(-1566547652), INT32_C(-1345603026),
                            INT32_C(  138933650), INT32_C(-1430090796), INT32_C(-1310267132), INT32_C( 1931451372)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castps_si256(simde_mm256_castsi256_ps(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castsi256_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-6436426043624243132), INT64_C( 2719911931068686329),
                             INT64_C(-3355851641471628446), INT64_C(-4058286728495258453)),
      simde_mm256_set_epi64x(INT64_C(-6436426043624243132), INT64_C( 2719911931068686329),
                             INT64_C(-3355851641471628446), INT64_C(-4058286728495258453)) },
    { simde_mm256_set_epi64x(INT64_C(-6993645949082966147), INT64_C( 4041637144880323460),
                             INT64_C( 2966258866008904789), INT64_C( 2735372768247448487)),
      simde_mm256_set_epi64x(INT64_C(-6993645949082966147), INT64_C( 4041637144880323460),
                             INT64_C( 2966258866008904789), INT64_C( 2735372768247448487)) },
    { simde_mm256_set_epi64x(INT64_C(-6467543300276167050), INT64_C(-7030233167547396539),
                             INT64_C(-5268215840490095714), INT64_C( 8140300440770855984)),
      simde_mm256_set_epi64x(INT64_C(-6467543300276167050), INT64_C(-7030233167547396539),
                             INT64_C(-5268215840490095714), INT64_C( 8140300440770855984)) },
    { simde_mm256_set_epi64x(INT64_C(-3250744318785917277), INT64_C( 2545355707516900387),
                             INT64_C( 2404409761557662509), INT64_C( 3863384403090649322)),
      simde_mm256_set_epi64x(INT64_C(-3250744318785917277), INT64_C( 2545355707516900387),
                             INT64_C( 2404409761557662509), INT64_C( 3863384403090649322)) },
    { simde_mm256_set_epi64x(INT64_C(-4992649395117694343), INT64_C( 2252708120662783492),
                             INT64_C(-3886485865609467666), INT64_C( 4133517733748490879)),
      simde_mm256_set_epi64x(INT64_C(-4992649395117694343), INT64_C( 2252708120662783492),
                             INT64_C(-3886485865609467666), INT64_C( 4133517733748490879)) },
    { simde_mm256_set_epi64x(INT64_C(-7084284413768371436), INT64_C(  727608602759940145),
                             INT64_C( 5594257850626695037), INT64_C(-7304190896383027628)),
      simde_mm256_set_epi64x(INT64_C(-7084284413768371436), INT64_C(  727608602759940145),
                             INT64_C( 5594257850626695037), INT64_C(-7304190896383027628)) },
    { simde_mm256_set_epi64x(INT64_C(-1886107943195258905), INT64_C(-7906247581446835510),
                             INT64_C( 9068725184054777835), INT64_C( 3330105325701476873)),
      simde_mm256_set_epi64x(INT64_C(-1886107943195258905), INT64_C(-7906247581446835510),
                             INT64_C( 9068725184054777835), INT64_C( 3330105325701476873)) },
    { simde_mm256_set_epi64x(INT64_C( 1390912152688035821), INT64_C(-4783191750990221778),
                             INT64_C(-4829331002619468971), INT64_C( 2643188978129753257)),
      simde_mm256_set_epi64x(INT64_C( 1390912152688035821), INT64_C(-4783191750990221778),
                             INT64_C(-4829331002619468971), INT64_C( 2643188978129753257)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castpd_si256(simde_mm256_castsi256_pd(test_vec[i].a));
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blend_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   61.35), SIMDE_FLOAT32_C(  540.33),
                         SIMDE_FLOAT32_C( -888.48), SIMDE_FLOAT32_C(  570.09),
                         SIMDE_FLOAT32_C(  312.02), SIMDE_FLOAT32_C( -960.46),
                         SIMDE_FLOAT32_C( -440.55), SIMDE_FLOAT32_C( -796.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -286.42), SIMDE_FLOAT32_C( -835.51),
                         SIMDE_FLOAT32_C(  177.42), SIMDE_FLOAT32_C(  142.03),
                         SIMDE_FLOAT32_C(  501.36), SIMDE_FLOAT32_C( -894.74),
                         SIMDE_FLOAT32_C( -798.77), SIMDE_FLOAT32_C(  511.25)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   61.35), SIMDE_FLOAT32_C(  540.33),
                         SIMDE_FLOAT32_C( -888.48), SIMDE_FLOAT32_C(  570.09),
                         SIMDE_FLOAT32_C(  501.36), SIMDE_FLOAT32_C( -894.74),
                         SIMDE_FLOAT32_C( -440.55), SIMDE_FLOAT32_C(  511.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  783.21), SIMDE_FLOAT32_C(  251.09),
                         SIMDE_FLOAT32_C( -929.85), SIMDE_FLOAT32_C( -378.97),
                         SIMDE_FLOAT32_C(  496.83), SIMDE_FLOAT32_C( -643.84),
                         SIMDE_FLOAT32_C( -785.45), SIMDE_FLOAT32_C( -676.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  375.42), SIMDE_FLOAT32_C( -689.69),
                         SIMDE_FLOAT32_C(  240.54), SIMDE_FLOAT32_C( -955.13),
                         SIMDE_FLOAT32_C(   82.52), SIMDE_FLOAT32_C(  210.36),
                         SIMDE_FLOAT32_C(  621.75), SIMDE_FLOAT32_C( -780.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  783.21), SIMDE_FLOAT32_C(  251.09),
                         SIMDE_FLOAT32_C( -929.85), SIMDE_FLOAT32_C( -378.97),
                         SIMDE_FLOAT32_C(   82.52), SIMDE_FLOAT32_C(  210.36),
                         SIMDE_FLOAT32_C( -785.45), SIMDE_FLOAT32_C( -780.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -376.86),
                         SIMDE_FLOAT32_C(  238.38), SIMDE_FLOAT32_C( -668.84),
                         SIMDE_FLOAT32_C(  238.09), SIMDE_FLOAT32_C(  936.53),
                         SIMDE_FLOAT32_C( -693.41), SIMDE_FLOAT32_C( -381.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   83.85), SIMDE_FLOAT32_C(  559.24),
                         SIMDE_FLOAT32_C( -896.35), SIMDE_FLOAT32_C(  225.46),
                         SIMDE_FLOAT32_C( -243.15), SIMDE_FLOAT32_C( -714.74),
                         SIMDE_FLOAT32_C(  388.91), SIMDE_FLOAT32_C(  608.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.80), SIMDE_FLOAT32_C( -376.86),
                         SIMDE_FLOAT32_C(  238.38), SIMDE_FLOAT32_C( -668.84),
                         SIMDE_FLOAT32_C( -243.15), SIMDE_FLOAT32_C( -714.74),
                         SIMDE_FLOAT32_C( -693.41), SIMDE_FLOAT32_C(  608.15)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.67), SIMDE_FLOAT32_C( -361.23),
                         SIMDE_FLOAT32_C(  362.97), SIMDE_FLOAT32_C( -860.62),
                         SIMDE_FLOAT32_C(  518.00), SIMDE_FLOAT32_C(  985.53),
                         SIMDE_FLOAT32_C(  -40.74), SIMDE_FLOAT32_C(  246.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  236.67), SIMDE_FLOAT32_C( -133.38),
                         SIMDE_FLOAT32_C( -240.09), SIMDE_FLOAT32_C(  681.13),
                         SIMDE_FLOAT32_C( -437.53), SIMDE_FLOAT32_C(  645.53),
                         SIMDE_FLOAT32_C(  472.51), SIMDE_FLOAT32_C(   30.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.67), SIMDE_FLOAT32_C( -361.23),
                         SIMDE_FLOAT32_C(  362.97), SIMDE_FLOAT32_C( -860.62),
                         SIMDE_FLOAT32_C( -437.53), SIMDE_FLOAT32_C(  645.53),
                         SIMDE_FLOAT32_C(  -40.74), SIMDE_FLOAT32_C(   30.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -759.07), SIMDE_FLOAT32_C(  240.96),
                         SIMDE_FLOAT32_C( -743.41), SIMDE_FLOAT32_C( -766.95),
                         SIMDE_FLOAT32_C( -733.55), SIMDE_FLOAT32_C( -798.68),
                         SIMDE_FLOAT32_C( -189.75), SIMDE_FLOAT32_C( -424.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -396.91), SIMDE_FLOAT32_C(  509.13),
                         SIMDE_FLOAT32_C(  462.02), SIMDE_FLOAT32_C(  520.45),
                         SIMDE_FLOAT32_C(  948.24), SIMDE_FLOAT32_C(  730.18),
                         SIMDE_FLOAT32_C( -709.02), SIMDE_FLOAT32_C( -858.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -759.07), SIMDE_FLOAT32_C(  240.96),
                         SIMDE_FLOAT32_C( -743.41), SIMDE_FLOAT32_C( -766.95),
                         SIMDE_FLOAT32_C(  948.24), SIMDE_FLOAT32_C(  730.18),
                         SIMDE_FLOAT32_C( -189.75), SIMDE_FLOAT32_C( -858.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  624.31), SIMDE_FLOAT32_C(  375.12),
                         SIMDE_FLOAT32_C(  629.27), SIMDE_FLOAT32_C(  901.24),
                         SIMDE_FLOAT32_C( -896.96), SIMDE_FLOAT32_C( -769.47),
                         SIMDE_FLOAT32_C(  452.93), SIMDE_FLOAT32_C( -251.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.06), SIMDE_FLOAT32_C( -474.61),
                         SIMDE_FLOAT32_C( -146.01), SIMDE_FLOAT32_C( -955.67),
                         SIMDE_FLOAT32_C(  931.60), SIMDE_FLOAT32_C( -773.07),
                         SIMDE_FLOAT32_C(  626.99), SIMDE_FLOAT32_C(  431.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  624.31), SIMDE_FLOAT32_C(  375.12),
                         SIMDE_FLOAT32_C(  629.27), SIMDE_FLOAT32_C(  901.24),
                         SIMDE_FLOAT32_C(  931.60), SIMDE_FLOAT32_C( -773.07),
                         SIMDE_FLOAT32_C(  452.93), SIMDE_FLOAT32_C(  431.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -812.40), SIMDE_FLOAT32_C( -551.18),
                         SIMDE_FLOAT32_C(  389.71), SIMDE_FLOAT32_C(  667.74),
                         SIMDE_FLOAT32_C(   -2.37), SIMDE_FLOAT32_C( -129.53),
                         SIMDE_FLOAT32_C(  860.16), SIMDE_FLOAT32_C(  760.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -172.95), SIMDE_FLOAT32_C( -591.71),
                         SIMDE_FLOAT32_C( -137.29), SIMDE_FLOAT32_C( -689.63),
                         SIMDE_FLOAT32_C(  644.48), SIMDE_FLOAT32_C(  859.03),
                         SIMDE_FLOAT32_C( -963.16), SIMDE_FLOAT32_C( -158.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -812.40), SIMDE_FLOAT32_C( -551.18),
                         SIMDE_FLOAT32_C(  389.71), SIMDE_FLOAT32_C(  667.74),
                         SIMDE_FLOAT32_C(  644.48), SIMDE_FLOAT32_C(  859.03),
                         SIMDE_FLOAT32_C(  860.16), SIMDE_FLOAT32_C( -158.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   53.03), SIMDE_FLOAT32_C( -493.76),
                         SIMDE_FLOAT32_C(  623.37), SIMDE_FLOAT32_C(  296.00),
                         SIMDE_FLOAT32_C( -416.71), SIMDE_FLOAT32_C( -539.89),
                         SIMDE_FLOAT32_C(  210.88), SIMDE_FLOAT32_C(  585.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.37), SIMDE_FLOAT32_C( -267.21),
                         SIMDE_FLOAT32_C(  411.37), SIMDE_FLOAT32_C( -265.51),
                         SIMDE_FLOAT32_C(  345.42), SIMDE_FLOAT32_C(  252.46),
                         SIMDE_FLOAT32_C(  286.48), SIMDE_FLOAT32_C( -858.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   53.03), SIMDE_FLOAT32_C( -493.76),
                         SIMDE_FLOAT32_C(  623.37), SIMDE_FLOAT32_C(  296.00),
                         SIMDE_FLOAT32_C(  345.42), SIMDE_FLOAT32_C(  252.46),
                         SIMDE_FLOAT32_C(  210.88), SIMDE_FLOAT32_C( -858.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_blend_ps(test_vec[i].a, test_vec[i].b, 13);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blend_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  983.61), SIMDE_FLOAT64_C(  -51.56),
                         SIMDE_FLOAT64_C(  561.13), SIMDE_FLOAT64_C( -977.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.03), SIMDE_FLOAT64_C( -876.87),
                         SIMDE_FLOAT64_C(   15.56), SIMDE_FLOAT64_C(  821.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.03), SIMDE_FLOAT64_C( -876.87),
                         SIMDE_FLOAT64_C(  561.13), SIMDE_FLOAT64_C(  821.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  486.15), SIMDE_FLOAT64_C( -809.80),
                         SIMDE_FLOAT64_C( -134.49), SIMDE_FLOAT64_C( -709.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -588.52), SIMDE_FLOAT64_C( -823.37),
                         SIMDE_FLOAT64_C( -436.62), SIMDE_FLOAT64_C( -938.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -588.52), SIMDE_FLOAT64_C( -823.37),
                         SIMDE_FLOAT64_C( -134.49), SIMDE_FLOAT64_C( -938.83)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   10.97), SIMDE_FLOAT64_C( -837.09),
                         SIMDE_FLOAT64_C( -238.93), SIMDE_FLOAT64_C( -927.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -150.59), SIMDE_FLOAT64_C(  428.13),
                         SIMDE_FLOAT64_C(  655.11), SIMDE_FLOAT64_C(  -28.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -150.59), SIMDE_FLOAT64_C(  428.13),
                         SIMDE_FLOAT64_C( -238.93), SIMDE_FLOAT64_C(  -28.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -691.52), SIMDE_FLOAT64_C( -756.72),
                         SIMDE_FLOAT64_C(   69.02), SIMDE_FLOAT64_C( -249.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.57), SIMDE_FLOAT64_C( -720.61),
                         SIMDE_FLOAT64_C(  529.12), SIMDE_FLOAT64_C(  813.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.57), SIMDE_FLOAT64_C( -720.61),
                         SIMDE_FLOAT64_C(   69.02), SIMDE_FLOAT64_C(  813.95)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  743.57), SIMDE_FLOAT64_C(  671.72),
                         SIMDE_FLOAT64_C(  747.66), SIMDE_FLOAT64_C(  592.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -559.29), SIMDE_FLOAT64_C(  529.63),
                         SIMDE_FLOAT64_C(  121.55), SIMDE_FLOAT64_C( -352.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -559.29), SIMDE_FLOAT64_C(  529.63),
                         SIMDE_FLOAT64_C(  747.66), SIMDE_FLOAT64_C( -352.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -466.05), SIMDE_FLOAT64_C( -621.64),
                         SIMDE_FLOAT64_C(  113.70), SIMDE_FLOAT64_C( -906.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -919.48), SIMDE_FLOAT64_C(  972.84),
                         SIMDE_FLOAT64_C(  378.79), SIMDE_FLOAT64_C( -196.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -919.48), SIMDE_FLOAT64_C(  972.84),
                         SIMDE_FLOAT64_C(  113.70), SIMDE_FLOAT64_C( -196.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -749.13), SIMDE_FLOAT64_C(   30.92),
                         SIMDE_FLOAT64_C(  753.62), SIMDE_FLOAT64_C( -864.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -997.13), SIMDE_FLOAT64_C(  675.64),
                         SIMDE_FLOAT64_C( -135.93), SIMDE_FLOAT64_C( -647.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -997.13), SIMDE_FLOAT64_C(  675.64),
                         SIMDE_FLOAT64_C(  753.62), SIMDE_FLOAT64_C( -647.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  757.64), SIMDE_FLOAT64_C(  119.62),
                         SIMDE_FLOAT64_C(  682.14), SIMDE_FLOAT64_C( -348.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  467.61), SIMDE_FLOAT64_C(  532.40),
                         SIMDE_FLOAT64_C(  959.59), SIMDE_FLOAT64_C( -392.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  467.61), SIMDE_FLOAT64_C(  532.40),
                         SIMDE_FLOAT64_C(  682.14), SIMDE_FLOAT64_C( -392.58)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_blend_pd(test_vec[i].a, test_vec[i].b, 13);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blendv_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 mask;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -169.19), SIMDE_FLOAT32_C( -303.51),
                         SIMDE_FLOAT32_C(  280.62), SIMDE_FLOAT32_C(  971.56),
                         SIMDE_FLOAT32_C(  558.62), SIMDE_FLOAT32_C(  244.31),
                         SIMDE_FLOAT32_C( -482.20), SIMDE_FLOAT32_C(  526.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  779.01), SIMDE_FLOAT32_C( -628.61),
                         SIMDE_FLOAT32_C( -781.26), SIMDE_FLOAT32_C( -923.79),
                         SIMDE_FLOAT32_C( -624.75), SIMDE_FLOAT32_C( -481.19),
                         SIMDE_FLOAT32_C(  750.60), SIMDE_FLOAT32_C(  693.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  392.97), SIMDE_FLOAT32_C(  752.07),
                         SIMDE_FLOAT32_C(  -74.68), SIMDE_FLOAT32_C( -769.29),
                         SIMDE_FLOAT32_C(  600.30), SIMDE_FLOAT32_C( -577.83),
                         SIMDE_FLOAT32_C(  257.89), SIMDE_FLOAT32_C( -759.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -169.19), SIMDE_FLOAT32_C( -303.51),
                         SIMDE_FLOAT32_C( -781.26), SIMDE_FLOAT32_C( -923.79),
                         SIMDE_FLOAT32_C(  558.62), SIMDE_FLOAT32_C( -481.19),
                         SIMDE_FLOAT32_C( -482.20), SIMDE_FLOAT32_C(  693.30)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  436.77), SIMDE_FLOAT32_C(  265.17),
                         SIMDE_FLOAT32_C( -598.85), SIMDE_FLOAT32_C( -424.56),
                         SIMDE_FLOAT32_C(  -24.79), SIMDE_FLOAT32_C( -558.99),
                         SIMDE_FLOAT32_C( -299.03), SIMDE_FLOAT32_C( -367.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(   46.59),
                         SIMDE_FLOAT32_C(   85.98), SIMDE_FLOAT32_C( -164.97),
                         SIMDE_FLOAT32_C(   72.68), SIMDE_FLOAT32_C( -140.26),
                         SIMDE_FLOAT32_C(  458.69), SIMDE_FLOAT32_C(  804.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  696.57), SIMDE_FLOAT32_C(  799.50),
                         SIMDE_FLOAT32_C(  216.00), SIMDE_FLOAT32_C(  812.94),
                         SIMDE_FLOAT32_C(  321.91), SIMDE_FLOAT32_C(  497.67),
                         SIMDE_FLOAT32_C( -321.87), SIMDE_FLOAT32_C(  -96.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  436.77), SIMDE_FLOAT32_C(  265.17),
                         SIMDE_FLOAT32_C( -598.85), SIMDE_FLOAT32_C( -424.56),
                         SIMDE_FLOAT32_C(  -24.79), SIMDE_FLOAT32_C( -558.99),
                         SIMDE_FLOAT32_C(  458.69), SIMDE_FLOAT32_C(  804.02)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  593.15), SIMDE_FLOAT32_C(  822.85),
                         SIMDE_FLOAT32_C( -843.43), SIMDE_FLOAT32_C( -486.43),
                         SIMDE_FLOAT32_C(  259.42), SIMDE_FLOAT32_C( -708.30),
                         SIMDE_FLOAT32_C( -398.61), SIMDE_FLOAT32_C(  689.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.96), SIMDE_FLOAT32_C(  346.21),
                         SIMDE_FLOAT32_C( -865.06), SIMDE_FLOAT32_C(  330.41),
                         SIMDE_FLOAT32_C(  355.72), SIMDE_FLOAT32_C( -380.53),
                         SIMDE_FLOAT32_C(  702.28), SIMDE_FLOAT32_C(    6.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.80), SIMDE_FLOAT32_C(  453.07),
                         SIMDE_FLOAT32_C( -312.81), SIMDE_FLOAT32_C(  655.80),
                         SIMDE_FLOAT32_C( -443.61), SIMDE_FLOAT32_C( -292.20),
                         SIMDE_FLOAT32_C( -429.77), SIMDE_FLOAT32_C(  815.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.96), SIMDE_FLOAT32_C(  822.85),
                         SIMDE_FLOAT32_C( -865.06), SIMDE_FLOAT32_C( -486.43),
                         SIMDE_FLOAT32_C(  355.72), SIMDE_FLOAT32_C( -380.53),
                         SIMDE_FLOAT32_C(  702.28), SIMDE_FLOAT32_C(  689.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  627.12), SIMDE_FLOAT32_C( -903.61),
                         SIMDE_FLOAT32_C(  802.66), SIMDE_FLOAT32_C(  393.79),
                         SIMDE_FLOAT32_C( -634.24), SIMDE_FLOAT32_C(  782.19),
                         SIMDE_FLOAT32_C(  964.94), SIMDE_FLOAT32_C( -554.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -249.23), SIMDE_FLOAT32_C( -358.11),
                         SIMDE_FLOAT32_C(   69.71), SIMDE_FLOAT32_C(  774.95),
                         SIMDE_FLOAT32_C( -447.84), SIMDE_FLOAT32_C( -947.94),
                         SIMDE_FLOAT32_C( -908.85), SIMDE_FLOAT32_C(  -21.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  241.23), SIMDE_FLOAT32_C(   27.04),
                         SIMDE_FLOAT32_C(  341.47), SIMDE_FLOAT32_C(  482.33),
                         SIMDE_FLOAT32_C(  411.77), SIMDE_FLOAT32_C( -282.69),
                         SIMDE_FLOAT32_C(  915.57), SIMDE_FLOAT32_C( -213.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  627.12), SIMDE_FLOAT32_C( -903.61),
                         SIMDE_FLOAT32_C(  802.66), SIMDE_FLOAT32_C(  393.79),
                         SIMDE_FLOAT32_C( -634.24), SIMDE_FLOAT32_C( -947.94),
                         SIMDE_FLOAT32_C(  964.94), SIMDE_FLOAT32_C(  -21.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  365.56), SIMDE_FLOAT32_C(  297.70),
                         SIMDE_FLOAT32_C( -723.56), SIMDE_FLOAT32_C(  -52.07),
                         SIMDE_FLOAT32_C(  692.93), SIMDE_FLOAT32_C( -882.05),
                         SIMDE_FLOAT32_C( -424.36), SIMDE_FLOAT32_C( -366.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  744.52), SIMDE_FLOAT32_C(  387.36),
                         SIMDE_FLOAT32_C( -311.40), SIMDE_FLOAT32_C( -280.68),
                         SIMDE_FLOAT32_C(  556.91), SIMDE_FLOAT32_C(  703.77),
                         SIMDE_FLOAT32_C( -828.92), SIMDE_FLOAT32_C(  893.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.86), SIMDE_FLOAT32_C(  793.25),
                         SIMDE_FLOAT32_C(  667.69), SIMDE_FLOAT32_C(  940.95),
                         SIMDE_FLOAT32_C( -273.21), SIMDE_FLOAT32_C(  148.61),
                         SIMDE_FLOAT32_C(  420.18), SIMDE_FLOAT32_C(    4.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  744.52), SIMDE_FLOAT32_C(  297.70),
                         SIMDE_FLOAT32_C( -723.56), SIMDE_FLOAT32_C(  -52.07),
                         SIMDE_FLOAT32_C(  556.91), SIMDE_FLOAT32_C( -882.05),
                         SIMDE_FLOAT32_C( -424.36), SIMDE_FLOAT32_C( -366.57)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  806.04), SIMDE_FLOAT32_C(  998.56),
                         SIMDE_FLOAT32_C(  954.81), SIMDE_FLOAT32_C( -105.93),
                         SIMDE_FLOAT32_C(  810.39), SIMDE_FLOAT32_C( -451.40),
                         SIMDE_FLOAT32_C( -991.41), SIMDE_FLOAT32_C(   24.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.57), SIMDE_FLOAT32_C(  -71.31),
                         SIMDE_FLOAT32_C( -379.77), SIMDE_FLOAT32_C( -507.58),
                         SIMDE_FLOAT32_C( -931.37), SIMDE_FLOAT32_C( -271.48),
                         SIMDE_FLOAT32_C(  709.92), SIMDE_FLOAT32_C( -442.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -608.56), SIMDE_FLOAT32_C( -319.60),
                         SIMDE_FLOAT32_C( -930.98), SIMDE_FLOAT32_C( -628.59),
                         SIMDE_FLOAT32_C(  898.10), SIMDE_FLOAT32_C( -782.18),
                         SIMDE_FLOAT32_C( -846.42), SIMDE_FLOAT32_C(  513.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.57), SIMDE_FLOAT32_C(  -71.31),
                         SIMDE_FLOAT32_C( -379.77), SIMDE_FLOAT32_C( -507.58),
                         SIMDE_FLOAT32_C(  810.39), SIMDE_FLOAT32_C( -271.48),
                         SIMDE_FLOAT32_C(  709.92), SIMDE_FLOAT32_C(   24.70)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.65), SIMDE_FLOAT32_C( -864.46),
                         SIMDE_FLOAT32_C( -182.16), SIMDE_FLOAT32_C(  855.39),
                         SIMDE_FLOAT32_C( -689.66), SIMDE_FLOAT32_C(  116.31),
                         SIMDE_FLOAT32_C( -552.00), SIMDE_FLOAT32_C(  962.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.01), SIMDE_FLOAT32_C(  601.06),
                         SIMDE_FLOAT32_C(  276.21), SIMDE_FLOAT32_C( -129.29),
                         SIMDE_FLOAT32_C( -199.59), SIMDE_FLOAT32_C( -345.44),
                         SIMDE_FLOAT32_C( -185.67), SIMDE_FLOAT32_C(  900.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  857.48), SIMDE_FLOAT32_C( -480.62),
                         SIMDE_FLOAT32_C( -406.99), SIMDE_FLOAT32_C( -422.80),
                         SIMDE_FLOAT32_C(    1.49), SIMDE_FLOAT32_C(  102.14),
                         SIMDE_FLOAT32_C(  113.98), SIMDE_FLOAT32_C( -405.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -598.65), SIMDE_FLOAT32_C(  601.06),
                         SIMDE_FLOAT32_C(  276.21), SIMDE_FLOAT32_C( -129.29),
                         SIMDE_FLOAT32_C( -689.66), SIMDE_FLOAT32_C(  116.31),
                         SIMDE_FLOAT32_C( -552.00), SIMDE_FLOAT32_C(  900.58)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  890.83), SIMDE_FLOAT32_C(  201.56),
                         SIMDE_FLOAT32_C(  104.24), SIMDE_FLOAT32_C(  496.38),
                         SIMDE_FLOAT32_C(  607.57), SIMDE_FLOAT32_C(  285.01),
                         SIMDE_FLOAT32_C(  501.29), SIMDE_FLOAT32_C( -590.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.60), SIMDE_FLOAT32_C(  256.83),
                         SIMDE_FLOAT32_C(  140.60), SIMDE_FLOAT32_C(  204.90),
                         SIMDE_FLOAT32_C(  371.07), SIMDE_FLOAT32_C( -744.00),
                         SIMDE_FLOAT32_C(  751.14), SIMDE_FLOAT32_C(  233.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -384.25), SIMDE_FLOAT32_C( -588.66),
                         SIMDE_FLOAT32_C( -531.19), SIMDE_FLOAT32_C( -520.11),
                         SIMDE_FLOAT32_C(  648.35), SIMDE_FLOAT32_C( -584.03),
                         SIMDE_FLOAT32_C(  700.38), SIMDE_FLOAT32_C(   21.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.60), SIMDE_FLOAT32_C(  256.83),
                         SIMDE_FLOAT32_C(  140.60), SIMDE_FLOAT32_C(  204.90),
                         SIMDE_FLOAT32_C(  607.57), SIMDE_FLOAT32_C( -744.00),
                         SIMDE_FLOAT32_C(  501.29), SIMDE_FLOAT32_C( -590.78)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_blendv_ps(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_blendv_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d mask;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -587.29), SIMDE_FLOAT64_C(  745.99),
                         SIMDE_FLOAT64_C(  660.01), SIMDE_FLOAT64_C(  -72.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.98), SIMDE_FLOAT64_C(  879.25),
                         SIMDE_FLOAT64_C(  340.44), SIMDE_FLOAT64_C( -338.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -599.03), SIMDE_FLOAT64_C(  269.37),
                         SIMDE_FLOAT64_C( -940.99), SIMDE_FLOAT64_C( -383.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.98), SIMDE_FLOAT64_C(  745.99),
                         SIMDE_FLOAT64_C(  340.44), SIMDE_FLOAT64_C( -338.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -369.37), SIMDE_FLOAT64_C(  888.66),
                         SIMDE_FLOAT64_C( -159.55), SIMDE_FLOAT64_C( -869.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  649.46), SIMDE_FLOAT64_C(  886.19),
                         SIMDE_FLOAT64_C(  926.89), SIMDE_FLOAT64_C( -697.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -515.74), SIMDE_FLOAT64_C( -918.64),
                         SIMDE_FLOAT64_C(  131.75), SIMDE_FLOAT64_C(  581.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  649.46), SIMDE_FLOAT64_C(  886.19),
                         SIMDE_FLOAT64_C( -159.55), SIMDE_FLOAT64_C( -869.53)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -900.47), SIMDE_FLOAT64_C(  409.14),
                         SIMDE_FLOAT64_C( -799.12), SIMDE_FLOAT64_C( -260.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -10.16), SIMDE_FLOAT64_C(  623.74),
                         SIMDE_FLOAT64_C( -915.24), SIMDE_FLOAT64_C( -491.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.78), SIMDE_FLOAT64_C( -317.20),
                         SIMDE_FLOAT64_C( -335.85), SIMDE_FLOAT64_C( -779.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -900.47), SIMDE_FLOAT64_C(  623.74),
                         SIMDE_FLOAT64_C( -915.24), SIMDE_FLOAT64_C( -491.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -87.84), SIMDE_FLOAT64_C(  244.36),
                         SIMDE_FLOAT64_C(  -17.33), SIMDE_FLOAT64_C(  496.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  176.35), SIMDE_FLOAT64_C(  303.26),
                         SIMDE_FLOAT64_C( -414.16), SIMDE_FLOAT64_C(  -98.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -385.65), SIMDE_FLOAT64_C( -192.42),
                         SIMDE_FLOAT64_C(  392.65), SIMDE_FLOAT64_C( -902.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  176.35), SIMDE_FLOAT64_C(  303.26),
                         SIMDE_FLOAT64_C(  -17.33), SIMDE_FLOAT64_C(  -98.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -793.35), SIMDE_FLOAT64_C(    6.53),
                         SIMDE_FLOAT64_C(  858.41), SIMDE_FLOAT64_C(  175.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.10), SIMDE_FLOAT64_C( -410.32),
                         SIMDE_FLOAT64_C(  -49.60), SIMDE_FLOAT64_C( -434.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -290.24), SIMDE_FLOAT64_C(  223.04),
                         SIMDE_FLOAT64_C(  738.63), SIMDE_FLOAT64_C( -193.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.10), SIMDE_FLOAT64_C(    6.53),
                         SIMDE_FLOAT64_C(  858.41), SIMDE_FLOAT64_C( -434.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -894.04), SIMDE_FLOAT64_C( -968.20),
                         SIMDE_FLOAT64_C(  146.09), SIMDE_FLOAT64_C( -741.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.76), SIMDE_FLOAT64_C( -340.64),
                         SIMDE_FLOAT64_C(  593.54), SIMDE_FLOAT64_C( -684.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  155.79), SIMDE_FLOAT64_C(  975.56),
                         SIMDE_FLOAT64_C(  939.33), SIMDE_FLOAT64_C(  615.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -894.04), SIMDE_FLOAT64_C( -968.20),
                         SIMDE_FLOAT64_C(  146.09), SIMDE_FLOAT64_C( -741.36)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -512.44), SIMDE_FLOAT64_C(  657.99),
                         SIMDE_FLOAT64_C(  888.55), SIMDE_FLOAT64_C(  863.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  344.43), SIMDE_FLOAT64_C(  994.17),
                         SIMDE_FLOAT64_C( -142.41), SIMDE_FLOAT64_C( -388.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -738.41), SIMDE_FLOAT64_C(  935.62),
                         SIMDE_FLOAT64_C( -743.51), SIMDE_FLOAT64_C(  -41.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  344.43), SIMDE_FLOAT64_C(  657.99),
                         SIMDE_FLOAT64_C( -142.41), SIMDE_FLOAT64_C( -388.31)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -178.00), SIMDE_FLOAT64_C( -981.39),
                         SIMDE_FLOAT64_C( -631.33), SIMDE_FLOAT64_C(  518.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  592.14), SIMDE_FLOAT64_C(  -27.22),
                         SIMDE_FLOAT64_C(  736.38), SIMDE_FLOAT64_C(  579.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  893.09), SIMDE_FLOAT64_C(  120.96),
                         SIMDE_FLOAT64_C(  910.10), SIMDE_FLOAT64_C( -128.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -178.00), SIMDE_FLOAT64_C( -981.39),
                         SIMDE_FLOAT64_C( -631.33), SIMDE_FLOAT64_C(  579.20)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_blendv_pd(test_vec[i].a, test_vec[i].b, test_vec[i].mask);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03),
                         SIMDE_FLOAT64_C( -513.14), SIMDE_FLOAT64_C( -996.03)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95),
                         SIMDE_FLOAT64_C( -857.31), SIMDE_FLOAT64_C(  353.95)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82),
                         SIMDE_FLOAT64_C( -899.34), SIMDE_FLOAT64_C(  232.82)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12),
                         SIMDE_FLOAT64_C(  382.07), SIMDE_FLOAT64_C(  111.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78),
                         SIMDE_FLOAT64_C( -172.90), SIMDE_FLOAT64_C(  651.78)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14),
                         SIMDE_FLOAT64_C(  181.43), SIMDE_FLOAT64_C( -457.14)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84),
                         SIMDE_FLOAT64_C( -742.24), SIMDE_FLOAT64_C(  215.84)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73),
                         SIMDE_FLOAT64_C( -536.84), SIMDE_FLOAT64_C(  334.73)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_broadcast_pd(&(test_vec[i].a));
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90), SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90),
                         SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60),
                         SIMDE_FLOAT32_C( -120.60), SIMDE_FLOAT32_C( -932.90),
                         SIMDE_FLOAT32_C( -860.11), SIMDE_FLOAT32_C(  350.60)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54), SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54),
                         SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80),
                         SIMDE_FLOAT32_C(  391.01), SIMDE_FLOAT32_C( -590.54),
                         SIMDE_FLOAT32_C(  324.31), SIMDE_FLOAT32_C( -643.80)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66), SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66),
                         SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42),
                         SIMDE_FLOAT32_C( -491.12), SIMDE_FLOAT32_C( -967.66),
                         SIMDE_FLOAT32_C(  104.85), SIMDE_FLOAT32_C(  671.42)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09), SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09),
                         SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57),
                         SIMDE_FLOAT32_C(  -32.73), SIMDE_FLOAT32_C( -190.09),
                         SIMDE_FLOAT32_C( -799.15), SIMDE_FLOAT32_C(  623.57)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68), SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68),
                         SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30),
                         SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C( -581.68),
                         SIMDE_FLOAT32_C(   -8.66), SIMDE_FLOAT32_C(  -28.30)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31), SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31),
                         SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29),
                         SIMDE_FLOAT32_C(  419.56), SIMDE_FLOAT32_C(   29.31),
                         SIMDE_FLOAT32_C(  547.18), SIMDE_FLOAT32_C(  390.29)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64), SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64),
                         SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34),
                         SIMDE_FLOAT32_C( -994.03), SIMDE_FLOAT32_C(   56.64),
                         SIMDE_FLOAT32_C(   34.15), SIMDE_FLOAT32_C( -848.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13), SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13),
                         SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59),
                         SIMDE_FLOAT32_C(  124.11), SIMDE_FLOAT32_C( -417.13),
                         SIMDE_FLOAT32_C(  650.71), SIMDE_FLOAT32_C(   49.59)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_broadcast_ps(&(test_vec[i].a));
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde__m256d r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C(  800.84),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  800.84), SIMDE_FLOAT64_C(  800.84),
                         SIMDE_FLOAT64_C(  800.84), SIMDE_FLOAT64_C(  800.84)) },
    { SIMDE_FLOAT64_C(  700.06),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  700.06), SIMDE_FLOAT64_C(  700.06),
                         SIMDE_FLOAT64_C(  700.06), SIMDE_FLOAT64_C(  700.06)) },
    { SIMDE_FLOAT64_C( -801.66),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -801.66), SIMDE_FLOAT64_C( -801.66),
                         SIMDE_FLOAT64_C( -801.66), SIMDE_FLOAT64_C( -801.66)) },
    { SIMDE_FLOAT64_C( -941.38),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.38), SIMDE_FLOAT64_C( -941.38),
                         SIMDE_FLOAT64_C( -941.38), SIMDE_FLOAT64_C( -941.38)) },
    { SIMDE_FLOAT64_C( -346.77),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -346.77), SIMDE_FLOAT64_C( -346.77),
                         SIMDE_FLOAT64_C( -346.77), SIMDE_FLOAT64_C( -346.77)) },
    { SIMDE_FLOAT64_C( -833.73),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -833.73), SIMDE_FLOAT64_C( -833.73),
                         SIMDE_FLOAT64_C( -833.73), SIMDE_FLOAT64_C( -833.73)) },
    { SIMDE_FLOAT64_C(  315.88),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  315.88), SIMDE_FLOAT64_C(  315.88),
                         SIMDE_FLOAT64_C(  315.88), SIMDE_FLOAT64_C(  315.88)) },
    { SIMDE_FLOAT64_C( -868.73),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -868.73), SIMDE_FLOAT64_C( -868.73),
                         SIMDE_FLOAT64_C( -868.73), SIMDE_FLOAT64_C( -868.73)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_broadcast_sd(&(test_vec[i].a));
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_broadcast_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m128 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(  137.82),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82), SIMDE_FLOAT32_C(  137.82)) },
    { SIMDE_FLOAT32_C( -118.58),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58), SIMDE_FLOAT32_C( -118.58)) },
    { SIMDE_FLOAT32_C(  963.02),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02), SIMDE_FLOAT32_C(  963.02)) },
    { SIMDE_FLOAT32_C(  515.85),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85), SIMDE_FLOAT32_C(  515.85)) },
    { SIMDE_FLOAT32_C(  110.78),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78), SIMDE_FLOAT32_C(  110.78)) },
    { SIMDE_FLOAT32_C( -190.98),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98), SIMDE_FLOAT32_C( -190.98)) },
    { SIMDE_FLOAT32_C( -429.63),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63), SIMDE_FLOAT32_C( -429.63)) },
    { SIMDE_FLOAT32_C( -924.63),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63), SIMDE_FLOAT32_C( -924.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_broadcast_ss(&(test_vec[i].a));
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_broadcast_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde__m256 r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C( -970.00),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00),
                         SIMDE_FLOAT32_C( -970.00), SIMDE_FLOAT32_C( -970.00)) },
    { SIMDE_FLOAT32_C(  425.08),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08),
                         SIMDE_FLOAT32_C(  425.08), SIMDE_FLOAT32_C(  425.08)) },
    { SIMDE_FLOAT32_C(  814.32),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32),
                         SIMDE_FLOAT32_C(  814.32), SIMDE_FLOAT32_C(  814.32)) },
    { SIMDE_FLOAT32_C(  309.83),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83),
                         SIMDE_FLOAT32_C(  309.83), SIMDE_FLOAT32_C(  309.83)) },
    { SIMDE_FLOAT32_C( -410.17),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -410.17), SIMDE_FLOAT32_C( -410.17)) },
    { SIMDE_FLOAT32_C( -592.37),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37),
                         SIMDE_FLOAT32_C( -592.37), SIMDE_FLOAT32_C( -592.37)) },
    { SIMDE_FLOAT32_C(  297.30),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30),
                         SIMDE_FLOAT32_C(  297.30), SIMDE_FLOAT32_C(  297.30)) },
    { SIMDE_FLOAT32_C( -549.85),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85),
                         SIMDE_FLOAT32_C( -549.85), SIMDE_FLOAT32_C( -549.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_broadcast_ss(&(test_vec[i].a));
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd128_pd256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -698.37), SIMDE_FLOAT64_C(  516.77)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -698.37), SIMDE_FLOAT64_C(  516.77)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -509.42), SIMDE_FLOAT64_C( -285.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -509.42), SIMDE_FLOAT64_C( -285.35)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -919.57), SIMDE_FLOAT64_C(  938.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -919.57), SIMDE_FLOAT64_C(  938.94)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   39.71), SIMDE_FLOAT64_C(  227.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   39.71), SIMDE_FLOAT64_C(  227.66)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  548.32), SIMDE_FLOAT64_C( -120.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  548.32), SIMDE_FLOAT64_C( -120.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -962.85), SIMDE_FLOAT64_C(  234.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -962.85), SIMDE_FLOAT64_C(  234.42)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -939.16), SIMDE_FLOAT64_C( -985.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -939.16), SIMDE_FLOAT64_C( -985.25)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  302.61), SIMDE_FLOAT64_C(  350.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  302.61), SIMDE_FLOAT64_C(  350.72)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d_private r = simde__m256d_to_private(simde_mm256_castpd128_pd256(test_vec[i].a));
    simde__m256d_private expected = simde__m256d_to_private(test_vec[i].r);
    simde_assert_m128d_equal(r.m128d[0], expected.m128d[0]);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_castpd256_pd128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -956.85), SIMDE_FLOAT64_C(  625.41),
                         SIMDE_FLOAT64_C(  728.85), SIMDE_FLOAT64_C(  239.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  728.85), SIMDE_FLOAT64_C(  239.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -642.31), SIMDE_FLOAT64_C( -953.04),
                         SIMDE_FLOAT64_C( -288.66), SIMDE_FLOAT64_C(  999.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -288.66), SIMDE_FLOAT64_C(  999.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -330.74), SIMDE_FLOAT64_C(  875.72),
                         SIMDE_FLOAT64_C( -137.28), SIMDE_FLOAT64_C( -787.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -137.28), SIMDE_FLOAT64_C( -787.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -616.04), SIMDE_FLOAT64_C( -762.33),
                         SIMDE_FLOAT64_C(  806.25), SIMDE_FLOAT64_C( -621.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  806.25), SIMDE_FLOAT64_C( -621.65)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -28.93), SIMDE_FLOAT64_C(  468.91),
                         SIMDE_FLOAT64_C(  242.39), SIMDE_FLOAT64_C(   -4.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  242.39), SIMDE_FLOAT64_C(   -4.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -635.10), SIMDE_FLOAT64_C( -479.80),
                         SIMDE_FLOAT64_C(  479.34), SIMDE_FLOAT64_C(  994.78)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  479.34), SIMDE_FLOAT64_C(  994.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  839.27), SIMDE_FLOAT64_C( -846.55),
                         SIMDE_FLOAT64_C( -287.23), SIMDE_FLOAT64_C(  498.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -287.23), SIMDE_FLOAT64_C(  498.33)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -68.67), SIMDE_FLOAT64_C(  956.25),
                         SIMDE_FLOAT64_C(  462.89), SIMDE_FLOAT64_C( -555.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  462.89), SIMDE_FLOAT64_C( -555.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm256_castpd256_pd128(test_vec[i].a);
    simde_assert_m128i_equal(simde_mm_castpd_si128(r), simde_mm_castpd_si128(test_vec[i].r));
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_ceil_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.41), SIMDE_FLOAT64_C( -377.59),
                         SIMDE_FLOAT64_C(  787.73), SIMDE_FLOAT64_C(  903.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -242.00), SIMDE_FLOAT64_C( -377.00),
                         SIMDE_FLOAT64_C(  788.00), SIMDE_FLOAT64_C(  904.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -851.63), SIMDE_FLOAT64_C( -168.29),
                         SIMDE_FLOAT64_C(  -47.72), SIMDE_FLOAT64_C( -227.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -851.00), SIMDE_FLOAT64_C( -168.00),
                         SIMDE_FLOAT64_C(  -47.00), SIMDE_FLOAT64_C( -227.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  922.71), SIMDE_FLOAT64_C( -494.40),
                         SIMDE_FLOAT64_C( -263.96), SIMDE_FLOAT64_C( -353.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  923.00), SIMDE_FLOAT64_C( -494.00),
                         SIMDE_FLOAT64_C( -263.00), SIMDE_FLOAT64_C( -353.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -611.84), SIMDE_FLOAT64_C(  512.63),
                         SIMDE_FLOAT64_C( -238.35), SIMDE_FLOAT64_C( -170.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -611.00), SIMDE_FLOAT64_C(  513.00),
                         SIMDE_FLOAT64_C( -238.00), SIMDE_FLOAT64_C( -170.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  816.43), SIMDE_FLOAT64_C(  815.17),
                         SIMDE_FLOAT64_C(  214.52), SIMDE_FLOAT64_C( -660.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  817.00), SIMDE_FLOAT64_C(  816.00),
                         SIMDE_FLOAT64_C(  215.00), SIMDE_FLOAT64_C( -660.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  434.90), SIMDE_FLOAT64_C(   54.02),
                         SIMDE_FLOAT64_C( -447.58), SIMDE_FLOAT64_C(  766.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  435.00), SIMDE_FLOAT64_C(   55.00),
                         SIMDE_FLOAT64_C( -447.00), SIMDE_FLOAT64_C(  767.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  372.78), SIMDE_FLOAT64_C( -135.62),
                         SIMDE_FLOAT64_C(  715.18), SIMDE_FLOAT64_C( -737.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  373.00), SIMDE_FLOAT64_C( -135.00),
                         SIMDE_FLOAT64_C(  716.00), SIMDE_FLOAT64_C( -737.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  491.75), SIMDE_FLOAT64_C(  481.14),
                         SIMDE_FLOAT64_C(  571.31), SIMDE_FLOAT64_C(  426.99)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  492.00), SIMDE_FLOAT64_C(  482.00),
                         SIMDE_FLOAT64_C(  572.00), SIMDE_FLOAT64_C(  427.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_ceil_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_ceil_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  719.50), SIMDE_FLOAT32_C(  423.42),
                         SIMDE_FLOAT32_C( -325.80), SIMDE_FLOAT32_C(   -7.65),
                         SIMDE_FLOAT32_C(  549.35), SIMDE_FLOAT32_C(   88.23),
                         SIMDE_FLOAT32_C(  442.11), SIMDE_FLOAT32_C(  103.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  720.00), SIMDE_FLOAT32_C(  424.00),
                         SIMDE_FLOAT32_C( -325.00), SIMDE_FLOAT32_C(   -7.00),
                         SIMDE_FLOAT32_C(  550.00), SIMDE_FLOAT32_C(   89.00),
                         SIMDE_FLOAT32_C(  443.00), SIMDE_FLOAT32_C(  104.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  295.26), SIMDE_FLOAT32_C(  174.52),
                         SIMDE_FLOAT32_C(  976.35), SIMDE_FLOAT32_C( -556.97),
                         SIMDE_FLOAT32_C( -188.36), SIMDE_FLOAT32_C( -888.83),
                         SIMDE_FLOAT32_C(  -89.34), SIMDE_FLOAT32_C(  743.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  296.00), SIMDE_FLOAT32_C(  175.00),
                         SIMDE_FLOAT32_C(  977.00), SIMDE_FLOAT32_C( -556.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C( -888.00),
                         SIMDE_FLOAT32_C(  -89.00), SIMDE_FLOAT32_C(  744.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -846.44), SIMDE_FLOAT32_C(  768.02),
                         SIMDE_FLOAT32_C(  217.87), SIMDE_FLOAT32_C(  724.14),
                         SIMDE_FLOAT32_C( -751.28), SIMDE_FLOAT32_C(  377.99),
                         SIMDE_FLOAT32_C( -892.77), SIMDE_FLOAT32_C( -779.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -846.00), SIMDE_FLOAT32_C(  769.00),
                         SIMDE_FLOAT32_C(  218.00), SIMDE_FLOAT32_C(  725.00),
                         SIMDE_FLOAT32_C( -751.00), SIMDE_FLOAT32_C(  378.00),
                         SIMDE_FLOAT32_C( -892.00), SIMDE_FLOAT32_C( -779.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -291.21), SIMDE_FLOAT32_C( -433.62),
                         SIMDE_FLOAT32_C(  331.96), SIMDE_FLOAT32_C(   13.15),
                         SIMDE_FLOAT32_C(   -6.69), SIMDE_FLOAT32_C( -467.28),
                         SIMDE_FLOAT32_C( -722.45), SIMDE_FLOAT32_C( -121.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -291.00), SIMDE_FLOAT32_C( -433.00),
                         SIMDE_FLOAT32_C(  332.00), SIMDE_FLOAT32_C(   14.00),
                         SIMDE_FLOAT32_C(   -6.00), SIMDE_FLOAT32_C( -467.00),
                         SIMDE_FLOAT32_C( -722.00), SIMDE_FLOAT32_C( -121.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  337.66), SIMDE_FLOAT32_C(  332.63),
                         SIMDE_FLOAT32_C(  164.76), SIMDE_FLOAT32_C(  401.70),
                         SIMDE_FLOAT32_C( -359.22), SIMDE_FLOAT32_C( -704.77),
                         SIMDE_FLOAT32_C(  780.49), SIMDE_FLOAT32_C( -605.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  338.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  165.00), SIMDE_FLOAT32_C(  402.00),
                         SIMDE_FLOAT32_C( -359.00), SIMDE_FLOAT32_C( -704.00),
                         SIMDE_FLOAT32_C(  781.00), SIMDE_FLOAT32_C( -605.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -670.88), SIMDE_FLOAT32_C(  812.79),
                         SIMDE_FLOAT32_C( -668.93), SIMDE_FLOAT32_C(  476.98),
                         SIMDE_FLOAT32_C(  590.12), SIMDE_FLOAT32_C(    1.22),
                         SIMDE_FLOAT32_C( -683.68), SIMDE_FLOAT32_C( -789.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -670.00), SIMDE_FLOAT32_C(  813.00),
                         SIMDE_FLOAT32_C( -668.00), SIMDE_FLOAT32_C(  477.00),
                         SIMDE_FLOAT32_C(  591.00), SIMDE_FLOAT32_C(    2.00),
                         SIMDE_FLOAT32_C( -683.00), SIMDE_FLOAT32_C( -789.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -872.42), SIMDE_FLOAT32_C(  -77.05),
                         SIMDE_FLOAT32_C( -381.51), SIMDE_FLOAT32_C( -862.58),
                         SIMDE_FLOAT32_C( -846.15), SIMDE_FLOAT32_C( -734.49),
                         SIMDE_FLOAT32_C(  -50.68), SIMDE_FLOAT32_C(  512.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -872.00), SIMDE_FLOAT32_C(  -77.00),
                         SIMDE_FLOAT32_C( -381.00), SIMDE_FLOAT32_C( -862.00),
                         SIMDE_FLOAT32_C( -846.00), SIMDE_FLOAT32_C( -734.00),
                         SIMDE_FLOAT32_C(  -50.00), SIMDE_FLOAT32_C(  513.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.22), SIMDE_FLOAT32_C(  -18.78),
                         SIMDE_FLOAT32_C(  479.49), SIMDE_FLOAT32_C(  552.41),
                         SIMDE_FLOAT32_C(  445.93), SIMDE_FLOAT32_C(  -70.46),
                         SIMDE_FLOAT32_C( -477.54), SIMDE_FLOAT32_C(  557.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -195.00), SIMDE_FLOAT32_C(  -18.00),
                         SIMDE_FLOAT32_C(  480.00), SIMDE_FLOAT32_C(  553.00),
                         SIMDE_FLOAT32_C(  446.00), SIMDE_FLOAT32_C(  -70.00),
                         SIMDE_FLOAT32_C( -477.00), SIMDE_FLOAT32_C(  558.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_ceil_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmp_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m128d r;
  } test_vec[] = {
    /* 0 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -529.39), SIMDE_FLOAT64_C(  120.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -464.46), SIMDE_FLOAT64_C(  787.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  952.78), SIMDE_FLOAT64_C( -168.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -565.68), SIMDE_FLOAT64_C( -927.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.75), SIMDE_FLOAT64_C(  421.91)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  154.75), SIMDE_FLOAT64_C(  421.91)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  824.22), SIMDE_FLOAT64_C(  893.34)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -441.87), SIMDE_FLOAT64_C(  716.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 1 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  696.22), SIMDE_FLOAT64_C( -762.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  919.14), SIMDE_FLOAT64_C(  193.81)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  633.35), SIMDE_FLOAT64_C(  108.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -781.31), SIMDE_FLOAT64_C( -480.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -959.59), SIMDE_FLOAT64_C(  537.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -959.59), SIMDE_FLOAT64_C(  537.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -264.04), SIMDE_FLOAT64_C(  375.43)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -794.42), SIMDE_FLOAT64_C(  595.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 2 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  867.95), SIMDE_FLOAT64_C(  922.57)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  898.26), SIMDE_FLOAT64_C(  935.85)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  202.85), SIMDE_FLOAT64_C(  -31.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -774.78), SIMDE_FLOAT64_C( -447.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.41), SIMDE_FLOAT64_C( -449.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -73.41), SIMDE_FLOAT64_C( -449.20)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  566.15), SIMDE_FLOAT64_C(   58.04)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  933.00), SIMDE_FLOAT64_C(  506.59)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 3 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -556.30), SIMDE_FLOAT64_C( -294.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  925.83), SIMDE_FLOAT64_C(  574.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  845.95), SIMDE_FLOAT64_C( -455.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  819.95), SIMDE_FLOAT64_C( -999.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  836.45), SIMDE_FLOAT64_C(   52.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  836.45), SIMDE_FLOAT64_C(   52.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  885.07), SIMDE_FLOAT64_C(  301.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  439.24), SIMDE_FLOAT64_C( -579.89)),
      simde_x_mm_setone_pd() },
    /* 4 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -870.88), SIMDE_FLOAT64_C(  245.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -24.26), SIMDE_FLOAT64_C(  522.18)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  197.35), SIMDE_FLOAT64_C(  431.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -239.79), SIMDE_FLOAT64_C( -923.26)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -817.59), SIMDE_FLOAT64_C(  878.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -817.59), SIMDE_FLOAT64_C(  878.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  732.05), SIMDE_FLOAT64_C(  358.02)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  376.41), SIMDE_FLOAT64_C( -150.39)),
      simde_x_mm_setone_pd() },
    /* 5 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -752.97), SIMDE_FLOAT64_C(  -94.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  129.56), SIMDE_FLOAT64_C(  291.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -694.60), SIMDE_FLOAT64_C(  283.15)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -744.59), SIMDE_FLOAT64_C( -281.74)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -245.17), SIMDE_FLOAT64_C(  713.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -245.17), SIMDE_FLOAT64_C(  713.29)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  800.54), SIMDE_FLOAT64_C(  336.83)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -984.20), SIMDE_FLOAT64_C(  916.79)),
      simde_x_mm_setone_pd() },
    /* 6 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  418.56), SIMDE_FLOAT64_C(  721.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  588.80), SIMDE_FLOAT64_C(  954.29)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -876.64), SIMDE_FLOAT64_C(  774.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -978.38), SIMDE_FLOAT64_C( -374.92)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  421.63), SIMDE_FLOAT64_C(  686.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  421.63), SIMDE_FLOAT64_C(  686.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  562.25), SIMDE_FLOAT64_C(  712.76)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -34.73), SIMDE_FLOAT64_C(   32.85)),
      simde_x_mm_setone_pd() },
    /* 7 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -970.08), SIMDE_FLOAT64_C(  342.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -564.35), SIMDE_FLOAT64_C(  715.16)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   74.04), SIMDE_FLOAT64_C(  782.97)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -252.40), SIMDE_FLOAT64_C( -653.45)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -820.35), SIMDE_FLOAT64_C(  846.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.35), SIMDE_FLOAT64_C(  846.68)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  262.97), SIMDE_FLOAT64_C( -220.11)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  652.85), SIMDE_FLOAT64_C(  169.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 8 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.55), SIMDE_FLOAT64_C( -860.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  131.29), SIMDE_FLOAT64_C( -493.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  793.95), SIMDE_FLOAT64_C(  172.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -232.93), SIMDE_FLOAT64_C(  -38.95)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  900.57), SIMDE_FLOAT64_C(  468.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  900.57), SIMDE_FLOAT64_C(  468.19)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -955.72), SIMDE_FLOAT64_C( -966.92)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  955.81), SIMDE_FLOAT64_C(  521.19)),
      simde_x_mm_setone_pd() },
    /* 9 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  295.38), SIMDE_FLOAT64_C( -590.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  311.26), SIMDE_FLOAT64_C(  337.73)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -88.55), SIMDE_FLOAT64_C( -176.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -876.40), SIMDE_FLOAT64_C( -707.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  723.57), SIMDE_FLOAT64_C(  487.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  723.57), SIMDE_FLOAT64_C(  487.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -138.67), SIMDE_FLOAT64_C( -722.72)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  469.74), SIMDE_FLOAT64_C( -238.12)),
      simde_x_mm_setone_pd() },
    /* 10 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -964.03), SIMDE_FLOAT64_C( -655.88)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  882.48), SIMDE_FLOAT64_C( -632.34)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -490.96), SIMDE_FLOAT64_C( -663.74)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -923.12), SIMDE_FLOAT64_C( -723.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -820.28), SIMDE_FLOAT64_C(  245.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -820.28), SIMDE_FLOAT64_C(  245.58)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -45.30), SIMDE_FLOAT64_C( -758.31)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -336.62), SIMDE_FLOAT64_C(  364.29)),
      simde_x_mm_setone_pd() },
    /* 11 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -362.47), SIMDE_FLOAT64_C( -433.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   48.67), SIMDE_FLOAT64_C(  358.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -861.52), SIMDE_FLOAT64_C(  340.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -862.78), SIMDE_FLOAT64_C(  207.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.45), SIMDE_FLOAT64_C( -796.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -51.45), SIMDE_FLOAT64_C( -796.45)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  402.78), SIMDE_FLOAT64_C( -860.46)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  908.56), SIMDE_FLOAT64_C(  -80.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 12 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -144.07), SIMDE_FLOAT64_C(  314.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -99.92), SIMDE_FLOAT64_C(  650.58)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -107.66), SIMDE_FLOAT64_C(  861.03)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -934.47), SIMDE_FLOAT64_C( -412.02)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -526.73), SIMDE_FLOAT64_C(  343.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -526.73), SIMDE_FLOAT64_C(  343.68)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -938.85), SIMDE_FLOAT64_C(  543.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  129.05), SIMDE_FLOAT64_C( -765.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 13 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   61.28), SIMDE_FLOAT64_C( -648.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   99.59), SIMDE_FLOAT64_C( -325.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  939.35), SIMDE_FLOAT64_C( -697.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  734.09), SIMDE_FLOAT64_C( -772.91)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  218.18), SIMDE_FLOAT64_C(  171.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  218.18), SIMDE_FLOAT64_C(  171.79)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  886.78), SIMDE_FLOAT64_C(  528.38)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  952.68), SIMDE_FLOAT64_C(  182.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 14 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -948.92), SIMDE_FLOAT64_C(  488.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  567.68), SIMDE_FLOAT64_C(  834.87)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -912.43), SIMDE_FLOAT64_C( -847.25)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -926.68), SIMDE_FLOAT64_C( -927.41)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -280.98), SIMDE_FLOAT64_C( -321.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -280.98), SIMDE_FLOAT64_C( -321.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  508.36), SIMDE_FLOAT64_C( -377.93)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  632.00), SIMDE_FLOAT64_C(  236.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 15 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -534.25), SIMDE_FLOAT64_C(  462.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -400.74), SIMDE_FLOAT64_C(  786.60)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   22.21), SIMDE_FLOAT64_C(    3.85)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -806.06), SIMDE_FLOAT64_C( -774.50)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -135.43), SIMDE_FLOAT64_C(    5.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -135.43), SIMDE_FLOAT64_C(    5.39)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -328.86), SIMDE_FLOAT64_C(   -1.43)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -578.68), SIMDE_FLOAT64_C( -504.59)),
      simde_x_mm_setone_pd() },
    /* 16 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -183.81), SIMDE_FLOAT64_C(  940.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  116.32), SIMDE_FLOAT64_C(  968.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  162.80), SIMDE_FLOAT64_C(  230.56)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.45), SIMDE_FLOAT64_C( -802.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  372.34), SIMDE_FLOAT64_C(  537.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  372.34), SIMDE_FLOAT64_C(  537.19)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -170.70), SIMDE_FLOAT64_C(   78.35)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -787.71), SIMDE_FLOAT64_C( -624.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 17 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  571.06), SIMDE_FLOAT64_C( -858.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  935.34), SIMDE_FLOAT64_C(  933.83)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   66.28), SIMDE_FLOAT64_C(   64.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -291.80), SIMDE_FLOAT64_C(  -28.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -336.17), SIMDE_FLOAT64_C( -225.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -336.17), SIMDE_FLOAT64_C( -225.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -780.19), SIMDE_FLOAT64_C(  709.48)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -626.75), SIMDE_FLOAT64_C( -830.11)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 18 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -366.69), SIMDE_FLOAT64_C(  668.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  797.88), SIMDE_FLOAT64_C(  703.26)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  789.39), SIMDE_FLOAT64_C(  864.32)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -300.63), SIMDE_FLOAT64_C( -736.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   83.76), SIMDE_FLOAT64_C( -578.41)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   83.76), SIMDE_FLOAT64_C( -578.41)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   92.61), SIMDE_FLOAT64_C(  780.89)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  133.54), SIMDE_FLOAT64_C(  148.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 19 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -871.45), SIMDE_FLOAT64_C(  -75.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.19), SIMDE_FLOAT64_C(  387.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -715.95), SIMDE_FLOAT64_C( -242.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -870.55), SIMDE_FLOAT64_C( -419.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -163.63), SIMDE_FLOAT64_C(  323.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -163.63), SIMDE_FLOAT64_C(  323.84)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -855.58), SIMDE_FLOAT64_C(  821.79)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -759.48), SIMDE_FLOAT64_C( -410.97)),
      simde_x_mm_setone_pd() },
    /* 20 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  608.05), SIMDE_FLOAT64_C(  305.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  786.81), SIMDE_FLOAT64_C(  485.46)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -332.74), SIMDE_FLOAT64_C( -240.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -490.37), SIMDE_FLOAT64_C( -482.95)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  959.57), SIMDE_FLOAT64_C( -245.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  959.57), SIMDE_FLOAT64_C( -245.61)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.52), SIMDE_FLOAT64_C( -254.36)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  805.34), SIMDE_FLOAT64_C(   47.10)),
      simde_x_mm_setone_pd() },
    /* 21 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -883.05), SIMDE_FLOAT64_C( -685.82)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  437.76), SIMDE_FLOAT64_C( -261.16)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   25.17), SIMDE_FLOAT64_C( -978.34)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -316.84), SIMDE_FLOAT64_C( -988.59)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -278.35), SIMDE_FLOAT64_C(  800.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -278.35), SIMDE_FLOAT64_C(  800.33)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  504.01), SIMDE_FLOAT64_C( -993.03)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -482.47), SIMDE_FLOAT64_C( -682.33)),
      simde_x_mm_setone_pd() },
    /* 22 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -947.05), SIMDE_FLOAT64_C(  497.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -479.84), SIMDE_FLOAT64_C(  771.58)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -957.22), SIMDE_FLOAT64_C( -498.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -996.36), SIMDE_FLOAT64_C( -893.25)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -196.35), SIMDE_FLOAT64_C(   70.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.35), SIMDE_FLOAT64_C(   70.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -895.00), SIMDE_FLOAT64_C( -516.24)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -605.59), SIMDE_FLOAT64_C(   95.56)),
      simde_x_mm_setone_pd() },
    /* 23 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -277.10), SIMDE_FLOAT64_C(  593.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -225.52), SIMDE_FLOAT64_C(  955.22)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  210.46), SIMDE_FLOAT64_C( -668.10)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.93), SIMDE_FLOAT64_C( -776.93)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  268.81), SIMDE_FLOAT64_C(   42.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  268.81), SIMDE_FLOAT64_C(   42.66)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -67.56), SIMDE_FLOAT64_C( -371.19)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -744.56), SIMDE_FLOAT64_C( -864.69)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 24 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  175.90), SIMDE_FLOAT64_C(  695.21)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  929.95), SIMDE_FLOAT64_C(  903.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -218.17), SIMDE_FLOAT64_C( -840.49)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -226.66), SIMDE_FLOAT64_C( -928.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  395.44), SIMDE_FLOAT64_C(  139.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  395.44), SIMDE_FLOAT64_C(  139.62)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -61.05), SIMDE_FLOAT64_C(  478.18)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -577.95), SIMDE_FLOAT64_C( -574.53)),
      simde_x_mm_setone_pd() },
    /* 25 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  416.40), SIMDE_FLOAT64_C( -526.24)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  660.03), SIMDE_FLOAT64_C(  -28.91)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -774.73), SIMDE_FLOAT64_C(  566.48)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -917.37), SIMDE_FLOAT64_C( -880.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.48), SIMDE_FLOAT64_C( -440.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   -0.48), SIMDE_FLOAT64_C( -440.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -568.05), SIMDE_FLOAT64_C( -288.94)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  864.36), SIMDE_FLOAT64_C(  525.81)),
      simde_x_mm_setone_pd() },
    /* 26 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -542.28), SIMDE_FLOAT64_C(  892.19)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -306.92), SIMDE_FLOAT64_C(  949.05)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  412.57), SIMDE_FLOAT64_C(  620.17)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   59.07), SIMDE_FLOAT64_C(  108.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -427.72), SIMDE_FLOAT64_C(  114.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -427.72), SIMDE_FLOAT64_C(  114.96)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  946.11), SIMDE_FLOAT64_C(   48.04)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  318.10), SIMDE_FLOAT64_C( -874.65)),
      simde_x_mm_setone_pd() },
    /* 27 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  143.93), SIMDE_FLOAT64_C(  507.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  234.55), SIMDE_FLOAT64_C(  992.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  929.86), SIMDE_FLOAT64_C(  964.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -205.11), SIMDE_FLOAT64_C(  847.14)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -693.95), SIMDE_FLOAT64_C(  407.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -693.95), SIMDE_FLOAT64_C(  407.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -669.92), SIMDE_FLOAT64_C( -839.60)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  788.01), SIMDE_FLOAT64_C( -470.01)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 28 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  979.33), SIMDE_FLOAT64_C( -879.66)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  997.49), SIMDE_FLOAT64_C(  973.15)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -307.60), SIMDE_FLOAT64_C(  589.50)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -312.27), SIMDE_FLOAT64_C( -323.93)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -607.36), SIMDE_FLOAT64_C(  554.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -607.36), SIMDE_FLOAT64_C(  554.31)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  121.31), SIMDE_FLOAT64_C( -306.77)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -196.08), SIMDE_FLOAT64_C( -442.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 29 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  205.23), SIMDE_FLOAT64_C(  463.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  891.83), SIMDE_FLOAT64_C(  478.06)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   83.52), SIMDE_FLOAT64_C( -712.98)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -494.14), SIMDE_FLOAT64_C( -713.70)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -225.77), SIMDE_FLOAT64_C(  -14.65)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -225.77), SIMDE_FLOAT64_C(  -14.65)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  277.42), SIMDE_FLOAT64_C( -194.72)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  401.09), SIMDE_FLOAT64_C( -152.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 30 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -392.42), SIMDE_FLOAT64_C(  780.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -149.10), SIMDE_FLOAT64_C(  880.51)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -834.34), SIMDE_FLOAT64_C(  188.96)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -969.00), SIMDE_FLOAT64_C( -426.74)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  862.72), SIMDE_FLOAT64_C(  212.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  862.72), SIMDE_FLOAT64_C(  212.40)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   70.37), SIMDE_FLOAT64_C(  306.92)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  111.27), SIMDE_FLOAT64_C(  341.53)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    /* 31 */
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -438.67), SIMDE_FLOAT64_C(  106.33)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   49.90), SIMDE_FLOAT64_C(  670.54)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -363.04), SIMDE_FLOAT64_C(  742.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -538.59), SIMDE_FLOAT64_C(  410.25)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  183.16), SIMDE_FLOAT64_C( -831.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  183.16), SIMDE_FLOAT64_C( -831.08)),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  429.68), SIMDE_FLOAT64_C(   -7.96)),
      simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_x_mm_setone_pd() },
    { simde_mm_set_pd(                     NAN ,                      NAN ),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  700.81), SIMDE_FLOAT64_C( -641.71)),
      simde_x_mm_setone_pd() },
  };

  for (size_t i = 0 ; i < 1 ; i++) {
    simde__m128d r = simde_mm_cmp_pd(test_vec[(0 * 5) + i].a, test_vec[(0 * 5) + i].b, 0);
    simde_assert_m128d_equal(r, test_vec[0 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(1 * 5) + i].a, test_vec[(1 * 5) + i].b, 1);
    simde_assert_m128d_equal(r, test_vec[1 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(2 * 5) + i].a, test_vec[(2 * 5) + i].b, 2);
    simde_assert_m128d_equal(r, test_vec[2 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(3 * 5) + i].a, test_vec[(3 * 5) + i].b, 3);
    simde_assert_m128d_equal(r, test_vec[3 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(4 * 5) + i].a, test_vec[(4 * 5) + i].b, 4);
    simde_assert_m128d_equal(r, test_vec[4 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(5 * 5) + i].a, test_vec[(5 * 5) + i].b, 5);
    simde_assert_m128d_equal(r, test_vec[5 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(6 * 5) + i].a, test_vec[(6 * 5) + i].b, 6);
    simde_assert_m128d_equal(r, test_vec[6 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(7 * 5) + i].a, test_vec[(7 * 5) + i].b, 7);
    simde_assert_m128d_equal(r, test_vec[7 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(8 * 5) + i].a, test_vec[(8 * 5) + i].b, 8);
    simde_assert_m128d_equal(r, test_vec[8 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(9 * 5) + i].a, test_vec[(9 * 5) + i].b, 9);
    simde_assert_m128d_equal(r, test_vec[9 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(10 * 5) + i].a, test_vec[(10 * 5) + i].b, 10);
    simde_assert_m128d_equal(r, test_vec[10 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(11 * 5) + i].a, test_vec[(11 * 5) + i].b, 11);
    simde_assert_m128d_equal(r, test_vec[11 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(12 * 5) + i].a, test_vec[(12 * 5) + i].b, 12);
    simde_assert_m128d_equal(r, test_vec[12 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(13 * 5) + i].a, test_vec[(13 * 5) + i].b, 13);
    simde_assert_m128d_equal(r, test_vec[13 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(14 * 5) + i].a, test_vec[(14 * 5) + i].b, 14);
    simde_assert_m128d_equal(r, test_vec[14 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(15 * 5) + i].a, test_vec[(15 * 5) + i].b, 15);
    simde_assert_m128d_equal(r, test_vec[15 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(16 * 5) + i].a, test_vec[(16 * 5) + i].b, 16);
    simde_assert_m128d_equal(r, test_vec[16 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(17 * 5) + i].a, test_vec[(17 * 5) + i].b, 17);
    simde_assert_m128d_equal(r, test_vec[17 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(18 * 5) + i].a, test_vec[(18 * 5) + i].b, 18);
    simde_assert_m128d_equal(r, test_vec[18 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(19 * 5) + i].a, test_vec[(19 * 5) + i].b, 19);
    simde_assert_m128d_equal(r, test_vec[19 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(20 * 5) + i].a, test_vec[(20 * 5) + i].b, 20);
    simde_assert_m128d_equal(r, test_vec[20 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(21 * 5) + i].a, test_vec[(21 * 5) + i].b, 21);
    simde_assert_m128d_equal(r, test_vec[21 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(22 * 5) + i].a, test_vec[(22 * 5) + i].b, 22);
    simde_assert_m128d_equal(r, test_vec[22 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(23 * 5) + i].a, test_vec[(23 * 5) + i].b, 23);
    simde_assert_m128d_equal(r, test_vec[23 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(24 * 5) + i].a, test_vec[(24 * 5) + i].b, SIMDE_CMP_EQ_US);
    simde_assert_m128d_equal(r, test_vec[24 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(25 * 5) + i].a, test_vec[(25 * 5) + i].b, 25);
    simde_assert_m128d_equal(r, test_vec[25 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(26 * 5) + i].a, test_vec[(26 * 5) + i].b, 26);
    simde_assert_m128d_equal(r, test_vec[26 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(27 * 5) + i].a, test_vec[(27 * 5) + i].b, 27);
    simde_assert_m128d_equal(r, test_vec[27 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(28 * 5) + i].a, test_vec[(28 * 5) + i].b, 28);
    simde_assert_m128d_equal(r, test_vec[28 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(29 * 5) + i].a, test_vec[(29 * 5) + i].b, 29);
    simde_assert_m128d_equal(r, test_vec[29 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(30 * 5) + i].a, test_vec[(30 * 5) + i].b, 30);
    simde_assert_m128d_equal(r, test_vec[30 * 5].r);

    r = simde_mm_cmp_pd(test_vec[(31 * 5) + i].a, test_vec[(31 * 5) + i].b, 31);
    simde_assert_m128d_equal(r, test_vec[31 * 5].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128 a, b, r, e;

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   78.15), SIMDE_FLOAT32_C(  891.26), SIMDE_FLOAT32_C( -343.00), SIMDE_FLOAT32_C(   84.56));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  698.49), SIMDE_FLOAT32_C( -963.46), SIMDE_FLOAT32_C( -116.01), SIMDE_FLOAT32_C( -590.30));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_EQ_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -265.69), SIMDE_FLOAT32_C(  933.07), SIMDE_FLOAT32_C( -527.28), SIMDE_FLOAT32_C(  -86.99));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -890.35), SIMDE_FLOAT32_C( -111.28), SIMDE_FLOAT32_C(  338.07), SIMDE_FLOAT32_C( -617.73));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_LT_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  768.00), SIMDE_FLOAT32_C(   58.55), SIMDE_FLOAT32_C(  317.58), SIMDE_FLOAT32_C( -318.11));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  357.58), SIMDE_FLOAT32_C(  682.66), SIMDE_FLOAT32_C(  366.57), SIMDE_FLOAT32_C( -244.60));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_LE_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -194.29), SIMDE_FLOAT32_C(  977.31), SIMDE_FLOAT32_C(  -40.23), SIMDE_FLOAT32_C(  277.84));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  740.22), SIMDE_FLOAT32_C(  146.59), SIMDE_FLOAT32_C(  780.20), SIMDE_FLOAT32_C(  471.27));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_UNORD_Q);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -120.65), SIMDE_FLOAT32_C( -397.11), SIMDE_FLOAT32_C(  121.30), SIMDE_FLOAT32_C( -296.83));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  705.83), SIMDE_FLOAT32_C(   29.37), SIMDE_FLOAT32_C(  519.72), SIMDE_FLOAT32_C( -103.90));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NEQ_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  303.98), SIMDE_FLOAT32_C(  122.35), SIMDE_FLOAT32_C( -371.51), SIMDE_FLOAT32_C( -830.97));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  595.80), SIMDE_FLOAT32_C( -291.27), SIMDE_FLOAT32_C(  984.58), SIMDE_FLOAT32_C( -789.32));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NLT_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  390.87), SIMDE_FLOAT32_C( -500.80), SIMDE_FLOAT32_C(  239.69), SIMDE_FLOAT32_C( -651.02));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -942.42), SIMDE_FLOAT32_C( -340.28), SIMDE_FLOAT32_C(  850.37), SIMDE_FLOAT32_C(  422.67));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NLE_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  241.90), SIMDE_FLOAT32_C(  133.36), SIMDE_FLOAT32_C(  343.70), SIMDE_FLOAT32_C( -917.50));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -715.40), SIMDE_FLOAT32_C( -986.32), SIMDE_FLOAT32_C(  113.89), SIMDE_FLOAT32_C(  742.57));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_ORD_Q);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  230.45), SIMDE_FLOAT32_C( -311.44), SIMDE_FLOAT32_C(  132.25), SIMDE_FLOAT32_C(  566.85));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -731.72), SIMDE_FLOAT32_C(  889.65), SIMDE_FLOAT32_C( -586.14), SIMDE_FLOAT32_C( -778.06));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_EQ_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  702.60), SIMDE_FLOAT32_C( -355.63), SIMDE_FLOAT32_C(  969.32), SIMDE_FLOAT32_C(  907.68));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  987.82), SIMDE_FLOAT32_C(   -0.12), SIMDE_FLOAT32_C(  651.63), SIMDE_FLOAT32_C(  179.23));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NGE_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -252.24), SIMDE_FLOAT32_C(  835.98), SIMDE_FLOAT32_C(  -89.83), SIMDE_FLOAT32_C( -473.83));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  473.44), SIMDE_FLOAT32_C(  -13.26), SIMDE_FLOAT32_C(  522.39), SIMDE_FLOAT32_C(  -29.61));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NGT_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -250.48), SIMDE_FLOAT32_C( -560.42), SIMDE_FLOAT32_C( -229.52), SIMDE_FLOAT32_C(  960.81));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  541.13), SIMDE_FLOAT32_C( -966.78), SIMDE_FLOAT32_C( -436.47), SIMDE_FLOAT32_C( -463.72));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_FALSE_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  178.14), SIMDE_FLOAT32_C( -394.90), SIMDE_FLOAT32_C( -713.61), SIMDE_FLOAT32_C( -298.00));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -303.13), SIMDE_FLOAT32_C( -717.53), SIMDE_FLOAT32_C(  358.73), SIMDE_FLOAT32_C(  268.02));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NEQ_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  241.76), SIMDE_FLOAT32_C(  236.50), SIMDE_FLOAT32_C(  831.59), SIMDE_FLOAT32_C( -144.41));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -899.96), SIMDE_FLOAT32_C( -131.90), SIMDE_FLOAT32_C( -192.42), SIMDE_FLOAT32_C(  450.27));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_GE_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -203.58), SIMDE_FLOAT32_C( -605.68), SIMDE_FLOAT32_C(  670.89), SIMDE_FLOAT32_C(  -47.94));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  952.52), SIMDE_FLOAT32_C(  790.50), SIMDE_FLOAT32_C( -574.64), SIMDE_FLOAT32_C(  891.61));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_GT_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  598.32), SIMDE_FLOAT32_C( -203.48), SIMDE_FLOAT32_C(  825.79), SIMDE_FLOAT32_C(  618.02));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  823.42), SIMDE_FLOAT32_C(  557.19), SIMDE_FLOAT32_C( -969.07), SIMDE_FLOAT32_C(   94.87));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_TRUE_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -576.38), SIMDE_FLOAT32_C( -929.43), SIMDE_FLOAT32_C(  533.57), SIMDE_FLOAT32_C( -129.85));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -792.74), SIMDE_FLOAT32_C( -537.71), SIMDE_FLOAT32_C(  -20.65), SIMDE_FLOAT32_C(  249.94));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_EQ_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  545.05), SIMDE_FLOAT32_C( -368.18), SIMDE_FLOAT32_C( -221.86), SIMDE_FLOAT32_C(  -21.72));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  521.14), SIMDE_FLOAT32_C(  669.26), SIMDE_FLOAT32_C( -763.27), SIMDE_FLOAT32_C(  590.72));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_LT_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  763.29), SIMDE_FLOAT32_C(  255.26), SIMDE_FLOAT32_C(  981.60), SIMDE_FLOAT32_C(  404.33));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  913.52), SIMDE_FLOAT32_C(  284.87), SIMDE_FLOAT32_C(  420.08), SIMDE_FLOAT32_C( -817.56));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_LE_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  989.95), SIMDE_FLOAT32_C(  638.39), SIMDE_FLOAT32_C( -397.70), SIMDE_FLOAT32_C( -288.05));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  358.68), SIMDE_FLOAT32_C( -151.14), SIMDE_FLOAT32_C(  886.12), SIMDE_FLOAT32_C( -860.69));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_UNORD_S);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  995.87), SIMDE_FLOAT32_C( -552.98), SIMDE_FLOAT32_C( -836.61), SIMDE_FLOAT32_C(  490.77));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  436.74), SIMDE_FLOAT32_C(  515.09), SIMDE_FLOAT32_C( -164.26), SIMDE_FLOAT32_C(   49.24));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NEQ_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  827.88), SIMDE_FLOAT32_C(  337.02), SIMDE_FLOAT32_C( -301.47), SIMDE_FLOAT32_C( -546.27));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  388.16), SIMDE_FLOAT32_C( -352.07), SIMDE_FLOAT32_C( -527.92), SIMDE_FLOAT32_C(  674.15));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NLT_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  819.64), SIMDE_FLOAT32_C(   88.69), SIMDE_FLOAT32_C( -965.38), SIMDE_FLOAT32_C(  535.26));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -769.63), SIMDE_FLOAT32_C(  452.84), SIMDE_FLOAT32_C( -471.48), SIMDE_FLOAT32_C(  287.79));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NLE_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  936.69), SIMDE_FLOAT32_C( -942.15), SIMDE_FLOAT32_C( -816.57), SIMDE_FLOAT32_C( -442.35));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -647.50), SIMDE_FLOAT32_C( -658.30), SIMDE_FLOAT32_C(  279.90), SIMDE_FLOAT32_C( -609.51));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_ORD_S);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   97.05), SIMDE_FLOAT32_C(  576.41), SIMDE_FLOAT32_C( -784.84), SIMDE_FLOAT32_C(  209.13));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  856.70), SIMDE_FLOAT32_C( -622.84), SIMDE_FLOAT32_C( -415.55), SIMDE_FLOAT32_C(   89.79));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_EQ_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  286.91), SIMDE_FLOAT32_C( -919.92), SIMDE_FLOAT32_C( -349.88), SIMDE_FLOAT32_C( -228.88));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -295.09), SIMDE_FLOAT32_C(  514.22), SIMDE_FLOAT32_C(  562.09), SIMDE_FLOAT32_C(  891.91));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NGE_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -640.97), SIMDE_FLOAT32_C( -490.26), SIMDE_FLOAT32_C( -933.90), SIMDE_FLOAT32_C( -330.97));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  534.02), SIMDE_FLOAT32_C( -107.29), SIMDE_FLOAT32_C( -715.08), SIMDE_FLOAT32_C(  503.15));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NGT_UQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -792.34), SIMDE_FLOAT32_C(  644.13), SIMDE_FLOAT32_C( -103.88), SIMDE_FLOAT32_C(  651.28));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   95.97), SIMDE_FLOAT32_C(   33.42), SIMDE_FLOAT32_C( -634.97), SIMDE_FLOAT32_C(  883.69));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_FALSE_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  218.19), SIMDE_FLOAT32_C( -253.10), SIMDE_FLOAT32_C(  639.91), SIMDE_FLOAT32_C(  539.70));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  363.48), SIMDE_FLOAT32_C( -215.54), SIMDE_FLOAT32_C( -953.32), SIMDE_FLOAT32_C(  216.26));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_NEQ_OS);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -168.77), SIMDE_FLOAT32_C( -919.40), SIMDE_FLOAT32_C(  791.57), SIMDE_FLOAT32_C( -550.77));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  879.65), SIMDE_FLOAT32_C(  140.25), SIMDE_FLOAT32_C( -548.43), SIMDE_FLOAT32_C( -209.64));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_GE_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -239.98), SIMDE_FLOAT32_C( -569.53), SIMDE_FLOAT32_C(  225.34), SIMDE_FLOAT32_C( -242.34));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  514.36), SIMDE_FLOAT32_C(  873.84), SIMDE_FLOAT32_C(  151.62), SIMDE_FLOAT32_C(  886.55));
  e = simde_mm_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_GT_OQ);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  -63.94), SIMDE_FLOAT32_C(  491.29), SIMDE_FLOAT32_C( -755.45), SIMDE_FLOAT32_C(  869.26));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  206.87), SIMDE_FLOAT32_C( -613.92), SIMDE_FLOAT32_C(  387.86), SIMDE_FLOAT32_C(  -36.43));
  e = simde_mm_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm_cmp_ps(a, b, SIMDE_CMP_TRUE_US);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmp_sd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128d a, b, r, e;

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  107.30), SIMDE_FLOAT64_C( -206.83));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  787.17), SIMDE_FLOAT64_C( -721.13));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  107.30), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 0);
  simde_assert_m128d_equal(r, e);

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(   33.46), SIMDE_FLOAT64_C(  248.77));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -730.30), SIMDE_FLOAT64_C(  751.84));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(   33.46), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 1);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.40), SIMDE_FLOAT64_C(   23.60));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -939.31), SIMDE_FLOAT64_C( -627.35));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  -53.40), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 2);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -636.30), SIMDE_FLOAT64_C( -129.84));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  230.46), SIMDE_FLOAT64_C( -440.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -636.30), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 3);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  961.48), SIMDE_FLOAT64_C(  556.89));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  374.50), SIMDE_FLOAT64_C(  904.56));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  961.48), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 4);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -605.79), SIMDE_FLOAT64_C( -288.15));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -656.14), SIMDE_FLOAT64_C(  374.06));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -605.79), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 5);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -592.25), SIMDE_FLOAT64_C( -155.18));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -130.80), SIMDE_FLOAT64_C(  432.83));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -592.25), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 6);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -431.55), SIMDE_FLOAT64_C(  636.53));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -452.34), SIMDE_FLOAT64_C( -728.36));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -431.55), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 7);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -183.31), SIMDE_FLOAT64_C( -243.73));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  442.30), SIMDE_FLOAT64_C(  450.60));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -183.31), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 8);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -210.29), SIMDE_FLOAT64_C(  -50.46));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -734.21), SIMDE_FLOAT64_C(  273.75));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -210.29), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 9);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -186.57), SIMDE_FLOAT64_C( -822.86));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -462.18), SIMDE_FLOAT64_C( -425.13));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -186.57), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 10);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  968.62), SIMDE_FLOAT64_C( -745.37));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -464.28), SIMDE_FLOAT64_C(  713.42));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  968.62), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 11);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  671.94), SIMDE_FLOAT64_C( -405.59));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -842.74), SIMDE_FLOAT64_C( -483.02));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  671.94), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 12);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -228.63), SIMDE_FLOAT64_C(  298.91));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -708.14), SIMDE_FLOAT64_C(  189.31));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -228.63), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 13);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -797.77), SIMDE_FLOAT64_C( -286.96));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  288.87), SIMDE_FLOAT64_C(  398.76));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -797.77), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 14);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -248.44), SIMDE_FLOAT64_C(  191.43));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  602.04), SIMDE_FLOAT64_C(  999.35));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -248.44), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 15);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -614.65), SIMDE_FLOAT64_C(  963.28));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -385.61), SIMDE_FLOAT64_C(  770.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -614.65), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 16);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -717.70), SIMDE_FLOAT64_C(  750.92));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  618.97), SIMDE_FLOAT64_C(  676.03));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -717.70), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 17);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  561.50), SIMDE_FLOAT64_C(  549.62));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -454.02), SIMDE_FLOAT64_C( -961.18));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  561.50), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 18);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -480.89), SIMDE_FLOAT64_C(  -68.38));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  293.48), SIMDE_FLOAT64_C(  459.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -480.89), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 19);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -600.32), SIMDE_FLOAT64_C( -105.54));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -623.63), SIMDE_FLOAT64_C(  235.12));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -600.32), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 20);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  548.84), SIMDE_FLOAT64_C(  411.69));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  824.49), SIMDE_FLOAT64_C( -866.20));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  548.84), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 21);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  201.44), SIMDE_FLOAT64_C(  276.75));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -301.93), SIMDE_FLOAT64_C( -238.56));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  201.44), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 22);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  250.23), SIMDE_FLOAT64_C( -604.81));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  557.49), SIMDE_FLOAT64_C(  137.99));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  250.23), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 23);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -235.15), SIMDE_FLOAT64_C( -121.76));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -394.35), SIMDE_FLOAT64_C(  272.69));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -235.15), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 24);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  119.18), SIMDE_FLOAT64_C(  423.89));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  610.02), SIMDE_FLOAT64_C( -437.27));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  119.18), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 25);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -156.34), SIMDE_FLOAT64_C( -571.13));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -665.54), SIMDE_FLOAT64_C(  -18.98));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -156.34), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 26);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  685.87), SIMDE_FLOAT64_C( -600.86));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -804.08), SIMDE_FLOAT64_C( -631.16));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  685.87), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 27);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  959.19), SIMDE_FLOAT64_C( -478.47));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C( -520.61), SIMDE_FLOAT64_C( -214.50));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  959.19), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 28);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -527.73), SIMDE_FLOAT64_C( -211.69));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  356.74), SIMDE_FLOAT64_C(  955.71));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -527.73), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 29);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C( -426.25), SIMDE_FLOAT64_C( -493.55));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  886.66), SIMDE_FLOAT64_C(  569.52));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C( -426.25), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm_cmp_sd(a, b, 30);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  a = simde_mm_set_pd(SIMDE_FLOAT64_C(  981.35), SIMDE_FLOAT64_C( -586.10));
  b = simde_mm_set_pd(SIMDE_FLOAT64_C(  775.81), SIMDE_FLOAT64_C(  631.37));
  e = simde_mm_set_pd(SIMDE_FLOAT64_C(  981.35), SIMDE_F64_ALL_SET);
  r = simde_mm_cmp_sd(a, b, 31);
  simde_assert_m128i_u64(simde_mm_castpd_si128(r), ==, simde_mm_castpd_si128(e));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_cmp_ss(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m128 a, b, r, e;

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   29.86), SIMDE_FLOAT32_C( -506.56), SIMDE_FLOAT32_C(   52.70), SIMDE_FLOAT32_C( -451.19));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -773.77), SIMDE_FLOAT32_C(  947.93), SIMDE_FLOAT32_C( -234.67), SIMDE_FLOAT32_C( -847.97));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   29.86), SIMDE_FLOAT32_C( -506.56), SIMDE_FLOAT32_C(   52.70), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 0);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -133.43), SIMDE_FLOAT32_C(  949.13), SIMDE_FLOAT32_C(  326.28), SIMDE_FLOAT32_C(  158.71));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  684.48), SIMDE_FLOAT32_C(  677.57), SIMDE_FLOAT32_C( -960.66), SIMDE_FLOAT32_C( -282.67));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -133.43), SIMDE_FLOAT32_C(  949.13), SIMDE_FLOAT32_C(  326.28), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 1);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  193.40), SIMDE_FLOAT32_C(  779.62), SIMDE_FLOAT32_C( -982.70), SIMDE_FLOAT32_C(  733.89));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  820.93), SIMDE_FLOAT32_C(   29.11), SIMDE_FLOAT32_C( -999.26), SIMDE_FLOAT32_C(   78.74));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  193.40), SIMDE_FLOAT32_C(  779.62), SIMDE_FLOAT32_C( -982.70), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 2);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  253.28), SIMDE_FLOAT32_C(  166.31), SIMDE_FLOAT32_C(  346.10), SIMDE_FLOAT32_C(  502.59));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  807.03), SIMDE_FLOAT32_C(  802.13), SIMDE_FLOAT32_C(  411.74), SIMDE_FLOAT32_C(  596.93));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  253.28), SIMDE_FLOAT32_C(  166.31), SIMDE_FLOAT32_C(  346.10), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 3);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  820.59), SIMDE_FLOAT32_C(  257.56), SIMDE_FLOAT32_C( -468.51), SIMDE_FLOAT32_C( -573.74));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -952.67), SIMDE_FLOAT32_C( -547.39), SIMDE_FLOAT32_C(   82.21), SIMDE_FLOAT32_C(   55.32));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  820.59), SIMDE_FLOAT32_C(  257.56), SIMDE_FLOAT32_C( -468.51), SIMDE_FLOAT32_C( -573.74)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 4);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -856.96), SIMDE_FLOAT32_C(  380.95), SIMDE_FLOAT32_C(  354.16), SIMDE_FLOAT32_C(  933.34));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  937.78), SIMDE_FLOAT32_C( -846.91), SIMDE_FLOAT32_C(  481.96), SIMDE_FLOAT32_C( -401.55));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -856.96), SIMDE_FLOAT32_C(  380.95), SIMDE_FLOAT32_C(  354.16), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 5);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  701.49), SIMDE_FLOAT32_C(  203.70), SIMDE_FLOAT32_C( -473.49), SIMDE_FLOAT32_C(  919.68));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  917.48), SIMDE_FLOAT32_C(  496.48), SIMDE_FLOAT32_C( -380.99), SIMDE_FLOAT32_C( -612.04));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  701.49), SIMDE_FLOAT32_C(  203.70), SIMDE_FLOAT32_C( -473.49), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 6);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -495.27), SIMDE_FLOAT32_C(    2.61), SIMDE_FLOAT32_C(  190.46), SIMDE_FLOAT32_C( -489.47));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  733.40), SIMDE_FLOAT32_C( -262.53), SIMDE_FLOAT32_C( -250.54), SIMDE_FLOAT32_C(  753.56));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -495.27), SIMDE_FLOAT32_C(    2.61), SIMDE_FLOAT32_C(  190.46), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 7);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -295.58), SIMDE_FLOAT32_C(  686.48), SIMDE_FLOAT32_C( -715.68), SIMDE_FLOAT32_C( -678.55));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -64.78), SIMDE_FLOAT32_C( -994.32), SIMDE_FLOAT32_C(  819.61), SIMDE_FLOAT32_C( -435.68));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -295.58), SIMDE_FLOAT32_C(  686.48), SIMDE_FLOAT32_C( -715.68), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 8);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -446.36), SIMDE_FLOAT32_C( -630.25), SIMDE_FLOAT32_C(  895.61), SIMDE_FLOAT32_C( -359.83));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -712.74), SIMDE_FLOAT32_C( -683.20), SIMDE_FLOAT32_C( -684.03), SIMDE_FLOAT32_C(  476.51));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -446.36), SIMDE_FLOAT32_C( -630.25), SIMDE_FLOAT32_C(  895.61), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 9);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  453.59), SIMDE_FLOAT32_C( -704.68), SIMDE_FLOAT32_C(  968.54), SIMDE_FLOAT32_C(  -73.76));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -793.56), SIMDE_FLOAT32_C( -626.26), SIMDE_FLOAT32_C(  371.33), SIMDE_FLOAT32_C(  945.10));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  453.59), SIMDE_FLOAT32_C( -704.68), SIMDE_FLOAT32_C(  968.54), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 10);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  747.32), SIMDE_FLOAT32_C(  722.71), SIMDE_FLOAT32_C(   10.11), SIMDE_FLOAT32_C( -589.46));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -358.96), SIMDE_FLOAT32_C( -216.71), SIMDE_FLOAT32_C( -367.08), SIMDE_FLOAT32_C(  571.81));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  747.32), SIMDE_FLOAT32_C(  722.71), SIMDE_FLOAT32_C(   10.11), SIMDE_FLOAT32_C( -589.46)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 11);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -393.04), SIMDE_FLOAT32_C( -521.21), SIMDE_FLOAT32_C(  315.85), SIMDE_FLOAT32_C(  101.30));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -254.13), SIMDE_FLOAT32_C(  380.76), SIMDE_FLOAT32_C(  862.95), SIMDE_FLOAT32_C( -994.97));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -393.04), SIMDE_FLOAT32_C( -521.21), SIMDE_FLOAT32_C(  315.85), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 12);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -429.51), SIMDE_FLOAT32_C(  950.04), SIMDE_FLOAT32_C(  770.94), SIMDE_FLOAT32_C( -853.08));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  178.64), SIMDE_FLOAT32_C(  -50.79), SIMDE_FLOAT32_C(  741.69), SIMDE_FLOAT32_C( -786.81));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -429.51), SIMDE_FLOAT32_C(  950.04), SIMDE_FLOAT32_C(  770.94), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 13);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  499.30), SIMDE_FLOAT32_C(  807.95), SIMDE_FLOAT32_C( -410.68), SIMDE_FLOAT32_C(  505.23));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -114.66), SIMDE_FLOAT32_C(  865.01), SIMDE_FLOAT32_C( -665.39), SIMDE_FLOAT32_C(  342.00));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  499.30), SIMDE_FLOAT32_C(  807.95), SIMDE_FLOAT32_C( -410.68), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 14);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  744.11), SIMDE_FLOAT32_C(  103.80), SIMDE_FLOAT32_C(  230.08), SIMDE_FLOAT32_C( -784.93));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -640.30), SIMDE_FLOAT32_C(  690.88), SIMDE_FLOAT32_C( -782.01), SIMDE_FLOAT32_C( -779.01));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  744.11), SIMDE_FLOAT32_C(  103.80), SIMDE_FLOAT32_C(  230.08), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 15);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  937.00), SIMDE_FLOAT32_C( -237.56), SIMDE_FLOAT32_C(  614.04), SIMDE_FLOAT32_C( -552.02));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  636.71), SIMDE_FLOAT32_C(  821.24), SIMDE_FLOAT32_C(  385.34), SIMDE_FLOAT32_C( -655.54));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  937.00), SIMDE_FLOAT32_C( -237.56), SIMDE_FLOAT32_C(  614.04), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 16);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -840.84), SIMDE_FLOAT32_C( -184.65), SIMDE_FLOAT32_C(  856.01), SIMDE_FLOAT32_C(  182.80));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  -54.26), SIMDE_FLOAT32_C(  831.01), SIMDE_FLOAT32_C( -693.60), SIMDE_FLOAT32_C( -149.67));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -840.84), SIMDE_FLOAT32_C( -184.65), SIMDE_FLOAT32_C(  856.01), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 17);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  422.72), SIMDE_FLOAT32_C( -740.98), SIMDE_FLOAT32_C( -971.04), SIMDE_FLOAT32_C(   90.38));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  787.23), SIMDE_FLOAT32_C( -946.13), SIMDE_FLOAT32_C(  562.60), SIMDE_FLOAT32_C(   34.39));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  422.72), SIMDE_FLOAT32_C( -740.98), SIMDE_FLOAT32_C( -971.04), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 18);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  379.97), SIMDE_FLOAT32_C(  252.47), SIMDE_FLOAT32_C(  573.41), SIMDE_FLOAT32_C(  371.64));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   86.67), SIMDE_FLOAT32_C(  230.06), SIMDE_FLOAT32_C(  816.36), SIMDE_FLOAT32_C( -574.41));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  379.97), SIMDE_FLOAT32_C(  252.47), SIMDE_FLOAT32_C(  573.41), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 19);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -387.90), SIMDE_FLOAT32_C( -409.94), SIMDE_FLOAT32_C(  339.05), SIMDE_FLOAT32_C(  567.23));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  548.12), SIMDE_FLOAT32_C(  482.27), SIMDE_FLOAT32_C( -877.01), SIMDE_FLOAT32_C(  105.90));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -387.90), SIMDE_FLOAT32_C( -409.94), SIMDE_FLOAT32_C(  339.05), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 20);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  443.93), SIMDE_FLOAT32_C(  879.02), SIMDE_FLOAT32_C(  280.77), SIMDE_FLOAT32_C(  215.63));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  858.68), SIMDE_FLOAT32_C(  507.37), SIMDE_FLOAT32_C(  274.86), SIMDE_FLOAT32_C( -935.31));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  443.93), SIMDE_FLOAT32_C(  879.02), SIMDE_FLOAT32_C(  280.77), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 21);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  417.98), SIMDE_FLOAT32_C(  304.47), SIMDE_FLOAT32_C( -370.04), SIMDE_FLOAT32_C(  620.00));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -491.67), SIMDE_FLOAT32_C(  756.54), SIMDE_FLOAT32_C( -538.71), SIMDE_FLOAT32_C( -880.53));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  417.98), SIMDE_FLOAT32_C(  304.47), SIMDE_FLOAT32_C( -370.04), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 22);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -778.82), SIMDE_FLOAT32_C( -277.37), SIMDE_FLOAT32_C( -561.10), SIMDE_FLOAT32_C(  913.75));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -799.75), SIMDE_FLOAT32_C(  322.89), SIMDE_FLOAT32_C(  168.49), SIMDE_FLOAT32_C( -586.31));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -778.82), SIMDE_FLOAT32_C( -277.37), SIMDE_FLOAT32_C( -561.10), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 23);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(   19.63), SIMDE_FLOAT32_C( -796.59), SIMDE_FLOAT32_C(  829.80), SIMDE_FLOAT32_C(  577.01));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  825.83), SIMDE_FLOAT32_C( -702.38), SIMDE_FLOAT32_C(  909.63), SIMDE_FLOAT32_C( -668.68));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(   19.63), SIMDE_FLOAT32_C( -796.59), SIMDE_FLOAT32_C(  829.80), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 24);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -935.55), SIMDE_FLOAT32_C( -906.06), SIMDE_FLOAT32_C(   23.18), SIMDE_FLOAT32_C( -374.29));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(  903.69), SIMDE_FLOAT32_C( -930.74), SIMDE_FLOAT32_C( -354.90), SIMDE_FLOAT32_C( -304.33));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -935.55), SIMDE_FLOAT32_C( -906.06), SIMDE_FLOAT32_C(   23.18), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 25);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -730.13), SIMDE_FLOAT32_C( -258.50), SIMDE_FLOAT32_C( -873.85), SIMDE_FLOAT32_C( -348.94));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   29.53), SIMDE_FLOAT32_C(  827.18), SIMDE_FLOAT32_C(  334.24), SIMDE_FLOAT32_C( -491.97));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -730.13), SIMDE_FLOAT32_C( -258.50), SIMDE_FLOAT32_C( -873.85), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 26);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -381.04), SIMDE_FLOAT32_C(  669.32), SIMDE_FLOAT32_C( -574.70), SIMDE_FLOAT32_C(  440.24));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -837.63), SIMDE_FLOAT32_C( -877.92), SIMDE_FLOAT32_C( -226.69), SIMDE_FLOAT32_C( -557.27));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -381.04), SIMDE_FLOAT32_C(  669.32), SIMDE_FLOAT32_C( -574.70), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 27);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C(  239.21), SIMDE_FLOAT32_C(  527.22), SIMDE_FLOAT32_C(  489.56), SIMDE_FLOAT32_C(  238.84));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -364.20), SIMDE_FLOAT32_C(  722.98), SIMDE_FLOAT32_C(  475.77), SIMDE_FLOAT32_C( -967.04));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C(  239.21), SIMDE_FLOAT32_C(  527.22), SIMDE_FLOAT32_C(  489.56), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 28);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -308.58), SIMDE_FLOAT32_C( -108.66), SIMDE_FLOAT32_C(  857.88), SIMDE_FLOAT32_C( -131.87));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -505.11), SIMDE_FLOAT32_C( -213.47), SIMDE_FLOAT32_C(   71.14), SIMDE_FLOAT32_C( -330.60));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -308.58), SIMDE_FLOAT32_C( -108.66), SIMDE_FLOAT32_C(  857.88), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 29);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -236.42), SIMDE_FLOAT32_C(  925.60), SIMDE_FLOAT32_C(  252.25), SIMDE_FLOAT32_C( -546.68));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C(   67.98), SIMDE_FLOAT32_C( -613.65), SIMDE_FLOAT32_C( -165.27), SIMDE_FLOAT32_C(  109.49));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -236.42), SIMDE_FLOAT32_C(  925.60), SIMDE_FLOAT32_C(  252.25), SIMDE_FLOAT32_C(    0.00)), simde_mm_setzero_ps());
  r = simde_mm_cmp_ss(a, b, 30);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  a = simde_mm_set_ps(SIMDE_FLOAT32_C( -851.42), SIMDE_FLOAT32_C(  716.28), SIMDE_FLOAT32_C(  257.21), SIMDE_FLOAT32_C(  191.16));
  b = simde_mm_set_ps(SIMDE_FLOAT32_C( -758.42), SIMDE_FLOAT32_C(  731.61), SIMDE_FLOAT32_C(   23.45), SIMDE_FLOAT32_C(  503.57));
  e = simde_mm_move_ss(simde_mm_set_ps(SIMDE_FLOAT32_C( -851.42), SIMDE_FLOAT32_C(  716.28), SIMDE_FLOAT32_C(  257.21), SIMDE_FLOAT32_C(     0.0)), simde_x_mm_setone_ps());
  r = simde_mm_cmp_ss(a, b, 31);
  simde_assert_m128i_u32(simde_mm_castps_si128(r), ==, simde_mm_castps_si128(e));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmp_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256d a, b, r, e;

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -357.57), SIMDE_FLOAT64_C(  765.93),
                         SIMDE_FLOAT64_C( -550.14), SIMDE_FLOAT64_C(  -22.41));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  868.56), SIMDE_FLOAT64_C(  688.68),
                         SIMDE_FLOAT64_C( -724.59), SIMDE_FLOAT64_C(  334.75));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 0);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -54.73), SIMDE_FLOAT64_C(   28.08),
                         SIMDE_FLOAT64_C(   97.90), SIMDE_FLOAT64_C(  892.29));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -838.35), SIMDE_FLOAT64_C(  389.60),
                         SIMDE_FLOAT64_C( -784.06), SIMDE_FLOAT64_C( -852.24));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 1);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -763.82), SIMDE_FLOAT64_C( -666.98),
                         SIMDE_FLOAT64_C(   95.45), SIMDE_FLOAT64_C(  511.10));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(   72.91), SIMDE_FLOAT64_C(  842.59),
                         SIMDE_FLOAT64_C( -301.64), SIMDE_FLOAT64_C(  977.39));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 2);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -891.91), SIMDE_FLOAT64_C( -127.40),
                         SIMDE_FLOAT64_C(  463.49), SIMDE_FLOAT64_C(  177.91));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -341.50), SIMDE_FLOAT64_C(  153.72),
                         SIMDE_FLOAT64_C(  151.04), SIMDE_FLOAT64_C( -348.13));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 3);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  100.63), SIMDE_FLOAT64_C(  228.90),
                         SIMDE_FLOAT64_C( -642.19), SIMDE_FLOAT64_C( -977.08));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  565.32), SIMDE_FLOAT64_C( -745.60),
                         SIMDE_FLOAT64_C( -937.14), SIMDE_FLOAT64_C( -396.84));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 4);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -698.69), SIMDE_FLOAT64_C(  381.53),
                         SIMDE_FLOAT64_C( -995.38), SIMDE_FLOAT64_C(  904.84));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  610.68), SIMDE_FLOAT64_C(  607.60),
                         SIMDE_FLOAT64_C(  346.14), SIMDE_FLOAT64_C( -567.77));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 5);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -32.88), SIMDE_FLOAT64_C(  456.08),
                         SIMDE_FLOAT64_C( -158.08), SIMDE_FLOAT64_C( -924.19));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -46.81), SIMDE_FLOAT64_C( -380.35),
                         SIMDE_FLOAT64_C(  820.23), SIMDE_FLOAT64_C( -250.91));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 6);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -875.29), SIMDE_FLOAT64_C(   57.11),
                         SIMDE_FLOAT64_C(  260.25), SIMDE_FLOAT64_C(  164.20));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  715.03), SIMDE_FLOAT64_C(  526.68),
                         SIMDE_FLOAT64_C(  724.10), SIMDE_FLOAT64_C( -661.45));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 7);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -59.93), SIMDE_FLOAT64_C(  531.74),
                         SIMDE_FLOAT64_C(  694.87), SIMDE_FLOAT64_C(  114.93));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  415.34), SIMDE_FLOAT64_C(  611.46),
                         SIMDE_FLOAT64_C( -279.38), SIMDE_FLOAT64_C(  402.62));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 8);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  414.18), SIMDE_FLOAT64_C( -763.39),
                         SIMDE_FLOAT64_C(  386.06), SIMDE_FLOAT64_C(  874.65));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  544.80), SIMDE_FLOAT64_C(  381.68),
                         SIMDE_FLOAT64_C(  466.15), SIMDE_FLOAT64_C( -212.81));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 9);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  970.77), SIMDE_FLOAT64_C( -757.81),
                         SIMDE_FLOAT64_C(  907.57), SIMDE_FLOAT64_C(  981.95));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  537.33), SIMDE_FLOAT64_C( -552.73),
                         SIMDE_FLOAT64_C( -335.84), SIMDE_FLOAT64_C(  263.81));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 10);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  792.31), SIMDE_FLOAT64_C(  400.04),
                         SIMDE_FLOAT64_C( -788.48), SIMDE_FLOAT64_C(  167.61));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  212.33), SIMDE_FLOAT64_C(  296.89),
                         SIMDE_FLOAT64_C(  622.33), SIMDE_FLOAT64_C( -766.53));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 11);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  758.22), SIMDE_FLOAT64_C( -663.32),
                         SIMDE_FLOAT64_C( -999.81), SIMDE_FLOAT64_C(  133.54));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -236.40), SIMDE_FLOAT64_C(  458.49),
                         SIMDE_FLOAT64_C( -796.87), SIMDE_FLOAT64_C(  971.44));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 12);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -918.24), SIMDE_FLOAT64_C( -553.29),
                         SIMDE_FLOAT64_C(  709.03), SIMDE_FLOAT64_C(  -42.30));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -249.29), SIMDE_FLOAT64_C( -863.89),
                         SIMDE_FLOAT64_C(  838.41), SIMDE_FLOAT64_C( -285.41));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 13);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -668.93), SIMDE_FLOAT64_C( -420.18),
                         SIMDE_FLOAT64_C(  785.36), SIMDE_FLOAT64_C( -788.63));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  111.55), SIMDE_FLOAT64_C( -222.13),
                         SIMDE_FLOAT64_C( -579.35), SIMDE_FLOAT64_C( -996.45));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 14);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  841.84), SIMDE_FLOAT64_C( -686.81),
                         SIMDE_FLOAT64_C( -199.31), SIMDE_FLOAT64_C(  982.01));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  421.52), SIMDE_FLOAT64_C(  488.69),
                         SIMDE_FLOAT64_C(  995.06), SIMDE_FLOAT64_C( -730.80));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 15);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -95.24), SIMDE_FLOAT64_C(  253.40),
                         SIMDE_FLOAT64_C( -815.08), SIMDE_FLOAT64_C(  358.42));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -399.53), SIMDE_FLOAT64_C( -710.61),
                         SIMDE_FLOAT64_C( -422.64), SIMDE_FLOAT64_C( -148.83));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 16);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(   77.77), SIMDE_FLOAT64_C(  698.58),
                         SIMDE_FLOAT64_C(  -27.60), SIMDE_FLOAT64_C(  435.81));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -150.12), SIMDE_FLOAT64_C( -751.03),
                         SIMDE_FLOAT64_C( -597.97), SIMDE_FLOAT64_C( -937.82));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 17);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -838.78), SIMDE_FLOAT64_C(   93.35),
                         SIMDE_FLOAT64_C( -825.83), SIMDE_FLOAT64_C( -323.02));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -282.39), SIMDE_FLOAT64_C(  572.90),
                         SIMDE_FLOAT64_C( -581.23), SIMDE_FLOAT64_C(   32.08));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 18);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -807.33), SIMDE_FLOAT64_C(  664.63),
                         SIMDE_FLOAT64_C(  982.61), SIMDE_FLOAT64_C(   63.27));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  946.39), SIMDE_FLOAT64_C(  207.32),
                         SIMDE_FLOAT64_C(   -9.66), SIMDE_FLOAT64_C(   11.76));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 19);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -738.69), SIMDE_FLOAT64_C( -322.11),
                         SIMDE_FLOAT64_C( -163.93), SIMDE_FLOAT64_C( -138.57));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  684.55), SIMDE_FLOAT64_C( -319.23),
                         SIMDE_FLOAT64_C(  930.19), SIMDE_FLOAT64_C(  517.01));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 20);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -76.84), SIMDE_FLOAT64_C(  457.06),
                         SIMDE_FLOAT64_C(  575.12), SIMDE_FLOAT64_C(  845.68));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  233.22), SIMDE_FLOAT64_C( -237.00),
                         SIMDE_FLOAT64_C( -964.93), SIMDE_FLOAT64_C(  750.37));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 21);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  199.98), SIMDE_FLOAT64_C(  741.05),
                         SIMDE_FLOAT64_C( -723.44), SIMDE_FLOAT64_C(  323.27));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  103.44), SIMDE_FLOAT64_C( -854.52),
                         SIMDE_FLOAT64_C(  244.92), SIMDE_FLOAT64_C(  486.47));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 22);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -576.37), SIMDE_FLOAT64_C(  750.85),
                         SIMDE_FLOAT64_C(  434.13), SIMDE_FLOAT64_C(  344.29));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -968.83), SIMDE_FLOAT64_C(  577.41),
                         SIMDE_FLOAT64_C(  995.59), SIMDE_FLOAT64_C(  750.10));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 23);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  526.25), SIMDE_FLOAT64_C(  -57.74),
                         SIMDE_FLOAT64_C( -432.94), SIMDE_FLOAT64_C(  882.68));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C( -495.53), SIMDE_FLOAT64_C( -602.01),
                         SIMDE_FLOAT64_C( -925.63), SIMDE_FLOAT64_C(  123.17));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 24);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -567.21), SIMDE_FLOAT64_C(  600.16),
                         SIMDE_FLOAT64_C( -766.87), SIMDE_FLOAT64_C(   11.16));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  695.58), SIMDE_FLOAT64_C(  482.48),
                         SIMDE_FLOAT64_C(  350.48), SIMDE_FLOAT64_C( -969.97));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_FLOAT64_C(    0.00),
                         SIMDE_F64_ALL_SET, SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 25);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -85.80), SIMDE_FLOAT64_C(  500.17),
                         SIMDE_FLOAT64_C(  916.37), SIMDE_FLOAT64_C(  398.15));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  745.00), SIMDE_FLOAT64_C( -144.13),
                         SIMDE_FLOAT64_C( -516.66), SIMDE_FLOAT64_C(  995.75));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 26);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  546.73), SIMDE_FLOAT64_C( -603.02),
                         SIMDE_FLOAT64_C( -971.83), SIMDE_FLOAT64_C(  389.90));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  776.68), SIMDE_FLOAT64_C( -130.82),
                         SIMDE_FLOAT64_C(  580.30), SIMDE_FLOAT64_C(  704.29));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));
  r = simde_mm256_cmp_pd(a, b, 27);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C( -164.05), SIMDE_FLOAT64_C(  409.22),
                         SIMDE_FLOAT64_C( -602.22), SIMDE_FLOAT64_C(  375.71));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  363.61), SIMDE_FLOAT64_C( -315.81),
                         SIMDE_FLOAT64_C( -199.39), SIMDE_FLOAT64_C(  806.44));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 28);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  200.12), SIMDE_FLOAT64_C(  648.82),
                         SIMDE_FLOAT64_C(  -75.31), SIMDE_FLOAT64_C(  801.78));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  431.61), SIMDE_FLOAT64_C(  123.43),
                         SIMDE_FLOAT64_C(  753.52), SIMDE_FLOAT64_C( -346.75));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 29);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -27.55), SIMDE_FLOAT64_C(  895.94),
                         SIMDE_FLOAT64_C(  742.64), SIMDE_FLOAT64_C(  -59.01));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  812.89), SIMDE_FLOAT64_C( -405.22),
                         SIMDE_FLOAT64_C(  782.32), SIMDE_FLOAT64_C( -131.42));
  e = simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET,
                         SIMDE_FLOAT64_C(    0.00), SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 30);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  a = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -68.17), SIMDE_FLOAT64_C( -246.45),
                         SIMDE_FLOAT64_C(   32.69), SIMDE_FLOAT64_C( -878.59));
  b = simde_mm256_set_pd(SIMDE_FLOAT64_C(  -82.57), SIMDE_FLOAT64_C(  930.53),
                         SIMDE_FLOAT64_C( -591.17), SIMDE_FLOAT64_C( -164.90));
  e = simde_mm256_set_pd(SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET,
                         SIMDE_F64_ALL_SET, SIMDE_F64_ALL_SET);
  r = simde_mm256_cmp_pd(a, b, 31);
  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cmp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256 a, b, r, e;

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  803.75), SIMDE_FLOAT32_C(   41.82),
                         SIMDE_FLOAT32_C( -135.21), SIMDE_FLOAT32_C( -426.86),
                         SIMDE_FLOAT32_C( -667.45), SIMDE_FLOAT32_C( -471.27),
                         SIMDE_FLOAT32_C(  582.67), SIMDE_FLOAT32_C( -556.69));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  947.23), SIMDE_FLOAT32_C( -284.56),
                         SIMDE_FLOAT32_C( -696.40), SIMDE_FLOAT32_C(  148.35),
                         SIMDE_FLOAT32_C(  759.58), SIMDE_FLOAT32_C(  941.33),
                         SIMDE_FLOAT32_C( -734.70), SIMDE_FLOAT32_C( -491.66));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 0);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  631.77), SIMDE_FLOAT32_C(  277.52),
                         SIMDE_FLOAT32_C( -622.54), SIMDE_FLOAT32_C( -161.68),
                         SIMDE_FLOAT32_C( -898.32), SIMDE_FLOAT32_C( -313.15),
                         SIMDE_FLOAT32_C( -233.08), SIMDE_FLOAT32_C(  -49.93));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -870.15), SIMDE_FLOAT32_C( -811.55),
                         SIMDE_FLOAT32_C(   94.74), SIMDE_FLOAT32_C(  -36.95),
                         SIMDE_FLOAT32_C( -368.63), SIMDE_FLOAT32_C(  744.09),
                         SIMDE_FLOAT32_C( -903.28), SIMDE_FLOAT32_C(  297.64));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 1);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -390.61), SIMDE_FLOAT32_C(  155.36),
                         SIMDE_FLOAT32_C( -387.67), SIMDE_FLOAT32_C( -531.88),
                         SIMDE_FLOAT32_C( -713.17), SIMDE_FLOAT32_C(  805.71),
                         SIMDE_FLOAT32_C(  886.16), SIMDE_FLOAT32_C(  319.56));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -28.95), SIMDE_FLOAT32_C(  -30.42),
                         SIMDE_FLOAT32_C(  455.91), SIMDE_FLOAT32_C( -309.55),
                         SIMDE_FLOAT32_C(  306.68), SIMDE_FLOAT32_C(   44.72),
                         SIMDE_FLOAT32_C(  995.53), SIMDE_FLOAT32_C( -435.97));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 2);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  108.25), SIMDE_FLOAT32_C( -817.89),
                         SIMDE_FLOAT32_C(  544.18), SIMDE_FLOAT32_C( -228.91),
                         SIMDE_FLOAT32_C(  781.88), SIMDE_FLOAT32_C( -335.51),
                         SIMDE_FLOAT32_C(  838.72), SIMDE_FLOAT32_C(  548.66));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -959.57), SIMDE_FLOAT32_C( -439.07),
                         SIMDE_FLOAT32_C(  447.94), SIMDE_FLOAT32_C( -832.97),
                         SIMDE_FLOAT32_C(  300.93), SIMDE_FLOAT32_C(  268.82),
                         SIMDE_FLOAT32_C(  -44.38), SIMDE_FLOAT32_C( -764.37));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 3);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  681.83), SIMDE_FLOAT32_C(  -98.68),
                         SIMDE_FLOAT32_C(  576.60), SIMDE_FLOAT32_C( -825.51),
                         SIMDE_FLOAT32_C( -981.15), SIMDE_FLOAT32_C( -781.62),
                         SIMDE_FLOAT32_C(  238.97), SIMDE_FLOAT32_C(  708.96));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  598.93), SIMDE_FLOAT32_C(  530.78),
                         SIMDE_FLOAT32_C(  290.29), SIMDE_FLOAT32_C(  456.74),
                         SIMDE_FLOAT32_C( -688.44), SIMDE_FLOAT32_C(  479.20),
                         SIMDE_FLOAT32_C( -526.39), SIMDE_FLOAT32_C(  111.85));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 4);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.01), SIMDE_FLOAT32_C(  601.19),
                         SIMDE_FLOAT32_C( -226.39), SIMDE_FLOAT32_C( -602.11),
                         SIMDE_FLOAT32_C( -733.84), SIMDE_FLOAT32_C(  571.60),
                         SIMDE_FLOAT32_C(  888.40), SIMDE_FLOAT32_C(  435.87));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -568.84), SIMDE_FLOAT32_C( -290.97),
                         SIMDE_FLOAT32_C( -428.69), SIMDE_FLOAT32_C(  594.16),
                         SIMDE_FLOAT32_C( -385.45), SIMDE_FLOAT32_C(  878.38),
                         SIMDE_FLOAT32_C(  771.04), SIMDE_FLOAT32_C( -520.10));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 5);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -220.16), SIMDE_FLOAT32_C( -128.37),
                         SIMDE_FLOAT32_C( -559.41), SIMDE_FLOAT32_C( -454.29),
                         SIMDE_FLOAT32_C(  350.58), SIMDE_FLOAT32_C(  911.03),
                         SIMDE_FLOAT32_C(  296.06), SIMDE_FLOAT32_C(  568.62));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -352.18), SIMDE_FLOAT32_C( -372.36),
                         SIMDE_FLOAT32_C(  447.08), SIMDE_FLOAT32_C(  452.17),
                         SIMDE_FLOAT32_C( -243.40), SIMDE_FLOAT32_C(  350.62),
                         SIMDE_FLOAT32_C(  305.52), SIMDE_FLOAT32_C( -502.03));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 6);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  615.60), SIMDE_FLOAT32_C(  619.40),
                         SIMDE_FLOAT32_C(  792.77), SIMDE_FLOAT32_C(  901.05),
                         SIMDE_FLOAT32_C(  333.13), SIMDE_FLOAT32_C(   48.96),
                         SIMDE_FLOAT32_C(  132.32), SIMDE_FLOAT32_C(   26.71));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  120.11), SIMDE_FLOAT32_C(  415.63),
                         SIMDE_FLOAT32_C( -658.13), SIMDE_FLOAT32_C(  663.72),
                         SIMDE_FLOAT32_C(  841.19), SIMDE_FLOAT32_C( -155.80),
                         SIMDE_FLOAT32_C(  212.50), SIMDE_FLOAT32_C( -466.55));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 7);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -433.41), SIMDE_FLOAT32_C( -764.18),
                         SIMDE_FLOAT32_C( -961.58), SIMDE_FLOAT32_C( -874.94),
                         SIMDE_FLOAT32_C( -163.70), SIMDE_FLOAT32_C( -839.31),
                         SIMDE_FLOAT32_C( -667.08), SIMDE_FLOAT32_C(  337.92));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  249.20), SIMDE_FLOAT32_C( -898.78),
                         SIMDE_FLOAT32_C( -555.22), SIMDE_FLOAT32_C(  707.96),
                         SIMDE_FLOAT32_C(  516.92), SIMDE_FLOAT32_C( -556.84),
                         SIMDE_FLOAT32_C( -537.76), SIMDE_FLOAT32_C( -705.36));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 8);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -696.67), SIMDE_FLOAT32_C( -489.80),
                         SIMDE_FLOAT32_C(  200.42), SIMDE_FLOAT32_C( -399.90),
                         SIMDE_FLOAT32_C(  153.90), SIMDE_FLOAT32_C(  505.83),
                         SIMDE_FLOAT32_C(  799.31), SIMDE_FLOAT32_C(  -15.86));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -405.31), SIMDE_FLOAT32_C( -462.02),
                         SIMDE_FLOAT32_C(  631.03), SIMDE_FLOAT32_C( -295.26),
                         SIMDE_FLOAT32_C(  -48.91), SIMDE_FLOAT32_C(  969.53),
                         SIMDE_FLOAT32_C( -852.51), SIMDE_FLOAT32_C(  559.42));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 9);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -561.97), SIMDE_FLOAT32_C( -971.30),
                         SIMDE_FLOAT32_C( -250.24), SIMDE_FLOAT32_C( -325.06),
                         SIMDE_FLOAT32_C(  -51.47), SIMDE_FLOAT32_C( -259.37),
                         SIMDE_FLOAT32_C( -492.34), SIMDE_FLOAT32_C(  100.58));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -848.06), SIMDE_FLOAT32_C( -621.13),
                         SIMDE_FLOAT32_C( -636.90), SIMDE_FLOAT32_C(  992.53),
                         SIMDE_FLOAT32_C( -474.40), SIMDE_FLOAT32_C(  -74.21),
                         SIMDE_FLOAT32_C( -340.21), SIMDE_FLOAT32_C( -243.84));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 10);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  239.07), SIMDE_FLOAT32_C(  874.09),
                         SIMDE_FLOAT32_C(  973.63), SIMDE_FLOAT32_C( -326.74),
                         SIMDE_FLOAT32_C( -105.33), SIMDE_FLOAT32_C( -113.10),
                         SIMDE_FLOAT32_C( -907.53), SIMDE_FLOAT32_C( -299.90));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  153.03), SIMDE_FLOAT32_C(  322.07),
                         SIMDE_FLOAT32_C( -271.79), SIMDE_FLOAT32_C(  197.54),
                         SIMDE_FLOAT32_C(  293.92), SIMDE_FLOAT32_C(    8.21),
                         SIMDE_FLOAT32_C(  456.82), SIMDE_FLOAT32_C( -366.71));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 11);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -287.90), SIMDE_FLOAT32_C( -229.67),
                         SIMDE_FLOAT32_C( -929.73), SIMDE_FLOAT32_C( -179.99),
                         SIMDE_FLOAT32_C(  848.21), SIMDE_FLOAT32_C( -997.57),
                         SIMDE_FLOAT32_C( -656.96), SIMDE_FLOAT32_C( -862.20));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  580.33), SIMDE_FLOAT32_C( -689.10),
                         SIMDE_FLOAT32_C(  649.25), SIMDE_FLOAT32_C(  176.45),
                         SIMDE_FLOAT32_C(  565.41), SIMDE_FLOAT32_C( -548.53),
                         SIMDE_FLOAT32_C( -949.03), SIMDE_FLOAT32_C(  336.81));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 12);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -617.06), SIMDE_FLOAT32_C( -436.28),
                         SIMDE_FLOAT32_C( -774.87), SIMDE_FLOAT32_C(  811.68),
                         SIMDE_FLOAT32_C( -458.23), SIMDE_FLOAT32_C(  612.49),
                         SIMDE_FLOAT32_C(  857.84), SIMDE_FLOAT32_C(   49.61));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -70.22), SIMDE_FLOAT32_C(  598.15),
                         SIMDE_FLOAT32_C( -715.51), SIMDE_FLOAT32_C( -654.30),
                         SIMDE_FLOAT32_C( -597.85), SIMDE_FLOAT32_C( -502.38),
                         SIMDE_FLOAT32_C(  175.10), SIMDE_FLOAT32_C( -126.08));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 13);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  108.84), SIMDE_FLOAT32_C(  652.10),
                         SIMDE_FLOAT32_C( -310.88), SIMDE_FLOAT32_C( -644.71),
                         SIMDE_FLOAT32_C( -530.21), SIMDE_FLOAT32_C(  877.99),
                         SIMDE_FLOAT32_C( -626.95), SIMDE_FLOAT32_C( -794.28));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -222.83), SIMDE_FLOAT32_C( -112.15),
                         SIMDE_FLOAT32_C(  359.65), SIMDE_FLOAT32_C(  441.32),
                         SIMDE_FLOAT32_C( -219.23), SIMDE_FLOAT32_C(  477.22),
                         SIMDE_FLOAT32_C( -766.46), SIMDE_FLOAT32_C( -440.48));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 14);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -718.37), SIMDE_FLOAT32_C(  402.09),
                         SIMDE_FLOAT32_C(  660.94), SIMDE_FLOAT32_C(  280.50),
                         SIMDE_FLOAT32_C( -500.81), SIMDE_FLOAT32_C(  -99.58),
                         SIMDE_FLOAT32_C(  609.32), SIMDE_FLOAT32_C( -871.48));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -231.85), SIMDE_FLOAT32_C( -142.83),
                         SIMDE_FLOAT32_C( -163.21), SIMDE_FLOAT32_C( -687.90),
                         SIMDE_FLOAT32_C( -906.29), SIMDE_FLOAT32_C(  896.58),
                         SIMDE_FLOAT32_C(  176.66), SIMDE_FLOAT32_C( -333.48));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 15);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  116.16), SIMDE_FLOAT32_C(  859.97),
                         SIMDE_FLOAT32_C(  226.33), SIMDE_FLOAT32_C(    8.76),
                         SIMDE_FLOAT32_C(  653.49), SIMDE_FLOAT32_C(  911.94),
                         SIMDE_FLOAT32_C( -467.83), SIMDE_FLOAT32_C(  901.04));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -984.25), SIMDE_FLOAT32_C( -389.87),
                         SIMDE_FLOAT32_C(  153.18), SIMDE_FLOAT32_C(  268.28),
                         SIMDE_FLOAT32_C(  389.59), SIMDE_FLOAT32_C( -887.68),
                         SIMDE_FLOAT32_C(  270.01), SIMDE_FLOAT32_C( -864.64));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 16);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  370.52), SIMDE_FLOAT32_C(  981.11),
                         SIMDE_FLOAT32_C(  129.13), SIMDE_FLOAT32_C( -206.59),
                         SIMDE_FLOAT32_C(  934.43), SIMDE_FLOAT32_C(  784.23),
                         SIMDE_FLOAT32_C( -480.27), SIMDE_FLOAT32_C( -564.50));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -678.14), SIMDE_FLOAT32_C(  144.17),
                         SIMDE_FLOAT32_C( -165.62), SIMDE_FLOAT32_C(  200.67),
                         SIMDE_FLOAT32_C( -971.31), SIMDE_FLOAT32_C( -618.84),
                         SIMDE_FLOAT32_C( -770.29), SIMDE_FLOAT32_C(  646.67));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 17);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  163.45), SIMDE_FLOAT32_C( -974.16),
                         SIMDE_FLOAT32_C( -872.88), SIMDE_FLOAT32_C(  866.32),
                         SIMDE_FLOAT32_C(  589.17), SIMDE_FLOAT32_C( -436.70),
                         SIMDE_FLOAT32_C(  651.94), SIMDE_FLOAT32_C( -800.52));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -321.81), SIMDE_FLOAT32_C(  575.56),
                         SIMDE_FLOAT32_C(  664.13), SIMDE_FLOAT32_C( -598.78),
                         SIMDE_FLOAT32_C(  405.66), SIMDE_FLOAT32_C( -161.92),
                         SIMDE_FLOAT32_C( -284.93), SIMDE_FLOAT32_C(  894.57));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 18);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -267.71), SIMDE_FLOAT32_C(  437.69),
                         SIMDE_FLOAT32_C( -122.76), SIMDE_FLOAT32_C( -910.35),
                         SIMDE_FLOAT32_C( -336.05), SIMDE_FLOAT32_C( -733.70),
                         SIMDE_FLOAT32_C( -255.51), SIMDE_FLOAT32_C(  200.58));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  866.33), SIMDE_FLOAT32_C(  -54.50),
                         SIMDE_FLOAT32_C(  991.32), SIMDE_FLOAT32_C(  618.32),
                         SIMDE_FLOAT32_C( -309.87), SIMDE_FLOAT32_C(  601.57),
                         SIMDE_FLOAT32_C( -408.16), SIMDE_FLOAT32_C(   18.48));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 19);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  -16.05), SIMDE_FLOAT32_C( -298.08),
                         SIMDE_FLOAT32_C(  249.83), SIMDE_FLOAT32_C(  758.02),
                         SIMDE_FLOAT32_C(  479.46), SIMDE_FLOAT32_C(  336.47),
                         SIMDE_FLOAT32_C(  883.93), SIMDE_FLOAT32_C(  849.23));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  527.85), SIMDE_FLOAT32_C(  873.42),
                         SIMDE_FLOAT32_C( -416.27), SIMDE_FLOAT32_C(   38.97),
                         SIMDE_FLOAT32_C( -132.92), SIMDE_FLOAT32_C(  674.04),
                         SIMDE_FLOAT32_C( -271.02), SIMDE_FLOAT32_C(  227.53));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 20);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  614.63), SIMDE_FLOAT32_C(  157.19),
                         SIMDE_FLOAT32_C(  417.58), SIMDE_FLOAT32_C(  646.09),
                         SIMDE_FLOAT32_C( -575.70), SIMDE_FLOAT32_C( -968.11),
                         SIMDE_FLOAT32_C( -412.85), SIMDE_FLOAT32_C(  552.77));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -891.04), SIMDE_FLOAT32_C(   82.95),
                         SIMDE_FLOAT32_C(  -16.42), SIMDE_FLOAT32_C(  297.67),
                         SIMDE_FLOAT32_C( -699.86), SIMDE_FLOAT32_C( -654.27),
                         SIMDE_FLOAT32_C( -999.41), SIMDE_FLOAT32_C( -517.03));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 21);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -836.21), SIMDE_FLOAT32_C( -887.30),
                         SIMDE_FLOAT32_C( -752.55), SIMDE_FLOAT32_C( -796.40),
                         SIMDE_FLOAT32_C(  351.16), SIMDE_FLOAT32_C( -178.21),
                         SIMDE_FLOAT32_C( -706.76), SIMDE_FLOAT32_C(   73.54));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -426.63), SIMDE_FLOAT32_C(  604.12),
                         SIMDE_FLOAT32_C(  650.64), SIMDE_FLOAT32_C(  773.20),
                         SIMDE_FLOAT32_C(  120.86), SIMDE_FLOAT32_C(   -7.00),
                         SIMDE_FLOAT32_C(  471.29), SIMDE_FLOAT32_C(  313.92));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 22);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  116.65), SIMDE_FLOAT32_C( -494.31),
                         SIMDE_FLOAT32_C( -707.48), SIMDE_FLOAT32_C(  709.57),
                         SIMDE_FLOAT32_C(  910.05), SIMDE_FLOAT32_C( -151.47),
                         SIMDE_FLOAT32_C( -953.89), SIMDE_FLOAT32_C( -496.46));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  177.47), SIMDE_FLOAT32_C( -756.65),
                         SIMDE_FLOAT32_C(  255.36), SIMDE_FLOAT32_C( -282.34),
                         SIMDE_FLOAT32_C( -175.69), SIMDE_FLOAT32_C( -724.05),
                         SIMDE_FLOAT32_C(  699.09), SIMDE_FLOAT32_C(  269.04));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 23);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -903.19), SIMDE_FLOAT32_C(  746.12),
                         SIMDE_FLOAT32_C(  342.73), SIMDE_FLOAT32_C(  795.69),
                         SIMDE_FLOAT32_C( -643.05), SIMDE_FLOAT32_C(  437.97),
                         SIMDE_FLOAT32_C(  559.94), SIMDE_FLOAT32_C( -748.98));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(   98.06), SIMDE_FLOAT32_C(  751.33),
                         SIMDE_FLOAT32_C(  270.29), SIMDE_FLOAT32_C(  106.83),
                         SIMDE_FLOAT32_C(  873.71), SIMDE_FLOAT32_C( -291.58),
                         SIMDE_FLOAT32_C( -813.87), SIMDE_FLOAT32_C(  765.52));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 24);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  510.52), SIMDE_FLOAT32_C(   -0.44),
                         SIMDE_FLOAT32_C( -126.10), SIMDE_FLOAT32_C(  409.54),
                         SIMDE_FLOAT32_C(  995.44), SIMDE_FLOAT32_C(  315.04),
                         SIMDE_FLOAT32_C(  962.60), SIMDE_FLOAT32_C(  941.69));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -187.35), SIMDE_FLOAT32_C( -452.95),
                         SIMDE_FLOAT32_C(  721.01), SIMDE_FLOAT32_C(  306.97),
                         SIMDE_FLOAT32_C( -164.06), SIMDE_FLOAT32_C(  498.34),
                         SIMDE_FLOAT32_C( -327.01), SIMDE_FLOAT32_C(   70.94));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 25);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  875.35), SIMDE_FLOAT32_C(  722.91),
                         SIMDE_FLOAT32_C(  314.64), SIMDE_FLOAT32_C(  955.25),
                         SIMDE_FLOAT32_C( -448.66), SIMDE_FLOAT32_C( -836.37),
                         SIMDE_FLOAT32_C( -166.39), SIMDE_FLOAT32_C(  761.84));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  219.22), SIMDE_FLOAT32_C(  980.19),
                         SIMDE_FLOAT32_C(  521.60), SIMDE_FLOAT32_C(  169.38),
                         SIMDE_FLOAT32_C( -454.09), SIMDE_FLOAT32_C( -679.40),
                         SIMDE_FLOAT32_C(  296.09), SIMDE_FLOAT32_C( -189.79));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 26);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  364.98), SIMDE_FLOAT32_C(  544.21),
                         SIMDE_FLOAT32_C(  898.24), SIMDE_FLOAT32_C(  705.23),
                         SIMDE_FLOAT32_C( -349.55), SIMDE_FLOAT32_C( -507.73),
                         SIMDE_FLOAT32_C( -126.59), SIMDE_FLOAT32_C(  632.35));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -343.37), SIMDE_FLOAT32_C( -456.75),
                         SIMDE_FLOAT32_C(  -23.18), SIMDE_FLOAT32_C( -118.51),
                         SIMDE_FLOAT32_C( -748.39), SIMDE_FLOAT32_C(   12.78),
                         SIMDE_FLOAT32_C(  746.33), SIMDE_FLOAT32_C(  804.05));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 27);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(  460.18), SIMDE_FLOAT32_C(  347.74),
                         SIMDE_FLOAT32_C( -472.72), SIMDE_FLOAT32_C(  665.79),
                         SIMDE_FLOAT32_C(  574.55), SIMDE_FLOAT32_C( -914.40),
                         SIMDE_FLOAT32_C(  582.67), SIMDE_FLOAT32_C( -561.20));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -507.07), SIMDE_FLOAT32_C(   23.76),
                         SIMDE_FLOAT32_C( -452.87), SIMDE_FLOAT32_C( -385.46),
                         SIMDE_FLOAT32_C( -717.37), SIMDE_FLOAT32_C(  438.32),
                         SIMDE_FLOAT32_C(  629.22), SIMDE_FLOAT32_C(  831.24));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 28);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -722.18), SIMDE_FLOAT32_C( -347.64),
                         SIMDE_FLOAT32_C( -854.87), SIMDE_FLOAT32_C( -899.08),
                         SIMDE_FLOAT32_C(   85.71), SIMDE_FLOAT32_C( -834.65),
                         SIMDE_FLOAT32_C(  389.94), SIMDE_FLOAT32_C(  481.97));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  314.14), SIMDE_FLOAT32_C(  -60.49),
                         SIMDE_FLOAT32_C(  531.62), SIMDE_FLOAT32_C(  990.93),
                         SIMDE_FLOAT32_C(   96.46), SIMDE_FLOAT32_C(  -19.75),
                         SIMDE_FLOAT32_C( -147.53), SIMDE_FLOAT32_C( -991.98));
  e = simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 29);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C( -326.32), SIMDE_FLOAT32_C(  553.34),
                         SIMDE_FLOAT32_C(  298.71), SIMDE_FLOAT32_C( -419.97),
                         SIMDE_FLOAT32_C(   24.57), SIMDE_FLOAT32_C(  392.20),
                         SIMDE_FLOAT32_C( -704.51), SIMDE_FLOAT32_C(  510.74));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C( -609.44), SIMDE_FLOAT32_C( -312.06),
                         SIMDE_FLOAT32_C(  205.60), SIMDE_FLOAT32_C(  160.74),
                         SIMDE_FLOAT32_C( -717.63), SIMDE_FLOAT32_C( -124.46),
                         SIMDE_FLOAT32_C(  761.31), SIMDE_FLOAT32_C(  650.10));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_FLOAT32_C(    0.00),
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));
  r = simde_mm256_cmp_ps(a, b, 30);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  a = simde_mm256_set_ps(SIMDE_FLOAT32_C(   17.13), SIMDE_FLOAT32_C(  745.11),
                         SIMDE_FLOAT32_C( -376.48), SIMDE_FLOAT32_C(  594.45),
                         SIMDE_FLOAT32_C( -508.77), SIMDE_FLOAT32_C( -947.81),
                         SIMDE_FLOAT32_C(  338.88), SIMDE_FLOAT32_C(  402.07));
  b = simde_mm256_set_ps(SIMDE_FLOAT32_C(  621.66), SIMDE_FLOAT32_C(  302.73),
                         SIMDE_FLOAT32_C(  326.55), SIMDE_FLOAT32_C(  551.02),
                         SIMDE_FLOAT32_C(  772.13), SIMDE_FLOAT32_C(  272.66),
                         SIMDE_FLOAT32_C(  449.95), SIMDE_FLOAT32_C( -910.83));
  e = simde_mm256_set_ps(SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET,
                         SIMDE_F32_ALL_SET, SIMDE_F32_ALL_SET);
  r = simde_mm256_cmp_ps(a, b, 31);
  simde_assert_m256i_equal(simde_mm256_castps_si256(r), simde_mm256_castps_si256(e));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi32_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C( 1957018358), INT32_C( 1074174472), INT32_C(  124397699), INT32_C( 1881644266)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(1957018358.00), SIMDE_FLOAT64_C(1074174472.00),
                         SIMDE_FLOAT64_C(124397699.00), SIMDE_FLOAT64_C(1881644266.00)) },
    { simde_mm_set_epi32(INT32_C( 2070107316), INT32_C( 1618653378), INT32_C( 1002292861), INT32_C( 2002977375)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(2070107316.00), SIMDE_FLOAT64_C(1618653378.00),
                         SIMDE_FLOAT64_C(1002292861.00), SIMDE_FLOAT64_C(2002977375.00)) },
    { simde_mm_set_epi32(INT32_C( 2031655643), INT32_C( 1380169755), INT32_C( 1722613954), INT32_C(  223100421)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(2031655643.00), SIMDE_FLOAT64_C(1380169755.00),
                         SIMDE_FLOAT64_C(1722613954.00), SIMDE_FLOAT64_C(223100421.00)) },
    { simde_mm_set_epi32(INT32_C(-1894427767), INT32_C(-1633274427), INT32_C(-2058387969), INT32_C(-1311515394)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1894427767.00), SIMDE_FLOAT64_C(-1633274427.00),
                         SIMDE_FLOAT64_C(-2058387969.00), SIMDE_FLOAT64_C(-1311515394.00)) },
    { simde_mm_set_epi32(INT32_C(-1443374135), INT32_C( 1382394218), INT32_C( 1459905767), INT32_C( -756048058)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1443374135.00), SIMDE_FLOAT64_C(1382394218.00),
                         SIMDE_FLOAT64_C(1459905767.00), SIMDE_FLOAT64_C(-756048058.00)) },
    { simde_mm_set_epi32(INT32_C( -781596301), INT32_C( 1840524706), INT32_C( 1502138952), INT32_C(-2118210723)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-781596301.00), SIMDE_FLOAT64_C(1840524706.00),
                         SIMDE_FLOAT64_C(1502138952.00), SIMDE_FLOAT64_C(-2118210723.00)) },
    { simde_mm_set_epi32(INT32_C(   52250967), INT32_C( 1988701031), INT32_C( 1592626424), INT32_C(-1778387557)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(52250967.00), SIMDE_FLOAT64_C(1988701031.00),
                         SIMDE_FLOAT64_C(1592626424.00), SIMDE_FLOAT64_C(-1778387557.00)) },
    { simde_mm_set_epi32(INT32_C(   30979646), INT32_C(  769206580), INT32_C(-2128276240), INT32_C( 1445709709)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(30979646.00), SIMDE_FLOAT64_C(769206580.00),
                         SIMDE_FLOAT64_C(-2128276240.00), SIMDE_FLOAT64_C(1445709709.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cvtepi32_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtepi32_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(      -6033), INT32_C(      15813), INT32_C(      12979), INT32_C(     -31712),
                            INT32_C(      18002), INT32_C(      -6019), INT32_C(     -26810), INT32_C(      14091)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-6033.00), SIMDE_FLOAT32_C(15813.00),
                         SIMDE_FLOAT32_C(12979.00), SIMDE_FLOAT32_C(-31712.00),
                         SIMDE_FLOAT32_C(18002.00), SIMDE_FLOAT32_C(-6019.00),
                         SIMDE_FLOAT32_C(-26810.00), SIMDE_FLOAT32_C(14091.00)) },
    { simde_mm256_set_epi32(INT32_C(       6359), INT32_C(       7786), INT32_C(      21856), INT32_C(     -20706),
                            INT32_C(     -20652), INT32_C(      21040), INT32_C(      -8561), INT32_C(     -12779)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 6359.00), SIMDE_FLOAT32_C( 7786.00),
                         SIMDE_FLOAT32_C(21856.00), SIMDE_FLOAT32_C(-20706.00),
                         SIMDE_FLOAT32_C(-20652.00), SIMDE_FLOAT32_C(21040.00),
                         SIMDE_FLOAT32_C(-8561.00), SIMDE_FLOAT32_C(-12779.00)) },
    { simde_mm256_set_epi32(INT32_C(     -28477), INT32_C(     -21667), INT32_C(     -16892), INT32_C(     -16024),
                            INT32_C(     -11576), INT32_C(        602), INT32_C(      23902), INT32_C(      17547)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-28477.00), SIMDE_FLOAT32_C(-21667.00),
                         SIMDE_FLOAT32_C(-16892.00), SIMDE_FLOAT32_C(-16024.00),
                         SIMDE_FLOAT32_C(-11576.00), SIMDE_FLOAT32_C(  602.00),
                         SIMDE_FLOAT32_C(23902.00), SIMDE_FLOAT32_C(17547.00)) },
    { simde_mm256_set_epi32(INT32_C(       8732), INT32_C(      13948), INT32_C(       7489), INT32_C(      25724),
                            INT32_C(      24561), INT32_C(      11189), INT32_C(      24773), INT32_C(      -8467)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 8732.00), SIMDE_FLOAT32_C(13948.00),
                         SIMDE_FLOAT32_C( 7489.00), SIMDE_FLOAT32_C(25724.00),
                         SIMDE_FLOAT32_C(24561.00), SIMDE_FLOAT32_C(11189.00),
                         SIMDE_FLOAT32_C(24773.00), SIMDE_FLOAT32_C(-8467.00)) },
    { simde_mm256_set_epi32(INT32_C(     -31943), INT32_C(      26870), INT32_C(     -22515), INT32_C(       3030),
                            INT32_C(      24358), INT32_C(      31924), INT32_C(      30771), INT32_C(       4777)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-31943.00), SIMDE_FLOAT32_C(26870.00),
                         SIMDE_FLOAT32_C(-22515.00), SIMDE_FLOAT32_C( 3030.00),
                         SIMDE_FLOAT32_C(24358.00), SIMDE_FLOAT32_C(31924.00),
                         SIMDE_FLOAT32_C(30771.00), SIMDE_FLOAT32_C( 4777.00)) },
    { simde_mm256_set_epi32(INT32_C(      -1809), INT32_C(     -14404), INT32_C(     -32286), INT32_C(      25399),
                            INT32_C(      29260), INT32_C(     -23412), INT32_C(      12480), INT32_C(     -23461)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1809.00), SIMDE_FLOAT32_C(-14404.00),
                         SIMDE_FLOAT32_C(-32286.00), SIMDE_FLOAT32_C(25399.00),
                         SIMDE_FLOAT32_C(29260.00), SIMDE_FLOAT32_C(-23412.00),
                         SIMDE_FLOAT32_C(12480.00), SIMDE_FLOAT32_C(-23461.00)) },
    { simde_mm256_set_epi32(INT32_C(      -2274), INT32_C(      23698), INT32_C(       4976), INT32_C(      13398),
                            INT32_C(      -8046), INT32_C(     -16937), INT32_C(      19340), INT32_C(      -6656)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-2274.00), SIMDE_FLOAT32_C(23698.00),
                         SIMDE_FLOAT32_C( 4976.00), SIMDE_FLOAT32_C(13398.00),
                         SIMDE_FLOAT32_C(-8046.00), SIMDE_FLOAT32_C(-16937.00),
                         SIMDE_FLOAT32_C(19340.00), SIMDE_FLOAT32_C(-6656.00)) },
    { simde_mm256_set_epi32(INT32_C(     -29605), INT32_C(       8888), INT32_C(      -8347), INT32_C(      -8890),
                            INT32_C(      -8372), INT32_C(       7334), INT32_C(      14947), INT32_C(      -5546)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-29605.00), SIMDE_FLOAT32_C( 8888.00),
                         SIMDE_FLOAT32_C(-8347.00), SIMDE_FLOAT32_C(-8890.00),
                         SIMDE_FLOAT32_C(-8372.00), SIMDE_FLOAT32_C( 7334.00),
                         SIMDE_FLOAT32_C(14947.00), SIMDE_FLOAT32_C(-5546.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_cvtepi32_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  823.92), SIMDE_FLOAT64_C( -252.31),
                         SIMDE_FLOAT64_C(  311.42), SIMDE_FLOAT64_C(  639.08)),
      simde_mm_set_epi32(INT32_C( 824), INT32_C(-252), INT32_C( 311), INT32_C( 639)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  311.89), SIMDE_FLOAT64_C( -507.25),
                         SIMDE_FLOAT64_C(  748.64), SIMDE_FLOAT64_C( -488.86)),
      simde_mm_set_epi32(INT32_C( 312), INT32_C(-507), INT32_C( 749), INT32_C(-489)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  478.57), SIMDE_FLOAT64_C( -328.29),
                         SIMDE_FLOAT64_C( -289.22), SIMDE_FLOAT64_C( -586.95)),
      simde_mm_set_epi32(INT32_C( 479), INT32_C(-328), INT32_C(-289), INT32_C(-587)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  341.08), SIMDE_FLOAT64_C(  432.49),
                         SIMDE_FLOAT64_C(  835.07), SIMDE_FLOAT64_C( -889.53)),
      simde_mm_set_epi32(INT32_C( 341), INT32_C( 432), INT32_C( 835), INT32_C(-890)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -811.21), SIMDE_FLOAT64_C( -487.29),
                         SIMDE_FLOAT64_C(  852.90), SIMDE_FLOAT64_C(  970.07)),
      simde_mm_set_epi32(INT32_C(-811), INT32_C(-487), INT32_C( 853), INT32_C( 970)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  456.79), SIMDE_FLOAT64_C( -836.64),
                         SIMDE_FLOAT64_C( -396.53), SIMDE_FLOAT64_C(  788.69)),
      simde_mm_set_epi32(INT32_C( 457), INT32_C(-837), INT32_C(-397), INT32_C( 789)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  538.31), SIMDE_FLOAT64_C(  630.62),
                         SIMDE_FLOAT64_C( -811.65), SIMDE_FLOAT64_C( -175.08)),
      simde_mm_set_epi32(INT32_C( 538), INT32_C( 631), INT32_C(-812), INT32_C(-175)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -53.87), SIMDE_FLOAT64_C(  -83.11),
                         SIMDE_FLOAT64_C( -288.58), SIMDE_FLOAT64_C( -287.98)),
      simde_mm_set_epi32(INT32_C( -54), INT32_C( -83), INT32_C(-289), INT32_C(-288)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvtpd_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtpd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  375.90), SIMDE_FLOAT64_C( -889.76),
                         SIMDE_FLOAT64_C( -974.31), SIMDE_FLOAT64_C(  373.58)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  375.90), SIMDE_FLOAT32_C( -889.76), SIMDE_FLOAT32_C( -974.31), SIMDE_FLOAT32_C(  373.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   84.47), SIMDE_FLOAT64_C(  744.53),
                         SIMDE_FLOAT64_C(  -27.43), SIMDE_FLOAT64_C(  -51.38)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   84.47), SIMDE_FLOAT32_C(  744.53), SIMDE_FLOAT32_C(  -27.43), SIMDE_FLOAT32_C(  -51.38)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   66.02), SIMDE_FLOAT64_C( -438.12),
                         SIMDE_FLOAT64_C(  408.44), SIMDE_FLOAT64_C(  197.54)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   66.02), SIMDE_FLOAT32_C( -438.12), SIMDE_FLOAT32_C(  408.44), SIMDE_FLOAT32_C(  197.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.23), SIMDE_FLOAT64_C(  910.03),
                         SIMDE_FLOAT64_C(  928.38), SIMDE_FLOAT64_C(  305.66)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   80.23), SIMDE_FLOAT32_C(  910.03), SIMDE_FLOAT32_C(  928.38), SIMDE_FLOAT32_C(  305.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -511.50), SIMDE_FLOAT64_C( -503.26),
                         SIMDE_FLOAT64_C( -164.88), SIMDE_FLOAT64_C(  -10.16)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -511.50), SIMDE_FLOAT32_C( -503.26), SIMDE_FLOAT32_C( -164.88), SIMDE_FLOAT32_C(  -10.16)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   99.85), SIMDE_FLOAT64_C( -538.53),
                         SIMDE_FLOAT64_C(   17.38), SIMDE_FLOAT64_C( -161.67)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   99.85), SIMDE_FLOAT32_C( -538.53), SIMDE_FLOAT32_C(   17.38), SIMDE_FLOAT32_C( -161.67)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  891.01), SIMDE_FLOAT64_C(  865.63),
                         SIMDE_FLOAT64_C(  -39.82), SIMDE_FLOAT64_C( -446.03)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  891.01), SIMDE_FLOAT32_C(  865.63), SIMDE_FLOAT32_C(  -39.82), SIMDE_FLOAT32_C( -446.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  394.04), SIMDE_FLOAT64_C(  238.42),
                         SIMDE_FLOAT64_C(  746.10), SIMDE_FLOAT64_C(   -8.70)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  394.04), SIMDE_FLOAT32_C(  238.42), SIMDE_FLOAT32_C(  746.10), SIMDE_FLOAT32_C(   -8.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm256_cvtpd_ps(test_vec[i].a);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  598.58), SIMDE_FLOAT32_C(  571.41),
                         SIMDE_FLOAT32_C( -242.37), SIMDE_FLOAT32_C( -717.41),
                         SIMDE_FLOAT32_C(  374.26), SIMDE_FLOAT32_C( -165.53),
                         SIMDE_FLOAT32_C( -357.04), SIMDE_FLOAT32_C( -622.88)),
      simde_mm256_set_epi32(INT32_C( 599), INT32_C( 571), INT32_C(-242), INT32_C(-717),
                            INT32_C( 374), INT32_C(-166), INT32_C(-357), INT32_C(-623)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  257.81), SIMDE_FLOAT32_C( -837.70),
                         SIMDE_FLOAT32_C(  261.48), SIMDE_FLOAT32_C(  542.96),
                         SIMDE_FLOAT32_C(  769.60), SIMDE_FLOAT32_C( -711.96),
                         SIMDE_FLOAT32_C( -326.97), SIMDE_FLOAT32_C( -113.31)),
      simde_mm256_set_epi32(INT32_C( 258), INT32_C(-838), INT32_C( 261), INT32_C( 543),
                            INT32_C( 770), INT32_C(-712), INT32_C(-327), INT32_C(-113)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -569.57), SIMDE_FLOAT32_C(  423.37),
                         SIMDE_FLOAT32_C(  -24.31), SIMDE_FLOAT32_C(  934.89),
                         SIMDE_FLOAT32_C(  421.98), SIMDE_FLOAT32_C(  514.39),
                         SIMDE_FLOAT32_C(  548.83), SIMDE_FLOAT32_C(  419.70)),
      simde_mm256_set_epi32(INT32_C(-570), INT32_C( 423), INT32_C( -24), INT32_C( 935),
                            INT32_C( 422), INT32_C( 514), INT32_C( 549), INT32_C( 420)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -391.60), SIMDE_FLOAT32_C( -565.59),
                         SIMDE_FLOAT32_C(  -30.37), SIMDE_FLOAT32_C( -335.58),
                         SIMDE_FLOAT32_C(  613.59), SIMDE_FLOAT32_C( -997.50),
                         SIMDE_FLOAT32_C( -875.20), SIMDE_FLOAT32_C(   61.16)),
      simde_mm256_set_epi32(INT32_C(-392), INT32_C(-566), INT32_C( -30), INT32_C(-336),
                            INT32_C( 614), INT32_C(-998), INT32_C(-875), INT32_C(  61)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -166.04), SIMDE_FLOAT32_C( -427.79),
                         SIMDE_FLOAT32_C(  609.54), SIMDE_FLOAT32_C( -532.28),
                         SIMDE_FLOAT32_C( -681.53), SIMDE_FLOAT32_C(  504.43),
                         SIMDE_FLOAT32_C( -888.34), SIMDE_FLOAT32_C(  403.18)),
      simde_mm256_set_epi32(INT32_C(-166), INT32_C(-428), INT32_C( 610), INT32_C(-532),
                            INT32_C(-682), INT32_C( 504), INT32_C(-888), INT32_C( 403)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  216.04), SIMDE_FLOAT32_C( -927.91),
                         SIMDE_FLOAT32_C(  780.38), SIMDE_FLOAT32_C(  765.71),
                         SIMDE_FLOAT32_C( -447.72), SIMDE_FLOAT32_C(  -65.81),
                         SIMDE_FLOAT32_C(  716.35), SIMDE_FLOAT32_C(  608.15)),
      simde_mm256_set_epi32(INT32_C( 216), INT32_C(-928), INT32_C( 780), INT32_C( 766),
                            INT32_C(-448), INT32_C( -66), INT32_C( 716), INT32_C( 608)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.27), SIMDE_FLOAT32_C( -611.58),
                         SIMDE_FLOAT32_C( -361.36), SIMDE_FLOAT32_C( -851.00),
                         SIMDE_FLOAT32_C(  839.99), SIMDE_FLOAT32_C(  207.87),
                         SIMDE_FLOAT32_C( -947.82), SIMDE_FLOAT32_C( -403.90)),
      simde_mm256_set_epi32(INT32_C( 971), INT32_C(-612), INT32_C(-361), INT32_C(-851),
                            INT32_C( 840), INT32_C( 208), INT32_C(-948), INT32_C(-404)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -507.54), SIMDE_FLOAT32_C(  581.68),
                         SIMDE_FLOAT32_C( -590.23), SIMDE_FLOAT32_C(  417.30),
                         SIMDE_FLOAT32_C(  -87.52), SIMDE_FLOAT32_C( -865.50),
                         SIMDE_FLOAT32_C(  940.51), SIMDE_FLOAT32_C(  910.77)),
      simde_mm256_set_epi32(INT32_C(-508), INT32_C( 582), INT32_C(-590), INT32_C( 417),
                            INT32_C( -88), INT32_C(-866), INT32_C( 941), INT32_C( 911)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvtps_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvtps_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  846.20), SIMDE_FLOAT32_C(  685.37), SIMDE_FLOAT32_C(  660.41), SIMDE_FLOAT32_C( -309.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  846.20), SIMDE_FLOAT64_C(  685.37),
                         SIMDE_FLOAT64_C(  660.41), SIMDE_FLOAT64_C( -309.12)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  900.54), SIMDE_FLOAT32_C(  555.77), SIMDE_FLOAT32_C( -412.48), SIMDE_FLOAT32_C( -684.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  900.54), SIMDE_FLOAT64_C(  555.77),
                         SIMDE_FLOAT64_C( -412.48), SIMDE_FLOAT64_C( -684.76)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -530.00), SIMDE_FLOAT32_C(  516.66), SIMDE_FLOAT32_C(  969.93), SIMDE_FLOAT32_C( -956.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -530.00), SIMDE_FLOAT64_C(  516.66),
                         SIMDE_FLOAT64_C(  969.93), SIMDE_FLOAT64_C( -956.57)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  876.84), SIMDE_FLOAT32_C(  972.29), SIMDE_FLOAT32_C(  715.44), SIMDE_FLOAT32_C(  -66.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  876.84), SIMDE_FLOAT64_C(  972.29),
                         SIMDE_FLOAT64_C(  715.44), SIMDE_FLOAT64_C(  -66.38)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -684.20), SIMDE_FLOAT32_C( -317.33), SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C(  992.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -684.20), SIMDE_FLOAT64_C( -317.33),
                         SIMDE_FLOAT64_C(   88.04), SIMDE_FLOAT64_C(  992.34)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  481.41), SIMDE_FLOAT32_C( -117.39), SIMDE_FLOAT32_C(  583.52), SIMDE_FLOAT32_C(  373.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  481.41), SIMDE_FLOAT64_C( -117.39),
                         SIMDE_FLOAT64_C(  583.52), SIMDE_FLOAT64_C(  373.09)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  798.14), SIMDE_FLOAT32_C(  486.93), SIMDE_FLOAT32_C( -832.59), SIMDE_FLOAT32_C(  796.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  798.14), SIMDE_FLOAT64_C(  486.93),
                         SIMDE_FLOAT64_C( -832.59), SIMDE_FLOAT64_C(  796.43)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   75.03), SIMDE_FLOAT32_C(  634.86), SIMDE_FLOAT32_C(  319.54), SIMDE_FLOAT32_C( -801.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   75.03), SIMDE_FLOAT64_C(  634.86),
                         SIMDE_FLOAT64_C(  319.54), SIMDE_FLOAT64_C( -801.15)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_cvtps_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvttpd_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128i r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -175.82), SIMDE_FLOAT64_C(  -91.19),
                         SIMDE_FLOAT64_C( -855.64), SIMDE_FLOAT64_C(-1000.00)),
      simde_mm_set_epi32(INT32_C(-175), INT32_C( -91), INT32_C(-855), INT32_C(-1000)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  296.54), SIMDE_FLOAT64_C(  312.22),
                         SIMDE_FLOAT64_C( -648.31), SIMDE_FLOAT64_C(  586.65)),
      simde_mm_set_epi32(INT32_C( 296), INT32_C( 312), INT32_C(-648), INT32_C( 586)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  502.08), SIMDE_FLOAT64_C( -904.00),
                         SIMDE_FLOAT64_C(  802.10), SIMDE_FLOAT64_C(  616.09)),
      simde_mm_set_epi32(INT32_C( 502), INT32_C(-904), INT32_C( 802), INT32_C( 616)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  808.28), SIMDE_FLOAT64_C( -212.29),
                         SIMDE_FLOAT64_C(   75.93), SIMDE_FLOAT64_C( -979.81)),
      simde_mm_set_epi32(INT32_C( 808), INT32_C(-212), INT32_C(  75), INT32_C(-979)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -426.54), SIMDE_FLOAT64_C(  577.52),
                         SIMDE_FLOAT64_C(  966.87), SIMDE_FLOAT64_C(  162.81)),
      simde_mm_set_epi32(INT32_C(-426), INT32_C( 577), INT32_C( 966), INT32_C( 162)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -50.83), SIMDE_FLOAT64_C(  928.40),
                         SIMDE_FLOAT64_C(  392.36), SIMDE_FLOAT64_C(  469.60)),
      simde_mm_set_epi32(INT32_C( -50), INT32_C( 928), INT32_C( 392), INT32_C( 469)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  701.55), SIMDE_FLOAT64_C( -334.03),
                         SIMDE_FLOAT64_C(  803.63), SIMDE_FLOAT64_C(  -68.22)),
      simde_mm_set_epi32(INT32_C( 701), INT32_C(-334), INT32_C( 803), INT32_C( -68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -168.66), SIMDE_FLOAT64_C( -164.87),
                         SIMDE_FLOAT64_C(  824.77), SIMDE_FLOAT64_C( -834.37)),
      simde_mm_set_epi32(INT32_C(-168), INT32_C(-164), INT32_C( 824), INT32_C(-834)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i r = simde_mm256_cvttpd_epi32(test_vec[i].a);
    simde_assert_m128i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_cvttps_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -135.75), SIMDE_FLOAT32_C(  534.39),
                         SIMDE_FLOAT32_C(  -81.93), SIMDE_FLOAT32_C( -234.94),
                         SIMDE_FLOAT32_C( -390.94), SIMDE_FLOAT32_C( -625.05),
                         SIMDE_FLOAT32_C(  991.22), SIMDE_FLOAT32_C(  326.76)),
      simde_mm256_set_epi32(INT32_C(-135), INT32_C( 534), INT32_C( -81), INT32_C(-234),
                            INT32_C(-390), INT32_C(-625), INT32_C( 991), INT32_C( 326)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  864.35), SIMDE_FLOAT32_C(  855.52),
                         SIMDE_FLOAT32_C( -619.15), SIMDE_FLOAT32_C( -985.70),
                         SIMDE_FLOAT32_C( -511.44), SIMDE_FLOAT32_C(  327.81),
                         SIMDE_FLOAT32_C(   88.57), SIMDE_FLOAT32_C(  775.15)),
      simde_mm256_set_epi32(INT32_C( 864), INT32_C( 855), INT32_C(-619), INT32_C(-985),
                            INT32_C(-511), INT32_C( 327), INT32_C(  88), INT32_C( 775)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  464.19), SIMDE_FLOAT32_C( -184.66),
                         SIMDE_FLOAT32_C(  626.41), SIMDE_FLOAT32_C(  -54.43),
                         SIMDE_FLOAT32_C(  810.20), SIMDE_FLOAT32_C(  906.68),
                         SIMDE_FLOAT32_C(  -63.04), SIMDE_FLOAT32_C( -182.48)),
      simde_mm256_set_epi32(INT32_C( 464), INT32_C(-184), INT32_C( 626), INT32_C( -54),
                            INT32_C( 810), INT32_C( 906), INT32_C( -63), INT32_C(-182)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.49), SIMDE_FLOAT32_C( -473.91),
                         SIMDE_FLOAT32_C( -171.73), SIMDE_FLOAT32_C( -903.89),
                         SIMDE_FLOAT32_C(   73.85), SIMDE_FLOAT32_C( -545.98),
                         SIMDE_FLOAT32_C( -240.40), SIMDE_FLOAT32_C(  286.08)),
      simde_mm256_set_epi32(INT32_C( 127), INT32_C(-473), INT32_C(-171), INT32_C(-903),
                            INT32_C(  73), INT32_C(-545), INT32_C(-240), INT32_C( 286)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -184.43), SIMDE_FLOAT32_C(  171.84),
                         SIMDE_FLOAT32_C( -693.45), SIMDE_FLOAT32_C( -961.18),
                         SIMDE_FLOAT32_C( -527.37), SIMDE_FLOAT32_C(  565.38),
                         SIMDE_FLOAT32_C(  865.23), SIMDE_FLOAT32_C(  998.03)),
      simde_mm256_set_epi32(INT32_C(-184), INT32_C( 171), INT32_C(-693), INT32_C(-961),
                            INT32_C(-527), INT32_C( 565), INT32_C( 865), INT32_C( 998)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  417.68), SIMDE_FLOAT32_C(  795.88),
                         SIMDE_FLOAT32_C( -307.52), SIMDE_FLOAT32_C(   75.71),
                         SIMDE_FLOAT32_C( -179.42), SIMDE_FLOAT32_C( -352.61),
                         SIMDE_FLOAT32_C( -314.52), SIMDE_FLOAT32_C(  250.68)),
      simde_mm256_set_epi32(INT32_C( 417), INT32_C( 795), INT32_C(-307), INT32_C(  75),
                            INT32_C(-179), INT32_C(-352), INT32_C(-314), INT32_C( 250)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   89.37), SIMDE_FLOAT32_C( -634.21),
                         SIMDE_FLOAT32_C(  115.63), SIMDE_FLOAT32_C(  878.23),
                         SIMDE_FLOAT32_C( -321.46), SIMDE_FLOAT32_C(  524.08),
                         SIMDE_FLOAT32_C(  597.19), SIMDE_FLOAT32_C(  940.58)),
      simde_mm256_set_epi32(INT32_C(  89), INT32_C(-634), INT32_C( 115), INT32_C( 878),
                            INT32_C(-321), INT32_C( 524), INT32_C( 597), INT32_C( 940)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -643.91), SIMDE_FLOAT32_C(  102.13),
                         SIMDE_FLOAT32_C(  800.40), SIMDE_FLOAT32_C( -587.08),
                         SIMDE_FLOAT32_C( -734.61), SIMDE_FLOAT32_C(  772.26),
                         SIMDE_FLOAT32_C( -256.23), SIMDE_FLOAT32_C( -452.64)),
      simde_mm256_set_epi32(INT32_C(-643), INT32_C( 102), INT32_C( 800), INT32_C(-587),
                            INT32_C(-734), INT32_C( 772), INT32_C(-256), INT32_C(-452)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_cvttps_epi32(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  675.83), SIMDE_FLOAT32_C(  732.26),
                         SIMDE_FLOAT32_C(   -4.57), SIMDE_FLOAT32_C( -168.80),
                         SIMDE_FLOAT32_C( -520.00), SIMDE_FLOAT32_C( -692.17),
                         SIMDE_FLOAT32_C(  934.56), SIMDE_FLOAT32_C(  631.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -378.09), SIMDE_FLOAT32_C( -656.19),
                         SIMDE_FLOAT32_C( -265.99), SIMDE_FLOAT32_C( -457.08),
                         SIMDE_FLOAT32_C( -481.51), SIMDE_FLOAT32_C(  732.73),
                         SIMDE_FLOAT32_C(  321.36), SIMDE_FLOAT32_C( -269.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -1.79), SIMDE_FLOAT32_C(   -1.12),
                         SIMDE_FLOAT32_C(    0.02), SIMDE_FLOAT32_C(    0.37),
                         SIMDE_FLOAT32_C(    1.08), SIMDE_FLOAT32_C(   -0.94),
                         SIMDE_FLOAT32_C(    2.91), SIMDE_FLOAT32_C(   -2.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  118.79), SIMDE_FLOAT32_C(  887.62),
                         SIMDE_FLOAT32_C(  493.85), SIMDE_FLOAT32_C( -554.19),
                         SIMDE_FLOAT32_C(  954.00), SIMDE_FLOAT32_C( -438.20),
                         SIMDE_FLOAT32_C(  457.40), SIMDE_FLOAT32_C( -597.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  136.05), SIMDE_FLOAT32_C( -648.50),
                         SIMDE_FLOAT32_C(  975.99), SIMDE_FLOAT32_C(  125.14),
                         SIMDE_FLOAT32_C(  391.49), SIMDE_FLOAT32_C( -989.28),
                         SIMDE_FLOAT32_C( -980.53), SIMDE_FLOAT32_C(  107.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.87), SIMDE_FLOAT32_C(   -1.37),
                         SIMDE_FLOAT32_C(    0.51), SIMDE_FLOAT32_C(   -4.43),
                         SIMDE_FLOAT32_C(    2.44), SIMDE_FLOAT32_C(    0.44),
                         SIMDE_FLOAT32_C(   -0.47), SIMDE_FLOAT32_C(   -5.57)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  788.25), SIMDE_FLOAT32_C( -786.20),
                         SIMDE_FLOAT32_C( -386.26), SIMDE_FLOAT32_C( -761.33),
                         SIMDE_FLOAT32_C(  307.75), SIMDE_FLOAT32_C(  863.78),
                         SIMDE_FLOAT32_C(  634.25), SIMDE_FLOAT32_C(  687.96)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  593.79), SIMDE_FLOAT32_C( -856.02),
                         SIMDE_FLOAT32_C(  504.54), SIMDE_FLOAT32_C(  553.51),
                         SIMDE_FLOAT32_C(  287.73), SIMDE_FLOAT32_C( -351.53),
                         SIMDE_FLOAT32_C( -572.54), SIMDE_FLOAT32_C(  264.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    1.33), SIMDE_FLOAT32_C(    0.92),
                         SIMDE_FLOAT32_C(   -0.77), SIMDE_FLOAT32_C(   -1.38),
                         SIMDE_FLOAT32_C(    1.07), SIMDE_FLOAT32_C(   -2.46),
                         SIMDE_FLOAT32_C(   -1.11), SIMDE_FLOAT32_C(    2.60)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  139.28), SIMDE_FLOAT32_C(  906.17),
                         SIMDE_FLOAT32_C(  486.23), SIMDE_FLOAT32_C(  556.78),
                         SIMDE_FLOAT32_C( -178.50), SIMDE_FLOAT32_C( -222.99),
                         SIMDE_FLOAT32_C(  642.44), SIMDE_FLOAT32_C(  839.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.29), SIMDE_FLOAT32_C( -752.32),
                         SIMDE_FLOAT32_C( -335.75), SIMDE_FLOAT32_C( -704.13),
                         SIMDE_FLOAT32_C(  526.15), SIMDE_FLOAT32_C( -407.90),
                         SIMDE_FLOAT32_C(  -13.13), SIMDE_FLOAT32_C( -893.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.51), SIMDE_FLOAT32_C(   -1.20),
                         SIMDE_FLOAT32_C(   -1.45), SIMDE_FLOAT32_C(   -0.79),
                         SIMDE_FLOAT32_C(   -0.34), SIMDE_FLOAT32_C(    0.55),
                         SIMDE_FLOAT32_C(  -48.93), SIMDE_FLOAT32_C(   -0.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -332.01), SIMDE_FLOAT32_C( -279.46),
                         SIMDE_FLOAT32_C(  360.69), SIMDE_FLOAT32_C( -121.43),
                         SIMDE_FLOAT32_C(  819.79), SIMDE_FLOAT32_C(  512.44),
                         SIMDE_FLOAT32_C( -185.75), SIMDE_FLOAT32_C(  503.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  621.10), SIMDE_FLOAT32_C(  514.79),
                         SIMDE_FLOAT32_C( -672.95), SIMDE_FLOAT32_C(  -62.01),
                         SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C(  518.20),
                         SIMDE_FLOAT32_C( -704.10), SIMDE_FLOAT32_C( -249.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.53), SIMDE_FLOAT32_C(   -0.54),
                         SIMDE_FLOAT32_C(   -0.54), SIMDE_FLOAT32_C(    1.96),
                         SIMDE_FLOAT32_C(   -5.29), SIMDE_FLOAT32_C(    0.99),
                         SIMDE_FLOAT32_C(    0.26), SIMDE_FLOAT32_C(   -2.01)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -784.88), SIMDE_FLOAT32_C( -855.22),
                         SIMDE_FLOAT32_C( -347.04), SIMDE_FLOAT32_C( -241.02),
                         SIMDE_FLOAT32_C(  748.57), SIMDE_FLOAT32_C( -179.02),
                         SIMDE_FLOAT32_C( -995.77), SIMDE_FLOAT32_C( -927.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  868.43), SIMDE_FLOAT32_C(    9.90),
                         SIMDE_FLOAT32_C( -308.85), SIMDE_FLOAT32_C( -944.06),
                         SIMDE_FLOAT32_C( -323.62), SIMDE_FLOAT32_C(  739.02),
                         SIMDE_FLOAT32_C(  -61.38), SIMDE_FLOAT32_C(  426.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.90), SIMDE_FLOAT32_C(  -86.39),
                         SIMDE_FLOAT32_C(    1.12), SIMDE_FLOAT32_C(    0.26),
                         SIMDE_FLOAT32_C(   -2.31), SIMDE_FLOAT32_C(   -0.24),
                         SIMDE_FLOAT32_C(   16.22), SIMDE_FLOAT32_C(   -2.18)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  307.07), SIMDE_FLOAT32_C(  591.05),
                         SIMDE_FLOAT32_C( -630.36), SIMDE_FLOAT32_C(  826.28),
                         SIMDE_FLOAT32_C( -436.93), SIMDE_FLOAT32_C(  982.53),
                         SIMDE_FLOAT32_C( -808.08), SIMDE_FLOAT32_C(  630.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -339.08), SIMDE_FLOAT32_C( -235.71),
                         SIMDE_FLOAT32_C( -196.92), SIMDE_FLOAT32_C(   27.62),
                         SIMDE_FLOAT32_C( -443.69), SIMDE_FLOAT32_C(  242.35),
                         SIMDE_FLOAT32_C(  774.01), SIMDE_FLOAT32_C(  833.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.91), SIMDE_FLOAT32_C(   -2.51),
                         SIMDE_FLOAT32_C(    3.20), SIMDE_FLOAT32_C(   29.92),
                         SIMDE_FLOAT32_C(    0.98), SIMDE_FLOAT32_C(    4.05),
                         SIMDE_FLOAT32_C(   -1.04), SIMDE_FLOAT32_C(    0.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -830.19), SIMDE_FLOAT32_C( -620.56),
                         SIMDE_FLOAT32_C( -306.38), SIMDE_FLOAT32_C( -602.04),
                         SIMDE_FLOAT32_C(  183.46), SIMDE_FLOAT32_C(  824.79),
                         SIMDE_FLOAT32_C( -492.06), SIMDE_FLOAT32_C( -609.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -335.15), SIMDE_FLOAT32_C( -390.73),
                         SIMDE_FLOAT32_C(  951.40), SIMDE_FLOAT32_C(  398.19),
                         SIMDE_FLOAT32_C(  181.71), SIMDE_FLOAT32_C( -932.03),
                         SIMDE_FLOAT32_C(  887.77), SIMDE_FLOAT32_C(  257.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    2.48), SIMDE_FLOAT32_C(    1.59),
                         SIMDE_FLOAT32_C(   -0.32), SIMDE_FLOAT32_C(   -1.51),
                         SIMDE_FLOAT32_C(    1.01), SIMDE_FLOAT32_C(   -0.88),
                         SIMDE_FLOAT32_C(   -0.55), SIMDE_FLOAT32_C(   -2.37)) }
  };
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_div_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_div_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   42.76), SIMDE_FLOAT64_C(  925.42),
                         SIMDE_FLOAT64_C(  624.80), SIMDE_FLOAT64_C(  413.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -621.50), SIMDE_FLOAT64_C( -651.30),
                         SIMDE_FLOAT64_C( -233.59), SIMDE_FLOAT64_C( -713.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.07), SIMDE_FLOAT64_C(   -1.42),
                         SIMDE_FLOAT64_C(   -2.67), SIMDE_FLOAT64_C(   -0.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  275.93), SIMDE_FLOAT64_C(  360.88),
                         SIMDE_FLOAT64_C(   -7.47), SIMDE_FLOAT64_C( -347.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  479.86), SIMDE_FLOAT64_C(  205.26),
                         SIMDE_FLOAT64_C(  174.68), SIMDE_FLOAT64_C(  363.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.58), SIMDE_FLOAT64_C(    1.76),
                         SIMDE_FLOAT64_C(   -0.04), SIMDE_FLOAT64_C(   -0.96)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  977.82), SIMDE_FLOAT64_C(  875.25),
                         SIMDE_FLOAT64_C(  775.86), SIMDE_FLOAT64_C(  314.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -748.72), SIMDE_FLOAT64_C(  258.24),
                         SIMDE_FLOAT64_C( -578.49), SIMDE_FLOAT64_C( -708.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -1.31), SIMDE_FLOAT64_C(    3.39),
                         SIMDE_FLOAT64_C(   -1.34), SIMDE_FLOAT64_C(   -0.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  617.56), SIMDE_FLOAT64_C( -254.21),
                         SIMDE_FLOAT64_C( -890.06), SIMDE_FLOAT64_C( -996.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -247.08), SIMDE_FLOAT64_C(  661.94),
                         SIMDE_FLOAT64_C( -120.93), SIMDE_FLOAT64_C( -574.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.50), SIMDE_FLOAT64_C(   -0.38),
                         SIMDE_FLOAT64_C(    7.36), SIMDE_FLOAT64_C(    1.73)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -932.29), SIMDE_FLOAT64_C( -263.62),
                         SIMDE_FLOAT64_C( -571.69), SIMDE_FLOAT64_C(  -83.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  395.02), SIMDE_FLOAT64_C(  290.85),
                         SIMDE_FLOAT64_C( -853.00), SIMDE_FLOAT64_C(  928.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.36), SIMDE_FLOAT64_C(   -0.91),
                         SIMDE_FLOAT64_C(    0.67), SIMDE_FLOAT64_C(   -0.09)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.60), SIMDE_FLOAT64_C( -812.14),
                         SIMDE_FLOAT64_C( -474.36), SIMDE_FLOAT64_C( -732.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -982.62), SIMDE_FLOAT64_C( -995.34),
                         SIMDE_FLOAT64_C(  -51.94), SIMDE_FLOAT64_C(  973.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.11), SIMDE_FLOAT64_C(    0.82),
                         SIMDE_FLOAT64_C(    9.13), SIMDE_FLOAT64_C(   -0.75)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -826.31), SIMDE_FLOAT64_C( -333.99),
                         SIMDE_FLOAT64_C( -238.49), SIMDE_FLOAT64_C( -706.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  929.44), SIMDE_FLOAT64_C(  493.44),
                         SIMDE_FLOAT64_C( -539.23), SIMDE_FLOAT64_C( -683.88)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.89), SIMDE_FLOAT64_C(   -0.68),
                         SIMDE_FLOAT64_C(    0.44), SIMDE_FLOAT64_C(    1.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  419.98), SIMDE_FLOAT64_C(  -51.88),
                         SIMDE_FLOAT64_C( -580.15), SIMDE_FLOAT64_C( -198.88)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  246.03), SIMDE_FLOAT64_C( -149.94),
                         SIMDE_FLOAT64_C( -107.67), SIMDE_FLOAT64_C(  875.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    1.71), SIMDE_FLOAT64_C(    0.35),
                         SIMDE_FLOAT64_C(    5.39), SIMDE_FLOAT64_C(   -0.23)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_div_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_floor_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  520.72), SIMDE_FLOAT32_C(  834.16),
                         SIMDE_FLOAT32_C( -945.36), SIMDE_FLOAT32_C( -135.41),
                         SIMDE_FLOAT32_C(  289.19), SIMDE_FLOAT32_C(  462.54),
                         SIMDE_FLOAT32_C( -937.67), SIMDE_FLOAT32_C(  706.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  520.00), SIMDE_FLOAT32_C(  834.00),
                         SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -136.00),
                         SIMDE_FLOAT32_C(  289.00), SIMDE_FLOAT32_C(  462.00),
                         SIMDE_FLOAT32_C( -938.00), SIMDE_FLOAT32_C(  706.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.00), SIMDE_FLOAT32_C(  401.24),
                         SIMDE_FLOAT32_C(  899.70), SIMDE_FLOAT32_C( -258.03),
                         SIMDE_FLOAT32_C( -634.92), SIMDE_FLOAT32_C( -438.26),
                         SIMDE_FLOAT32_C(  433.94), SIMDE_FLOAT32_C( -170.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -9.00), SIMDE_FLOAT32_C(  401.00),
                         SIMDE_FLOAT32_C(  899.00), SIMDE_FLOAT32_C( -259.00),
                         SIMDE_FLOAT32_C( -635.00), SIMDE_FLOAT32_C( -439.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C( -171.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -908.95), SIMDE_FLOAT32_C( -376.33),
                         SIMDE_FLOAT32_C( -639.88), SIMDE_FLOAT32_C(   40.45),
                         SIMDE_FLOAT32_C( -431.46), SIMDE_FLOAT32_C( -404.49),
                         SIMDE_FLOAT32_C( -411.60), SIMDE_FLOAT32_C(  531.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -909.00), SIMDE_FLOAT32_C( -377.00),
                         SIMDE_FLOAT32_C( -640.00), SIMDE_FLOAT32_C(   40.00),
                         SIMDE_FLOAT32_C( -432.00), SIMDE_FLOAT32_C( -405.00),
                         SIMDE_FLOAT32_C( -412.00), SIMDE_FLOAT32_C(  531.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -394.79), SIMDE_FLOAT32_C( -654.48),
                         SIMDE_FLOAT32_C(  223.95), SIMDE_FLOAT32_C( -557.45),
                         SIMDE_FLOAT32_C(  908.61), SIMDE_FLOAT32_C( -493.34),
                         SIMDE_FLOAT32_C(  466.68), SIMDE_FLOAT32_C( -301.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -395.00), SIMDE_FLOAT32_C( -655.00),
                         SIMDE_FLOAT32_C(  223.00), SIMDE_FLOAT32_C( -558.00),
                         SIMDE_FLOAT32_C(  908.00), SIMDE_FLOAT32_C( -494.00),
                         SIMDE_FLOAT32_C(  466.00), SIMDE_FLOAT32_C( -302.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -5.40), SIMDE_FLOAT32_C(  828.84),
                         SIMDE_FLOAT32_C(  468.99), SIMDE_FLOAT32_C(  665.66),
                         SIMDE_FLOAT32_C( -648.14), SIMDE_FLOAT32_C( -841.90),
                         SIMDE_FLOAT32_C( -380.33), SIMDE_FLOAT32_C(  740.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -6.00), SIMDE_FLOAT32_C(  828.00),
                         SIMDE_FLOAT32_C(  468.00), SIMDE_FLOAT32_C(  665.00),
                         SIMDE_FLOAT32_C( -649.00), SIMDE_FLOAT32_C( -842.00),
                         SIMDE_FLOAT32_C( -381.00), SIMDE_FLOAT32_C(  740.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -752.16), SIMDE_FLOAT32_C( -655.98),
                         SIMDE_FLOAT32_C(  902.13), SIMDE_FLOAT32_C(  972.30),
                         SIMDE_FLOAT32_C( -497.57), SIMDE_FLOAT32_C( -530.16),
                         SIMDE_FLOAT32_C( -966.55), SIMDE_FLOAT32_C(  570.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -753.00), SIMDE_FLOAT32_C( -656.00),
                         SIMDE_FLOAT32_C(  902.00), SIMDE_FLOAT32_C(  972.00),
                         SIMDE_FLOAT32_C( -498.00), SIMDE_FLOAT32_C( -531.00),
                         SIMDE_FLOAT32_C( -967.00), SIMDE_FLOAT32_C(  570.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  723.18), SIMDE_FLOAT32_C(  202.51),
                         SIMDE_FLOAT32_C(  -41.39), SIMDE_FLOAT32_C( -372.98),
                         SIMDE_FLOAT32_C(  697.91), SIMDE_FLOAT32_C( -303.11),
                         SIMDE_FLOAT32_C( -180.07), SIMDE_FLOAT32_C(  941.44)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  723.00), SIMDE_FLOAT32_C(  202.00),
                         SIMDE_FLOAT32_C(  -42.00), SIMDE_FLOAT32_C( -373.00),
                         SIMDE_FLOAT32_C(  697.00), SIMDE_FLOAT32_C( -304.00),
                         SIMDE_FLOAT32_C( -181.00), SIMDE_FLOAT32_C(  941.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  995.24), SIMDE_FLOAT32_C(   68.12),
                         SIMDE_FLOAT32_C(  284.41), SIMDE_FLOAT32_C(  723.96),
                         SIMDE_FLOAT32_C( -373.95), SIMDE_FLOAT32_C(   15.43),
                         SIMDE_FLOAT32_C( -498.85), SIMDE_FLOAT32_C(  581.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  995.00), SIMDE_FLOAT32_C(   68.00),
                         SIMDE_FLOAT32_C(  284.00), SIMDE_FLOAT32_C(  723.00),
                         SIMDE_FLOAT32_C( -374.00), SIMDE_FLOAT32_C(   15.00),
                         SIMDE_FLOAT32_C( -499.00), SIMDE_FLOAT32_C(  581.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_floor_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extractf128_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m128d ra;
    simde__m128d rb;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  115.05), SIMDE_FLOAT64_C(  580.50),
                         SIMDE_FLOAT64_C(  784.61), SIMDE_FLOAT64_C(    6.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -748.60), SIMDE_FLOAT64_C(  328.25),
                         SIMDE_FLOAT64_C( -515.20), SIMDE_FLOAT64_C(  761.63)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  784.61), SIMDE_FLOAT64_C(    6.02)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -748.60), SIMDE_FLOAT64_C(  328.25)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -201.97), SIMDE_FLOAT64_C(  -32.82),
                         SIMDE_FLOAT64_C(  698.56), SIMDE_FLOAT64_C( -504.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -706.22), SIMDE_FLOAT64_C(  296.17),
                         SIMDE_FLOAT64_C(  289.51), SIMDE_FLOAT64_C( -515.71)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  698.56), SIMDE_FLOAT64_C( -504.23)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -706.22), SIMDE_FLOAT64_C(  296.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  708.15), SIMDE_FLOAT64_C( -171.50),
                         SIMDE_FLOAT64_C(  534.26), SIMDE_FLOAT64_C( -815.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C( -861.78),
                         SIMDE_FLOAT64_C(   -7.26), SIMDE_FLOAT64_C(  861.75)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  534.26), SIMDE_FLOAT64_C( -815.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -29.20), SIMDE_FLOAT64_C( -861.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  186.47), SIMDE_FLOAT64_C(  690.51),
                         SIMDE_FLOAT64_C( -956.51), SIMDE_FLOAT64_C(  679.80)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  327.68),
                         SIMDE_FLOAT64_C(  -42.45), SIMDE_FLOAT64_C(  443.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -956.51), SIMDE_FLOAT64_C(  679.80)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  790.70), SIMDE_FLOAT64_C(  327.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -320.95), SIMDE_FLOAT64_C(  190.95),
                         SIMDE_FLOAT64_C( -667.22), SIMDE_FLOAT64_C( -985.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -263.54), SIMDE_FLOAT64_C(  946.34),
                         SIMDE_FLOAT64_C(  395.23), SIMDE_FLOAT64_C(  318.77)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -667.22), SIMDE_FLOAT64_C( -985.92)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -263.54), SIMDE_FLOAT64_C(  946.34)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  258.92), SIMDE_FLOAT64_C( -434.64),
                         SIMDE_FLOAT64_C(  431.03), SIMDE_FLOAT64_C( -543.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   13.27), SIMDE_FLOAT64_C( -706.44),
                         SIMDE_FLOAT64_C(   14.64), SIMDE_FLOAT64_C( -663.76)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  431.03), SIMDE_FLOAT64_C( -543.52)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   13.27), SIMDE_FLOAT64_C( -706.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -867.30), SIMDE_FLOAT64_C(  693.24),
                         SIMDE_FLOAT64_C( -963.86), SIMDE_FLOAT64_C(   73.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -726.99), SIMDE_FLOAT64_C(  691.78),
                         SIMDE_FLOAT64_C(  411.83), SIMDE_FLOAT64_C(  204.72)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -963.86), SIMDE_FLOAT64_C(   73.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -726.99), SIMDE_FLOAT64_C(  691.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -771.52), SIMDE_FLOAT64_C( -673.29),
                         SIMDE_FLOAT64_C( -291.52), SIMDE_FLOAT64_C( -321.79)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  979.05), SIMDE_FLOAT64_C(  161.61),
                         SIMDE_FLOAT64_C(  682.54), SIMDE_FLOAT64_C(   63.94)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -291.52), SIMDE_FLOAT64_C( -321.79)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  979.05), SIMDE_FLOAT64_C(  161.61)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d ra = simde_mm256_extractf128_pd(test_vec[i].a, 0);
    simde__m128d rb = simde_mm256_extractf128_pd(test_vec[i].b, 1);
    simde_assert_m128d_equal(ra, test_vec[i].ra);
    simde_assert_m128d_equal(rb, test_vec[i].rb);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extractf128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m128 ra;
    simde__m128 rb;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -982.78), SIMDE_FLOAT32_C(  936.88),
                         SIMDE_FLOAT32_C(  412.85), SIMDE_FLOAT32_C( -941.25),
                         SIMDE_FLOAT32_C(  131.34), SIMDE_FLOAT32_C(  565.12),
                         SIMDE_FLOAT32_C( -716.42), SIMDE_FLOAT32_C( -825.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  850.34), SIMDE_FLOAT32_C( -992.50),
                         SIMDE_FLOAT32_C(  927.06), SIMDE_FLOAT32_C( -523.74),
                         SIMDE_FLOAT32_C( -670.83), SIMDE_FLOAT32_C(  805.14),
                         SIMDE_FLOAT32_C( -177.24), SIMDE_FLOAT32_C( -739.27)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  131.34), SIMDE_FLOAT32_C(  565.12), SIMDE_FLOAT32_C( -716.42), SIMDE_FLOAT32_C( -825.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -982.78), SIMDE_FLOAT32_C(  936.88), SIMDE_FLOAT32_C(  412.85), SIMDE_FLOAT32_C( -941.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -70.97), SIMDE_FLOAT32_C( -281.18),
                         SIMDE_FLOAT32_C(  775.52), SIMDE_FLOAT32_C( -398.03),
                         SIMDE_FLOAT32_C(  484.85), SIMDE_FLOAT32_C( -518.53),
                         SIMDE_FLOAT32_C( -204.80), SIMDE_FLOAT32_C( -550.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -638.16), SIMDE_FLOAT32_C(   -1.38),
                         SIMDE_FLOAT32_C( -998.42), SIMDE_FLOAT32_C(   63.00),
                         SIMDE_FLOAT32_C(  880.69), SIMDE_FLOAT32_C(  119.17),
                         SIMDE_FLOAT32_C(   35.15), SIMDE_FLOAT32_C( -586.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  484.85), SIMDE_FLOAT32_C( -518.53), SIMDE_FLOAT32_C( -204.80), SIMDE_FLOAT32_C( -550.46)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -70.97), SIMDE_FLOAT32_C( -281.18), SIMDE_FLOAT32_C(  775.52), SIMDE_FLOAT32_C( -398.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  899.55), SIMDE_FLOAT32_C(  996.09),
                         SIMDE_FLOAT32_C( -135.99), SIMDE_FLOAT32_C(  141.51),
                         SIMDE_FLOAT32_C(  -55.54), SIMDE_FLOAT32_C(  357.72),
                         SIMDE_FLOAT32_C( -706.21), SIMDE_FLOAT32_C(  310.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  434.09), SIMDE_FLOAT32_C(  834.83),
                         SIMDE_FLOAT32_C( -713.54), SIMDE_FLOAT32_C( -262.36),
                         SIMDE_FLOAT32_C(  332.23), SIMDE_FLOAT32_C(  176.07),
                         SIMDE_FLOAT32_C( -753.38), SIMDE_FLOAT32_C( -978.05)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -55.54), SIMDE_FLOAT32_C(  357.72), SIMDE_FLOAT32_C( -706.21), SIMDE_FLOAT32_C(  310.52)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  899.55), SIMDE_FLOAT32_C(  996.09), SIMDE_FLOAT32_C( -135.99), SIMDE_FLOAT32_C(  141.51)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  683.50), SIMDE_FLOAT32_C( -416.59),
                         SIMDE_FLOAT32_C(  629.11), SIMDE_FLOAT32_C(  891.79),
                         SIMDE_FLOAT32_C( -173.40), SIMDE_FLOAT32_C( -666.21),
                         SIMDE_FLOAT32_C( -628.67), SIMDE_FLOAT32_C(  605.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -779.97), SIMDE_FLOAT32_C(  302.06),
                         SIMDE_FLOAT32_C(  734.68), SIMDE_FLOAT32_C( -886.16),
                         SIMDE_FLOAT32_C(  707.40), SIMDE_FLOAT32_C(  833.35),
                         SIMDE_FLOAT32_C(  963.40), SIMDE_FLOAT32_C(  412.83)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -173.40), SIMDE_FLOAT32_C( -666.21), SIMDE_FLOAT32_C( -628.67), SIMDE_FLOAT32_C(  605.77)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  683.50), SIMDE_FLOAT32_C( -416.59), SIMDE_FLOAT32_C(  629.11), SIMDE_FLOAT32_C(  891.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -802.04), SIMDE_FLOAT32_C(  699.58),
                         SIMDE_FLOAT32_C(  450.94), SIMDE_FLOAT32_C( -386.39),
                         SIMDE_FLOAT32_C(  494.04), SIMDE_FLOAT32_C(  940.54),
                         SIMDE_FLOAT32_C( -934.60), SIMDE_FLOAT32_C( -970.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  648.13), SIMDE_FLOAT32_C(  946.05),
                         SIMDE_FLOAT32_C(  808.22), SIMDE_FLOAT32_C(  517.90),
                         SIMDE_FLOAT32_C( -691.53), SIMDE_FLOAT32_C(  525.44),
                         SIMDE_FLOAT32_C( -474.29), SIMDE_FLOAT32_C( -454.31)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  494.04), SIMDE_FLOAT32_C(  940.54), SIMDE_FLOAT32_C( -934.60), SIMDE_FLOAT32_C( -970.12)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -802.04), SIMDE_FLOAT32_C(  699.58), SIMDE_FLOAT32_C(  450.94), SIMDE_FLOAT32_C( -386.39)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -543.05), SIMDE_FLOAT32_C(  -31.72),
                         SIMDE_FLOAT32_C( -407.93), SIMDE_FLOAT32_C(  926.97),
                         SIMDE_FLOAT32_C(  179.76), SIMDE_FLOAT32_C(  712.03),
                         SIMDE_FLOAT32_C(  463.85), SIMDE_FLOAT32_C( -838.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  673.45), SIMDE_FLOAT32_C(  368.84),
                         SIMDE_FLOAT32_C(  678.61), SIMDE_FLOAT32_C(  857.34),
                         SIMDE_FLOAT32_C( -482.39), SIMDE_FLOAT32_C(  -94.31),
                         SIMDE_FLOAT32_C(  471.32), SIMDE_FLOAT32_C(  173.80)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  179.76), SIMDE_FLOAT32_C(  712.03), SIMDE_FLOAT32_C(  463.85), SIMDE_FLOAT32_C( -838.23)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -543.05), SIMDE_FLOAT32_C(  -31.72), SIMDE_FLOAT32_C( -407.93), SIMDE_FLOAT32_C(  926.97)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -929.66), SIMDE_FLOAT32_C( -223.82),
                         SIMDE_FLOAT32_C(  340.48), SIMDE_FLOAT32_C(  717.03),
                         SIMDE_FLOAT32_C(  895.13), SIMDE_FLOAT32_C(  964.64),
                         SIMDE_FLOAT32_C( -654.82), SIMDE_FLOAT32_C(   74.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  665.16), SIMDE_FLOAT32_C(  209.26),
                         SIMDE_FLOAT32_C(  133.64), SIMDE_FLOAT32_C(  -42.02),
                         SIMDE_FLOAT32_C( -424.16), SIMDE_FLOAT32_C( -122.50),
                         SIMDE_FLOAT32_C( -788.87), SIMDE_FLOAT32_C( -239.50)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  895.13), SIMDE_FLOAT32_C(  964.64), SIMDE_FLOAT32_C( -654.82), SIMDE_FLOAT32_C(   74.87)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -929.66), SIMDE_FLOAT32_C( -223.82), SIMDE_FLOAT32_C(  340.48), SIMDE_FLOAT32_C(  717.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  406.90), SIMDE_FLOAT32_C( -672.60),
                         SIMDE_FLOAT32_C(  803.83), SIMDE_FLOAT32_C( -409.89),
                         SIMDE_FLOAT32_C(  549.46), SIMDE_FLOAT32_C(  773.35),
                         SIMDE_FLOAT32_C( -173.87), SIMDE_FLOAT32_C(  365.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  381.05), SIMDE_FLOAT32_C( -236.95),
                         SIMDE_FLOAT32_C( -568.89), SIMDE_FLOAT32_C(  375.92),
                         SIMDE_FLOAT32_C(  259.53), SIMDE_FLOAT32_C( -247.84),
                         SIMDE_FLOAT32_C(  166.06), SIMDE_FLOAT32_C( -963.74)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  549.46), SIMDE_FLOAT32_C(  773.35), SIMDE_FLOAT32_C( -173.87), SIMDE_FLOAT32_C(  365.19)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  406.90), SIMDE_FLOAT32_C( -672.60), SIMDE_FLOAT32_C(  803.83), SIMDE_FLOAT32_C( -409.89)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 ra = simde_mm256_extractf128_ps(test_vec[i].a, 0);
    simde__m128 rb = simde_mm256_extractf128_ps(test_vec[i].a, 1);
    simde_assert_m128_close(ra, test_vec[i].ra, 1);
    simde_assert_m128_close(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extractf128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m128i ra;
    simde__m128i rb;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625),
                            INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm256_set_epi32(INT32_C( -867719772), INT32_C(-1804212438), INT32_C( 1849818353), INT32_C(  405560893),
                            INT32_C( 1351338386), INT32_C( -886724662), INT32_C( 1197680760), INT32_C( 1003042592)),
      simde_mm_set_epi32(INT32_C( 1795700153), INT32_C( -297324271), INT32_C( 1549329146), INT32_C( -534963225)),
      simde_mm_set_epi32(INT32_C( 1229394801), INT32_C(  992221618), INT32_C(-1388107406), INT32_C(  780445625)) },
    { simde_mm256_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984),
                            INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm256_set_epi32(INT32_C( 2021215895), INT32_C( -422044488), INT32_C(-1385706777), INT32_C(   22702781),
                            INT32_C( 1076807274), INT32_C(-1923875401), INT32_C( -554846936), INT32_C(-1008226174)),
      simde_mm_set_epi32(INT32_C(-1015866216), INT32_C( -556342867), INT32_C( -766379029), INT32_C( -130781639)),
      simde_mm_set_epi32(INT32_C( 1839397279), INT32_C( -585358334), INT32_C(  779178160), INT32_C( -362976984)) },
    { simde_mm256_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864),
                            INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm256_set_epi32(INT32_C( 2088662618), INT32_C(-1671363325), INT32_C( -997695043), INT32_C( -809764814),
                            INT32_C( 2092581708), INT32_C(-1073689737), INT32_C(-1556963227), INT32_C( -641330488)),
      simde_mm_set_epi32(INT32_C( -835154412), INT32_C( -431540196), INT32_C( -161564683), INT32_C(  204589457)),
      simde_mm_set_epi32(INT32_C(   23865749), INT32_C( -908972624), INT32_C(-1642418179), INT32_C(  111689864)) },
    { simde_mm256_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179),
                            INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm256_set_epi32(INT32_C(  -42175512), INT32_C(-2146588690), INT32_C(-1902868938), INT32_C( 1919945739),
                            INT32_C(  410749235), INT32_C(-1828962645), INT32_C(  525862553), INT32_C( -282512400)),
      simde_mm_set_epi32(INT32_C( 1343207861), INT32_C(-1541174422), INT32_C(-2097250480), INT32_C(-1382492089)),
      simde_mm_set_epi32(INT32_C( 1727711569), INT32_C(-1915329589), INT32_C( -979233658), INT32_C( -409203179)) },
    { simde_mm256_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622),
                            INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm256_set_epi32(INT32_C( 1481955155), INT32_C( -119794855), INT32_C(-2109995042), INT32_C(  582656481),
                            INT32_C( 1178951500), INT32_C(  762286037), INT32_C(  628377158), INT32_C( -188026020)),
      simde_mm_set_epi32(INT32_C( 1815109517), INT32_C( 1103735854), INT32_C( 1342116414), INT32_C( 1750949195)),
      simde_mm_set_epi32(INT32_C(  377369527), INT32_C( 1159197718), INT32_C(  288677560), INT32_C(  828517622)) },
    { simde_mm256_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145),
                            INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm256_set_epi32(INT32_C(-1510707643), INT32_C( 1988531398), INT32_C(-1182276921), INT32_C(  363503044),
                            INT32_C( 2086268932), INT32_C( -428647595), INT32_C( 1685321543), INT32_C( 1979089365)),
      simde_mm_set_epi32(INT32_C( -677093043), INT32_C( -527636644), INT32_C( 1238565466), INT32_C(-1592387355)),
      simde_mm_set_epi32(INT32_C(-1996051424), INT32_C( -314294760), INT32_C( -770521150), INT32_C(  508113145)) },
    { simde_mm256_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965),
                            INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm256_set_epi32(INT32_C( -575114102), INT32_C( -399786699), INT32_C(-1468780124), INT32_C( 2032090700),
                            INT32_C(  723386747), INT32_C(-1766232746), INT32_C(   73837413), INT32_C(  496540408)),
      simde_mm_set_epi32(INT32_C( -665786654), INT32_C(  663766301), INT32_C(-1237697897), INT32_C( -260948936)),
      simde_mm_set_epi32(INT32_C(    4593159), INT32_C( 1779671737), INT32_C( -569674634), INT32_C( -184254965)) },
    { simde_mm256_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432),
                            INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm256_set_epi32(INT32_C(-1815372819), INT32_C( -102535612), INT32_C(  115383384), INT32_C( 1004544095),
                            INT32_C( 1506420054), INT32_C(-1014523798), INT32_C(-1776388104), INT32_C( 1550371104)),
      simde_mm_set_epi32(INT32_C( 1903716614), INT32_C(-1951673698), INT32_C(-1858071379), INT32_C( 2070124471)),
      simde_mm_set_epi32(INT32_C( -328197013), INT32_C( 1036318270), INT32_C(-1930293157), INT32_C( 1948339432)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i ra = simde_mm256_extractf128_si256(test_vec[i].a, 0);
    simde__m128i rb = simde_mm256_extractf128_si256(test_vec[i].a, 1);
    simde_assert_m128i_i32(ra, ==, test_vec[i].ra);
    simde_assert_m128i_i32(rb, ==, test_vec[i].rb);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_floor_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -86.60), SIMDE_FLOAT64_C(  -29.62),
                         SIMDE_FLOAT64_C(  880.65), SIMDE_FLOAT64_C(  474.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -87.00), SIMDE_FLOAT64_C(  -30.00),
                         SIMDE_FLOAT64_C(  880.00), SIMDE_FLOAT64_C(  474.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  335.44), SIMDE_FLOAT64_C(   87.17),
                         SIMDE_FLOAT64_C(  264.70), SIMDE_FLOAT64_C(  435.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  335.00), SIMDE_FLOAT64_C(   87.00),
                         SIMDE_FLOAT64_C(  264.00), SIMDE_FLOAT64_C(  435.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  657.73), SIMDE_FLOAT64_C( -255.01),
                         SIMDE_FLOAT64_C( -236.61), SIMDE_FLOAT64_C(  198.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  657.00), SIMDE_FLOAT64_C( -256.00),
                         SIMDE_FLOAT64_C( -237.00), SIMDE_FLOAT64_C(  198.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -459.75), SIMDE_FLOAT64_C(  234.86),
                         SIMDE_FLOAT64_C( -517.66), SIMDE_FLOAT64_C( -561.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -460.00), SIMDE_FLOAT64_C(  234.00),
                         SIMDE_FLOAT64_C( -518.00), SIMDE_FLOAT64_C( -562.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -815.90), SIMDE_FLOAT64_C( -973.26),
                         SIMDE_FLOAT64_C( -704.97), SIMDE_FLOAT64_C(  629.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -816.00), SIMDE_FLOAT64_C( -974.00),
                         SIMDE_FLOAT64_C( -705.00), SIMDE_FLOAT64_C(  629.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -147.09), SIMDE_FLOAT64_C( -283.85),
                         SIMDE_FLOAT64_C(   91.60), SIMDE_FLOAT64_C( -808.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -148.00), SIMDE_FLOAT64_C( -284.00),
                         SIMDE_FLOAT64_C(   91.00), SIMDE_FLOAT64_C( -809.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  346.15), SIMDE_FLOAT64_C( -862.92),
                         SIMDE_FLOAT64_C( -616.19), SIMDE_FLOAT64_C( -434.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  346.00), SIMDE_FLOAT64_C( -863.00),
                         SIMDE_FLOAT64_C( -617.00), SIMDE_FLOAT64_C( -435.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -593.06), SIMDE_FLOAT64_C( -286.08),
                         SIMDE_FLOAT64_C(  351.32), SIMDE_FLOAT64_C(  -29.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -594.00), SIMDE_FLOAT64_C( -287.00),
                         SIMDE_FLOAT64_C(  351.00), SIMDE_FLOAT64_C(  -30.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_floor_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hadd_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -626.68), SIMDE_FLOAT32_C( -596.09),
                         SIMDE_FLOAT32_C( -988.19), SIMDE_FLOAT32_C(  961.65),
                         SIMDE_FLOAT32_C(  518.43), SIMDE_FLOAT32_C(  334.09),
                         SIMDE_FLOAT32_C(  212.95), SIMDE_FLOAT32_C( -488.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -361.77), SIMDE_FLOAT32_C(  121.01),
                         SIMDE_FLOAT32_C( -252.45), SIMDE_FLOAT32_C(  920.40),
                         SIMDE_FLOAT32_C( -660.15), SIMDE_FLOAT32_C( -869.23),
                         SIMDE_FLOAT32_C(  372.46), SIMDE_FLOAT32_C(  408.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -240.76), SIMDE_FLOAT32_C(  667.95),
                         SIMDE_FLOAT32_C(-1222.77), SIMDE_FLOAT32_C(  -26.54),
                         SIMDE_FLOAT32_C(-1529.38), SIMDE_FLOAT32_C(  781.12),
                         SIMDE_FLOAT32_C(  852.52), SIMDE_FLOAT32_C( -275.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  781.58), SIMDE_FLOAT32_C(  111.71),
                         SIMDE_FLOAT32_C( -214.03), SIMDE_FLOAT32_C( -280.14),
                         SIMDE_FLOAT32_C(  285.11), SIMDE_FLOAT32_C( -159.71),
                         SIMDE_FLOAT32_C(  737.74), SIMDE_FLOAT32_C(  159.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -542.95), SIMDE_FLOAT32_C(  311.99),
                         SIMDE_FLOAT32_C( -695.66), SIMDE_FLOAT32_C( -563.82),
                         SIMDE_FLOAT32_C( -378.07), SIMDE_FLOAT32_C(  160.57),
                         SIMDE_FLOAT32_C(  591.32), SIMDE_FLOAT32_C(  -15.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -230.96), SIMDE_FLOAT32_C(-1259.48),
                         SIMDE_FLOAT32_C(  893.29), SIMDE_FLOAT32_C( -494.17),
                         SIMDE_FLOAT32_C( -217.50), SIMDE_FLOAT32_C(  575.44),
                         SIMDE_FLOAT32_C(  125.40), SIMDE_FLOAT32_C(  896.80)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -397.87), SIMDE_FLOAT32_C(  582.70),
                         SIMDE_FLOAT32_C(  728.77), SIMDE_FLOAT32_C(  563.76),
                         SIMDE_FLOAT32_C( -874.44), SIMDE_FLOAT32_C( -323.73),
                         SIMDE_FLOAT32_C(  191.14), SIMDE_FLOAT32_C( -425.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  398.85), SIMDE_FLOAT32_C(  435.48),
                         SIMDE_FLOAT32_C( -736.85), SIMDE_FLOAT32_C( -251.61),
                         SIMDE_FLOAT32_C(  363.70), SIMDE_FLOAT32_C( -850.74),
                         SIMDE_FLOAT32_C(  513.62), SIMDE_FLOAT32_C(  893.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  834.33), SIMDE_FLOAT32_C( -988.46),
                         SIMDE_FLOAT32_C(  184.83), SIMDE_FLOAT32_C( 1292.53),
                         SIMDE_FLOAT32_C( -487.04), SIMDE_FLOAT32_C( 1406.85),
                         SIMDE_FLOAT32_C(-1198.17), SIMDE_FLOAT32_C( -234.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -659.61), SIMDE_FLOAT32_C( -996.22),
                         SIMDE_FLOAT32_C(  426.97), SIMDE_FLOAT32_C(   60.91),
                         SIMDE_FLOAT32_C(  175.17), SIMDE_FLOAT32_C(  226.61),
                         SIMDE_FLOAT32_C(  234.99), SIMDE_FLOAT32_C(  755.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -152.71), SIMDE_FLOAT32_C(  857.34),
                         SIMDE_FLOAT32_C(  403.84), SIMDE_FLOAT32_C( -862.22),
                         SIMDE_FLOAT32_C(  782.97), SIMDE_FLOAT32_C(  437.87),
                         SIMDE_FLOAT32_C(  825.47), SIMDE_FLOAT32_C(  915.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  704.63), SIMDE_FLOAT32_C( -458.38),
                         SIMDE_FLOAT32_C(-1655.83), SIMDE_FLOAT32_C(  487.88),
                         SIMDE_FLOAT32_C( 1220.84), SIMDE_FLOAT32_C( 1740.75),
                         SIMDE_FLOAT32_C(  401.78), SIMDE_FLOAT32_C(  990.37)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -564.13), SIMDE_FLOAT32_C( -973.32),
                         SIMDE_FLOAT32_C(  233.13), SIMDE_FLOAT32_C(  504.79),
                         SIMDE_FLOAT32_C(  857.55), SIMDE_FLOAT32_C(  275.11),
                         SIMDE_FLOAT32_C(  643.61), SIMDE_FLOAT32_C(  -70.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -709.38), SIMDE_FLOAT32_C(  310.06),
                         SIMDE_FLOAT32_C( -793.34), SIMDE_FLOAT32_C( -947.00),
                         SIMDE_FLOAT32_C( -974.52), SIMDE_FLOAT32_C(  878.25),
                         SIMDE_FLOAT32_C( -856.10), SIMDE_FLOAT32_C(  529.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -399.32), SIMDE_FLOAT32_C(-1740.34),
                         SIMDE_FLOAT32_C(-1537.45), SIMDE_FLOAT32_C(  737.92),
                         SIMDE_FLOAT32_C(  -96.27), SIMDE_FLOAT32_C( -327.06),
                         SIMDE_FLOAT32_C( 1132.66), SIMDE_FLOAT32_C(  573.49)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.99), SIMDE_FLOAT32_C( -737.47),
                         SIMDE_FLOAT32_C( -603.71), SIMDE_FLOAT32_C(  863.52),
                         SIMDE_FLOAT32_C( -639.50), SIMDE_FLOAT32_C(  474.16),
                         SIMDE_FLOAT32_C(  816.39), SIMDE_FLOAT32_C(   75.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  412.95), SIMDE_FLOAT32_C(  396.26),
                         SIMDE_FLOAT32_C(  519.43), SIMDE_FLOAT32_C( -413.53),
                         SIMDE_FLOAT32_C( -676.69), SIMDE_FLOAT32_C( -335.15),
                         SIMDE_FLOAT32_C(  961.37), SIMDE_FLOAT32_C(  820.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  809.21), SIMDE_FLOAT32_C(  105.90),
                         SIMDE_FLOAT32_C(   -3.48), SIMDE_FLOAT32_C(  259.81),
                         SIMDE_FLOAT32_C(-1011.84), SIMDE_FLOAT32_C( 1781.47),
                         SIMDE_FLOAT32_C( -165.34), SIMDE_FLOAT32_C(  891.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -149.16), SIMDE_FLOAT32_C( -430.29),
                         SIMDE_FLOAT32_C( -817.18), SIMDE_FLOAT32_C(  272.68),
                         SIMDE_FLOAT32_C( -899.55), SIMDE_FLOAT32_C( -654.95),
                         SIMDE_FLOAT32_C(  148.93), SIMDE_FLOAT32_C(  957.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -940.60), SIMDE_FLOAT32_C(  528.45),
                         SIMDE_FLOAT32_C(  574.67), SIMDE_FLOAT32_C(  993.90),
                         SIMDE_FLOAT32_C( -532.80), SIMDE_FLOAT32_C( -214.29),
                         SIMDE_FLOAT32_C( -506.86), SIMDE_FLOAT32_C(  389.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -412.15), SIMDE_FLOAT32_C( 1568.57),
                         SIMDE_FLOAT32_C( -579.45), SIMDE_FLOAT32_C( -544.50),
                         SIMDE_FLOAT32_C( -747.09), SIMDE_FLOAT32_C( -117.13),
                         SIMDE_FLOAT32_C(-1554.50), SIMDE_FLOAT32_C( 1105.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -426.98), SIMDE_FLOAT32_C(  653.68),
                         SIMDE_FLOAT32_C(  854.01), SIMDE_FLOAT32_C( -871.75),
                         SIMDE_FLOAT32_C(   60.41), SIMDE_FLOAT32_C(  197.76),
                         SIMDE_FLOAT32_C( -611.16), SIMDE_FLOAT32_C(  848.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  243.99), SIMDE_FLOAT32_C( -967.54),
                         SIMDE_FLOAT32_C(  893.59), SIMDE_FLOAT32_C( -630.65),
                         SIMDE_FLOAT32_C( -132.65), SIMDE_FLOAT32_C( -434.90),
                         SIMDE_FLOAT32_C( -516.97), SIMDE_FLOAT32_C(  151.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -723.55), SIMDE_FLOAT32_C(  262.94),
                         SIMDE_FLOAT32_C(  226.70), SIMDE_FLOAT32_C(  -17.74),
                         SIMDE_FLOAT32_C( -567.55), SIMDE_FLOAT32_C( -365.73),
                         SIMDE_FLOAT32_C(  258.17), SIMDE_FLOAT32_C(  237.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_hadd_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hadd_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -436.68), SIMDE_FLOAT64_C(  480.99),
                         SIMDE_FLOAT64_C( -278.34), SIMDE_FLOAT64_C(  588.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  130.14), SIMDE_FLOAT64_C( -927.67),
                         SIMDE_FLOAT64_C( -646.84), SIMDE_FLOAT64_C(  150.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -797.53), SIMDE_FLOAT64_C(   44.31),
                         SIMDE_FLOAT64_C( -495.90), SIMDE_FLOAT64_C(  310.55)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -433.18), SIMDE_FLOAT64_C(  708.48),
                         SIMDE_FLOAT64_C(  534.86), SIMDE_FLOAT64_C( -929.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  826.52), SIMDE_FLOAT64_C(   36.50),
                         SIMDE_FLOAT64_C(  561.99), SIMDE_FLOAT64_C( -293.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  863.02), SIMDE_FLOAT64_C(  275.30),
                         SIMDE_FLOAT64_C(  268.96), SIMDE_FLOAT64_C( -395.08)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  255.04), SIMDE_FLOAT64_C( -637.84),
                         SIMDE_FLOAT64_C( -513.11), SIMDE_FLOAT64_C( -599.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -910.36), SIMDE_FLOAT64_C( -799.15),
                         SIMDE_FLOAT64_C( -982.23), SIMDE_FLOAT64_C( -206.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1709.51), SIMDE_FLOAT64_C( -382.80),
                         SIMDE_FLOAT64_C(-1189.18), SIMDE_FLOAT64_C(-1112.94)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  149.87), SIMDE_FLOAT64_C(  274.56),
                         SIMDE_FLOAT64_C(  400.10), SIMDE_FLOAT64_C(  410.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  883.42), SIMDE_FLOAT64_C(   46.03),
                         SIMDE_FLOAT64_C( -600.38), SIMDE_FLOAT64_C(  131.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  929.45), SIMDE_FLOAT64_C(  424.43),
                         SIMDE_FLOAT64_C( -469.04), SIMDE_FLOAT64_C(  810.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -461.17), SIMDE_FLOAT64_C( -757.61),
                         SIMDE_FLOAT64_C( -114.45), SIMDE_FLOAT64_C(  853.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  397.09), SIMDE_FLOAT64_C( -444.66),
                         SIMDE_FLOAT64_C( -909.26), SIMDE_FLOAT64_C(  102.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -47.57), SIMDE_FLOAT64_C(-1218.78),
                         SIMDE_FLOAT64_C( -807.10), SIMDE_FLOAT64_C(  739.03)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -703.10), SIMDE_FLOAT64_C( -547.05),
                         SIMDE_FLOAT64_C( -158.62), SIMDE_FLOAT64_C( -256.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  137.64), SIMDE_FLOAT64_C( -342.68),
                         SIMDE_FLOAT64_C(  619.75), SIMDE_FLOAT64_C(  498.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.04), SIMDE_FLOAT64_C(-1250.15),
                         SIMDE_FLOAT64_C( 1117.79), SIMDE_FLOAT64_C( -415.32)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -818.29), SIMDE_FLOAT64_C(  196.32),
                         SIMDE_FLOAT64_C( -434.03), SIMDE_FLOAT64_C(   36.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -181.91), SIMDE_FLOAT64_C(  587.12),
                         SIMDE_FLOAT64_C( -318.37), SIMDE_FLOAT64_C(  -24.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  405.21), SIMDE_FLOAT64_C( -621.97),
                         SIMDE_FLOAT64_C( -342.50), SIMDE_FLOAT64_C( -397.85)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  129.06), SIMDE_FLOAT64_C( -240.83),
                         SIMDE_FLOAT64_C( -486.28), SIMDE_FLOAT64_C(  630.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  679.75), SIMDE_FLOAT64_C(  -37.94),
                         SIMDE_FLOAT64_C(  761.33), SIMDE_FLOAT64_C( -837.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  641.81), SIMDE_FLOAT64_C( -111.77),
                         SIMDE_FLOAT64_C(  -76.41), SIMDE_FLOAT64_C(  144.47)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_hadd_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hsub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -183.85), SIMDE_FLOAT32_C(  905.07),
                         SIMDE_FLOAT32_C( -962.47), SIMDE_FLOAT32_C(  739.25),
                         SIMDE_FLOAT32_C(   13.54), SIMDE_FLOAT32_C( -172.40),
                         SIMDE_FLOAT32_C(  456.21), SIMDE_FLOAT32_C(  164.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  959.87), SIMDE_FLOAT32_C(  500.02),
                         SIMDE_FLOAT32_C( -991.36), SIMDE_FLOAT32_C(  373.08),
                         SIMDE_FLOAT32_C( -962.56), SIMDE_FLOAT32_C( -502.91),
                         SIMDE_FLOAT32_C( -108.93), SIMDE_FLOAT32_C(  403.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -459.85), SIMDE_FLOAT32_C( 1364.44),
                         SIMDE_FLOAT32_C( 1088.92), SIMDE_FLOAT32_C( 1701.72),
                         SIMDE_FLOAT32_C(  459.65), SIMDE_FLOAT32_C(  512.30),
                         SIMDE_FLOAT32_C( -185.94), SIMDE_FLOAT32_C( -291.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  716.55), SIMDE_FLOAT32_C( -798.82),
                         SIMDE_FLOAT32_C(  -17.12), SIMDE_FLOAT32_C(  981.07),
                         SIMDE_FLOAT32_C( -241.05), SIMDE_FLOAT32_C(  266.35),
                         SIMDE_FLOAT32_C(  140.17), SIMDE_FLOAT32_C(  285.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  835.80), SIMDE_FLOAT32_C(  802.76),
                         SIMDE_FLOAT32_C( -745.28), SIMDE_FLOAT32_C( -228.38),
                         SIMDE_FLOAT32_C(  -44.09), SIMDE_FLOAT32_C(  991.15),
                         SIMDE_FLOAT32_C(  461.60), SIMDE_FLOAT32_C(   89.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.04), SIMDE_FLOAT32_C(  516.90),
                         SIMDE_FLOAT32_C(-1515.37), SIMDE_FLOAT32_C(  998.19),
                         SIMDE_FLOAT32_C( 1035.24), SIMDE_FLOAT32_C( -372.31),
                         SIMDE_FLOAT32_C(  507.40), SIMDE_FLOAT32_C(  145.69)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -323.55), SIMDE_FLOAT32_C( -835.05),
                         SIMDE_FLOAT32_C( -869.80), SIMDE_FLOAT32_C( -771.34),
                         SIMDE_FLOAT32_C( -342.71), SIMDE_FLOAT32_C(  374.92),
                         SIMDE_FLOAT32_C( -998.95), SIMDE_FLOAT32_C(   85.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -235.37), SIMDE_FLOAT32_C( -740.75),
                         SIMDE_FLOAT32_C(  568.96), SIMDE_FLOAT32_C(  984.74),
                         SIMDE_FLOAT32_C(  344.48), SIMDE_FLOAT32_C( -384.09),
                         SIMDE_FLOAT32_C( -746.69), SIMDE_FLOAT32_C(  666.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -505.38), SIMDE_FLOAT32_C(  415.78),
                         SIMDE_FLOAT32_C( -511.50), SIMDE_FLOAT32_C(   98.46),
                         SIMDE_FLOAT32_C( -728.57), SIMDE_FLOAT32_C( 1413.04),
                         SIMDE_FLOAT32_C(  717.63), SIMDE_FLOAT32_C( 1084.26)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  685.93), SIMDE_FLOAT32_C(  492.23),
                         SIMDE_FLOAT32_C(  668.17), SIMDE_FLOAT32_C( -421.85),
                         SIMDE_FLOAT32_C(  -93.75), SIMDE_FLOAT32_C( -819.96),
                         SIMDE_FLOAT32_C( -246.22), SIMDE_FLOAT32_C( -823.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  304.04), SIMDE_FLOAT32_C( -843.07),
                         SIMDE_FLOAT32_C( -204.07), SIMDE_FLOAT32_C( -879.53),
                         SIMDE_FLOAT32_C(  -83.04), SIMDE_FLOAT32_C( -516.58),
                         SIMDE_FLOAT32_C(  600.96), SIMDE_FLOAT32_C(   84.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1147.11), SIMDE_FLOAT32_C( -675.46),
                         SIMDE_FLOAT32_C( -193.70), SIMDE_FLOAT32_C(-1090.02),
                         SIMDE_FLOAT32_C( -433.54), SIMDE_FLOAT32_C( -516.83),
                         SIMDE_FLOAT32_C( -726.21), SIMDE_FLOAT32_C( -577.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  492.05), SIMDE_FLOAT32_C( -121.48),
                         SIMDE_FLOAT32_C(  197.17), SIMDE_FLOAT32_C(  108.83),
                         SIMDE_FLOAT32_C( -910.74), SIMDE_FLOAT32_C( -610.63),
                         SIMDE_FLOAT32_C( -510.98), SIMDE_FLOAT32_C(  996.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -210.55), SIMDE_FLOAT32_C(  321.75),
                         SIMDE_FLOAT32_C( -949.93), SIMDE_FLOAT32_C(  547.84),
                         SIMDE_FLOAT32_C(  133.08), SIMDE_FLOAT32_C( -303.40),
                         SIMDE_FLOAT32_C(   47.44), SIMDE_FLOAT32_C( -236.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  532.30), SIMDE_FLOAT32_C( 1497.77),
                         SIMDE_FLOAT32_C( -613.53), SIMDE_FLOAT32_C(  -88.34),
                         SIMDE_FLOAT32_C( -436.48), SIMDE_FLOAT32_C( -283.94),
                         SIMDE_FLOAT32_C(  300.11), SIMDE_FLOAT32_C( 1507.79)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.77), SIMDE_FLOAT32_C( -920.82),
                         SIMDE_FLOAT32_C( -807.55), SIMDE_FLOAT32_C(  138.87),
                         SIMDE_FLOAT32_C(   34.09), SIMDE_FLOAT32_C( -826.98),
                         SIMDE_FLOAT32_C( -567.48), SIMDE_FLOAT32_C(  943.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -46.97), SIMDE_FLOAT32_C(  474.05),
                         SIMDE_FLOAT32_C(  -64.19), SIMDE_FLOAT32_C( -945.80),
                         SIMDE_FLOAT32_C( -873.08), SIMDE_FLOAT32_C( -569.02),
                         SIMDE_FLOAT32_C( -630.19), SIMDE_FLOAT32_C( -681.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  521.02), SIMDE_FLOAT32_C( -881.61),
                         SIMDE_FLOAT32_C(-1125.59), SIMDE_FLOAT32_C(  946.42),
                         SIMDE_FLOAT32_C(  304.06), SIMDE_FLOAT32_C(  -51.49),
                         SIMDE_FLOAT32_C( -861.07), SIMDE_FLOAT32_C( 1511.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  470.38), SIMDE_FLOAT32_C( -693.79),
                         SIMDE_FLOAT32_C( -843.14), SIMDE_FLOAT32_C( -640.08),
                         SIMDE_FLOAT32_C(  950.30), SIMDE_FLOAT32_C(  582.04),
                         SIMDE_FLOAT32_C( -585.94), SIMDE_FLOAT32_C(  175.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   45.69), SIMDE_FLOAT32_C(   38.77),
                         SIMDE_FLOAT32_C(  194.04), SIMDE_FLOAT32_C(  410.12),
                         SIMDE_FLOAT32_C(  -28.08), SIMDE_FLOAT32_C( -596.23),
                         SIMDE_FLOAT32_C(  -38.68), SIMDE_FLOAT32_C( -731.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -6.92), SIMDE_FLOAT32_C(  216.08),
                         SIMDE_FLOAT32_C(-1164.17), SIMDE_FLOAT32_C(  203.06),
                         SIMDE_FLOAT32_C( -568.15), SIMDE_FLOAT32_C( -692.49),
                         SIMDE_FLOAT32_C( -368.26), SIMDE_FLOAT32_C(  761.63)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -171.77), SIMDE_FLOAT32_C( -878.69),
                         SIMDE_FLOAT32_C( -337.47), SIMDE_FLOAT32_C( -864.26),
                         SIMDE_FLOAT32_C(  976.73), SIMDE_FLOAT32_C(  253.08),
                         SIMDE_FLOAT32_C(  134.24), SIMDE_FLOAT32_C( -737.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  167.53), SIMDE_FLOAT32_C( -453.33),
                         SIMDE_FLOAT32_C(   11.70), SIMDE_FLOAT32_C(  471.07),
                         SIMDE_FLOAT32_C( -269.64), SIMDE_FLOAT32_C(  547.27),
                         SIMDE_FLOAT32_C( -313.69), SIMDE_FLOAT32_C( -333.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -620.86), SIMDE_FLOAT32_C(  459.37),
                         SIMDE_FLOAT32_C( -706.92), SIMDE_FLOAT32_C( -526.79),
                         SIMDE_FLOAT32_C(  816.91), SIMDE_FLOAT32_C(  -19.55),
                         SIMDE_FLOAT32_C( -723.65), SIMDE_FLOAT32_C( -872.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_hsub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_hsub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -762.69), SIMDE_FLOAT64_C(  237.58),
                         SIMDE_FLOAT64_C(  832.53), SIMDE_FLOAT64_C(  -18.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  974.95), SIMDE_FLOAT64_C(  -69.86),
                         SIMDE_FLOAT64_C(   78.29), SIMDE_FLOAT64_C( -156.35)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1044.81), SIMDE_FLOAT64_C( 1000.27),
                         SIMDE_FLOAT64_C( -234.64), SIMDE_FLOAT64_C( -850.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  220.65), SIMDE_FLOAT64_C( -139.75),
                         SIMDE_FLOAT64_C( -707.34), SIMDE_FLOAT64_C( -798.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  397.80), SIMDE_FLOAT64_C( -497.83),
                         SIMDE_FLOAT64_C(  717.31), SIMDE_FLOAT64_C( -807.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.63), SIMDE_FLOAT64_C( -360.40),
                         SIMDE_FLOAT64_C(-1525.03), SIMDE_FLOAT64_C(  -91.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  105.63), SIMDE_FLOAT64_C(  306.00),
                         SIMDE_FLOAT64_C(  281.00), SIMDE_FLOAT64_C(  310.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -325.57), SIMDE_FLOAT64_C(  534.52),
                         SIMDE_FLOAT64_C(  987.26), SIMDE_FLOAT64_C(  787.06)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  860.09), SIMDE_FLOAT64_C(  200.37),
                         SIMDE_FLOAT64_C( -200.20), SIMDE_FLOAT64_C(   29.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  967.71), SIMDE_FLOAT64_C( -641.51),
                         SIMDE_FLOAT64_C( -759.32), SIMDE_FLOAT64_C(  -97.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  348.76), SIMDE_FLOAT64_C( -255.68),
                         SIMDE_FLOAT64_C(  982.70), SIMDE_FLOAT64_C(  155.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -604.44), SIMDE_FLOAT64_C(-1609.22),
                         SIMDE_FLOAT64_C( -827.21), SIMDE_FLOAT64_C(  661.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  679.95), SIMDE_FLOAT64_C( -269.56),
                         SIMDE_FLOAT64_C( -481.42), SIMDE_FLOAT64_C(  919.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -2.64), SIMDE_FLOAT64_C(  468.75),
                         SIMDE_FLOAT64_C(  -36.44), SIMDE_FLOAT64_C(  441.73)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  471.39), SIMDE_FLOAT64_C( -949.51),
                         SIMDE_FLOAT64_C(  478.17), SIMDE_FLOAT64_C( 1400.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -496.34), SIMDE_FLOAT64_C(  144.53),
                         SIMDE_FLOAT64_C(   -0.78), SIMDE_FLOAT64_C(  -49.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  551.16), SIMDE_FLOAT64_C(    1.32),
                         SIMDE_FLOAT64_C( -388.16), SIMDE_FLOAT64_C(  219.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -549.84), SIMDE_FLOAT64_C(  640.87),
                         SIMDE_FLOAT64_C(  607.41), SIMDE_FLOAT64_C(  -48.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -33.11), SIMDE_FLOAT64_C( -186.08),
                         SIMDE_FLOAT64_C(  701.92), SIMDE_FLOAT64_C(   14.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   92.65), SIMDE_FLOAT64_C( -100.54),
                         SIMDE_FLOAT64_C( -271.34), SIMDE_FLOAT64_C(  -61.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -193.19), SIMDE_FLOAT64_C( -152.97),
                         SIMDE_FLOAT64_C(  210.20), SIMDE_FLOAT64_C( -687.66)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  116.05), SIMDE_FLOAT64_C( -582.94),
                         SIMDE_FLOAT64_C(   -9.93), SIMDE_FLOAT64_C( -395.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  109.95), SIMDE_FLOAT64_C( -493.57),
                         SIMDE_FLOAT64_C(  927.71), SIMDE_FLOAT64_C(   40.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -603.52), SIMDE_FLOAT64_C( -698.99),
                         SIMDE_FLOAT64_C( -887.50), SIMDE_FLOAT64_C( -385.58)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_hsub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_dp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -505.73), SIMDE_FLOAT32_C(   -137.42),
                         SIMDE_FLOAT32_C(     17.33), SIMDE_FLOAT32_C(    756.92),
                         SIMDE_FLOAT32_C(   -935.43), SIMDE_FLOAT32_C(    966.58),
                         SIMDE_FLOAT32_C(   -542.20), SIMDE_FLOAT32_C(   -986.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -727.11), SIMDE_FLOAT32_C(     41.36),
                         SIMDE_FLOAT32_C(   -966.84), SIMDE_FLOAT32_C(    -80.50),
                         SIMDE_FLOAT32_C(    623.90), SIMDE_FLOAT32_C(   -996.55),
                         SIMDE_FLOAT32_C(   -173.15), SIMDE_FLOAT32_C(   -230.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -16755.34), SIMDE_FLOAT32_C( -16755.34),
                         SIMDE_FLOAT32_C( -16755.34), SIMDE_FLOAT32_C( -16755.34),
                         SIMDE_FLOAT32_C(  93881.93), SIMDE_FLOAT32_C(  93881.93),
                         SIMDE_FLOAT32_C(  93881.93), SIMDE_FLOAT32_C(  93881.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    203.19), SIMDE_FLOAT32_C(   -301.86),
                         SIMDE_FLOAT32_C(   -510.29), SIMDE_FLOAT32_C(   -548.13),
                         SIMDE_FLOAT32_C(    769.15), SIMDE_FLOAT32_C(    758.71),
                         SIMDE_FLOAT32_C(    788.95), SIMDE_FLOAT32_C(   -308.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -93.30), SIMDE_FLOAT32_C(   -209.30),
                         SIMDE_FLOAT32_C(    125.32), SIMDE_FLOAT32_C(   -995.11),
                         SIMDE_FLOAT32_C(    443.92), SIMDE_FLOAT32_C(     15.16),
                         SIMDE_FLOAT32_C(    480.88), SIMDE_FLOAT32_C(   -179.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -63949.54), SIMDE_FLOAT32_C( -63949.54),
                         SIMDE_FLOAT32_C( -63949.54), SIMDE_FLOAT32_C( -63949.54),
                         SIMDE_FLOAT32_C( 379390.28), SIMDE_FLOAT32_C( 379390.28),
                         SIMDE_FLOAT32_C( 379390.28), SIMDE_FLOAT32_C( 379390.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -642.96), SIMDE_FLOAT32_C(    460.10),
                         SIMDE_FLOAT32_C(    365.68), SIMDE_FLOAT32_C(    149.19),
                         SIMDE_FLOAT32_C(   -863.16), SIMDE_FLOAT32_C(    539.13),
                         SIMDE_FLOAT32_C(    -10.06), SIMDE_FLOAT32_C(   -915.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -102.23), SIMDE_FLOAT32_C(     63.93),
                         SIMDE_FLOAT32_C(    220.16), SIMDE_FLOAT32_C(    -95.11),
                         SIMDE_FLOAT32_C(    920.74), SIMDE_FLOAT32_C(   -798.64),
                         SIMDE_FLOAT32_C(    549.26), SIMDE_FLOAT32_C(    150.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  80508.11), SIMDE_FLOAT32_C(  80508.11),
                         SIMDE_FLOAT32_C(  80508.11), SIMDE_FLOAT32_C(  80508.11),
                         SIMDE_FLOAT32_C(  -5525.56), SIMDE_FLOAT32_C(  -5525.56),
                         SIMDE_FLOAT32_C(  -5525.56), SIMDE_FLOAT32_C(  -5525.56)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -135.78), SIMDE_FLOAT32_C(   -796.33),
                         SIMDE_FLOAT32_C(   -449.54), SIMDE_FLOAT32_C(   -938.34),
                         SIMDE_FLOAT32_C(    393.31), SIMDE_FLOAT32_C(   -848.57),
                         SIMDE_FLOAT32_C(   -577.93), SIMDE_FLOAT32_C(   -905.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     36.84), SIMDE_FLOAT32_C(    187.09),
                         SIMDE_FLOAT32_C(   -980.80), SIMDE_FLOAT32_C(   -813.89),
                         SIMDE_FLOAT32_C(   -648.02), SIMDE_FLOAT32_C(     86.79),
                         SIMDE_FLOAT32_C(    527.03), SIMDE_FLOAT32_C(   -592.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 440908.84), SIMDE_FLOAT32_C( 440908.84),
                         SIMDE_FLOAT32_C( 440908.84), SIMDE_FLOAT32_C( 440908.84),
                         SIMDE_FLOAT32_C(-304586.47), SIMDE_FLOAT32_C(-304586.47),
                         SIMDE_FLOAT32_C(-304586.47), SIMDE_FLOAT32_C(-304586.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(     74.94), SIMDE_FLOAT32_C(    503.91),
                         SIMDE_FLOAT32_C(   -375.34), SIMDE_FLOAT32_C(   -743.13),
                         SIMDE_FLOAT32_C(    569.57), SIMDE_FLOAT32_C(    343.31),
                         SIMDE_FLOAT32_C(    -63.75), SIMDE_FLOAT32_C(   -543.95)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -655.40), SIMDE_FLOAT32_C(   -172.92),
                         SIMDE_FLOAT32_C(    342.45), SIMDE_FLOAT32_C(    357.80),
                         SIMDE_FLOAT32_C(    265.80), SIMDE_FLOAT32_C(   -306.65),
                         SIMDE_FLOAT32_C(      8.98), SIMDE_FLOAT32_C(    608.49)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-128535.19), SIMDE_FLOAT32_C(-128535.19),
                         SIMDE_FLOAT32_C(-128535.19), SIMDE_FLOAT32_C(-128535.19),
                         SIMDE_FLOAT32_C(   -572.47), SIMDE_FLOAT32_C(   -572.47),
                         SIMDE_FLOAT32_C(   -572.47), SIMDE_FLOAT32_C(   -572.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    691.92), SIMDE_FLOAT32_C(   -222.27),
                         SIMDE_FLOAT32_C(   -447.07), SIMDE_FLOAT32_C(    147.51),
                         SIMDE_FLOAT32_C(    537.10), SIMDE_FLOAT32_C(    171.81),
                         SIMDE_FLOAT32_C(    347.32), SIMDE_FLOAT32_C(   -960.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    144.97), SIMDE_FLOAT32_C(   -282.53),
                         SIMDE_FLOAT32_C(    612.87), SIMDE_FLOAT32_C(   -406.95),
                         SIMDE_FLOAT32_C(   -724.51), SIMDE_FLOAT32_C(   -908.13),
                         SIMDE_FLOAT32_C(    448.37), SIMDE_FLOAT32_C(   -713.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-273995.78), SIMDE_FLOAT32_C(-273995.78),
                         SIMDE_FLOAT32_C(-273995.78), SIMDE_FLOAT32_C(-273995.78),
                         SIMDE_FLOAT32_C( 155727.88), SIMDE_FLOAT32_C( 155727.88),
                         SIMDE_FLOAT32_C( 155727.88), SIMDE_FLOAT32_C( 155727.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -208.78), SIMDE_FLOAT32_C(    929.10),
                         SIMDE_FLOAT32_C(   -272.86), SIMDE_FLOAT32_C(     86.66),
                         SIMDE_FLOAT32_C(   -744.06), SIMDE_FLOAT32_C(   -881.86),
                         SIMDE_FLOAT32_C(   -663.16), SIMDE_FLOAT32_C(    193.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -31.12), SIMDE_FLOAT32_C(   -303.48),
                         SIMDE_FLOAT32_C(   -758.68), SIMDE_FLOAT32_C(    -57.97),
                         SIMDE_FLOAT32_C(    -16.19), SIMDE_FLOAT32_C(    187.47),
                         SIMDE_FLOAT32_C(     13.98), SIMDE_FLOAT32_C(    577.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 207013.41), SIMDE_FLOAT32_C( 207013.41),
                         SIMDE_FLOAT32_C( 207013.41), SIMDE_FLOAT32_C( 207013.41),
                         SIMDE_FLOAT32_C(  -9270.98), SIMDE_FLOAT32_C(  -9270.98),
                         SIMDE_FLOAT32_C(  -9270.98), SIMDE_FLOAT32_C(  -9270.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    696.37), SIMDE_FLOAT32_C(    300.52),
                         SIMDE_FLOAT32_C(   -476.62), SIMDE_FLOAT32_C(    523.01),
                         SIMDE_FLOAT32_C(   -147.94), SIMDE_FLOAT32_C(   -993.31),
                         SIMDE_FLOAT32_C(    910.70), SIMDE_FLOAT32_C(   -650.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -298.13), SIMDE_FLOAT32_C(   -528.10),
                         SIMDE_FLOAT32_C(    371.86), SIMDE_FLOAT32_C(    -93.70),
                         SIMDE_FLOAT32_C(   -396.01), SIMDE_FLOAT32_C(   -319.70),
                         SIMDE_FLOAT32_C(   -350.31), SIMDE_FLOAT32_C(   -580.49)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-177235.91), SIMDE_FLOAT32_C(-177235.91),
                         SIMDE_FLOAT32_C(-177235.91), SIMDE_FLOAT32_C(-177235.91),
                         SIMDE_FLOAT32_C(-319027.31), SIMDE_FLOAT32_C(-319027.31),
                         SIMDE_FLOAT32_C(-319027.31), SIMDE_FLOAT32_C(-319027.31)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_dp_ps(test_vec[i].a, test_vec[i].b, 47);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a;

  a = simde_mm256_set_epi32(INT32_C( 1385655883), INT32_C(-1710235670), INT32_C( 1840319559), INT32_C(   46971468),
                            INT32_C(  543693501), INT32_C( 1301344915), INT32_C( 1566637023), INT32_C( 2143093505));
  munit_assert_int32(simde_mm256_extract_epi32(a, 0), ==, INT32_C(2143093505));

  a = simde_mm256_set_epi32(INT32_C( -318872645), INT32_C(  154450085), INT32_C(  940983410), INT32_C(-2131037397),
                            INT32_C( 1379124831), INT32_C(  546028595), INT32_C(  -61508185), INT32_C( 1543937407));
  munit_assert_int32(simde_mm256_extract_epi32(a, 1), ==, INT32_C(-61508185));

  a = simde_mm256_set_epi32(INT32_C(-1821994577), INT32_C( 1502812176), INT32_C( -436334344), INT32_C( 2003643735),
                            INT32_C(-1707163842), INT32_C(-1393484615), INT32_C(-1517380673), INT32_C( -785551131));
  munit_assert_int32(simde_mm256_extract_epi32(a, 2), ==, INT32_C(-1393484615));

  a = simde_mm256_set_epi32(INT32_C(-1342559050), INT32_C( 1280753378), INT32_C(  519553994), INT32_C(  134336686),
                            INT32_C(-1696266450), INT32_C( 1521778870), INT32_C(-1336686564), INT32_C( -138601679));
  munit_assert_int32(simde_mm256_extract_epi32(a, 3), ==, INT32_C(-1696266450));

  a = simde_mm256_set_epi32(INT32_C( -346178226), INT32_C(-1487718780), INT32_C( 1522880003), INT32_C(  588601981),
                            INT32_C( 1931111095), INT32_C(-1466649812), INT32_C(-1669730912), INT32_C(  257973424));
  munit_assert_int32(simde_mm256_extract_epi32(a, 4), ==, INT32_C(588601981));

  a = simde_mm256_set_epi32(INT32_C(  564328837), INT32_C(  600105992), INT32_C(-1245299261), INT32_C(  186243465),
                            INT32_C( 1677067524), INT32_C( -306576008), INT32_C(-1101353897), INT32_C(  733243889));
  munit_assert_int32(simde_mm256_extract_epi32(a, 5), ==, INT32_C(-1245299261));

  a = simde_mm256_set_epi32(INT32_C( -460169306), INT32_C( -732910055), INT32_C(  973235428), INT32_C(  784780564),
                            INT32_C( -944171968), INT32_C(-1846057571), INT32_C( 1068840758), INT32_C(  786857160));
  munit_assert_int32(simde_mm256_extract_epi32(a, 6), ==, INT32_C(-732910055));

  a = simde_mm256_set_epi32(INT32_C( -541300758), INT32_C(-2119881925), INT32_C(-1597449913), INT32_C(  489702841),
                            INT32_C(-1364763213), INT32_C(  217047214), INT32_C( 1964050600), INT32_C(-1022338452));
  munit_assert_int32(simde_mm256_extract_epi32(a, 7), ==, INT32_C(-541300758));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_extract_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a;

  a = simde_mm256_set_epi64x(INT64_C(-4660489839809071463), INT64_C(-3275104097342830593),
                             INT64_C(-7646437287554588382), INT64_C(-1616723671742758177));
  munit_assert_int64(simde_mm256_extract_epi64(a, 0), ==, INT64_C(-1616723671742758177));

  a = simde_mm256_set_epi64x(INT64_C(-4654112182052362730), INT64_C( 4380015427737745916),
                             INT64_C(-2237548103057162518), INT64_C( -717271117564457282));
  munit_assert_int64(simde_mm256_extract_epi64(a, 1), ==, INT64_C(-2237548103057162518));

  a = simde_mm256_set_epi64x(INT64_C(-9053768942501696029), INT64_C(  -11082930357956064),
                             INT64_C( 4721540626264374149), INT64_C(-2904931686008463967));
  munit_assert_int64(simde_mm256_extract_epi64(a, 2), ==, INT64_C(  -11082930357956064));

  a = simde_mm256_set_epi64x(INT64_C(  952352888602265092), INT64_C(-6100868528376933823),
                             INT64_C(-6435628201550193122), INT64_C(-1473382845492258957));
  munit_assert_int64(simde_mm256_extract_epi64(a, 3), ==, INT64_C(  952352888602265092));

  a = simde_mm256_set_epi64x(INT64_C( 3571656271242113686), INT64_C(-4496934129483038288),
                             INT64_C(-1076704560171997551), INT64_C( 3873627956598886953));
  munit_assert_int64(simde_mm256_extract_epi64(a, 0), ==, INT64_C( 3873627956598886953));

  a = simde_mm256_set_epi64x(INT64_C( 4706661489617163532), INT64_C( 5127697303613520544),
                             INT64_C(-7455940824973292748), INT64_C(-7733027913451150656));
  munit_assert_int64(simde_mm256_extract_epi64(a, 1), ==, INT64_C(-7455940824973292748));

  a = simde_mm256_set_epi64x(INT64_C( 5538080490384191196), INT64_C( -631116641013180065),
                             INT64_C(-8091873078648501156), INT64_C(-6139846631858294273));
  munit_assert_int64(simde_mm256_extract_epi64(a, 2), ==, INT64_C( -631116641013180065));

  a = simde_mm256_set_epi64x(INT64_C(-5169157996131687226), INT64_C(-8345143279822783157),
                             INT64_C(   28110904629261106), INT64_C(-2611039926221160636));
  munit_assert_int64(simde_mm256_extract_epi64(a, 3), ==, INT64_C(-5169157996131687226));

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a, r, e;

  a = simde_mm256_set_epi8(INT8_C(   2), INT8_C(  84), INT8_C(   6), INT8_C( -83),
                           INT8_C( 118), INT8_C(  45), INT8_C(  46), INT8_C( -44),
                           INT8_C(-115), INT8_C( -99), INT8_C(  35), INT8_C(  32),
                           INT8_C( 111), INT8_C(  68), INT8_C( 103), INT8_C(   7),
                           INT8_C( -73), INT8_C(-111), INT8_C(-113), INT8_C(  29),
                           INT8_C(  25), INT8_C( 114), INT8_C(-122), INT8_C(  38),
                           INT8_C( -96), INT8_C( 114), INT8_C(  39), INT8_C(  74),
                           INT8_C(  99), INT8_C(  11), INT8_C(  76), INT8_C(  56));
  r = simde_mm256_insert_epi8(a, INT8_C(-3),  5);
  e = simde_mm256_set_epi8(INT8_C(   2), INT8_C(  84), INT8_C(   6), INT8_C( -83),
                           INT8_C( 118), INT8_C(  45), INT8_C(  46), INT8_C( -44),
                           INT8_C(-115), INT8_C( -99), INT8_C(  35), INT8_C(  32),
                           INT8_C( 111), INT8_C(  68), INT8_C( 103), INT8_C(   7),
                           INT8_C( -73), INT8_C(-111), INT8_C(-113), INT8_C(  29),
                           INT8_C(  25), INT8_C( 114), INT8_C(-122), INT8_C(  38),
                           INT8_C( -96), INT8_C( 114), INT8_C(  -3), INT8_C(  74),
                           INT8_C(  99), INT8_C(  11), INT8_C(  76), INT8_C(  56));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C(-119), INT8_C(-118), INT8_C(  60), INT8_C(  31),
                           INT8_C(-126), INT8_C( -54), INT8_C(  51), INT8_C(-114),
                           INT8_C(-128), INT8_C( -32), INT8_C(  25), INT8_C( 116),
                           INT8_C( 103), INT8_C( -83), INT8_C(  64), INT8_C(  29),
                           INT8_C( -50), INT8_C( -55), INT8_C( 114), INT8_C(  10),
                           INT8_C(  44), INT8_C(-111), INT8_C(-114), INT8_C( -60),
                           INT8_C(-128), INT8_C( -48), INT8_C(  15), INT8_C(  67),
                           INT8_C( -42), INT8_C( -49), INT8_C(  99), INT8_C( 114));
  r = simde_mm256_insert_epi8(a, INT8_C(59),  9);
  e = simde_mm256_set_epi8(INT8_C(-119), INT8_C(-118), INT8_C(  60), INT8_C(  31),
                           INT8_C(-126), INT8_C( -54), INT8_C(  51), INT8_C(-114),
                           INT8_C(-128), INT8_C( -32), INT8_C(  25), INT8_C( 116),
                           INT8_C( 103), INT8_C( -83), INT8_C(  64), INT8_C(  29),
                           INT8_C( -50), INT8_C( -55), INT8_C( 114), INT8_C(  10),
                           INT8_C(  44), INT8_C(-111), INT8_C(  59), INT8_C( -60),
                           INT8_C(-128), INT8_C( -48), INT8_C(  15), INT8_C(  67),
                           INT8_C( -42), INT8_C( -49), INT8_C(  99), INT8_C( 114));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C( -89), INT8_C(  90), INT8_C(-119), INT8_C( -38),
                           INT8_C( -50), INT8_C(  -6), INT8_C(-121), INT8_C( -93),
                           INT8_C(  88), INT8_C(  83), INT8_C( -93), INT8_C( -96),
                           INT8_C( -77), INT8_C( -84), INT8_C(-110), INT8_C( -16),
                           INT8_C( -67), INT8_C(  18), INT8_C(  25), INT8_C( -38),
                           INT8_C( -60), INT8_C(  59), INT8_C( 108), INT8_C( -22),
                           INT8_C(  39), INT8_C( 101), INT8_C(   5), INT8_C( 105),
                           INT8_C(  45), INT8_C( -43), INT8_C(  87), INT8_C(  73));
  r = simde_mm256_insert_epi8(a, INT8_C(-38),  6);
  e = simde_mm256_set_epi8(INT8_C( -89), INT8_C(  90), INT8_C(-119), INT8_C( -38),
                           INT8_C( -50), INT8_C(  -6), INT8_C(-121), INT8_C( -93),
                           INT8_C(  88), INT8_C(  83), INT8_C( -93), INT8_C( -96),
                           INT8_C( -77), INT8_C( -84), INT8_C(-110), INT8_C( -16),
                           INT8_C( -67), INT8_C(  18), INT8_C(  25), INT8_C( -38),
                           INT8_C( -60), INT8_C(  59), INT8_C( 108), INT8_C( -22),
                           INT8_C(  39), INT8_C( -38), INT8_C(   5), INT8_C( 105),
                           INT8_C(  45), INT8_C( -43), INT8_C(  87), INT8_C(  73));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C( 109), INT8_C(  -4), INT8_C(  42), INT8_C(  13),
                           INT8_C(  50), INT8_C(  75), INT8_C( 107), INT8_C(  56),
                           INT8_C(  48), INT8_C( -32), INT8_C(  -5), INT8_C( -89),
                           INT8_C(-120), INT8_C(  97), INT8_C(  24), INT8_C(  11),
                           INT8_C( -12), INT8_C( -17), INT8_C(  64), INT8_C(  44),
                           INT8_C(  42), INT8_C(  13), INT8_C(   7), INT8_C(  86),
                           INT8_C( -64), INT8_C(   9), INT8_C( -71), INT8_C( -23),
                           INT8_C(  74), INT8_C(  49), INT8_C( 126), INT8_C(  43));
  r = simde_mm256_insert_epi8(a, INT8_C(39), 10);
  e = simde_mm256_set_epi8(INT8_C( 109), INT8_C(  -4), INT8_C(  42), INT8_C(  13),
                           INT8_C(  50), INT8_C(  75), INT8_C( 107), INT8_C(  56),
                           INT8_C(  48), INT8_C( -32), INT8_C(  -5), INT8_C( -89),
                           INT8_C(-120), INT8_C(  97), INT8_C(  24), INT8_C(  11),
                           INT8_C( -12), INT8_C( -17), INT8_C(  64), INT8_C(  44),
                           INT8_C(  42), INT8_C(  39), INT8_C(   7), INT8_C(  86),
                           INT8_C( -64), INT8_C(   9), INT8_C( -71), INT8_C( -23),
                           INT8_C(  74), INT8_C(  49), INT8_C( 126), INT8_C(  43));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C(  19), INT8_C( -38), INT8_C(  78), INT8_C( -23),
                           INT8_C(  62), INT8_C( -68), INT8_C(-102), INT8_C(  63),
                           INT8_C( 124), INT8_C(-113), INT8_C( -21), INT8_C( 108),
                           INT8_C( -68), INT8_C( -75), INT8_C(  51), INT8_C( 124),
                           INT8_C(  76), INT8_C( -65), INT8_C( -80), INT8_C(  56),
                           INT8_C(  41), INT8_C(  59), INT8_C( 106), INT8_C(  -7),
                           INT8_C( -87), INT8_C(  20), INT8_C(   3), INT8_C( 106),
                           INT8_C(  72), INT8_C(-115), INT8_C(-103), INT8_C(  26));
  r = simde_mm256_insert_epi8(a, INT8_C(-114), 10);
  e = simde_mm256_set_epi8(INT8_C(  19), INT8_C( -38), INT8_C(  78), INT8_C( -23),
                           INT8_C(  62), INT8_C( -68), INT8_C(-102), INT8_C(  63),
                           INT8_C( 124), INT8_C(-113), INT8_C( -21), INT8_C( 108),
                           INT8_C( -68), INT8_C( -75), INT8_C(  51), INT8_C( 124),
                           INT8_C(  76), INT8_C( -65), INT8_C( -80), INT8_C(  56),
                           INT8_C(  41), INT8_C(-114), INT8_C( 106), INT8_C(  -7),
                           INT8_C( -87), INT8_C(  20), INT8_C(   3), INT8_C( 106),
                           INT8_C(  72), INT8_C(-115), INT8_C(-103), INT8_C(  26));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C( 124), INT8_C(  -4), INT8_C( -73), INT8_C( 108),
                           INT8_C(  66), INT8_C( -17), INT8_C(-121), INT8_C( 100),
                           INT8_C( 124), INT8_C( -94), INT8_C(  17), INT8_C( -78),
                           INT8_C( -99), INT8_C(  31), INT8_C(  28), INT8_C(   7),
                           INT8_C(-108), INT8_C( -43), INT8_C( -23), INT8_C( 104),
                           INT8_C( 122), INT8_C(  61), INT8_C( -93), INT8_C(-102),
                           INT8_C( 125), INT8_C( -79), INT8_C(  24), INT8_C(  49),
                           INT8_C(   9), INT8_C( -93), INT8_C(  36), INT8_C( -74));
  r = simde_mm256_insert_epi8(a, INT8_C(-65),  2);
  e = simde_mm256_set_epi8(INT8_C( 124), INT8_C(  -4), INT8_C( -73), INT8_C( 108),
                           INT8_C(  66), INT8_C( -17), INT8_C(-121), INT8_C( 100),
                           INT8_C( 124), INT8_C( -94), INT8_C(  17), INT8_C( -78),
                           INT8_C( -99), INT8_C(  31), INT8_C(  28), INT8_C(   7),
                           INT8_C(-108), INT8_C( -43), INT8_C( -23), INT8_C( 104),
                           INT8_C( 122), INT8_C(  61), INT8_C( -93), INT8_C(-102),
                           INT8_C( 125), INT8_C( -79), INT8_C(  24), INT8_C(  49),
                           INT8_C(   9), INT8_C( -65), INT8_C(  36), INT8_C( -74));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C(-100), INT8_C(  10), INT8_C(  87), INT8_C( -57),
                           INT8_C( -89), INT8_C( -66), INT8_C( -32), INT8_C( 104),
                           INT8_C(  66), INT8_C( -81), INT8_C( -94), INT8_C(  71),
                           INT8_C(  67), INT8_C( 108), INT8_C( -88), INT8_C(  53),
                           INT8_C( 108), INT8_C( -39), INT8_C( -93), INT8_C(  -2),
                           INT8_C(  93), INT8_C(  67), INT8_C( -85), INT8_C( -42),
                           INT8_C(  28), INT8_C( -64), INT8_C(  83), INT8_C(  -9),
                           INT8_C( -95), INT8_C(  36), INT8_C(  44), INT8_C( 112));
  r = simde_mm256_insert_epi8(a, INT8_C(58),  8);
  e = simde_mm256_set_epi8(INT8_C(-100), INT8_C(  10), INT8_C(  87), INT8_C( -57),
                           INT8_C( -89), INT8_C( -66), INT8_C( -32), INT8_C( 104),
                           INT8_C(  66), INT8_C( -81), INT8_C( -94), INT8_C(  71),
                           INT8_C(  67), INT8_C( 108), INT8_C( -88), INT8_C(  53),
                           INT8_C( 108), INT8_C( -39), INT8_C( -93), INT8_C(  -2),
                           INT8_C(  93), INT8_C(  67), INT8_C( -85), INT8_C(  58),
                           INT8_C(  28), INT8_C( -64), INT8_C(  83), INT8_C(  -9),
                           INT8_C( -95), INT8_C(  36), INT8_C(  44), INT8_C( 112));
  simde_assert_m256i_i8(r, ==, e);

  a = simde_mm256_set_epi8(INT8_C( -16), INT8_C( -47), INT8_C( -77), INT8_C(  42),
                           INT8_C(  89), INT8_C(  -7), INT8_C( -62), INT8_C(  45),
                           INT8_C( -28), INT8_C(  34), INT8_C( -59), INT8_C(  -9),
                           INT8_C( -38), INT8_C(-118), INT8_C(  83), INT8_C(  59),
                           INT8_C( -16), INT8_C(  34), INT8_C( -64), INT8_C(  16),
                           INT8_C( -15), INT8_C( -28), INT8_C(  47), INT8_C(  10),
                           INT8_C(-112), INT8_C( -37), INT8_C(  71), INT8_C( -84),
                           INT8_C( -78), INT8_C( -81), INT8_C(  40), INT8_C( -98));
  r = simde_mm256_insert_epi8(a, INT8_C(121),  7);
  e = simde_mm256_set_epi8(INT8_C( -16), INT8_C( -47), INT8_C( -77), INT8_C(  42),
                           INT8_C(  89), INT8_C(  -7), INT8_C( -62), INT8_C(  45),
                           INT8_C( -28), INT8_C(  34), INT8_C( -59), INT8_C(  -9),
                           INT8_C( -38), INT8_C(-118), INT8_C(  83), INT8_C(  59),
                           INT8_C( -16), INT8_C(  34), INT8_C( -64), INT8_C(  16),
                           INT8_C( -15), INT8_C( -28), INT8_C(  47), INT8_C(  10),
                           INT8_C( 121), INT8_C( -37), INT8_C(  71), INT8_C( -84),
                           INT8_C( -78), INT8_C( -81), INT8_C(  40), INT8_C( -98));
  simde_assert_m256i_i8(r, ==, e);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a, r, e;

  a = simde_mm256_set_epi16(INT16_C(-21602), INT16_C( 27671), INT16_C(-26514), INT16_C( 32139),
                            INT16_C( 27553), INT16_C(  3389), INT16_C( 26164), INT16_C(  3268),
                            INT16_C( -3948), INT16_C( 26700), INT16_C( 31313), INT16_C( 27327),
                            INT16_C(-25076), INT16_C( -6473), INT16_C(-27908), INT16_C(-18876));
  r = simde_mm256_insert_epi16(a, INT16_C(13157),  5);
  e = simde_mm256_set_epi16(INT16_C(-21602), INT16_C( 27671), INT16_C(-26514), INT16_C( 32139),
                            INT16_C( 27553), INT16_C(  3389), INT16_C( 26164), INT16_C(  3268),
                            INT16_C( -3948), INT16_C( 26700), INT16_C( 13157), INT16_C( 27327),
                            INT16_C(-25076), INT16_C( -6473), INT16_C(-27908), INT16_C(-18876));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C(-15739), INT16_C(-22477), INT16_C( 24105), INT16_C(  1501),
                            INT16_C(-14518), INT16_C( 18176), INT16_C( 14482), INT16_C( 20288),
                            INT16_C(-15586), INT16_C( 12200), INT16_C( -9527), INT16_C( -9462),
                            INT16_C(-20273), INT16_C(-22514), INT16_C(  1070), INT16_C(-15309));
  r = simde_mm256_insert_epi16(a, INT16_C(369),  3);
  e = simde_mm256_set_epi16(INT16_C(-15739), INT16_C(-22477), INT16_C( 24105), INT16_C(  1501),
                            INT16_C(-14518), INT16_C( 18176), INT16_C( 14482), INT16_C( 20288),
                            INT16_C(-15586), INT16_C( 12200), INT16_C( -9527), INT16_C( -9462),
                            INT16_C(   369), INT16_C(-22514), INT16_C(  1070), INT16_C(-15309));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C(-20578), INT16_C( 31339), INT16_C(-21867), INT16_C(  6148),
                            INT16_C(-32342), INT16_C(-12751), INT16_C(-22422), INT16_C( 12556),
                            INT16_C(-31526), INT16_C(-24860), INT16_C( 25156), INT16_C( -4916),
                            INT16_C(-20990), INT16_C(-13542), INT16_C(-25587), INT16_C(-20477));
  r = simde_mm256_insert_epi16(a, INT16_C(-32428),  1);
  e = simde_mm256_set_epi16(INT16_C(-20578), INT16_C( 31339), INT16_C(-21867), INT16_C(  6148),
                            INT16_C(-32342), INT16_C(-12751), INT16_C(-22422), INT16_C( 12556),
                            INT16_C(-31526), INT16_C(-24860), INT16_C( 25156), INT16_C( -4916),
                            INT16_C(-20990), INT16_C(-13542), INT16_C(-32428), INT16_C(-20477));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C( 16682), INT16_C(  9974), INT16_C( -6779), INT16_C(  1747),
                            INT16_C(-26827), INT16_C(-32182), INT16_C( 17867), INT16_C(-23355),
                            INT16_C( 15404), INT16_C( -2091), INT16_C(  -560), INT16_C(-24442),
                            INT16_C( 12274), INT16_C(-19942), INT16_C(  8401), INT16_C(-15722));
  r = simde_mm256_insert_epi16(a, INT16_C(16950), 12);
  e = simde_mm256_set_epi16(INT16_C( 16682), INT16_C(  9974), INT16_C( -6779), INT16_C( 16950),
                            INT16_C(-26827), INT16_C(-32182), INT16_C( 17867), INT16_C(-23355),
                            INT16_C( 15404), INT16_C( -2091), INT16_C(  -560), INT16_C(-24442),
                            INT16_C( 12274), INT16_C(-19942), INT16_C(  8401), INT16_C(-15722));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C( 31205), INT16_C( 25676), INT16_C(  7342), INT16_C(  4880),
                            INT16_C( -8533), INT16_C(-32080), INT16_C( -7595), INT16_C(-22500),
                            INT16_C(-10840), INT16_C( 19996), INT16_C( -4449), INT16_C(-31416),
                            INT16_C(-26476), INT16_C( -3822), INT16_C( 13156), INT16_C(-26200));
  r = simde_mm256_insert_epi16(a, INT16_C(27229), 15);
  e = simde_mm256_set_epi16(INT16_C( 27229), INT16_C( 25676), INT16_C(  7342), INT16_C(  4880),
                            INT16_C( -8533), INT16_C(-32080), INT16_C( -7595), INT16_C(-22500),
                            INT16_C(-10840), INT16_C( 19996), INT16_C( -4449), INT16_C(-31416),
                            INT16_C(-26476), INT16_C( -3822), INT16_C( 13156), INT16_C(-26200));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C( -8749), INT16_C(-27202), INT16_C(-11704), INT16_C(    52),
                            INT16_C(-10454), INT16_C( -3314), INT16_C( -8238), INT16_C(-18856),
                            INT16_C(  6163), INT16_C(-27363), INT16_C(  1816), INT16_C(-31045),
                            INT16_C( 28943), INT16_C(-22635), INT16_C(  1291), INT16_C(-31630));
  r = simde_mm256_insert_epi16(a, INT16_C(25149),  9);
  e = simde_mm256_set_epi16(INT16_C( -8749), INT16_C(-27202), INT16_C(-11704), INT16_C(    52),
                            INT16_C(-10454), INT16_C( -3314), INT16_C( 25149), INT16_C(-18856),
                            INT16_C(  6163), INT16_C(-27363), INT16_C(  1816), INT16_C(-31045),
                            INT16_C( 28943), INT16_C(-22635), INT16_C(  1291), INT16_C(-31630));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C( -5789), INT16_C( 32645), INT16_C(-25474), INT16_C( -6052),
                            INT16_C( 30501), INT16_C( 13572), INT16_C( 32362), INT16_C( 31220),
                            INT16_C( 21812), INT16_C( 21730), INT16_C(-10684), INT16_C(-29591),
                            INT16_C( 23321), INT16_C(  4014), INT16_C( 18929), INT16_C(  -646));
  r = simde_mm256_insert_epi16(a, INT16_C(10486), 11);
  e = simde_mm256_set_epi16(INT16_C( -5789), INT16_C( 32645), INT16_C(-25474), INT16_C( -6052),
                            INT16_C( 10486), INT16_C( 13572), INT16_C( 32362), INT16_C( 31220),
                            INT16_C( 21812), INT16_C( 21730), INT16_C(-10684), INT16_C(-29591),
                            INT16_C( 23321), INT16_C(  4014), INT16_C( 18929), INT16_C(  -646));
  simde_assert_m256i_i16(r, ==, e);

  a = simde_mm256_set_epi16(INT16_C( -2271), INT16_C(  8016), INT16_C( 26327), INT16_C( 27397),
                            INT16_C( 19036), INT16_C( 25193), INT16_C(-11253), INT16_C(-15734),
                            INT16_C(  -521), INT16_C( 20581), INT16_C(-18434), INT16_C(  4365),
                            INT16_C(-18143), INT16_C( 23566), INT16_C(-32412), INT16_C(-20606));
  r = simde_mm256_insert_epi16(a, INT16_C(4940),  6);
  e = simde_mm256_set_epi16(INT16_C( -2271), INT16_C(  8016), INT16_C( 26327), INT16_C( 27397),
                            INT16_C( 19036), INT16_C( 25193), INT16_C(-11253), INT16_C(-15734),
                            INT16_C(  -521), INT16_C(  4940), INT16_C(-18434), INT16_C(  4365),
                            INT16_C(-18143), INT16_C( 23566), INT16_C(-32412), INT16_C(-20606));
  simde_assert_m256i_i16(r, ==, e);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a, r, e;

  a = simde_mm256_set_epi32(INT32_C( 1527893980), INT32_C(  272236058), INT32_C( 1771532776), INT32_C( -527129145),
                            INT32_C(-1867900811), INT32_C( 1959964247), INT32_C( 1343894165), INT32_C( 1334695580));
  r = simde_mm256_insert_epi32(a, INT32_C( -707274869),  0);

  e = simde_mm256_set_epi32(INT32_C( 1527893980), INT32_C(  272236058), INT32_C( 1771532776), INT32_C( -527129145),
                            INT32_C(-1867900811), INT32_C( 1959964247), INT32_C( 1343894165), INT32_C( -707274869));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C( -661063243), INT32_C(-1710175048), INT32_C(  930876847), INT32_C(-1520459634),
                            INT32_C( -463408284), INT32_C( -440016671), INT32_C( 1321845686), INT32_C( 1111303375));
  r = simde_mm256_insert_epi32(a, INT32_C( 1750585714),  6);

  e = simde_mm256_set_epi32(INT32_C( -661063243), INT32_C( 1750585714), INT32_C(  930876847), INT32_C(-1520459634),
                            INT32_C( -463408284), INT32_C( -440016671), INT32_C( 1321845686), INT32_C( 1111303375));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C(  922514807), INT32_C(-1345830052), INT32_C(  578930278), INT32_C( -474805558),
                            INT32_C( 1483567706), INT32_C( 1465521628), INT32_C( 1619162073), INT32_C( -603337611));
  r = simde_mm256_insert_epi32(a, INT32_C( 1709940880),  5);

  e = simde_mm256_set_epi32(INT32_C(  922514807), INT32_C(-1345830052), INT32_C( 1709940880), INT32_C( -474805558),
                            INT32_C( 1483567706), INT32_C( 1465521628), INT32_C( 1619162073), INT32_C( -603337611));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C( 1682496014), INT32_C( -265998243), INT32_C( -696943616), INT32_C( -723203182),
                            INT32_C( 1593791374), INT32_C( -358344217), INT32_C(  813656782), INT32_C(   58704738));
  r = simde_mm256_insert_epi32(a, INT32_C( 1488485361),  5);

  e = simde_mm256_set_epi32(INT32_C( 1682496014), INT32_C( -265998243), INT32_C( 1488485361), INT32_C( -723203182),
                            INT32_C( 1593791374), INT32_C( -358344217), INT32_C(  813656782), INT32_C(   58704738));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C( 1847223436), INT32_C( -901858482), INT32_C( 1721924326), INT32_C(  291173023),
                            INT32_C(-1897007668), INT32_C(-1769936815), INT32_C(-1568319650), INT32_C(   -5176498));
  r = simde_mm256_insert_epi32(a, INT32_C(-1531789383),  1);

  e = simde_mm256_set_epi32(INT32_C( 1847223436), INT32_C( -901858482), INT32_C( 1721924326), INT32_C(  291173023),
                            INT32_C(-1897007668), INT32_C(-1769936815), INT32_C(-1531789383), INT32_C(   -5176498));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C(  350203051), INT32_C( -910749534), INT32_C(  265750572), INT32_C( 1641173073),
                            INT32_C( -538285717), INT32_C( -840003501), INT32_C( 1271510949), INT32_C(-1020673062));
  r = simde_mm256_insert_epi32(a, INT32_C( 1836561709),  3);

  e = simde_mm256_set_epi32(INT32_C(  350203051), INT32_C( -910749534), INT32_C(  265750572), INT32_C( 1641173073),
                            INT32_C( 1836561709), INT32_C( -840003501), INT32_C( 1271510949), INT32_C(-1020673062));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C(  547373175), INT32_C(-1592451622), INT32_C( 2039829911), INT32_C( -457221951),
                            INT32_C(-1618527211), INT32_C(-1978334272), INT32_C( 1765993380), INT32_C( 1580829317));
  r = simde_mm256_insert_epi32(a, INT32_C( 1732675568),  7);

  e = simde_mm256_set_epi32(INT32_C( 1732675568), INT32_C(-1592451622), INT32_C( 2039829911), INT32_C( -457221951),
                            INT32_C(-1618527211), INT32_C(-1978334272), INT32_C( 1765993380), INT32_C( 1580829317));
  simde_assert_m256i_i32(r, ==, e);

  a = simde_mm256_set_epi32(INT32_C( 1958144037), INT32_C(  549134406), INT32_C( -361892467), INT32_C( -550141532),
                            INT32_C(-2067091063), INT32_C( 1069015288), INT32_C(-1107603429), INT32_C( 1078737418));
  r = simde_mm256_insert_epi32(a, INT32_C(  896343144),  1);

  e = simde_mm256_set_epi32(INT32_C( 1958144037), INT32_C(  549134406), INT32_C( -361892467), INT32_C( -550141532),
                            INT32_C(-2067091063), INT32_C( 1069015288), INT32_C(  896343144), INT32_C( 1078737418));
  simde_assert_m256i_i32(r, ==, e);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insert_epi64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i a, r, e;

  a = simde_mm256_set_epi64x(INT64_C(-4505752726775834758), INT64_C( 5929367822849325121),
                             INT64_C( 7859909444158050752), INT64_C( 8378794972787494426));
  r = simde_mm256_insert_epi64(a, INT64_C( 3154696592882520417),  1);
  e = simde_mm256_set_epi64x(INT64_C(-4505752726775834758), INT64_C( 5929367822849325121),
                             INT64_C( 3154696592882520417), INT64_C( 8378794972787494426));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C(  396574839952628801), INT64_C( 4240491953132221671),
                             INT64_C( -278319971650278791), INT64_C( 6491233263195366023));
  r = simde_mm256_insert_epi64(a, INT64_C(-3297610962929123976),  3);
  e = simde_mm256_set_epi64x(INT64_C(-3297610962929123976), INT64_C( 4240491953132221671),
                             INT64_C( -278319971650278791), INT64_C( 6491233263195366023));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C(-1728252678477676185), INT64_C( 4096939565061250649),
                             INT64_C( -899841113114403992), INT64_C( 5786373883955623560));
  r = simde_mm256_insert_epi64(a, INT64_C(-3905247737278663189),  0);
  e = simde_mm256_set_epi64x(INT64_C(-1728252678477676185), INT64_C( 4096939565061250649),
                             INT64_C( -899841113114403992), INT64_C(-3905247737278663189));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C(-7506903298948604025), INT64_C(-5148494998623595939),
                             INT64_C( 1486007124617083344), INT64_C( 4658534095800830357));
  r = simde_mm256_insert_epi64(a, INT64_C(-7835784393738508471),  1);
  e = simde_mm256_set_epi64x(INT64_C(-7506903298948604025), INT64_C(-5148494998623595939),
                             INT64_C(-7835784393738508471), INT64_C( 4658534095800830357));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C(-2191440769984549047), INT64_C( 3908463436719096448),
                             INT64_C( 8526354170218817669), INT64_C(-3858780869273911597));
  r = simde_mm256_insert_epi64(a, INT64_C( 4403056273253937364),  3);
  e = simde_mm256_set_epi64x(INT64_C( 4403056273253937364), INT64_C( 3908463436719096448),
                             INT64_C( 8526354170218817669), INT64_C(-3858780869273911597));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C( 6661310305483280859), INT64_C(-6601747037924714764),
                             INT64_C(-1630628469313698153), INT64_C( 1161250947816487188));
  r = simde_mm256_insert_epi64(a, INT64_C(-7130294008098064663),  1);
  e = simde_mm256_set_epi64x(INT64_C( 6661310305483280859), INT64_C(-6601747037924714764),
                             INT64_C(-7130294008098064663), INT64_C( 1161250947816487188));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C(  782834070832404014), INT64_C(-2125384153009736171),
                             INT64_C(-8527778016730746462), INT64_C( 3421940001003476372));
  r = simde_mm256_insert_epi64(a, INT64_C( 3833121528156448342),  2);
  e = simde_mm256_set_epi64x(INT64_C(  782834070832404014), INT64_C( 3833121528156448342),
                             INT64_C(-8527778016730746462), INT64_C( 3421940001003476372));
  simde_assert_m256i_i64(r, ==, e);

  a = simde_mm256_set_epi64x(INT64_C( -656366593936952908), INT64_C(-1584520372107281742),
                             INT64_C( 8511510589800984870), INT64_C( 3076176925060453392));
  r = simde_mm256_insert_epi64(a, INT64_C( 7232381223726455225),  0);
  e = simde_mm256_set_epi64x(INT64_C( -656366593936952908), INT64_C(-1584520372107281742),
                             INT64_C( 8511510589800984870), INT64_C( 7232381223726455225));
  simde_assert_m256i_i64(r, ==, e);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m128 b;
    simde__m256 ra;
    simde__m256 rb;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   57.86), SIMDE_FLOAT32_C(  900.49),
                         SIMDE_FLOAT32_C(  678.15), SIMDE_FLOAT32_C( -551.43),
                         SIMDE_FLOAT32_C(  431.88), SIMDE_FLOAT32_C( -426.33),
                         SIMDE_FLOAT32_C( -705.72), SIMDE_FLOAT32_C(  809.23)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   57.86), SIMDE_FLOAT32_C(  900.49),
                         SIMDE_FLOAT32_C(  678.15), SIMDE_FLOAT32_C( -551.43),
                         SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -625.43), SIMDE_FLOAT32_C( -829.28),
                         SIMDE_FLOAT32_C(  -42.04), SIMDE_FLOAT32_C( -643.64),
                         SIMDE_FLOAT32_C(  431.88), SIMDE_FLOAT32_C( -426.33),
                         SIMDE_FLOAT32_C( -705.72), SIMDE_FLOAT32_C(  809.23)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -837.79), SIMDE_FLOAT32_C(  338.83),
                         SIMDE_FLOAT32_C(  296.45), SIMDE_FLOAT32_C(  172.80),
                         SIMDE_FLOAT32_C(  220.09), SIMDE_FLOAT32_C(  171.14),
                         SIMDE_FLOAT32_C(  492.30), SIMDE_FLOAT32_C( -224.75)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -837.79), SIMDE_FLOAT32_C(  338.83),
                         SIMDE_FLOAT32_C(  296.45), SIMDE_FLOAT32_C(  172.80),
                         SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -479.01), SIMDE_FLOAT32_C(  686.13),
                         SIMDE_FLOAT32_C( -518.69), SIMDE_FLOAT32_C( -606.38),
                         SIMDE_FLOAT32_C(  220.09), SIMDE_FLOAT32_C(  171.14),
                         SIMDE_FLOAT32_C(  492.30), SIMDE_FLOAT32_C( -224.75)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.08), SIMDE_FLOAT32_C( -599.25),
                         SIMDE_FLOAT32_C( -107.42), SIMDE_FLOAT32_C( -565.87),
                         SIMDE_FLOAT32_C( -588.15), SIMDE_FLOAT32_C(  906.13),
                         SIMDE_FLOAT32_C(  481.87), SIMDE_FLOAT32_C(  540.93)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -665.08), SIMDE_FLOAT32_C( -599.25),
                         SIMDE_FLOAT32_C( -107.42), SIMDE_FLOAT32_C( -565.87),
                         SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  308.44), SIMDE_FLOAT32_C( -387.39),
                         SIMDE_FLOAT32_C(  312.59), SIMDE_FLOAT32_C( -811.76),
                         SIMDE_FLOAT32_C( -588.15), SIMDE_FLOAT32_C(  906.13),
                         SIMDE_FLOAT32_C(  481.87), SIMDE_FLOAT32_C(  540.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -499.97), SIMDE_FLOAT32_C( -474.63),
                         SIMDE_FLOAT32_C( -449.49), SIMDE_FLOAT32_C(  941.31),
                         SIMDE_FLOAT32_C( -102.84), SIMDE_FLOAT32_C( -165.66),
                         SIMDE_FLOAT32_C( -680.74), SIMDE_FLOAT32_C(   98.73)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -499.97), SIMDE_FLOAT32_C( -474.63),
                         SIMDE_FLOAT32_C( -449.49), SIMDE_FLOAT32_C(  941.31),
                         SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -600.34), SIMDE_FLOAT32_C(  321.05),
                         SIMDE_FLOAT32_C(  438.78), SIMDE_FLOAT32_C(  -70.17),
                         SIMDE_FLOAT32_C( -102.84), SIMDE_FLOAT32_C( -165.66),
                         SIMDE_FLOAT32_C( -680.74), SIMDE_FLOAT32_C(   98.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.57), SIMDE_FLOAT32_C( -372.27),
                         SIMDE_FLOAT32_C( -839.54), SIMDE_FLOAT32_C(  507.35),
                         SIMDE_FLOAT32_C( -596.72), SIMDE_FLOAT32_C(  333.88),
                         SIMDE_FLOAT32_C( -839.21), SIMDE_FLOAT32_C( -624.72)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -402.57), SIMDE_FLOAT32_C( -372.27),
                         SIMDE_FLOAT32_C( -839.54), SIMDE_FLOAT32_C(  507.35),
                         SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -109.04), SIMDE_FLOAT32_C( -997.63),
                         SIMDE_FLOAT32_C(  959.39), SIMDE_FLOAT32_C( -856.10),
                         SIMDE_FLOAT32_C( -596.72), SIMDE_FLOAT32_C(  333.88),
                         SIMDE_FLOAT32_C( -839.21), SIMDE_FLOAT32_C( -624.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.40), SIMDE_FLOAT32_C( -137.24),
                         SIMDE_FLOAT32_C(  665.88), SIMDE_FLOAT32_C( -239.38),
                         SIMDE_FLOAT32_C(  864.82), SIMDE_FLOAT32_C(  415.07),
                         SIMDE_FLOAT32_C(  223.96), SIMDE_FLOAT32_C(  144.96)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -148.40), SIMDE_FLOAT32_C( -137.24),
                         SIMDE_FLOAT32_C(  665.88), SIMDE_FLOAT32_C( -239.38),
                         SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -29.35), SIMDE_FLOAT32_C( -415.61),
                         SIMDE_FLOAT32_C(  231.08), SIMDE_FLOAT32_C( -375.28),
                         SIMDE_FLOAT32_C(  864.82), SIMDE_FLOAT32_C(  415.07),
                         SIMDE_FLOAT32_C(  223.96), SIMDE_FLOAT32_C(  144.96)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  384.21), SIMDE_FLOAT32_C( -172.99),
                         SIMDE_FLOAT32_C( -651.42), SIMDE_FLOAT32_C(  104.60),
                         SIMDE_FLOAT32_C( -412.61), SIMDE_FLOAT32_C( -685.74),
                         SIMDE_FLOAT32_C(  349.45), SIMDE_FLOAT32_C(  431.71)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  384.21), SIMDE_FLOAT32_C( -172.99),
                         SIMDE_FLOAT32_C( -651.42), SIMDE_FLOAT32_C(  104.60),
                         SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  810.19), SIMDE_FLOAT32_C(   94.73),
                         SIMDE_FLOAT32_C(  542.66), SIMDE_FLOAT32_C(  824.78),
                         SIMDE_FLOAT32_C( -412.61), SIMDE_FLOAT32_C( -685.74),
                         SIMDE_FLOAT32_C(  349.45), SIMDE_FLOAT32_C(  431.71)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  117.02), SIMDE_FLOAT32_C(  874.06),
                         SIMDE_FLOAT32_C( -896.71), SIMDE_FLOAT32_C(  927.83),
                         SIMDE_FLOAT32_C( -471.09), SIMDE_FLOAT32_C(  907.26),
                         SIMDE_FLOAT32_C(  774.08), SIMDE_FLOAT32_C(  141.60)),
      simde_mm_set_ps   (SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  117.02), SIMDE_FLOAT32_C(  874.06),
                         SIMDE_FLOAT32_C( -896.71), SIMDE_FLOAT32_C(  927.83),
                         SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   69.32), SIMDE_FLOAT32_C(  645.62),
                         SIMDE_FLOAT32_C(  860.89), SIMDE_FLOAT32_C(  694.26),
                         SIMDE_FLOAT32_C( -471.09), SIMDE_FLOAT32_C(  907.26),
                         SIMDE_FLOAT32_C(  774.08), SIMDE_FLOAT32_C(  141.60)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 ra = simde_mm256_insertf128_ps(test_vec[i].a, test_vec[i].b, 0);
    simde__m256 rb = simde_mm256_insertf128_ps(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256_close(ra, test_vec[i].ra, 1);
    simde_assert_m256_close(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m128d b;
    simde__m256d ra;
    simde__m256d rb;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  500.07), SIMDE_FLOAT64_C(   24.20),
                         SIMDE_FLOAT64_C( -264.31), SIMDE_FLOAT64_C(  584.01)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  500.07), SIMDE_FLOAT64_C(   24.20),
                         SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  431.47), SIMDE_FLOAT64_C(  318.12),
                         SIMDE_FLOAT64_C( -264.31), SIMDE_FLOAT64_C(  584.01)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  669.13), SIMDE_FLOAT64_C( -378.72),
                         SIMDE_FLOAT64_C( -204.56), SIMDE_FLOAT64_C(  289.88)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  669.13), SIMDE_FLOAT64_C( -378.72),
                         SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  609.30), SIMDE_FLOAT64_C(  491.95),
                         SIMDE_FLOAT64_C( -204.56), SIMDE_FLOAT64_C(  289.88)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -439.47), SIMDE_FLOAT64_C(  501.94),
                         SIMDE_FLOAT64_C( -311.14), SIMDE_FLOAT64_C( -486.50)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -439.47), SIMDE_FLOAT64_C(  501.94),
                         SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  460.51), SIMDE_FLOAT64_C(  800.13),
                         SIMDE_FLOAT64_C( -311.14), SIMDE_FLOAT64_C( -486.50)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -828.83), SIMDE_FLOAT64_C(  892.34),
                         SIMDE_FLOAT64_C(  849.35), SIMDE_FLOAT64_C(   71.26)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -828.83), SIMDE_FLOAT64_C(  892.34),
                         SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  690.69), SIMDE_FLOAT64_C( -666.59),
                         SIMDE_FLOAT64_C(  849.35), SIMDE_FLOAT64_C(   71.26)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.25), SIMDE_FLOAT64_C( -143.78),
                         SIMDE_FLOAT64_C(  452.34), SIMDE_FLOAT64_C(  313.17)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -393.25), SIMDE_FLOAT64_C( -143.78),
                         SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    2.43), SIMDE_FLOAT64_C( -405.20),
                         SIMDE_FLOAT64_C(  452.34), SIMDE_FLOAT64_C(  313.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.72), SIMDE_FLOAT64_C( -282.65),
                         SIMDE_FLOAT64_C( -261.63), SIMDE_FLOAT64_C( -641.13)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -19.72), SIMDE_FLOAT64_C( -282.65),
                         SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  818.65), SIMDE_FLOAT64_C( -240.18),
                         SIMDE_FLOAT64_C( -261.63), SIMDE_FLOAT64_C( -641.13)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.87), SIMDE_FLOAT64_C(  692.31),
                         SIMDE_FLOAT64_C(  848.43), SIMDE_FLOAT64_C( -514.36)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.87), SIMDE_FLOAT64_C(  692.31),
                         SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -330.16), SIMDE_FLOAT64_C(  670.26),
                         SIMDE_FLOAT64_C(  848.43), SIMDE_FLOAT64_C( -514.36)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -917.99), SIMDE_FLOAT64_C(  637.33),
                         SIMDE_FLOAT64_C(  143.49), SIMDE_FLOAT64_C(  390.85)),
      simde_mm_set_pd   (SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -917.99), SIMDE_FLOAT64_C(  637.33),
                         SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.83), SIMDE_FLOAT64_C(  948.25),
                         SIMDE_FLOAT64_C(  143.49), SIMDE_FLOAT64_C(  390.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d ra = simde_mm256_insertf128_pd(test_vec[i].a, test_vec[i].b, 0);
    simde__m256d rb = simde_mm256_insertf128_pd(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256d_close(ra, test_vec[i].ra, 1);
    simde_assert_m256d_close(rb, test_vec[i].rb, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_insertf128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m128i b;
    simde__m256i ra;
    simde__m256i rb;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1732788931), INT32_C( -493919285), INT32_C( -171391193), INT32_C( 1397412103),
                            INT32_C( -356536147), INT32_C(-1692932708), INT32_C(-1699348696), INT32_C( -647395099)),
      simde_mm_set_epi32   (INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332)),
      simde_mm256_set_epi32(INT32_C( 1732788931), INT32_C( -493919285), INT32_C( -171391193), INT32_C( 1397412103),
                            INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332)),
      simde_mm256_set_epi32(INT32_C(-1522680411), INT32_C(-1731979321), INT32_C( 1240335413), INT32_C(  201854332),
                            INT32_C( -356536147), INT32_C(-1692932708), INT32_C(-1699348696), INT32_C( -647395099)) },
    { simde_mm256_set_epi32(INT32_C(-1444875329), INT32_C( 1610023191), INT32_C( -708588022), INT32_C( -172947680),
                            INT32_C(  545675582), INT32_C( 1925063203), INT32_C(  200249152), INT32_C(  925361522)),
      simde_mm_set_epi32   (INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265)),
      simde_mm256_set_epi32(INT32_C(-1444875329), INT32_C( 1610023191), INT32_C( -708588022), INT32_C( -172947680),
                            INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265)),
      simde_mm256_set_epi32(INT32_C( -719778838), INT32_C( -908663617), INT32_C(-1043096582), INT32_C( 2027106265),
                            INT32_C(  545675582), INT32_C( 1925063203), INT32_C(  200249152), INT32_C(  925361522)) },
    { simde_mm256_set_epi32(INT32_C(  819255641), INT32_C(  758383634), INT32_C( -712717178), INT32_C( 1831898363),
                            INT32_C( -652589148), INT32_C(  437505059), INT32_C(-1426201125), INT32_C(  915542579)),
      simde_mm_set_epi32   (INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672)),
      simde_mm256_set_epi32(INT32_C(  819255641), INT32_C(  758383634), INT32_C( -712717178), INT32_C( 1831898363),
                            INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672)),
      simde_mm256_set_epi32(INT32_C( 1102980249), INT32_C( 1568821342), INT32_C( 1031497605), INT32_C( 1535564672),
                            INT32_C( -652589148), INT32_C(  437505059), INT32_C(-1426201125), INT32_C(  915542579)) },
    { simde_mm256_set_epi32(INT32_C(-1576300711), INT32_C(  804080573), INT32_C(-1947930635), INT32_C( -773073118),
                            INT32_C( -708044343), INT32_C( 1025803241), INT32_C(-1542400953), INT32_C( 1513652867)),
      simde_mm_set_epi32   (INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491)),
      simde_mm256_set_epi32(INT32_C(-1576300711), INT32_C(  804080573), INT32_C(-1947930635), INT32_C( -773073118),
                            INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491)),
      simde_mm256_set_epi32(INT32_C( -630903986), INT32_C( 1210274072), INT32_C(-1479627472), INT32_C( 1540958491),
                            INT32_C( -708044343), INT32_C( 1025803241), INT32_C(-1542400953), INT32_C( 1513652867)) },
    { simde_mm256_set_epi32(INT32_C(-1474400259), INT32_C( 1988182849), INT32_C(-1345043070), INT32_C(-2043590369),
                            INT32_C( -792511350), INT32_C(-1919476039), INT32_C( -711077027), INT32_C(-1924737697)),
      simde_mm_set_epi32   (INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932)),
      simde_mm256_set_epi32(INT32_C(-1474400259), INT32_C( 1988182849), INT32_C(-1345043070), INT32_C(-2043590369),
                            INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932)),
      simde_mm256_set_epi32(INT32_C(-1229154872), INT32_C( 1506932355), INT32_C(  529233496), INT32_C(  900061932),
                            INT32_C( -792511350), INT32_C(-1919476039), INT32_C( -711077027), INT32_C(-1924737697)) },
    { simde_mm256_set_epi32(INT32_C( 1011012252), INT32_C(-1383487313), INT32_C( -799281089), INT32_C(-1421799289),
                            INT32_C(-1020863292), INT32_C( -870274327), INT32_C(  767506840), INT32_C(  905532467)),
      simde_mm_set_epi32   (INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450)),
      simde_mm256_set_epi32(INT32_C( 1011012252), INT32_C(-1383487313), INT32_C( -799281089), INT32_C(-1421799289),
                            INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450)),
      simde_mm256_set_epi32(INT32_C(  535053718), INT32_C( 1571414305), INT32_C(  327456521), INT32_C(  562021450),
                            INT32_C(-1020863292), INT32_C( -870274327), INT32_C(  767506840), INT32_C(  905532467)) },
    { simde_mm256_set_epi32(INT32_C(-1892816233), INT32_C( -258025342), INT32_C(-1474147149), INT32_C(  200557748),
                            INT32_C(  863187861), INT32_C( 1974870245), INT32_C( 1114174400), INT32_C( -122006961)),
      simde_mm_set_epi32   (INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353)),
      simde_mm256_set_epi32(INT32_C(-1892816233), INT32_C( -258025342), INT32_C(-1474147149), INT32_C(  200557748),
                            INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353)),
      simde_mm256_set_epi32(INT32_C( 1960728456), INT32_C(-1615388317), INT32_C(  728614642), INT32_C(  181559353),
                            INT32_C(  863187861), INT32_C( 1974870245), INT32_C( 1114174400), INT32_C( -122006961)) },
    { simde_mm256_set_epi32(INT32_C( -172940012), INT32_C(-1274554211), INT32_C( -855665209), INT32_C(  935611457),
                            INT32_C( -592164168), INT32_C(  945068232), INT32_C(  755470781), INT32_C(-1762512447)),
      simde_mm_set_epi32   (INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337)),
      simde_mm256_set_epi32(INT32_C( -172940012), INT32_C(-1274554211), INT32_C( -855665209), INT32_C(  935611457),
                            INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337)),
      simde_mm256_set_epi32(INT32_C(-1172491108), INT32_C(-1413112125), INT32_C(   65588240), INT32_C(-1859214337),
                            INT32_C( -592164168), INT32_C(  945068232), INT32_C(  755470781), INT32_C(-1762512447)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i ra = simde_mm256_insertf128_si256(test_vec[i].a, test_vec[i].b, 0);
    simde__m256i rb = simde_mm256_insertf128_si256(test_vec[i].a, test_vec[i].b, 1);
    simde_assert_m256i_i32(ra, ==, test_vec[i].ra);
    simde_assert_m256i_i32(rb, ==, test_vec[i].rb);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_lddqu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -208613396), INT32_C(  972060947), INT32_C( 1079690819), INT32_C(-1629141358),
                            INT32_C( -291568998), INT32_C( -706346303), INT32_C( 1782265269), INT32_C(  663843445)),
      simde_mm256_set_epi32(INT32_C( -208613396), INT32_C(  972060947), INT32_C( 1079690819), INT32_C(-1629141358),
                            INT32_C( -291568998), INT32_C( -706346303), INT32_C( 1782265269), INT32_C(  663843445)) },
    { simde_mm256_set_epi32(INT32_C( -542385526), INT32_C(-1915647746), INT32_C(  251129882), INT32_C(  290247368),
                            INT32_C(  363399145), INT32_C(  688121978), INT32_C(  600807845), INT32_C( 1456401224)),
      simde_mm256_set_epi32(INT32_C( -542385526), INT32_C(-1915647746), INT32_C(  251129882), INT32_C(  290247368),
                            INT32_C(  363399145), INT32_C(  688121978), INT32_C(  600807845), INT32_C( 1456401224)) },
    { simde_mm256_set_epi32(INT32_C(  862880243), INT32_C(  961555167), INT32_C( -704902562), INT32_C(-2017515450),
                            INT32_C(-1906482322), INT32_C(-1699379933), INT32_C( 1894527886), INT32_C( 2049947519)),
      simde_mm256_set_epi32(INT32_C(  862880243), INT32_C(  961555167), INT32_C( -704902562), INT32_C(-2017515450),
                            INT32_C(-1906482322), INT32_C(-1699379933), INT32_C( 1894527886), INT32_C( 2049947519)) },
    { simde_mm256_set_epi32(INT32_C( 1564827830), INT32_C( -831950379), INT32_C(  815117120), INT32_C( -372364589),
                            INT32_C(-1095370522), INT32_C( 1608512554), INT32_C( 1210942744), INT32_C(  816264608)),
      simde_mm256_set_epi32(INT32_C( 1564827830), INT32_C( -831950379), INT32_C(  815117120), INT32_C( -372364589),
                            INT32_C(-1095370522), INT32_C( 1608512554), INT32_C( 1210942744), INT32_C(  816264608)) },
    { simde_mm256_set_epi32(INT32_C( 1014835213), INT32_C(  419509758), INT32_C( -940172407), INT32_C( 2075423717),
                            INT32_C( -958302313), INT32_C( 2056263130), INT32_C( -179845947), INT32_C( -487391602)),
      simde_mm256_set_epi32(INT32_C( 1014835213), INT32_C(  419509758), INT32_C( -940172407), INT32_C( 2075423717),
                            INT32_C( -958302313), INT32_C( 2056263130), INT32_C( -179845947), INT32_C( -487391602)) },
    { simde_mm256_set_epi32(INT32_C(  750230136), INT32_C(  830844077), INT32_C( 1366738463), INT32_C( 1719449608),
                            INT32_C(  953227083), INT32_C( -624601508), INT32_C( -983006206), INT32_C( 1138640848)),
      simde_mm256_set_epi32(INT32_C(  750230136), INT32_C(  830844077), INT32_C( 1366738463), INT32_C( 1719449608),
                            INT32_C(  953227083), INT32_C( -624601508), INT32_C( -983006206), INT32_C( 1138640848)) },
    { simde_mm256_set_epi32(INT32_C(-2045061394), INT32_C( -759814821), INT32_C( 1064937743), INT32_C(-1124388611),
                            INT32_C( -168818003), INT32_C( -757055903), INT32_C(-1606176919), INT32_C(  254467933)),
      simde_mm256_set_epi32(INT32_C(-2045061394), INT32_C( -759814821), INT32_C( 1064937743), INT32_C(-1124388611),
                            INT32_C( -168818003), INT32_C( -757055903), INT32_C(-1606176919), INT32_C(  254467933)) },
    { simde_mm256_set_epi32(INT32_C(-1387663431), INT32_C( 2083885974), INT32_C(  524830617), INT32_C( 1548734942),
                            INT32_C( 1378860315), INT32_C(-1149727640), INT32_C( 1373643603), INT32_C(  772353923)),
      simde_mm256_set_epi32(INT32_C(-1387663431), INT32_C( 2083885974), INT32_C(  524830617), INT32_C( 1548734942),
                            INT32_C( 1378860315), INT32_C(-1149727640), INT32_C( 1373643603), INT32_C(  772353923)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_lddqu_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a[sizeof(simde__m256d) / sizeof(simde_float64)];
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C( -338.67), SIMDE_FLOAT64_C(  630.84), SIMDE_FLOAT64_C( -302.19), SIMDE_FLOAT64_C( -238.77) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -238.77), SIMDE_FLOAT64_C( -302.19),
                         SIMDE_FLOAT64_C(  630.84), SIMDE_FLOAT64_C( -338.67)) },
    { { SIMDE_FLOAT64_C(  725.41), SIMDE_FLOAT64_C( -787.32), SIMDE_FLOAT64_C( -819.45), SIMDE_FLOAT64_C(  657.50) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  657.50), SIMDE_FLOAT64_C( -819.45),
                         SIMDE_FLOAT64_C( -787.32), SIMDE_FLOAT64_C(  725.41)) },
    { { SIMDE_FLOAT64_C( -519.61), SIMDE_FLOAT64_C(  692.74), SIMDE_FLOAT64_C(   96.96), SIMDE_FLOAT64_C(  -63.30) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -63.30), SIMDE_FLOAT64_C(   96.96),
                         SIMDE_FLOAT64_C(  692.74), SIMDE_FLOAT64_C( -519.61)) },
    { { SIMDE_FLOAT64_C(  577.54), SIMDE_FLOAT64_C( -524.47), SIMDE_FLOAT64_C( -254.05), SIMDE_FLOAT64_C(  614.55) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  614.55), SIMDE_FLOAT64_C( -254.05),
                         SIMDE_FLOAT64_C( -524.47), SIMDE_FLOAT64_C(  577.54)) },
    { { SIMDE_FLOAT64_C( -608.94), SIMDE_FLOAT64_C(  345.46), SIMDE_FLOAT64_C( -476.81), SIMDE_FLOAT64_C( -532.19) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -532.19), SIMDE_FLOAT64_C( -476.81),
                         SIMDE_FLOAT64_C(  345.46), SIMDE_FLOAT64_C( -608.94)) },
    { { SIMDE_FLOAT64_C(   96.64), SIMDE_FLOAT64_C( -218.82), SIMDE_FLOAT64_C( -345.29), SIMDE_FLOAT64_C( -716.59) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -716.59), SIMDE_FLOAT64_C( -345.29),
                         SIMDE_FLOAT64_C( -218.82), SIMDE_FLOAT64_C(   96.64)) },
    { { SIMDE_FLOAT64_C(  896.80), SIMDE_FLOAT64_C( -999.47), SIMDE_FLOAT64_C(  692.69), SIMDE_FLOAT64_C(   75.34) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   75.34), SIMDE_FLOAT64_C(  692.69),
                         SIMDE_FLOAT64_C( -999.47), SIMDE_FLOAT64_C(  896.80)) },
    { { SIMDE_FLOAT64_C( -936.41), SIMDE_FLOAT64_C(  832.42), SIMDE_FLOAT64_C(  861.03), SIMDE_FLOAT64_C( -909.25) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -909.25), SIMDE_FLOAT64_C(  861.03),
                         SIMDE_FLOAT64_C(  832.42), SIMDE_FLOAT64_C( -936.41)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_load_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN_AS(32, simde__m256) simde_float32 a[sizeof(simde__m256) / sizeof(simde_float32)];
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -651.15), SIMDE_FLOAT32_C(   486.09),
        SIMDE_FLOAT32_C(   809.52), SIMDE_FLOAT32_C(   897.18),
        SIMDE_FLOAT32_C(  -164.76), SIMDE_FLOAT32_C(   925.08),
        SIMDE_FLOAT32_C(  -141.17), SIMDE_FLOAT32_C(   524.77) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   524.77), SIMDE_FLOAT32_C(  -141.17),
                         SIMDE_FLOAT32_C(   925.08), SIMDE_FLOAT32_C(  -164.76),
                         SIMDE_FLOAT32_C(   897.18), SIMDE_FLOAT32_C(   809.52),
                         SIMDE_FLOAT32_C(   486.09), SIMDE_FLOAT32_C(  -651.15)) },
    { { SIMDE_FLOAT32_C(   154.61), SIMDE_FLOAT32_C(  -436.96),
        SIMDE_FLOAT32_C(  -109.54), SIMDE_FLOAT32_C(  -422.39),
        SIMDE_FLOAT32_C(  -113.81), SIMDE_FLOAT32_C(  -740.60),
        SIMDE_FLOAT32_C(  -581.05), SIMDE_FLOAT32_C(   534.88) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   534.88), SIMDE_FLOAT32_C(  -581.05),
                         SIMDE_FLOAT32_C(  -740.60), SIMDE_FLOAT32_C(  -113.81),
                         SIMDE_FLOAT32_C(  -422.39), SIMDE_FLOAT32_C(  -109.54),
                         SIMDE_FLOAT32_C(  -436.96), SIMDE_FLOAT32_C(   154.61)) },
    { { SIMDE_FLOAT32_C(   689.49), SIMDE_FLOAT32_C(  -831.99),
        SIMDE_FLOAT32_C(   872.86), SIMDE_FLOAT32_C(   554.28),
        SIMDE_FLOAT32_C(   799.73), SIMDE_FLOAT32_C(  -331.18),
        SIMDE_FLOAT32_C(   338.85), SIMDE_FLOAT32_C(   425.19) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   425.19), SIMDE_FLOAT32_C(   338.85),
                         SIMDE_FLOAT32_C(  -331.18), SIMDE_FLOAT32_C(   799.73),
                         SIMDE_FLOAT32_C(   554.28), SIMDE_FLOAT32_C(   872.86),
                         SIMDE_FLOAT32_C(  -831.99), SIMDE_FLOAT32_C(   689.49)) },
    { { SIMDE_FLOAT32_C(    22.85), SIMDE_FLOAT32_C(  -436.81),
        SIMDE_FLOAT32_C(   473.32), SIMDE_FLOAT32_C(   132.51),
        SIMDE_FLOAT32_C(  -295.42), SIMDE_FLOAT32_C(    74.04),
        SIMDE_FLOAT32_C(   445.74), SIMDE_FLOAT32_C(   574.68) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   574.68), SIMDE_FLOAT32_C(   445.74),
                         SIMDE_FLOAT32_C(    74.04), SIMDE_FLOAT32_C(  -295.42),
                         SIMDE_FLOAT32_C(   132.51), SIMDE_FLOAT32_C(   473.32),
                         SIMDE_FLOAT32_C(  -436.81), SIMDE_FLOAT32_C(    22.85)) },
    { { SIMDE_FLOAT32_C(   105.79), SIMDE_FLOAT32_C(   -21.01),
        SIMDE_FLOAT32_C(  -754.65), SIMDE_FLOAT32_C(  -355.76),
        SIMDE_FLOAT32_C(   716.76), SIMDE_FLOAT32_C(  -141.32),
        SIMDE_FLOAT32_C(   300.83), SIMDE_FLOAT32_C(   -21.61) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -21.61), SIMDE_FLOAT32_C(   300.83),
                         SIMDE_FLOAT32_C(  -141.32), SIMDE_FLOAT32_C(   716.76),
                         SIMDE_FLOAT32_C(  -355.76), SIMDE_FLOAT32_C(  -754.65),
                         SIMDE_FLOAT32_C(   -21.01), SIMDE_FLOAT32_C(   105.79)) },
    { { SIMDE_FLOAT32_C(  -421.92), SIMDE_FLOAT32_C(   236.64),
        SIMDE_FLOAT32_C(  -349.60), SIMDE_FLOAT32_C(   710.87),
        SIMDE_FLOAT32_C(  -664.65), SIMDE_FLOAT32_C(    50.17),
        SIMDE_FLOAT32_C(    82.89), SIMDE_FLOAT32_C(  -240.57) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -240.57), SIMDE_FLOAT32_C(    82.89),
                         SIMDE_FLOAT32_C(    50.17), SIMDE_FLOAT32_C(  -664.65),
                         SIMDE_FLOAT32_C(   710.87), SIMDE_FLOAT32_C(  -349.60),
                         SIMDE_FLOAT32_C(   236.64), SIMDE_FLOAT32_C(  -421.92)) },
    { { SIMDE_FLOAT32_C(    68.48), SIMDE_FLOAT32_C(   518.42),
        SIMDE_FLOAT32_C(   968.06), SIMDE_FLOAT32_C(  -197.34),
        SIMDE_FLOAT32_C(   351.10), SIMDE_FLOAT32_C(   113.17),
        SIMDE_FLOAT32_C(   713.12), SIMDE_FLOAT32_C(  -462.23) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -462.23), SIMDE_FLOAT32_C(   713.12),
                         SIMDE_FLOAT32_C(   113.17), SIMDE_FLOAT32_C(   351.10),
                         SIMDE_FLOAT32_C(  -197.34), SIMDE_FLOAT32_C(   968.06),
                         SIMDE_FLOAT32_C(   518.42), SIMDE_FLOAT32_C(    68.48)) },
    { { SIMDE_FLOAT32_C(  -676.83), SIMDE_FLOAT32_C(   745.78),
        SIMDE_FLOAT32_C(  -436.07), SIMDE_FLOAT32_C(   808.02),
        SIMDE_FLOAT32_C(   901.47), SIMDE_FLOAT32_C(  -652.23),
        SIMDE_FLOAT32_C(  -649.97), SIMDE_FLOAT32_C(  -289.44) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -289.44), SIMDE_FLOAT32_C(  -649.97),
                         SIMDE_FLOAT32_C(  -652.23), SIMDE_FLOAT32_C(   901.47),
                         SIMDE_FLOAT32_C(   808.02), SIMDE_FLOAT32_C(  -436.07),
                         SIMDE_FLOAT32_C(   745.78), SIMDE_FLOAT32_C(  -676.83)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_load_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_load_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)),
      simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)) },
    { simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)),
      simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)) },
    { simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)),
      simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)) },
    { simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)),
      simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)) },
    { simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)),
      simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)) },
    { simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)),
      simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)) },
    { simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)),
      simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)) },
    { simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)),
      simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_load_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a[sizeof(simde__m256d) / sizeof(simde_float64)];
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C( -245.76), SIMDE_FLOAT64_C( -764.95),
        SIMDE_FLOAT64_C(  498.87), SIMDE_FLOAT64_C( -327.12) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -327.12), SIMDE_FLOAT64_C(  498.87),
                         SIMDE_FLOAT64_C( -764.95), SIMDE_FLOAT64_C( -245.76)) },
    { { SIMDE_FLOAT64_C( -747.96), SIMDE_FLOAT64_C(  887.55),
        SIMDE_FLOAT64_C( -714.24), SIMDE_FLOAT64_C(  189.85) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  189.85), SIMDE_FLOAT64_C( -714.24),
                         SIMDE_FLOAT64_C(  887.55), SIMDE_FLOAT64_C( -747.96)) },
    { { SIMDE_FLOAT64_C( -816.60), SIMDE_FLOAT64_C(  548.05),
        SIMDE_FLOAT64_C( -852.03), SIMDE_FLOAT64_C(  683.50) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  683.50), SIMDE_FLOAT64_C( -852.03),
                         SIMDE_FLOAT64_C(  548.05), SIMDE_FLOAT64_C( -816.60)) },
    { { SIMDE_FLOAT64_C(  957.12), SIMDE_FLOAT64_C(  857.15),
        SIMDE_FLOAT64_C( -289.83), SIMDE_FLOAT64_C( -642.05) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -642.05), SIMDE_FLOAT64_C( -289.83),
                         SIMDE_FLOAT64_C(  857.15), SIMDE_FLOAT64_C(  957.12)) },
    { { SIMDE_FLOAT64_C(  279.73), SIMDE_FLOAT64_C(   98.54),
        SIMDE_FLOAT64_C(  917.87), SIMDE_FLOAT64_C( -218.86) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -218.86), SIMDE_FLOAT64_C(  917.87),
                         SIMDE_FLOAT64_C(   98.54), SIMDE_FLOAT64_C(  279.73)) },
    { { SIMDE_FLOAT64_C( -705.64), SIMDE_FLOAT64_C(  -89.39),
        SIMDE_FLOAT64_C( -237.89), SIMDE_FLOAT64_C(    9.05) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    9.05), SIMDE_FLOAT64_C( -237.89),
                         SIMDE_FLOAT64_C(  -89.39), SIMDE_FLOAT64_C( -705.64)) },
    { { SIMDE_FLOAT64_C(  359.06), SIMDE_FLOAT64_C(  630.19),
        SIMDE_FLOAT64_C( -718.76), SIMDE_FLOAT64_C(  263.72) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  263.72), SIMDE_FLOAT64_C( -718.76),
                         SIMDE_FLOAT64_C(  630.19), SIMDE_FLOAT64_C(  359.06)) },
    { { SIMDE_FLOAT64_C(  705.88), SIMDE_FLOAT64_C(  454.13),
        SIMDE_FLOAT64_C(  871.24), SIMDE_FLOAT64_C( -794.27) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -794.27), SIMDE_FLOAT64_C(  871.24),
                         SIMDE_FLOAT64_C(  454.13), SIMDE_FLOAT64_C(  705.88)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_load_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a[sizeof(simde__m256) / sizeof(simde_float32)];
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   989.38), SIMDE_FLOAT32_C(  -636.59),
        SIMDE_FLOAT32_C(   969.19), SIMDE_FLOAT32_C(   802.78),
        SIMDE_FLOAT32_C(  -677.79), SIMDE_FLOAT32_C(   669.00),
        SIMDE_FLOAT32_C(  -625.50), SIMDE_FLOAT32_C(  -971.80) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -971.80), SIMDE_FLOAT32_C(  -625.50),
                         SIMDE_FLOAT32_C(   669.00), SIMDE_FLOAT32_C(  -677.79),
                         SIMDE_FLOAT32_C(   802.78), SIMDE_FLOAT32_C(   969.19),
                         SIMDE_FLOAT32_C(  -636.59), SIMDE_FLOAT32_C(   989.38)) },
    { { SIMDE_FLOAT32_C(   483.87), SIMDE_FLOAT32_C(   313.54),
        SIMDE_FLOAT32_C(  -722.81), SIMDE_FLOAT32_C(   175.58),
        SIMDE_FLOAT32_C(  -520.14), SIMDE_FLOAT32_C(  -222.39),
        SIMDE_FLOAT32_C(   889.56), SIMDE_FLOAT32_C(  -141.86) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -141.86), SIMDE_FLOAT32_C(   889.56),
                         SIMDE_FLOAT32_C(  -222.39), SIMDE_FLOAT32_C(  -520.14),
                         SIMDE_FLOAT32_C(   175.58), SIMDE_FLOAT32_C(  -722.81),
                         SIMDE_FLOAT32_C(   313.54), SIMDE_FLOAT32_C(   483.87)) },
    { { SIMDE_FLOAT32_C(    28.06), SIMDE_FLOAT32_C(   709.83),
        SIMDE_FLOAT32_C(  -372.28), SIMDE_FLOAT32_C(   743.18),
        SIMDE_FLOAT32_C(  -465.26), SIMDE_FLOAT32_C(  -871.71),
        SIMDE_FLOAT32_C(   213.87), SIMDE_FLOAT32_C(    34.60) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    34.60), SIMDE_FLOAT32_C(   213.87),
                         SIMDE_FLOAT32_C(  -871.71), SIMDE_FLOAT32_C(  -465.26),
                         SIMDE_FLOAT32_C(   743.18), SIMDE_FLOAT32_C(  -372.28),
                         SIMDE_FLOAT32_C(   709.83), SIMDE_FLOAT32_C(    28.06)) },
    { { SIMDE_FLOAT32_C(   290.56), SIMDE_FLOAT32_C(   408.42),
        SIMDE_FLOAT32_C(  -438.13), SIMDE_FLOAT32_C(  -460.46),
        SIMDE_FLOAT32_C(  -639.21), SIMDE_FLOAT32_C(  -231.83),
        SIMDE_FLOAT32_C(   590.87), SIMDE_FLOAT32_C(  -474.24) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -474.24), SIMDE_FLOAT32_C(   590.87),
                         SIMDE_FLOAT32_C(  -231.83), SIMDE_FLOAT32_C(  -639.21),
                         SIMDE_FLOAT32_C(  -460.46), SIMDE_FLOAT32_C(  -438.13),
                         SIMDE_FLOAT32_C(   408.42), SIMDE_FLOAT32_C(   290.56)) },
    { { SIMDE_FLOAT32_C(  -304.73), SIMDE_FLOAT32_C(   108.23),
        SIMDE_FLOAT32_C(   -73.19), SIMDE_FLOAT32_C(   188.25),
        SIMDE_FLOAT32_C(   420.93), SIMDE_FLOAT32_C(   522.97),
        SIMDE_FLOAT32_C(   234.89), SIMDE_FLOAT32_C(  -731.34) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -731.34), SIMDE_FLOAT32_C(   234.89),
                         SIMDE_FLOAT32_C(   522.97), SIMDE_FLOAT32_C(   420.93),
                         SIMDE_FLOAT32_C(   188.25), SIMDE_FLOAT32_C(   -73.19),
                         SIMDE_FLOAT32_C(   108.23), SIMDE_FLOAT32_C(  -304.73)) },
    { { SIMDE_FLOAT32_C(   708.07), SIMDE_FLOAT32_C(   370.70),
        SIMDE_FLOAT32_C(  -989.08), SIMDE_FLOAT32_C(  -602.45),
        SIMDE_FLOAT32_C(  -987.01), SIMDE_FLOAT32_C(   154.31),
        SIMDE_FLOAT32_C(  -220.43), SIMDE_FLOAT32_C(   262.39) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   262.39), SIMDE_FLOAT32_C(  -220.43),
                         SIMDE_FLOAT32_C(   154.31), SIMDE_FLOAT32_C(  -987.01),
                         SIMDE_FLOAT32_C(  -602.45), SIMDE_FLOAT32_C(  -989.08),
                         SIMDE_FLOAT32_C(   370.70), SIMDE_FLOAT32_C(   708.07)) },
    { { SIMDE_FLOAT32_C(   947.64), SIMDE_FLOAT32_C(   -74.77),
        SIMDE_FLOAT32_C(   902.77), SIMDE_FLOAT32_C(  -429.19),
        SIMDE_FLOAT32_C(  -305.81), SIMDE_FLOAT32_C(   762.65),
        SIMDE_FLOAT32_C(  -261.04), SIMDE_FLOAT32_C(  -156.66) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -156.66), SIMDE_FLOAT32_C(  -261.04),
                         SIMDE_FLOAT32_C(   762.65), SIMDE_FLOAT32_C(  -305.81),
                         SIMDE_FLOAT32_C(  -429.19), SIMDE_FLOAT32_C(   902.77),
                         SIMDE_FLOAT32_C(   -74.77), SIMDE_FLOAT32_C(   947.64)) },
    { { SIMDE_FLOAT32_C(  -313.48), SIMDE_FLOAT32_C(  -237.38),
        SIMDE_FLOAT32_C(   572.62), SIMDE_FLOAT32_C(  -800.42),
        SIMDE_FLOAT32_C(    -6.98), SIMDE_FLOAT32_C(   968.23),
        SIMDE_FLOAT32_C(   417.54), SIMDE_FLOAT32_C(   107.47) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   107.47), SIMDE_FLOAT32_C(   417.54),
                         SIMDE_FLOAT32_C(   968.23), SIMDE_FLOAT32_C(    -6.98),
                         SIMDE_FLOAT32_C(  -800.42), SIMDE_FLOAT32_C(   572.62),
                         SIMDE_FLOAT32_C(  -237.38), SIMDE_FLOAT32_C(  -313.48)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_loadu_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)),
      simde_mm256_set_epi32(INT32_C(   93433077), INT32_C(  912488615), INT32_C( -849505573), INT32_C( -538760324),
                            INT32_C(  576018808), INT32_C(  306399285), INT32_C(  761465198), INT32_C(   67322681)) },
    { simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)),
      simde_mm256_set_epi32(INT32_C( 1661040700), INT32_C(-1506281364), INT32_C(  769308925), INT32_C( -545741767),
                            INT32_C(-1609914843), INT32_C(-1728610320), INT32_C( 1438363911), INT32_C(-1495474004)) },
    { simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)),
      simde_mm256_set_epi32(INT32_C( -403469250), INT32_C( 1422195130), INT32_C( 1240509512), INT32_C(-1325093027),
                            INT32_C( 1112848703), INT32_C(  757887555), INT32_C( -808479029), INT32_C( 1524821649)) },
    { simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)),
      simde_mm256_set_epi32(INT32_C(  419753251), INT32_C( 1133371811), INT32_C( 1920523876), INT32_C( 1566543302),
                            INT32_C( 1608176387), INT32_C(  174748447), INT32_C(-1944132629), INT32_C(-1618941327)) },
    { simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)),
      simde_mm256_set_epi32(INT32_C(  133578927), INT32_C(  -89176331), INT32_C(  533976318), INT32_C(  686005880),
                            INT32_C( 1680867737), INT32_C( -633287306), INT32_C( -911734776), INT32_C( 1028891739)) },
    { simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)),
      simde_mm256_set_epi32(INT32_C( 1968343895), INT32_C( 1991193919), INT32_C(-1412421123), INT32_C(-1413471204),
                            INT32_C( 1571538617), INT32_C(  392630938), INT32_C(   44925707), INT32_C(-1288122501)) },
    { simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)),
      simde_mm256_set_epi32(INT32_C(  932954327), INT32_C(  884951875), INT32_C(-1145840174), INT32_C( 2040117874),
                            INT32_C(   39201359), INT32_C( -102892947), INT32_C(  740751736), INT32_C( 1598969461)) },
    { simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)),
      simde_mm256_set_epi32(INT32_C( -471731507), INT32_C( 1955207001), INT32_C(-1681640586), INT32_C( -304295513),
                            INT32_C( 1688427496), INT32_C(-1852849481), INT32_C( -533311004), INT32_C(  263226824)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_loadu_si256(&(test_vec[i].a));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a[sizeof(simde__m128) / sizeof(simde_float32)];
    simde_float32 b[sizeof(simde__m128) / sizeof(simde_float32)];
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(    13.39), SIMDE_FLOAT32_C(   253.33), SIMDE_FLOAT32_C(   769.78), SIMDE_FLOAT32_C(   607.23) },
      { SIMDE_FLOAT32_C(   382.59), SIMDE_FLOAT32_C(   295.37), SIMDE_FLOAT32_C(  -847.51), SIMDE_FLOAT32_C(  -193.22) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   607.23), SIMDE_FLOAT32_C(   769.78),
                         SIMDE_FLOAT32_C(   253.33), SIMDE_FLOAT32_C(    13.39),
                         SIMDE_FLOAT32_C(  -193.22), SIMDE_FLOAT32_C(  -847.51),
                         SIMDE_FLOAT32_C(   295.37), SIMDE_FLOAT32_C(   382.59)) },
    { { SIMDE_FLOAT32_C(  -621.90), SIMDE_FLOAT32_C(   305.75), SIMDE_FLOAT32_C(  -907.35), SIMDE_FLOAT32_C(  -378.43) },
      { SIMDE_FLOAT32_C(   165.24), SIMDE_FLOAT32_C(   212.29), SIMDE_FLOAT32_C(   823.95), SIMDE_FLOAT32_C(   837.28) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -378.43), SIMDE_FLOAT32_C(  -907.35),
                         SIMDE_FLOAT32_C(   305.75), SIMDE_FLOAT32_C(  -621.90),
                         SIMDE_FLOAT32_C(   837.28), SIMDE_FLOAT32_C(   823.95),
                         SIMDE_FLOAT32_C(   212.29), SIMDE_FLOAT32_C(   165.24)) },
    { { SIMDE_FLOAT32_C(  -207.02), SIMDE_FLOAT32_C(   949.44), SIMDE_FLOAT32_C(   953.63), SIMDE_FLOAT32_C(  -540.83) },
      { SIMDE_FLOAT32_C(  -239.63), SIMDE_FLOAT32_C(  -907.66), SIMDE_FLOAT32_C(  -840.87), SIMDE_FLOAT32_C(   300.80) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -540.83), SIMDE_FLOAT32_C(   953.63),
                         SIMDE_FLOAT32_C(   949.44), SIMDE_FLOAT32_C(  -207.02),
                         SIMDE_FLOAT32_C(   300.80), SIMDE_FLOAT32_C(  -840.87),
                         SIMDE_FLOAT32_C(  -907.66), SIMDE_FLOAT32_C(  -239.63)) },
    { { SIMDE_FLOAT32_C(   568.29), SIMDE_FLOAT32_C(  -558.59), SIMDE_FLOAT32_C(    -1.20), SIMDE_FLOAT32_C(  -521.17) },
      { SIMDE_FLOAT32_C(   772.77), SIMDE_FLOAT32_C(  -729.14), SIMDE_FLOAT32_C(  -873.98), SIMDE_FLOAT32_C(   142.46) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -521.17), SIMDE_FLOAT32_C(    -1.20),
                         SIMDE_FLOAT32_C(  -558.59), SIMDE_FLOAT32_C(   568.29),
                         SIMDE_FLOAT32_C(   142.46), SIMDE_FLOAT32_C(  -873.98),
                         SIMDE_FLOAT32_C(  -729.14), SIMDE_FLOAT32_C(   772.77)) },
    { { SIMDE_FLOAT32_C(   499.82), SIMDE_FLOAT32_C(  -346.37), SIMDE_FLOAT32_C(   357.98), SIMDE_FLOAT32_C(  -982.20) },
      { SIMDE_FLOAT32_C(   429.05), SIMDE_FLOAT32_C(   743.13), SIMDE_FLOAT32_C(   351.79), SIMDE_FLOAT32_C(  -106.23) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -982.20), SIMDE_FLOAT32_C(   357.98),
                         SIMDE_FLOAT32_C(  -346.37), SIMDE_FLOAT32_C(   499.82),
                         SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   351.79),
                         SIMDE_FLOAT32_C(   743.13), SIMDE_FLOAT32_C(   429.05)) },
    { { SIMDE_FLOAT32_C(  -764.00), SIMDE_FLOAT32_C(   204.78), SIMDE_FLOAT32_C(   842.05), SIMDE_FLOAT32_C(   473.10) },
      { SIMDE_FLOAT32_C(  -181.50), SIMDE_FLOAT32_C(  -509.59), SIMDE_FLOAT32_C(   968.67), SIMDE_FLOAT32_C(   585.40) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   473.10), SIMDE_FLOAT32_C(   842.05),
                         SIMDE_FLOAT32_C(   204.78), SIMDE_FLOAT32_C(  -764.00),
                         SIMDE_FLOAT32_C(   585.40), SIMDE_FLOAT32_C(   968.67),
                         SIMDE_FLOAT32_C(  -509.59), SIMDE_FLOAT32_C(  -181.50)) },
    { { SIMDE_FLOAT32_C(  -248.73), SIMDE_FLOAT32_C(  -498.50), SIMDE_FLOAT32_C(  -186.56), SIMDE_FLOAT32_C(   244.41) },
      { SIMDE_FLOAT32_C(   987.29), SIMDE_FLOAT32_C(   541.99), SIMDE_FLOAT32_C(   577.71), SIMDE_FLOAT32_C(   147.41) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   244.41), SIMDE_FLOAT32_C(  -186.56),
                         SIMDE_FLOAT32_C(  -498.50), SIMDE_FLOAT32_C(  -248.73),
                         SIMDE_FLOAT32_C(   147.41), SIMDE_FLOAT32_C(   577.71),
                         SIMDE_FLOAT32_C(   541.99), SIMDE_FLOAT32_C(   987.29)) },
    { { SIMDE_FLOAT32_C(   -53.98), SIMDE_FLOAT32_C(   -59.84), SIMDE_FLOAT32_C(  -791.34), SIMDE_FLOAT32_C(     7.53) },
      { SIMDE_FLOAT32_C(     2.84), SIMDE_FLOAT32_C(   254.21), SIMDE_FLOAT32_C(   404.98), SIMDE_FLOAT32_C(  -410.67) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     7.53), SIMDE_FLOAT32_C(  -791.34),
                         SIMDE_FLOAT32_C(   -59.84), SIMDE_FLOAT32_C(   -53.98),
                         SIMDE_FLOAT32_C(  -410.67), SIMDE_FLOAT32_C(   404.98),
                         SIMDE_FLOAT32_C(   254.21), SIMDE_FLOAT32_C(     2.84)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_loadu2_m128(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a[sizeof(simde__m128d) / sizeof(simde_float64)];
    simde_float64 b[sizeof(simde__m128d) / sizeof(simde_float64)];
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(  193.14), SIMDE_FLOAT64_C( -237.27) },
      { SIMDE_FLOAT64_C(  826.89), SIMDE_FLOAT64_C( -516.49) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -237.27), SIMDE_FLOAT64_C(  193.14),
                         SIMDE_FLOAT64_C( -516.49), SIMDE_FLOAT64_C(  826.89)) },
    { { SIMDE_FLOAT64_C( -640.74), SIMDE_FLOAT64_C( -449.08) },
      { SIMDE_FLOAT64_C(  244.98), SIMDE_FLOAT64_C( -467.92) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -449.08), SIMDE_FLOAT64_C( -640.74),
                         SIMDE_FLOAT64_C( -467.92), SIMDE_FLOAT64_C(  244.98)) },
    { { SIMDE_FLOAT64_C(  384.40), SIMDE_FLOAT64_C( -595.56) },
      { SIMDE_FLOAT64_C( -808.24), SIMDE_FLOAT64_C(  198.37) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -595.56), SIMDE_FLOAT64_C(  384.40),
                         SIMDE_FLOAT64_C(  198.37), SIMDE_FLOAT64_C( -808.24)) },
    { { SIMDE_FLOAT64_C(  647.94), SIMDE_FLOAT64_C( -628.27) },
      { SIMDE_FLOAT64_C( -496.78), SIMDE_FLOAT64_C( -569.08) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -628.27), SIMDE_FLOAT64_C(  647.94),
                         SIMDE_FLOAT64_C( -569.08), SIMDE_FLOAT64_C( -496.78)) },
    { { SIMDE_FLOAT64_C(  911.82), SIMDE_FLOAT64_C( -491.30) },
      { SIMDE_FLOAT64_C(  365.77), SIMDE_FLOAT64_C( -898.74) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -491.30), SIMDE_FLOAT64_C(  911.82),
                         SIMDE_FLOAT64_C( -898.74), SIMDE_FLOAT64_C(  365.77)) },
    { { SIMDE_FLOAT64_C( -297.53), SIMDE_FLOAT64_C( -521.34) },
      { SIMDE_FLOAT64_C(  145.28), SIMDE_FLOAT64_C(  488.58) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -521.34), SIMDE_FLOAT64_C( -297.53),
                         SIMDE_FLOAT64_C(  488.58), SIMDE_FLOAT64_C(  145.28)) },
    { { SIMDE_FLOAT64_C( -224.71), SIMDE_FLOAT64_C(   -7.50) },
      { SIMDE_FLOAT64_C(  -86.35), SIMDE_FLOAT64_C(  810.88) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -7.50), SIMDE_FLOAT64_C( -224.71),
                         SIMDE_FLOAT64_C(  810.88), SIMDE_FLOAT64_C(  -86.35)) },
    { { SIMDE_FLOAT64_C(  885.68), SIMDE_FLOAT64_C( -940.09) },
      { SIMDE_FLOAT64_C( -481.99), SIMDE_FLOAT64_C( -433.50) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -940.09), SIMDE_FLOAT64_C(  885.68),
                         SIMDE_FLOAT64_C( -433.50), SIMDE_FLOAT64_C( -481.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_loadu2_m128d(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_loadu2_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(  354008351), INT32_C( 1710178598), INT32_C( 1223789711), INT32_C(-1500329554)),
      simde_mm_set_epi32(INT32_C(-1388022686), INT32_C( -390861004), INT32_C( -560834160), INT32_C( 1618430517)),
      simde_mm256_set_epi32(INT32_C(  354008351), INT32_C( 1710178598), INT32_C( 1223789711), INT32_C(-1500329554),
                            INT32_C(-1388022686), INT32_C( -390861004), INT32_C( -560834160), INT32_C( 1618430517)) },
    { simde_mm_set_epi32(INT32_C(-2097010594), INT32_C(-1953861975), INT32_C( 1525655088), INT32_C(-1479248872)),
      simde_mm_set_epi32(INT32_C( -212387035), INT32_C( -783086135), INT32_C( -464607138), INT32_C( -807907186)),
      simde_mm256_set_epi32(INT32_C(-2097010594), INT32_C(-1953861975), INT32_C( 1525655088), INT32_C(-1479248872),
                            INT32_C( -212387035), INT32_C( -783086135), INT32_C( -464607138), INT32_C( -807907186)) },
    { simde_mm_set_epi32(INT32_C( 1556453306), INT32_C( -628648157), INT32_C(-1070645220), INT32_C( 1816365112)),
      simde_mm_set_epi32(INT32_C( -449670221), INT32_C(  758539132), INT32_C(  894912628), INT32_C( 2013246533)),
      simde_mm256_set_epi32(INT32_C( 1556453306), INT32_C( -628648157), INT32_C(-1070645220), INT32_C( 1816365112),
                            INT32_C( -449670221), INT32_C(  758539132), INT32_C(  894912628), INT32_C( 2013246533)) },
    { simde_mm_set_epi32(INT32_C(  973055118), INT32_C(  267011876), INT32_C( -970751985), INT32_C( -790620326)),
      simde_mm_set_epi32(INT32_C(-1774701032), INT32_C(  110651775), INT32_C(-2029162765), INT32_C( -644927818)),
      simde_mm256_set_epi32(INT32_C(  973055118), INT32_C(  267011876), INT32_C( -970751985), INT32_C( -790620326),
                            INT32_C(-1774701032), INT32_C(  110651775), INT32_C(-2029162765), INT32_C( -644927818)) },
    { simde_mm_set_epi32(INT32_C( 1343331807), INT32_C( -752743183), INT32_C( -212726727), INT32_C(  673547091)),
      simde_mm_set_epi32(INT32_C(  510472604), INT32_C(   30606375), INT32_C(-1460649586), INT32_C( -783315263)),
      simde_mm256_set_epi32(INT32_C( 1343331807), INT32_C( -752743183), INT32_C( -212726727), INT32_C(  673547091),
                            INT32_C(  510472604), INT32_C(   30606375), INT32_C(-1460649586), INT32_C( -783315263)) },
    { simde_mm_set_epi32(INT32_C( 1773008222), INT32_C( -172973908), INT32_C( -578745695), INT32_C( 1088863920)),
      simde_mm_set_epi32(INT32_C(-2064848056), INT32_C(  207858402), INT32_C(-1299831865), INT32_C(-1364624980)),
      simde_mm256_set_epi32(INT32_C( 1773008222), INT32_C( -172973908), INT32_C( -578745695), INT32_C( 1088863920),
                            INT32_C(-2064848056), INT32_C(  207858402), INT32_C(-1299831865), INT32_C(-1364624980)) },
    { simde_mm_set_epi32(INT32_C( -608977283), INT32_C(-1563798803), INT32_C(-1827655569), INT32_C( -382597224)),
      simde_mm_set_epi32(INT32_C(-1788804177), INT32_C(-1217503299), INT32_C(   57159833), INT32_C(  -53652220)),
      simde_mm256_set_epi32(INT32_C( -608977283), INT32_C(-1563798803), INT32_C(-1827655569), INT32_C( -382597224),
                            INT32_C(-1788804177), INT32_C(-1217503299), INT32_C(   57159833), INT32_C(  -53652220)) },
    { simde_mm_set_epi32(INT32_C( 2096190829), INT32_C(  255970451), INT32_C( 2016421031), INT32_C( -950647181)),
      simde_mm_set_epi32(INT32_C( -133085873), INT32_C(-1605552420), INT32_C( -147782601), INT32_C( -870212282)),
      simde_mm256_set_epi32(INT32_C( 2096190829), INT32_C(  255970451), INT32_C( 2016421031), INT32_C( -950647181),
                            INT32_C( -133085873), INT32_C(-1605552420), INT32_C( -147782601), INT32_C( -870212282)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_loadu2_m128i(&(test_vec[i].a), &(test_vec[i].b));
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskload_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN_AS(16, simde__m128) simde_float64 a[sizeof(simde__m128) / sizeof(simde_float64)];
    simde__m128i mask;
    simde__m128d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C( -538.57), SIMDE_FLOAT64_C(  -11.46) },
      simde_mm_set_epi64x(INT64_C(-9017751799918590017), INT64_C(-5501772696658696646)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -11.46), SIMDE_FLOAT64_C( -538.57)) },
    { { SIMDE_FLOAT64_C( -641.37), SIMDE_FLOAT64_C(   64.21) },
      simde_mm_set_epi64x(INT64_C( 3369893883355791274), INT64_C( 1336077705062666411)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -814.84), SIMDE_FLOAT64_C(  -39.12) },
      simde_mm_set_epi64x(INT64_C( -175773991823241704), INT64_C( 6120573636597284743)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -39.12), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -476.96), SIMDE_FLOAT64_C( -478.18) },
      simde_mm_set_epi64x(INT64_C( 4690248076557898109), INT64_C(-4266881794966063516)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -476.96)) },
    { { SIMDE_FLOAT64_C(  985.57), SIMDE_FLOAT64_C( -476.52) },
      simde_mm_set_epi64x(INT64_C( 4222817080399977593), INT64_C( 8206214779752167639)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -802.47), SIMDE_FLOAT64_C(  146.97) },
      simde_mm_set_epi64x(INT64_C(-5692044190455390660), INT64_C(-8533965121569475071)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  146.97), SIMDE_FLOAT64_C( -802.47)) },
    { { SIMDE_FLOAT64_C(   45.00), SIMDE_FLOAT64_C(  173.91) },
      simde_mm_set_epi64x(INT64_C(-2144009867794184728), INT64_C( 8971533173921860714)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  173.91), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C(  719.52), SIMDE_FLOAT64_C( -212.42) },
      simde_mm_set_epi64x(INT64_C(  621556199349545261), INT64_C( 7304654265079802349)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_maskload_pd(test_vec[i].a, test_vec[i].mask);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskload_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN_AS(32, simde__m256d) simde_float64 a[sizeof(simde__m256d) / sizeof(simde_float64)];
    simde__m256i mask;
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C( -742.80), SIMDE_FLOAT64_C( -304.64),
        SIMDE_FLOAT64_C( -396.27), SIMDE_FLOAT64_C(  355.76) },
      simde_mm256_set_epi64x(INT64_C( 4071980571380202090), INT64_C( 6721554273116684789),
                             INT64_C( 4717796242123824292), INT64_C( 3729843393737950292)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -514.90), SIMDE_FLOAT64_C(  662.93),
        SIMDE_FLOAT64_C( -919.62), SIMDE_FLOAT64_C(  282.13) },
      simde_mm256_set_epi64x(INT64_C(-1474100978480931658), INT64_C(  785949451008475287),
                             INT64_C( -474172885564190225), INT64_C( 4848240700454505058)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  282.13), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  662.93), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C(   35.69), SIMDE_FLOAT64_C( -641.22),
        SIMDE_FLOAT64_C( -465.53), SIMDE_FLOAT64_C(  572.28) },
      simde_mm256_set_epi64x(INT64_C( 4128095662430017309), INT64_C( 6705808167706949150),
                             INT64_C(-6324610130247810694), INT64_C( 5912417394960517664)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -641.22), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -368.99), SIMDE_FLOAT64_C(  756.90),
        SIMDE_FLOAT64_C(   27.12), SIMDE_FLOAT64_C(  420.25) },
      simde_mm256_set_epi64x(INT64_C( 8013574521919499409), INT64_C(-1110549801744899582),
                             INT64_C(-6909462128779075108), INT64_C(-5215868231346481394)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   27.12),
                         SIMDE_FLOAT64_C(  756.90), SIMDE_FLOAT64_C( -368.99)) },
    { { SIMDE_FLOAT64_C(   60.76), SIMDE_FLOAT64_C( -377.85),
        SIMDE_FLOAT64_C( -246.15), SIMDE_FLOAT64_C(  904.02) },
      simde_mm256_set_epi64x(INT64_C(-6252993179686435401), INT64_C(-6222176361525742304),
                             INT64_C( 1568873442565098273), INT64_C(-2646512981403531561)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  904.02), SIMDE_FLOAT64_C( -246.15),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   60.76)) },
    { { SIMDE_FLOAT64_C(  473.35), SIMDE_FLOAT64_C( -512.10),
        SIMDE_FLOAT64_C(  840.64), SIMDE_FLOAT64_C(  335.07) },
      simde_mm256_set_epi64x(INT64_C(-4342406725980980796), INT64_C( 4316001481728249841),
                             INT64_C(-5762940000286803356), INT64_C( 1630787670649577947)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  335.07), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -512.10), SIMDE_FLOAT64_C(    0.00)) },
    { { SIMDE_FLOAT64_C( -768.36), SIMDE_FLOAT64_C(  875.80),
        SIMDE_FLOAT64_C(  655.66), SIMDE_FLOAT64_C( -654.72) },
      simde_mm256_set_epi64x(INT64_C(-1458032190732153407), INT64_C(-6962041223442936959),
                             INT64_C( 5580150308320821369), INT64_C(-2943615932930424860)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -654.72), SIMDE_FLOAT64_C(  655.66),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -768.36)) },
    { { SIMDE_FLOAT64_C( -596.56), SIMDE_FLOAT64_C(  -29.90),
        SIMDE_FLOAT64_C(  952.73), SIMDE_FLOAT64_C(  820.08) },
      simde_mm256_set_epi64x(INT64_C( 2126361914499801021), INT64_C(-4173624423068301374),
                             INT64_C( 2526062043756015814), INT64_C(-1857778675173237324)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(  952.73),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C( -596.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_maskload_pd(test_vec[i].a, test_vec[i].mask);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskload_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN_AS(32, simde__m128) simde_float32 a[sizeof(simde__m128) / sizeof(simde_float32)];
    simde__m128i mask;
    simde__m128 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(   238.88), SIMDE_FLOAT32_C(   -33.02),
        SIMDE_FLOAT32_C(  -437.92), SIMDE_FLOAT32_C(  -101.59) },
      simde_mm_set_epi32(INT32_C(  373241754), INT32_C(-1241699397), INT32_C(-2020705997), INT32_C(-2007250138)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -437.92),
                      SIMDE_FLOAT32_C(   -33.02), SIMDE_FLOAT32_C(   238.88)) },
    { { SIMDE_FLOAT32_C(    96.24), SIMDE_FLOAT32_C(  -879.01),
        SIMDE_FLOAT32_C(   368.28), SIMDE_FLOAT32_C(   665.38) },
      simde_mm_set_epi32(INT32_C( 1837649408), INT32_C( 1503609090), INT32_C( -125079359), INT32_C(  877124431)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                      SIMDE_FLOAT32_C(  -879.01), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(  -453.25), SIMDE_FLOAT32_C(   745.86),
        SIMDE_FLOAT32_C(  -712.88), SIMDE_FLOAT32_C(  -621.74) },
      simde_mm_set_epi32(INT32_C( 1849190327), INT32_C(-1060272907), INT32_C(  674926787), INT32_C( 1596024266)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -712.88),
                      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(   308.88), SIMDE_FLOAT32_C(   291.85),
        SIMDE_FLOAT32_C(  -677.80), SIMDE_FLOAT32_C(    44.62) },
      simde_mm_set_epi32(INT32_C(  881057698), INT32_C( -209775842), INT32_C(-2093831398), INT32_C( 1667988466)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -677.80),
                      SIMDE_FLOAT32_C(   291.85), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(  -906.08), SIMDE_FLOAT32_C(   237.44),
        SIMDE_FLOAT32_C(  -418.96), SIMDE_FLOAT32_C(  -339.76) },
      simde_mm_set_epi32(INT32_C(-1844913619), INT32_C(-2122500835), INT32_C( -518224422), INT32_C(-1131970930)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -339.76), SIMDE_FLOAT32_C(  -418.96),
                      SIMDE_FLOAT32_C(   237.44), SIMDE_FLOAT32_C(  -906.08)) },
    { { SIMDE_FLOAT32_C(   843.17), SIMDE_FLOAT32_C(  -793.80),
        SIMDE_FLOAT32_C(  -798.92), SIMDE_FLOAT32_C(   651.44) },
      simde_mm_set_epi32(INT32_C(-1461381000), INT32_C( 1314511128), INT32_C( 1084742428), INT32_C(  481018738)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   651.44), SIMDE_FLOAT32_C(     0.00),
                      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(   178.10), SIMDE_FLOAT32_C(  -561.96),
        SIMDE_FLOAT32_C(  -999.47), SIMDE_FLOAT32_C(  -911.06) },
      simde_mm_set_epi32(INT32_C( 1019312153), INT32_C(  586722973), INT32_C(  624149170), INT32_C(-1687322738)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   178.10)) },
    { { SIMDE_FLOAT32_C(   -32.99), SIMDE_FLOAT32_C(   985.78),
        SIMDE_FLOAT32_C(   524.46), SIMDE_FLOAT32_C(  -571.82) },
      simde_mm_set_epi32(INT32_C( 1258594112), INT32_C( 1828944398), INT32_C(  600534056), INT32_C(-1605644363)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -32.99)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_maskload_ps(test_vec[i].a, test_vec[i].mask);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskload_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    SIMDE_ALIGN_AS(32, simde__m256) simde_float32 a[sizeof(simde__m256) / sizeof(simde_float32)];
    simde__m256i mask;
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -498.36), SIMDE_FLOAT32_C(   518.00),
        SIMDE_FLOAT32_C(   921.61), SIMDE_FLOAT32_C(    88.59),
        SIMDE_FLOAT32_C(   740.00), SIMDE_FLOAT32_C(   873.65),
        SIMDE_FLOAT32_C(   464.81), SIMDE_FLOAT32_C(   -13.79) },
      simde_mm256_set_epi32(INT32_C( 1126353735), INT32_C(  484340645), INT32_C( -204363389), INT32_C(-1370799423),
                            INT32_C( -443538278), INT32_C( 1458045182), INT32_C( 1256590829), INT32_C(  300941504)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   873.65), SIMDE_FLOAT32_C(   740.00),
                         SIMDE_FLOAT32_C(    88.59), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(  -722.38), SIMDE_FLOAT32_C(   854.98),
        SIMDE_FLOAT32_C(   292.96), SIMDE_FLOAT32_C(   378.96),
        SIMDE_FLOAT32_C(   774.84), SIMDE_FLOAT32_C(   276.85),
        SIMDE_FLOAT32_C(   697.63), SIMDE_FLOAT32_C(  -283.41) },
      simde_mm256_set_epi32(INT32_C( -450215514), INT32_C(-1503484739), INT32_C(-1564727340), INT32_C(  545680781),
                            INT32_C(-1078784217), INT32_C( -952242442), INT32_C(  978340536), INT32_C(-1506302314)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -283.41), SIMDE_FLOAT32_C(   697.63),
                         SIMDE_FLOAT32_C(   276.85), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   378.96), SIMDE_FLOAT32_C(   292.96),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -722.38)) },
    { { SIMDE_FLOAT32_C(  -482.92), SIMDE_FLOAT32_C(  -871.87),
        SIMDE_FLOAT32_C(   -49.55), SIMDE_FLOAT32_C(  -353.52),
        SIMDE_FLOAT32_C(  -663.89), SIMDE_FLOAT32_C(   506.78),
        SIMDE_FLOAT32_C(  -791.60), SIMDE_FLOAT32_C(   244.78) },
      simde_mm256_set_epi32(INT32_C( 1040523516), INT32_C(-1050539254), INT32_C(-1026234973), INT32_C(-1175306773),
                            INT32_C( 2014700388), INT32_C( 1292358485), INT32_C( -289050973), INT32_C( 1933552616)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -791.60),
                         SIMDE_FLOAT32_C(   506.78), SIMDE_FLOAT32_C(  -663.89),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -871.87), SIMDE_FLOAT32_C(     0.00)) },
    { { SIMDE_FLOAT32_C(  -539.06), SIMDE_FLOAT32_C(  -905.50),
        SIMDE_FLOAT32_C(   900.23), SIMDE_FLOAT32_C(  -396.92),
        SIMDE_FLOAT32_C(  -499.54), SIMDE_FLOAT32_C(  -633.84),
        SIMDE_FLOAT32_C(   958.22), SIMDE_FLOAT32_C(   647.81) },
      simde_mm256_set_epi32(INT32_C(  882904777), INT32_C( -175107992), INT32_C(  975911934), INT32_C(  675138288),
                            INT32_C(  603182614), INT32_C( 2060191940), INT32_C( -127171073), INT32_C( -360031784)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   958.22),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -905.50), SIMDE_FLOAT32_C(  -539.06)) },
    { { SIMDE_FLOAT32_C(    99.57), SIMDE_FLOAT32_C(  -670.39),
        SIMDE_FLOAT32_C(   -60.02), SIMDE_FLOAT32_C(   499.74),
        SIMDE_FLOAT32_C(   -41.22), SIMDE_FLOAT32_C(   369.53),
        SIMDE_FLOAT32_C(   242.88), SIMDE_FLOAT32_C(   154.72) },
      simde_mm256_set_epi32(INT32_C( 1778816602), INT32_C( -463622568), INT32_C(-1894986380), INT32_C(  488060271),
                            INT32_C(-2015801359), INT32_C( -100310138), INT32_C( -147358371), INT32_C(-1833605867)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   242.88),
                         SIMDE_FLOAT32_C(   369.53), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   499.74), SIMDE_FLOAT32_C(   -60.02),
                         SIMDE_FLOAT32_C(  -670.39), SIMDE_FLOAT32_C(    99.57)) },
    { { SIMDE_FLOAT32_C(  -900.31), SIMDE_FLOAT32_C(   482.56),
        SIMDE_FLOAT32_C(   149.15), SIMDE_FLOAT32_C(  -541.63),
        SIMDE_FLOAT32_C(   308.58), SIMDE_FLOAT32_C(  -754.37),
        SIMDE_FLOAT32_C(  -542.63), SIMDE_FLOAT32_C(    62.23) },
      simde_mm256_set_epi32(INT32_C(-1970206334), INT32_C(  921523603), INT32_C( 1362605060), INT32_C( 1654272009),
                            INT32_C( -837503862), INT32_C(-2123350492), INT32_C(  -98405346), INT32_C(-1139506011)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    62.23), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -541.63), SIMDE_FLOAT32_C(   149.15),
                         SIMDE_FLOAT32_C(   482.56), SIMDE_FLOAT32_C(  -900.31)) },
    { { SIMDE_FLOAT32_C(  -554.63), SIMDE_FLOAT32_C(  -627.48),
        SIMDE_FLOAT32_C(   740.07), SIMDE_FLOAT32_C(   115.83),
        SIMDE_FLOAT32_C(   488.58), SIMDE_FLOAT32_C(   151.81),
        SIMDE_FLOAT32_C(  -631.98), SIMDE_FLOAT32_C(  -425.34) },
      simde_mm256_set_epi32(INT32_C( -732532869), INT32_C( -300747863), INT32_C( -999632451), INT32_C(-1670016341),
                            INT32_C( 1243460650), INT32_C(-1069820224), INT32_C(  444722836), INT32_C(-1288346892)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -425.34), SIMDE_FLOAT32_C(  -631.98),
                         SIMDE_FLOAT32_C(   151.81), SIMDE_FLOAT32_C(   488.58),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   740.07),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -554.63)) },
    { { SIMDE_FLOAT32_C(   896.14), SIMDE_FLOAT32_C(   562.36),
        SIMDE_FLOAT32_C(   177.20), SIMDE_FLOAT32_C(   879.89),
        SIMDE_FLOAT32_C(  -856.93), SIMDE_FLOAT32_C(  -464.55),
        SIMDE_FLOAT32_C(   714.56), SIMDE_FLOAT32_C(    -9.58) },
      simde_mm256_set_epi32(INT32_C( -743537150), INT32_C( 1484159593), INT32_C(-1561251112), INT32_C(  857122953),
                            INT32_C(-1211524150), INT32_C( 1341368510), INT32_C( 1095760414), INT32_C( 1510181093)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -9.58), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(  -464.55), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(   879.89), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_maskload_ps(test_vec[i].a, test_vec[i].mask);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskstore_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i mask;
    double ri[2];
    double ro[2];
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  291.40), SIMDE_FLOAT64_C( -747.46)),
      simde_mm_set_epi64x(INT64_C( -901196363302656956), INT64_C(  423467829629286510)),
      { SIMDE_FLOAT64_C( -279.11), SIMDE_FLOAT64_C( -707.31) },
      { SIMDE_FLOAT64_C( -279.11), SIMDE_FLOAT64_C(  291.40) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   36.11), SIMDE_FLOAT64_C( -279.03)),
      simde_mm_set_epi64x(INT64_C(-5374148835716618800), INT64_C( 4687824648494664977)),
      { SIMDE_FLOAT64_C( -513.32), SIMDE_FLOAT64_C(  997.01) },
      { SIMDE_FLOAT64_C( -513.32), SIMDE_FLOAT64_C(   36.11) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  252.18), SIMDE_FLOAT64_C( -396.70)),
      simde_mm_set_epi64x(INT64_C(-2340838553401196290), INT64_C(-8255671198755410933)),
      { SIMDE_FLOAT64_C( -313.87), SIMDE_FLOAT64_C(  648.77) },
      { SIMDE_FLOAT64_C( -396.70), SIMDE_FLOAT64_C(  252.18) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -154.32), SIMDE_FLOAT64_C(  707.71)),
      simde_mm_set_epi64x(INT64_C( -336577207510206055), INT64_C(-8731515008786621717)),
      { SIMDE_FLOAT64_C( -956.34), SIMDE_FLOAT64_C(  661.79) },
      { SIMDE_FLOAT64_C(  707.71), SIMDE_FLOAT64_C( -154.32) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -482.35), SIMDE_FLOAT64_C(  870.14)),
      simde_mm_set_epi64x(INT64_C(-6428326320006280400), INT64_C( 2370968363897859860)),
      { SIMDE_FLOAT64_C(  -88.00), SIMDE_FLOAT64_C( -393.63) },
      { SIMDE_FLOAT64_C(  -88.00), SIMDE_FLOAT64_C( -482.35) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -798.76), SIMDE_FLOAT64_C(  378.53)),
      simde_mm_set_epi64x(INT64_C( 2158346412704669322), INT64_C(-1741710562990070947)),
      { SIMDE_FLOAT64_C( -459.19), SIMDE_FLOAT64_C( -261.60) },
      { SIMDE_FLOAT64_C(  378.53), SIMDE_FLOAT64_C( -261.60) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   47.39), SIMDE_FLOAT64_C(  457.82)),
      simde_mm_set_epi64x(INT64_C( 3118706775454689373), INT64_C(-4723277293636004112)),
      { SIMDE_FLOAT64_C( -206.48), SIMDE_FLOAT64_C(  663.61) },
      { SIMDE_FLOAT64_C(  457.82), SIMDE_FLOAT64_C(  663.61) } },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -497.78), SIMDE_FLOAT64_C(  -27.40)),
      simde_mm_set_epi64x(INT64_C(-5481981628135809029), INT64_C(-7037919562781567894)),
      { SIMDE_FLOAT64_C(   54.28), SIMDE_FLOAT64_C(  -36.05) },
      { SIMDE_FLOAT64_C(  -27.40), SIMDE_FLOAT64_C( -497.78) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    double r[2] = { test_vec[i].ri[0], test_vec[i].ri[1], };
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm_maskstore_pd(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, sizeof(r) / sizeof(r[0]), r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskstore_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256i mask;
    simde_float64 ri[4];
    simde_float64 ro[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  256.10), SIMDE_FLOAT64_C(  343.75),
                         SIMDE_FLOAT64_C( -441.90), SIMDE_FLOAT64_C(  609.80)),
      simde_mm256_set_epi64x(INT64_C( 4260458650207424972), INT64_C( 7445494124920454187),
                             INT64_C( 3286955945790099662), INT64_C(-7285974739268381254)),
      { SIMDE_FLOAT64_C( -289.65), SIMDE_FLOAT64_C(  426.76),
        SIMDE_FLOAT64_C(   -9.11), SIMDE_FLOAT64_C( -274.93) },
      { SIMDE_FLOAT64_C(  609.80), SIMDE_FLOAT64_C(  426.76),
        SIMDE_FLOAT64_C(   -9.11), SIMDE_FLOAT64_C( -274.93) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  571.67), SIMDE_FLOAT64_C(  518.20),
                         SIMDE_FLOAT64_C(  -98.22), SIMDE_FLOAT64_C( -751.94)),
      simde_mm256_set_epi64x(INT64_C( 1638253588391173148), INT64_C( 1793291230565330203),
                             INT64_C(-9111784699029565866), INT64_C( -227326109536357972)),
      { SIMDE_FLOAT64_C( -486.54), SIMDE_FLOAT64_C(  729.14),
        SIMDE_FLOAT64_C( -705.07), SIMDE_FLOAT64_C( -433.33) },
      { SIMDE_FLOAT64_C( -751.94), SIMDE_FLOAT64_C(  -98.22),
        SIMDE_FLOAT64_C( -705.07), SIMDE_FLOAT64_C( -433.33) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  102.13), SIMDE_FLOAT64_C( -818.78),
                         SIMDE_FLOAT64_C( -736.90), SIMDE_FLOAT64_C( -616.20)),
      simde_mm256_set_epi64x(INT64_C(-2892759574131760065), INT64_C(-3440936018861750870),
                             INT64_C( -525494054977382250), INT64_C(-2782562282709585632)),
      { SIMDE_FLOAT64_C( -465.13), SIMDE_FLOAT64_C(  232.40),
        SIMDE_FLOAT64_C( -478.53), SIMDE_FLOAT64_C(  -53.86) },
      { SIMDE_FLOAT64_C( -616.20), SIMDE_FLOAT64_C( -736.90),
        SIMDE_FLOAT64_C( -818.78), SIMDE_FLOAT64_C(  102.13) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  748.35), SIMDE_FLOAT64_C(  412.39),
                         SIMDE_FLOAT64_C(  180.73), SIMDE_FLOAT64_C( -772.53)),
      simde_mm256_set_epi64x(INT64_C(-7252528024816875961), INT64_C( 3768666429054031776),
                             INT64_C(-5502653220660844988), INT64_C( 6869378166726947276)),
      { SIMDE_FLOAT64_C( -276.66), SIMDE_FLOAT64_C( -248.39),
        SIMDE_FLOAT64_C( -589.21), SIMDE_FLOAT64_C(  826.33) },
      { SIMDE_FLOAT64_C( -276.66), SIMDE_FLOAT64_C(  180.73),
        SIMDE_FLOAT64_C( -589.21), SIMDE_FLOAT64_C(  748.35) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  837.77), SIMDE_FLOAT64_C(  582.83),
                         SIMDE_FLOAT64_C(  901.95), SIMDE_FLOAT64_C(  440.28)),
      simde_mm256_set_epi64x(INT64_C( 7132263712774217761), INT64_C( 7513359651930322343),
                             INT64_C( 7271276353319921669), INT64_C(-6353645951073475265)),
      { SIMDE_FLOAT64_C(  194.29), SIMDE_FLOAT64_C( -702.43),
        SIMDE_FLOAT64_C(  663.08), SIMDE_FLOAT64_C( -837.37) },
      { SIMDE_FLOAT64_C(  440.28), SIMDE_FLOAT64_C( -702.43),
        SIMDE_FLOAT64_C(  663.08), SIMDE_FLOAT64_C( -837.37) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -476.01), SIMDE_FLOAT64_C(  964.03),
                         SIMDE_FLOAT64_C( -620.01), SIMDE_FLOAT64_C( -190.51)),
      simde_mm256_set_epi64x(INT64_C(-6904573933630117437), INT64_C( 8435505992452950995),
                             INT64_C(-2030909113789010322), INT64_C(-3516031824252737762)),
      { SIMDE_FLOAT64_C(  412.73), SIMDE_FLOAT64_C( -375.82),
        SIMDE_FLOAT64_C(  493.97), SIMDE_FLOAT64_C( -325.91) },
      { SIMDE_FLOAT64_C( -190.51), SIMDE_FLOAT64_C( -620.01),
        SIMDE_FLOAT64_C(  493.97), SIMDE_FLOAT64_C( -476.01) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  109.41), SIMDE_FLOAT64_C( -105.03),
                         SIMDE_FLOAT64_C(  942.38), SIMDE_FLOAT64_C(  492.62)),
      simde_mm256_set_epi64x(INT64_C(-4507038716603653937), INT64_C(-5597740526711762453),
                             INT64_C(-4892847490676269188), INT64_C(-2050275303632712946)),
      { SIMDE_FLOAT64_C(  999.52), SIMDE_FLOAT64_C(   91.29),
        SIMDE_FLOAT64_C( -389.17), SIMDE_FLOAT64_C( -828.90) },
      { SIMDE_FLOAT64_C(  492.62), SIMDE_FLOAT64_C(  942.38),
        SIMDE_FLOAT64_C( -105.03), SIMDE_FLOAT64_C(  109.41) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -984.18), SIMDE_FLOAT64_C(  526.23),
                         SIMDE_FLOAT64_C(  210.69), SIMDE_FLOAT64_C( -960.42)),
      simde_mm256_set_epi64x(INT64_C(-2327918596051776606), INT64_C(-6284034566091225578),
                             INT64_C( 5326594562181579270), INT64_C( 7458656096830697285)),
      { SIMDE_FLOAT64_C(  719.28), SIMDE_FLOAT64_C( -272.00),
        SIMDE_FLOAT64_C( -305.09), SIMDE_FLOAT64_C(  995.54) },
      { SIMDE_FLOAT64_C(  719.28), SIMDE_FLOAT64_C( -272.00),
        SIMDE_FLOAT64_C(  526.23), SIMDE_FLOAT64_C( -984.18) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r[4];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm256_maskstore_pd(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, sizeof(r) / sizeof(r[0]), r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_maskstore_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i mask;
    simde_float32 ri[4];
    simde_float32 ro[4];
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  674.56), SIMDE_FLOAT32_C( -800.90), SIMDE_FLOAT32_C( -515.11), SIMDE_FLOAT32_C(  918.12)),
      simde_mm_set_epi32(INT32_C( 1108579007), INT32_C( 1980053353), INT32_C( 1803323457), INT32_C( -407836103)),
      { SIMDE_FLOAT32_C( -619.39), SIMDE_FLOAT32_C( -235.61), SIMDE_FLOAT32_C( -100.19), SIMDE_FLOAT32_C(  132.85) },
      { SIMDE_FLOAT32_C(  918.12), SIMDE_FLOAT32_C( -235.61), SIMDE_FLOAT32_C( -100.19), SIMDE_FLOAT32_C(  132.85) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -921.95), SIMDE_FLOAT32_C( -150.48), SIMDE_FLOAT32_C(  -68.61), SIMDE_FLOAT32_C(  516.22)),
      simde_mm_set_epi32(INT32_C(  992186029), INT32_C( 1116343160), INT32_C(  312629428), INT32_C( -102955009)),
      { SIMDE_FLOAT32_C(  590.22), SIMDE_FLOAT32_C(   90.53), SIMDE_FLOAT32_C(  -38.56), SIMDE_FLOAT32_C(  730.28) },
      { SIMDE_FLOAT32_C(  516.22), SIMDE_FLOAT32_C(   90.53), SIMDE_FLOAT32_C(  -38.56), SIMDE_FLOAT32_C(  730.28) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -641.93), SIMDE_FLOAT32_C(  207.52), SIMDE_FLOAT32_C( -794.64), SIMDE_FLOAT32_C(  604.13)),
      simde_mm_set_epi32(INT32_C( -917957115), INT32_C( 1866845223), INT32_C(  844085971), INT32_C( -482023893)),
      { SIMDE_FLOAT32_C( -925.57), SIMDE_FLOAT32_C(    8.11), SIMDE_FLOAT32_C( -375.92), SIMDE_FLOAT32_C( -370.15) },
      { SIMDE_FLOAT32_C(  604.13), SIMDE_FLOAT32_C(    8.11), SIMDE_FLOAT32_C( -375.92), SIMDE_FLOAT32_C( -641.93) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  805.10), SIMDE_FLOAT32_C( -153.46), SIMDE_FLOAT32_C(  308.00), SIMDE_FLOAT32_C( -159.40)),
      simde_mm_set_epi32(INT32_C( -582979650), INT32_C( 2118735836), INT32_C( -687047741), INT32_C( -848367450)),
      { SIMDE_FLOAT32_C(  678.23), SIMDE_FLOAT32_C(  517.86), SIMDE_FLOAT32_C(  930.59), SIMDE_FLOAT32_C( -376.44) },
      { SIMDE_FLOAT32_C( -159.40), SIMDE_FLOAT32_C(  308.00), SIMDE_FLOAT32_C(  930.59), SIMDE_FLOAT32_C(  805.10) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  286.93), SIMDE_FLOAT32_C( -263.99), SIMDE_FLOAT32_C( -966.59), SIMDE_FLOAT32_C( -652.85)),
      simde_mm_set_epi32(INT32_C( -773117066), INT32_C(-1995762340), INT32_C(-1086112436), INT32_C(  352565673)),
      { SIMDE_FLOAT32_C( -243.02), SIMDE_FLOAT32_C(  -10.35), SIMDE_FLOAT32_C( -930.64), SIMDE_FLOAT32_C( -942.71) },
      { SIMDE_FLOAT32_C( -243.02), SIMDE_FLOAT32_C( -966.59), SIMDE_FLOAT32_C( -263.99), SIMDE_FLOAT32_C(  286.93) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  695.71), SIMDE_FLOAT32_C(  544.01), SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C(  773.52)),
      simde_mm_set_epi32(INT32_C( 2130523937), INT32_C(  959365319), INT32_C(  -87305215), INT32_C(  336137071)),
      { SIMDE_FLOAT32_C(  331.75), SIMDE_FLOAT32_C(  641.50), SIMDE_FLOAT32_C( -114.90), SIMDE_FLOAT32_C(  582.07) },
      { SIMDE_FLOAT32_C(  331.75), SIMDE_FLOAT32_C( -155.11), SIMDE_FLOAT32_C( -114.90), SIMDE_FLOAT32_C(  582.07) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -51.27), SIMDE_FLOAT32_C(  493.10), SIMDE_FLOAT32_C( -182.48), SIMDE_FLOAT32_C( -902.32)),
      simde_mm_set_epi32(INT32_C( -776181519), INT32_C(-1636897440), INT32_C( -492655883), INT32_C(-1758902344)),
      { SIMDE_FLOAT32_C(  -81.09), SIMDE_FLOAT32_C( -980.86), SIMDE_FLOAT32_C( -619.01), SIMDE_FLOAT32_C( -490.33) },
      { SIMDE_FLOAT32_C( -902.32), SIMDE_FLOAT32_C( -182.48), SIMDE_FLOAT32_C(  493.10), SIMDE_FLOAT32_C(  -51.27) } },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  432.35), SIMDE_FLOAT32_C(  341.26), SIMDE_FLOAT32_C(  183.18), SIMDE_FLOAT32_C( -136.49)),
      simde_mm_set_epi32(INT32_C( 1637126517), INT32_C(-1887081950), INT32_C( 1956680612), INT32_C( 1224753500)),
      { SIMDE_FLOAT32_C( -471.44), SIMDE_FLOAT32_C(  241.66), SIMDE_FLOAT32_C(  -19.61), SIMDE_FLOAT32_C( -311.97) },
      { SIMDE_FLOAT32_C( -471.44), SIMDE_FLOAT32_C(  241.66), SIMDE_FLOAT32_C(  341.26), SIMDE_FLOAT32_C( -311.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[4];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm_maskstore_ps(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_f32v_equal(simde_float32, sizeof(r) / sizeof(r[0]), r, test_vec[i].ro, 1);
    simde_assert_f32v_close(simde_float32, 4, r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_maskstore_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i mask;
    simde_float32 ri[8];
    simde_float32 ro[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   631.62), SIMDE_FLOAT32_C(  -891.94),
                         SIMDE_FLOAT32_C(  -689.27), SIMDE_FLOAT32_C(   347.81),
                         SIMDE_FLOAT32_C(  -616.22), SIMDE_FLOAT32_C(   642.58),
                         SIMDE_FLOAT32_C(   228.19), SIMDE_FLOAT32_C(  -205.29)),
      simde_mm256_set_epi32(INT32_C(  295073064), INT32_C(  716384814), INT32_C(  546124227), INT32_C( -305648391),
                            INT32_C(-1290025628), INT32_C(-1970079627), INT32_C( -571027584), INT32_C(  423261258)),
      { SIMDE_FLOAT32_C(  -608.38), SIMDE_FLOAT32_C(   456.15),
        SIMDE_FLOAT32_C(   520.16), SIMDE_FLOAT32_C(   784.51),
        SIMDE_FLOAT32_C(   874.80), SIMDE_FLOAT32_C(  -683.96),
        SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -304.46) },
      { SIMDE_FLOAT32_C(  -608.38), SIMDE_FLOAT32_C(   228.19),
        SIMDE_FLOAT32_C(   642.58), SIMDE_FLOAT32_C(  -616.22),
        SIMDE_FLOAT32_C(   347.81), SIMDE_FLOAT32_C(  -683.96),
        SIMDE_FLOAT32_C(  -492.84), SIMDE_FLOAT32_C(  -304.46) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   410.61), SIMDE_FLOAT32_C(  -548.69),
                         SIMDE_FLOAT32_C(  -844.69), SIMDE_FLOAT32_C(   115.46),
                         SIMDE_FLOAT32_C(  -883.40), SIMDE_FLOAT32_C(  -942.83),
                         SIMDE_FLOAT32_C(   299.17), SIMDE_FLOAT32_C(   463.83)),
      simde_mm256_set_epi32(INT32_C(  162007636), INT32_C( 1372837309), INT32_C( 1276687632), INT32_C(-1819337795),
                            INT32_C(-2027923298), INT32_C(  531821300), INT32_C( 1062735782), INT32_C( -103135294)),
      { SIMDE_FLOAT32_C(  -186.23), SIMDE_FLOAT32_C(   411.88),
        SIMDE_FLOAT32_C(  -764.36), SIMDE_FLOAT32_C(   765.54),
        SIMDE_FLOAT32_C(  -288.35), SIMDE_FLOAT32_C(   486.60),
        SIMDE_FLOAT32_C(  -405.36), SIMDE_FLOAT32_C(   812.05) },
      { SIMDE_FLOAT32_C(   463.83), SIMDE_FLOAT32_C(   411.88),
        SIMDE_FLOAT32_C(  -764.36), SIMDE_FLOAT32_C(  -883.40),
        SIMDE_FLOAT32_C(   115.46), SIMDE_FLOAT32_C(   486.60),
        SIMDE_FLOAT32_C(  -405.36), SIMDE_FLOAT32_C(   812.05) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -783.01), SIMDE_FLOAT32_C(  -741.62),
                         SIMDE_FLOAT32_C(  -384.48), SIMDE_FLOAT32_C(   584.48),
                         SIMDE_FLOAT32_C(  -995.40), SIMDE_FLOAT32_C(  -545.74),
                         SIMDE_FLOAT32_C(  -304.24), SIMDE_FLOAT32_C(   611.74)),
      simde_mm256_set_epi32(INT32_C(-1838874946), INT32_C(-2030629043), INT32_C(   38494100), INT32_C(   -7221084),
                            INT32_C(-1092763998), INT32_C(   39946466), INT32_C( -239157020), INT32_C(-1142390879)),
      { SIMDE_FLOAT32_C(  -415.76), SIMDE_FLOAT32_C(   542.61),
        SIMDE_FLOAT32_C(   568.26), SIMDE_FLOAT32_C(   280.16),
        SIMDE_FLOAT32_C(   662.20), SIMDE_FLOAT32_C(   -14.92),
        SIMDE_FLOAT32_C(   639.71), SIMDE_FLOAT32_C(  -773.09) },
      { SIMDE_FLOAT32_C(   611.74), SIMDE_FLOAT32_C(  -304.24),
        SIMDE_FLOAT32_C(   568.26), SIMDE_FLOAT32_C(  -995.40),
        SIMDE_FLOAT32_C(   584.48), SIMDE_FLOAT32_C(   -14.92),
        SIMDE_FLOAT32_C(  -741.62), SIMDE_FLOAT32_C(  -783.01) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   921.86), SIMDE_FLOAT32_C(  -688.86),
                         SIMDE_FLOAT32_C(    43.96), SIMDE_FLOAT32_C(   754.20),
                         SIMDE_FLOAT32_C(  -480.27), SIMDE_FLOAT32_C(  -645.94),
                         SIMDE_FLOAT32_C(   315.20), SIMDE_FLOAT32_C(   726.23)),
      simde_mm256_set_epi32(INT32_C( -956355020), INT32_C( -805184504), INT32_C(   -5391233), INT32_C(  154150621),
                            INT32_C( -322849130), INT32_C(-1596216639), INT32_C( -653101729), INT32_C( -652476461)),
      { SIMDE_FLOAT32_C(   -76.23), SIMDE_FLOAT32_C(   -18.44),
        SIMDE_FLOAT32_C(   771.31), SIMDE_FLOAT32_C(   206.00),
        SIMDE_FLOAT32_C(   650.40), SIMDE_FLOAT32_C(   -69.08),
        SIMDE_FLOAT32_C(  -737.29), SIMDE_FLOAT32_C(   222.97) },
      { SIMDE_FLOAT32_C(   726.23), SIMDE_FLOAT32_C(   315.20),
        SIMDE_FLOAT32_C(  -645.94), SIMDE_FLOAT32_C(  -480.27),
        SIMDE_FLOAT32_C(   650.40), SIMDE_FLOAT32_C(    43.96),
        SIMDE_FLOAT32_C(  -688.86), SIMDE_FLOAT32_C(   921.86) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   606.49), SIMDE_FLOAT32_C(   777.74),
                         SIMDE_FLOAT32_C(   -66.55), SIMDE_FLOAT32_C(   -42.93),
                         SIMDE_FLOAT32_C(    40.92), SIMDE_FLOAT32_C(  -104.82),
                         SIMDE_FLOAT32_C(   745.57), SIMDE_FLOAT32_C(  -526.15)),
      simde_mm256_set_epi32(INT32_C( 1494400292), INT32_C(  898207849), INT32_C(  499297865), INT32_C(   32131455),
                            INT32_C(  837039755), INT32_C(  686948685), INT32_C( 1413261791), INT32_C( 1091352937)),
      { SIMDE_FLOAT32_C(  -911.46), SIMDE_FLOAT32_C(   181.07),
        SIMDE_FLOAT32_C(    60.18), SIMDE_FLOAT32_C(   299.13),
        SIMDE_FLOAT32_C(  -412.14), SIMDE_FLOAT32_C(  -496.33),
        SIMDE_FLOAT32_C(   300.62), SIMDE_FLOAT32_C(  -738.40) },
      { SIMDE_FLOAT32_C(  -911.46), SIMDE_FLOAT32_C(   181.07),
        SIMDE_FLOAT32_C(    60.18), SIMDE_FLOAT32_C(   299.13),
        SIMDE_FLOAT32_C(  -412.14), SIMDE_FLOAT32_C(  -496.33),
        SIMDE_FLOAT32_C(   300.62), SIMDE_FLOAT32_C(  -738.40) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -418.84), SIMDE_FLOAT32_C(   873.25),
                         SIMDE_FLOAT32_C(   510.96), SIMDE_FLOAT32_C(   992.60),
                         SIMDE_FLOAT32_C(  -316.31), SIMDE_FLOAT32_C(    91.31),
                         SIMDE_FLOAT32_C(   578.46), SIMDE_FLOAT32_C(  -878.58)),
      simde_mm256_set_epi32(INT32_C(  957079452), INT32_C( 1280918142), INT32_C( 1743745557), INT32_C( 1819407670),
                            INT32_C(  242366822), INT32_C( 1212388671), INT32_C(-1368211077), INT32_C( 1178548564)),
      { SIMDE_FLOAT32_C(   268.38), SIMDE_FLOAT32_C(   166.26),
        SIMDE_FLOAT32_C(  -817.18), SIMDE_FLOAT32_C(  -906.27),
        SIMDE_FLOAT32_C(   690.97), SIMDE_FLOAT32_C(    40.42),
        SIMDE_FLOAT32_C(   937.35), SIMDE_FLOAT32_C(  -494.05) },
      { SIMDE_FLOAT32_C(   268.38), SIMDE_FLOAT32_C(   578.46),
        SIMDE_FLOAT32_C(  -817.18), SIMDE_FLOAT32_C(  -906.27),
        SIMDE_FLOAT32_C(   690.97), SIMDE_FLOAT32_C(    40.42),
        SIMDE_FLOAT32_C(   937.35), SIMDE_FLOAT32_C(  -494.05) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   991.62), SIMDE_FLOAT32_C(   121.11),
                         SIMDE_FLOAT32_C(   504.72), SIMDE_FLOAT32_C(   982.21),
                         SIMDE_FLOAT32_C(   263.79), SIMDE_FLOAT32_C(   803.03),
                         SIMDE_FLOAT32_C(    92.44), SIMDE_FLOAT32_C(  -807.69)),
      simde_mm256_set_epi32(INT32_C(-2097969116), INT32_C(-2051872419), INT32_C(  269695043), INT32_C( -952585033),
                            INT32_C( 1293504381), INT32_C( -196806212), INT32_C(-2045108827), INT32_C( 1173779579)),
      { SIMDE_FLOAT32_C(   292.67), SIMDE_FLOAT32_C(   917.15),
        SIMDE_FLOAT32_C(    90.37), SIMDE_FLOAT32_C(   166.43),
        SIMDE_FLOAT32_C(   627.88), SIMDE_FLOAT32_C(  -780.11),
        SIMDE_FLOAT32_C(  -304.67), SIMDE_FLOAT32_C(  -518.81) },
      { SIMDE_FLOAT32_C(   292.67), SIMDE_FLOAT32_C(    92.44),
        SIMDE_FLOAT32_C(   803.03), SIMDE_FLOAT32_C(   166.43),
        SIMDE_FLOAT32_C(   982.21), SIMDE_FLOAT32_C(  -780.11),
        SIMDE_FLOAT32_C(   121.11), SIMDE_FLOAT32_C(   991.62) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -433.27), SIMDE_FLOAT32_C(   892.50),
                         SIMDE_FLOAT32_C(   314.40), SIMDE_FLOAT32_C(  -419.48),
                         SIMDE_FLOAT32_C(  -384.30), SIMDE_FLOAT32_C(  -314.92),
                         SIMDE_FLOAT32_C(   743.09), SIMDE_FLOAT32_C(  -477.54)),
      simde_mm256_set_epi32(INT32_C( 1543878346), INT32_C(  -55266127), INT32_C(-1716646352), INT32_C( 1500867969),
                            INT32_C( -538309268), INT32_C( 1738471819), INT32_C( -967093953), INT32_C( -389124917)),
      { SIMDE_FLOAT32_C(   553.15), SIMDE_FLOAT32_C(  -107.56),
        SIMDE_FLOAT32_C(  -195.96), SIMDE_FLOAT32_C(   763.27),
        SIMDE_FLOAT32_C(  -256.55), SIMDE_FLOAT32_C(  -826.51),
        SIMDE_FLOAT32_C(  -168.36), SIMDE_FLOAT32_C(  -340.90) },
      { SIMDE_FLOAT32_C(  -477.54), SIMDE_FLOAT32_C(   743.09),
        SIMDE_FLOAT32_C(  -195.96), SIMDE_FLOAT32_C(  -384.30),
        SIMDE_FLOAT32_C(  -256.55), SIMDE_FLOAT32_C(   314.40),
        SIMDE_FLOAT32_C(   892.50), SIMDE_FLOAT32_C(  -340.90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[8];
    memcpy(r, test_vec[i].ri, sizeof(r));
    simde_mm256_maskstore_ps(r, test_vec[i].mask, test_vec[i].a);
    simde_assert_f32v_equal(simde_float32, sizeof(r) / sizeof(r[0]), r, test_vec[i].ro, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_min_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  620.32), SIMDE_FLOAT32_C( -596.35),
                         SIMDE_FLOAT32_C(  174.72), SIMDE_FLOAT32_C(  165.53),
                         SIMDE_FLOAT32_C(  242.92), SIMDE_FLOAT32_C(  330.00),
                         SIMDE_FLOAT32_C( -436.53), SIMDE_FLOAT32_C( -259.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  137.36), SIMDE_FLOAT32_C(  -49.88),
                         SIMDE_FLOAT32_C(  846.67), SIMDE_FLOAT32_C(  642.07),
                         SIMDE_FLOAT32_C(  353.31), SIMDE_FLOAT32_C( -696.33),
                         SIMDE_FLOAT32_C( -153.51), SIMDE_FLOAT32_C( -347.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  137.36), SIMDE_FLOAT32_C( -596.35),
                         SIMDE_FLOAT32_C(  174.72), SIMDE_FLOAT32_C(  165.53),
                         SIMDE_FLOAT32_C(  242.92), SIMDE_FLOAT32_C( -696.33),
                         SIMDE_FLOAT32_C( -436.53), SIMDE_FLOAT32_C( -347.51)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  938.63), SIMDE_FLOAT32_C(  244.19),
                         SIMDE_FLOAT32_C(  355.24), SIMDE_FLOAT32_C(  261.35),
                         SIMDE_FLOAT32_C(  679.42), SIMDE_FLOAT32_C(  -31.35),
                         SIMDE_FLOAT32_C(  138.77), SIMDE_FLOAT32_C( -717.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -563.43), SIMDE_FLOAT32_C(  586.11),
                         SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C(  850.65),
                         SIMDE_FLOAT32_C(  165.14), SIMDE_FLOAT32_C( -413.67),
                         SIMDE_FLOAT32_C( -290.54), SIMDE_FLOAT32_C(  984.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -563.43), SIMDE_FLOAT32_C(  244.19),
                         SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C(  261.35),
                         SIMDE_FLOAT32_C(  165.14), SIMDE_FLOAT32_C( -413.67),
                         SIMDE_FLOAT32_C( -290.54), SIMDE_FLOAT32_C( -717.66)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -838.48), SIMDE_FLOAT32_C(  344.61),
                         SIMDE_FLOAT32_C( -913.53), SIMDE_FLOAT32_C(  858.23),
                         SIMDE_FLOAT32_C( -347.90), SIMDE_FLOAT32_C( -707.87),
                         SIMDE_FLOAT32_C( -634.91), SIMDE_FLOAT32_C( -919.82)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -180.34), SIMDE_FLOAT32_C( -789.22),
                         SIMDE_FLOAT32_C(  607.01), SIMDE_FLOAT32_C(  440.98),
                         SIMDE_FLOAT32_C(  432.59), SIMDE_FLOAT32_C( -196.73),
                         SIMDE_FLOAT32_C(  380.83), SIMDE_FLOAT32_C(  796.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -838.48), SIMDE_FLOAT32_C( -789.22),
                         SIMDE_FLOAT32_C( -913.53), SIMDE_FLOAT32_C(  440.98),
                         SIMDE_FLOAT32_C( -347.90), SIMDE_FLOAT32_C( -707.87),
                         SIMDE_FLOAT32_C( -634.91), SIMDE_FLOAT32_C( -919.82)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -210.35), SIMDE_FLOAT32_C( -870.90),
                         SIMDE_FLOAT32_C(  992.08), SIMDE_FLOAT32_C( -822.82),
                         SIMDE_FLOAT32_C( -209.97), SIMDE_FLOAT32_C( -436.22),
                         SIMDE_FLOAT32_C(  481.44), SIMDE_FLOAT32_C(  169.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -860.96), SIMDE_FLOAT32_C(  972.39),
                         SIMDE_FLOAT32_C(  830.57), SIMDE_FLOAT32_C(  -23.76),
                         SIMDE_FLOAT32_C(  311.19), SIMDE_FLOAT32_C(  554.15),
                         SIMDE_FLOAT32_C(    0.80), SIMDE_FLOAT32_C( -247.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -860.96), SIMDE_FLOAT32_C( -870.90),
                         SIMDE_FLOAT32_C(  830.57), SIMDE_FLOAT32_C( -822.82),
                         SIMDE_FLOAT32_C( -209.97), SIMDE_FLOAT32_C( -436.22),
                         SIMDE_FLOAT32_C(    0.80), SIMDE_FLOAT32_C( -247.41)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -158.36), SIMDE_FLOAT32_C( -758.94),
                         SIMDE_FLOAT32_C(  618.04), SIMDE_FLOAT32_C(  976.02),
                         SIMDE_FLOAT32_C( -953.60), SIMDE_FLOAT32_C(  866.14),
                         SIMDE_FLOAT32_C(  565.22), SIMDE_FLOAT32_C(  554.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -8.54), SIMDE_FLOAT32_C( -896.75),
                         SIMDE_FLOAT32_C(  630.48), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  865.05), SIMDE_FLOAT32_C( -640.13),
                         SIMDE_FLOAT32_C( -969.96), SIMDE_FLOAT32_C( -427.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -158.36), SIMDE_FLOAT32_C( -896.75),
                         SIMDE_FLOAT32_C(  618.04), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C( -953.60), SIMDE_FLOAT32_C( -640.13),
                         SIMDE_FLOAT32_C( -969.96), SIMDE_FLOAT32_C( -427.62)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -601.54), SIMDE_FLOAT32_C( -545.11),
                         SIMDE_FLOAT32_C( -568.66), SIMDE_FLOAT32_C(  393.12),
                         SIMDE_FLOAT32_C( -656.85), SIMDE_FLOAT32_C(  612.23),
                         SIMDE_FLOAT32_C(  417.91), SIMDE_FLOAT32_C( -206.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -56.90), SIMDE_FLOAT32_C( -986.18),
                         SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C(  -52.08),
                         SIMDE_FLOAT32_C( -838.46), SIMDE_FLOAT32_C( -751.49),
                         SIMDE_FLOAT32_C(  775.89), SIMDE_FLOAT32_C(  940.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -601.54), SIMDE_FLOAT32_C( -986.18),
                         SIMDE_FLOAT32_C( -568.66), SIMDE_FLOAT32_C(  -52.08),
                         SIMDE_FLOAT32_C( -838.46), SIMDE_FLOAT32_C( -751.49),
                         SIMDE_FLOAT32_C(  417.91), SIMDE_FLOAT32_C( -206.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  459.26), SIMDE_FLOAT32_C( -447.11),
                         SIMDE_FLOAT32_C(  826.76), SIMDE_FLOAT32_C( -107.61),
                         SIMDE_FLOAT32_C( -521.03), SIMDE_FLOAT32_C(  -33.76),
                         SIMDE_FLOAT32_C(  315.53), SIMDE_FLOAT32_C( -222.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.58), SIMDE_FLOAT32_C(   50.72),
                         SIMDE_FLOAT32_C(  921.42), SIMDE_FLOAT32_C(  664.07),
                         SIMDE_FLOAT32_C(  743.00), SIMDE_FLOAT32_C( -236.39),
                         SIMDE_FLOAT32_C(  981.20), SIMDE_FLOAT32_C(  280.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.58), SIMDE_FLOAT32_C( -447.11),
                         SIMDE_FLOAT32_C(  826.76), SIMDE_FLOAT32_C( -107.61),
                         SIMDE_FLOAT32_C( -521.03), SIMDE_FLOAT32_C( -236.39),
                         SIMDE_FLOAT32_C(  315.53), SIMDE_FLOAT32_C( -222.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  356.76), SIMDE_FLOAT32_C( -389.22),
                         SIMDE_FLOAT32_C( -477.96), SIMDE_FLOAT32_C(   -3.77),
                         SIMDE_FLOAT32_C( -645.03), SIMDE_FLOAT32_C( -766.89),
                         SIMDE_FLOAT32_C(  755.76), SIMDE_FLOAT32_C(  244.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  823.25), SIMDE_FLOAT32_C(  384.14),
                         SIMDE_FLOAT32_C(  475.61), SIMDE_FLOAT32_C( -650.92),
                         SIMDE_FLOAT32_C( -913.35), SIMDE_FLOAT32_C( -290.77),
                         SIMDE_FLOAT32_C(  213.82), SIMDE_FLOAT32_C( -350.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  356.76), SIMDE_FLOAT32_C( -389.22),
                         SIMDE_FLOAT32_C( -477.96), SIMDE_FLOAT32_C( -650.92),
                         SIMDE_FLOAT32_C( -913.35), SIMDE_FLOAT32_C( -766.89),
                         SIMDE_FLOAT32_C(  213.82), SIMDE_FLOAT32_C( -350.01)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_min_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_min_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  207.41), SIMDE_FLOAT64_C(  328.63),
                         SIMDE_FLOAT64_C( -694.69), SIMDE_FLOAT64_C(  687.63)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   89.05), SIMDE_FLOAT64_C(  448.86),
                         SIMDE_FLOAT64_C(   19.12), SIMDE_FLOAT64_C( -158.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   89.05), SIMDE_FLOAT64_C(  328.63),
                         SIMDE_FLOAT64_C( -694.69), SIMDE_FLOAT64_C( -158.19)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.97), SIMDE_FLOAT64_C( -437.57),
                         SIMDE_FLOAT64_C( -994.98), SIMDE_FLOAT64_C( -594.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  949.89), SIMDE_FLOAT64_C( -515.80),
                         SIMDE_FLOAT64_C( -545.90), SIMDE_FLOAT64_C(  794.78)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  809.97), SIMDE_FLOAT64_C( -515.80),
                         SIMDE_FLOAT64_C( -994.98), SIMDE_FLOAT64_C( -594.51)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -509.90), SIMDE_FLOAT64_C( -421.15),
                         SIMDE_FLOAT64_C( -539.85), SIMDE_FLOAT64_C( -245.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -30.48), SIMDE_FLOAT64_C( -451.08),
                         SIMDE_FLOAT64_C(  -92.82), SIMDE_FLOAT64_C( -896.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -509.90), SIMDE_FLOAT64_C( -451.08),
                         SIMDE_FLOAT64_C( -539.85), SIMDE_FLOAT64_C( -896.69)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  362.92), SIMDE_FLOAT64_C(  618.37),
                         SIMDE_FLOAT64_C( -874.81), SIMDE_FLOAT64_C(  119.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  479.87), SIMDE_FLOAT64_C(  161.56),
                         SIMDE_FLOAT64_C(  162.67), SIMDE_FLOAT64_C( -967.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  362.92), SIMDE_FLOAT64_C(  161.56),
                         SIMDE_FLOAT64_C( -874.81), SIMDE_FLOAT64_C( -967.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -124.73), SIMDE_FLOAT64_C(  204.12),
                         SIMDE_FLOAT64_C( -546.39), SIMDE_FLOAT64_C(  -78.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  120.00), SIMDE_FLOAT64_C(  851.26),
                         SIMDE_FLOAT64_C(  153.83), SIMDE_FLOAT64_C(  393.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -124.73), SIMDE_FLOAT64_C(  204.12),
                         SIMDE_FLOAT64_C( -546.39), SIMDE_FLOAT64_C(  -78.22)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -812.91), SIMDE_FLOAT64_C(  797.50),
                         SIMDE_FLOAT64_C(  285.31), SIMDE_FLOAT64_C(  340.33)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -48.34), SIMDE_FLOAT64_C( -906.19),
                         SIMDE_FLOAT64_C(  314.61), SIMDE_FLOAT64_C(  602.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -812.91), SIMDE_FLOAT64_C( -906.19),
                         SIMDE_FLOAT64_C(  285.31), SIMDE_FLOAT64_C(  340.33)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  376.08), SIMDE_FLOAT64_C(  847.57),
                         SIMDE_FLOAT64_C(  979.10), SIMDE_FLOAT64_C( -602.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.85), SIMDE_FLOAT64_C(  571.44),
                         SIMDE_FLOAT64_C( -621.81), SIMDE_FLOAT64_C(  -12.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  307.85), SIMDE_FLOAT64_C(  571.44),
                         SIMDE_FLOAT64_C( -621.81), SIMDE_FLOAT64_C( -602.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.10), SIMDE_FLOAT64_C(  349.84),
                         SIMDE_FLOAT64_C( -943.34), SIMDE_FLOAT64_C(  341.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -89.49), SIMDE_FLOAT64_C( -236.51),
                         SIMDE_FLOAT64_C(  632.28), SIMDE_FLOAT64_C( -535.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.10), SIMDE_FLOAT64_C( -236.51),
                         SIMDE_FLOAT64_C( -943.34), SIMDE_FLOAT64_C( -535.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_min_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  449.92), SIMDE_FLOAT32_C(   34.28),
                         SIMDE_FLOAT32_C(  -25.78), SIMDE_FLOAT32_C(  210.08),
                         SIMDE_FLOAT32_C(  389.04), SIMDE_FLOAT32_C( -871.84),
                         SIMDE_FLOAT32_C( -259.15), SIMDE_FLOAT32_C( -935.03)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -540.89), SIMDE_FLOAT32_C(  480.33),
                         SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C(  243.72),
                         SIMDE_FLOAT32_C(  827.03), SIMDE_FLOAT32_C(  -35.53),
                         SIMDE_FLOAT32_C( -369.50), SIMDE_FLOAT32_C( -834.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  449.92), SIMDE_FLOAT32_C(  480.33),
                         SIMDE_FLOAT32_C(   35.20), SIMDE_FLOAT32_C(  243.72),
                         SIMDE_FLOAT32_C(  827.03), SIMDE_FLOAT32_C(  -35.53),
                         SIMDE_FLOAT32_C( -259.15), SIMDE_FLOAT32_C( -834.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  489.45), SIMDE_FLOAT32_C( -170.78),
                         SIMDE_FLOAT32_C(  183.48), SIMDE_FLOAT32_C(  307.64),
                         SIMDE_FLOAT32_C( -977.66), SIMDE_FLOAT32_C(  745.18),
                         SIMDE_FLOAT32_C(  561.96), SIMDE_FLOAT32_C( -868.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -220.92), SIMDE_FLOAT32_C(  742.39),
                         SIMDE_FLOAT32_C(  682.97), SIMDE_FLOAT32_C(  319.92),
                         SIMDE_FLOAT32_C(  734.45), SIMDE_FLOAT32_C( -490.69),
                         SIMDE_FLOAT32_C( -753.68), SIMDE_FLOAT32_C( -110.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  489.45), SIMDE_FLOAT32_C(  742.39),
                         SIMDE_FLOAT32_C(  682.97), SIMDE_FLOAT32_C(  319.92),
                         SIMDE_FLOAT32_C(  734.45), SIMDE_FLOAT32_C(  745.18),
                         SIMDE_FLOAT32_C(  561.96), SIMDE_FLOAT32_C( -110.63)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -934.39), SIMDE_FLOAT32_C( -436.28),
                         SIMDE_FLOAT32_C(  572.10), SIMDE_FLOAT32_C( -111.64),
                         SIMDE_FLOAT32_C(  551.18), SIMDE_FLOAT32_C(  829.61),
                         SIMDE_FLOAT32_C( -107.94), SIMDE_FLOAT32_C( -864.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.77), SIMDE_FLOAT32_C(  207.18),
                         SIMDE_FLOAT32_C( -690.52), SIMDE_FLOAT32_C(  861.15),
                         SIMDE_FLOAT32_C(  110.08), SIMDE_FLOAT32_C(   67.85),
                         SIMDE_FLOAT32_C( -389.66), SIMDE_FLOAT32_C(  867.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.77), SIMDE_FLOAT32_C(  207.18),
                         SIMDE_FLOAT32_C(  572.10), SIMDE_FLOAT32_C(  861.15),
                         SIMDE_FLOAT32_C(  551.18), SIMDE_FLOAT32_C(  829.61),
                         SIMDE_FLOAT32_C( -107.94), SIMDE_FLOAT32_C(  867.20)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  481.13), SIMDE_FLOAT32_C(  -53.37),
                         SIMDE_FLOAT32_C(   -0.04), SIMDE_FLOAT32_C(  614.09),
                         SIMDE_FLOAT32_C(  596.94), SIMDE_FLOAT32_C(  349.18),
                         SIMDE_FLOAT32_C(   53.36), SIMDE_FLOAT32_C(  244.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -253.17), SIMDE_FLOAT32_C( -107.20),
                         SIMDE_FLOAT32_C( -893.53), SIMDE_FLOAT32_C(  608.05),
                         SIMDE_FLOAT32_C(  292.67), SIMDE_FLOAT32_C(  529.08),
                         SIMDE_FLOAT32_C(  170.70), SIMDE_FLOAT32_C( -778.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  481.13), SIMDE_FLOAT32_C(  -53.37),
                         SIMDE_FLOAT32_C(   -0.04), SIMDE_FLOAT32_C(  614.09),
                         SIMDE_FLOAT32_C(  596.94), SIMDE_FLOAT32_C(  529.08),
                         SIMDE_FLOAT32_C(  170.70), SIMDE_FLOAT32_C(  244.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -125.79), SIMDE_FLOAT32_C( -776.79),
                         SIMDE_FLOAT32_C( -268.99), SIMDE_FLOAT32_C(  991.82),
                         SIMDE_FLOAT32_C(  880.36), SIMDE_FLOAT32_C( -906.06),
                         SIMDE_FLOAT32_C( -550.03), SIMDE_FLOAT32_C(  415.17)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.77), SIMDE_FLOAT32_C( -207.30),
                         SIMDE_FLOAT32_C( -944.02), SIMDE_FLOAT32_C( -591.97),
                         SIMDE_FLOAT32_C( -584.21), SIMDE_FLOAT32_C(  271.28),
                         SIMDE_FLOAT32_C( -845.79), SIMDE_FLOAT32_C( -155.27)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  733.77), SIMDE_FLOAT32_C( -207.30),
                         SIMDE_FLOAT32_C( -268.99), SIMDE_FLOAT32_C(  991.82),
                         SIMDE_FLOAT32_C(  880.36), SIMDE_FLOAT32_C(  271.28),
                         SIMDE_FLOAT32_C( -550.03), SIMDE_FLOAT32_C(  415.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.67), SIMDE_FLOAT32_C(  221.00),
                         SIMDE_FLOAT32_C( -864.98), SIMDE_FLOAT32_C(  290.97),
                         SIMDE_FLOAT32_C( -704.76), SIMDE_FLOAT32_C( -867.43),
                         SIMDE_FLOAT32_C( -323.83), SIMDE_FLOAT32_C(   74.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -127.03), SIMDE_FLOAT32_C(  135.62),
                         SIMDE_FLOAT32_C( -308.59), SIMDE_FLOAT32_C( -352.70),
                         SIMDE_FLOAT32_C(  883.68), SIMDE_FLOAT32_C(  134.86),
                         SIMDE_FLOAT32_C( -894.89), SIMDE_FLOAT32_C( -737.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -127.03), SIMDE_FLOAT32_C(  221.00),
                         SIMDE_FLOAT32_C( -308.59), SIMDE_FLOAT32_C(  290.97),
                         SIMDE_FLOAT32_C(  883.68), SIMDE_FLOAT32_C(  134.86),
                         SIMDE_FLOAT32_C( -323.83), SIMDE_FLOAT32_C(   74.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  780.81), SIMDE_FLOAT32_C(  -76.69),
                         SIMDE_FLOAT32_C( -213.47), SIMDE_FLOAT32_C(  296.05),
                         SIMDE_FLOAT32_C(  129.81), SIMDE_FLOAT32_C(   95.07),
                         SIMDE_FLOAT32_C( -493.97), SIMDE_FLOAT32_C( -309.39)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  224.91), SIMDE_FLOAT32_C(  545.10),
                         SIMDE_FLOAT32_C( -928.25), SIMDE_FLOAT32_C(  373.14),
                         SIMDE_FLOAT32_C( -710.01), SIMDE_FLOAT32_C(  166.25),
                         SIMDE_FLOAT32_C(  729.82), SIMDE_FLOAT32_C(  996.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  780.81), SIMDE_FLOAT32_C(  545.10),
                         SIMDE_FLOAT32_C( -213.47), SIMDE_FLOAT32_C(  373.14),
                         SIMDE_FLOAT32_C(  129.81), SIMDE_FLOAT32_C(  166.25),
                         SIMDE_FLOAT32_C(  729.82), SIMDE_FLOAT32_C(  996.22)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -153.19), SIMDE_FLOAT32_C( -809.42),
                         SIMDE_FLOAT32_C(  665.06), SIMDE_FLOAT32_C(  966.51),
                         SIMDE_FLOAT32_C(  515.00), SIMDE_FLOAT32_C(  239.45),
                         SIMDE_FLOAT32_C(  878.48), SIMDE_FLOAT32_C(   83.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -855.75), SIMDE_FLOAT32_C( -288.00),
                         SIMDE_FLOAT32_C(  118.38), SIMDE_FLOAT32_C(  373.81),
                         SIMDE_FLOAT32_C( -507.54), SIMDE_FLOAT32_C( -677.13),
                         SIMDE_FLOAT32_C( -680.61), SIMDE_FLOAT32_C(  934.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -153.19), SIMDE_FLOAT32_C( -288.00),
                         SIMDE_FLOAT32_C(  665.06), SIMDE_FLOAT32_C(  966.51),
                         SIMDE_FLOAT32_C(  515.00), SIMDE_FLOAT32_C(  239.45),
                         SIMDE_FLOAT32_C(  878.48), SIMDE_FLOAT32_C(  934.18)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_max_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_max_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -66.36), SIMDE_FLOAT64_C( -982.48),
                         SIMDE_FLOAT64_C( -994.10), SIMDE_FLOAT64_C(  656.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   58.12), SIMDE_FLOAT64_C(  730.28),
                         SIMDE_FLOAT64_C(  705.46), SIMDE_FLOAT64_C(  138.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   58.12), SIMDE_FLOAT64_C(  730.28),
                         SIMDE_FLOAT64_C(  705.46), SIMDE_FLOAT64_C(  656.44)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  965.09), SIMDE_FLOAT64_C( -956.81),
                         SIMDE_FLOAT64_C(  -84.17), SIMDE_FLOAT64_C(   -0.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -943.91), SIMDE_FLOAT64_C( -849.45),
                         SIMDE_FLOAT64_C(  747.06), SIMDE_FLOAT64_C(  297.16)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  965.09), SIMDE_FLOAT64_C( -849.45),
                         SIMDE_FLOAT64_C(  747.06), SIMDE_FLOAT64_C(  297.16)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -285.40), SIMDE_FLOAT64_C(   20.32),
                         SIMDE_FLOAT64_C( -517.57), SIMDE_FLOAT64_C(  747.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -634.35), SIMDE_FLOAT64_C( -655.50),
                         SIMDE_FLOAT64_C(  321.54), SIMDE_FLOAT64_C( -151.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -285.40), SIMDE_FLOAT64_C(   20.32),
                         SIMDE_FLOAT64_C(  321.54), SIMDE_FLOAT64_C(  747.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  766.49), SIMDE_FLOAT64_C( -821.02),
                         SIMDE_FLOAT64_C(  800.18), SIMDE_FLOAT64_C(  -78.19)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -744.41), SIMDE_FLOAT64_C(  250.49),
                         SIMDE_FLOAT64_C(   16.63), SIMDE_FLOAT64_C(  223.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  766.49), SIMDE_FLOAT64_C(  250.49),
                         SIMDE_FLOAT64_C(  800.18), SIMDE_FLOAT64_C(  223.92)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  297.61), SIMDE_FLOAT64_C(   -1.23),
                         SIMDE_FLOAT64_C( -644.62), SIMDE_FLOAT64_C(  -37.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -152.08), SIMDE_FLOAT64_C(  667.58),
                         SIMDE_FLOAT64_C(  737.38), SIMDE_FLOAT64_C(  221.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  297.61), SIMDE_FLOAT64_C(  667.58),
                         SIMDE_FLOAT64_C(  737.38), SIMDE_FLOAT64_C(  221.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.47), SIMDE_FLOAT64_C( -363.06),
                         SIMDE_FLOAT64_C( -130.47), SIMDE_FLOAT64_C( -257.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -448.43), SIMDE_FLOAT64_C(   52.56),
                         SIMDE_FLOAT64_C( -688.52), SIMDE_FLOAT64_C(  690.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  804.47), SIMDE_FLOAT64_C(   52.56),
                         SIMDE_FLOAT64_C( -130.47), SIMDE_FLOAT64_C(  690.05)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.48), SIMDE_FLOAT64_C(  404.58),
                         SIMDE_FLOAT64_C( -885.87), SIMDE_FLOAT64_C(  607.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -402.92), SIMDE_FLOAT64_C(  777.55),
                         SIMDE_FLOAT64_C( -392.90), SIMDE_FLOAT64_C(  385.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.48), SIMDE_FLOAT64_C(  777.55),
                         SIMDE_FLOAT64_C( -392.90), SIMDE_FLOAT64_C(  607.60)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -612.46), SIMDE_FLOAT64_C( -353.94),
                         SIMDE_FLOAT64_C( -723.01), SIMDE_FLOAT64_C( -705.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -638.30), SIMDE_FLOAT64_C(   67.95),
                         SIMDE_FLOAT64_C(  537.38), SIMDE_FLOAT64_C( -280.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -612.46), SIMDE_FLOAT64_C(   67.95),
                         SIMDE_FLOAT64_C(  537.38), SIMDE_FLOAT64_C( -280.17)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_max_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movedup_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -848.53), SIMDE_FLOAT64_C( -411.84),
                         SIMDE_FLOAT64_C( -162.95), SIMDE_FLOAT64_C(  899.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -411.84), SIMDE_FLOAT64_C( -411.84),
                         SIMDE_FLOAT64_C(  899.65), SIMDE_FLOAT64_C(  899.65)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -411.40), SIMDE_FLOAT64_C( -713.22),
                         SIMDE_FLOAT64_C( -868.77), SIMDE_FLOAT64_C( -109.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -713.22), SIMDE_FLOAT64_C( -713.22),
                         SIMDE_FLOAT64_C( -109.40), SIMDE_FLOAT64_C( -109.40)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -430.65), SIMDE_FLOAT64_C(  350.42),
                         SIMDE_FLOAT64_C( -891.94), SIMDE_FLOAT64_C( -973.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  350.42), SIMDE_FLOAT64_C(  350.42),
                         SIMDE_FLOAT64_C( -973.52), SIMDE_FLOAT64_C( -973.52)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -988.20), SIMDE_FLOAT64_C( -840.45),
                         SIMDE_FLOAT64_C(  979.48), SIMDE_FLOAT64_C( -644.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -840.45), SIMDE_FLOAT64_C( -840.45),
                         SIMDE_FLOAT64_C( -644.54), SIMDE_FLOAT64_C( -644.54)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  459.82), SIMDE_FLOAT64_C(  645.18),
                         SIMDE_FLOAT64_C( -152.73), SIMDE_FLOAT64_C(  150.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  645.18), SIMDE_FLOAT64_C(  645.18),
                         SIMDE_FLOAT64_C(  150.29), SIMDE_FLOAT64_C(  150.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -902.52), SIMDE_FLOAT64_C(   -5.45),
                         SIMDE_FLOAT64_C( -958.89), SIMDE_FLOAT64_C( -924.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -5.45), SIMDE_FLOAT64_C(   -5.45),
                         SIMDE_FLOAT64_C( -924.74), SIMDE_FLOAT64_C( -924.74)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -582.37), SIMDE_FLOAT64_C(  163.98),
                         SIMDE_FLOAT64_C( -479.86), SIMDE_FLOAT64_C(  420.17)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  163.98), SIMDE_FLOAT64_C(  163.98),
                         SIMDE_FLOAT64_C(  420.17), SIMDE_FLOAT64_C(  420.17)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -319.68), SIMDE_FLOAT64_C(  791.82),
                         SIMDE_FLOAT64_C(  388.17), SIMDE_FLOAT64_C(  537.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  791.82), SIMDE_FLOAT64_C(  791.82),
                         SIMDE_FLOAT64_C(  537.00), SIMDE_FLOAT64_C(  537.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_movedup_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movehdup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C( -208.59),
                         SIMDE_FLOAT32_C( -422.71), SIMDE_FLOAT32_C( -254.03),
                         SIMDE_FLOAT32_C(    4.80), SIMDE_FLOAT32_C( -671.71),
                         SIMDE_FLOAT32_C(  685.42), SIMDE_FLOAT32_C( -954.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  948.05), SIMDE_FLOAT32_C(  948.05),
                         SIMDE_FLOAT32_C( -422.71), SIMDE_FLOAT32_C( -422.71),
                         SIMDE_FLOAT32_C(    4.80), SIMDE_FLOAT32_C(    4.80),
                         SIMDE_FLOAT32_C(  685.42), SIMDE_FLOAT32_C(  685.42)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  569.22), SIMDE_FLOAT32_C(  232.90),
                         SIMDE_FLOAT32_C(  835.45), SIMDE_FLOAT32_C(   10.13),
                         SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C(  598.20),
                         SIMDE_FLOAT32_C(  376.16), SIMDE_FLOAT32_C( -918.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  569.22), SIMDE_FLOAT32_C(  569.22),
                         SIMDE_FLOAT32_C(  835.45), SIMDE_FLOAT32_C(  835.45),
                         SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C(   30.06),
                         SIMDE_FLOAT32_C(  376.16), SIMDE_FLOAT32_C(  376.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   97.81), SIMDE_FLOAT32_C(  286.59),
                         SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C(  944.38),
                         SIMDE_FLOAT32_C( -367.92), SIMDE_FLOAT32_C(  626.43),
                         SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  776.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   97.81), SIMDE_FLOAT32_C(   97.81),
                         SIMDE_FLOAT32_C( -299.41), SIMDE_FLOAT32_C( -299.41),
                         SIMDE_FLOAT32_C( -367.92), SIMDE_FLOAT32_C( -367.92),
                         SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  889.36)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.83), SIMDE_FLOAT32_C( -435.86),
                         SIMDE_FLOAT32_C( -637.27), SIMDE_FLOAT32_C(  -95.13),
                         SIMDE_FLOAT32_C(  698.01), SIMDE_FLOAT32_C(   55.48),
                         SIMDE_FLOAT32_C(    1.28), SIMDE_FLOAT32_C( -243.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -67.83), SIMDE_FLOAT32_C(  -67.83),
                         SIMDE_FLOAT32_C( -637.27), SIMDE_FLOAT32_C( -637.27),
                         SIMDE_FLOAT32_C(  698.01), SIMDE_FLOAT32_C(  698.01),
                         SIMDE_FLOAT32_C(    1.28), SIMDE_FLOAT32_C(    1.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.47), SIMDE_FLOAT32_C(  784.83),
                         SIMDE_FLOAT32_C( -470.70), SIMDE_FLOAT32_C(  865.28),
                         SIMDE_FLOAT32_C(  393.60), SIMDE_FLOAT32_C( -743.40),
                         SIMDE_FLOAT32_C(  858.48), SIMDE_FLOAT32_C(  507.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.47), SIMDE_FLOAT32_C( -266.47),
                         SIMDE_FLOAT32_C( -470.70), SIMDE_FLOAT32_C( -470.70),
                         SIMDE_FLOAT32_C(  393.60), SIMDE_FLOAT32_C(  393.60),
                         SIMDE_FLOAT32_C(  858.48), SIMDE_FLOAT32_C(  858.48)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.84), SIMDE_FLOAT32_C(   46.20),
                         SIMDE_FLOAT32_C( -185.53), SIMDE_FLOAT32_C(  211.61),
                         SIMDE_FLOAT32_C(  -20.87), SIMDE_FLOAT32_C( -661.06),
                         SIMDE_FLOAT32_C(  209.04), SIMDE_FLOAT32_C(  920.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.84), SIMDE_FLOAT32_C(  270.84),
                         SIMDE_FLOAT32_C( -185.53), SIMDE_FLOAT32_C( -185.53),
                         SIMDE_FLOAT32_C(  -20.87), SIMDE_FLOAT32_C(  -20.87),
                         SIMDE_FLOAT32_C(  209.04), SIMDE_FLOAT32_C(  209.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -751.76), SIMDE_FLOAT32_C( -655.85),
                         SIMDE_FLOAT32_C(  179.21), SIMDE_FLOAT32_C(  373.36),
                         SIMDE_FLOAT32_C(    1.62), SIMDE_FLOAT32_C( -981.05),
                         SIMDE_FLOAT32_C(  802.72), SIMDE_FLOAT32_C(  -49.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -751.76), SIMDE_FLOAT32_C( -751.76),
                         SIMDE_FLOAT32_C(  179.21), SIMDE_FLOAT32_C(  179.21),
                         SIMDE_FLOAT32_C(    1.62), SIMDE_FLOAT32_C(    1.62),
                         SIMDE_FLOAT32_C(  802.72), SIMDE_FLOAT32_C(  802.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   44.57), SIMDE_FLOAT32_C( -391.28),
                         SIMDE_FLOAT32_C(  614.40), SIMDE_FLOAT32_C( -901.50),
                         SIMDE_FLOAT32_C(  577.45), SIMDE_FLOAT32_C( -465.25),
                         SIMDE_FLOAT32_C( -148.70), SIMDE_FLOAT32_C( -714.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   44.57), SIMDE_FLOAT32_C(   44.57),
                         SIMDE_FLOAT32_C(  614.40), SIMDE_FLOAT32_C(  614.40),
                         SIMDE_FLOAT32_C(  577.45), SIMDE_FLOAT32_C(  577.45),
                         SIMDE_FLOAT32_C( -148.70), SIMDE_FLOAT32_C( -148.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_movehdup_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_moveldup_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  366.49), SIMDE_FLOAT32_C(  -15.43),
                         SIMDE_FLOAT32_C( -732.71), SIMDE_FLOAT32_C(  312.44),
                         SIMDE_FLOAT32_C( -535.64), SIMDE_FLOAT32_C(  -24.14),
                         SIMDE_FLOAT32_C( -881.62), SIMDE_FLOAT32_C(  419.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -15.43), SIMDE_FLOAT32_C(  -15.43),
                         SIMDE_FLOAT32_C(  312.44), SIMDE_FLOAT32_C(  312.44),
                         SIMDE_FLOAT32_C(  -24.14), SIMDE_FLOAT32_C(  -24.14),
                         SIMDE_FLOAT32_C(  419.86), SIMDE_FLOAT32_C(  419.86)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -625.40), SIMDE_FLOAT32_C( -523.97),
                         SIMDE_FLOAT32_C(  296.91), SIMDE_FLOAT32_C(  228.72),
                         SIMDE_FLOAT32_C(  553.44), SIMDE_FLOAT32_C(  -88.10),
                         SIMDE_FLOAT32_C( -240.30), SIMDE_FLOAT32_C(  437.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -523.97), SIMDE_FLOAT32_C( -523.97),
                         SIMDE_FLOAT32_C(  228.72), SIMDE_FLOAT32_C(  228.72),
                         SIMDE_FLOAT32_C(  -88.10), SIMDE_FLOAT32_C(  -88.10),
                         SIMDE_FLOAT32_C(  437.29), SIMDE_FLOAT32_C(  437.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -54.17), SIMDE_FLOAT32_C( -444.25),
                         SIMDE_FLOAT32_C( -384.50), SIMDE_FLOAT32_C(  781.57),
                         SIMDE_FLOAT32_C(  607.05), SIMDE_FLOAT32_C( -295.21),
                         SIMDE_FLOAT32_C(  101.75), SIMDE_FLOAT32_C( -941.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -444.25), SIMDE_FLOAT32_C( -444.25),
                         SIMDE_FLOAT32_C(  781.57), SIMDE_FLOAT32_C(  781.57),
                         SIMDE_FLOAT32_C( -295.21), SIMDE_FLOAT32_C( -295.21),
                         SIMDE_FLOAT32_C( -941.55), SIMDE_FLOAT32_C( -941.55)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -41.58), SIMDE_FLOAT32_C( -957.94),
                         SIMDE_FLOAT32_C(  871.50), SIMDE_FLOAT32_C( -839.89),
                         SIMDE_FLOAT32_C(  692.80), SIMDE_FLOAT32_C( -417.15),
                         SIMDE_FLOAT32_C( -850.22), SIMDE_FLOAT32_C(  594.16)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -957.94), SIMDE_FLOAT32_C( -957.94),
                         SIMDE_FLOAT32_C( -839.89), SIMDE_FLOAT32_C( -839.89),
                         SIMDE_FLOAT32_C( -417.15), SIMDE_FLOAT32_C( -417.15),
                         SIMDE_FLOAT32_C(  594.16), SIMDE_FLOAT32_C(  594.16)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -319.28), SIMDE_FLOAT32_C( -229.51),
                         SIMDE_FLOAT32_C( -581.14), SIMDE_FLOAT32_C(   81.57),
                         SIMDE_FLOAT32_C(  774.33), SIMDE_FLOAT32_C( -621.69),
                         SIMDE_FLOAT32_C( -447.13), SIMDE_FLOAT32_C(  334.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -229.51), SIMDE_FLOAT32_C( -229.51),
                         SIMDE_FLOAT32_C(   81.57), SIMDE_FLOAT32_C(   81.57),
                         SIMDE_FLOAT32_C( -621.69), SIMDE_FLOAT32_C( -621.69),
                         SIMDE_FLOAT32_C(  334.88), SIMDE_FLOAT32_C(  334.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  288.60), SIMDE_FLOAT32_C(  139.33),
                         SIMDE_FLOAT32_C(  951.18), SIMDE_FLOAT32_C( -924.84),
                         SIMDE_FLOAT32_C( -320.35), SIMDE_FLOAT32_C( -998.89),
                         SIMDE_FLOAT32_C(  164.55), SIMDE_FLOAT32_C(  991.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  139.33), SIMDE_FLOAT32_C(  139.33),
                         SIMDE_FLOAT32_C( -924.84), SIMDE_FLOAT32_C( -924.84),
                         SIMDE_FLOAT32_C( -998.89), SIMDE_FLOAT32_C( -998.89),
                         SIMDE_FLOAT32_C(  991.73), SIMDE_FLOAT32_C(  991.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -671.27), SIMDE_FLOAT32_C(   35.52),
                         SIMDE_FLOAT32_C(  780.53), SIMDE_FLOAT32_C(  -58.65),
                         SIMDE_FLOAT32_C(  227.27), SIMDE_FLOAT32_C( -621.99),
                         SIMDE_FLOAT32_C( -182.62), SIMDE_FLOAT32_C(  448.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   35.52), SIMDE_FLOAT32_C(   35.52),
                         SIMDE_FLOAT32_C(  -58.65), SIMDE_FLOAT32_C(  -58.65),
                         SIMDE_FLOAT32_C( -621.99), SIMDE_FLOAT32_C( -621.99),
                         SIMDE_FLOAT32_C(  448.36), SIMDE_FLOAT32_C(  448.36)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -984.41), SIMDE_FLOAT32_C( -968.89),
                         SIMDE_FLOAT32_C( -986.96), SIMDE_FLOAT32_C( -760.49),
                         SIMDE_FLOAT32_C(  908.37), SIMDE_FLOAT32_C(   35.57),
                         SIMDE_FLOAT32_C( -144.09), SIMDE_FLOAT32_C( -735.38)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -968.89), SIMDE_FLOAT32_C( -968.89),
                         SIMDE_FLOAT32_C( -760.49), SIMDE_FLOAT32_C( -760.49),
                         SIMDE_FLOAT32_C(   35.57), SIMDE_FLOAT32_C(   35.57),
                         SIMDE_FLOAT32_C( -735.38), SIMDE_FLOAT32_C( -735.38)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_moveldup_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movemask_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1882468747), INT32_C(  687119108), INT32_C(  990615051), INT32_C(-1253009356),
                            INT32_C( -617641993), INT32_C(-1788847115), INT32_C( 1286496634), INT32_C( -717001088)),
      157 },
    { simde_mm256_set_epi32(INT32_C(-1989003409), INT32_C(-1421574364), INT32_C( -382909714), INT32_C( 1867671217),
                            INT32_C( -487294761), INT32_C( -454003817), INT32_C(  -33445130), INT32_C( -757457478)),
      239 },
    { simde_mm256_set_epi32(INT32_C(   75750543), INT32_C( -792015200), INT32_C( -456366441), INT32_C( 1395825015),
                            INT32_C( 1090607410), INT32_C( -644107645), INT32_C( 2024077315), INT32_C( 1442543377)),
      100 },
    { simde_mm256_set_epi32(INT32_C(   64842844), INT32_C(-1499432736), INT32_C( -849672143), INT32_C(  808386603),
                            INT32_C( 1431766696), INT32_C(  778893676), INT32_C(   -4359592), INT32_C( -465691700)),
      99 },
    { simde_mm256_set_epi32(INT32_C(-1142593030), INT32_C( 1697913004), INT32_C(-1241903623), INT32_C( 1420498198),
                            INT32_C( 1725730120), INT32_C( 1757719770), INT32_C( 1834101516), INT32_C(-1076410946)),
      161 },
    { simde_mm256_set_epi32(INT32_C( -247458634), INT32_C(  497266182), INT32_C(  668953611), INT32_C( -198408792),
                            INT32_C(  443042962), INT32_C(  174399567), INT32_C( 1910223665), INT32_C( 1408104689)),
      144 },
    { simde_mm256_set_epi32(INT32_C( 1266303831), INT32_C(-1981624404), INT32_C( 1894718767), INT32_C( 1471458198),
                            INT32_C(-1698669031), INT32_C(-1514661026), INT32_C(-1880466849), INT32_C(-1226909311)),
      79 },
    { simde_mm256_set_epi32(INT32_C( 1314135938), INT32_C( 1476193225), INT32_C( 1478701126), INT32_C( 1097128360),
                            INT32_C( -681267332), INT32_C( -854863432), INT32_C(-1814679036), INT32_C( 2077413591)),
      14 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_movemask_ps(simde_mm256_castsi256_ps(test_vec[i].a));
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_movemask_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-3476114617639449125), INT64_C( 4174348817044283167),
                             INT64_C( 2372823762134739460), INT64_C( 2922754125044459603)),
      8 },
    { simde_mm256_set_epi64x(INT64_C( 2977848152908728188), INT64_C(-9001314161736319662),
                             INT64_C(  316358866512427816), INT64_C(  122734419977663898)),
      4 },
    { simde_mm256_set_epi64x(INT64_C( 1458362257601867464), INT64_C(-2204086314119824728),
                             INT64_C( 4226262178485377739), INT64_C( 3412235452127467527)),
      4 },
    { simde_mm256_set_epi64x(INT64_C(-3206742534496437425), INT64_C( 4783689227782243759),
                             INT64_C(-2969411634419391796), INT64_C( 6490543198836487087)),
      10 },
    { simde_mm256_set_epi64x(INT64_C( 5617129527752259343), INT64_C( 8836429733868806831),
                             INT64_C(-3648376369890579220), INT64_C( 2974368927295586543)),
      2 },
    { simde_mm256_set_epi64x(INT64_C(-7634385432411504297), INT64_C( 7257505416389479780),
                             INT64_C( 7838438756599446984), INT64_C( 8814240438147347165)),
      8 },
    { simde_mm256_set_epi64x(INT64_C( 9071444056306285548), INT64_C( 8310979399473657009),
                             INT64_C(-1777863912628705993), INT64_C( 4472167403670196676)),
      2 },
    { simde_mm256_set_epi64x(INT64_C(-6555517372143397251), INT64_C( 2575855241209659630),
                             INT64_C(-8431720993701553511), INT64_C( -874276281105343662)),
      11 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_movemask_pd(simde_mm256_castsi256_pd(test_vec[i].a));
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mul_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -65.11), SIMDE_FLOAT32_C(  729.63),
                         SIMDE_FLOAT32_C(  579.86), SIMDE_FLOAT32_C(  759.34),
                         SIMDE_FLOAT32_C(  638.63), SIMDE_FLOAT32_C(  366.71),
                         SIMDE_FLOAT32_C( -251.89), SIMDE_FLOAT32_C( -327.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -853.75), SIMDE_FLOAT32_C(  306.50),
                         SIMDE_FLOAT32_C( -694.30), SIMDE_FLOAT32_C(   62.03),
                         SIMDE_FLOAT32_C( -332.43), SIMDE_FLOAT32_C( -617.58),
                         SIMDE_FLOAT32_C( -841.05), SIMDE_FLOAT32_C( -990.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(55587.66), SIMDE_FLOAT32_C(223631.59),
                         SIMDE_FLOAT32_C(-402596.78), SIMDE_FLOAT32_C(47101.86),
                         SIMDE_FLOAT32_C(-212299.77), SIMDE_FLOAT32_C(-226472.77),
                         SIMDE_FLOAT32_C(211852.08), SIMDE_FLOAT32_C(324721.22)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -540.24), SIMDE_FLOAT32_C(  599.92),
                         SIMDE_FLOAT32_C(  946.63), SIMDE_FLOAT32_C(  269.39),
                         SIMDE_FLOAT32_C(  990.71), SIMDE_FLOAT32_C(  736.78),
                         SIMDE_FLOAT32_C(  735.17), SIMDE_FLOAT32_C( -839.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -471.86), SIMDE_FLOAT32_C(  231.47),
                         SIMDE_FLOAT32_C(  368.19), SIMDE_FLOAT32_C( -199.69),
                         SIMDE_FLOAT32_C( -781.21), SIMDE_FLOAT32_C( -576.81),
                         SIMDE_FLOAT32_C( -351.44), SIMDE_FLOAT32_C(  650.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(254917.64), SIMDE_FLOAT32_C(138863.48),
                         SIMDE_FLOAT32_C(348539.72), SIMDE_FLOAT32_C(-53794.49),
                         SIMDE_FLOAT32_C(-773952.62), SIMDE_FLOAT32_C(-424982.09),
                         SIMDE_FLOAT32_C(-258368.14), SIMDE_FLOAT32_C(-546355.19)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  174.33), SIMDE_FLOAT32_C( -261.00),
                         SIMDE_FLOAT32_C(  947.71), SIMDE_FLOAT32_C(  -39.38),
                         SIMDE_FLOAT32_C( -142.31), SIMDE_FLOAT32_C( -753.91),
                         SIMDE_FLOAT32_C( -304.55), SIMDE_FLOAT32_C(  197.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -894.79), SIMDE_FLOAT32_C(  298.89),
                         SIMDE_FLOAT32_C(  413.08), SIMDE_FLOAT32_C(   45.44),
                         SIMDE_FLOAT32_C( -362.24), SIMDE_FLOAT32_C(  247.39),
                         SIMDE_FLOAT32_C( -836.15), SIMDE_FLOAT32_C(  250.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-155988.73), SIMDE_FLOAT32_C(-78010.30),
                         SIMDE_FLOAT32_C(391480.03), SIMDE_FLOAT32_C(-1789.43),
                         SIMDE_FLOAT32_C(51550.37), SIMDE_FLOAT32_C(-186509.78),
                         SIMDE_FLOAT32_C(254649.48), SIMDE_FLOAT32_C(49367.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -108.81), SIMDE_FLOAT32_C( -144.46),
                         SIMDE_FLOAT32_C( -926.46), SIMDE_FLOAT32_C(  -87.02),
                         SIMDE_FLOAT32_C( -701.58), SIMDE_FLOAT32_C(  412.02),
                         SIMDE_FLOAT32_C( -404.71), SIMDE_FLOAT32_C( -140.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -502.46), SIMDE_FLOAT32_C( -741.60),
                         SIMDE_FLOAT32_C(  261.69), SIMDE_FLOAT32_C( -236.88),
                         SIMDE_FLOAT32_C(  805.45), SIMDE_FLOAT32_C(  663.49),
                         SIMDE_FLOAT32_C(  804.65), SIMDE_FLOAT32_C( -231.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(54672.67), SIMDE_FLOAT32_C(107131.54),
                         SIMDE_FLOAT32_C(-242445.33), SIMDE_FLOAT32_C(20613.30),
                         SIMDE_FLOAT32_C(-565087.62), SIMDE_FLOAT32_C(273371.12),
                         SIMDE_FLOAT32_C(-325649.91), SIMDE_FLOAT32_C(32378.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  274.12), SIMDE_FLOAT32_C(  417.28),
                         SIMDE_FLOAT32_C(  626.47), SIMDE_FLOAT32_C(  541.42),
                         SIMDE_FLOAT32_C( -351.86), SIMDE_FLOAT32_C(  144.88),
                         SIMDE_FLOAT32_C( -692.65), SIMDE_FLOAT32_C(  994.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -588.84), SIMDE_FLOAT32_C(  440.91),
                         SIMDE_FLOAT32_C( -668.35), SIMDE_FLOAT32_C(  950.11),
                         SIMDE_FLOAT32_C(   38.08), SIMDE_FLOAT32_C( -877.72),
                         SIMDE_FLOAT32_C(  389.76), SIMDE_FLOAT32_C(  702.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-161412.83), SIMDE_FLOAT32_C(183982.92),
                         SIMDE_FLOAT32_C(-418701.19), SIMDE_FLOAT32_C(514408.53),
                         SIMDE_FLOAT32_C(-13398.83), SIMDE_FLOAT32_C(-127164.07),
                         SIMDE_FLOAT32_C(-269967.28), SIMDE_FLOAT32_C(698361.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.46), SIMDE_FLOAT32_C( -957.98),
                         SIMDE_FLOAT32_C(  872.62), SIMDE_FLOAT32_C( -600.00),
                         SIMDE_FLOAT32_C(  937.99), SIMDE_FLOAT32_C( -698.26),
                         SIMDE_FLOAT32_C(  895.96), SIMDE_FLOAT32_C( -799.53)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -864.38), SIMDE_FLOAT32_C( -416.69),
                         SIMDE_FLOAT32_C(  894.78), SIMDE_FLOAT32_C(  968.43),
                         SIMDE_FLOAT32_C(  609.48), SIMDE_FLOAT32_C(  317.20),
                         SIMDE_FLOAT32_C(  767.37), SIMDE_FLOAT32_C(  -51.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(62632.97), SIMDE_FLOAT32_C(399180.69),
                         SIMDE_FLOAT32_C(780802.94), SIMDE_FLOAT32_C(-581058.00),
                         SIMDE_FLOAT32_C(571686.12), SIMDE_FLOAT32_C(-221488.08),
                         SIMDE_FLOAT32_C(687532.81), SIMDE_FLOAT32_C(41319.71)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -131.07), SIMDE_FLOAT32_C( -294.47),
                         SIMDE_FLOAT32_C( -916.92), SIMDE_FLOAT32_C(  146.62),
                         SIMDE_FLOAT32_C(  597.05), SIMDE_FLOAT32_C(   75.62),
                         SIMDE_FLOAT32_C(  636.06), SIMDE_FLOAT32_C(  363.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  427.08), SIMDE_FLOAT32_C( -105.65),
                         SIMDE_FLOAT32_C(   98.05), SIMDE_FLOAT32_C(  398.71),
                         SIMDE_FLOAT32_C( -883.53), SIMDE_FLOAT32_C( -434.31),
                         SIMDE_FLOAT32_C(  638.77), SIMDE_FLOAT32_C( -453.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-55977.38), SIMDE_FLOAT32_C(31110.76),
                         SIMDE_FLOAT32_C(-89904.01), SIMDE_FLOAT32_C(58458.86),
                         SIMDE_FLOAT32_C(-527511.56), SIMDE_FLOAT32_C(-32842.52),
                         SIMDE_FLOAT32_C(406296.06), SIMDE_FLOAT32_C(-164826.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  401.83), SIMDE_FLOAT32_C( -101.21),
                         SIMDE_FLOAT32_C( -199.00), SIMDE_FLOAT32_C(  823.62),
                         SIMDE_FLOAT32_C( -930.84), SIMDE_FLOAT32_C( -154.42),
                         SIMDE_FLOAT32_C(  958.59), SIMDE_FLOAT32_C(  853.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -449.55), SIMDE_FLOAT32_C(  354.78),
                         SIMDE_FLOAT32_C( -131.96), SIMDE_FLOAT32_C( -519.93),
                         SIMDE_FLOAT32_C(  699.65), SIMDE_FLOAT32_C(  781.77),
                         SIMDE_FLOAT32_C( -157.96), SIMDE_FLOAT32_C( -793.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-180642.67), SIMDE_FLOAT32_C(-35907.29),
                         SIMDE_FLOAT32_C(26260.04), SIMDE_FLOAT32_C(-428224.75),
                         SIMDE_FLOAT32_C(-651262.25), SIMDE_FLOAT32_C(-120720.92),
                         SIMDE_FLOAT32_C(-151418.89), SIMDE_FLOAT32_C(-677377.38)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_mul_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_mul_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -216.07), SIMDE_FLOAT64_C(   -759.70),
                         SIMDE_FLOAT64_C(   -257.81), SIMDE_FLOAT64_C(    916.82)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -279.71), SIMDE_FLOAT64_C(    654.36),
                         SIMDE_FLOAT64_C(   -699.07), SIMDE_FLOAT64_C(    772.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  60436.94), SIMDE_FLOAT64_C(-497117.29),
                         SIMDE_FLOAT64_C( 180227.24), SIMDE_FLOAT64_C( 707922.56)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -576.02), SIMDE_FLOAT64_C(   -915.91),
                         SIMDE_FLOAT64_C(    616.42), SIMDE_FLOAT64_C(    692.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    285.52), SIMDE_FLOAT64_C(   -538.61),
                         SIMDE_FLOAT64_C(    604.61), SIMDE_FLOAT64_C(   -220.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-164465.23), SIMDE_FLOAT64_C( 493318.29),
                         SIMDE_FLOAT64_C( 372693.70), SIMDE_FLOAT64_C(-152619.76)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -378.41), SIMDE_FLOAT64_C(   -782.44),
                         SIMDE_FLOAT64_C(   -858.38), SIMDE_FLOAT64_C(   -932.65)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    782.91), SIMDE_FLOAT64_C(    352.73),
                         SIMDE_FLOAT64_C(    705.00), SIMDE_FLOAT64_C(    -78.46)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-296260.97), SIMDE_FLOAT64_C(-275990.06),
                         SIMDE_FLOAT64_C(-605157.90), SIMDE_FLOAT64_C(  73175.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   -936.48), SIMDE_FLOAT64_C(    274.43),
                         SIMDE_FLOAT64_C(    341.69), SIMDE_FLOAT64_C(    588.43)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -915.35), SIMDE_FLOAT64_C(    625.98),
                         SIMDE_FLOAT64_C(    -66.28), SIMDE_FLOAT64_C(   -474.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( 857206.97), SIMDE_FLOAT64_C( 171787.69),
                         SIMDE_FLOAT64_C( -22647.21), SIMDE_FLOAT64_C(-279115.89)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(    371.75), SIMDE_FLOAT64_C(   -392.05),
                         SIMDE_FLOAT64_C(   -730.60), SIMDE_FLOAT64_C(    399.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -409.43), SIMDE_FLOAT64_C(    920.37),
                         SIMDE_FLOAT64_C(    -56.28), SIMDE_FLOAT64_C(   -779.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-152205.60), SIMDE_FLOAT64_C(-360831.06),
                         SIMDE_FLOAT64_C(  41118.17), SIMDE_FLOAT64_C(-311248.62)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     -0.10), SIMDE_FLOAT64_C(    955.19),
                         SIMDE_FLOAT64_C(    162.40), SIMDE_FLOAT64_C(   -236.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -741.60), SIMDE_FLOAT64_C(    194.99),
                         SIMDE_FLOAT64_C(    845.16), SIMDE_FLOAT64_C(    363.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(     74.16), SIMDE_FLOAT64_C( 186252.50),
                         SIMDE_FLOAT64_C( 137253.98), SIMDE_FLOAT64_C( -85763.67)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     18.23), SIMDE_FLOAT64_C(    296.33),
                         SIMDE_FLOAT64_C(    628.43), SIMDE_FLOAT64_C(   -660.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    -24.23), SIMDE_FLOAT64_C(    573.95),
                         SIMDE_FLOAT64_C(    350.37), SIMDE_FLOAT64_C(   -979.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -441.71), SIMDE_FLOAT64_C( 170078.60),
                         SIMDE_FLOAT64_C( 220183.02), SIMDE_FLOAT64_C( 646661.61)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(     14.47), SIMDE_FLOAT64_C(    780.26),
                         SIMDE_FLOAT64_C(   -875.01), SIMDE_FLOAT64_C(    609.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    690.47), SIMDE_FLOAT64_C(   -614.79),
                         SIMDE_FLOAT64_C(    626.96), SIMDE_FLOAT64_C(   -369.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   9991.10), SIMDE_FLOAT64_C(-479696.05),
                         SIMDE_FLOAT64_C(-548596.27), SIMDE_FLOAT64_C(-224937.13)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_mul_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_or_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -856.34), SIMDE_FLOAT32_C(   -251.54),
                         SIMDE_FLOAT32_C(    873.84), SIMDE_FLOAT32_C(    282.56),
                         SIMDE_FLOAT32_C(   -701.43), SIMDE_FLOAT32_C(    881.08),
                         SIMDE_FLOAT32_C(    949.17), SIMDE_FLOAT32_C(    -70.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     13.03), SIMDE_FLOAT32_C(   -213.71),
                         SIMDE_FLOAT32_C(   -960.05), SIMDE_FLOAT32_C(     76.97),
                         SIMDE_FLOAT32_C(    529.10), SIMDE_FLOAT32_C(   -768.23),
                         SIMDE_FLOAT32_C(    808.48), SIMDE_FLOAT32_C(   -237.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -3431.99), SIMDE_FLOAT32_C(   -255.75),
                         SIMDE_FLOAT32_C(  -1001.87), SIMDE_FLOAT32_C(    315.93),
                         SIMDE_FLOAT32_C(   -701.50), SIMDE_FLOAT32_C(   -881.25),
                         SIMDE_FLOAT32_C(    957.48), SIMDE_FLOAT32_C(   -474.81)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    222.49), SIMDE_FLOAT32_C(    898.11),
                         SIMDE_FLOAT32_C(   -986.95), SIMDE_FLOAT32_C(   -624.89),
                         SIMDE_FLOAT32_C(   -780.02), SIMDE_FLOAT32_C(    920.74),
                         SIMDE_FLOAT32_C(    815.92), SIMDE_FLOAT32_C(    550.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -274.50), SIMDE_FLOAT32_C(    377.51),
                         SIMDE_FLOAT32_C(    595.96), SIMDE_FLOAT32_C(    513.30),
                         SIMDE_FLOAT32_C(    235.21), SIMDE_FLOAT32_C(    -45.95),
                         SIMDE_FLOAT32_C(    722.85), SIMDE_FLOAT32_C(    781.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -446.98), SIMDE_FLOAT32_C( 129422.58),
                         SIMDE_FLOAT32_C(   -987.97), SIMDE_FLOAT32_C(   -625.94),
                         SIMDE_FLOAT32_C( -60213.79), SIMDE_FLOAT32_C( -15867.97),
                         SIMDE_FLOAT32_C(   1023.98), SIMDE_FLOAT32_C(    815.93)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -789.64), SIMDE_FLOAT32_C(    957.16),
                         SIMDE_FLOAT32_C(   -431.62), SIMDE_FLOAT32_C(    527.46),
                         SIMDE_FLOAT32_C(   -345.54), SIMDE_FLOAT32_C(   -528.90),
                         SIMDE_FLOAT32_C(   -257.76), SIMDE_FLOAT32_C(    194.98)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    966.68), SIMDE_FLOAT32_C(    513.70),
                         SIMDE_FLOAT32_C(    151.32), SIMDE_FLOAT32_C(   -424.41),
                         SIMDE_FLOAT32_C(   -411.73), SIMDE_FLOAT32_C(    846.41),
                         SIMDE_FLOAT32_C(    151.87), SIMDE_FLOAT32_C(   -542.65)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -983.69), SIMDE_FLOAT32_C(    957.73),
                         SIMDE_FLOAT32_C(   -431.75), SIMDE_FLOAT32_C(-110586.96),
                         SIMDE_FLOAT32_C(   -475.73), SIMDE_FLOAT32_C(   -862.93),
                         SIMDE_FLOAT32_C(   -304.00), SIMDE_FLOAT32_C( -51195.98)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -998.71), SIMDE_FLOAT32_C(   -667.81),
                         SIMDE_FLOAT32_C(     67.10), SIMDE_FLOAT32_C(   -760.87),
                         SIMDE_FLOAT32_C(   -217.54), SIMDE_FLOAT32_C(    503.65),
                         SIMDE_FLOAT32_C(    247.04), SIMDE_FLOAT32_C(    844.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    661.94), SIMDE_FLOAT32_C(   -209.04),
                         SIMDE_FLOAT32_C(    -75.64), SIMDE_FLOAT32_C(   -274.76),
                         SIMDE_FLOAT32_C(   -442.04), SIMDE_FLOAT32_C(   -562.29),
                         SIMDE_FLOAT32_C(   -151.20), SIMDE_FLOAT32_C(    897.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -1015.96), SIMDE_FLOAT32_C( -63484.00),
                         SIMDE_FLOAT32_C(    -75.73), SIMDE_FLOAT32_C( -98031.86),
                         SIMDE_FLOAT32_C(   -443.12), SIMDE_FLOAT32_C(-130983.49),
                         SIMDE_FLOAT32_C(   -247.23), SIMDE_FLOAT32_C(    973.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    413.34), SIMDE_FLOAT32_C(    969.02),
                         SIMDE_FLOAT32_C(   -337.47), SIMDE_FLOAT32_C(   -324.75),
                         SIMDE_FLOAT32_C(   -193.88), SIMDE_FLOAT32_C(   -534.97),
                         SIMDE_FLOAT32_C(    873.51), SIMDE_FLOAT32_C(   -141.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -783.17), SIMDE_FLOAT32_C(    718.95),
                         SIMDE_FLOAT32_C(    707.27), SIMDE_FLOAT32_C(   -573.61),
                         SIMDE_FLOAT32_C(   -268.73), SIMDE_FLOAT32_C(    245.35),
                         SIMDE_FLOAT32_C(    309.36), SIMDE_FLOAT32_C(   -248.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-106455.79), SIMDE_FLOAT32_C(    975.97),
                         SIMDE_FLOAT32_C( -94714.82), SIMDE_FLOAT32_C( -89806.08),
                         SIMDE_FLOAT32_C(   -399.98), SIMDE_FLOAT32_C( -62975.62),
                         SIMDE_FLOAT32_C( 112093.41), SIMDE_FLOAT32_C(   -253.95)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -788.80), SIMDE_FLOAT32_C(   -153.54),
                         SIMDE_FLOAT32_C(    281.95), SIMDE_FLOAT32_C(    256.34),
                         SIMDE_FLOAT32_C(   -635.81), SIMDE_FLOAT32_C(   -147.12),
                         SIMDE_FLOAT32_C(   -744.53), SIMDE_FLOAT32_C(    799.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(      2.25), SIMDE_FLOAT32_C(    -53.24),
                         SIMDE_FLOAT32_C(    690.38), SIMDE_FLOAT32_C(    776.59),
                         SIMDE_FLOAT32_C(   -713.17), SIMDE_FLOAT32_C(   -856.98),
                         SIMDE_FLOAT32_C(   -302.74), SIMDE_FLOAT32_C(    409.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -852.80), SIMDE_FLOAT32_C(   -222.00),
                         SIMDE_FLOAT32_C(  88563.70), SIMDE_FLOAT32_C(  99423.55),
                         SIMDE_FLOAT32_C(   -763.94), SIMDE_FLOAT32_C( -55102.72),
                         SIMDE_FLOAT32_C( -98047.97), SIMDE_FLOAT32_C( 106487.99)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   -404.76), SIMDE_FLOAT32_C(   -875.24),
                         SIMDE_FLOAT32_C(    822.92), SIMDE_FLOAT32_C(    409.42),
                         SIMDE_FLOAT32_C(    144.27), SIMDE_FLOAT32_C(    260.67),
                         SIMDE_FLOAT32_C(    383.19), SIMDE_FLOAT32_C(    173.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -913.39), SIMDE_FLOAT32_C(   -747.11),
                         SIMDE_FLOAT32_C(    262.13), SIMDE_FLOAT32_C(    535.89),
                         SIMDE_FLOAT32_C(   -513.17), SIMDE_FLOAT32_C(    945.43),
                         SIMDE_FLOAT32_C(    473.23), SIMDE_FLOAT32_C(    594.31)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-122099.98), SIMDE_FLOAT32_C(  -1003.24),
                         SIMDE_FLOAT32_C( 106357.79), SIMDE_FLOAT32_C( 105467.93),
                         SIMDE_FLOAT32_C( -36944.00), SIMDE_FLOAT32_C( 122047.55),
                         SIMDE_FLOAT32_C(    511.23), SIMDE_FLOAT32_C(  48543.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(    255.64), SIMDE_FLOAT32_C(    352.54),
                         SIMDE_FLOAT32_C(    905.17), SIMDE_FLOAT32_C(    -97.04),
                         SIMDE_FLOAT32_C(    635.19), SIMDE_FLOAT32_C(   -653.37),
                         SIMDE_FLOAT32_C(    871.87), SIMDE_FLOAT32_C(   -471.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -534.86), SIMDE_FLOAT32_C(     20.68),
                         SIMDE_FLOAT32_C(    963.33), SIMDE_FLOAT32_C(   -431.12),
                         SIMDE_FLOAT32_C(    199.08), SIMDE_FLOAT32_C(    684.85),
                         SIMDE_FLOAT32_C(   -893.07), SIMDE_FLOAT32_C(   -817.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -65463.87), SIMDE_FLOAT32_C(    362.92),
                         SIMDE_FLOAT32_C(    971.50), SIMDE_FLOAT32_C(   -431.25),
                         SIMDE_FLOAT32_C(  57308.48), SIMDE_FLOAT32_C(   -685.87),
                         SIMDE_FLOAT32_C(   -895.87), SIMDE_FLOAT32_C(-122879.96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_or_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_or_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -465239073), INT32_C( 1279184195), INT32_C( 2016764339), INT32_C(-2145324536),
                            INT32_C(-1764212445), INT32_C(  366604460), INT32_C( 2076865232), INT32_C( -193563958)),
      simde_mm256_set_epi32(INT32_C(  541400396), INT32_C( -972933189), INT32_C(  510962050), INT32_C( -823731197),
                            INT32_C(  -98096262), INT32_C( -873938367), INT32_C(  832486509), INT32_C(-1258790386)),
      simde_mm256_set_epi32(INT32_C( -465231905), INT32_C( -834732037), INT32_C( 2121656755), INT32_C( -823722485),
                            INT32_C(  -16815237), INT32_C( -537267475), INT32_C( 2078211837), INT32_C( -184651058)) },
    { simde_mm256_set_epi32(INT32_C( -357268810), INT32_C( -651759515), INT32_C(  235257662), INT32_C( -710907048),
                            INT32_C(-1810919865), INT32_C( 1157547055), INT32_C(-1536937137), INT32_C( 1736416320)),
      simde_mm256_set_epi32(INT32_C( -849859400), INT32_C(  -22261753), INT32_C(-1893529894), INT32_C( -986693653),
                            INT32_C( -263776240), INT32_C(  502458571), INT32_C( -753857515), INT32_C(-1100300353)),
      simde_mm256_set_epi32(INT32_C( -268652866), INT32_C(   -5312409), INT32_C(-1893220354), INT32_C( -709853189),
                            INT32_C( -196108713), INT32_C( 1576987887), INT32_C( -143311009), INT32_C(   -8404993)) },
    { simde_mm256_set_epi32(INT32_C(-1390025255), INT32_C(  226124884), INT32_C( 1790052194), INT32_C( -108567495),
                            INT32_C( 1678439305), INT32_C(  946188942), INT32_C(-2005442113), INT32_C(-1348041469)),
      simde_mm256_set_epi32(INT32_C(  575705169), INT32_C(-1737321258), INT32_C(-1640691781), INT32_C( -551468190),
                            INT32_C( 1952646913), INT32_C( 1393751647), INT32_C(-1388496514), INT32_C(  590324192)),
      simde_mm256_set_epi32(INT32_C(-1351223847), INT32_C(-1652886314), INT32_C(  -21559301), INT32_C(   -5806213),
                            INT32_C( 1953232777), INT32_C( 2071459551), INT32_C(-1384154625), INT32_C(-1347443229)) },
    { simde_mm256_set_epi32(INT32_C(-1745763744), INT32_C( -289111572), INT32_C( -806274679), INT32_C( 1716472169),
                            INT32_C( 1235124509), INT32_C(   -2416200), INT32_C( -718461715), INT32_C(-2068168100)),
      simde_mm256_set_epi32(INT32_C( -747913617), INT32_C( 1661223449), INT32_C(  458600484), INT32_C(-1412075388),
                            INT32_C( 1069408970), INT32_C( 1945090076), INT32_C( -553357992), INT32_C(-1440436522)),
      simde_mm256_set_epi32(INT32_C( -671351185), INT32_C( -272317443), INT32_C( -537544275), INT32_C( -270566931),
                            INT32_C( 2143282143), INT32_C(     -17988), INT32_C( -550670851), INT32_C(-1363218722)) },
    { simde_mm256_set_epi32(INT32_C(-1244409590), INT32_C( 1807868489), INT32_C(  -47548399), INT32_C( 1894098437),
                            INT32_C(-1418958797), INT32_C( -739449954), INT32_C(  531303833), INT32_C( -582313126)),
      simde_mm256_set_epi32(INT32_C(  357521808), INT32_C( 1489594358), INT32_C(-1693320213), INT32_C( 1373628776),
                            INT32_C( -817392977), INT32_C( -536101335), INT32_C( 1011260304), INT32_C(  796312463)),
      simde_mm256_set_epi32(INT32_C(-1243620966), INT32_C( 2076829695), INT32_C(  -12846085), INT32_C( 1912598381),
                            INT32_C( -277873985), INT32_C( -202375233), INT32_C( 1072668569), INT32_C(   -8463393)) },
    { simde_mm256_set_epi32(INT32_C(-1207931928), INT32_C( -834187886), INT32_C(  -41133883), INT32_C( 1826519423),
                            INT32_C(-1537225150), INT32_C(-1972742802), INT32_C(-1107144372), INT32_C( 2074601373)),
      simde_mm256_set_epi32(INT32_C( 1198219345), INT32_C(  680764868), INT32_C( 1929177864), INT32_C( 1458999019),
                            INT32_C(  847246989), INT32_C(  902092277), INT32_C(   17517725), INT32_C(  814431018)),
      simde_mm256_set_epi32(INT32_C(   -9737223), INT32_C( -287838762), INT32_C(    -197683), INT32_C( 2130640895),
                            INT32_C(-1233125681), INT32_C(-1074866689), INT32_C(-1089774115), INT32_C( 2075131839)) },
    { simde_mm256_set_epi32(INT32_C( -137211173), INT32_C( -663911731), INT32_C( 1607469024), INT32_C( -419979231),
                            INT32_C( 1165074553), INT32_C( 1528925488), INT32_C(-1523385372), INT32_C( -907053265)),
      simde_mm256_set_epi32(INT32_C(  994086113), INT32_C(  702992700), INT32_C( -270545927), INT32_C( -490915434),
                            INT32_C( -743254762), INT32_C(   48033191), INT32_C(-2091867903), INT32_C( -756059930)),
      simde_mm256_set_epi32(INT32_C(   -2957573), INT32_C( -101723139), INT32_C(   -2109447), INT32_C( -419448393),
                            INT32_C( -671877761), INT32_C( 1543368119), INT32_C(-1485636635), INT32_C( -605063185)) },
    { simde_mm256_set_epi32(INT32_C( 1358203904), INT32_C(  915012873), INT32_C( 1992547669), INT32_C(-1717736064),
                            INT32_C(-1421704847), INT32_C(-1530428724), INT32_C(  686978685), INT32_C(  376599363)),
      simde_mm256_set_epi32(INT32_C(  963177670), INT32_C( -310024670), INT32_C(-1429164258), INT32_C(  390666975),
                            INT32_C( -901190881), INT32_C(-1166820314), INT32_C( 2002591871), INT32_C( -569097185)),
      simde_mm256_set_epi32(INT32_C( 2046618822), INT32_C(   -7471317), INT32_C(  -19660961), INT32_C(-1612873761),
                            INT32_C( -347411585), INT32_C(-1091059986), INT32_C( 2147448447), INT32_C( -562661537)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_castpd_si256(simde_mm256_or_pd(simde_mm256_castsi256_pd(test_vec[i].a), simde_mm256_castsi256_pd(test_vec[i].b)));
    simde_assert_m256i_equal(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    struct {
      simde__m256 a;
      simde__m256 r;
    } p[8];
  } test_vec[1] = {
    {
      {
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -139.04), SIMDE_FLOAT32_C( -911.51),
                             SIMDE_FLOAT32_C(  580.20), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C( -878.62), SIMDE_FLOAT32_C( -797.57),
                             SIMDE_FLOAT32_C( -426.64), SIMDE_FLOAT32_C( -818.52)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  982.03), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C(  982.03), SIMDE_FLOAT32_C(  982.03),
                             SIMDE_FLOAT32_C( -818.52), SIMDE_FLOAT32_C( -818.52),
                             SIMDE_FLOAT32_C( -818.52), SIMDE_FLOAT32_C( -818.52)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -946.18), SIMDE_FLOAT32_C(  580.43),
                             SIMDE_FLOAT32_C(  276.12), SIMDE_FLOAT32_C(  862.54),
                             SIMDE_FLOAT32_C(  664.35), SIMDE_FLOAT32_C(  162.22),
                             SIMDE_FLOAT32_C(  234.37), SIMDE_FLOAT32_C(  188.86)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  862.54), SIMDE_FLOAT32_C(  862.54),
                             SIMDE_FLOAT32_C(  862.54), SIMDE_FLOAT32_C(  276.12),
                             SIMDE_FLOAT32_C(  188.86), SIMDE_FLOAT32_C(  188.86),
                             SIMDE_FLOAT32_C(  188.86), SIMDE_FLOAT32_C(  234.37)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -799.19), SIMDE_FLOAT32_C( -835.77),
                             SIMDE_FLOAT32_C( -716.61), SIMDE_FLOAT32_C(  614.58),
                             SIMDE_FLOAT32_C(  366.48), SIMDE_FLOAT32_C(  294.53),
                             SIMDE_FLOAT32_C( -368.14), SIMDE_FLOAT32_C(  638.90)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  614.58), SIMDE_FLOAT32_C(  614.58),
                             SIMDE_FLOAT32_C(  614.58), SIMDE_FLOAT32_C( -835.77),
                             SIMDE_FLOAT32_C(  638.90), SIMDE_FLOAT32_C(  638.90),
                             SIMDE_FLOAT32_C(  638.90), SIMDE_FLOAT32_C(  294.53)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  141.00), SIMDE_FLOAT32_C( -110.45),
                             SIMDE_FLOAT32_C( -302.60), SIMDE_FLOAT32_C( -332.94),
                             SIMDE_FLOAT32_C(  188.73), SIMDE_FLOAT32_C(  551.54),
                             SIMDE_FLOAT32_C( -580.84), SIMDE_FLOAT32_C(  854.95)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -332.94), SIMDE_FLOAT32_C( -332.94),
                             SIMDE_FLOAT32_C( -332.94), SIMDE_FLOAT32_C(  141.00),
                             SIMDE_FLOAT32_C(  854.95), SIMDE_FLOAT32_C(  854.95),
                             SIMDE_FLOAT32_C(  854.95), SIMDE_FLOAT32_C(  188.73)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  655.95), SIMDE_FLOAT32_C( -740.30),
                             SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C(   67.66), SIMDE_FLOAT32_C(  990.02),
                             SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  470.48)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -434.04), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C( -946.00), SIMDE_FLOAT32_C( -434.04),
                             SIMDE_FLOAT32_C(  470.48), SIMDE_FLOAT32_C(  470.48),
                             SIMDE_FLOAT32_C(  889.36), SIMDE_FLOAT32_C(  470.48)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C(  184.64), SIMDE_FLOAT32_C(  689.89),
                             SIMDE_FLOAT32_C(   66.41), SIMDE_FLOAT32_C(  657.41),
                             SIMDE_FLOAT32_C( -642.74), SIMDE_FLOAT32_C(  674.83),
                             SIMDE_FLOAT32_C( -458.59), SIMDE_FLOAT32_C( -735.59)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  657.41), SIMDE_FLOAT32_C(  657.41),
                             SIMDE_FLOAT32_C(   66.41), SIMDE_FLOAT32_C(   66.41),
                             SIMDE_FLOAT32_C( -735.59), SIMDE_FLOAT32_C( -735.59),
                             SIMDE_FLOAT32_C( -458.59), SIMDE_FLOAT32_C( -458.59)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -810.48), SIMDE_FLOAT32_C( -796.84),
                             SIMDE_FLOAT32_C(  173.69), SIMDE_FLOAT32_C(  -58.65),
                             SIMDE_FLOAT32_C( -873.61), SIMDE_FLOAT32_C( -813.18),
                             SIMDE_FLOAT32_C( -876.21), SIMDE_FLOAT32_C( -105.85)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C(  -58.65), SIMDE_FLOAT32_C(  -58.65),
                             SIMDE_FLOAT32_C(  173.69), SIMDE_FLOAT32_C( -796.84),
                             SIMDE_FLOAT32_C( -105.85), SIMDE_FLOAT32_C( -105.85),
                             SIMDE_FLOAT32_C( -876.21), SIMDE_FLOAT32_C( -813.18)) },
        { simde_mm256_set_ps(SIMDE_FLOAT32_C( -653.04), SIMDE_FLOAT32_C( -205.53),
                             SIMDE_FLOAT32_C(  -47.21), SIMDE_FLOAT32_C( -850.03),
                             SIMDE_FLOAT32_C( -120.73), SIMDE_FLOAT32_C( -663.03),
                             SIMDE_FLOAT32_C(  803.42), SIMDE_FLOAT32_C(  391.07)),
          simde_mm256_set_ps(SIMDE_FLOAT32_C( -850.03), SIMDE_FLOAT32_C( -850.03),
                             SIMDE_FLOAT32_C(  -47.21), SIMDE_FLOAT32_C( -653.04),
                             SIMDE_FLOAT32_C(  391.07), SIMDE_FLOAT32_C(  391.07),
                             SIMDE_FLOAT32_C(  803.42), SIMDE_FLOAT32_C( -120.73)) },
      },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;

    r = simde_mm256_permute_ps(test_vec[i].p[0].a, 0);
    simde_assert_m256_close(r, test_vec[i].p[0].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[1].a, 1);
    simde_assert_m256_close(r, test_vec[i].p[1].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[2].a, 2);
    simde_assert_m256_close(r, test_vec[i].p[2].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[3].a, 3);
    simde_assert_m256_close(r, test_vec[i].p[3].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[4].a, 4);
    simde_assert_m256_close(r, test_vec[i].p[4].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[5].a, 5);
    simde_assert_m256_close(r, test_vec[i].p[5].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[6].a, 6);
    simde_assert_m256_close(r, test_vec[i].p[6].r, 1);

    r = simde_mm256_permute_ps(test_vec[i].p[7].a, 7);
    simde_assert_m256_close(r, test_vec[i].p[7].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permute_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    struct {
      simde__m128d a;
      simde__m128d r;
    } p[4];
  } test_vec[8] = {
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -586.66), SIMDE_FLOAT64_C(  759.07)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  759.07), SIMDE_FLOAT64_C(  759.07)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  312.86), SIMDE_FLOAT64_C(  489.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  489.25), SIMDE_FLOAT64_C(  312.86)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  510.93), SIMDE_FLOAT64_C( -731.36)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  510.93), SIMDE_FLOAT64_C( -731.36)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  211.69), SIMDE_FLOAT64_C(  302.00)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  211.69), SIMDE_FLOAT64_C(  211.69)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  878.46), SIMDE_FLOAT64_C(  679.15)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  679.15), SIMDE_FLOAT64_C(  679.15)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -990.20), SIMDE_FLOAT64_C( -630.61)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -630.61), SIMDE_FLOAT64_C( -990.20)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  471.54), SIMDE_FLOAT64_C( -307.27)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  471.54), SIMDE_FLOAT64_C( -307.27)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  625.19), SIMDE_FLOAT64_C(  623.51)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  625.19), SIMDE_FLOAT64_C(  625.19)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  637.56), SIMDE_FLOAT64_C(  480.86)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  480.86), SIMDE_FLOAT64_C(  480.86)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -358.97), SIMDE_FLOAT64_C( -958.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -958.25), SIMDE_FLOAT64_C( -358.97)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  867.67), SIMDE_FLOAT64_C(  -39.52)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  867.67), SIMDE_FLOAT64_C(  -39.52)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  596.21), SIMDE_FLOAT64_C(  558.65)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  596.21), SIMDE_FLOAT64_C(  596.21)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   32.94), SIMDE_FLOAT64_C( -306.71)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -306.71), SIMDE_FLOAT64_C( -306.71)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  881.79), SIMDE_FLOAT64_C(  737.35)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  737.35), SIMDE_FLOAT64_C(  881.79)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  857.28), SIMDE_FLOAT64_C(  640.79)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  857.28), SIMDE_FLOAT64_C(  640.79)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  529.31), SIMDE_FLOAT64_C(  660.42)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  529.31), SIMDE_FLOAT64_C(  529.31)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -645.32), SIMDE_FLOAT64_C( -500.25)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -500.25), SIMDE_FLOAT64_C( -500.25)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -862.75), SIMDE_FLOAT64_C( -773.36)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -773.36), SIMDE_FLOAT64_C( -862.75)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  795.76), SIMDE_FLOAT64_C(  320.59)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  795.76), SIMDE_FLOAT64_C(  320.59)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -749.80), SIMDE_FLOAT64_C(  899.97)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -749.80), SIMDE_FLOAT64_C( -749.80)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  711.35), SIMDE_FLOAT64_C(  304.45)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  304.45), SIMDE_FLOAT64_C(  304.45)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  -92.64), SIMDE_FLOAT64_C(   45.68)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(   45.68), SIMDE_FLOAT64_C(  -92.64)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  261.59), SIMDE_FLOAT64_C(  207.13)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  261.59), SIMDE_FLOAT64_C(  207.13)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -540.32), SIMDE_FLOAT64_C(  -11.20)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -540.32), SIMDE_FLOAT64_C( -540.32)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   11.20), SIMDE_FLOAT64_C(  175.87)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  175.87), SIMDE_FLOAT64_C(  175.87)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  274.15), SIMDE_FLOAT64_C(  152.30)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  152.30), SIMDE_FLOAT64_C(  274.15)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  673.19), SIMDE_FLOAT64_C(  979.94)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  673.19), SIMDE_FLOAT64_C(  979.94)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(   36.65), SIMDE_FLOAT64_C( -391.85)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(   36.65), SIMDE_FLOAT64_C(   36.65)) },
      },
    },
    {
      {
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -950.12), SIMDE_FLOAT64_C( -979.88)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -979.88), SIMDE_FLOAT64_C( -979.88)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C(  910.59), SIMDE_FLOAT64_C(  380.41)),
          simde_mm_set_pd(SIMDE_FLOAT64_C(  380.41), SIMDE_FLOAT64_C(  910.59)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -731.74), SIMDE_FLOAT64_C(  314.11)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -731.74), SIMDE_FLOAT64_C(  314.11)) },
        { simde_mm_set_pd(SIMDE_FLOAT64_C( -794.00), SIMDE_FLOAT64_C( -659.77)),
          simde_mm_set_pd(SIMDE_FLOAT64_C( -794.00), SIMDE_FLOAT64_C( -794.00)) },
      },
    }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r;

    r = simde_mm_permute_pd(test_vec[i].p[0].a, 0);
    simde_assert_m128d_close(r, test_vec[i].p[0].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[1].a, 1);
    simde_assert_m128d_close(r, test_vec[i].p[1].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[2].a, 2);
    simde_assert_m128d_close(r, test_vec[i].p[2].r, 1);

    r = simde_mm_permute_pd(test_vec[i].p[3].a, 3);
    simde_assert_m128d_close(r, test_vec[i].p[3].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permute_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   -46.54), SIMDE_FLOAT32_C(  -884.02), SIMDE_FLOAT32_C(  -125.85), SIMDE_FLOAT32_C(  -211.36)),
      // imm8 = 104
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -125.85), SIMDE_FLOAT32_C(  -884.02), SIMDE_FLOAT32_C(  -884.02), SIMDE_FLOAT32_C(  -211.36)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -126.12), SIMDE_FLOAT32_C(   654.39), SIMDE_FLOAT32_C(   987.87), SIMDE_FLOAT32_C(   213.63)),
      // imm8 = 15
      simde_mm_set_ps(SIMDE_FLOAT32_C(   213.63), SIMDE_FLOAT32_C(   213.63), SIMDE_FLOAT32_C(  -126.12), SIMDE_FLOAT32_C(  -126.12)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   545.41), SIMDE_FLOAT32_C(   -55.61), SIMDE_FLOAT32_C(   390.65), SIMDE_FLOAT32_C(  -546.65)),
      // imm8 = 25
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -546.65), SIMDE_FLOAT32_C(   390.65), SIMDE_FLOAT32_C(   -55.61), SIMDE_FLOAT32_C(   390.65)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -570.93), SIMDE_FLOAT32_C(   337.51), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(  -941.32)),
      // imm8 = 21
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -941.32), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(    48.49), SIMDE_FLOAT32_C(    48.49)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    35.91), SIMDE_FLOAT32_C(  -937.58), SIMDE_FLOAT32_C(   867.97), SIMDE_FLOAT32_C(   -64.33)),
      // imm8 = 105
      simde_mm_set_ps(SIMDE_FLOAT32_C(   867.97), SIMDE_FLOAT32_C(  -937.58), SIMDE_FLOAT32_C(  -937.58), SIMDE_FLOAT32_C(   867.97)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   592.52), SIMDE_FLOAT32_C(   823.80), SIMDE_FLOAT32_C(   377.28), SIMDE_FLOAT32_C(   174.06)),
      // imm8 = 246
      simde_mm_set_ps(SIMDE_FLOAT32_C(   592.52), SIMDE_FLOAT32_C(   592.52), SIMDE_FLOAT32_C(   377.28), SIMDE_FLOAT32_C(   823.80)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -853.11), SIMDE_FLOAT32_C(   886.60), SIMDE_FLOAT32_C(  -771.84), SIMDE_FLOAT32_C(  -900.32)),
      // imm8 = 183
      simde_mm_set_ps(SIMDE_FLOAT32_C(   886.60), SIMDE_FLOAT32_C(  -853.11), SIMDE_FLOAT32_C(  -771.84), SIMDE_FLOAT32_C(  -853.11)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(    59.21), SIMDE_FLOAT32_C(  -625.11), SIMDE_FLOAT32_C(  -350.66), SIMDE_FLOAT32_C(   873.23)),
      // imm8 = 169
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -625.11), SIMDE_FLOAT32_C(  -625.11), SIMDE_FLOAT32_C(  -625.11), SIMDE_FLOAT32_C(  -350.66)) }
  };

  simde__m128 r;

  r = simde_mm_permute_ps(test_vec[0].a, 104);
  simde_assert_m128_equal(r, test_vec[0].r);

  r = simde_mm_permute_ps(test_vec[1].a, 15);
  simde_assert_m128_equal(r, test_vec[1].r);

  r = simde_mm_permute_ps(test_vec[2].a, 25);
  simde_assert_m128_equal(r, test_vec[2].r);

  r = simde_mm_permute_ps(test_vec[3].a, 21);
  simde_assert_m128_equal(r, test_vec[3].r);

  r = simde_mm_permute_ps(test_vec[4].a, 105);
  simde_assert_m128_equal(r, test_vec[4].r);

  r = simde_mm_permute_ps(test_vec[5].a, 246);
  simde_assert_m128_equal(r, test_vec[5].r);

  r = simde_mm_permute_ps(test_vec[6].a, 183);
  simde_assert_m128_equal(r, test_vec[6].r);

  r = simde_mm_permute_ps(test_vec[7].a, 169);
  simde_assert_m128_equal(r, test_vec[7].r);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a[4];
    simde__m256d r[4];
  } test_vec[8] = {
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -307.33), SIMDE_FLOAT64_C( -277.83),
                           SIMDE_FLOAT64_C( -811.26), SIMDE_FLOAT64_C( -340.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  520.01), SIMDE_FLOAT64_C(   20.96),
                           SIMDE_FLOAT64_C( -217.27), SIMDE_FLOAT64_C(  475.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -236.99), SIMDE_FLOAT64_C( -515.97),
                           SIMDE_FLOAT64_C( -252.10), SIMDE_FLOAT64_C( -367.50)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -740.61), SIMDE_FLOAT64_C(  459.66),
                           SIMDE_FLOAT64_C(  780.67), SIMDE_FLOAT64_C( -928.66)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -277.83), SIMDE_FLOAT64_C( -277.83),
                           SIMDE_FLOAT64_C( -340.98), SIMDE_FLOAT64_C( -340.98)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.96), SIMDE_FLOAT64_C(   20.96),
                           SIMDE_FLOAT64_C(  475.98), SIMDE_FLOAT64_C( -217.27)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -515.97), SIMDE_FLOAT64_C( -515.97),
                           SIMDE_FLOAT64_C( -252.10), SIMDE_FLOAT64_C( -367.50)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  459.66), SIMDE_FLOAT64_C(  459.66),
                           SIMDE_FLOAT64_C(  780.67), SIMDE_FLOAT64_C(  780.67)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  718.00), SIMDE_FLOAT64_C( -514.42),
                           SIMDE_FLOAT64_C( -222.91), SIMDE_FLOAT64_C( -665.22)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  431.31), SIMDE_FLOAT64_C( -787.13),
                           SIMDE_FLOAT64_C( -902.93), SIMDE_FLOAT64_C( -601.27)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -645.66), SIMDE_FLOAT64_C(  168.66),
                           SIMDE_FLOAT64_C(  823.10), SIMDE_FLOAT64_C(  348.53)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -855.11), SIMDE_FLOAT64_C(  343.83),
                           SIMDE_FLOAT64_C(  888.93), SIMDE_FLOAT64_C(   81.36)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -514.42), SIMDE_FLOAT64_C( -514.42),
                           SIMDE_FLOAT64_C( -665.22), SIMDE_FLOAT64_C( -665.22)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -787.13), SIMDE_FLOAT64_C( -787.13),
                           SIMDE_FLOAT64_C( -601.27), SIMDE_FLOAT64_C( -902.93)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  168.66), SIMDE_FLOAT64_C(  168.66),
                           SIMDE_FLOAT64_C(  823.10), SIMDE_FLOAT64_C(  348.53)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  343.83), SIMDE_FLOAT64_C(  343.83),
                           SIMDE_FLOAT64_C(  888.93), SIMDE_FLOAT64_C(  888.93)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  482.80), SIMDE_FLOAT64_C(  651.20),
                           SIMDE_FLOAT64_C( -299.11), SIMDE_FLOAT64_C(  660.92)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  562.16), SIMDE_FLOAT64_C( -407.46),
                           SIMDE_FLOAT64_C(  470.74), SIMDE_FLOAT64_C(  663.86)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -609.81), SIMDE_FLOAT64_C(  224.41),
                           SIMDE_FLOAT64_C(  638.76), SIMDE_FLOAT64_C(  609.66)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  950.61), SIMDE_FLOAT64_C( -221.62),
                           SIMDE_FLOAT64_C(  198.64), SIMDE_FLOAT64_C(  472.05)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.20), SIMDE_FLOAT64_C(  651.20),
                           SIMDE_FLOAT64_C(  660.92), SIMDE_FLOAT64_C(  660.92)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -407.46), SIMDE_FLOAT64_C( -407.46),
                           SIMDE_FLOAT64_C(  663.86), SIMDE_FLOAT64_C(  470.74)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  224.41), SIMDE_FLOAT64_C(  224.41),
                           SIMDE_FLOAT64_C(  638.76), SIMDE_FLOAT64_C(  609.66)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -221.62), SIMDE_FLOAT64_C( -221.62),
                           SIMDE_FLOAT64_C(  198.64), SIMDE_FLOAT64_C(  198.64)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -304.11), SIMDE_FLOAT64_C(  887.38),
                           SIMDE_FLOAT64_C(  -49.50), SIMDE_FLOAT64_C( -449.56)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -667.31), SIMDE_FLOAT64_C(  293.87),
                           SIMDE_FLOAT64_C( -667.79), SIMDE_FLOAT64_C(  371.99)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  895.41), SIMDE_FLOAT64_C(  116.14),
                           SIMDE_FLOAT64_C(   65.95), SIMDE_FLOAT64_C( -990.78)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -751.37), SIMDE_FLOAT64_C( -570.35),
                           SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C(  337.40)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(  887.38), SIMDE_FLOAT64_C(  887.38),
                           SIMDE_FLOAT64_C( -449.56), SIMDE_FLOAT64_C( -449.56)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  293.87), SIMDE_FLOAT64_C(  293.87),
                           SIMDE_FLOAT64_C(  371.99), SIMDE_FLOAT64_C( -667.79)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  116.14), SIMDE_FLOAT64_C(  116.14),
                           SIMDE_FLOAT64_C(   65.95), SIMDE_FLOAT64_C( -990.78)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.35), SIMDE_FLOAT64_C( -570.35),
                           SIMDE_FLOAT64_C(  -32.79), SIMDE_FLOAT64_C(  -32.79)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -78.53), SIMDE_FLOAT64_C( -723.45),
                           SIMDE_FLOAT64_C( -594.84), SIMDE_FLOAT64_C( -504.83)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  599.38), SIMDE_FLOAT64_C( -102.58),
                           SIMDE_FLOAT64_C(  369.99), SIMDE_FLOAT64_C(  -58.86)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -705.85), SIMDE_FLOAT64_C( -561.88),
                           SIMDE_FLOAT64_C( -855.33), SIMDE_FLOAT64_C( -876.41)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  200.30), SIMDE_FLOAT64_C( -816.59),
                           SIMDE_FLOAT64_C(  495.88), SIMDE_FLOAT64_C(  -20.39)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -723.45), SIMDE_FLOAT64_C( -723.45),
                           SIMDE_FLOAT64_C( -504.83), SIMDE_FLOAT64_C( -504.83)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -102.58), SIMDE_FLOAT64_C( -102.58),
                           SIMDE_FLOAT64_C(  -58.86), SIMDE_FLOAT64_C(  369.99)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -561.88), SIMDE_FLOAT64_C( -561.88),
                           SIMDE_FLOAT64_C( -855.33), SIMDE_FLOAT64_C( -876.41)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -816.59), SIMDE_FLOAT64_C( -816.59),
                           SIMDE_FLOAT64_C(  495.88), SIMDE_FLOAT64_C(  495.88)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -459.43), SIMDE_FLOAT64_C(   35.05),
                           SIMDE_FLOAT64_C( -647.26), SIMDE_FLOAT64_C( -116.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  861.84), SIMDE_FLOAT64_C(   79.42),
                           SIMDE_FLOAT64_C(  -61.14), SIMDE_FLOAT64_C( -959.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -190.88), SIMDE_FLOAT64_C(   91.78),
                           SIMDE_FLOAT64_C(  624.59), SIMDE_FLOAT64_C( -875.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -757.98), SIMDE_FLOAT64_C( -777.95),
                           SIMDE_FLOAT64_C( -309.55), SIMDE_FLOAT64_C(  387.53)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C(   35.05), SIMDE_FLOAT64_C(   35.05),
                           SIMDE_FLOAT64_C( -116.28), SIMDE_FLOAT64_C( -116.28)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   79.42), SIMDE_FLOAT64_C(   79.42),
                           SIMDE_FLOAT64_C( -959.28), SIMDE_FLOAT64_C(  -61.14)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(   91.78), SIMDE_FLOAT64_C(   91.78),
                           SIMDE_FLOAT64_C(  624.59), SIMDE_FLOAT64_C( -875.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -777.95), SIMDE_FLOAT64_C( -777.95),
                           SIMDE_FLOAT64_C( -309.55), SIMDE_FLOAT64_C( -309.55)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -297.45), SIMDE_FLOAT64_C( -420.28),
                           SIMDE_FLOAT64_C( -324.78), SIMDE_FLOAT64_C( -643.43)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  271.76), SIMDE_FLOAT64_C( -727.19),
                           SIMDE_FLOAT64_C(  659.23), SIMDE_FLOAT64_C(   91.29)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  751.73), SIMDE_FLOAT64_C(  366.97),
                           SIMDE_FLOAT64_C(  178.00), SIMDE_FLOAT64_C( -562.69)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  355.89), SIMDE_FLOAT64_C(  861.10),
                           SIMDE_FLOAT64_C(  814.16), SIMDE_FLOAT64_C(  218.35)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -420.28), SIMDE_FLOAT64_C( -420.28),
                           SIMDE_FLOAT64_C( -643.43), SIMDE_FLOAT64_C( -643.43)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -727.19), SIMDE_FLOAT64_C( -727.19),
                           SIMDE_FLOAT64_C(   91.29), SIMDE_FLOAT64_C(  659.23)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  366.97), SIMDE_FLOAT64_C(  366.97),
                           SIMDE_FLOAT64_C(  178.00), SIMDE_FLOAT64_C( -562.69)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  861.10), SIMDE_FLOAT64_C(  861.10),
                           SIMDE_FLOAT64_C(  814.16), SIMDE_FLOAT64_C(  814.16)) } },
    { { simde_mm256_set_pd(SIMDE_FLOAT64_C( -344.58), SIMDE_FLOAT64_C( -961.29),
                           SIMDE_FLOAT64_C(  602.43), SIMDE_FLOAT64_C(  -99.06)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  915.17), SIMDE_FLOAT64_C(  886.67),
                           SIMDE_FLOAT64_C(  631.07), SIMDE_FLOAT64_C( -393.04)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  815.36), SIMDE_FLOAT64_C( -920.33),
                           SIMDE_FLOAT64_C( -701.98), SIMDE_FLOAT64_C(  230.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  408.01), SIMDE_FLOAT64_C( -369.61),
                           SIMDE_FLOAT64_C( -195.80), SIMDE_FLOAT64_C( -161.14)) },
      { simde_mm256_set_pd(SIMDE_FLOAT64_C( -961.29), SIMDE_FLOAT64_C( -961.29),
                           SIMDE_FLOAT64_C(  -99.06), SIMDE_FLOAT64_C(  -99.06)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C(  886.67), SIMDE_FLOAT64_C(  886.67),
                           SIMDE_FLOAT64_C( -393.04), SIMDE_FLOAT64_C(  631.07)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -920.33), SIMDE_FLOAT64_C( -920.33),
                           SIMDE_FLOAT64_C( -701.98), SIMDE_FLOAT64_C(  230.05)),
        simde_mm256_set_pd(SIMDE_FLOAT64_C( -369.61), SIMDE_FLOAT64_C( -369.61),
                           SIMDE_FLOAT64_C( -195.80), SIMDE_FLOAT64_C( -195.80)) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;

    r = simde_mm256_permute_pd(test_vec[i].a[0], 0);
    simde_assert_m256d_close(r, test_vec[i].r[0], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[1], 1);
    simde_assert_m256d_close(r, test_vec[i].r[1], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[2], 2);
    simde_assert_m256d_close(r, test_vec[i].r[2], 1);

    r = simde_mm256_permute_pd(test_vec[i].a[3], 3);
    simde_assert_m256d_close(r, test_vec[i].r[3], 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permutevar_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128i b;
    simde__m128 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -220.03), SIMDE_FLOAT32_C( -102.32), SIMDE_FLOAT32_C( -878.65), SIMDE_FLOAT32_C(  736.04)),
      simde_mm_set_epi32(INT32_C( 1978615509), INT32_C( -298382064), INT32_C(  844888802), INT32_C(-1984258319)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -878.65), SIMDE_FLOAT32_C(  736.04), SIMDE_FLOAT32_C( -102.32), SIMDE_FLOAT32_C( -878.65)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -74.21), SIMDE_FLOAT32_C(   20.33), SIMDE_FLOAT32_C(  -47.37), SIMDE_FLOAT32_C( -145.03)),
      simde_mm_set_epi32(INT32_C(-1739872531), INT32_C( 1398798289), INT32_C(  139283762), INT32_C( -468646578)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -47.37), SIMDE_FLOAT32_C(  -47.37), SIMDE_FLOAT32_C(   20.33), SIMDE_FLOAT32_C(   20.33)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  388.02), SIMDE_FLOAT32_C(  910.17), SIMDE_FLOAT32_C( -160.23), SIMDE_FLOAT32_C( -802.99)),
      simde_mm_set_epi32(INT32_C(  836573493), INT32_C(-1468644888), INT32_C( -506758879), INT32_C( -861763047)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -160.23), SIMDE_FLOAT32_C( -802.99), SIMDE_FLOAT32_C( -160.23), SIMDE_FLOAT32_C( -160.23)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  909.90), SIMDE_FLOAT32_C(  126.61), SIMDE_FLOAT32_C(  817.61), SIMDE_FLOAT32_C(  504.25)),
      simde_mm_set_epi32(INT32_C(  584238895), INT32_C(  928311120), INT32_C( -480157729), INT32_C(  870102815)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  909.90), SIMDE_FLOAT32_C(  504.25), SIMDE_FLOAT32_C(  909.90), SIMDE_FLOAT32_C(  909.90)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -446.77), SIMDE_FLOAT32_C(  -55.86), SIMDE_FLOAT32_C(  873.78), SIMDE_FLOAT32_C( -757.74)),
      simde_mm_set_epi32(INT32_C(-1116848756), INT32_C(   67501238), INT32_C( 1151634701), INT32_C(-1833672337)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -757.74), SIMDE_FLOAT32_C(  -55.86), SIMDE_FLOAT32_C(  873.78), SIMDE_FLOAT32_C( -446.77)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   17.75), SIMDE_FLOAT32_C(  909.79), SIMDE_FLOAT32_C( -854.76), SIMDE_FLOAT32_C(  845.21)),
      simde_mm_set_epi32(INT32_C( -650701315), INT32_C( -514022340), INT32_C( -456325153), INT32_C(  575846112)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -854.76), SIMDE_FLOAT32_C(  845.21), SIMDE_FLOAT32_C(   17.75), SIMDE_FLOAT32_C(  845.21)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -703.39), SIMDE_FLOAT32_C(  212.03), SIMDE_FLOAT32_C(  766.48), SIMDE_FLOAT32_C(   58.02)),
      simde_mm_set_epi32(INT32_C(  751532596), INT32_C( 2017282760), INT32_C( 1270374455), INT32_C( -795583425)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   58.02), SIMDE_FLOAT32_C(   58.02), SIMDE_FLOAT32_C( -703.39), SIMDE_FLOAT32_C( -703.39)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  101.14), SIMDE_FLOAT32_C(  114.68), SIMDE_FLOAT32_C(  986.99), SIMDE_FLOAT32_C( -651.72)),
      simde_mm_set_epi32(INT32_C( 1630473427), INT32_C( 1562779502), INT32_C( 1531074799), INT32_C(-1809767434)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  101.14), SIMDE_FLOAT32_C(  114.68), SIMDE_FLOAT32_C(  101.14), SIMDE_FLOAT32_C(  114.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128 r = simde_mm_permutevar_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m128_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_permutevar_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128i b;
    simde__m128d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -190.00), SIMDE_FLOAT64_C( -363.64)),
      simde_mm_set_epi64x(INT64_C(-3679719263685326635), INT64_C(-5014117432834044471)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -363.64), SIMDE_FLOAT64_C( -363.64)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  107.93), SIMDE_FLOAT64_C(  497.72)),
      simde_mm_set_epi64x(INT64_C(1238725724228652833), INT64_C(2295575207610739945)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  497.72), SIMDE_FLOAT64_C(  497.72)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -71.89), SIMDE_FLOAT64_C( -692.84)),
      simde_mm_set_epi64x(INT64_C(3235819707285929243), INT64_C(-60491261046190647)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  -71.89), SIMDE_FLOAT64_C( -692.84)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -729.73), SIMDE_FLOAT64_C(  585.33)),
      simde_mm_set_epi64x(INT64_C(2481877852619205882), INT64_C(3545311239979806958)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -729.73), SIMDE_FLOAT64_C( -729.73)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -735.74), SIMDE_FLOAT64_C(  646.64)),
      simde_mm_set_epi64x(INT64_C(-8424077459294111103), INT64_C(-6727548776374001581)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  646.64), SIMDE_FLOAT64_C( -735.74)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  403.13), SIMDE_FLOAT64_C( -882.62)),
      simde_mm_set_epi64x(INT64_C(-731202554371506341), INT64_C(7811413526677278696)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  403.13), SIMDE_FLOAT64_C( -882.62)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  910.78), SIMDE_FLOAT64_C(  162.04)),
      simde_mm_set_epi64x(INT64_C(-7914651116933831795), INT64_C(-7291667702753737699)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  162.04), SIMDE_FLOAT64_C(  162.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -194.64), SIMDE_FLOAT64_C(   21.61)),
      simde_mm_set_epi64x(INT64_C(-8162260555449998511), INT64_C(-7079262047989370805)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   21.61), SIMDE_FLOAT64_C( -194.64)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128d r = simde_mm_permutevar_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m128d_equal(r, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permutevar_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256i b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -581.11), SIMDE_FLOAT32_C(  662.67),
                         SIMDE_FLOAT32_C(  749.10), SIMDE_FLOAT32_C(  794.46),
                         SIMDE_FLOAT32_C(  351.98), SIMDE_FLOAT32_C(   95.47),
                         SIMDE_FLOAT32_C( -323.47), SIMDE_FLOAT32_C(  766.08)),
      simde_mm256_set_epi32(INT32_C(-1995089848), INT32_C(-1205354020), INT32_C(  942463332), INT32_C( 2042714882),
                            INT32_C(   -3085894), INT32_C( 1293825925), INT32_C( 1293195492), INT32_C( -942672880)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  794.46), SIMDE_FLOAT32_C(  794.46),
                         SIMDE_FLOAT32_C(  794.46), SIMDE_FLOAT32_C(  662.67),
                         SIMDE_FLOAT32_C(   95.47), SIMDE_FLOAT32_C( -323.47),
                         SIMDE_FLOAT32_C(  766.08), SIMDE_FLOAT32_C(  766.08)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  553.57), SIMDE_FLOAT32_C( -638.78),
                         SIMDE_FLOAT32_C( -812.35), SIMDE_FLOAT32_C( -453.08),
                         SIMDE_FLOAT32_C(  690.64), SIMDE_FLOAT32_C( -358.14),
                         SIMDE_FLOAT32_C(  491.09), SIMDE_FLOAT32_C(  642.81)),
      simde_mm256_set_epi32(INT32_C(   74819979), INT32_C(-1724654262), INT32_C( 1654056695), INT32_C(  767929859),
                            INT32_C(-1773750147), INT32_C( 1504941571), INT32_C(-1277766239), INT32_C( -474163433)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  553.57), SIMDE_FLOAT32_C( -638.78),
                         SIMDE_FLOAT32_C(  553.57), SIMDE_FLOAT32_C(  553.57),
                         SIMDE_FLOAT32_C(  491.09), SIMDE_FLOAT32_C(  690.64),
                         SIMDE_FLOAT32_C(  491.09), SIMDE_FLOAT32_C(  690.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -359.39), SIMDE_FLOAT32_C(  -64.37),
                         SIMDE_FLOAT32_C( -720.24), SIMDE_FLOAT32_C( -724.37),
                         SIMDE_FLOAT32_C( -455.62), SIMDE_FLOAT32_C(  674.74),
                         SIMDE_FLOAT32_C( -589.17), SIMDE_FLOAT32_C( -867.21)),
      simde_mm256_set_epi32(INT32_C(-1090291188), INT32_C(-2009955584), INT32_C(-1244380880), INT32_C( 2087210230),
                            INT32_C( 1556610240), INT32_C(  347022662), INT32_C( -341820489), INT32_C(  209748637)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -724.37), SIMDE_FLOAT32_C( -724.37),
                         SIMDE_FLOAT32_C( -724.37), SIMDE_FLOAT32_C(  -64.37),
                         SIMDE_FLOAT32_C( -867.21), SIMDE_FLOAT32_C(  674.74),
                         SIMDE_FLOAT32_C( -455.62), SIMDE_FLOAT32_C( -589.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -688.17), SIMDE_FLOAT32_C(  265.16),
                         SIMDE_FLOAT32_C(  223.77), SIMDE_FLOAT32_C(  457.91),
                         SIMDE_FLOAT32_C( -449.18), SIMDE_FLOAT32_C(  418.80),
                         SIMDE_FLOAT32_C( -219.32), SIMDE_FLOAT32_C( -798.45)),
      simde_mm256_set_epi32(INT32_C(-2022840556), INT32_C(  147366607), INT32_C( 1340044144), INT32_C(-1339633728),
                            INT32_C(-2141656242), INT32_C(  179357343), INT32_C( -169847688), INT32_C(  944580448)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  457.91), SIMDE_FLOAT32_C( -688.17),
                         SIMDE_FLOAT32_C(  457.91), SIMDE_FLOAT32_C(  457.91),
                         SIMDE_FLOAT32_C(  418.80), SIMDE_FLOAT32_C( -449.18),
                         SIMDE_FLOAT32_C( -798.45), SIMDE_FLOAT32_C( -798.45)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -894.16), SIMDE_FLOAT32_C( -261.98),
                         SIMDE_FLOAT32_C( -668.79), SIMDE_FLOAT32_C( -535.27),
                         SIMDE_FLOAT32_C(  295.60), SIMDE_FLOAT32_C( -624.10),
                         SIMDE_FLOAT32_C( -218.41), SIMDE_FLOAT32_C( -239.98)),
      simde_mm256_set_epi32(INT32_C(-1987732124), INT32_C(-1043251572), INT32_C(-1915492365), INT32_C( 1239473734),
                            INT32_C( 1924578330), INT32_C(  667857703), INT32_C( 1334096582), INT32_C(-1561092382)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -535.27), SIMDE_FLOAT32_C( -535.27),
                         SIMDE_FLOAT32_C( -894.16), SIMDE_FLOAT32_C( -261.98),
                         SIMDE_FLOAT32_C( -624.10), SIMDE_FLOAT32_C(  295.60),
                         SIMDE_FLOAT32_C( -624.10), SIMDE_FLOAT32_C( -624.10)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  282.55), SIMDE_FLOAT32_C(  313.26),
                         SIMDE_FLOAT32_C( -349.67), SIMDE_FLOAT32_C( -128.29),
                         SIMDE_FLOAT32_C(  298.40), SIMDE_FLOAT32_C( -200.08),
                         SIMDE_FLOAT32_C( -322.88), SIMDE_FLOAT32_C(  643.97)),
      simde_mm256_set_epi32(INT32_C(-1231918378), INT32_C(-1967971864), INT32_C( 1721865701), INT32_C( -553468547),
                            INT32_C( -723509981), INT32_C( 1588622188), INT32_C( 1625856378), INT32_C(-1426622327)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  313.26), SIMDE_FLOAT32_C( -128.29),
                         SIMDE_FLOAT32_C( -349.67), SIMDE_FLOAT32_C( -349.67),
                         SIMDE_FLOAT32_C(  298.40), SIMDE_FLOAT32_C(  643.97),
                         SIMDE_FLOAT32_C( -200.08), SIMDE_FLOAT32_C( -322.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -773.19), SIMDE_FLOAT32_C(  149.49),
                         SIMDE_FLOAT32_C( -417.32), SIMDE_FLOAT32_C( -747.01),
                         SIMDE_FLOAT32_C(  553.89), SIMDE_FLOAT32_C( -499.06),
                         SIMDE_FLOAT32_C( -480.71), SIMDE_FLOAT32_C( -871.55)),
      simde_mm256_set_epi32(INT32_C(-1619504079), INT32_C(  234838625), INT32_C( 1611169016), INT32_C(  708864983),
                            INT32_C(  595455017), INT32_C( -338961641), INT32_C( 1283075935), INT32_C(  -90174648)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -417.32), SIMDE_FLOAT32_C( -417.32),
                         SIMDE_FLOAT32_C( -747.01), SIMDE_FLOAT32_C( -773.19),
                         SIMDE_FLOAT32_C( -480.71), SIMDE_FLOAT32_C(  553.89),
                         SIMDE_FLOAT32_C(  553.89), SIMDE_FLOAT32_C( -871.55)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  770.41), SIMDE_FLOAT32_C( -575.75),
                         SIMDE_FLOAT32_C( -694.46), SIMDE_FLOAT32_C(  878.16),
                         SIMDE_FLOAT32_C(  230.89), SIMDE_FLOAT32_C( -700.74),
                         SIMDE_FLOAT32_C( -243.26), SIMDE_FLOAT32_C(  192.97)),
      simde_mm256_set_epi32(INT32_C(-1612783450), INT32_C( 2104159364), INT32_C( -271090577), INT32_C(  962282198),
                            INT32_C(-1614359330), INT32_C( -824400343), INT32_C( -259439032), INT32_C( -336808887)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -575.75), SIMDE_FLOAT32_C(  878.16),
                         SIMDE_FLOAT32_C(  770.41), SIMDE_FLOAT32_C( -575.75),
                         SIMDE_FLOAT32_C( -700.74), SIMDE_FLOAT32_C( -243.26),
                         SIMDE_FLOAT32_C(  192.97), SIMDE_FLOAT32_C( -243.26)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_permutevar_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permutevar_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256i b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  191.45), SIMDE_FLOAT64_C(  955.97),
                         SIMDE_FLOAT64_C( -381.93), SIMDE_FLOAT64_C( -276.35)),
      simde_mm256_set_epi64x(INT64_C( 7847047898918917938), INT64_C(-2237739371695600451),
                             INT64_C(-5921100696665465273), INT64_C(-3629132568613815239)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  191.45), SIMDE_FLOAT64_C(  955.97),
                         SIMDE_FLOAT64_C( -381.93), SIMDE_FLOAT64_C( -276.35)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -864.55), SIMDE_FLOAT64_C(  105.60),
                         SIMDE_FLOAT64_C(  308.22), SIMDE_FLOAT64_C( -262.99)),
      simde_mm256_set_epi64x(INT64_C( 1954446392539316319), INT64_C(-5867362525432575314),
                             INT64_C(-5609592881024898283), INT64_C(-2732169121859970729)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -864.55), SIMDE_FLOAT64_C( -864.55),
                         SIMDE_FLOAT64_C( -262.99), SIMDE_FLOAT64_C(  308.22)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C(  408.71),
                         SIMDE_FLOAT64_C(  -24.71), SIMDE_FLOAT64_C(  850.59)),
      simde_mm256_set_epi64x(INT64_C( 8155867202589355926), INT64_C(-4551757813155184517),
                             INT64_C( 4070473136336150836), INT64_C( 8294293362513343506)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -415.61), SIMDE_FLOAT64_C( -415.61),
                         SIMDE_FLOAT64_C(  850.59), SIMDE_FLOAT64_C(  -24.71)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -858.92), SIMDE_FLOAT64_C( -409.27),
                         SIMDE_FLOAT64_C(  940.24), SIMDE_FLOAT64_C(  118.21)),
      simde_mm256_set_epi64x(INT64_C(-6819188498234901479), INT64_C( 2067633441850695354),
                             INT64_C(  371129412881073798), INT64_C(-4745838610152722297)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -409.27), SIMDE_FLOAT64_C( -858.92),
                         SIMDE_FLOAT64_C(  940.24), SIMDE_FLOAT64_C(  940.24)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -35.59), SIMDE_FLOAT64_C(  620.23),
                         SIMDE_FLOAT64_C(  173.49), SIMDE_FLOAT64_C( -242.33)),
      simde_mm256_set_epi64x(INT64_C( 6267827345436252242), INT64_C( 7757337633506703794),
                             INT64_C( 8397042844771135785), INT64_C( 4768191744605903319)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -35.59), SIMDE_FLOAT64_C(  -35.59),
                         SIMDE_FLOAT64_C( -242.33), SIMDE_FLOAT64_C(  173.49)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -615.22), SIMDE_FLOAT64_C( -205.25),
                         SIMDE_FLOAT64_C(  427.82), SIMDE_FLOAT64_C( -695.42)),
      simde_mm256_set_epi64x(INT64_C(-4627283775150795805), INT64_C( 5796432689531982886),
                             INT64_C(-5333403376253040789), INT64_C(-1223877538147285054)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -615.22), SIMDE_FLOAT64_C( -615.22),
                         SIMDE_FLOAT64_C(  427.82), SIMDE_FLOAT64_C(  427.82)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.58), SIMDE_FLOAT64_C( -322.38),
                         SIMDE_FLOAT64_C( -747.07), SIMDE_FLOAT64_C( -350.25)),
      simde_mm256_set_epi64x(INT64_C(-4907910955860203917), INT64_C(-1172835446387939434),
                             INT64_C( 6316430026104479052), INT64_C( 8850000004913574542)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  461.58), SIMDE_FLOAT64_C(  461.58),
                         SIMDE_FLOAT64_C( -350.25), SIMDE_FLOAT64_C( -747.07)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  705.05), SIMDE_FLOAT64_C(   49.33),
                         SIMDE_FLOAT64_C(  -85.30), SIMDE_FLOAT64_C(  936.63)),
      simde_mm256_set_epi64x(INT64_C( 8506270823776015936), INT64_C(-7945266156798964263),
                             INT64_C( 7749717350625346930), INT64_C( -406852585870799824)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   49.33), SIMDE_FLOAT64_C(   49.33),
                         SIMDE_FLOAT64_C(  -85.30), SIMDE_FLOAT64_C(  936.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_permutevar_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_permute2f128_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -376.93), SIMDE_FLOAT32_C( -598.80),
                         SIMDE_FLOAT32_C(  335.44), SIMDE_FLOAT32_C( -614.52),
                         SIMDE_FLOAT32_C(  219.29), SIMDE_FLOAT32_C( -425.58),
                         SIMDE_FLOAT32_C(  790.46), SIMDE_FLOAT32_C(  701.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -146.60), SIMDE_FLOAT32_C(  813.49),
                         SIMDE_FLOAT32_C( -148.37), SIMDE_FLOAT32_C( -614.66),
                         SIMDE_FLOAT32_C(  951.32), SIMDE_FLOAT32_C(  -49.79),
                         SIMDE_FLOAT32_C(  618.54), SIMDE_FLOAT32_C(  -94.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  219.29), SIMDE_FLOAT32_C( -425.58),
                         SIMDE_FLOAT32_C(  790.46), SIMDE_FLOAT32_C(  701.47),
                         SIMDE_FLOAT32_C(  219.29), SIMDE_FLOAT32_C( -425.58),
                         SIMDE_FLOAT32_C(  790.46), SIMDE_FLOAT32_C(  701.47)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.90), SIMDE_FLOAT32_C(  -24.42),
                         SIMDE_FLOAT32_C(   78.54), SIMDE_FLOAT32_C(  -19.08),
                         SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  204.91), SIMDE_FLOAT32_C(  161.00),
                         SIMDE_FLOAT32_C(  230.93), SIMDE_FLOAT32_C(  108.17),
                         SIMDE_FLOAT32_C(  327.81), SIMDE_FLOAT32_C( -178.38),
                         SIMDE_FLOAT32_C( -611.38), SIMDE_FLOAT32_C( -189.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  935.39), SIMDE_FLOAT32_C(  982.16),
                         SIMDE_FLOAT32_C(  380.38), SIMDE_FLOAT32_C( -917.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00)) }
  };

  simde__m256 r;

  r = simde_mm256_permute2f128_ps(test_vec[0x0].a, test_vec[0x0].b, 0x0);
  simde_assert_m256_close(r, test_vec[0x0].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x1].a, test_vec[0x1].b, 0x1);
  simde_assert_m256_close(r, test_vec[0x1].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x2].a, test_vec[0x2].b, 0x2);
  simde_assert_m256_close(r, test_vec[0x2].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x3].a, test_vec[0x3].b, 0x3);
  simde_assert_m256_close(r, test_vec[0x3].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x4].a, test_vec[0x4].b, 0x4);
  simde_assert_m256_close(r, test_vec[0x4].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x5].a, test_vec[0x5].b, 0x5);
  simde_assert_m256_close(r, test_vec[0x5].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x6].a, test_vec[0x6].b, 0x6);
  simde_assert_m256_close(r, test_vec[0x6].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x7].a, test_vec[0x7].b, 0x7);
  simde_assert_m256_close(r, test_vec[0x7].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x8].a, test_vec[0x8].b, 0x8);
  simde_assert_m256_close(r, test_vec[0x8].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0x9].a, test_vec[0x9].b, 0x9);
  simde_assert_m256_close(r, test_vec[0x9].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xa].a, test_vec[0xa].b, 0xa);
  simde_assert_m256_close(r, test_vec[0xa].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xb].a, test_vec[0xb].b, 0xb);
  simde_assert_m256_close(r, test_vec[0xb].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xc].a, test_vec[0xc].b, 0xc);
  simde_assert_m256_close(r, test_vec[0xc].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xd].a, test_vec[0xd].b, 0xd);
  simde_assert_m256_close(r, test_vec[0xd].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xe].a, test_vec[0xe].b, 0xe);
  simde_assert_m256_close(r, test_vec[0xe].r, 1);

  r = simde_mm256_permute2f128_ps(test_vec[0xf].a, test_vec[0xf].b, 0xf);
  simde_assert_m256_close(r, test_vec[0xf].r, 1);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rcp_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -908.92), SIMDE_FLOAT32_C( -201.59),
                         SIMDE_FLOAT32_C(    3.47), SIMDE_FLOAT32_C(  829.08),
                         SIMDE_FLOAT32_C(  -86.36), SIMDE_FLOAT32_C(  780.02),
                         SIMDE_FLOAT32_C(   13.29), SIMDE_FLOAT32_C(  492.53)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.29), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.01), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  745.72), SIMDE_FLOAT32_C( -860.90),
                         SIMDE_FLOAT32_C(  647.35), SIMDE_FLOAT32_C( -932.06),
                         SIMDE_FLOAT32_C(  782.22), SIMDE_FLOAT32_C(  232.69),
                         SIMDE_FLOAT32_C(   88.27), SIMDE_FLOAT32_C( -882.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.01), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  750.74), SIMDE_FLOAT32_C(  -90.83),
                         SIMDE_FLOAT32_C(  949.51), SIMDE_FLOAT32_C(  177.31),
                         SIMDE_FLOAT32_C( -204.98), SIMDE_FLOAT32_C(  340.91),
                         SIMDE_FLOAT32_C(  -39.69), SIMDE_FLOAT32_C( -715.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.01),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.01),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.03), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -147.11), SIMDE_FLOAT32_C(  588.21),
                         SIMDE_FLOAT32_C(  521.36), SIMDE_FLOAT32_C( -659.55),
                         SIMDE_FLOAT32_C(  932.00), SIMDE_FLOAT32_C(  548.33),
                         SIMDE_FLOAT32_C(  639.13), SIMDE_FLOAT32_C( -316.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.01), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -794.81), SIMDE_FLOAT32_C(   88.08),
                         SIMDE_FLOAT32_C( -540.52), SIMDE_FLOAT32_C(   32.82),
                         SIMDE_FLOAT32_C( -921.78), SIMDE_FLOAT32_C( -970.13),
                         SIMDE_FLOAT32_C(  659.29), SIMDE_FLOAT32_C( -464.98)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.01),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -853.91), SIMDE_FLOAT32_C(  837.38),
                         SIMDE_FLOAT32_C( -478.03), SIMDE_FLOAT32_C(  330.06),
                         SIMDE_FLOAT32_C(  627.16), SIMDE_FLOAT32_C(  535.10),
                         SIMDE_FLOAT32_C( -787.00), SIMDE_FLOAT32_C(  376.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -244.65), SIMDE_FLOAT32_C(  415.43),
                         SIMDE_FLOAT32_C(  415.27), SIMDE_FLOAT32_C(  243.86),
                         SIMDE_FLOAT32_C(  475.16), SIMDE_FLOAT32_C(    0.53),
                         SIMDE_FLOAT32_C( -509.99), SIMDE_FLOAT32_C( -861.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    1.89),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -819.61), SIMDE_FLOAT32_C( -441.38),
                         SIMDE_FLOAT32_C( -736.01), SIMDE_FLOAT32_C(  681.16),
                         SIMDE_FLOAT32_C( -798.05), SIMDE_FLOAT32_C(  561.39),
                         SIMDE_FLOAT32_C(  116.98), SIMDE_FLOAT32_C( -372.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(   -0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(   -0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.01), SIMDE_FLOAT32_C(   -0.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_rcp_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_round_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 nearest;
    simde__m256 neg_inf;
    simde__m256 pos_inf;
    simde__m256 truncate;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.99), SIMDE_FLOAT32_C(  332.86),
                         SIMDE_FLOAT32_C(  531.55), SIMDE_FLOAT32_C(  188.24),
                         SIMDE_FLOAT32_C(  135.31), SIMDE_FLOAT32_C( -341.69),
                         SIMDE_FLOAT32_C( -995.08), SIMDE_FLOAT32_C(  -84.86)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  532.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -342.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -85.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.00), SIMDE_FLOAT32_C(  332.00),
                         SIMDE_FLOAT32_C(  531.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -342.00),
                         SIMDE_FLOAT32_C( -996.00), SIMDE_FLOAT32_C(  -85.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.00), SIMDE_FLOAT32_C(  333.00),
                         SIMDE_FLOAT32_C(  532.00), SIMDE_FLOAT32_C(  189.00),
                         SIMDE_FLOAT32_C(  136.00), SIMDE_FLOAT32_C( -341.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -84.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -437.00), SIMDE_FLOAT32_C(  332.00),
                         SIMDE_FLOAT32_C(  531.00), SIMDE_FLOAT32_C(  188.00),
                         SIMDE_FLOAT32_C(  135.00), SIMDE_FLOAT32_C( -341.00),
                         SIMDE_FLOAT32_C( -995.00), SIMDE_FLOAT32_C(  -84.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.77), SIMDE_FLOAT32_C( -902.26),
                         SIMDE_FLOAT32_C(  960.96), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.99), SIMDE_FLOAT32_C(  273.55),
                         SIMDE_FLOAT32_C( -508.74), SIMDE_FLOAT32_C(  304.51)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  961.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  185.00), SIMDE_FLOAT32_C(  274.00),
                         SIMDE_FLOAT32_C( -509.00), SIMDE_FLOAT32_C(  305.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -272.00), SIMDE_FLOAT32_C( -903.00),
                         SIMDE_FLOAT32_C(  960.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.00), SIMDE_FLOAT32_C(  273.00),
                         SIMDE_FLOAT32_C( -509.00), SIMDE_FLOAT32_C(  304.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  961.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  185.00), SIMDE_FLOAT32_C(  274.00),
                         SIMDE_FLOAT32_C( -508.00), SIMDE_FLOAT32_C(  305.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -271.00), SIMDE_FLOAT32_C( -902.00),
                         SIMDE_FLOAT32_C(  960.00), SIMDE_FLOAT32_C(  885.00),
                         SIMDE_FLOAT32_C(  184.00), SIMDE_FLOAT32_C(  273.00),
                         SIMDE_FLOAT32_C( -508.00), SIMDE_FLOAT32_C(  304.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.76), SIMDE_FLOAT32_C( -833.91),
                         SIMDE_FLOAT32_C( -187.58), SIMDE_FLOAT32_C(   27.59),
                         SIMDE_FLOAT32_C(  181.38), SIMDE_FLOAT32_C( -399.46),
                         SIMDE_FLOAT32_C( -127.86), SIMDE_FLOAT32_C( -393.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.00), SIMDE_FLOAT32_C( -834.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C(   28.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -128.00), SIMDE_FLOAT32_C( -393.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.00), SIMDE_FLOAT32_C( -834.00),
                         SIMDE_FLOAT32_C( -188.00), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -400.00),
                         SIMDE_FLOAT32_C( -128.00), SIMDE_FLOAT32_C( -394.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  971.00), SIMDE_FLOAT32_C( -833.00),
                         SIMDE_FLOAT32_C( -187.00), SIMDE_FLOAT32_C(   28.00),
                         SIMDE_FLOAT32_C(  182.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -127.00), SIMDE_FLOAT32_C( -393.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  970.00), SIMDE_FLOAT32_C( -833.00),
                         SIMDE_FLOAT32_C( -187.00), SIMDE_FLOAT32_C(   27.00),
                         SIMDE_FLOAT32_C(  181.00), SIMDE_FLOAT32_C( -399.00),
                         SIMDE_FLOAT32_C( -127.00), SIMDE_FLOAT32_C( -393.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.90), SIMDE_FLOAT32_C( -282.33),
                         SIMDE_FLOAT32_C(  766.19), SIMDE_FLOAT32_C(  948.74),
                         SIMDE_FLOAT32_C( -533.05), SIMDE_FLOAT32_C(  397.75),
                         SIMDE_FLOAT32_C(  998.83), SIMDE_FLOAT32_C( -841.13)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  260.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  949.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  398.00),
                         SIMDE_FLOAT32_C(  999.00), SIMDE_FLOAT32_C( -841.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.00), SIMDE_FLOAT32_C( -283.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  948.00),
                         SIMDE_FLOAT32_C( -534.00), SIMDE_FLOAT32_C(  397.00),
                         SIMDE_FLOAT32_C(  998.00), SIMDE_FLOAT32_C( -842.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  260.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  767.00), SIMDE_FLOAT32_C(  949.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  398.00),
                         SIMDE_FLOAT32_C(  999.00), SIMDE_FLOAT32_C( -841.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  259.00), SIMDE_FLOAT32_C( -282.00),
                         SIMDE_FLOAT32_C(  766.00), SIMDE_FLOAT32_C(  948.00),
                         SIMDE_FLOAT32_C( -533.00), SIMDE_FLOAT32_C(  397.00),
                         SIMDE_FLOAT32_C(  998.00), SIMDE_FLOAT32_C( -841.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.69), SIMDE_FLOAT32_C(  880.71),
                         SIMDE_FLOAT32_C( -928.72), SIMDE_FLOAT32_C( -201.24),
                         SIMDE_FLOAT32_C(  -99.45), SIMDE_FLOAT32_C(  785.84),
                         SIMDE_FLOAT32_C(  542.02), SIMDE_FLOAT32_C(  -81.93)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -179.00), SIMDE_FLOAT32_C(  881.00),
                         SIMDE_FLOAT32_C( -929.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  786.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -82.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -179.00), SIMDE_FLOAT32_C(  880.00),
                         SIMDE_FLOAT32_C( -929.00), SIMDE_FLOAT32_C( -202.00),
                         SIMDE_FLOAT32_C( -100.00), SIMDE_FLOAT32_C(  785.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -82.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.00), SIMDE_FLOAT32_C(  881.00),
                         SIMDE_FLOAT32_C( -928.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  786.00),
                         SIMDE_FLOAT32_C(  543.00), SIMDE_FLOAT32_C(  -81.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -178.00), SIMDE_FLOAT32_C(  880.00),
                         SIMDE_FLOAT32_C( -928.00), SIMDE_FLOAT32_C( -201.00),
                         SIMDE_FLOAT32_C(  -99.00), SIMDE_FLOAT32_C(  785.00),
                         SIMDE_FLOAT32_C(  542.00), SIMDE_FLOAT32_C(  -81.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.16), SIMDE_FLOAT32_C(  854.52),
                         SIMDE_FLOAT32_C(  980.48), SIMDE_FLOAT32_C(  -86.24),
                         SIMDE_FLOAT32_C(  473.38), SIMDE_FLOAT32_C(  104.75),
                         SIMDE_FLOAT32_C(   14.33), SIMDE_FLOAT32_C(   91.35)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  855.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  105.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -938.00), SIMDE_FLOAT32_C(  854.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -87.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  104.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  855.00),
                         SIMDE_FLOAT32_C(  981.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  474.00), SIMDE_FLOAT32_C(  105.00),
                         SIMDE_FLOAT32_C(   15.00), SIMDE_FLOAT32_C(   92.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -937.00), SIMDE_FLOAT32_C(  854.00),
                         SIMDE_FLOAT32_C(  980.00), SIMDE_FLOAT32_C(  -86.00),
                         SIMDE_FLOAT32_C(  473.00), SIMDE_FLOAT32_C(  104.00),
                         SIMDE_FLOAT32_C(   14.00), SIMDE_FLOAT32_C(   91.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.30), SIMDE_FLOAT32_C(  148.64),
                         SIMDE_FLOAT32_C(  820.35), SIMDE_FLOAT32_C(  265.99),
                         SIMDE_FLOAT32_C(  701.82), SIMDE_FLOAT32_C(  479.73),
                         SIMDE_FLOAT32_C(  432.96), SIMDE_FLOAT32_C(  276.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  149.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  266.00),
                         SIMDE_FLOAT32_C(  702.00), SIMDE_FLOAT32_C(  480.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C(  276.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  148.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  265.00),
                         SIMDE_FLOAT32_C(  701.00), SIMDE_FLOAT32_C(  479.00),
                         SIMDE_FLOAT32_C(  432.00), SIMDE_FLOAT32_C(  276.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  530.00), SIMDE_FLOAT32_C(  149.00),
                         SIMDE_FLOAT32_C(  821.00), SIMDE_FLOAT32_C(  266.00),
                         SIMDE_FLOAT32_C(  702.00), SIMDE_FLOAT32_C(  480.00),
                         SIMDE_FLOAT32_C(  433.00), SIMDE_FLOAT32_C(  277.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  529.00), SIMDE_FLOAT32_C(  148.00),
                         SIMDE_FLOAT32_C(  820.00), SIMDE_FLOAT32_C(  265.00),
                         SIMDE_FLOAT32_C(  701.00), SIMDE_FLOAT32_C(  479.00),
                         SIMDE_FLOAT32_C(  432.00), SIMDE_FLOAT32_C(  276.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.90), SIMDE_FLOAT32_C( -334.90),
                         SIMDE_FLOAT32_C( -399.58), SIMDE_FLOAT32_C(  824.28),
                         SIMDE_FLOAT32_C(  442.40), SIMDE_FLOAT32_C(  699.22),
                         SIMDE_FLOAT32_C( -143.02), SIMDE_FLOAT32_C( -465.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.00), SIMDE_FLOAT32_C( -335.00),
                         SIMDE_FLOAT32_C( -400.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -466.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -34.00), SIMDE_FLOAT32_C( -335.00),
                         SIMDE_FLOAT32_C( -400.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -144.00), SIMDE_FLOAT32_C( -466.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C( -334.00),
                         SIMDE_FLOAT32_C( -399.00), SIMDE_FLOAT32_C(  825.00),
                         SIMDE_FLOAT32_C(  443.00), SIMDE_FLOAT32_C(  700.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -465.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -33.00), SIMDE_FLOAT32_C( -334.00),
                         SIMDE_FLOAT32_C( -399.00), SIMDE_FLOAT32_C(  824.00),
                         SIMDE_FLOAT32_C(  442.00), SIMDE_FLOAT32_C(  699.00),
                         SIMDE_FLOAT32_C( -143.00), SIMDE_FLOAT32_C( -465.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m256_close(r, test_vec[i].nearest, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m256_close(r, test_vec[i].neg_inf, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m256_close(r, test_vec[i].pos_inf, 1);

    r = simde_mm256_round_ps(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m256_close(r, test_vec[i].truncate, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_round_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d nearest;
    simde__m256d neg_inf;
    simde__m256d pos_inf;
    simde__m256d truncate;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.12), SIMDE_FLOAT64_C(  818.22),
                         SIMDE_FLOAT64_C(   62.47), SIMDE_FLOAT64_C(  918.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  313.00), SIMDE_FLOAT64_C(  819.00),
                         SIMDE_FLOAT64_C(   63.00), SIMDE_FLOAT64_C(  919.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  312.00), SIMDE_FLOAT64_C(  818.00),
                         SIMDE_FLOAT64_C(   62.00), SIMDE_FLOAT64_C(  918.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.78), SIMDE_FLOAT64_C( -771.04),
                         SIMDE_FLOAT64_C(  544.48), SIMDE_FLOAT64_C(  333.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  652.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.00), SIMDE_FLOAT64_C( -772.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  652.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  545.00), SIMDE_FLOAT64_C(  334.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  651.00), SIMDE_FLOAT64_C( -771.00),
                         SIMDE_FLOAT64_C(  544.00), SIMDE_FLOAT64_C(  333.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.62), SIMDE_FLOAT64_C(  921.42),
                         SIMDE_FLOAT64_C(   23.03), SIMDE_FLOAT64_C(  143.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.00), SIMDE_FLOAT64_C(  922.00),
                         SIMDE_FLOAT64_C(   24.00), SIMDE_FLOAT64_C(  144.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -661.00), SIMDE_FLOAT64_C(  921.00),
                         SIMDE_FLOAT64_C(   23.00), SIMDE_FLOAT64_C(  143.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.29),
                         SIMDE_FLOAT64_C( -644.20), SIMDE_FLOAT64_C( -788.03)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -190.00),
                         SIMDE_FLOAT64_C( -645.00), SIMDE_FLOAT64_C( -789.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -70.00), SIMDE_FLOAT64_C( -189.00),
                         SIMDE_FLOAT64_C( -644.00), SIMDE_FLOAT64_C( -788.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.31), SIMDE_FLOAT64_C(  917.83),
                         SIMDE_FLOAT64_C( -173.85), SIMDE_FLOAT64_C( -622.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  918.00),
                         SIMDE_FLOAT64_C( -174.00), SIMDE_FLOAT64_C( -622.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1000.00), SIMDE_FLOAT64_C(  917.00),
                         SIMDE_FLOAT64_C( -174.00), SIMDE_FLOAT64_C( -623.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  918.00),
                         SIMDE_FLOAT64_C( -173.00), SIMDE_FLOAT64_C( -622.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -999.00), SIMDE_FLOAT64_C(  917.00),
                         SIMDE_FLOAT64_C( -173.00), SIMDE_FLOAT64_C( -622.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.08), SIMDE_FLOAT64_C(   96.40),
                         SIMDE_FLOAT64_C(  481.12), SIMDE_FLOAT64_C(  989.53)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  990.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -906.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  989.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   97.00),
                         SIMDE_FLOAT64_C(  482.00), SIMDE_FLOAT64_C(  990.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -905.00), SIMDE_FLOAT64_C(   96.00),
                         SIMDE_FLOAT64_C(  481.00), SIMDE_FLOAT64_C(  989.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.53), SIMDE_FLOAT64_C(  251.75),
                         SIMDE_FLOAT64_C( -843.75), SIMDE_FLOAT64_C( -890.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  381.00), SIMDE_FLOAT64_C(  252.00),
                         SIMDE_FLOAT64_C( -844.00), SIMDE_FLOAT64_C( -891.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.00), SIMDE_FLOAT64_C(  251.00),
                         SIMDE_FLOAT64_C( -844.00), SIMDE_FLOAT64_C( -891.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  381.00), SIMDE_FLOAT64_C(  252.00),
                         SIMDE_FLOAT64_C( -843.00), SIMDE_FLOAT64_C( -890.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  380.00), SIMDE_FLOAT64_C(  251.00),
                         SIMDE_FLOAT64_C( -843.00), SIMDE_FLOAT64_C( -890.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.52), SIMDE_FLOAT64_C( -590.14),
                         SIMDE_FLOAT64_C(    3.25), SIMDE_FLOAT64_C(  599.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -383.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -383.00), SIMDE_FLOAT64_C( -591.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    4.00), SIMDE_FLOAT64_C(  600.00)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -382.00), SIMDE_FLOAT64_C( -590.00),
                         SIMDE_FLOAT64_C(    3.00), SIMDE_FLOAT64_C(  599.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEAREST_INT);
    simde_assert_m256d_close(r, test_vec[i].nearest, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_NEG_INF);
    simde_assert_m256d_close(r, test_vec[i].neg_inf, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_POS_INF);
    simde_assert_m256d_close(r, test_vec[i].pos_inf, 1);

    r = simde_mm256_round_pd(test_vec[i].a, SIMDE_MM_FROUND_TO_ZERO);
    simde_assert_m256d_close(r, test_vec[i].truncate, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_rsqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  376.34), SIMDE_FLOAT32_C(  781.09),
                         SIMDE_FLOAT32_C(  426.92), SIMDE_FLOAT32_C(  127.71),
                         SIMDE_FLOAT32_C(  308.06), SIMDE_FLOAT32_C(  169.26),
                         SIMDE_FLOAT32_C(  264.24), SIMDE_FLOAT32_C(   87.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.09),
                         SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.08),
                         SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.11)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  840.99), SIMDE_FLOAT32_C(  641.73),
                         SIMDE_FLOAT32_C(  425.88), SIMDE_FLOAT32_C(  794.85),
                         SIMDE_FLOAT32_C(  374.41), SIMDE_FLOAT32_C(  576.54),
                         SIMDE_FLOAT32_C(  840.83), SIMDE_FLOAT32_C(  886.63)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.05), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  314.85), SIMDE_FLOAT32_C(  671.43),
                         SIMDE_FLOAT32_C(  540.12), SIMDE_FLOAT32_C(  529.67),
                         SIMDE_FLOAT32_C(  498.35), SIMDE_FLOAT32_C(  224.61),
                         SIMDE_FLOAT32_C(  518.07), SIMDE_FLOAT32_C(  759.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.07),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  990.90), SIMDE_FLOAT32_C(  800.35),
                         SIMDE_FLOAT32_C(   95.53), SIMDE_FLOAT32_C(  852.74),
                         SIMDE_FLOAT32_C(  140.49), SIMDE_FLOAT32_C(  379.21),
                         SIMDE_FLOAT32_C(  930.80), SIMDE_FLOAT32_C(   70.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.10), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.12)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  251.14), SIMDE_FLOAT32_C(  612.05),
                         SIMDE_FLOAT32_C(   55.90), SIMDE_FLOAT32_C(  550.93),
                         SIMDE_FLOAT32_C(   71.18), SIMDE_FLOAT32_C(  968.41),
                         SIMDE_FLOAT32_C(   36.22), SIMDE_FLOAT32_C(  986.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.06), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.13), SIMDE_FLOAT32_C(    0.04),
                         SIMDE_FLOAT32_C(    0.12), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.17), SIMDE_FLOAT32_C(    0.03)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  657.13), SIMDE_FLOAT32_C(  431.08),
                         SIMDE_FLOAT32_C(  717.98), SIMDE_FLOAT32_C(   27.05),
                         SIMDE_FLOAT32_C(  195.42), SIMDE_FLOAT32_C(  859.20),
                         SIMDE_FLOAT32_C(  157.91), SIMDE_FLOAT32_C(  578.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.19),
                         SIMDE_FLOAT32_C(    0.07), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.08), SIMDE_FLOAT32_C(    0.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  738.73), SIMDE_FLOAT32_C(  198.62),
                         SIMDE_FLOAT32_C(  544.16), SIMDE_FLOAT32_C(  379.62),
                         SIMDE_FLOAT32_C(  782.12), SIMDE_FLOAT32_C(   91.05),
                         SIMDE_FLOAT32_C(  650.65), SIMDE_FLOAT32_C(  315.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.07),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.05),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.10),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.06)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  788.79), SIMDE_FLOAT32_C(  929.94),
                         SIMDE_FLOAT32_C(   55.55), SIMDE_FLOAT32_C(  137.30),
                         SIMDE_FLOAT32_C(  612.48), SIMDE_FLOAT32_C(    6.47),
                         SIMDE_FLOAT32_C(  828.22), SIMDE_FLOAT32_C(  971.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.03),
                         SIMDE_FLOAT32_C(    0.13), SIMDE_FLOAT32_C(    0.09),
                         SIMDE_FLOAT32_C(    0.04), SIMDE_FLOAT32_C(    0.39),
                         SIMDE_FLOAT32_C(    0.03), SIMDE_FLOAT32_C(    0.03)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_rsqrt_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a[32];
    simde__m256i r;
  } test_vec[8] = {
    { { INT8_C(  -4), INT8_C(  97), INT8_C( -85), INT8_C( -82),
        INT8_C(  42), INT8_C(  35), INT8_C(  11), INT8_C(  62),
        INT8_C( -47), INT8_C(  10), INT8_C(-127), INT8_C(  56),
        INT8_C(  44), INT8_C(  59), INT8_C( -13), INT8_C(  22),
        INT8_C( -14), INT8_C(  77), INT8_C( -49), INT8_C( -46),
        INT8_C(  53), INT8_C(-109), INT8_C(  30), INT8_C(  70),
        INT8_C(-110), INT8_C(  70), INT8_C(  95), INT8_C( -22),
        INT8_C(  89), INT8_C( -50), INT8_C( -28), INT8_C(-122) },
      simde_mm256_set_epi8(INT8_C(-122), INT8_C( -28), INT8_C( -50), INT8_C(  89),
                           INT8_C( -22), INT8_C(  95), INT8_C(  70), INT8_C(-110),
                           INT8_C(  70), INT8_C(  30), INT8_C(-109), INT8_C(  53),
                           INT8_C( -46), INT8_C( -49), INT8_C(  77), INT8_C( -14),
                           INT8_C(  22), INT8_C( -13), INT8_C(  59), INT8_C(  44),
                           INT8_C(  56), INT8_C(-127), INT8_C(  10), INT8_C( -47),
                           INT8_C(  62), INT8_C(  11), INT8_C(  35), INT8_C(  42),
                           INT8_C( -82), INT8_C( -85), INT8_C(  97), INT8_C(  -4)) },
    { { INT8_C( 127), INT8_C(  42), INT8_C( -70), INT8_C( -73),
        INT8_C( -56), INT8_C(-116), INT8_C( -43), INT8_C(  20),
        INT8_C(  -7), INT8_C(-120), INT8_C( -33), INT8_C(   3),
        INT8_C(  87), INT8_C(  58), INT8_C(  61), INT8_C( -32),
        INT8_C(  37), INT8_C(-114), INT8_C(  14), INT8_C(  80),
        INT8_C( -87), INT8_C(  43), INT8_C( -56), INT8_C(  51),
        INT8_C(  64), INT8_C(-107), INT8_C(  80), INT8_C(  59),
        INT8_C( -99), INT8_C( -49), INT8_C(  22), INT8_C( 109) },
      simde_mm256_set_epi8(INT8_C( 109), INT8_C(  22), INT8_C( -49), INT8_C( -99),
                           INT8_C(  59), INT8_C(  80), INT8_C(-107), INT8_C(  64),
                           INT8_C(  51), INT8_C( -56), INT8_C(  43), INT8_C( -87),
                           INT8_C(  80), INT8_C(  14), INT8_C(-114), INT8_C(  37),
                           INT8_C( -32), INT8_C(  61), INT8_C(  58), INT8_C(  87),
                           INT8_C(   3), INT8_C( -33), INT8_C(-120), INT8_C(  -7),
                           INT8_C(  20), INT8_C( -43), INT8_C(-116), INT8_C( -56),
                           INT8_C( -73), INT8_C( -70), INT8_C(  42), INT8_C( 127)) },
    { { INT8_C(  18), INT8_C( 106), INT8_C( -14), INT8_C( -63),
        INT8_C(  49), INT8_C(  26), INT8_C( 111), INT8_C( 121),
        INT8_C(-109), INT8_C(  19), INT8_C(  59), INT8_C( -42),
        INT8_C( -61), INT8_C(  44), INT8_C(  95), INT8_C(   0),
        INT8_C(  14), INT8_C(  62), INT8_C(  88), INT8_C(  98),
        INT8_C(  26), INT8_C(  58), INT8_C(  76), INT8_C( -18),
        INT8_C(-104), INT8_C(  -9), INT8_C( -67), INT8_C(  20),
        INT8_C( -43), INT8_C( -63), INT8_C(  30), INT8_C( 123) },
      simde_mm256_set_epi8(INT8_C( 123), INT8_C(  30), INT8_C( -63), INT8_C( -43),
                           INT8_C(  20), INT8_C( -67), INT8_C(  -9), INT8_C(-104),
                           INT8_C( -18), INT8_C(  76), INT8_C(  58), INT8_C(  26),
                           INT8_C(  98), INT8_C(  88), INT8_C(  62), INT8_C(  14),
                           INT8_C(   0), INT8_C(  95), INT8_C(  44), INT8_C( -61),
                           INT8_C( -42), INT8_C(  59), INT8_C(  19), INT8_C(-109),
                           INT8_C( 121), INT8_C( 111), INT8_C(  26), INT8_C(  49),
                           INT8_C( -63), INT8_C( -14), INT8_C( 106), INT8_C(  18)) },
    { { INT8_C(-122), INT8_C( 106), INT8_C( -25), INT8_C(  57),
        INT8_C(-110), INT8_C(  80), INT8_C(  35), INT8_C( -81),
        INT8_C(-111), INT8_C(   7), INT8_C(  90), INT8_C( -14),
        INT8_C(  64), INT8_C(  90), INT8_C( -51), INT8_C(  87),
        INT8_C(  49), INT8_C(  77), INT8_C( 127), INT8_C( -93),
        INT8_C( -57), INT8_C( 112), INT8_C( -74), INT8_C(  26),
        INT8_C(-113), INT8_C( -77), INT8_C( -29), INT8_C( -29),
        INT8_C( 117), INT8_C(  31), INT8_C(-100), INT8_C( -86) },
      simde_mm256_set_epi8(INT8_C( -86), INT8_C(-100), INT8_C(  31), INT8_C( 117),
                           INT8_C( -29), INT8_C( -29), INT8_C( -77), INT8_C(-113),
                           INT8_C(  26), INT8_C( -74), INT8_C( 112), INT8_C( -57),
                           INT8_C( -93), INT8_C( 127), INT8_C(  77), INT8_C(  49),
                           INT8_C(  87), INT8_C( -51), INT8_C(  90), INT8_C(  64),
                           INT8_C( -14), INT8_C(  90), INT8_C(   7), INT8_C(-111),
                           INT8_C( -81), INT8_C(  35), INT8_C(  80), INT8_C(-110),
                           INT8_C(  57), INT8_C( -25), INT8_C( 106), INT8_C(-122)) },
    { { INT8_C(  58), INT8_C(   6), INT8_C( 118), INT8_C(  36),
        INT8_C( 115), INT8_C( -15), INT8_C(  37), INT8_C( 119),
        INT8_C( -89), INT8_C( -10), INT8_C( -50), INT8_C(-119),
        INT8_C(   6), INT8_C( -77), INT8_C(  70), INT8_C( 117),
        INT8_C( -12), INT8_C( -22), INT8_C( 114), INT8_C( -39),
        INT8_C( 100), INT8_C( 122), INT8_C(-102), INT8_C( -55),
        INT8_C( 116), INT8_C( -23), INT8_C( -29), INT8_C( -57),
        INT8_C( -40), INT8_C(  41), INT8_C( 119), INT8_C( 121) },
      simde_mm256_set_epi8(INT8_C( 121), INT8_C( 119), INT8_C(  41), INT8_C( -40),
                           INT8_C( -57), INT8_C( -29), INT8_C( -23), INT8_C( 116),
                           INT8_C( -55), INT8_C(-102), INT8_C( 122), INT8_C( 100),
                           INT8_C( -39), INT8_C( 114), INT8_C( -22), INT8_C( -12),
                           INT8_C( 117), INT8_C(  70), INT8_C( -77), INT8_C(   6),
                           INT8_C(-119), INT8_C( -50), INT8_C( -10), INT8_C( -89),
                           INT8_C( 119), INT8_C(  37), INT8_C( -15), INT8_C( 115),
                           INT8_C(  36), INT8_C( 118), INT8_C(   6), INT8_C(  58)) },
    { { INT8_C(  47), INT8_C(  33), INT8_C( -28), INT8_C(-105),
        INT8_C(  -6), INT8_C( -69), INT8_C( 111), INT8_C( -17),
        INT8_C(  43), INT8_C(-123), INT8_C(  56), INT8_C( 119),
        INT8_C(  18), INT8_C(  -6), INT8_C( -96), INT8_C(-126),
        INT8_C( 113), INT8_C(-107), INT8_C(  83), INT8_C(  24),
        INT8_C( -84), INT8_C(-124), INT8_C( -72), INT8_C( -86),
        INT8_C(  80), INT8_C(  33), INT8_C(  -6), INT8_C( -30),
        INT8_C(  85), INT8_C( -74), INT8_C(  58), INT8_C( -88) },
      simde_mm256_set_epi8(INT8_C( -88), INT8_C(  58), INT8_C( -74), INT8_C(  85),
                           INT8_C( -30), INT8_C(  -6), INT8_C(  33), INT8_C(  80),
                           INT8_C( -86), INT8_C( -72), INT8_C(-124), INT8_C( -84),
                           INT8_C(  24), INT8_C(  83), INT8_C(-107), INT8_C( 113),
                           INT8_C(-126), INT8_C( -96), INT8_C(  -6), INT8_C(  18),
                           INT8_C( 119), INT8_C(  56), INT8_C(-123), INT8_C(  43),
                           INT8_C( -17), INT8_C( 111), INT8_C( -69), INT8_C(  -6),
                           INT8_C(-105), INT8_C( -28), INT8_C(  33), INT8_C(  47)) },
    { { INT8_C(  12), INT8_C(  93), INT8_C( -74), INT8_C( 117),
        INT8_C( -55), INT8_C( -56), INT8_C(   9), INT8_C( -48),
        INT8_C( 100), INT8_C(  -4), INT8_C( 101), INT8_C(  -1),
        INT8_C( -41), INT8_C( -98), INT8_C(-128), INT8_C( -73),
        INT8_C( -47), INT8_C(  35), INT8_C( -89), INT8_C( -36),
        INT8_C(-117), INT8_C( -95), INT8_C( -70), INT8_C( -94),
        INT8_C( -61), INT8_C( -88), INT8_C( -41), INT8_C( -56),
        INT8_C(  -5), INT8_C( -90), INT8_C( -61), INT8_C(  58) },
      simde_mm256_set_epi8(INT8_C(  58), INT8_C( -61), INT8_C( -90), INT8_C(  -5),
                           INT8_C( -56), INT8_C( -41), INT8_C( -88), INT8_C( -61),
                           INT8_C( -94), INT8_C( -70), INT8_C( -95), INT8_C(-117),
                           INT8_C( -36), INT8_C( -89), INT8_C(  35), INT8_C( -47),
                           INT8_C( -73), INT8_C(-128), INT8_C( -98), INT8_C( -41),
                           INT8_C(  -1), INT8_C( 101), INT8_C(  -4), INT8_C( 100),
                           INT8_C( -48), INT8_C(   9), INT8_C( -56), INT8_C( -55),
                           INT8_C( 117), INT8_C( -74), INT8_C(  93), INT8_C(  12)) },
    { { INT8_C( -62), INT8_C( 106), INT8_C(  33), INT8_C( -86),
        INT8_C(  50), INT8_C(  51), INT8_C(   1), INT8_C(  83),
        INT8_C( -24), INT8_C(  24), INT8_C( 119), INT8_C( -35),
        INT8_C(  55), INT8_C( 109), INT8_C( -56), INT8_C( -46),
        INT8_C( -64), INT8_C( 124), INT8_C(  -1), INT8_C( -71),
        INT8_C(  27), INT8_C( 108), INT8_C(-113), INT8_C( -86),
        INT8_C(  94), INT8_C(  46), INT8_C( -59), INT8_C( -32),
        INT8_C( -63), INT8_C( -39), INT8_C( -52), INT8_C( 101) },
      simde_mm256_set_epi8(INT8_C( 101), INT8_C( -52), INT8_C( -39), INT8_C( -63),
                           INT8_C( -32), INT8_C( -59), INT8_C(  46), INT8_C(  94),
                           INT8_C( -86), INT8_C(-113), INT8_C( 108), INT8_C(  27),
                           INT8_C( -71), INT8_C(  -1), INT8_C( 124), INT8_C( -64),
                           INT8_C( -46), INT8_C( -56), INT8_C( 109), INT8_C(  55),
                           INT8_C( -35), INT8_C( 119), INT8_C(  24), INT8_C( -24),
                           INT8_C(  83), INT8_C(   1), INT8_C(  51), INT8_C(  50),
                           INT8_C( -86), INT8_C(  33), INT8_C( 106), INT8_C( -62)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi8(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
        test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
        test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15],
        test_vec[i].a[16], test_vec[i].a[17], test_vec[i].a[18], test_vec[i].a[19],
        test_vec[i].a[20], test_vec[i].a[21], test_vec[i].a[22], test_vec[i].a[23],
        test_vec[i].a[24], test_vec[i].a[25], test_vec[i].a[26], test_vec[i].a[27],
        test_vec[i].a[28], test_vec[i].a[29], test_vec[i].a[30], test_vec[i].a[31]);
    simde_assert_m256i_i8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a[16];
    simde__m256i r;
  } test_vec[8] = {
    { { INT16_C(-20822), INT16_C(  4719), INT16_C( 13700), INT16_C( 26280),
        INT16_C( -8393), INT16_C( 13684), INT16_C(-27950), INT16_C(-18508),
        INT16_C( 32037), INT16_C(-24299), INT16_C(-21546), INT16_C(  1669),
        INT16_C(   957), INT16_C( 10001), INT16_C(-15549), INT16_C(-30917) },
      simde_mm256_set_epi16(INT16_C(-30917), INT16_C(-15549), INT16_C( 10001), INT16_C(   957),
                            INT16_C(  1669), INT16_C(-21546), INT16_C(-24299), INT16_C( 32037),
                            INT16_C(-18508), INT16_C(-27950), INT16_C( 13684), INT16_C( -8393),
                            INT16_C( 26280), INT16_C( 13700), INT16_C(  4719), INT16_C(-20822)) },
    { { INT16_C(-21993), INT16_C(-20656), INT16_C( 29326), INT16_C( 28940),
        INT16_C(-31152), INT16_C(-19248), INT16_C(-26052), INT16_C(-19065),
        INT16_C(-11006), INT16_C( -7550), INT16_C( 14017), INT16_C( 19342),
        INT16_C(-32339), INT16_C(  3580), INT16_C( 28313), INT16_C(-13882) },
      simde_mm256_set_epi16(INT16_C(-13882), INT16_C( 28313), INT16_C(  3580), INT16_C(-32339),
                            INT16_C( 19342), INT16_C( 14017), INT16_C( -7550), INT16_C(-11006),
                            INT16_C(-19065), INT16_C(-26052), INT16_C(-19248), INT16_C(-31152),
                            INT16_C( 28940), INT16_C( 29326), INT16_C(-20656), INT16_C(-21993)) },
    { { INT16_C( 10866), INT16_C(  9786), INT16_C(  3944), INT16_C(-19272),
        INT16_C(-30670), INT16_C( 14551), INT16_C(  8410), INT16_C( -6777),
        INT16_C(-16568), INT16_C(-18107), INT16_C(-20605), INT16_C( 22309),
        INT16_C(-22975), INT16_C( 30575), INT16_C( -4285), INT16_C( 10884) },
      simde_mm256_set_epi16(INT16_C( 10884), INT16_C( -4285), INT16_C( 30575), INT16_C(-22975),
                            INT16_C( 22309), INT16_C(-20605), INT16_C(-18107), INT16_C(-16568),
                            INT16_C( -6777), INT16_C(  8410), INT16_C( 14551), INT16_C(-30670),
                            INT16_C(-19272), INT16_C(  3944), INT16_C(  9786), INT16_C( 10866)) },
    { { INT16_C(  3382), INT16_C(-18461), INT16_C( 23033), INT16_C(-12757),
        INT16_C(  -812), INT16_C( 15509), INT16_C(-23059), INT16_C(  2475),
        INT16_C(-26254), INT16_C(-14528), INT16_C(-12769), INT16_C( -6867),
        INT16_C(-17924), INT16_C( 22705), INT16_C(-26548), INT16_C(-32025) },
      simde_mm256_set_epi16(INT16_C(-32025), INT16_C(-26548), INT16_C( 22705), INT16_C(-17924),
                            INT16_C( -6867), INT16_C(-12769), INT16_C(-14528), INT16_C(-26254),
                            INT16_C(  2475), INT16_C(-23059), INT16_C( 15509), INT16_C(  -812),
                            INT16_C(-12757), INT16_C( 23033), INT16_C(-18461), INT16_C(  3382)) },
    { { INT16_C(-16227), INT16_C( 12780), INT16_C( 24958), INT16_C( 10168),
        INT16_C(-24922), INT16_C(-26733), INT16_C(  3884), INT16_C(  8130),
        INT16_C(  -363), INT16_C( -2828), INT16_C( -7524), INT16_C( 28685),
        INT16_C( -7215), INT16_C(  7765), INT16_C( 25104), INT16_C(-23004) },
      simde_mm256_set_epi16(INT16_C(-23004), INT16_C( 25104), INT16_C(  7765), INT16_C( -7215),
                            INT16_C( 28685), INT16_C( -7524), INT16_C( -2828), INT16_C(  -363),
                            INT16_C(  8130), INT16_C(  3884), INT16_C(-26733), INT16_C(-24922),
                            INT16_C( 10168), INT16_C( 24958), INT16_C( 12780), INT16_C(-16227)) },
    { { INT16_C(-23604), INT16_C(-17002), INT16_C( -3804), INT16_C(-31486),
        INT16_C(-31316), INT16_C(  8603), INT16_C( 13936), INT16_C(-30323),
        INT16_C( 17911), INT16_C(-25284), INT16_C( 11323), INT16_C( -3450),
        INT16_C( -2379), INT16_C( -4748), INT16_C( -1701), INT16_C(-14575) },
      simde_mm256_set_epi16(INT16_C(-14575), INT16_C( -1701), INT16_C( -4748), INT16_C( -2379),
                            INT16_C( -3450), INT16_C( 11323), INT16_C(-25284), INT16_C( 17911),
                            INT16_C(-30323), INT16_C( 13936), INT16_C(  8603), INT16_C(-31316),
                            INT16_C(-31486), INT16_C( -3804), INT16_C(-17002), INT16_C(-23604)) },
    { { INT16_C(  2504), INT16_C(  3886), INT16_C( -8527), INT16_C( 15137),
        INT16_C( -2956), INT16_C(  3741), INT16_C(-30624), INT16_C(-26724),
        INT16_C(  6830), INT16_C( 31838), INT16_C( 31654), INT16_C(-13744),
        INT16_C( -1202), INT16_C( 10750), INT16_C(  5862), INT16_C(-29772) },
      simde_mm256_set_epi16(INT16_C(-29772), INT16_C(  5862), INT16_C( 10750), INT16_C( -1202),
                            INT16_C(-13744), INT16_C( 31654), INT16_C( 31838), INT16_C(  6830),
                            INT16_C(-26724), INT16_C(-30624), INT16_C(  3741), INT16_C( -2956),
                            INT16_C( 15137), INT16_C( -8527), INT16_C(  3886), INT16_C(  2504)) },
    { { INT16_C(  9166), INT16_C( 24566), INT16_C(-20956), INT16_C( 25846),
        INT16_C( -9797), INT16_C(-30693), INT16_C( 17134), INT16_C(-20898),
        INT16_C(-11673), INT16_C( -1066), INT16_C( 24186), INT16_C( 15486),
        INT16_C( -6894), INT16_C( -1878), INT16_C(-19558), INT16_C( 25792) },
      simde_mm256_set_epi16(INT16_C( 25792), INT16_C(-19558), INT16_C( -1878), INT16_C( -6894),
                            INT16_C( 15486), INT16_C( 24186), INT16_C( -1066), INT16_C(-11673),
                            INT16_C(-20898), INT16_C( 17134), INT16_C(-30693), INT16_C( -9797),
                            INT16_C( 25846), INT16_C(-20956), INT16_C( 24566), INT16_C(  9166)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi16(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7],
        test_vec[i].a[ 8], test_vec[i].a[ 9], test_vec[i].a[10], test_vec[i].a[11],
        test_vec[i].a[12], test_vec[i].a[13], test_vec[i].a[14], test_vec[i].a[15]);
    simde_assert_m256i_i16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a[8];
    simde__m256i r;
  } test_vec[8] = {
    { { INT32_C(  932849909), INT32_C( -456580424), INT32_C(-1072840342), INT32_C(  187025165),
        INT32_C(  -54386372), INT32_C(-1527557226), INT32_C(  842765893), INT32_C(-1371730077) },
      simde_mm256_set_epi32(INT32_C(-1371730077), INT32_C(  842765893), INT32_C(-1527557226), INT32_C(  -54386372),
                            INT32_C(  187025165), INT32_C(-1072840342), INT32_C( -456580424), INT32_C(  932849909)) },
    { { INT32_C( 1893614455), INT32_C( 1294871072), INT32_C( 1552259151), INT32_C(  946045936),
        INT32_C(   -7047247), INT32_C(  177282155), INT32_C( -581856304), INT32_C(  673832922) },
      simde_mm256_set_epi32(INT32_C(  673832922), INT32_C( -581856304), INT32_C(  177282155), INT32_C(   -7047247),
                            INT32_C(  946045936), INT32_C( 1552259151), INT32_C( 1294871072), INT32_C( 1893614455)) },
    { { INT32_C(-1610219922), INT32_C(  -94583836), INT32_C( -424768577), INT32_C( -880788885),
        INT32_C(  602433069), INT32_C( -274391227), INT32_C( -328110003), INT32_C(  499660384) },
      simde_mm256_set_epi32(INT32_C(  499660384), INT32_C( -328110003), INT32_C( -274391227), INT32_C(  602433069),
                            INT32_C( -880788885), INT32_C( -424768577), INT32_C(  -94583836), INT32_C(-1610219922)) },
    { { INT32_C( 1302188877), INT32_C( -801832432), INT32_C( 1655080701), INT32_C(-1605614771),
        INT32_C( 1846614190), INT32_C( 1570676076), INT32_C(  -68393412), INT32_C( 1031272058) },
      simde_mm256_set_epi32(INT32_C( 1031272058), INT32_C(  -68393412), INT32_C( 1570676076), INT32_C( 1846614190),
                            INT32_C(-1605614771), INT32_C( 1655080701), INT32_C( -801832432), INT32_C( 1302188877)) },
    { { INT32_C(   25897078), INT32_C(-1241591361), INT32_C( -592602700), INT32_C( -348865550),
        INT32_C( 1694164628), INT32_C( -856795223), INT32_C( -997978026), INT32_C( 1280081679) },
      simde_mm256_set_epi32(INT32_C( 1280081679), INT32_C( -997978026), INT32_C( -856795223), INT32_C( 1694164628),
                            INT32_C( -348865550), INT32_C( -592602700), INT32_C(-1241591361), INT32_C(   25897078)) },
    { { INT32_C(  -87546396), INT32_C( 1852814507), INT32_C( -373825552), INT32_C( 1866208106),
        INT32_C(  910270627), INT32_C( 1550266609), INT32_C( 1485123950), INT32_C( -498285483) },
      simde_mm256_set_epi32(INT32_C( -498285483), INT32_C( 1485123950), INT32_C( 1550266609), INT32_C(  910270627),
                            INT32_C( 1866208106), INT32_C( -373825552), INT32_C( 1852814507), INT32_C(  -87546396)) },
    { { INT32_C( -786490570), INT32_C( -486650057), INT32_C(-1901610760), INT32_C(-1385527729),
        INT32_C( 1837621475), INT32_C(  362332872), INT32_C( 1409187239), INT32_C( -294514311) },
      simde_mm256_set_epi32(INT32_C( -294514311), INT32_C( 1409187239), INT32_C(  362332872), INT32_C( 1837621475),
                            INT32_C(-1385527729), INT32_C(-1901610760), INT32_C( -486650057), INT32_C( -786490570)) },
    { { INT32_C(-2037006285), INT32_C(-1237137601), INT32_C(-1490902854), INT32_C(-1337182966),
        INT32_C( -732587886), INT32_C(-1907285545), INT32_C(  165118547), INT32_C(-1097315632) },
      simde_mm256_set_epi32(INT32_C(-1097315632), INT32_C(  165118547), INT32_C(-1907285545), INT32_C( -732587886),
                            INT32_C(-1337182966), INT32_C(-1490902854), INT32_C(-1237137601), INT32_C(-2037006285)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi32(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_epi64x(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a[4];
    simde__m256i r;
  } test_vec[8] = {
    { { INT64_C( 3013620110861784505), INT64_C(-9156069624919168580),
        INT64_C( 1343723656449999612), INT64_C(-3830101585267880776) },
      simde_mm256_set_epi64x(INT64_C(-3830101585267880776), INT64_C( 1343723656449999612),
                             INT64_C(-9156069624919168580), INT64_C( 3013620110861784505)) },
    { { INT64_C( -470898397325052178), INT64_C(-1684256644586675245),
        INT64_C(-8451403171467723697), INT64_C( 5467852576317781229) },
      simde_mm256_set_epi64x(INT64_C( 5467852576317781229), INT64_C(-8451403171467723697),
                             INT64_C(-1684256644586675245), INT64_C( -470898397325052178)) },
    { { INT64_C(-8481091302015892038), INT64_C(-5840489628108018840),
        INT64_C( 8103807582752765524), INT64_C( 9048592296921391543) },
      simde_mm256_set_epi64x(INT64_C( 9048592296921391543), INT64_C( 8103807582752765524),
                             INT64_C(-5840489628108018840), INT64_C(-8481091302015892038)) },
    { { INT64_C( 1422449841795305675), INT64_C( 2887994309822364165),
        INT64_C( 7807032920035636816), INT64_C(-3076736950419346689) },
      simde_mm256_set_epi64x(INT64_C(-3076736950419346689), INT64_C( 7807032920035636816),
                             INT64_C( 2887994309822364165), INT64_C( 1422449841795305675)) },
    { { INT64_C( 3070310353568185156), INT64_C(-8852504885484410210),
        INT64_C( 8605078790751557478), INT64_C(-3993303917440615301) },
      simde_mm256_set_epi64x(INT64_C(-3993303917440615301), INT64_C( 8605078790751557478),
                             INT64_C(-8852504885484410210), INT64_C( 3070310353568185156)) },
    { { INT64_C( 8628903781070638905), INT64_C( 7741876512722404057),
        INT64_C(-7211506260596057593), INT64_C( 4414889885954661792) },
      simde_mm256_set_epi64x(INT64_C( 4414889885954661792), INT64_C(-7211506260596057593),
                             INT64_C( 7741876512722404057), INT64_C( 8628903781070638905)) },
    { { INT64_C( 5522184073273144975), INT64_C(-7081867462548166489),
        INT64_C( 9175542926859973104), INT64_C( 1769179143810464101) },
      simde_mm256_set_epi64x(INT64_C( 1769179143810464101), INT64_C( 9175542926859973104),
                             INT64_C(-7081867462548166489), INT64_C( 5522184073273144975)) },
    { { INT64_C(-8500631716292798858), INT64_C( 4882720816332117442),
        INT64_C(  328133580565148934), INT64_C( 3537144852497440140) },
      simde_mm256_set_epi64x(INT64_C( 3537144852497440140), INT64_C(  328133580565148934),
                             INT64_C( 4882720816332117442), INT64_C(-8500631716292798858)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_epi64x(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m256i_i64(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a[8];
    simde__m256 r;
  } test_vec[8] = {
    { { SIMDE_FLOAT32_C(  -98.84), SIMDE_FLOAT32_C(  882.16),
        SIMDE_FLOAT32_C(  306.69), SIMDE_FLOAT32_C( -539.67),
        SIMDE_FLOAT32_C( -947.14), SIMDE_FLOAT32_C( -871.17),
        SIMDE_FLOAT32_C(  -26.40), SIMDE_FLOAT32_C( -202.75) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -202.75), SIMDE_FLOAT32_C(  -26.40),
                         SIMDE_FLOAT32_C( -871.17), SIMDE_FLOAT32_C( -947.14),
                         SIMDE_FLOAT32_C( -539.67), SIMDE_FLOAT32_C(  306.69),
                         SIMDE_FLOAT32_C(  882.16), SIMDE_FLOAT32_C(  -98.84)) },
    { { SIMDE_FLOAT32_C(  499.74), SIMDE_FLOAT32_C( -810.04),
        SIMDE_FLOAT32_C(  499.26), SIMDE_FLOAT32_C( -519.32),
        SIMDE_FLOAT32_C(  852.97), SIMDE_FLOAT32_C(  119.58),
        SIMDE_FLOAT32_C(   88.58), SIMDE_FLOAT32_C(  364.48) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  364.48), SIMDE_FLOAT32_C(   88.58),
                         SIMDE_FLOAT32_C(  119.58), SIMDE_FLOAT32_C(  852.97),
                         SIMDE_FLOAT32_C( -519.32), SIMDE_FLOAT32_C(  499.26),
                         SIMDE_FLOAT32_C( -810.04), SIMDE_FLOAT32_C(  499.74)) },
    { { SIMDE_FLOAT32_C(  127.60), SIMDE_FLOAT32_C(  904.28),
        SIMDE_FLOAT32_C(  -45.75), SIMDE_FLOAT32_C( -900.72),
        SIMDE_FLOAT32_C(  277.91), SIMDE_FLOAT32_C( -221.10),
        SIMDE_FLOAT32_C(  935.26), SIMDE_FLOAT32_C( -125.20) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -125.20), SIMDE_FLOAT32_C(  935.26),
                         SIMDE_FLOAT32_C( -221.10), SIMDE_FLOAT32_C(  277.91),
                         SIMDE_FLOAT32_C( -900.72), SIMDE_FLOAT32_C(  -45.75),
                         SIMDE_FLOAT32_C(  904.28), SIMDE_FLOAT32_C(  127.60)) },
    { { SIMDE_FLOAT32_C( -252.48), SIMDE_FLOAT32_C( -889.53),
        SIMDE_FLOAT32_C(  628.46), SIMDE_FLOAT32_C(  326.01),
        SIMDE_FLOAT32_C(  211.05), SIMDE_FLOAT32_C( -703.39),
        SIMDE_FLOAT32_C( -581.63), SIMDE_FLOAT32_C( -367.12) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -367.12), SIMDE_FLOAT32_C( -581.63),
                         SIMDE_FLOAT32_C( -703.39), SIMDE_FLOAT32_C(  211.05),
                         SIMDE_FLOAT32_C(  326.01), SIMDE_FLOAT32_C(  628.46),
                         SIMDE_FLOAT32_C( -889.53), SIMDE_FLOAT32_C( -252.48)) },
    { { SIMDE_FLOAT32_C( -852.61), SIMDE_FLOAT32_C(  168.93),
        SIMDE_FLOAT32_C(  -51.67), SIMDE_FLOAT32_C( -699.78),
        SIMDE_FLOAT32_C( -215.36), SIMDE_FLOAT32_C(  505.82),
        SIMDE_FLOAT32_C(  -83.94), SIMDE_FLOAT32_C( -117.98) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -117.98), SIMDE_FLOAT32_C(  -83.94),
                         SIMDE_FLOAT32_C(  505.82), SIMDE_FLOAT32_C( -215.36),
                         SIMDE_FLOAT32_C( -699.78), SIMDE_FLOAT32_C(  -51.67),
                         SIMDE_FLOAT32_C(  168.93), SIMDE_FLOAT32_C( -852.61)) },
    { { SIMDE_FLOAT32_C(  422.80), SIMDE_FLOAT32_C(  684.40),
        SIMDE_FLOAT32_C(  497.91), SIMDE_FLOAT32_C( -511.24),
        SIMDE_FLOAT32_C(  504.14), SIMDE_FLOAT32_C(  871.91),
        SIMDE_FLOAT32_C(  175.65), SIMDE_FLOAT32_C( -754.38) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -754.38), SIMDE_FLOAT32_C(  175.65),
                         SIMDE_FLOAT32_C(  871.91), SIMDE_FLOAT32_C(  504.14),
                         SIMDE_FLOAT32_C( -511.24), SIMDE_FLOAT32_C(  497.91),
                         SIMDE_FLOAT32_C(  684.40), SIMDE_FLOAT32_C(  422.80)) },
    { { SIMDE_FLOAT32_C( -712.98), SIMDE_FLOAT32_C(   92.05),
        SIMDE_FLOAT32_C( -155.74), SIMDE_FLOAT32_C(  933.89),
        SIMDE_FLOAT32_C(  385.65), SIMDE_FLOAT32_C( -406.91),
        SIMDE_FLOAT32_C( -999.59), SIMDE_FLOAT32_C( -851.48) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -851.48), SIMDE_FLOAT32_C( -999.59),
                         SIMDE_FLOAT32_C( -406.91), SIMDE_FLOAT32_C(  385.65),
                         SIMDE_FLOAT32_C(  933.89), SIMDE_FLOAT32_C( -155.74),
                         SIMDE_FLOAT32_C(   92.05), SIMDE_FLOAT32_C( -712.98)) },
    { { SIMDE_FLOAT32_C( -182.06), SIMDE_FLOAT32_C( -447.19),
        SIMDE_FLOAT32_C( -170.21), SIMDE_FLOAT32_C( -504.91),
        SIMDE_FLOAT32_C(  448.84), SIMDE_FLOAT32_C( -232.24),
        SIMDE_FLOAT32_C( -688.18), SIMDE_FLOAT32_C( -405.72) },
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -405.72), SIMDE_FLOAT32_C( -688.18),
                         SIMDE_FLOAT32_C( -232.24), SIMDE_FLOAT32_C(  448.84),
                         SIMDE_FLOAT32_C( -504.91), SIMDE_FLOAT32_C( -170.21),
                         SIMDE_FLOAT32_C( -447.19), SIMDE_FLOAT32_C( -182.06)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_setr_ps(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3],
        test_vec[i].a[ 4], test_vec[i].a[ 5], test_vec[i].a[ 6], test_vec[i].a[ 7]);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a[4];
    simde__m256d r;
  } test_vec[8] = {
    { { SIMDE_FLOAT64_C(  648.06), SIMDE_FLOAT64_C( -427.64),
        SIMDE_FLOAT64_C(  870.51), SIMDE_FLOAT64_C( -400.08) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -400.08), SIMDE_FLOAT64_C(  870.51),
                         SIMDE_FLOAT64_C( -427.64), SIMDE_FLOAT64_C(  648.06)) },
    { { SIMDE_FLOAT64_C(  631.12), SIMDE_FLOAT64_C(  452.84),
        SIMDE_FLOAT64_C(  521.67), SIMDE_FLOAT64_C(  516.74) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  516.74), SIMDE_FLOAT64_C(  521.67),
                         SIMDE_FLOAT64_C(  452.84), SIMDE_FLOAT64_C(  631.12)) },
    { { SIMDE_FLOAT64_C( -967.92), SIMDE_FLOAT64_C(   20.70),
        SIMDE_FLOAT64_C(  301.61), SIMDE_FLOAT64_C( -721.26) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -721.26), SIMDE_FLOAT64_C(  301.61),
                         SIMDE_FLOAT64_C(   20.70), SIMDE_FLOAT64_C( -967.92)) },
    { { SIMDE_FLOAT64_C(  324.87), SIMDE_FLOAT64_C( -688.66),
        SIMDE_FLOAT64_C( -942.28), SIMDE_FLOAT64_C( -476.77) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -476.77), SIMDE_FLOAT64_C( -942.28),
                         SIMDE_FLOAT64_C( -688.66), SIMDE_FLOAT64_C(  324.87)) },
    { { SIMDE_FLOAT64_C( -951.83), SIMDE_FLOAT64_C(   77.38),
        SIMDE_FLOAT64_C(   95.18), SIMDE_FLOAT64_C( -682.02) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.02), SIMDE_FLOAT64_C(   95.18),
                         SIMDE_FLOAT64_C(   77.38), SIMDE_FLOAT64_C( -951.83)) },
    { { SIMDE_FLOAT64_C( -650.77), SIMDE_FLOAT64_C( -285.31),
        SIMDE_FLOAT64_C(  662.58), SIMDE_FLOAT64_C(  693.61) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  693.61), SIMDE_FLOAT64_C(  662.58),
                         SIMDE_FLOAT64_C( -285.31), SIMDE_FLOAT64_C( -650.77)) },
    { { SIMDE_FLOAT64_C(  209.43), SIMDE_FLOAT64_C(  188.93),
        SIMDE_FLOAT64_C( -264.78), SIMDE_FLOAT64_C(  938.62) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  938.62), SIMDE_FLOAT64_C( -264.78),
                         SIMDE_FLOAT64_C(  188.93), SIMDE_FLOAT64_C(  209.43)) },
    { { SIMDE_FLOAT64_C(  887.57), SIMDE_FLOAT64_C(  787.01),
        SIMDE_FLOAT64_C( -658.13), SIMDE_FLOAT64_C(  241.09) },
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  241.09), SIMDE_FLOAT64_C( -658.13),
                         SIMDE_FLOAT64_C(  787.01), SIMDE_FLOAT64_C(  887.57)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_setr_pd(
        test_vec[i].a[ 0], test_vec[i].a[ 1], test_vec[i].a[ 2], test_vec[i].a[ 3]);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -682.25), SIMDE_FLOAT32_C( -899.79), SIMDE_FLOAT32_C( -478.94), SIMDE_FLOAT32_C(  364.00)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -650.11), SIMDE_FLOAT32_C( -192.16), SIMDE_FLOAT32_C(  808.30), SIMDE_FLOAT32_C(  519.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -650.11), SIMDE_FLOAT32_C( -192.16),
                         SIMDE_FLOAT32_C(  808.30), SIMDE_FLOAT32_C(  519.14),
                         SIMDE_FLOAT32_C( -682.25), SIMDE_FLOAT32_C( -899.79),
                         SIMDE_FLOAT32_C( -478.94), SIMDE_FLOAT32_C(  364.00)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   16.48), SIMDE_FLOAT32_C(  517.23), SIMDE_FLOAT32_C( -546.20), SIMDE_FLOAT32_C(  -61.05)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C( -476.50), SIMDE_FLOAT32_C( -479.17), SIMDE_FLOAT32_C( -869.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  715.06), SIMDE_FLOAT32_C( -476.50),
                         SIMDE_FLOAT32_C( -479.17), SIMDE_FLOAT32_C( -869.09),
                         SIMDE_FLOAT32_C(   16.48), SIMDE_FLOAT32_C(  517.23),
                         SIMDE_FLOAT32_C( -546.20), SIMDE_FLOAT32_C(  -61.05)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -779.37), SIMDE_FLOAT32_C(   30.06), SIMDE_FLOAT32_C( -690.77), SIMDE_FLOAT32_C(  921.96)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -173.53), SIMDE_FLOAT32_C(  887.42), SIMDE_FLOAT32_C(  309.36), SIMDE_FLOAT32_C(  929.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -173.53), SIMDE_FLOAT32_C(  887.42),
                         SIMDE_FLOAT32_C(  309.36), SIMDE_FLOAT32_C(  929.48),
                         SIMDE_FLOAT32_C( -779.37), SIMDE_FLOAT32_C(   30.06),
                         SIMDE_FLOAT32_C( -690.77), SIMDE_FLOAT32_C(  921.96)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  766.53), SIMDE_FLOAT32_C( -675.92), SIMDE_FLOAT32_C( -948.96), SIMDE_FLOAT32_C(  521.94)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  725.37), SIMDE_FLOAT32_C( -802.67), SIMDE_FLOAT32_C( -800.62), SIMDE_FLOAT32_C(  419.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  725.37), SIMDE_FLOAT32_C( -802.67),
                         SIMDE_FLOAT32_C( -800.62), SIMDE_FLOAT32_C(  419.68),
                         SIMDE_FLOAT32_C(  766.53), SIMDE_FLOAT32_C( -675.92),
                         SIMDE_FLOAT32_C( -948.96), SIMDE_FLOAT32_C(  521.94)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  133.15), SIMDE_FLOAT32_C(  853.30), SIMDE_FLOAT32_C(  295.19), SIMDE_FLOAT32_C( -233.49)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  973.48), SIMDE_FLOAT32_C(  235.18), SIMDE_FLOAT32_C(  111.09), SIMDE_FLOAT32_C( -515.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  973.48), SIMDE_FLOAT32_C(  235.18),
                         SIMDE_FLOAT32_C(  111.09), SIMDE_FLOAT32_C( -515.37),
                         SIMDE_FLOAT32_C(  133.15), SIMDE_FLOAT32_C(  853.30),
                         SIMDE_FLOAT32_C(  295.19), SIMDE_FLOAT32_C( -233.49)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -131.35), SIMDE_FLOAT32_C(  737.21), SIMDE_FLOAT32_C(  816.16), SIMDE_FLOAT32_C(  442.16)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -614.82), SIMDE_FLOAT32_C( -170.44), SIMDE_FLOAT32_C(  851.94), SIMDE_FLOAT32_C(  235.41)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -614.82), SIMDE_FLOAT32_C( -170.44),
                         SIMDE_FLOAT32_C(  851.94), SIMDE_FLOAT32_C(  235.41),
                         SIMDE_FLOAT32_C( -131.35), SIMDE_FLOAT32_C(  737.21),
                         SIMDE_FLOAT32_C(  816.16), SIMDE_FLOAT32_C(  442.16)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  291.38), SIMDE_FLOAT32_C( -442.22), SIMDE_FLOAT32_C(  756.36), SIMDE_FLOAT32_C( -768.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -266.91), SIMDE_FLOAT32_C( -275.67), SIMDE_FLOAT32_C( -687.10), SIMDE_FLOAT32_C(  236.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -266.91), SIMDE_FLOAT32_C( -275.67),
                         SIMDE_FLOAT32_C( -687.10), SIMDE_FLOAT32_C(  236.32),
                         SIMDE_FLOAT32_C(  291.38), SIMDE_FLOAT32_C( -442.22),
                         SIMDE_FLOAT32_C(  756.36), SIMDE_FLOAT32_C( -768.65)) },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  561.83), SIMDE_FLOAT32_C(  979.61), SIMDE_FLOAT32_C(   43.21), SIMDE_FLOAT32_C( -386.38)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -879.64), SIMDE_FLOAT32_C( -192.97), SIMDE_FLOAT32_C( -876.27), SIMDE_FLOAT32_C(  -36.00)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -879.64), SIMDE_FLOAT32_C( -192.97),
                         SIMDE_FLOAT32_C( -876.27), SIMDE_FLOAT32_C(  -36.00),
                         SIMDE_FLOAT32_C(  561.83), SIMDE_FLOAT32_C(  979.61),
                         SIMDE_FLOAT32_C(   43.21), SIMDE_FLOAT32_C( -386.38)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_setr_m128(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -456.75), SIMDE_FLOAT64_C( -671.00)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -831.34), SIMDE_FLOAT64_C(  280.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -831.34), SIMDE_FLOAT64_C(  280.05),
                         SIMDE_FLOAT64_C( -456.75), SIMDE_FLOAT64_C( -671.00)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  937.15), SIMDE_FLOAT64_C( -608.20)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -231.75), SIMDE_FLOAT64_C( -301.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -231.75), SIMDE_FLOAT64_C( -301.21),
                         SIMDE_FLOAT64_C(  937.15), SIMDE_FLOAT64_C( -608.20)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -418.68), SIMDE_FLOAT64_C( -219.09)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -262.95), SIMDE_FLOAT64_C( -857.27)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -262.95), SIMDE_FLOAT64_C( -857.27),
                         SIMDE_FLOAT64_C( -418.68), SIMDE_FLOAT64_C( -219.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  154.88), SIMDE_FLOAT64_C(   64.12)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  231.57), SIMDE_FLOAT64_C(  996.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  231.57), SIMDE_FLOAT64_C(  996.12),
                         SIMDE_FLOAT64_C(  154.88), SIMDE_FLOAT64_C(   64.12)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -46.48), SIMDE_FLOAT64_C( -511.22)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  951.46), SIMDE_FLOAT64_C(  771.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  951.46), SIMDE_FLOAT64_C(  771.21),
                         SIMDE_FLOAT64_C(  -46.48), SIMDE_FLOAT64_C( -511.22)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -492.75), SIMDE_FLOAT64_C( -725.08)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -545.59), SIMDE_FLOAT64_C( -960.12)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -545.59), SIMDE_FLOAT64_C( -960.12),
                         SIMDE_FLOAT64_C( -492.75), SIMDE_FLOAT64_C( -725.08)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(   -9.74), SIMDE_FLOAT64_C(  -44.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  854.62), SIMDE_FLOAT64_C( -942.41)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  854.62), SIMDE_FLOAT64_C( -942.41),
                         SIMDE_FLOAT64_C(   -9.74), SIMDE_FLOAT64_C(  -44.37)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  575.33), SIMDE_FLOAT64_C( -493.55)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   73.10), SIMDE_FLOAT64_C(   90.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   73.10), SIMDE_FLOAT64_C(   90.67),
                         SIMDE_FLOAT64_C(  575.33), SIMDE_FLOAT64_C( -493.55)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_setr_m128d(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setr_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m128i b;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1742712724), INT32_C( -314784100), INT32_C(  986737210), INT32_C( 1275380805)),
      simde_mm_set_epi32(INT32_C( -652328462), INT32_C(-1178876865), INT32_C(-2116026355), INT32_C(  283851183)),
      simde_mm256_set_epi32(INT32_C( -652328462), INT32_C(-1178876865), INT32_C(-2116026355), INT32_C(  283851183),
                            INT32_C(-1742712724), INT32_C( -314784100), INT32_C(  986737210), INT32_C( 1275380805)) },
    { simde_mm_set_epi32(INT32_C( 1950785462), INT32_C(-1647057227), INT32_C( 1610379205), INT32_C( -779524107)),
      simde_mm_set_epi32(INT32_C(  463748536), INT32_C( -797772071), INT32_C( 1736524491), INT32_C( 1281308863)),
      simde_mm256_set_epi32(INT32_C(  463748536), INT32_C( -797772071), INT32_C( 1736524491), INT32_C( 1281308863),
                            INT32_C( 1950785462), INT32_C(-1647057227), INT32_C( 1610379205), INT32_C( -779524107)) },
    { simde_mm_set_epi32(INT32_C(-2008212267), INT32_C(-2138916541), INT32_C(-1006728926), INT32_C(-1435438838)),
      simde_mm_set_epi32(INT32_C( -133349630), INT32_C(-1192564707), INT32_C(-2002224298), INT32_C(  917327905)),
      simde_mm256_set_epi32(INT32_C( -133349630), INT32_C(-1192564707), INT32_C(-2002224298), INT32_C(  917327905),
                            INT32_C(-2008212267), INT32_C(-2138916541), INT32_C(-1006728926), INT32_C(-1435438838)) },
    { simde_mm_set_epi32(INT32_C( -870567789), INT32_C(-1650884654), INT32_C(  516950890), INT32_C(-1478935293)),
      simde_mm_set_epi32(INT32_C(  346251173), INT32_C(   44036763), INT32_C( -453299917), INT32_C( 1313402969)),
      simde_mm256_set_epi32(INT32_C(  346251173), INT32_C(   44036763), INT32_C( -453299917), INT32_C( 1313402969),
                            INT32_C( -870567789), INT32_C(-1650884654), INT32_C(  516950890), INT32_C(-1478935293)) },
    { simde_mm_set_epi32(INT32_C( 1685745491), INT32_C(-1092039924), INT32_C( 1442866872), INT32_C(-1523614432)),
      simde_mm_set_epi32(INT32_C(  863519834), INT32_C(  230110187), INT32_C(  812017634), INT32_C( 1688191143)),
      simde_mm256_set_epi32(INT32_C(  863519834), INT32_C(  230110187), INT32_C(  812017634), INT32_C( 1688191143),
                            INT32_C( 1685745491), INT32_C(-1092039924), INT32_C( 1442866872), INT32_C(-1523614432)) },
    { simde_mm_set_epi32(INT32_C(  245453619), INT32_C( 1778016121), INT32_C(   58675090), INT32_C( 1219256368)),
      simde_mm_set_epi32(INT32_C( 1174470085), INT32_C( -388376691), INT32_C( -990477533), INT32_C( -476034642)),
      simde_mm256_set_epi32(INT32_C( 1174470085), INT32_C( -388376691), INT32_C( -990477533), INT32_C( -476034642),
                            INT32_C(  245453619), INT32_C( 1778016121), INT32_C(   58675090), INT32_C( 1219256368)) },
    { simde_mm_set_epi32(INT32_C(    4875253), INT32_C(-1938130041), INT32_C( -829985839), INT32_C( 1737785848)),
      simde_mm_set_epi32(INT32_C(  645358488), INT32_C(   69189244), INT32_C( 1744086784), INT32_C(  473310154)),
      simde_mm256_set_epi32(INT32_C(  645358488), INT32_C(   69189244), INT32_C( 1744086784), INT32_C(  473310154),
                            INT32_C(    4875253), INT32_C(-1938130041), INT32_C( -829985839), INT32_C( 1737785848)) },
    { simde_mm_set_epi32(INT32_C(  804470839), INT32_C(-1989324616), INT32_C( 2138294939), INT32_C(  -20370473)),
      simde_mm_set_epi32(INT32_C(  587534668), INT32_C(  665646160), INT32_C(-1572975914), INT32_C( 1262599280)),
      simde_mm256_set_epi32(INT32_C(  587534668), INT32_C(  665646160), INT32_C(-1572975914), INT32_C( 1262599280),
                            INT32_C(  804470839), INT32_C(-1989324616), INT32_C( 2138294939), INT32_C(  -20370473)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_setr_m128i(test_vec[i].a, test_vec[i].b);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r1;
    simde__m256 r2;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -37.53), SIMDE_FLOAT32_C(  505.45),
                         SIMDE_FLOAT32_C( -772.05), SIMDE_FLOAT32_C( -524.38),
                         SIMDE_FLOAT32_C(   32.28), SIMDE_FLOAT32_C(  575.28),
                         SIMDE_FLOAT32_C(  459.50), SIMDE_FLOAT32_C( -869.92)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  190.31), SIMDE_FLOAT32_C( -827.59),
                         SIMDE_FLOAT32_C( -501.09), SIMDE_FLOAT32_C(  667.40),
                         SIMDE_FLOAT32_C( -205.26), SIMDE_FLOAT32_C(  908.59),
                         SIMDE_FLOAT32_C(  448.39), SIMDE_FLOAT32_C( -264.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -501.09), SIMDE_FLOAT32_C( -501.09),
                         SIMDE_FLOAT32_C( -772.05), SIMDE_FLOAT32_C( -772.05),
                         SIMDE_FLOAT32_C(  448.39), SIMDE_FLOAT32_C(  448.39),
                         SIMDE_FLOAT32_C(  459.50), SIMDE_FLOAT32_C(  459.50)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -827.59), SIMDE_FLOAT32_C( -827.59),
                         SIMDE_FLOAT32_C(  505.45), SIMDE_FLOAT32_C(  505.45),
                         SIMDE_FLOAT32_C(  908.59), SIMDE_FLOAT32_C(  908.59),
                         SIMDE_FLOAT32_C(  575.28), SIMDE_FLOAT32_C(  575.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -651.57), SIMDE_FLOAT32_C( -282.66),
                         SIMDE_FLOAT32_C( -530.16), SIMDE_FLOAT32_C( -552.16),
                         SIMDE_FLOAT32_C(  586.68), SIMDE_FLOAT32_C(  706.29),
                         SIMDE_FLOAT32_C(  537.21), SIMDE_FLOAT32_C( -450.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -642.32), SIMDE_FLOAT32_C( -725.64),
                         SIMDE_FLOAT32_C(  162.03), SIMDE_FLOAT32_C(  624.91),
                         SIMDE_FLOAT32_C(  415.33), SIMDE_FLOAT32_C(  -62.25),
                         SIMDE_FLOAT32_C(  445.83), SIMDE_FLOAT32_C( -888.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  162.03), SIMDE_FLOAT32_C(  162.03),
                         SIMDE_FLOAT32_C( -530.16), SIMDE_FLOAT32_C( -530.16),
                         SIMDE_FLOAT32_C(  445.83), SIMDE_FLOAT32_C(  445.83),
                         SIMDE_FLOAT32_C(  537.21), SIMDE_FLOAT32_C(  537.21)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -725.64), SIMDE_FLOAT32_C( -725.64),
                         SIMDE_FLOAT32_C( -282.66), SIMDE_FLOAT32_C( -282.66),
                         SIMDE_FLOAT32_C(  -62.25), SIMDE_FLOAT32_C(  -62.25),
                         SIMDE_FLOAT32_C(  706.29), SIMDE_FLOAT32_C(  706.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -586.61), SIMDE_FLOAT32_C( -444.58),
                         SIMDE_FLOAT32_C(  804.56), SIMDE_FLOAT32_C( -661.78),
                         SIMDE_FLOAT32_C( -398.96), SIMDE_FLOAT32_C(  555.99),
                         SIMDE_FLOAT32_C(  255.05), SIMDE_FLOAT32_C(  326.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   59.74), SIMDE_FLOAT32_C(  544.15),
                         SIMDE_FLOAT32_C(  414.09), SIMDE_FLOAT32_C(   11.73),
                         SIMDE_FLOAT32_C(  678.11), SIMDE_FLOAT32_C(  264.09),
                         SIMDE_FLOAT32_C(  492.67), SIMDE_FLOAT32_C( -690.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  414.09), SIMDE_FLOAT32_C(  414.09),
                         SIMDE_FLOAT32_C(  804.56), SIMDE_FLOAT32_C(  804.56),
                         SIMDE_FLOAT32_C(  492.67), SIMDE_FLOAT32_C(  492.67),
                         SIMDE_FLOAT32_C(  255.05), SIMDE_FLOAT32_C(  255.05)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  544.15), SIMDE_FLOAT32_C(  544.15),
                         SIMDE_FLOAT32_C( -444.58), SIMDE_FLOAT32_C( -444.58),
                         SIMDE_FLOAT32_C(  264.09), SIMDE_FLOAT32_C(  264.09),
                         SIMDE_FLOAT32_C(  555.99), SIMDE_FLOAT32_C(  555.99)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -738.46), SIMDE_FLOAT32_C(  931.97),
                         SIMDE_FLOAT32_C( -722.34), SIMDE_FLOAT32_C( -600.75),
                         SIMDE_FLOAT32_C( -215.41), SIMDE_FLOAT32_C( -472.40),
                         SIMDE_FLOAT32_C(  -60.64), SIMDE_FLOAT32_C(  120.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  773.86), SIMDE_FLOAT32_C( -298.57),
                         SIMDE_FLOAT32_C(  440.00), SIMDE_FLOAT32_C( -205.51),
                         SIMDE_FLOAT32_C( -237.18), SIMDE_FLOAT32_C( -760.22),
                         SIMDE_FLOAT32_C( -446.09), SIMDE_FLOAT32_C( -381.56)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  440.00), SIMDE_FLOAT32_C(  440.00),
                         SIMDE_FLOAT32_C( -722.34), SIMDE_FLOAT32_C( -722.34),
                         SIMDE_FLOAT32_C( -446.09), SIMDE_FLOAT32_C( -446.09),
                         SIMDE_FLOAT32_C(  -60.64), SIMDE_FLOAT32_C(  -60.64)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -298.57), SIMDE_FLOAT32_C( -298.57),
                         SIMDE_FLOAT32_C(  931.97), SIMDE_FLOAT32_C(  931.97),
                         SIMDE_FLOAT32_C( -760.22), SIMDE_FLOAT32_C( -760.22),
                         SIMDE_FLOAT32_C( -472.40), SIMDE_FLOAT32_C( -472.40)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -868.52), SIMDE_FLOAT32_C( -561.35),
                         SIMDE_FLOAT32_C( -571.37), SIMDE_FLOAT32_C(  511.95),
                         SIMDE_FLOAT32_C(  794.40), SIMDE_FLOAT32_C(  468.29),
                         SIMDE_FLOAT32_C(  949.07), SIMDE_FLOAT32_C(  504.01)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -600.88), SIMDE_FLOAT32_C( -128.06),
                         SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C( -620.63),
                         SIMDE_FLOAT32_C(  888.33), SIMDE_FLOAT32_C(  864.93),
                         SIMDE_FLOAT32_C( -548.30), SIMDE_FLOAT32_C(  693.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   -3.70), SIMDE_FLOAT32_C(   -3.70),
                         SIMDE_FLOAT32_C( -571.37), SIMDE_FLOAT32_C( -571.37),
                         SIMDE_FLOAT32_C( -548.30), SIMDE_FLOAT32_C( -548.30),
                         SIMDE_FLOAT32_C(  949.07), SIMDE_FLOAT32_C(  949.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -128.06), SIMDE_FLOAT32_C( -128.06),
                         SIMDE_FLOAT32_C( -561.35), SIMDE_FLOAT32_C( -561.35),
                         SIMDE_FLOAT32_C(  864.93), SIMDE_FLOAT32_C(  864.93),
                         SIMDE_FLOAT32_C(  468.29), SIMDE_FLOAT32_C(  468.29)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -274.24), SIMDE_FLOAT32_C( -910.17),
                         SIMDE_FLOAT32_C(  548.80), SIMDE_FLOAT32_C( -838.00),
                         SIMDE_FLOAT32_C( -379.63), SIMDE_FLOAT32_C(  775.00),
                         SIMDE_FLOAT32_C( -238.61), SIMDE_FLOAT32_C( -278.26)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   28.03), SIMDE_FLOAT32_C( -206.70),
                         SIMDE_FLOAT32_C(  -80.05), SIMDE_FLOAT32_C(  380.68),
                         SIMDE_FLOAT32_C(  342.48), SIMDE_FLOAT32_C(  525.81),
                         SIMDE_FLOAT32_C( -202.62), SIMDE_FLOAT32_C(  412.48)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -80.05), SIMDE_FLOAT32_C(  -80.05),
                         SIMDE_FLOAT32_C(  548.80), SIMDE_FLOAT32_C(  548.80),
                         SIMDE_FLOAT32_C( -202.62), SIMDE_FLOAT32_C( -202.62),
                         SIMDE_FLOAT32_C( -238.61), SIMDE_FLOAT32_C( -238.61)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -206.70), SIMDE_FLOAT32_C( -206.70),
                         SIMDE_FLOAT32_C( -910.17), SIMDE_FLOAT32_C( -910.17),
                         SIMDE_FLOAT32_C(  525.81), SIMDE_FLOAT32_C(  525.81),
                         SIMDE_FLOAT32_C(  775.00), SIMDE_FLOAT32_C(  775.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  270.95), SIMDE_FLOAT32_C(  727.79),
                         SIMDE_FLOAT32_C(  361.48), SIMDE_FLOAT32_C(  843.29),
                         SIMDE_FLOAT32_C( -519.67), SIMDE_FLOAT32_C( -181.50),
                         SIMDE_FLOAT32_C( -112.74), SIMDE_FLOAT32_C(  545.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -132.55), SIMDE_FLOAT32_C( -718.86),
                         SIMDE_FLOAT32_C(  142.59), SIMDE_FLOAT32_C(  742.01),
                         SIMDE_FLOAT32_C(  593.39), SIMDE_FLOAT32_C(  515.42),
                         SIMDE_FLOAT32_C(  897.24), SIMDE_FLOAT32_C(  759.74)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  142.59), SIMDE_FLOAT32_C(  142.59),
                         SIMDE_FLOAT32_C(  361.48), SIMDE_FLOAT32_C(  361.48),
                         SIMDE_FLOAT32_C(  897.24), SIMDE_FLOAT32_C(  897.24),
                         SIMDE_FLOAT32_C( -112.74), SIMDE_FLOAT32_C( -112.74)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -718.86), SIMDE_FLOAT32_C( -718.86),
                         SIMDE_FLOAT32_C(  727.79), SIMDE_FLOAT32_C(  727.79),
                         SIMDE_FLOAT32_C(  515.42), SIMDE_FLOAT32_C(  515.42),
                         SIMDE_FLOAT32_C( -181.50), SIMDE_FLOAT32_C( -181.50)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -964.03), SIMDE_FLOAT32_C(  334.31),
                         SIMDE_FLOAT32_C( -520.63), SIMDE_FLOAT32_C(  -60.01),
                         SIMDE_FLOAT32_C(  788.31), SIMDE_FLOAT32_C( -532.00),
                         SIMDE_FLOAT32_C(  146.02), SIMDE_FLOAT32_C(  -45.94)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -225.66), SIMDE_FLOAT32_C( -255.31),
                         SIMDE_FLOAT32_C(  440.71), SIMDE_FLOAT32_C( -673.25),
                         SIMDE_FLOAT32_C( -649.50), SIMDE_FLOAT32_C( -704.29),
                         SIMDE_FLOAT32_C(  340.20), SIMDE_FLOAT32_C( -395.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  440.71), SIMDE_FLOAT32_C(  440.71),
                         SIMDE_FLOAT32_C( -520.63), SIMDE_FLOAT32_C( -520.63),
                         SIMDE_FLOAT32_C(  340.20), SIMDE_FLOAT32_C(  340.20),
                         SIMDE_FLOAT32_C(  146.02), SIMDE_FLOAT32_C(  146.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -255.31), SIMDE_FLOAT32_C( -255.31),
                         SIMDE_FLOAT32_C(  334.31), SIMDE_FLOAT32_C(  334.31),
                         SIMDE_FLOAT32_C( -704.29), SIMDE_FLOAT32_C( -704.29),
                         SIMDE_FLOAT32_C( -532.00), SIMDE_FLOAT32_C( -532.00)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r;

    r = simde_mm256_shuffle_ps(test_vec[i].a, test_vec[i].b, 0x55);
    simde_assert_m256_close(r, test_vec[i].r1, 1);

    r = simde_mm256_shuffle_ps(test_vec[i].a, test_vec[i].b, 0xaa);
    simde_assert_m256_close(r, test_vec[i].r2, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_shuffle_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r1;
    simde__m256d r2;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  934.66), SIMDE_FLOAT64_C( -881.67),
                         SIMDE_FLOAT64_C(  836.94), SIMDE_FLOAT64_C( -777.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -249.31), SIMDE_FLOAT64_C(  364.30),
                         SIMDE_FLOAT64_C( -553.11), SIMDE_FLOAT64_C( -269.32)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  364.30), SIMDE_FLOAT64_C(  934.66),
                         SIMDE_FLOAT64_C( -269.32), SIMDE_FLOAT64_C(  836.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -249.31), SIMDE_FLOAT64_C( -881.67),
                         SIMDE_FLOAT64_C( -553.11), SIMDE_FLOAT64_C( -777.20)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.38), SIMDE_FLOAT64_C(  768.57),
                         SIMDE_FLOAT64_C(  912.15), SIMDE_FLOAT64_C(  -23.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -107.98), SIMDE_FLOAT64_C( -226.33),
                         SIMDE_FLOAT64_C(  924.14), SIMDE_FLOAT64_C( -792.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -226.33), SIMDE_FLOAT64_C( -570.38),
                         SIMDE_FLOAT64_C( -792.70), SIMDE_FLOAT64_C(  912.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -107.98), SIMDE_FLOAT64_C(  768.57),
                         SIMDE_FLOAT64_C(  924.14), SIMDE_FLOAT64_C(  -23.81)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -307.34), SIMDE_FLOAT64_C(  256.70),
                         SIMDE_FLOAT64_C(  615.34), SIMDE_FLOAT64_C(  966.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.56), SIMDE_FLOAT64_C( -102.88),
                         SIMDE_FLOAT64_C(  558.25), SIMDE_FLOAT64_C(  907.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -102.88), SIMDE_FLOAT64_C( -307.34),
                         SIMDE_FLOAT64_C(  907.54), SIMDE_FLOAT64_C(  615.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   80.56), SIMDE_FLOAT64_C(  256.70),
                         SIMDE_FLOAT64_C(  558.25), SIMDE_FLOAT64_C(  966.02)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -428.91), SIMDE_FLOAT64_C( -946.94),
                         SIMDE_FLOAT64_C( -242.51), SIMDE_FLOAT64_C(  207.30)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  871.74), SIMDE_FLOAT64_C(  294.25),
                         SIMDE_FLOAT64_C(  -23.76), SIMDE_FLOAT64_C(  857.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  294.25), SIMDE_FLOAT64_C( -428.91),
                         SIMDE_FLOAT64_C(  857.02), SIMDE_FLOAT64_C( -242.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  871.74), SIMDE_FLOAT64_C( -946.94),
                         SIMDE_FLOAT64_C(  -23.76), SIMDE_FLOAT64_C(  207.30)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  684.37), SIMDE_FLOAT64_C(  -77.07),
                         SIMDE_FLOAT64_C( -492.40), SIMDE_FLOAT64_C( -711.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  911.18), SIMDE_FLOAT64_C( -875.79),
                         SIMDE_FLOAT64_C(  168.17), SIMDE_FLOAT64_C( -582.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -875.79), SIMDE_FLOAT64_C(  684.37),
                         SIMDE_FLOAT64_C( -582.90), SIMDE_FLOAT64_C( -492.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  911.18), SIMDE_FLOAT64_C(  -77.07),
                         SIMDE_FLOAT64_C(  168.17), SIMDE_FLOAT64_C( -711.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  844.28), SIMDE_FLOAT64_C( -547.02),
                         SIMDE_FLOAT64_C( -536.51), SIMDE_FLOAT64_C( -341.28)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.14), SIMDE_FLOAT64_C(   35.47),
                         SIMDE_FLOAT64_C(  536.74), SIMDE_FLOAT64_C(  843.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   35.47), SIMDE_FLOAT64_C(  844.28),
                         SIMDE_FLOAT64_C(  843.54), SIMDE_FLOAT64_C( -536.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -205.14), SIMDE_FLOAT64_C( -547.02),
                         SIMDE_FLOAT64_C(  536.74), SIMDE_FLOAT64_C( -341.28)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  597.24), SIMDE_FLOAT64_C(   73.58),
                         SIMDE_FLOAT64_C(  575.62), SIMDE_FLOAT64_C( -337.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  430.69), SIMDE_FLOAT64_C( -764.62),
                         SIMDE_FLOAT64_C(  152.29), SIMDE_FLOAT64_C(  529.08)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -764.62), SIMDE_FLOAT64_C(  597.24),
                         SIMDE_FLOAT64_C(  529.08), SIMDE_FLOAT64_C(  575.62)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  430.69), SIMDE_FLOAT64_C(   73.58),
                         SIMDE_FLOAT64_C(  152.29), SIMDE_FLOAT64_C( -337.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  276.59), SIMDE_FLOAT64_C(  918.52),
                         SIMDE_FLOAT64_C(  859.45), SIMDE_FLOAT64_C(   26.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -365.57), SIMDE_FLOAT64_C(  780.68),
                         SIMDE_FLOAT64_C(  333.70), SIMDE_FLOAT64_C( -391.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  780.68), SIMDE_FLOAT64_C(  276.59),
                         SIMDE_FLOAT64_C( -391.20), SIMDE_FLOAT64_C(  859.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -365.57), SIMDE_FLOAT64_C(  918.52),
                         SIMDE_FLOAT64_C(  333.70), SIMDE_FLOAT64_C(   26.68)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r;

    r = simde_mm256_shuffle_pd(test_vec[i].a, test_vec[i].b, 0x5);
    simde_assert_m256d_close(r, test_vec[i].r1, 1);

    r = simde_mm256_shuffle_pd(test_vec[i].a, test_vec[i].b, 0xa);
    simde_assert_m256d_close(r, test_vec[i].r2, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sqrt_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   37.27), SIMDE_FLOAT32_C(  842.37),
                         SIMDE_FLOAT32_C(  821.35), SIMDE_FLOAT32_C(  882.42),
                         SIMDE_FLOAT32_C(  506.85), SIMDE_FLOAT32_C(  418.78),
                         SIMDE_FLOAT32_C(  759.20), SIMDE_FLOAT32_C(  903.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    6.10), SIMDE_FLOAT32_C(   29.02),
                         SIMDE_FLOAT32_C(   28.66), SIMDE_FLOAT32_C(   29.71),
                         SIMDE_FLOAT32_C(   22.51), SIMDE_FLOAT32_C(   20.46),
                         SIMDE_FLOAT32_C(   27.55), SIMDE_FLOAT32_C(   30.05)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  675.11), SIMDE_FLOAT32_C(  473.44),
                         SIMDE_FLOAT32_C(  936.76), SIMDE_FLOAT32_C(  315.53),
                         SIMDE_FLOAT32_C(  585.70), SIMDE_FLOAT32_C(  466.99),
                         SIMDE_FLOAT32_C(  876.99), SIMDE_FLOAT32_C(  421.09)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   25.98), SIMDE_FLOAT32_C(   21.76),
                         SIMDE_FLOAT32_C(   30.61), SIMDE_FLOAT32_C(   17.76),
                         SIMDE_FLOAT32_C(   24.20), SIMDE_FLOAT32_C(   21.61),
                         SIMDE_FLOAT32_C(   29.61), SIMDE_FLOAT32_C(   20.52)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  455.63), SIMDE_FLOAT32_C(  708.48),
                         SIMDE_FLOAT32_C(  426.65), SIMDE_FLOAT32_C(   16.24),
                         SIMDE_FLOAT32_C(  899.49), SIMDE_FLOAT32_C(  710.23),
                         SIMDE_FLOAT32_C(  195.07), SIMDE_FLOAT32_C(  877.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   21.35), SIMDE_FLOAT32_C(   26.62),
                         SIMDE_FLOAT32_C(   20.66), SIMDE_FLOAT32_C(    4.03),
                         SIMDE_FLOAT32_C(   29.99), SIMDE_FLOAT32_C(   26.65),
                         SIMDE_FLOAT32_C(   13.97), SIMDE_FLOAT32_C(   29.62)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  247.65), SIMDE_FLOAT32_C(  650.69),
                         SIMDE_FLOAT32_C(  691.01), SIMDE_FLOAT32_C(  931.91),
                         SIMDE_FLOAT32_C(  760.76), SIMDE_FLOAT32_C(  925.05),
                         SIMDE_FLOAT32_C(  438.39), SIMDE_FLOAT32_C(  204.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   15.74), SIMDE_FLOAT32_C(   25.51),
                         SIMDE_FLOAT32_C(   26.29), SIMDE_FLOAT32_C(   30.53),
                         SIMDE_FLOAT32_C(   27.58), SIMDE_FLOAT32_C(   30.41),
                         SIMDE_FLOAT32_C(   20.94), SIMDE_FLOAT32_C(   14.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  281.85), SIMDE_FLOAT32_C(  525.43),
                         SIMDE_FLOAT32_C(   50.88), SIMDE_FLOAT32_C(  685.15),
                         SIMDE_FLOAT32_C(  223.40), SIMDE_FLOAT32_C(  911.30),
                         SIMDE_FLOAT32_C(   97.50), SIMDE_FLOAT32_C(  436.55)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   16.79), SIMDE_FLOAT32_C(   22.92),
                         SIMDE_FLOAT32_C(    7.13), SIMDE_FLOAT32_C(   26.18),
                         SIMDE_FLOAT32_C(   14.95), SIMDE_FLOAT32_C(   30.19),
                         SIMDE_FLOAT32_C(    9.87), SIMDE_FLOAT32_C(   20.89)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  420.63), SIMDE_FLOAT32_C(  643.40),
                         SIMDE_FLOAT32_C(  474.44), SIMDE_FLOAT32_C(  474.06),
                         SIMDE_FLOAT32_C(  331.02), SIMDE_FLOAT32_C(  191.18),
                         SIMDE_FLOAT32_C(  614.70), SIMDE_FLOAT32_C(  135.59)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   20.51), SIMDE_FLOAT32_C(   25.37),
                         SIMDE_FLOAT32_C(   21.78), SIMDE_FLOAT32_C(   21.77),
                         SIMDE_FLOAT32_C(   18.19), SIMDE_FLOAT32_C(   13.83),
                         SIMDE_FLOAT32_C(   24.79), SIMDE_FLOAT32_C(   11.64)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  777.57), SIMDE_FLOAT32_C(  684.09),
                         SIMDE_FLOAT32_C(  183.20), SIMDE_FLOAT32_C(  761.60),
                         SIMDE_FLOAT32_C(  226.72), SIMDE_FLOAT32_C(  710.47),
                         SIMDE_FLOAT32_C(  853.48), SIMDE_FLOAT32_C(  115.80)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   27.88), SIMDE_FLOAT32_C(   26.16),
                         SIMDE_FLOAT32_C(   13.54), SIMDE_FLOAT32_C(   27.60),
                         SIMDE_FLOAT32_C(   15.06), SIMDE_FLOAT32_C(   26.65),
                         SIMDE_FLOAT32_C(   29.21), SIMDE_FLOAT32_C(   10.76)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  797.47), SIMDE_FLOAT32_C(  634.08),
                         SIMDE_FLOAT32_C(  881.12), SIMDE_FLOAT32_C(  697.30),
                         SIMDE_FLOAT32_C(  189.46), SIMDE_FLOAT32_C(   47.99),
                         SIMDE_FLOAT32_C(   85.88), SIMDE_FLOAT32_C(  938.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   28.24), SIMDE_FLOAT32_C(   25.18),
                         SIMDE_FLOAT32_C(   29.68), SIMDE_FLOAT32_C(   26.41),
                         SIMDE_FLOAT32_C(   13.76), SIMDE_FLOAT32_C(    6.93),
                         SIMDE_FLOAT32_C(    9.27), SIMDE_FLOAT32_C(   30.63)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sqrt_ps(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setzero_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256 r =
    simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                       SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                       SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                       SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00));

  simde__m256 res = simde_mm256_setzero_ps();
  simde_assert_m256_close(r, res, 1);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setzero_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256d r =
    simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                       SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00));

  simde__m256d res = simde_mm256_setzero_pd();
  simde_assert_m256d_close(r, res, 1);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_setzero_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256i r =
    simde_mm256_set_epi32(INT32_C(0), INT32_C(0), INT32_C(0), INT32_C(0),
                          INT32_C(0), INT32_C(0), INT32_C(0), INT32_C(0));

  simde__m256i res = simde_mm256_setzero_si256();
  simde_assert_m256i_i32(r, ==, res);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sqrt_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  121.95), SIMDE_FLOAT64_C(  169.21),
                         SIMDE_FLOAT64_C(  224.34), SIMDE_FLOAT64_C(  661.75)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   11.04), SIMDE_FLOAT64_C(   13.01),
                         SIMDE_FLOAT64_C(   14.98), SIMDE_FLOAT64_C(   25.72)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   41.79), SIMDE_FLOAT64_C(   48.53),
                         SIMDE_FLOAT64_C(   17.25), SIMDE_FLOAT64_C(  585.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.46), SIMDE_FLOAT64_C(    6.97),
                         SIMDE_FLOAT64_C(    4.15), SIMDE_FLOAT64_C(   24.19)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  323.54), SIMDE_FLOAT64_C(   12.60),
                         SIMDE_FLOAT64_C(  916.80), SIMDE_FLOAT64_C(  392.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   17.99), SIMDE_FLOAT64_C(    3.55),
                         SIMDE_FLOAT64_C(   30.28), SIMDE_FLOAT64_C(   19.80)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  317.36), SIMDE_FLOAT64_C(  248.26),
                         SIMDE_FLOAT64_C(   48.91), SIMDE_FLOAT64_C(  291.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   17.81), SIMDE_FLOAT64_C(   15.76),
                         SIMDE_FLOAT64_C(    6.99), SIMDE_FLOAT64_C(   17.06)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  476.37), SIMDE_FLOAT64_C(  799.71),
                         SIMDE_FLOAT64_C(  234.23), SIMDE_FLOAT64_C(  908.93)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   21.83), SIMDE_FLOAT64_C(   28.28),
                         SIMDE_FLOAT64_C(   15.30), SIMDE_FLOAT64_C(   30.15)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  937.16), SIMDE_FLOAT64_C(  886.92),
                         SIMDE_FLOAT64_C(  703.77), SIMDE_FLOAT64_C(  383.22)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   30.61), SIMDE_FLOAT64_C(   29.78),
                         SIMDE_FLOAT64_C(   26.53), SIMDE_FLOAT64_C(   19.58)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   36.08), SIMDE_FLOAT64_C(  932.02),
                         SIMDE_FLOAT64_C(  592.55), SIMDE_FLOAT64_C(  593.01)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    6.01), SIMDE_FLOAT64_C(   30.53),
                         SIMDE_FLOAT64_C(   24.34), SIMDE_FLOAT64_C(   24.35)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  436.31), SIMDE_FLOAT64_C(  915.76),
                         SIMDE_FLOAT64_C(  575.57), SIMDE_FLOAT64_C(  268.70)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   20.89), SIMDE_FLOAT64_C(   30.26),
                         SIMDE_FLOAT64_C(   23.99), SIMDE_FLOAT64_C(   16.39)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sqrt_pd(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    SIMDE_ALIGN(32) simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  256.09), SIMDE_FLOAT32_C(  768.79),
                         SIMDE_FLOAT32_C(  201.90), SIMDE_FLOAT32_C(  339.33),
                         SIMDE_FLOAT32_C(  957.46), SIMDE_FLOAT32_C(  728.44),
                         SIMDE_FLOAT32_C(   73.67), SIMDE_FLOAT32_C(  440.11)),
      { SIMDE_FLOAT32_C(  440.11), SIMDE_FLOAT32_C(   73.67),
        SIMDE_FLOAT32_C(  728.44), SIMDE_FLOAT32_C(  957.46),
        SIMDE_FLOAT32_C(  339.33), SIMDE_FLOAT32_C(  201.90),
        SIMDE_FLOAT32_C(  768.79), SIMDE_FLOAT32_C(  256.09) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.04), SIMDE_FLOAT32_C( -425.25),
                         SIMDE_FLOAT32_C(  471.77), SIMDE_FLOAT32_C(  976.75),
                         SIMDE_FLOAT32_C( -510.20), SIMDE_FLOAT32_C(  696.54),
                         SIMDE_FLOAT32_C( -843.54), SIMDE_FLOAT32_C( -868.41)),
      { SIMDE_FLOAT32_C( -868.41), SIMDE_FLOAT32_C( -843.54),
        SIMDE_FLOAT32_C(  696.54), SIMDE_FLOAT32_C( -510.20),
        SIMDE_FLOAT32_C(  976.75), SIMDE_FLOAT32_C(  471.77),
        SIMDE_FLOAT32_C( -425.25), SIMDE_FLOAT32_C(  -72.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -304.23), SIMDE_FLOAT32_C(  477.48),
                         SIMDE_FLOAT32_C(  356.58), SIMDE_FLOAT32_C(  955.81),
                         SIMDE_FLOAT32_C(  999.99), SIMDE_FLOAT32_C(  487.33),
                         SIMDE_FLOAT32_C(  633.61), SIMDE_FLOAT32_C(  518.11)),
      { SIMDE_FLOAT32_C(  518.11), SIMDE_FLOAT32_C(  633.61),
        SIMDE_FLOAT32_C(  487.33), SIMDE_FLOAT32_C(  999.99),
        SIMDE_FLOAT32_C(  955.81), SIMDE_FLOAT32_C(  356.58),
        SIMDE_FLOAT32_C(  477.48), SIMDE_FLOAT32_C( -304.23) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C( -296.25),
                         SIMDE_FLOAT32_C(  948.33), SIMDE_FLOAT32_C( -584.17),
                         SIMDE_FLOAT32_C( -796.11), SIMDE_FLOAT32_C(  -38.84),
                         SIMDE_FLOAT32_C( -706.11), SIMDE_FLOAT32_C(  347.32)),
      { SIMDE_FLOAT32_C(  347.32), SIMDE_FLOAT32_C( -706.11),
        SIMDE_FLOAT32_C(  -38.84), SIMDE_FLOAT32_C( -796.11),
        SIMDE_FLOAT32_C( -584.17), SIMDE_FLOAT32_C(  948.33),
        SIMDE_FLOAT32_C( -296.25), SIMDE_FLOAT32_C(   88.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -143.76), SIMDE_FLOAT32_C(  504.36),
                         SIMDE_FLOAT32_C( -154.12), SIMDE_FLOAT32_C(  375.43),
                         SIMDE_FLOAT32_C( -307.18), SIMDE_FLOAT32_C(  256.93),
                         SIMDE_FLOAT32_C(   78.86), SIMDE_FLOAT32_C(  526.77)),
      { SIMDE_FLOAT32_C(  526.77), SIMDE_FLOAT32_C(   78.86),
        SIMDE_FLOAT32_C(  256.93), SIMDE_FLOAT32_C( -307.18),
        SIMDE_FLOAT32_C(  375.43), SIMDE_FLOAT32_C( -154.12),
        SIMDE_FLOAT32_C(  504.36), SIMDE_FLOAT32_C( -143.76) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  597.82), SIMDE_FLOAT32_C(  697.68),
                         SIMDE_FLOAT32_C( -285.13), SIMDE_FLOAT32_C(  354.51),
                         SIMDE_FLOAT32_C(   41.32), SIMDE_FLOAT32_C( -445.78),
                         SIMDE_FLOAT32_C( -483.17), SIMDE_FLOAT32_C( -727.28)),
      { SIMDE_FLOAT32_C( -727.28), SIMDE_FLOAT32_C( -483.17),
        SIMDE_FLOAT32_C( -445.78), SIMDE_FLOAT32_C(   41.32),
        SIMDE_FLOAT32_C(  354.51), SIMDE_FLOAT32_C( -285.13),
        SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  597.82) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.93), SIMDE_FLOAT32_C( -382.04),
                         SIMDE_FLOAT32_C(  392.67), SIMDE_FLOAT32_C(  690.10),
                         SIMDE_FLOAT32_C(  -30.26), SIMDE_FLOAT32_C( -968.87),
                         SIMDE_FLOAT32_C( -246.46), SIMDE_FLOAT32_C(  625.73)),
      { SIMDE_FLOAT32_C(  625.73), SIMDE_FLOAT32_C( -246.46),
        SIMDE_FLOAT32_C( -968.87), SIMDE_FLOAT32_C(  -30.26),
        SIMDE_FLOAT32_C(  690.10), SIMDE_FLOAT32_C(  392.67),
        SIMDE_FLOAT32_C( -382.04), SIMDE_FLOAT32_C( -441.93) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  442.97), SIMDE_FLOAT32_C(  -20.37),
                         SIMDE_FLOAT32_C(  758.01), SIMDE_FLOAT32_C( -507.47),
                         SIMDE_FLOAT32_C(  529.68), SIMDE_FLOAT32_C( -598.71),
                         SIMDE_FLOAT32_C(  952.31), SIMDE_FLOAT32_C( -565.36)),
      { SIMDE_FLOAT32_C( -565.36), SIMDE_FLOAT32_C(  952.31),
        SIMDE_FLOAT32_C( -598.71), SIMDE_FLOAT32_C(  529.68),
        SIMDE_FLOAT32_C( -507.47), SIMDE_FLOAT32_C(  758.01),
        SIMDE_FLOAT32_C(  -20.37), SIMDE_FLOAT32_C(  442.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float32 r[8];
    simde_mm256_store_ps(r, test_vec[i].a);
    simde_assert_f32v_equal(simde_float32, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    SIMDE_ALIGN(32) simde_float64 r[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  771.84), SIMDE_FLOAT64_C(  578.19),
                         SIMDE_FLOAT64_C(  287.63), SIMDE_FLOAT64_C(  196.16)),
      { SIMDE_FLOAT64_C(  196.16), SIMDE_FLOAT64_C(  287.63),
        SIMDE_FLOAT64_C(  578.19), SIMDE_FLOAT64_C(  771.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.73), SIMDE_FLOAT64_C( -687.45),
                         SIMDE_FLOAT64_C( -865.09), SIMDE_FLOAT64_C(  586.03)),
      { SIMDE_FLOAT64_C(  586.03), SIMDE_FLOAT64_C( -865.09),
        SIMDE_FLOAT64_C( -687.45), SIMDE_FLOAT64_C( -941.73) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -342.90), SIMDE_FLOAT64_C( -658.61),
                         SIMDE_FLOAT64_C(  882.05), SIMDE_FLOAT64_C( -607.89)),
      { SIMDE_FLOAT64_C( -607.89), SIMDE_FLOAT64_C(  882.05),
        SIMDE_FLOAT64_C( -658.61), SIMDE_FLOAT64_C( -342.90) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.91), SIMDE_FLOAT64_C( -473.20),
                         SIMDE_FLOAT64_C(  170.76), SIMDE_FLOAT64_C( -407.02)),
      { SIMDE_FLOAT64_C( -407.02), SIMDE_FLOAT64_C(  170.76),
        SIMDE_FLOAT64_C( -473.20), SIMDE_FLOAT64_C( -248.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.69), SIMDE_FLOAT64_C(  697.67),
                         SIMDE_FLOAT64_C(  911.25), SIMDE_FLOAT64_C( -299.04)),
      { SIMDE_FLOAT64_C( -299.04), SIMDE_FLOAT64_C(  911.25),
        SIMDE_FLOAT64_C(  697.67), SIMDE_FLOAT64_C(  181.69) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -630.92), SIMDE_FLOAT64_C( -612.42),
                         SIMDE_FLOAT64_C(  645.34), SIMDE_FLOAT64_C( -379.90)),
      { SIMDE_FLOAT64_C( -379.90), SIMDE_FLOAT64_C(  645.34),
        SIMDE_FLOAT64_C( -612.42), SIMDE_FLOAT64_C( -630.92) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -339.32), SIMDE_FLOAT64_C(  404.98),
                         SIMDE_FLOAT64_C( -361.76), SIMDE_FLOAT64_C(  391.60)),
      { SIMDE_FLOAT64_C(  391.60), SIMDE_FLOAT64_C( -361.76),
        SIMDE_FLOAT64_C(  404.98), SIMDE_FLOAT64_C( -339.32) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  714.72), SIMDE_FLOAT64_C(  997.58),
                         SIMDE_FLOAT64_C(  807.47), SIMDE_FLOAT64_C(  948.80)),
      { SIMDE_FLOAT64_C(  948.80), SIMDE_FLOAT64_C(  807.47),
        SIMDE_FLOAT64_C(  997.58), SIMDE_FLOAT64_C(  714.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float64 r[4];
    simde_mm256_store_pd(r, test_vec[i].a);
    simde_assert_f64v_close(simde_float64, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_store_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)),
      simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)) },
    { simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)),
      simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)) },
    { simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)),
      simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)) },
    { simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)),
      simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)) },
    { simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)),
      simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)) },
    { simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)),
      simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)) },
    { simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)),
      simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)) },
    { simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)),
      simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_store_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  389.47), SIMDE_FLOAT32_C(  -23.53),
                         SIMDE_FLOAT32_C(  971.41), SIMDE_FLOAT32_C(  968.93),
                         SIMDE_FLOAT32_C(  388.52), SIMDE_FLOAT32_C(  400.32),
                         SIMDE_FLOAT32_C( -988.67), SIMDE_FLOAT32_C(  867.57)),
      { SIMDE_FLOAT32_C(  867.57), SIMDE_FLOAT32_C( -988.67),
        SIMDE_FLOAT32_C(  400.32), SIMDE_FLOAT32_C(  388.52),
        SIMDE_FLOAT32_C(  968.93), SIMDE_FLOAT32_C(  971.41),
        SIMDE_FLOAT32_C(  -23.53), SIMDE_FLOAT32_C(  389.47) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -904.63), SIMDE_FLOAT32_C(  373.49),
                         SIMDE_FLOAT32_C( -535.56), SIMDE_FLOAT32_C(  674.97),
                         SIMDE_FLOAT32_C( -321.09), SIMDE_FLOAT32_C( -666.72),
                         SIMDE_FLOAT32_C(  574.65), SIMDE_FLOAT32_C( -486.68)),
      { SIMDE_FLOAT32_C( -486.68), SIMDE_FLOAT32_C(  574.65),
        SIMDE_FLOAT32_C( -666.72), SIMDE_FLOAT32_C( -321.09),
        SIMDE_FLOAT32_C(  674.97), SIMDE_FLOAT32_C( -535.56),
        SIMDE_FLOAT32_C(  373.49), SIMDE_FLOAT32_C( -904.63) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  716.68), SIMDE_FLOAT32_C( -902.50),
                         SIMDE_FLOAT32_C(  689.19), SIMDE_FLOAT32_C(  562.96),
                         SIMDE_FLOAT32_C(  218.97), SIMDE_FLOAT32_C( -717.02),
                         SIMDE_FLOAT32_C(   50.08), SIMDE_FLOAT32_C(  473.03)),
      { SIMDE_FLOAT32_C(  473.03), SIMDE_FLOAT32_C(   50.08),
        SIMDE_FLOAT32_C( -717.02), SIMDE_FLOAT32_C(  218.97),
        SIMDE_FLOAT32_C(  562.96), SIMDE_FLOAT32_C(  689.19),
        SIMDE_FLOAT32_C( -902.50), SIMDE_FLOAT32_C(  716.68) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -748.65), SIMDE_FLOAT32_C( -546.25),
                         SIMDE_FLOAT32_C( -755.41), SIMDE_FLOAT32_C(  720.41),
                         SIMDE_FLOAT32_C(  469.62), SIMDE_FLOAT32_C( -529.37),
                         SIMDE_FLOAT32_C(   68.16), SIMDE_FLOAT32_C( -880.26)),
      { SIMDE_FLOAT32_C( -880.26), SIMDE_FLOAT32_C(   68.16),
        SIMDE_FLOAT32_C( -529.37), SIMDE_FLOAT32_C(  469.62),
        SIMDE_FLOAT32_C(  720.41), SIMDE_FLOAT32_C( -755.41),
        SIMDE_FLOAT32_C( -546.25), SIMDE_FLOAT32_C( -748.65) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -639.31), SIMDE_FLOAT32_C(  210.80),
                         SIMDE_FLOAT32_C( -481.50), SIMDE_FLOAT32_C( -773.33),
                         SIMDE_FLOAT32_C(  766.24), SIMDE_FLOAT32_C(  722.05),
                         SIMDE_FLOAT32_C(  569.99), SIMDE_FLOAT32_C(   78.20)),
      { SIMDE_FLOAT32_C(   78.20), SIMDE_FLOAT32_C(  569.99),
        SIMDE_FLOAT32_C(  722.05), SIMDE_FLOAT32_C(  766.24),
        SIMDE_FLOAT32_C( -773.33), SIMDE_FLOAT32_C( -481.50),
        SIMDE_FLOAT32_C(  210.80), SIMDE_FLOAT32_C( -639.31) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  219.96), SIMDE_FLOAT32_C( -967.95),
                         SIMDE_FLOAT32_C( -966.73), SIMDE_FLOAT32_C( -375.54),
                         SIMDE_FLOAT32_C( -872.08), SIMDE_FLOAT32_C( -211.68),
                         SIMDE_FLOAT32_C(  797.84), SIMDE_FLOAT32_C(  819.26)),
      { SIMDE_FLOAT32_C(  819.26), SIMDE_FLOAT32_C(  797.84),
        SIMDE_FLOAT32_C( -211.68), SIMDE_FLOAT32_C( -872.08),
        SIMDE_FLOAT32_C( -375.54), SIMDE_FLOAT32_C( -966.73),
        SIMDE_FLOAT32_C( -967.95), SIMDE_FLOAT32_C(  219.96) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  601.98), SIMDE_FLOAT32_C( -827.42),
                         SIMDE_FLOAT32_C(  747.06), SIMDE_FLOAT32_C( -914.70),
                         SIMDE_FLOAT32_C(  111.41), SIMDE_FLOAT32_C(  873.12),
                         SIMDE_FLOAT32_C(  763.60), SIMDE_FLOAT32_C(  161.15)),
      { SIMDE_FLOAT32_C(  161.15), SIMDE_FLOAT32_C(  763.60),
        SIMDE_FLOAT32_C(  873.12), SIMDE_FLOAT32_C(  111.41),
        SIMDE_FLOAT32_C( -914.70), SIMDE_FLOAT32_C(  747.06),
        SIMDE_FLOAT32_C( -827.42), SIMDE_FLOAT32_C(  601.98) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  800.45), SIMDE_FLOAT32_C(  526.22),
                         SIMDE_FLOAT32_C(  670.34), SIMDE_FLOAT32_C(  433.87),
                         SIMDE_FLOAT32_C(  651.08), SIMDE_FLOAT32_C( -532.01),
                         SIMDE_FLOAT32_C( -619.94), SIMDE_FLOAT32_C(   88.39)),
      { SIMDE_FLOAT32_C(   88.39), SIMDE_FLOAT32_C( -619.94),
        SIMDE_FLOAT32_C( -532.01), SIMDE_FLOAT32_C(  651.08),
        SIMDE_FLOAT32_C(  433.87), SIMDE_FLOAT32_C(  670.34),
        SIMDE_FLOAT32_C(  526.22), SIMDE_FLOAT32_C(  800.45) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 r[8];
    simde_mm256_storeu_ps(r, test_vec[i].a);
    simde_assert_f32v_close(simde_float32, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde_float64 r[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -416.91), SIMDE_FLOAT64_C( -266.91),
                         SIMDE_FLOAT64_C(  400.77), SIMDE_FLOAT64_C(  614.06)),
      { SIMDE_FLOAT64_C(  614.06), SIMDE_FLOAT64_C(  400.77),
        SIMDE_FLOAT64_C( -266.91), SIMDE_FLOAT64_C( -416.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -82.84), SIMDE_FLOAT64_C(  375.26),
                         SIMDE_FLOAT64_C( -316.62), SIMDE_FLOAT64_C(  608.04)),
      { SIMDE_FLOAT64_C(  608.04), SIMDE_FLOAT64_C( -316.62),
        SIMDE_FLOAT64_C(  375.26), SIMDE_FLOAT64_C(  -82.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  218.37), SIMDE_FLOAT64_C( -388.98),
                         SIMDE_FLOAT64_C( -164.15), SIMDE_FLOAT64_C(   66.39)),
      { SIMDE_FLOAT64_C(   66.39), SIMDE_FLOAT64_C( -164.15),
        SIMDE_FLOAT64_C( -388.98), SIMDE_FLOAT64_C(  218.37) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  414.66), SIMDE_FLOAT64_C(  373.86),
                         SIMDE_FLOAT64_C(  387.85), SIMDE_FLOAT64_C(  140.99)),
      { SIMDE_FLOAT64_C(  140.99), SIMDE_FLOAT64_C(  387.85),
        SIMDE_FLOAT64_C(  373.86), SIMDE_FLOAT64_C(  414.66) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  513.43), SIMDE_FLOAT64_C( -671.43),
                         SIMDE_FLOAT64_C( -383.59), SIMDE_FLOAT64_C(  476.58)),
      { SIMDE_FLOAT64_C(  476.58), SIMDE_FLOAT64_C( -383.59),
        SIMDE_FLOAT64_C( -671.43), SIMDE_FLOAT64_C(  513.43) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -620.74), SIMDE_FLOAT64_C(  593.91),
                         SIMDE_FLOAT64_C(  595.45), SIMDE_FLOAT64_C(  326.69)),
      { SIMDE_FLOAT64_C(  326.69), SIMDE_FLOAT64_C(  595.45),
        SIMDE_FLOAT64_C(  593.91), SIMDE_FLOAT64_C( -620.74) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  933.41), SIMDE_FLOAT64_C( -583.63),
                         SIMDE_FLOAT64_C(  451.59), SIMDE_FLOAT64_C(   17.38)),
      { SIMDE_FLOAT64_C(   17.38), SIMDE_FLOAT64_C(  451.59),
        SIMDE_FLOAT64_C( -583.63), SIMDE_FLOAT64_C(  933.41) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -951.90), SIMDE_FLOAT64_C(  -96.08),
                         SIMDE_FLOAT64_C( -475.76), SIMDE_FLOAT64_C( -920.22)),
      { SIMDE_FLOAT64_C( -920.22), SIMDE_FLOAT64_C( -475.76),
        SIMDE_FLOAT64_C(  -96.08), SIMDE_FLOAT64_C( -951.90) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 r[4];
    simde_mm256_storeu_pd(r, test_vec[i].a);
    simde_assert_f64v_close(simde_float64, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(-1690076372), INT32_C(  273159718), INT32_C(  661600261), INT32_C( -431509063),
                            INT32_C(-1410315245), INT32_C(  938478074), INT32_C( -325173074), INT32_C( -955068873)),
      simde_mm256_set_epi32(INT32_C(-1690076372), INT32_C(  273159718), INT32_C(  661600261), INT32_C( -431509063),
                            INT32_C(-1410315245), INT32_C(  938478074), INT32_C( -325173074), INT32_C( -955068873)) },
    { simde_mm256_set_epi32(INT32_C( 1349804757), INT32_C( -716302605), INT32_C( -407964159), INT32_C( 1438548072),
                            INT32_C(-1765250498), INT32_C(-1398568590), INT32_C( -166142303), INT32_C(-1616708423)),
      simde_mm256_set_epi32(INT32_C( 1349804757), INT32_C( -716302605), INT32_C( -407964159), INT32_C( 1438548072),
                            INT32_C(-1765250498), INT32_C(-1398568590), INT32_C( -166142303), INT32_C(-1616708423)) },
    { simde_mm256_set_epi32(INT32_C( 1299583779), INT32_C( 1018639695), INT32_C(  378838390), INT32_C(  823542835),
                            INT32_C(  107040332), INT32_C( 1160607838), INT32_C(-1073772085), INT32_C(  550633253)),
      simde_mm256_set_epi32(INT32_C( 1299583779), INT32_C( 1018639695), INT32_C(  378838390), INT32_C(  823542835),
                            INT32_C(  107040332), INT32_C( 1160607838), INT32_C(-1073772085), INT32_C(  550633253)) },
    { simde_mm256_set_epi32(INT32_C(-2020164947), INT32_C( 1097566074), INT32_C(  838709016), INT32_C(-1310900036),
                            INT32_C(  205435207), INT32_C(-1570208834), INT32_C( -866634640), INT32_C(-1469292111)),
      simde_mm256_set_epi32(INT32_C(-2020164947), INT32_C( 1097566074), INT32_C(  838709016), INT32_C(-1310900036),
                            INT32_C(  205435207), INT32_C(-1570208834), INT32_C( -866634640), INT32_C(-1469292111)) },
    { simde_mm256_set_epi32(INT32_C( 1996197805), INT32_C(-1742000211), INT32_C( -252812234), INT32_C(  126353816),
                            INT32_C(-1209789142), INT32_C(-1818044476), INT32_C(-1843734346), INT32_C( 1208980142)),
      simde_mm256_set_epi32(INT32_C( 1996197805), INT32_C(-1742000211), INT32_C( -252812234), INT32_C(  126353816),
                            INT32_C(-1209789142), INT32_C(-1818044476), INT32_C(-1843734346), INT32_C( 1208980142)) },
    { simde_mm256_set_epi32(INT32_C(  264233747), INT32_C(   65047959), INT32_C(-2078914587), INT32_C(  -76956293),
                            INT32_C(-1404669906), INT32_C(-1580100987), INT32_C(-1585720935), INT32_C( -962400296)),
      simde_mm256_set_epi32(INT32_C(  264233747), INT32_C(   65047959), INT32_C(-2078914587), INT32_C(  -76956293),
                            INT32_C(-1404669906), INT32_C(-1580100987), INT32_C(-1585720935), INT32_C( -962400296)) },
    { simde_mm256_set_epi32(INT32_C(-2048043478), INT32_C( -746745729), INT32_C(  515423412), INT32_C(-1288873149),
                            INT32_C(  -50167373), INT32_C(  751152155), INT32_C(   63560258), INT32_C(  839041982)),
      simde_mm256_set_epi32(INT32_C(-2048043478), INT32_C( -746745729), INT32_C(  515423412), INT32_C(-1288873149),
                            INT32_C(  -50167373), INT32_C(  751152155), INT32_C(   63560258), INT32_C(  839041982)) },
    { simde_mm256_set_epi32(INT32_C(-1066512345), INT32_C(-1608586608), INT32_C( 2001494396), INT32_C(  667109925),
                            INT32_C(  134968304), INT32_C(  154885492), INT32_C(  204100449), INT32_C(-2103566856)),
      simde_mm256_set_epi32(INT32_C(-1066512345), INT32_C(-1608586608), INT32_C( 2001494396), INT32_C(  667109925),
                            INT32_C(  134968304), INT32_C(  154885492), INT32_C(  204100449), INT32_C(-2103566856)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_storeu_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128d(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde_float64 lo[2];
    simde_float64 hi[2];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -194.98), SIMDE_FLOAT64_C(  916.70),
                         SIMDE_FLOAT64_C(  887.89), SIMDE_FLOAT64_C( -369.82)),
      { SIMDE_FLOAT64_C( -369.82), SIMDE_FLOAT64_C(  887.89) },
      { SIMDE_FLOAT64_C(  916.70), SIMDE_FLOAT64_C( -194.98) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -641.49), SIMDE_FLOAT64_C( -881.69),
                         SIMDE_FLOAT64_C(  627.53), SIMDE_FLOAT64_C(  575.62)),
      { SIMDE_FLOAT64_C(  575.62), SIMDE_FLOAT64_C(  627.53) },
      { SIMDE_FLOAT64_C( -881.69), SIMDE_FLOAT64_C( -641.49) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  518.30), SIMDE_FLOAT64_C( -433.95),
                         SIMDE_FLOAT64_C( -285.84), SIMDE_FLOAT64_C( -221.03)),
      { SIMDE_FLOAT64_C( -221.03), SIMDE_FLOAT64_C( -285.84) },
      { SIMDE_FLOAT64_C( -433.95), SIMDE_FLOAT64_C(  518.30) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -662.71), SIMDE_FLOAT64_C(  122.75),
                         SIMDE_FLOAT64_C( -172.81), SIMDE_FLOAT64_C(  852.48)),
      { SIMDE_FLOAT64_C(  852.48), SIMDE_FLOAT64_C( -172.81) },
      { SIMDE_FLOAT64_C(  122.75), SIMDE_FLOAT64_C( -662.71) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  223.39), SIMDE_FLOAT64_C(   81.02),
                         SIMDE_FLOAT64_C( -389.17), SIMDE_FLOAT64_C( -925.92)),
      { SIMDE_FLOAT64_C( -925.92), SIMDE_FLOAT64_C( -389.17) },
      { SIMDE_FLOAT64_C(   81.02), SIMDE_FLOAT64_C(  223.39) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -179.05), SIMDE_FLOAT64_C( -523.56),
                         SIMDE_FLOAT64_C( -888.14), SIMDE_FLOAT64_C( -890.71)),
      { SIMDE_FLOAT64_C( -890.71), SIMDE_FLOAT64_C( -888.14) },
      { SIMDE_FLOAT64_C( -523.56), SIMDE_FLOAT64_C( -179.05) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  495.30), SIMDE_FLOAT64_C(  776.16),
                         SIMDE_FLOAT64_C(  945.09), SIMDE_FLOAT64_C( -993.27)),
      { SIMDE_FLOAT64_C( -993.27), SIMDE_FLOAT64_C(  945.09) },
      { SIMDE_FLOAT64_C(  776.16), SIMDE_FLOAT64_C(  495.30) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -570.57), SIMDE_FLOAT64_C(  -54.05),
                         SIMDE_FLOAT64_C(   18.98), SIMDE_FLOAT64_C(  273.66)),
      { SIMDE_FLOAT64_C(  273.66), SIMDE_FLOAT64_C(   18.98) },
      { SIMDE_FLOAT64_C(  -54.05), SIMDE_FLOAT64_C( -570.57) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64 lo[2];
    simde_float64 hi[2];
    simde_mm256_storeu2_m128d(hi, lo, test_vec[i].a);
    simde_assert_f32v_equal(simde_float64, sizeof(lo) / sizeof(lo[0]), lo, test_vec[i].lo, 1);
    simde_assert_f32v_equal(simde_float64, sizeof(hi) / sizeof(hi[0]), hi, test_vec[i].hi, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde_float32 lo[4];
    simde_float32 hi[4];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  443.79), SIMDE_FLOAT32_C( -943.66),
                         SIMDE_FLOAT32_C( -617.03), SIMDE_FLOAT32_C(  623.90),
                         SIMDE_FLOAT32_C(  762.13), SIMDE_FLOAT32_C( -191.81),
                         SIMDE_FLOAT32_C( -640.60), SIMDE_FLOAT32_C( -234.64)),
      { SIMDE_FLOAT32_C( -234.64), SIMDE_FLOAT32_C( -640.60),
        SIMDE_FLOAT32_C( -191.81), SIMDE_FLOAT32_C(  762.13) },
      { SIMDE_FLOAT32_C(  623.90), SIMDE_FLOAT32_C( -617.03),
        SIMDE_FLOAT32_C( -943.66), SIMDE_FLOAT32_C(  443.79) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  182.89), SIMDE_FLOAT32_C(  873.05),
                         SIMDE_FLOAT32_C( -272.49), SIMDE_FLOAT32_C(  736.89),
                         SIMDE_FLOAT32_C(  847.09), SIMDE_FLOAT32_C( -558.86),
                         SIMDE_FLOAT32_C(  408.24), SIMDE_FLOAT32_C(  859.69)),
      { SIMDE_FLOAT32_C(  859.69), SIMDE_FLOAT32_C(  408.24),
        SIMDE_FLOAT32_C( -558.86), SIMDE_FLOAT32_C(  847.09) },
      { SIMDE_FLOAT32_C(  736.89), SIMDE_FLOAT32_C( -272.49),
        SIMDE_FLOAT32_C(  873.05), SIMDE_FLOAT32_C(  182.89) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -136.90), SIMDE_FLOAT32_C(  907.77),
                         SIMDE_FLOAT32_C(  406.39), SIMDE_FLOAT32_C( -278.95),
                         SIMDE_FLOAT32_C( -644.43), SIMDE_FLOAT32_C( -382.39),
                         SIMDE_FLOAT32_C( -628.10), SIMDE_FLOAT32_C(  477.81)),
      { SIMDE_FLOAT32_C(  477.81), SIMDE_FLOAT32_C( -628.10),
        SIMDE_FLOAT32_C( -382.39), SIMDE_FLOAT32_C( -644.43) },
      { SIMDE_FLOAT32_C( -278.95), SIMDE_FLOAT32_C(  406.39),
        SIMDE_FLOAT32_C(  907.77), SIMDE_FLOAT32_C( -136.90) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -403.18), SIMDE_FLOAT32_C( -297.11),
                         SIMDE_FLOAT32_C( -839.59), SIMDE_FLOAT32_C(  925.44),
                         SIMDE_FLOAT32_C(   -4.12), SIMDE_FLOAT32_C(  223.77),
                         SIMDE_FLOAT32_C(  124.27), SIMDE_FLOAT32_C( -589.05)),
      { SIMDE_FLOAT32_C( -589.05), SIMDE_FLOAT32_C(  124.27),
        SIMDE_FLOAT32_C(  223.77), SIMDE_FLOAT32_C(   -4.12) },
      { SIMDE_FLOAT32_C(  925.44), SIMDE_FLOAT32_C( -839.59),
        SIMDE_FLOAT32_C( -297.11), SIMDE_FLOAT32_C( -403.18) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  375.51), SIMDE_FLOAT32_C(  712.93),
                         SIMDE_FLOAT32_C(  259.42), SIMDE_FLOAT32_C(  -11.11),
                         SIMDE_FLOAT32_C( -941.70), SIMDE_FLOAT32_C(  747.97),
                         SIMDE_FLOAT32_C( -604.59), SIMDE_FLOAT32_C(  959.68)),
      { SIMDE_FLOAT32_C(  959.68), SIMDE_FLOAT32_C( -604.59),
        SIMDE_FLOAT32_C(  747.97), SIMDE_FLOAT32_C( -941.70) },
      { SIMDE_FLOAT32_C(  -11.11), SIMDE_FLOAT32_C(  259.42),
        SIMDE_FLOAT32_C(  712.93), SIMDE_FLOAT32_C(  375.51) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  836.60), SIMDE_FLOAT32_C(  294.15),
                         SIMDE_FLOAT32_C( -609.69), SIMDE_FLOAT32_C( -302.95),
                         SIMDE_FLOAT32_C(   53.57), SIMDE_FLOAT32_C(  -19.22),
                         SIMDE_FLOAT32_C( -957.62), SIMDE_FLOAT32_C(  661.17)),
      { SIMDE_FLOAT32_C(  661.17), SIMDE_FLOAT32_C( -957.62),
        SIMDE_FLOAT32_C(  -19.22), SIMDE_FLOAT32_C(   53.57) },
      { SIMDE_FLOAT32_C( -302.95), SIMDE_FLOAT32_C( -609.69),
        SIMDE_FLOAT32_C(  294.15), SIMDE_FLOAT32_C(  836.60) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -436.80), SIMDE_FLOAT32_C( -424.39),
                         SIMDE_FLOAT32_C(  570.24), SIMDE_FLOAT32_C( -821.65),
                         SIMDE_FLOAT32_C( -881.33), SIMDE_FLOAT32_C( -593.81),
                         SIMDE_FLOAT32_C( -486.59), SIMDE_FLOAT32_C(  962.05)),
      { SIMDE_FLOAT32_C(  962.05), SIMDE_FLOAT32_C( -486.59),
        SIMDE_FLOAT32_C( -593.81), SIMDE_FLOAT32_C( -881.33) },
      { SIMDE_FLOAT32_C( -821.65), SIMDE_FLOAT32_C(  570.24),
        SIMDE_FLOAT32_C( -424.39), SIMDE_FLOAT32_C( -436.80) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -876.51), SIMDE_FLOAT32_C(  339.14),
                         SIMDE_FLOAT32_C(  805.13), SIMDE_FLOAT32_C(  -98.57),
                         SIMDE_FLOAT32_C(  486.75), SIMDE_FLOAT32_C( -826.76),
                         SIMDE_FLOAT32_C( -802.86), SIMDE_FLOAT32_C(  864.61)),
      { SIMDE_FLOAT32_C(  864.61), SIMDE_FLOAT32_C( -802.86),
        SIMDE_FLOAT32_C( -826.76), SIMDE_FLOAT32_C(  486.75) },
      { SIMDE_FLOAT32_C(  -98.57), SIMDE_FLOAT32_C(  805.13),
        SIMDE_FLOAT32_C(  339.14), SIMDE_FLOAT32_C( -876.51) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32 lo[4];
    simde_float32 hi[4];
    simde_mm256_storeu2_m128(hi, lo, test_vec[i].a);
    simde_assert_f32v_close(simde_float32, 4, lo, test_vec[i].lo, 1);
    simde_assert_f32v_close(simde_float32, 4, hi, test_vec[i].hi, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_storeu2_m128i(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m128i lo;
    simde__m128i hi;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C(  393618896), INT32_C(-2001591323), INT32_C(  571243540), INT32_C( -991131551),
                            INT32_C(-1628428871), INT32_C(-1785170070), INT32_C(-1344585991), INT32_C(  394549136)),
      simde_mm_set_epi32(INT32_C(-1628428871), INT32_C(-1785170070), INT32_C(-1344585991), INT32_C(  394549136)),
      simde_mm_set_epi32(INT32_C(  393618896), INT32_C(-2001591323), INT32_C(  571243540), INT32_C( -991131551)) },
    { simde_mm256_set_epi32(INT32_C(-1934140687), INT32_C(-1810421284), INT32_C( 1425686798), INT32_C( -866335309),
                            INT32_C(  -95249521), INT32_C( 1994067869), INT32_C( -221558182), INT32_C(-1252244061)),
      simde_mm_set_epi32(INT32_C(  -95249521), INT32_C( 1994067869), INT32_C( -221558182), INT32_C(-1252244061)),
      simde_mm_set_epi32(INT32_C(-1934140687), INT32_C(-1810421284), INT32_C( 1425686798), INT32_C( -866335309)) },
    { simde_mm256_set_epi32(INT32_C( -246697484), INT32_C(-1956819884), INT32_C(-1699719942), INT32_C( -979363348),
                            INT32_C( -887855577), INT32_C(-1489598373), INT32_C(  -35728240), INT32_C(-1964323946)),
      simde_mm_set_epi32(INT32_C( -887855577), INT32_C(-1489598373), INT32_C(  -35728240), INT32_C(-1964323946)),
      simde_mm_set_epi32(INT32_C( -246697484), INT32_C(-1956819884), INT32_C(-1699719942), INT32_C( -979363348)) },
    { simde_mm256_set_epi32(INT32_C( 1386381884), INT32_C(   37784267), INT32_C(-1684378143), INT32_C( -594239665),
                            INT32_C( 1400213774), INT32_C( -622529784), INT32_C(  401959227), INT32_C(  971273192)),
      simde_mm_set_epi32(INT32_C( 1400213774), INT32_C( -622529784), INT32_C(  401959227), INT32_C(  971273192)),
      simde_mm_set_epi32(INT32_C( 1386381884), INT32_C(   37784267), INT32_C(-1684378143), INT32_C( -594239665)) },
    { simde_mm256_set_epi32(INT32_C(-1612998305), INT32_C( 1288430921), INT32_C(-1609225142), INT32_C( -537331182),
                            INT32_C(-1310393347), INT32_C(-1547450104), INT32_C( 1731121387), INT32_C( 1158176208)),
      simde_mm_set_epi32(INT32_C(-1310393347), INT32_C(-1547450104), INT32_C( 1731121387), INT32_C( 1158176208)),
      simde_mm_set_epi32(INT32_C(-1612998305), INT32_C( 1288430921), INT32_C(-1609225142), INT32_C( -537331182)) },
    { simde_mm256_set_epi32(INT32_C(  853720407), INT32_C( 1963572434), INT32_C(-1461958617), INT32_C(    -948574),
                            INT32_C(  440127588), INT32_C( -575649939), INT32_C( -647922801), INT32_C( 1292269475)),
      simde_mm_set_epi32(INT32_C(  440127588), INT32_C( -575649939), INT32_C( -647922801), INT32_C( 1292269475)),
      simde_mm_set_epi32(INT32_C(  853720407), INT32_C( 1963572434), INT32_C(-1461958617), INT32_C(    -948574)) },
    { simde_mm256_set_epi32(INT32_C( 1035304658), INT32_C(-1477195307), INT32_C( 1255581892), INT32_C( -187826179),
                            INT32_C( -553614821), INT32_C(-1529210253), INT32_C(  524369675), INT32_C(-1409815299)),
      simde_mm_set_epi32(INT32_C( -553614821), INT32_C(-1529210253), INT32_C(  524369675), INT32_C(-1409815299)),
      simde_mm_set_epi32(INT32_C( 1035304658), INT32_C(-1477195307), INT32_C( 1255581892), INT32_C( -187826179)) },
    { simde_mm256_set_epi32(INT32_C(-1147733206), INT32_C(-1982126005), INT32_C( 1233979928), INT32_C(-1413154458),
                            INT32_C(   36276938), INT32_C(  -66222229), INT32_C(-1746900300), INT32_C(  533326126)),
      simde_mm_set_epi32(INT32_C(   36276938), INT32_C(  -66222229), INT32_C(-1746900300), INT32_C(  533326126)),
      simde_mm_set_epi32(INT32_C(-1147733206), INT32_C(-1982126005), INT32_C( 1233979928), INT32_C(-1413154458)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m128i lo, hi;
    simde_mm256_storeu2_m128i(&hi, &lo, test_vec[i].a);
    simde_assert_m128i_i32(lo, ==, test_vec[i].lo);
    simde_assert_m128i_i32(hi, ==, test_vec[i].hi);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    SIMDE_ALIGN(32) simde_float32 r[8];
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  256.09), SIMDE_FLOAT32_C(  768.79),
                         SIMDE_FLOAT32_C(  201.90), SIMDE_FLOAT32_C(  339.33),
                         SIMDE_FLOAT32_C(  957.46), SIMDE_FLOAT32_C(  728.44),
                         SIMDE_FLOAT32_C(   73.67), SIMDE_FLOAT32_C(  440.11)),
      { SIMDE_FLOAT32_C(  440.11), SIMDE_FLOAT32_C(   73.67),
        SIMDE_FLOAT32_C(  728.44), SIMDE_FLOAT32_C(  957.46),
        SIMDE_FLOAT32_C(  339.33), SIMDE_FLOAT32_C(  201.90),
        SIMDE_FLOAT32_C(  768.79), SIMDE_FLOAT32_C(  256.09) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -72.04), SIMDE_FLOAT32_C( -425.25),
                         SIMDE_FLOAT32_C(  471.77), SIMDE_FLOAT32_C(  976.75),
                         SIMDE_FLOAT32_C( -510.20), SIMDE_FLOAT32_C(  696.54),
                         SIMDE_FLOAT32_C( -843.54), SIMDE_FLOAT32_C( -868.41)),
      { SIMDE_FLOAT32_C( -868.41), SIMDE_FLOAT32_C( -843.54),
        SIMDE_FLOAT32_C(  696.54), SIMDE_FLOAT32_C( -510.20),
        SIMDE_FLOAT32_C(  976.75), SIMDE_FLOAT32_C(  471.77),
        SIMDE_FLOAT32_C( -425.25), SIMDE_FLOAT32_C(  -72.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -304.23), SIMDE_FLOAT32_C(  477.48),
                         SIMDE_FLOAT32_C(  356.58), SIMDE_FLOAT32_C(  955.81),
                         SIMDE_FLOAT32_C(  999.99), SIMDE_FLOAT32_C(  487.33),
                         SIMDE_FLOAT32_C(  633.61), SIMDE_FLOAT32_C(  518.11)),
      { SIMDE_FLOAT32_C(  518.11), SIMDE_FLOAT32_C(  633.61),
        SIMDE_FLOAT32_C(  487.33), SIMDE_FLOAT32_C(  999.99),
        SIMDE_FLOAT32_C(  955.81), SIMDE_FLOAT32_C(  356.58),
        SIMDE_FLOAT32_C(  477.48), SIMDE_FLOAT32_C( -304.23) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   88.04), SIMDE_FLOAT32_C( -296.25),
                         SIMDE_FLOAT32_C(  948.33), SIMDE_FLOAT32_C( -584.17),
                         SIMDE_FLOAT32_C( -796.11), SIMDE_FLOAT32_C(  -38.84),
                         SIMDE_FLOAT32_C( -706.11), SIMDE_FLOAT32_C(  347.32)),
      { SIMDE_FLOAT32_C(  347.32), SIMDE_FLOAT32_C( -706.11),
        SIMDE_FLOAT32_C(  -38.84), SIMDE_FLOAT32_C( -796.11),
        SIMDE_FLOAT32_C( -584.17), SIMDE_FLOAT32_C(  948.33),
        SIMDE_FLOAT32_C( -296.25), SIMDE_FLOAT32_C(   88.04) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -143.76), SIMDE_FLOAT32_C(  504.36),
                         SIMDE_FLOAT32_C( -154.12), SIMDE_FLOAT32_C(  375.43),
                         SIMDE_FLOAT32_C( -307.18), SIMDE_FLOAT32_C(  256.93),
                         SIMDE_FLOAT32_C(   78.86), SIMDE_FLOAT32_C(  526.77)),
      { SIMDE_FLOAT32_C(  526.77), SIMDE_FLOAT32_C(   78.86),
        SIMDE_FLOAT32_C(  256.93), SIMDE_FLOAT32_C( -307.18),
        SIMDE_FLOAT32_C(  375.43), SIMDE_FLOAT32_C( -154.12),
        SIMDE_FLOAT32_C(  504.36), SIMDE_FLOAT32_C( -143.76) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  597.82), SIMDE_FLOAT32_C(  697.68),
                         SIMDE_FLOAT32_C( -285.13), SIMDE_FLOAT32_C(  354.51),
                         SIMDE_FLOAT32_C(   41.32), SIMDE_FLOAT32_C( -445.78),
                         SIMDE_FLOAT32_C( -483.17), SIMDE_FLOAT32_C( -727.28)),
      { SIMDE_FLOAT32_C( -727.28), SIMDE_FLOAT32_C( -483.17),
        SIMDE_FLOAT32_C( -445.78), SIMDE_FLOAT32_C(   41.32),
        SIMDE_FLOAT32_C(  354.51), SIMDE_FLOAT32_C( -285.13),
        SIMDE_FLOAT32_C(  697.68), SIMDE_FLOAT32_C(  597.82) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -441.93), SIMDE_FLOAT32_C( -382.04),
                         SIMDE_FLOAT32_C(  392.67), SIMDE_FLOAT32_C(  690.10),
                         SIMDE_FLOAT32_C(  -30.26), SIMDE_FLOAT32_C( -968.87),
                         SIMDE_FLOAT32_C( -246.46), SIMDE_FLOAT32_C(  625.73)),
      { SIMDE_FLOAT32_C(  625.73), SIMDE_FLOAT32_C( -246.46),
        SIMDE_FLOAT32_C( -968.87), SIMDE_FLOAT32_C(  -30.26),
        SIMDE_FLOAT32_C(  690.10), SIMDE_FLOAT32_C(  392.67),
        SIMDE_FLOAT32_C( -382.04), SIMDE_FLOAT32_C( -441.93) } },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  442.97), SIMDE_FLOAT32_C(  -20.37),
                         SIMDE_FLOAT32_C(  758.01), SIMDE_FLOAT32_C( -507.47),
                         SIMDE_FLOAT32_C(  529.68), SIMDE_FLOAT32_C( -598.71),
                         SIMDE_FLOAT32_C(  952.31), SIMDE_FLOAT32_C( -565.36)),
      { SIMDE_FLOAT32_C( -565.36), SIMDE_FLOAT32_C(  952.31),
        SIMDE_FLOAT32_C( -598.71), SIMDE_FLOAT32_C(  529.68),
        SIMDE_FLOAT32_C( -507.47), SIMDE_FLOAT32_C(  758.01),
        SIMDE_FLOAT32_C(  -20.37), SIMDE_FLOAT32_C(  442.97) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float32 r[8];
    simde_mm256_stream_ps(r, test_vec[i].a);
    simde_assert_f32v_close(simde_float32, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    SIMDE_ALIGN(32) simde_float64 r[4];
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  771.84), SIMDE_FLOAT64_C(  578.19),
                         SIMDE_FLOAT64_C(  287.63), SIMDE_FLOAT64_C(  196.16)),
      { SIMDE_FLOAT64_C(  196.16), SIMDE_FLOAT64_C(  287.63),
        SIMDE_FLOAT64_C(  578.19), SIMDE_FLOAT64_C(  771.84) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -941.73), SIMDE_FLOAT64_C( -687.45),
                         SIMDE_FLOAT64_C( -865.09), SIMDE_FLOAT64_C(  586.03)),
      { SIMDE_FLOAT64_C(  586.03), SIMDE_FLOAT64_C( -865.09),
        SIMDE_FLOAT64_C( -687.45), SIMDE_FLOAT64_C( -941.73) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -342.90), SIMDE_FLOAT64_C( -658.61),
                         SIMDE_FLOAT64_C(  882.05), SIMDE_FLOAT64_C( -607.89)),
      { SIMDE_FLOAT64_C( -607.89), SIMDE_FLOAT64_C(  882.05),
        SIMDE_FLOAT64_C( -658.61), SIMDE_FLOAT64_C( -342.90) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -248.91), SIMDE_FLOAT64_C( -473.20),
                         SIMDE_FLOAT64_C(  170.76), SIMDE_FLOAT64_C( -407.02)),
      { SIMDE_FLOAT64_C( -407.02), SIMDE_FLOAT64_C(  170.76),
        SIMDE_FLOAT64_C( -473.20), SIMDE_FLOAT64_C( -248.91) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  181.69), SIMDE_FLOAT64_C(  697.67),
                         SIMDE_FLOAT64_C(  911.25), SIMDE_FLOAT64_C( -299.04)),
      { SIMDE_FLOAT64_C( -299.04), SIMDE_FLOAT64_C(  911.25),
        SIMDE_FLOAT64_C(  697.67), SIMDE_FLOAT64_C(  181.69) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -630.92), SIMDE_FLOAT64_C( -612.42),
                         SIMDE_FLOAT64_C(  645.34), SIMDE_FLOAT64_C( -379.90)),
      { SIMDE_FLOAT64_C( -379.90), SIMDE_FLOAT64_C(  645.34),
        SIMDE_FLOAT64_C( -612.42), SIMDE_FLOAT64_C( -630.92) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -339.32), SIMDE_FLOAT64_C(  404.98),
                         SIMDE_FLOAT64_C( -361.76), SIMDE_FLOAT64_C(  391.60)),
      { SIMDE_FLOAT64_C(  391.60), SIMDE_FLOAT64_C( -361.76),
        SIMDE_FLOAT64_C(  404.98), SIMDE_FLOAT64_C( -339.32) } },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  714.72), SIMDE_FLOAT64_C(  997.58),
                         SIMDE_FLOAT64_C(  807.47), SIMDE_FLOAT64_C(  948.80)),
      { SIMDE_FLOAT64_C(  948.80), SIMDE_FLOAT64_C(  807.47),
        SIMDE_FLOAT64_C(  997.58), SIMDE_FLOAT64_C(  714.72) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    SIMDE_ALIGN(32) simde_float64 r[4];
    simde_mm256_stream_pd(r, test_vec[i].a);
    simde_assert_f64v_close(simde_float64, sizeof(r) / sizeof(r[0]), r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_stream_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)),
      simde_mm256_set_epi32(INT32_C( -495387953), INT32_C( 1389422093), INT32_C( 1549613541), INT32_C( 1621396930),
                            INT32_C(  431885981), INT32_C( -495493978), INT32_C(  957980176), INT32_C( -756622382)) },
    { simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)),
      simde_mm256_set_epi32(INT32_C(-1537563225), INT32_C( -111752931), INT32_C( 2068479386), INT32_C( 2004807479),
                            INT32_C( 2110162316), INT32_C( 1854708769), INT32_C(  -83811592), INT32_C( -892599604)) },
    { simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)),
      simde_mm256_set_epi32(INT32_C( 1682126570), INT32_C(  340006289), INT32_C(  149083722), INT32_C( 1734045351),
                            INT32_C(-1572830580), INT32_C( 1824421914), INT32_C( 1423738129), INT32_C( -492096848)) },
    { simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)),
      simde_mm256_set_epi32(INT32_C(-2079347795), INT32_C( -336455233), INT32_C( -761216501), INT32_C( 1784601451),
                            INT32_C(  386854500), INT32_C(  177253765), INT32_C(  797476379), INT32_C( -848434210)) },
    { simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)),
      simde_mm256_set_epi32(INT32_C(-1024397654), INT32_C(  273228891), INT32_C( -327343542), INT32_C(  941152347),
                            INT32_C(-1943801853), INT32_C( -571606335), INT32_C(-1600503753), INT32_C(    3657489)) },
    { simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)),
      simde_mm256_set_epi32(INT32_C(  392666418), INT32_C(-1141495552), INT32_C(-1265226558), INT32_C( -341769681),
                            INT32_C(  784056885), INT32_C(   -8791049), INT32_C( -255179514), INT32_C( 1505512077)) },
    { simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)),
      simde_mm256_set_epi32(INT32_C(-2051731929), INT32_C( 1367430487), INT32_C( -142986568), INT32_C( 1381573702),
                            INT32_C( -856833247), INT32_C(  665026143), INT32_C( 1196790497), INT32_C( -507260176)) },
    { simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)),
      simde_mm256_set_epi32(INT32_C( -878005657), INT32_C( -546637276), INT32_C(-1056155816), INT32_C(  259320365),
                            INT32_C(-1537222115), INT32_C(  895058753), INT32_C( -970999316), INT32_C(  224281618)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r;
    simde_mm256_stream_si256(&r, test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  895.54), SIMDE_FLOAT32_C( -418.39),
                         SIMDE_FLOAT32_C( -695.61), SIMDE_FLOAT32_C( -703.30),
                         SIMDE_FLOAT32_C( -607.73), SIMDE_FLOAT32_C(  485.65),
                         SIMDE_FLOAT32_C(  755.18), SIMDE_FLOAT32_C(   41.77)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -396.67), SIMDE_FLOAT32_C( -773.83),
                         SIMDE_FLOAT32_C( -672.24), SIMDE_FLOAT32_C(  931.02),
                         SIMDE_FLOAT32_C( -562.65), SIMDE_FLOAT32_C( -945.51),
                         SIMDE_FLOAT32_C(  938.88), SIMDE_FLOAT32_C(  508.62)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( 1292.21), SIMDE_FLOAT32_C(  355.44),
                         SIMDE_FLOAT32_C(  -23.37), SIMDE_FLOAT32_C(-1634.32),
                         SIMDE_FLOAT32_C(  -45.08), SIMDE_FLOAT32_C( 1431.16),
                         SIMDE_FLOAT32_C( -183.70), SIMDE_FLOAT32_C( -466.85)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -470.99), SIMDE_FLOAT32_C( -584.82),
                         SIMDE_FLOAT32_C(  594.88), SIMDE_FLOAT32_C( -970.99),
                         SIMDE_FLOAT32_C(  -61.62), SIMDE_FLOAT32_C(    8.56),
                         SIMDE_FLOAT32_C( -149.02), SIMDE_FLOAT32_C(  992.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -290.52), SIMDE_FLOAT32_C(  724.83),
                         SIMDE_FLOAT32_C(  -46.66), SIMDE_FLOAT32_C( -959.87),
                         SIMDE_FLOAT32_C( -350.83), SIMDE_FLOAT32_C( -742.59),
                         SIMDE_FLOAT32_C( -154.10), SIMDE_FLOAT32_C(  297.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -180.47), SIMDE_FLOAT32_C(-1309.65),
                         SIMDE_FLOAT32_C(  641.54), SIMDE_FLOAT32_C(  -11.12),
                         SIMDE_FLOAT32_C(  289.21), SIMDE_FLOAT32_C(  751.15),
                         SIMDE_FLOAT32_C(    5.08), SIMDE_FLOAT32_C(  695.04)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -970.60), SIMDE_FLOAT32_C(  -80.01),
                         SIMDE_FLOAT32_C(  -52.72), SIMDE_FLOAT32_C(  126.54),
                         SIMDE_FLOAT32_C( -671.14), SIMDE_FLOAT32_C( -767.97),
                         SIMDE_FLOAT32_C( -218.43), SIMDE_FLOAT32_C(  532.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  605.24), SIMDE_FLOAT32_C(  -39.09),
                         SIMDE_FLOAT32_C(  863.80), SIMDE_FLOAT32_C( -150.76),
                         SIMDE_FLOAT32_C( -836.71), SIMDE_FLOAT32_C(  584.17),
                         SIMDE_FLOAT32_C(  207.01), SIMDE_FLOAT32_C(  321.52)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(-1575.84), SIMDE_FLOAT32_C(  -40.92),
                         SIMDE_FLOAT32_C( -916.52), SIMDE_FLOAT32_C(  277.30),
                         SIMDE_FLOAT32_C(  165.57), SIMDE_FLOAT32_C(-1352.14),
                         SIMDE_FLOAT32_C( -425.44), SIMDE_FLOAT32_C(  210.68)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  342.27), SIMDE_FLOAT32_C( -662.10),
                         SIMDE_FLOAT32_C( -934.33), SIMDE_FLOAT32_C( -742.68),
                         SIMDE_FLOAT32_C( -973.49), SIMDE_FLOAT32_C(   11.46),
                         SIMDE_FLOAT32_C(  125.25), SIMDE_FLOAT32_C( -964.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  604.39), SIMDE_FLOAT32_C(  789.04),
                         SIMDE_FLOAT32_C( -177.72), SIMDE_FLOAT32_C(  -86.37),
                         SIMDE_FLOAT32_C( -125.89), SIMDE_FLOAT32_C(  264.15),
                         SIMDE_FLOAT32_C(  690.78), SIMDE_FLOAT32_C(  529.89)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -262.12), SIMDE_FLOAT32_C(-1451.14),
                         SIMDE_FLOAT32_C( -756.61), SIMDE_FLOAT32_C( -656.31),
                         SIMDE_FLOAT32_C( -847.60), SIMDE_FLOAT32_C( -252.69),
                         SIMDE_FLOAT32_C( -565.53), SIMDE_FLOAT32_C(-1494.25)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   25.31), SIMDE_FLOAT32_C(  539.95),
                         SIMDE_FLOAT32_C(  423.13), SIMDE_FLOAT32_C(  781.76),
                         SIMDE_FLOAT32_C(  417.34), SIMDE_FLOAT32_C(  842.38),
                         SIMDE_FLOAT32_C( -253.59), SIMDE_FLOAT32_C( -916.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  772.83), SIMDE_FLOAT32_C(  517.22),
                         SIMDE_FLOAT32_C(  908.12), SIMDE_FLOAT32_C( -320.25),
                         SIMDE_FLOAT32_C(  304.42), SIMDE_FLOAT32_C( -692.34),
                         SIMDE_FLOAT32_C( -714.07), SIMDE_FLOAT32_C( -793.24)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -747.52), SIMDE_FLOAT32_C(   22.73),
                         SIMDE_FLOAT32_C( -484.99), SIMDE_FLOAT32_C( 1102.01),
                         SIMDE_FLOAT32_C(  112.92), SIMDE_FLOAT32_C( 1534.72),
                         SIMDE_FLOAT32_C(  460.48), SIMDE_FLOAT32_C( -123.73)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  393.40), SIMDE_FLOAT32_C( -394.71),
                         SIMDE_FLOAT32_C(  -86.25), SIMDE_FLOAT32_C(  978.22),
                         SIMDE_FLOAT32_C(  983.88), SIMDE_FLOAT32_C(  704.75),
                         SIMDE_FLOAT32_C(  982.77), SIMDE_FLOAT32_C(  368.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -436.22), SIMDE_FLOAT32_C( -898.24),
                         SIMDE_FLOAT32_C( -332.96), SIMDE_FLOAT32_C(  552.30),
                         SIMDE_FLOAT32_C(  889.88), SIMDE_FLOAT32_C( -709.13),
                         SIMDE_FLOAT32_C( -308.74), SIMDE_FLOAT32_C(  240.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  829.62), SIMDE_FLOAT32_C(  503.53),
                         SIMDE_FLOAT32_C(  246.71), SIMDE_FLOAT32_C(  425.92),
                         SIMDE_FLOAT32_C(   94.00), SIMDE_FLOAT32_C( 1413.88),
                         SIMDE_FLOAT32_C( 1291.51), SIMDE_FLOAT32_C(  127.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  338.33), SIMDE_FLOAT32_C(  742.66),
                         SIMDE_FLOAT32_C( -662.36), SIMDE_FLOAT32_C(  193.25),
                         SIMDE_FLOAT32_C( -791.36), SIMDE_FLOAT32_C(  864.59),
                         SIMDE_FLOAT32_C( -234.67), SIMDE_FLOAT32_C( -697.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -154.56), SIMDE_FLOAT32_C(  577.30),
                         SIMDE_FLOAT32_C(  801.65), SIMDE_FLOAT32_C(  520.59),
                         SIMDE_FLOAT32_C( -742.87), SIMDE_FLOAT32_C( -868.99),
                         SIMDE_FLOAT32_C(   16.41), SIMDE_FLOAT32_C(  377.46)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  492.89), SIMDE_FLOAT32_C(  165.36),
                         SIMDE_FLOAT32_C(-1464.01), SIMDE_FLOAT32_C( -327.34),
                         SIMDE_FLOAT32_C(  -48.49), SIMDE_FLOAT32_C( 1733.58),
                         SIMDE_FLOAT32_C( -251.08), SIMDE_FLOAT32_C(-1075.31)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  301.89), SIMDE_FLOAT32_C(  110.31),
                         SIMDE_FLOAT32_C( -669.00), SIMDE_FLOAT32_C( -603.43),
                         SIMDE_FLOAT32_C(  552.74), SIMDE_FLOAT32_C(  111.39),
                         SIMDE_FLOAT32_C(  485.92), SIMDE_FLOAT32_C(   89.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  222.86), SIMDE_FLOAT32_C(  451.25),
                         SIMDE_FLOAT32_C(  422.47), SIMDE_FLOAT32_C( -182.63),
                         SIMDE_FLOAT32_C( -845.87), SIMDE_FLOAT32_C( -863.72),
                         SIMDE_FLOAT32_C( -400.45), SIMDE_FLOAT32_C(  543.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   79.03), SIMDE_FLOAT32_C( -340.94),
                         SIMDE_FLOAT32_C(-1091.47), SIMDE_FLOAT32_C( -420.80),
                         SIMDE_FLOAT32_C( 1398.61), SIMDE_FLOAT32_C(  975.11),
                         SIMDE_FLOAT32_C(  886.37), SIMDE_FLOAT32_C( -454.56)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_sub_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_sub_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.29), SIMDE_FLOAT64_C(  818.19),
                         SIMDE_FLOAT64_C( -310.33), SIMDE_FLOAT64_C( -307.48)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  349.11), SIMDE_FLOAT64_C(  984.47),
                         SIMDE_FLOAT64_C(  184.55), SIMDE_FLOAT64_C(  274.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -821.40), SIMDE_FLOAT64_C( -166.28),
                         SIMDE_FLOAT64_C( -494.88), SIMDE_FLOAT64_C( -581.90)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -992.33), SIMDE_FLOAT64_C( -503.60),
                         SIMDE_FLOAT64_C( -575.41), SIMDE_FLOAT64_C(  497.58)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  203.77), SIMDE_FLOAT64_C( -296.83),
                         SIMDE_FLOAT64_C( -970.76), SIMDE_FLOAT64_C(  837.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1196.10), SIMDE_FLOAT64_C( -206.77),
                         SIMDE_FLOAT64_C(  395.35), SIMDE_FLOAT64_C( -340.39)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  691.42), SIMDE_FLOAT64_C(  124.38),
                         SIMDE_FLOAT64_C( -117.46), SIMDE_FLOAT64_C(  -44.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  865.33), SIMDE_FLOAT64_C( -985.94),
                         SIMDE_FLOAT64_C( -427.40), SIMDE_FLOAT64_C(  247.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -173.91), SIMDE_FLOAT64_C( 1110.32),
                         SIMDE_FLOAT64_C(  309.94), SIMDE_FLOAT64_C( -292.25)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -811.54), SIMDE_FLOAT64_C( -682.27),
                         SIMDE_FLOAT64_C( -138.35), SIMDE_FLOAT64_C(  149.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -356.84), SIMDE_FLOAT64_C( -870.72),
                         SIMDE_FLOAT64_C(  278.05), SIMDE_FLOAT64_C(  725.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -454.70), SIMDE_FLOAT64_C(  188.45),
                         SIMDE_FLOAT64_C( -416.40), SIMDE_FLOAT64_C( -575.71)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -372.68), SIMDE_FLOAT64_C( -973.76),
                         SIMDE_FLOAT64_C( -655.95), SIMDE_FLOAT64_C(  -13.49)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  132.41), SIMDE_FLOAT64_C( -317.72),
                         SIMDE_FLOAT64_C(  685.31), SIMDE_FLOAT64_C( -205.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -505.09), SIMDE_FLOAT64_C( -656.04),
                         SIMDE_FLOAT64_C(-1341.26), SIMDE_FLOAT64_C(  192.41)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -904.59), SIMDE_FLOAT64_C(  450.57),
                         SIMDE_FLOAT64_C(  462.97), SIMDE_FLOAT64_C( -213.02)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  256.78), SIMDE_FLOAT64_C(  248.73),
                         SIMDE_FLOAT64_C( -329.49), SIMDE_FLOAT64_C(  126.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(-1161.37), SIMDE_FLOAT64_C(  201.84),
                         SIMDE_FLOAT64_C(  792.46), SIMDE_FLOAT64_C( -339.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  425.49), SIMDE_FLOAT64_C( -968.50),
                         SIMDE_FLOAT64_C( -130.01), SIMDE_FLOAT64_C(  908.84)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  529.10), SIMDE_FLOAT64_C(   40.66),
                         SIMDE_FLOAT64_C(  677.87), SIMDE_FLOAT64_C( -349.20)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -103.61), SIMDE_FLOAT64_C(-1009.16),
                         SIMDE_FLOAT64_C( -807.88), SIMDE_FLOAT64_C( 1258.04)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  385.72), SIMDE_FLOAT64_C(  135.17),
                         SIMDE_FLOAT64_C( -935.76), SIMDE_FLOAT64_C(  307.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  799.62), SIMDE_FLOAT64_C(  219.20),
                         SIMDE_FLOAT64_C(  812.15), SIMDE_FLOAT64_C(   33.47)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -413.90), SIMDE_FLOAT64_C(  -84.03),
                         SIMDE_FLOAT64_C(-1747.91), SIMDE_FLOAT64_C(  273.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_sub_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_undefined_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256 r;
  simde__m256 e = simde_mm256_setzero_ps();

  r = simde_mm256_undefined_ps();
  r = simde_mm256_xor_ps(r, r);

  simde_assert_m256_close(r, e, 1);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_undefined_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256d r;
  simde__m256d e = simde_mm256_setzero_pd();

  r = simde_mm256_undefined_pd();
  r = simde_mm256_xor_pd(r, r);

  simde_assert_m256d_close(r, e, 1);

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_undefined_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  simde__m256d r;
  simde__m256d e = simde_mm256_setzero_pd();

  r = simde_mm256_undefined_pd();
  r = simde_mm256_xor_pd(r, r);

  simde_assert_m256i_equal(simde_mm256_castpd_si256(r), simde_mm256_castpd_si256(e));
  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpackhi_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  807.72), SIMDE_FLOAT32_C(  100.14),
                         SIMDE_FLOAT32_C(  187.05), SIMDE_FLOAT32_C( -298.31),
                         SIMDE_FLOAT32_C(  -34.37), SIMDE_FLOAT32_C(  964.34),
                         SIMDE_FLOAT32_C(  191.73), SIMDE_FLOAT32_C(  188.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -734.87), SIMDE_FLOAT32_C( -828.29),
                         SIMDE_FLOAT32_C( -280.75), SIMDE_FLOAT32_C(  955.06),
                         SIMDE_FLOAT32_C(  436.60), SIMDE_FLOAT32_C( -584.60),
                         SIMDE_FLOAT32_C(  158.18), SIMDE_FLOAT32_C(   60.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -734.87), SIMDE_FLOAT32_C(  807.72),
                         SIMDE_FLOAT32_C( -828.29), SIMDE_FLOAT32_C(  100.14),
                         SIMDE_FLOAT32_C(  436.60), SIMDE_FLOAT32_C(  -34.37),
                         SIMDE_FLOAT32_C( -584.60), SIMDE_FLOAT32_C(  964.34)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -931.86), SIMDE_FLOAT32_C( -611.79),
                         SIMDE_FLOAT32_C( -274.19), SIMDE_FLOAT32_C( -226.15),
                         SIMDE_FLOAT32_C( -145.52), SIMDE_FLOAT32_C(  128.94),
                         SIMDE_FLOAT32_C( -102.01), SIMDE_FLOAT32_C( -500.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.58), SIMDE_FLOAT32_C( -771.61),
                         SIMDE_FLOAT32_C(  661.02), SIMDE_FLOAT32_C( -824.40),
                         SIMDE_FLOAT32_C(  837.69), SIMDE_FLOAT32_C(   62.03),
                         SIMDE_FLOAT32_C(  350.22), SIMDE_FLOAT32_C(  -94.71)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -438.58), SIMDE_FLOAT32_C( -931.86),
                         SIMDE_FLOAT32_C( -771.61), SIMDE_FLOAT32_C( -611.79),
                         SIMDE_FLOAT32_C(  837.69), SIMDE_FLOAT32_C( -145.52),
                         SIMDE_FLOAT32_C(   62.03), SIMDE_FLOAT32_C(  128.94)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -514.10), SIMDE_FLOAT32_C(  798.26),
                         SIMDE_FLOAT32_C(  453.29), SIMDE_FLOAT32_C( -723.59),
                         SIMDE_FLOAT32_C(  488.64), SIMDE_FLOAT32_C( -551.49),
                         SIMDE_FLOAT32_C( -160.63), SIMDE_FLOAT32_C(   78.66)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  525.47), SIMDE_FLOAT32_C( -613.64),
                         SIMDE_FLOAT32_C(  666.94), SIMDE_FLOAT32_C( -806.63),
                         SIMDE_FLOAT32_C(  409.97), SIMDE_FLOAT32_C(  221.24),
                         SIMDE_FLOAT32_C(  721.07), SIMDE_FLOAT32_C( -434.84)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  525.47), SIMDE_FLOAT32_C( -514.10),
                         SIMDE_FLOAT32_C( -613.64), SIMDE_FLOAT32_C(  798.26),
                         SIMDE_FLOAT32_C(  409.97), SIMDE_FLOAT32_C(  488.64),
                         SIMDE_FLOAT32_C(  221.24), SIMDE_FLOAT32_C( -551.49)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -951.19), SIMDE_FLOAT32_C(  -28.42),
                         SIMDE_FLOAT32_C(  106.10), SIMDE_FLOAT32_C( -926.30),
                         SIMDE_FLOAT32_C( -891.33), SIMDE_FLOAT32_C( -910.68),
                         SIMDE_FLOAT32_C(  859.23), SIMDE_FLOAT32_C( -534.18)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -774.25), SIMDE_FLOAT32_C( -509.69),
                         SIMDE_FLOAT32_C( -863.30), SIMDE_FLOAT32_C( -245.43),
                         SIMDE_FLOAT32_C( -949.52), SIMDE_FLOAT32_C( -135.53),
                         SIMDE_FLOAT32_C(  390.61), SIMDE_FLOAT32_C( -616.91)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -774.25), SIMDE_FLOAT32_C( -951.19),
                         SIMDE_FLOAT32_C( -509.69), SIMDE_FLOAT32_C(  -28.42),
                         SIMDE_FLOAT32_C( -949.52), SIMDE_FLOAT32_C( -891.33),
                         SIMDE_FLOAT32_C( -135.53), SIMDE_FLOAT32_C( -910.68)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  854.52), SIMDE_FLOAT32_C( -781.40),
                         SIMDE_FLOAT32_C(  848.96), SIMDE_FLOAT32_C(  755.16),
                         SIMDE_FLOAT32_C(  991.03), SIMDE_FLOAT32_C( -213.85),
                         SIMDE_FLOAT32_C(  907.55), SIMDE_FLOAT32_C( -711.16)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.01), SIMDE_FLOAT32_C( -206.18),
                         SIMDE_FLOAT32_C( -786.69), SIMDE_FLOAT32_C(  940.75),
                         SIMDE_FLOAT32_C( -664.64), SIMDE_FLOAT32_C( -614.97),
                         SIMDE_FLOAT32_C(  524.63), SIMDE_FLOAT32_C(  291.78)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.01), SIMDE_FLOAT32_C(  854.52),
                         SIMDE_FLOAT32_C( -206.18), SIMDE_FLOAT32_C( -781.40),
                         SIMDE_FLOAT32_C( -664.64), SIMDE_FLOAT32_C(  991.03),
                         SIMDE_FLOAT32_C( -614.97), SIMDE_FLOAT32_C( -213.85)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -51.56), SIMDE_FLOAT32_C(  716.82),
                         SIMDE_FLOAT32_C(  820.37), SIMDE_FLOAT32_C( -556.55),
                         SIMDE_FLOAT32_C( -748.23), SIMDE_FLOAT32_C( -191.87),
                         SIMDE_FLOAT32_C(  886.02), SIMDE_FLOAT32_C( -964.97)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.40), SIMDE_FLOAT32_C( -388.17),
                         SIMDE_FLOAT32_C(  620.64), SIMDE_FLOAT32_C(  768.35),
                         SIMDE_FLOAT32_C( -196.91), SIMDE_FLOAT32_C( -771.49),
                         SIMDE_FLOAT32_C( -618.58), SIMDE_FLOAT32_C( -887.04)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  942.40), SIMDE_FLOAT32_C(  -51.56),
                         SIMDE_FLOAT32_C( -388.17), SIMDE_FLOAT32_C(  716.82),
                         SIMDE_FLOAT32_C( -196.91), SIMDE_FLOAT32_C( -748.23),
                         SIMDE_FLOAT32_C( -771.49), SIMDE_FLOAT32_C( -191.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  934.86), SIMDE_FLOAT32_C( -147.82),
                         SIMDE_FLOAT32_C(  984.99), SIMDE_FLOAT32_C(  944.15),
                         SIMDE_FLOAT32_C(  882.67), SIMDE_FLOAT32_C(  370.21),
                         SIMDE_FLOAT32_C(  981.44), SIMDE_FLOAT32_C( -856.37)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.89), SIMDE_FLOAT32_C(  -20.18),
                         SIMDE_FLOAT32_C( -561.60), SIMDE_FLOAT32_C(  599.04),
                         SIMDE_FLOAT32_C( -556.62), SIMDE_FLOAT32_C( -514.91),
                         SIMDE_FLOAT32_C( -240.53), SIMDE_FLOAT32_C( -421.29)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   80.89), SIMDE_FLOAT32_C(  934.86),
                         SIMDE_FLOAT32_C(  -20.18), SIMDE_FLOAT32_C( -147.82),
                         SIMDE_FLOAT32_C( -556.62), SIMDE_FLOAT32_C(  882.67),
                         SIMDE_FLOAT32_C( -514.91), SIMDE_FLOAT32_C(  370.21)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -445.93), SIMDE_FLOAT32_C(  998.84),
                         SIMDE_FLOAT32_C( -975.41), SIMDE_FLOAT32_C(  762.47),
                         SIMDE_FLOAT32_C(  829.30), SIMDE_FLOAT32_C( -324.70),
                         SIMDE_FLOAT32_C(  745.09), SIMDE_FLOAT32_C(   12.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  177.17), SIMDE_FLOAT32_C(  871.02),
                         SIMDE_FLOAT32_C(  263.38), SIMDE_FLOAT32_C( -284.12),
                         SIMDE_FLOAT32_C( -407.86), SIMDE_FLOAT32_C( -554.15),
                         SIMDE_FLOAT32_C(   -7.26), SIMDE_FLOAT32_C( -655.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  177.17), SIMDE_FLOAT32_C( -445.93),
                         SIMDE_FLOAT32_C(  871.02), SIMDE_FLOAT32_C(  998.84),
                         SIMDE_FLOAT32_C( -407.86), SIMDE_FLOAT32_C(  829.30),
                         SIMDE_FLOAT32_C( -554.15), SIMDE_FLOAT32_C( -324.70)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_unpackhi_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpackhi_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  474.20), SIMDE_FLOAT64_C(  -84.92),
                         SIMDE_FLOAT64_C(  521.98), SIMDE_FLOAT64_C( -506.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  547.06), SIMDE_FLOAT64_C( -105.08),
                         SIMDE_FLOAT64_C(  810.31), SIMDE_FLOAT64_C(  175.50)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  547.06), SIMDE_FLOAT64_C(  474.20),
                         SIMDE_FLOAT64_C(  810.31), SIMDE_FLOAT64_C(  521.98)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -738.63), SIMDE_FLOAT64_C( -207.02),
                         SIMDE_FLOAT64_C(  624.23), SIMDE_FLOAT64_C( -787.13)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -734.37), SIMDE_FLOAT64_C(   16.93),
                         SIMDE_FLOAT64_C( -235.12), SIMDE_FLOAT64_C(  261.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -734.37), SIMDE_FLOAT64_C( -738.63),
                         SIMDE_FLOAT64_C( -235.12), SIMDE_FLOAT64_C(  624.23)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  713.19), SIMDE_FLOAT64_C(  906.18),
                         SIMDE_FLOAT64_C( -969.47), SIMDE_FLOAT64_C( -953.69)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  182.58), SIMDE_FLOAT64_C(  575.97),
                         SIMDE_FLOAT64_C(  870.00), SIMDE_FLOAT64_C(  681.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  182.58), SIMDE_FLOAT64_C(  713.19),
                         SIMDE_FLOAT64_C(  870.00), SIMDE_FLOAT64_C( -969.47)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -478.99), SIMDE_FLOAT64_C( -198.61),
                         SIMDE_FLOAT64_C( -506.78), SIMDE_FLOAT64_C( -744.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -105.58), SIMDE_FLOAT64_C( -594.58),
                         SIMDE_FLOAT64_C( -326.65), SIMDE_FLOAT64_C(  744.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -105.58), SIMDE_FLOAT64_C( -478.99),
                         SIMDE_FLOAT64_C( -326.65), SIMDE_FLOAT64_C( -506.78)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  456.60), SIMDE_FLOAT64_C( -346.15),
                         SIMDE_FLOAT64_C(  230.97), SIMDE_FLOAT64_C(  246.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.16), SIMDE_FLOAT64_C(  675.27),
                         SIMDE_FLOAT64_C( -175.34), SIMDE_FLOAT64_C( -350.18)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -895.16), SIMDE_FLOAT64_C(  456.60),
                         SIMDE_FLOAT64_C( -175.34), SIMDE_FLOAT64_C(  230.97)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  517.62), SIMDE_FLOAT64_C( -985.29),
                         SIMDE_FLOAT64_C( -720.18), SIMDE_FLOAT64_C(   52.87)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  519.19), SIMDE_FLOAT64_C(  -56.82),
                         SIMDE_FLOAT64_C(  611.63), SIMDE_FLOAT64_C(  463.94)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  519.19), SIMDE_FLOAT64_C(  517.62),
                         SIMDE_FLOAT64_C(  611.63), SIMDE_FLOAT64_C( -720.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -839.87), SIMDE_FLOAT64_C(  -23.85),
                         SIMDE_FLOAT64_C(  777.18), SIMDE_FLOAT64_C(  867.39)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.42), SIMDE_FLOAT64_C(  503.57),
                         SIMDE_FLOAT64_C(  891.19), SIMDE_FLOAT64_C(  137.98)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -606.42), SIMDE_FLOAT64_C( -839.87),
                         SIMDE_FLOAT64_C(  891.19), SIMDE_FLOAT64_C(  777.18)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -362.78), SIMDE_FLOAT64_C( -942.23),
                         SIMDE_FLOAT64_C(  577.23), SIMDE_FLOAT64_C(  747.66)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.53), SIMDE_FLOAT64_C(  145.74),
                         SIMDE_FLOAT64_C(  948.38), SIMDE_FLOAT64_C( -772.85)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -987.53), SIMDE_FLOAT64_C( -362.78),
                         SIMDE_FLOAT64_C(  948.38), SIMDE_FLOAT64_C(  577.23)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_unpackhi_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpacklo_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  476.45), SIMDE_FLOAT32_C(  703.11),
                         SIMDE_FLOAT32_C(  221.80), SIMDE_FLOAT32_C( -361.45),
                         SIMDE_FLOAT32_C(  645.73), SIMDE_FLOAT32_C(  420.76),
                         SIMDE_FLOAT32_C(  -23.12), SIMDE_FLOAT32_C(   96.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -773.95), SIMDE_FLOAT32_C(  586.39),
                         SIMDE_FLOAT32_C(  118.66), SIMDE_FLOAT32_C(    5.14),
                         SIMDE_FLOAT32_C(    9.63), SIMDE_FLOAT32_C(  896.46),
                         SIMDE_FLOAT32_C(  121.67), SIMDE_FLOAT32_C( -134.20)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  118.66), SIMDE_FLOAT32_C(  221.80),
                         SIMDE_FLOAT32_C(    5.14), SIMDE_FLOAT32_C( -361.45),
                         SIMDE_FLOAT32_C(  121.67), SIMDE_FLOAT32_C(  -23.12),
                         SIMDE_FLOAT32_C( -134.20), SIMDE_FLOAT32_C(   96.33)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -605.12), SIMDE_FLOAT32_C(  481.83),
                         SIMDE_FLOAT32_C(  757.82), SIMDE_FLOAT32_C( -782.53),
                         SIMDE_FLOAT32_C(  546.60), SIMDE_FLOAT32_C( -405.06),
                         SIMDE_FLOAT32_C( -413.20), SIMDE_FLOAT32_C( -645.12)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -646.85), SIMDE_FLOAT32_C( -619.64),
                         SIMDE_FLOAT32_C(    4.92), SIMDE_FLOAT32_C(  816.93),
                         SIMDE_FLOAT32_C( -509.30), SIMDE_FLOAT32_C(  435.06),
                         SIMDE_FLOAT32_C(  -11.96), SIMDE_FLOAT32_C( -147.23)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    4.92), SIMDE_FLOAT32_C(  757.82),
                         SIMDE_FLOAT32_C(  816.93), SIMDE_FLOAT32_C( -782.53),
                         SIMDE_FLOAT32_C(  -11.96), SIMDE_FLOAT32_C( -413.20),
                         SIMDE_FLOAT32_C( -147.23), SIMDE_FLOAT32_C( -645.12)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  850.74), SIMDE_FLOAT32_C(  -85.68),
                         SIMDE_FLOAT32_C( -210.45), SIMDE_FLOAT32_C(  -73.45),
                         SIMDE_FLOAT32_C(  532.06), SIMDE_FLOAT32_C(  709.20),
                         SIMDE_FLOAT32_C(  882.78), SIMDE_FLOAT32_C( -768.32)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -922.57), SIMDE_FLOAT32_C(   42.72),
                         SIMDE_FLOAT32_C(  514.25), SIMDE_FLOAT32_C( -144.83),
                         SIMDE_FLOAT32_C(  -74.58), SIMDE_FLOAT32_C( -573.39),
                         SIMDE_FLOAT32_C( -176.90), SIMDE_FLOAT32_C( -171.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  514.25), SIMDE_FLOAT32_C( -210.45),
                         SIMDE_FLOAT32_C( -144.83), SIMDE_FLOAT32_C(  -73.45),
                         SIMDE_FLOAT32_C( -176.90), SIMDE_FLOAT32_C(  882.78),
                         SIMDE_FLOAT32_C( -171.10), SIMDE_FLOAT32_C( -768.32)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -573.82), SIMDE_FLOAT32_C(  486.51),
                         SIMDE_FLOAT32_C(  332.79), SIMDE_FLOAT32_C( -446.48),
                         SIMDE_FLOAT32_C(  110.94), SIMDE_FLOAT32_C(  515.10),
                         SIMDE_FLOAT32_C(  513.81), SIMDE_FLOAT32_C( -806.87)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  206.71), SIMDE_FLOAT32_C( -250.67),
                         SIMDE_FLOAT32_C(  127.20), SIMDE_FLOAT32_C(  -93.11),
                         SIMDE_FLOAT32_C( -774.94), SIMDE_FLOAT32_C( -230.88),
                         SIMDE_FLOAT32_C(  631.35), SIMDE_FLOAT32_C(  231.15)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  127.20), SIMDE_FLOAT32_C(  332.79),
                         SIMDE_FLOAT32_C(  -93.11), SIMDE_FLOAT32_C( -446.48),
                         SIMDE_FLOAT32_C(  631.35), SIMDE_FLOAT32_C(  513.81),
                         SIMDE_FLOAT32_C(  231.15), SIMDE_FLOAT32_C( -806.87)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  149.45), SIMDE_FLOAT32_C(  726.97),
                         SIMDE_FLOAT32_C(  -55.39), SIMDE_FLOAT32_C(  -82.15),
                         SIMDE_FLOAT32_C(  549.77), SIMDE_FLOAT32_C(  954.11),
                         SIMDE_FLOAT32_C(  -93.98), SIMDE_FLOAT32_C( -820.28)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  456.52), SIMDE_FLOAT32_C( -978.21),
                         SIMDE_FLOAT32_C(  560.56), SIMDE_FLOAT32_C(  178.87),
                         SIMDE_FLOAT32_C(  916.04), SIMDE_FLOAT32_C( -801.57),
                         SIMDE_FLOAT32_C( -369.99), SIMDE_FLOAT32_C(   24.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  560.56), SIMDE_FLOAT32_C(  -55.39),
                         SIMDE_FLOAT32_C(  178.87), SIMDE_FLOAT32_C(  -82.15),
                         SIMDE_FLOAT32_C( -369.99), SIMDE_FLOAT32_C(  -93.98),
                         SIMDE_FLOAT32_C(   24.70), SIMDE_FLOAT32_C( -820.28)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  683.93), SIMDE_FLOAT32_C( -442.40),
                         SIMDE_FLOAT32_C( -321.81), SIMDE_FLOAT32_C(  -47.02),
                         SIMDE_FLOAT32_C( -854.54), SIMDE_FLOAT32_C(  -65.39),
                         SIMDE_FLOAT32_C( -879.02), SIMDE_FLOAT32_C( -144.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -204.43), SIMDE_FLOAT32_C(  186.43),
                         SIMDE_FLOAT32_C( -537.46), SIMDE_FLOAT32_C( -851.25),
                         SIMDE_FLOAT32_C( -312.32), SIMDE_FLOAT32_C( -630.06),
                         SIMDE_FLOAT32_C( -737.72), SIMDE_FLOAT32_C(  475.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -537.46), SIMDE_FLOAT32_C( -321.81),
                         SIMDE_FLOAT32_C( -851.25), SIMDE_FLOAT32_C(  -47.02),
                         SIMDE_FLOAT32_C( -737.72), SIMDE_FLOAT32_C( -879.02),
                         SIMDE_FLOAT32_C(  475.72), SIMDE_FLOAT32_C( -144.43)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -948.98), SIMDE_FLOAT32_C(  497.67),
                         SIMDE_FLOAT32_C(  650.06), SIMDE_FLOAT32_C(  741.02),
                         SIMDE_FLOAT32_C( -984.88), SIMDE_FLOAT32_C( -952.48),
                         SIMDE_FLOAT32_C( -355.06), SIMDE_FLOAT32_C(  845.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  984.39), SIMDE_FLOAT32_C( -147.65),
                         SIMDE_FLOAT32_C( -608.72), SIMDE_FLOAT32_C(  798.45),
                         SIMDE_FLOAT32_C( -191.22), SIMDE_FLOAT32_C( -819.43),
                         SIMDE_FLOAT32_C(  651.13), SIMDE_FLOAT32_C(  878.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -608.72), SIMDE_FLOAT32_C(  650.06),
                         SIMDE_FLOAT32_C(  798.45), SIMDE_FLOAT32_C(  741.02),
                         SIMDE_FLOAT32_C(  651.13), SIMDE_FLOAT32_C( -355.06),
                         SIMDE_FLOAT32_C(  878.58), SIMDE_FLOAT32_C(  845.88)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  860.59), SIMDE_FLOAT32_C(  -10.76),
                         SIMDE_FLOAT32_C( -198.30), SIMDE_FLOAT32_C(   77.85),
                         SIMDE_FLOAT32_C(  -62.31), SIMDE_FLOAT32_C(   -4.21),
                         SIMDE_FLOAT32_C(  365.71), SIMDE_FLOAT32_C(  937.33)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -309.45), SIMDE_FLOAT32_C(  297.29),
                         SIMDE_FLOAT32_C(  986.26), SIMDE_FLOAT32_C( -531.67),
                         SIMDE_FLOAT32_C(  648.25), SIMDE_FLOAT32_C( -225.86),
                         SIMDE_FLOAT32_C( -897.83), SIMDE_FLOAT32_C(  816.08)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  986.26), SIMDE_FLOAT32_C( -198.30),
                         SIMDE_FLOAT32_C( -531.67), SIMDE_FLOAT32_C(   77.85),
                         SIMDE_FLOAT32_C( -897.83), SIMDE_FLOAT32_C(  365.71),
                         SIMDE_FLOAT32_C(  816.08), SIMDE_FLOAT32_C(  937.33)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_unpacklo_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_unpacklo_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -600.90), SIMDE_FLOAT64_C( -534.18),
                         SIMDE_FLOAT64_C( -294.96), SIMDE_FLOAT64_C(  194.68)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  653.08), SIMDE_FLOAT64_C( -555.28),
                         SIMDE_FLOAT64_C(  745.15), SIMDE_FLOAT64_C( -216.67)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -555.28), SIMDE_FLOAT64_C( -534.18),
                         SIMDE_FLOAT64_C( -216.67), SIMDE_FLOAT64_C(  194.68)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  421.87), SIMDE_FLOAT64_C(  397.23),
                         SIMDE_FLOAT64_C(  303.53), SIMDE_FLOAT64_C(  285.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -720.94), SIMDE_FLOAT64_C( -472.31),
                         SIMDE_FLOAT64_C(  488.28), SIMDE_FLOAT64_C( -308.40)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -472.31), SIMDE_FLOAT64_C(  397.23),
                         SIMDE_FLOAT64_C( -308.40), SIMDE_FLOAT64_C(  285.42)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -109.61), SIMDE_FLOAT64_C(  180.86),
                         SIMDE_FLOAT64_C(  399.64), SIMDE_FLOAT64_C(  594.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -866.29), SIMDE_FLOAT64_C(  935.36),
                         SIMDE_FLOAT64_C(  680.83), SIMDE_FLOAT64_C(  371.83)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  935.36), SIMDE_FLOAT64_C(  180.86),
                         SIMDE_FLOAT64_C(  371.83), SIMDE_FLOAT64_C(  594.61)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   90.32), SIMDE_FLOAT64_C(  277.68),
                         SIMDE_FLOAT64_C(  879.43), SIMDE_FLOAT64_C( -100.14)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  615.95), SIMDE_FLOAT64_C( -913.08),
                         SIMDE_FLOAT64_C(  109.38), SIMDE_FLOAT64_C(  735.81)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -913.08), SIMDE_FLOAT64_C(  277.68),
                         SIMDE_FLOAT64_C(  735.81), SIMDE_FLOAT64_C( -100.14)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  932.30), SIMDE_FLOAT64_C(  361.71),
                         SIMDE_FLOAT64_C( -106.90), SIMDE_FLOAT64_C( -236.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -388.60), SIMDE_FLOAT64_C( -254.78),
                         SIMDE_FLOAT64_C(   -8.15), SIMDE_FLOAT64_C( -517.38)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -254.78), SIMDE_FLOAT64_C(  361.71),
                         SIMDE_FLOAT64_C( -517.38), SIMDE_FLOAT64_C( -236.07)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  420.24), SIMDE_FLOAT64_C(  915.08),
                         SIMDE_FLOAT64_C( -310.09), SIMDE_FLOAT64_C(  924.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -6.45), SIMDE_FLOAT64_C(  943.38),
                         SIMDE_FLOAT64_C( -842.17), SIMDE_FLOAT64_C(  303.10)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  943.38), SIMDE_FLOAT64_C(  915.08),
                         SIMDE_FLOAT64_C(  303.10), SIMDE_FLOAT64_C(  924.29)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  198.81), SIMDE_FLOAT64_C(  823.67),
                         SIMDE_FLOAT64_C(   21.23), SIMDE_FLOAT64_C(  275.37)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -789.28), SIMDE_FLOAT64_C(  222.39),
                         SIMDE_FLOAT64_C( -125.82), SIMDE_FLOAT64_C( -521.52)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  222.39), SIMDE_FLOAT64_C(  823.67),
                         SIMDE_FLOAT64_C( -521.52), SIMDE_FLOAT64_C(  275.37)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   71.55), SIMDE_FLOAT64_C( -915.84),
                         SIMDE_FLOAT64_C( -246.51), SIMDE_FLOAT64_C( -206.93)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -663.61), SIMDE_FLOAT64_C(  763.05),
                         SIMDE_FLOAT64_C( -365.16), SIMDE_FLOAT64_C( -475.21)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  763.05), SIMDE_FLOAT64_C( -915.84),
                         SIMDE_FLOAT64_C( -475.21), SIMDE_FLOAT64_C( -206.93)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_unpacklo_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xor_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  125.09), SIMDE_FLOAT64_C(  533.33),
                         SIMDE_FLOAT64_C(  190.03), SIMDE_FLOAT64_C( -352.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  208.67), SIMDE_FLOAT64_C( -937.37),
                         SIMDE_FLOAT64_C(  842.10), SIMDE_FLOAT64_C(  692.29)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -785.19), SIMDE_FLOAT64_C( -227.52),
                         SIMDE_FLOAT64_C( -675.22), SIMDE_FLOAT64_C(  927.05)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  333.25), SIMDE_FLOAT64_C(  653.61),
                         SIMDE_FLOAT64_C(  853.07), SIMDE_FLOAT64_C(  580.55)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  846.59), SIMDE_FLOAT64_C( -306.35),
                         SIMDE_FLOAT64_C(  201.33), SIMDE_FLOAT64_C( -591.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  539.65), SIMDE_FLOAT64_C(  901.07),
                         SIMDE_FLOAT64_C( -281.86), SIMDE_FLOAT64_C( -385.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -208.55), SIMDE_FLOAT64_C( -102.16),
                         SIMDE_FLOAT64_C(  741.78), SIMDE_FLOAT64_C( -841.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   42.61), SIMDE_FLOAT64_C(  866.30),
                         SIMDE_FLOAT64_C( -734.78), SIMDE_FLOAT64_C( -363.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  -80.10), SIMDE_FLOAT64_C(   -6.79),
                         SIMDE_FLOAT64_C(   45.81), SIMDE_FLOAT64_C( -402.99)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -431.36), SIMDE_FLOAT64_C(  229.84),
                         SIMDE_FLOAT64_C( -298.07), SIMDE_FLOAT64_C( -459.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -252.25), SIMDE_FLOAT64_C( -434.28),
                         SIMDE_FLOAT64_C( -802.07), SIMDE_FLOAT64_C(  931.61)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  494.93), SIMDE_FLOAT64_C( -455.26),
                         SIMDE_FLOAT64_C(  781.09), SIMDE_FLOAT64_C(  819.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(   -0.00), SIMDE_FLOAT64_C(    0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  114.61), SIMDE_FLOAT64_C(  574.95),
                         SIMDE_FLOAT64_C( -900.56), SIMDE_FLOAT64_C( -784.93)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  405.36), SIMDE_FLOAT64_C(  885.34),
                         SIMDE_FLOAT64_C( -606.18), SIMDE_FLOAT64_C(  785.23)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00)) },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -477.77), SIMDE_FLOAT64_C( -377.20),
                         SIMDE_FLOAT64_C( -207.72), SIMDE_FLOAT64_C(  319.51)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -449.36), SIMDE_FLOAT64_C(  638.76),
                         SIMDE_FLOAT64_C( -315.99), SIMDE_FLOAT64_C(  136.54)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(   -0.00),
                         SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_xor_pd(test_vec[i].a, test_vec[i].b);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_xor_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    simde__m256 r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   548.70), SIMDE_FLOAT32_C(  -868.78),
                         SIMDE_FLOAT32_C(    -8.43), SIMDE_FLOAT32_C(   -89.68),
                         SIMDE_FLOAT32_C(  -222.56), SIMDE_FLOAT32_C(   837.57),
                         SIMDE_FLOAT32_C(  -514.53), SIMDE_FLOAT32_C(   769.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -145.72), SIMDE_FLOAT32_C(  -597.70),
                         SIMDE_FLOAT32_C(  -427.69), SIMDE_FLOAT32_C(  -216.99),
                         SIMDE_FLOAT32_C(   665.42), SIMDE_FLOAT32_C(    -3.00),
                         SIMDE_FLOAT32_C(  -694.73), SIMDE_FLOAT32_C(   203.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   476.58), SIMDE_FLOAT32_C(  -306.29),
                         SIMDE_FLOAT32_C(   588.53), SIMDE_FLOAT32_C(   127.68),
                         SIMDE_FLOAT32_C(  -500.35), SIMDE_FLOAT32_C(   955.55),
                         SIMDE_FLOAT32_C(   220.89), SIMDE_FLOAT32_C(  -767.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   445.28), SIMDE_FLOAT32_C(   141.81),
                         SIMDE_FLOAT32_C(  -713.76), SIMDE_FLOAT32_C(  -354.21),
                         SIMDE_FLOAT32_C(   679.03), SIMDE_FLOAT32_C(  -912.95),
                         SIMDE_FLOAT32_C(   204.18), SIMDE_FLOAT32_C(   506.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   933.45), SIMDE_FLOAT32_C(     5.37),
                         SIMDE_FLOAT32_C(  -777.73), SIMDE_FLOAT32_C(   798.82),
                         SIMDE_FLOAT32_C(   443.43), SIMDE_FLOAT32_C(    -5.06),
                         SIMDE_FLOAT32_C(   288.87), SIMDE_FLOAT32_C(  -504.88)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   239.90), SIMDE_FLOAT32_C(  -955.68),
                         SIMDE_FLOAT32_C(  -266.36), SIMDE_FLOAT32_C(   865.21),
                         SIMDE_FLOAT32_C(   416.82), SIMDE_FLOAT32_C(   -51.58),
                         SIMDE_FLOAT32_C(   122.82), SIMDE_FLOAT32_C(   125.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   802.73), SIMDE_FLOAT32_C(  -683.98),
                         SIMDE_FLOAT32_C(  -844.98), SIMDE_FLOAT32_C(   391.53),
                         SIMDE_FLOAT32_C(  -895.03), SIMDE_FLOAT32_C(  -743.00),
                         SIMDE_FLOAT32_C(  -811.16), SIMDE_FLOAT32_C(  -926.14)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   136.72), SIMDE_FLOAT32_C(  -962.56),
                         SIMDE_FLOAT32_C(   589.78), SIMDE_FLOAT32_C(   684.43),
                         SIMDE_FLOAT32_C(  -510.18), SIMDE_FLOAT32_C(   881.66),
                         SIMDE_FLOAT32_C(  -753.43), SIMDE_FLOAT32_C(   713.54)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -483.96), SIMDE_FLOAT32_C(  -109.20),
                         SIMDE_FLOAT32_C(  -641.20), SIMDE_FLOAT32_C(   454.31),
                         SIMDE_FLOAT32_C(   511.51), SIMDE_FLOAT32_C(  -732.98),
                         SIMDE_FLOAT32_C(   946.00), SIMDE_FLOAT32_C(  -922.25)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -819.03), SIMDE_FLOAT32_C(  -496.99),
                         SIMDE_FLOAT32_C(    85.62), SIMDE_FLOAT32_C(  -569.10),
                         SIMDE_FLOAT32_C(  -386.34), SIMDE_FLOAT32_C(   216.80),
                         SIMDE_FLOAT32_C(  -244.13), SIMDE_FLOAT32_C(   -77.34)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   727.77), SIMDE_FLOAT32_C(  -477.08),
                         SIMDE_FLOAT32_C(     7.90), SIMDE_FLOAT32_C(   499.42),
                         SIMDE_FLOAT32_C(  -256.10), SIMDE_FLOAT32_C(  -756.97),
                         SIMDE_FLOAT32_C(   383.44), SIMDE_FLOAT32_C(  -510.60)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -270.31), SIMDE_FLOAT32_C(  -502.66),
                         SIMDE_FLOAT32_C(   467.87), SIMDE_FLOAT32_C(   445.96),
                         SIMDE_FLOAT32_C(  -357.92), SIMDE_FLOAT32_C(  -586.04),
                         SIMDE_FLOAT32_C(   -63.05), SIMDE_FLOAT32_C(   391.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -426.87), SIMDE_FLOAT32_C(   -96.04),
                         SIMDE_FLOAT32_C(   625.98), SIMDE_FLOAT32_C(   704.53),
                         SIMDE_FLOAT32_C(   227.86), SIMDE_FLOAT32_C(  -411.45),
                         SIMDE_FLOAT32_C(   -17.45), SIMDE_FLOAT32_C(   -10.30)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   456.59), SIMDE_FLOAT32_C(   656.00),
                         SIMDE_FLOAT32_C(    17.64), SIMDE_FLOAT32_C(   602.75),
                         SIMDE_FLOAT32_C(   153.79), SIMDE_FLOAT32_C(  -466.92),
                         SIMDE_FLOAT32_C(  -648.89), SIMDE_FLOAT32_C(  -965.57)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00)) },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -404.61), SIMDE_FLOAT32_C(  -361.93),
                         SIMDE_FLOAT32_C(     8.96), SIMDE_FLOAT32_C(  -813.96),
                         SIMDE_FLOAT32_C(   760.95), SIMDE_FLOAT32_C(   953.74),
                         SIMDE_FLOAT32_C(   288.70), SIMDE_FLOAT32_C(   347.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  -441.96), SIMDE_FLOAT32_C(   232.27),
                         SIMDE_FLOAT32_C(    51.60), SIMDE_FLOAT32_C(  -387.30),
                         SIMDE_FLOAT32_C(  -615.38), SIMDE_FLOAT32_C(   162.60),
                         SIMDE_FLOAT32_C(  -145.41), SIMDE_FLOAT32_C(   683.61)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
                         SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),
                         SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_xor_ps(test_vec[i].a, test_vec[i].b);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}


static MunitResult
test_simde_mm256_zextps128_ps256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m256 r;
  } test_vec[8] = {
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -312.77), SIMDE_FLOAT32_C(  594.20),
                         SIMDE_FLOAT32_C( -325.59), SIMDE_FLOAT32_C( -490.02)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -312.77), SIMDE_FLOAT32_C(  594.20),
                         SIMDE_FLOAT32_C( -325.59), SIMDE_FLOAT32_C( -490.02)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -164.79), SIMDE_FLOAT32_C( -934.42),
                         SIMDE_FLOAT32_C(  921.14), SIMDE_FLOAT32_C(   62.10)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -164.79), SIMDE_FLOAT32_C( -934.42),
                         SIMDE_FLOAT32_C(  921.14), SIMDE_FLOAT32_C(   62.10)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -517.66), SIMDE_FLOAT32_C(  967.01),
                         SIMDE_FLOAT32_C(  846.07), SIMDE_FLOAT32_C(  311.22)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -517.66), SIMDE_FLOAT32_C(  967.01),
                         SIMDE_FLOAT32_C(  846.07), SIMDE_FLOAT32_C(  311.22)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  258.19), SIMDE_FLOAT32_C(    3.23),
                         SIMDE_FLOAT32_C( -975.57), SIMDE_FLOAT32_C(  -36.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  258.19), SIMDE_FLOAT32_C(    3.23),
                         SIMDE_FLOAT32_C( -975.57), SIMDE_FLOAT32_C(  -36.42)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -435.42), SIMDE_FLOAT32_C(  892.30),
                         SIMDE_FLOAT32_C( -907.17), SIMDE_FLOAT32_C( -773.85)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -435.42), SIMDE_FLOAT32_C(  892.30),
                         SIMDE_FLOAT32_C( -907.17), SIMDE_FLOAT32_C( -773.85)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  555.74), SIMDE_FLOAT32_C( -152.72),
                         SIMDE_FLOAT32_C(  264.72), SIMDE_FLOAT32_C(  888.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  555.74), SIMDE_FLOAT32_C( -152.72),
                         SIMDE_FLOAT32_C(  264.72), SIMDE_FLOAT32_C(  888.72)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C( -118.52), SIMDE_FLOAT32_C( -258.55),
                         SIMDE_FLOAT32_C(  -89.99), SIMDE_FLOAT32_C(  -84.84)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C( -118.52), SIMDE_FLOAT32_C( -258.55),
                         SIMDE_FLOAT32_C(  -89.99), SIMDE_FLOAT32_C(  -84.84)) },
    {    simde_mm_set_ps(SIMDE_FLOAT32_C(  270.43), SIMDE_FLOAT32_C( -194.76),
                         SIMDE_FLOAT32_C( -351.14), SIMDE_FLOAT32_C(  335.42)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(    0.00), SIMDE_FLOAT32_C(    0.00),
                         SIMDE_FLOAT32_C(  270.43), SIMDE_FLOAT32_C( -194.76),
                         SIMDE_FLOAT32_C( -351.14), SIMDE_FLOAT32_C(  335.42)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256 r = simde_mm256_zextps128_ps256(test_vec[i].a);
    simde_assert_m256_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_zextpd128_pd256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m256d r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  376.29), SIMDE_FLOAT64_C( -625.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  376.29), SIMDE_FLOAT64_C( -625.09)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -371.24), SIMDE_FLOAT64_C( -550.26)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -371.24), SIMDE_FLOAT64_C( -550.26)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -354.92), SIMDE_FLOAT64_C( -801.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -354.92), SIMDE_FLOAT64_C( -801.74)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -686.18), SIMDE_FLOAT64_C(  492.11)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -686.18), SIMDE_FLOAT64_C(  492.11)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -504.19), SIMDE_FLOAT64_C( -186.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -504.19), SIMDE_FLOAT64_C( -186.92)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  116.22), SIMDE_FLOAT64_C(  481.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  116.22), SIMDE_FLOAT64_C(  481.86)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  436.67), SIMDE_FLOAT64_C(  524.04)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C(  436.67), SIMDE_FLOAT64_C(  524.04)) },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -466.66), SIMDE_FLOAT64_C(  855.76)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(    0.00), SIMDE_FLOAT64_C(    0.00),
                         SIMDE_FLOAT64_C( -466.66), SIMDE_FLOAT64_C(  855.76)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256d r = simde_mm256_zextpd128_pd256(test_vec[i].a);
    simde_assert_m256d_close(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_zextsi128_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128i a;
    simde__m256i r;
  } test_vec[8] = {
    { simde_mm_set_epi32(INT32_C(-1643962878), INT32_C(-2136224029), INT32_C( -862547967), INT32_C( 1563544589)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1643962878), INT32_C(-2136224029), INT32_C( -862547967), INT32_C( 1563544589)) },
    { simde_mm_set_epi32(INT32_C(  222615505), INT32_C(-1697983622), INT32_C(-1628394379), INT32_C( 1723107736)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  222615505), INT32_C(-1697983622), INT32_C(-1628394379), INT32_C( 1723107736)) },
    { simde_mm_set_epi32(INT32_C(  317003320), INT32_C(  266477895), INT32_C(-2056377610), INT32_C( -882756593)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  317003320), INT32_C(  266477895), INT32_C(-2056377610), INT32_C( -882756593)) },
    { simde_mm_set_epi32(INT32_C( 1329871120), INT32_C( 1486902655), INT32_C(   47452678), INT32_C( 1284761395)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1329871120), INT32_C( 1486902655), INT32_C(   47452678), INT32_C( 1284761395)) },
    { simde_mm_set_epi32(INT32_C( 1382110307), INT32_C( 1399602482), INT32_C(-2085222328), INT32_C( -378818432)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( 1382110307), INT32_C( 1399602482), INT32_C(-2085222328), INT32_C( -378818432)) },
    { simde_mm_set_epi32(INT32_C(  181961329), INT32_C(  805996393), INT32_C( 1252840330), INT32_C( -381034184)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(  181961329), INT32_C(  805996393), INT32_C( 1252840330), INT32_C( -381034184)) },
    { simde_mm_set_epi32(INT32_C(-1859226353), INT32_C( -981205803), INT32_C( -178937485), INT32_C(-1391112590)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(-1859226353), INT32_C( -981205803), INT32_C( -178937485), INT32_C(-1391112590)) },
    { simde_mm_set_epi32(INT32_C( -625262837), INT32_C(-1636493607), INT32_C( -899223790), INT32_C(-2123458109)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C( -625262837), INT32_C(-1636493607), INT32_C( -899223790), INT32_C(-2123458109)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m256i r = simde_mm256_zextsi128_si256(test_vec[i].a);
    simde_assert_m256i_i32(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testc_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -975.49), SIMDE_FLOAT32_C(  483.21), SIMDE_FLOAT32_C( -728.28), SIMDE_FLOAT32_C(   87.20)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  838.35), SIMDE_FLOAT32_C(  502.70), SIMDE_FLOAT32_C(  259.53), SIMDE_FLOAT32_C(  492.16)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  145.89), SIMDE_FLOAT32_C(  703.10), SIMDE_FLOAT32_C(  934.08), SIMDE_FLOAT32_C(  486.65)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -729.11), SIMDE_FLOAT32_C( -285.01), SIMDE_FLOAT32_C(  936.71), SIMDE_FLOAT32_C( -581.95)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -465.31), SIMDE_FLOAT32_C(  947.68), SIMDE_FLOAT32_C(  581.66), SIMDE_FLOAT32_C(  632.88)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  892.71), SIMDE_FLOAT32_C(  965.49), SIMDE_FLOAT32_C( -562.05), SIMDE_FLOAT32_C(   23.24)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  527.52), SIMDE_FLOAT32_C(  684.72), SIMDE_FLOAT32_C( -444.91), SIMDE_FLOAT32_C(  864.11)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -726.99), SIMDE_FLOAT32_C(  870.43), SIMDE_FLOAT32_C(  880.94), SIMDE_FLOAT32_C(  503.59)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -313.88), SIMDE_FLOAT32_C(  663.71), SIMDE_FLOAT32_C( -545.28), SIMDE_FLOAT32_C(  409.96)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   31.21), SIMDE_FLOAT32_C(  -81.33), SIMDE_FLOAT32_C( -792.56), SIMDE_FLOAT32_C(  868.13)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  844.22), SIMDE_FLOAT32_C( -506.15), SIMDE_FLOAT32_C( -527.87), SIMDE_FLOAT32_C( -352.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  765.09), SIMDE_FLOAT32_C(  315.48), SIMDE_FLOAT32_C(  792.46), SIMDE_FLOAT32_C(  202.31)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -116.04), SIMDE_FLOAT32_C(  223.43), SIMDE_FLOAT32_C(  582.43), SIMDE_FLOAT32_C(  806.86)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -409.50), SIMDE_FLOAT32_C(  334.07), SIMDE_FLOAT32_C( -959.71), SIMDE_FLOAT32_C( -395.22)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  -17.46), SIMDE_FLOAT32_C(  569.91), SIMDE_FLOAT32_C( -620.83), SIMDE_FLOAT32_C(  411.71)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  294.19), SIMDE_FLOAT32_C(  545.09), SIMDE_FLOAT32_C(  315.96), SIMDE_FLOAT32_C( -698.39)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testc_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testc_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  403.40), SIMDE_FLOAT64_C( -277.35)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  458.69), SIMDE_FLOAT64_C( -453.43)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -528.69), SIMDE_FLOAT64_C(   40.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  548.92), SIMDE_FLOAT64_C(  -42.14)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -931.64), SIMDE_FLOAT64_C( -909.64)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -112.03), SIMDE_FLOAT64_C(  413.67)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -611.37), SIMDE_FLOAT64_C(   85.99)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  527.48), SIMDE_FLOAT64_C( -378.25)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -343.28), SIMDE_FLOAT64_C( -471.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  984.73), SIMDE_FLOAT64_C(  518.21)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  965.66), SIMDE_FLOAT64_C( -647.86)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  395.59), SIMDE_FLOAT64_C(  961.89)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  763.28), SIMDE_FLOAT64_C(  421.62)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -682.67), SIMDE_FLOAT64_C( -348.51)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -947.12), SIMDE_FLOAT64_C(  147.81)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  745.97), SIMDE_FLOAT64_C( -540.47)),
      0 }
  };
  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testc_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testc_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -169.00), SIMDE_FLOAT32_C( -295.41),
                         SIMDE_FLOAT32_C(  260.09), SIMDE_FLOAT32_C( -617.68),
                         SIMDE_FLOAT32_C(  318.47), SIMDE_FLOAT32_C( -889.00),
                         SIMDE_FLOAT32_C(  991.56), SIMDE_FLOAT32_C(  -25.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  252.34), SIMDE_FLOAT32_C(  -77.52),
                         SIMDE_FLOAT32_C( -724.69), SIMDE_FLOAT32_C(  823.10),
                         SIMDE_FLOAT32_C( -653.61), SIMDE_FLOAT32_C( -673.14),
                         SIMDE_FLOAT32_C(  294.16), SIMDE_FLOAT32_C(  969.47)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  269.05), SIMDE_FLOAT32_C(  535.88),
                         SIMDE_FLOAT32_C(  534.89), SIMDE_FLOAT32_C( -793.57),
                         SIMDE_FLOAT32_C( -723.99), SIMDE_FLOAT32_C( -951.14),
                         SIMDE_FLOAT32_C( -834.84), SIMDE_FLOAT32_C( -924.19)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -369.85), SIMDE_FLOAT32_C( -791.09),
                         SIMDE_FLOAT32_C(  -28.29), SIMDE_FLOAT32_C(  -28.76),
                         SIMDE_FLOAT32_C(  912.84), SIMDE_FLOAT32_C( -660.86),
                         SIMDE_FLOAT32_C( -511.48), SIMDE_FLOAT32_C( -116.65)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  491.90), SIMDE_FLOAT32_C( -371.75),
                         SIMDE_FLOAT32_C( -693.29), SIMDE_FLOAT32_C(  554.30),
                         SIMDE_FLOAT32_C( -859.01), SIMDE_FLOAT32_C( -958.17),
                         SIMDE_FLOAT32_C(  272.98), SIMDE_FLOAT32_C(  829.99)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  783.82), SIMDE_FLOAT32_C( -735.12),
                         SIMDE_FLOAT32_C(  265.82), SIMDE_FLOAT32_C( -598.04),
                         SIMDE_FLOAT32_C( -693.48), SIMDE_FLOAT32_C(  798.61),
                         SIMDE_FLOAT32_C( -618.96), SIMDE_FLOAT32_C(  625.43)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  321.41), SIMDE_FLOAT32_C( -827.42),
                         SIMDE_FLOAT32_C( -235.24), SIMDE_FLOAT32_C(  914.82),
                         SIMDE_FLOAT32_C(    3.35), SIMDE_FLOAT32_C(  -99.95),
                         SIMDE_FLOAT32_C( -932.57), SIMDE_FLOAT32_C(  846.75)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  827.87), SIMDE_FLOAT32_C(  782.35),
                         SIMDE_FLOAT32_C(  364.26), SIMDE_FLOAT32_C(  589.04),
                         SIMDE_FLOAT32_C(   72.17), SIMDE_FLOAT32_C(  906.51),
                         SIMDE_FLOAT32_C(  816.64), SIMDE_FLOAT32_C(  975.90)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -175.70), SIMDE_FLOAT32_C( -858.68),
                         SIMDE_FLOAT32_C(  205.72), SIMDE_FLOAT32_C(  623.26),
                         SIMDE_FLOAT32_C( -971.72), SIMDE_FLOAT32_C( -925.85),
                         SIMDE_FLOAT32_C( -832.18), SIMDE_FLOAT32_C(  290.40)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  995.07), SIMDE_FLOAT32_C(  482.43),
                         SIMDE_FLOAT32_C(  148.85), SIMDE_FLOAT32_C(  851.08),
                         SIMDE_FLOAT32_C( -260.21), SIMDE_FLOAT32_C( -679.27),
                         SIMDE_FLOAT32_C(  612.96), SIMDE_FLOAT32_C( -131.17)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -930.60), SIMDE_FLOAT32_C(  310.01),
                         SIMDE_FLOAT32_C(  768.42), SIMDE_FLOAT32_C( -620.68),
                         SIMDE_FLOAT32_C( -106.57), SIMDE_FLOAT32_C( -657.44),
                         SIMDE_FLOAT32_C(  384.33), SIMDE_FLOAT32_C( -279.72)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   43.01), SIMDE_FLOAT32_C( -312.85),
                         SIMDE_FLOAT32_C( -161.92), SIMDE_FLOAT32_C( -359.59),
                         SIMDE_FLOAT32_C( -839.05), SIMDE_FLOAT32_C(   39.24),
                         SIMDE_FLOAT32_C(  321.97), SIMDE_FLOAT32_C(  303.19)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(   58.24), SIMDE_FLOAT32_C( -990.13),
                         SIMDE_FLOAT32_C(  132.06), SIMDE_FLOAT32_C( -797.37),
                         SIMDE_FLOAT32_C(  843.65), SIMDE_FLOAT32_C( -987.25),
                         SIMDE_FLOAT32_C( -376.56), SIMDE_FLOAT32_C( -319.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -543.47), SIMDE_FLOAT32_C( -525.74),
                         SIMDE_FLOAT32_C( -613.35), SIMDE_FLOAT32_C(  390.35),
                         SIMDE_FLOAT32_C( -782.19), SIMDE_FLOAT32_C(  -13.25),
                         SIMDE_FLOAT32_C(  978.40), SIMDE_FLOAT32_C(  796.97)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  904.12), SIMDE_FLOAT32_C( -477.03),
                         SIMDE_FLOAT32_C( -234.30), SIMDE_FLOAT32_C( -407.00),
                         SIMDE_FLOAT32_C( -205.27), SIMDE_FLOAT32_C(  -89.25),
                         SIMDE_FLOAT32_C( -245.34), SIMDE_FLOAT32_C( -973.70)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  359.42), SIMDE_FLOAT32_C(  340.47),
                         SIMDE_FLOAT32_C( -928.36), SIMDE_FLOAT32_C(  988.69),
                         SIMDE_FLOAT32_C(  898.92), SIMDE_FLOAT32_C( -682.31),
                         SIMDE_FLOAT32_C( -259.92), SIMDE_FLOAT32_C(  333.26)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testc_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testc_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  123.47), SIMDE_FLOAT64_C(  212.54),
                         SIMDE_FLOAT64_C(  522.75), SIMDE_FLOAT64_C(    1.15)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -709.99), SIMDE_FLOAT64_C(  514.03),
                         SIMDE_FLOAT64_C(  845.48), SIMDE_FLOAT64_C( -789.13)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  684.95), SIMDE_FLOAT64_C( -284.02),
                         SIMDE_FLOAT64_C(  731.17), SIMDE_FLOAT64_C( -676.64)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -937.45), SIMDE_FLOAT64_C( -128.99),
                         SIMDE_FLOAT64_C( -272.42), SIMDE_FLOAT64_C(  828.88)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  792.09), SIMDE_FLOAT64_C(  380.65),
                         SIMDE_FLOAT64_C( -640.40), SIMDE_FLOAT64_C(  320.89)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  952.36), SIMDE_FLOAT64_C( -153.20),
                         SIMDE_FLOAT64_C( -728.44), SIMDE_FLOAT64_C(  534.46)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -746.07), SIMDE_FLOAT64_C( -762.31),
                         SIMDE_FLOAT64_C( -109.79), SIMDE_FLOAT64_C(  660.25)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -321.84), SIMDE_FLOAT64_C(  811.70),
                         SIMDE_FLOAT64_C( -839.71), SIMDE_FLOAT64_C(  614.83)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  484.63), SIMDE_FLOAT64_C(  471.47),
                         SIMDE_FLOAT64_C( -100.70), SIMDE_FLOAT64_C(  887.09)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -761.94), SIMDE_FLOAT64_C( -263.49),
                         SIMDE_FLOAT64_C( -928.32), SIMDE_FLOAT64_C( -481.21)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  563.75), SIMDE_FLOAT64_C( -564.39),
                         SIMDE_FLOAT64_C(    2.49), SIMDE_FLOAT64_C(  514.36)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  928.41), SIMDE_FLOAT64_C(  792.30),
                         SIMDE_FLOAT64_C( -596.24), SIMDE_FLOAT64_C(  365.58)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -909.73), SIMDE_FLOAT64_C(  892.46),
                         SIMDE_FLOAT64_C( -678.05), SIMDE_FLOAT64_C(  778.72)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -258.15), SIMDE_FLOAT64_C(  100.48),
                         SIMDE_FLOAT64_C(  -77.87), SIMDE_FLOAT64_C( -152.48)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -613.30), SIMDE_FLOAT64_C( -567.86),
                         SIMDE_FLOAT64_C(  674.67), SIMDE_FLOAT64_C( -566.07)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  -57.83), SIMDE_FLOAT64_C( -183.14),
                         SIMDE_FLOAT64_C(  852.20), SIMDE_FLOAT64_C( -939.00)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testc_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testc_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi32(INT32_C( 1590541233), INT32_C( -436989526), INT32_C(-1581572624), INT32_C(-1048507105),
                            INT32_C(-1251227046), INT32_C( -111355701), INT32_C(  463981150), INT32_C(-1310282310)),
      simde_mm256_set_epi32(INT32_C(-1730174443), INT32_C(  962749992), INT32_C( 1889650969), INT32_C(-1644227432),
                            INT32_C(-1044962626), INT32_C( 2047573026), INT32_C(-1475613534), INT32_C( -143917251)),
      0 },
    { simde_mm256_set_epi32(INT32_C(-1338083145), INT32_C( 1764771144), INT32_C( -397147050), INT32_C( -289476710),
                            INT32_C( 1323271828), INT32_C(  -86062147), INT32_C( -642595378), INT32_C( -876487591)),
      simde_mm256_set_epi32(INT32_C( -876677989), INT32_C( 1319440399), INT32_C(  561344787), INT32_C( 2014642071),
                            INT32_C( 1196573650), INT32_C(  773018631), INT32_C( 1292104201), INT32_C( 1045703036)),
      0 },
    { simde_mm256_set_epi32(INT32_C(  283890165), INT32_C( -214227023), INT32_C(  601751308), INT32_C( -649446863),
                            INT32_C( -948918925), INT32_C( 1931664941), INT32_C( -846451204), INT32_C( 1136409049)),
      simde_mm256_set_epi32(INT32_C( -384402282), INT32_C( -992732365), INT32_C(-1540963980), INT32_C(  244471001),
                            INT32_C( -395648516), INT32_C( 1146402181), INT32_C( -520478107), INT32_C(-1866567951)),
      0 },
    { simde_mm256_set_epi32(INT32_C(-1798222531), INT32_C(-1196367171), INT32_C( 1622696128), INT32_C(  716668488),
                            INT32_C( 1277881561), INT32_C(-1886059507), INT32_C(-1722396956), INT32_C(  904397943)),
      simde_mm256_set_epi32(INT32_C( 1590185315), INT32_C(-2054583206), INT32_C( -524141746), INT32_C( 1070740740),
                            INT32_C(  228023403), INT32_C(-1312111237), INT32_C(-1647173119), INT32_C(-1984225652)),
      0 },
    { simde_mm256_set_epi32(INT32_C( -291109931), INT32_C(  864813403), INT32_C( 1389239783), INT32_C( 1410930820),
                            INT32_C(  876721304), INT32_C( 1356075339), INT32_C( -969519815), INT32_C( 1884376513)),
      simde_mm256_set_epi32(INT32_C( -348088337), INT32_C( 1648834089), INT32_C(  799153644), INT32_C(-1690149060),
                            INT32_C( -552425726), INT32_C(  889492544), INT32_C( -332273251), INT32_C(-1382843562)),
      0 },
    { simde_mm256_set_epi32(INT32_C( 1282291341), INT32_C( 1395600177), INT32_C( -618520147), INT32_C(  318386342),
                            INT32_C(-1071446046), INT32_C( 1914859572), INT32_C(-1754705496), INT32_C( -643641727)),
      simde_mm256_set_epi32(INT32_C( 1620891909), INT32_C(-1744463022), INT32_C( 1083709334), INT32_C( 1908851820),
                            INT32_C(-1141617057), INT32_C(-1138459296), INT32_C( -288617760), INT32_C(-1727368553)),
      0 },
    { simde_mm256_set_epi32(INT32_C( 1523147892), INT32_C( 1037444310), INT32_C(  -23711686), INT32_C(-1269181771),
                            INT32_C( 1945791614), INT32_C( -804519478), INT32_C(  -20906646), INT32_C( 1310709876)),
      simde_mm256_set_epi32(INT32_C( -504237752), INT32_C(  883986365), INT32_C( 1802809300), INT32_C(-1859897822),
                            INT32_C(-1272698163), INT32_C( -143410874), INT32_C(  638495924), INT32_C(-1299515093)),
      0 },
    { simde_mm256_set_epi32(INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1),
                            INT32_C(         -1), INT32_C(         -1), INT32_C(         -1), INT32_C(         -1)),
      simde_mm256_set_epi32(INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0),
                            INT32_C(          0), INT32_C(          0), INT32_C(          0), INT32_C(          0)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testc_si256(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testz_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -535.65), SIMDE_FLOAT32_C( -770.48), SIMDE_FLOAT32_C(  566.67), SIMDE_FLOAT32_C(  159.53)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  117.32), SIMDE_FLOAT32_C( -915.32), SIMDE_FLOAT32_C( -244.51), SIMDE_FLOAT32_C(  139.82)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  688.86), SIMDE_FLOAT32_C(  962.46), SIMDE_FLOAT32_C(  502.62), SIMDE_FLOAT32_C( -759.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  447.13), SIMDE_FLOAT32_C(  569.82), SIMDE_FLOAT32_C(  813.87), SIMDE_FLOAT32_C(  -41.23)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  717.58), SIMDE_FLOAT32_C( -388.95), SIMDE_FLOAT32_C(  405.99), SIMDE_FLOAT32_C( -505.21)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  651.17), SIMDE_FLOAT32_C(   43.00), SIMDE_FLOAT32_C( -865.65), SIMDE_FLOAT32_C(  116.25)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  748.82), SIMDE_FLOAT32_C( -519.63), SIMDE_FLOAT32_C(  940.52), SIMDE_FLOAT32_C( -776.61)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -86.61), SIMDE_FLOAT32_C(  528.66), SIMDE_FLOAT32_C(  315.29), SIMDE_FLOAT32_C( -836.37)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -930.47), SIMDE_FLOAT32_C(  385.27), SIMDE_FLOAT32_C(  328.25), SIMDE_FLOAT32_C( -891.42)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  769.90), SIMDE_FLOAT32_C(  203.87), SIMDE_FLOAT32_C(   70.77), SIMDE_FLOAT32_C(  153.64)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  110.09), SIMDE_FLOAT32_C( -474.31), SIMDE_FLOAT32_C( -205.82), SIMDE_FLOAT32_C( -912.60)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  690.10), SIMDE_FLOAT32_C( -177.50), SIMDE_FLOAT32_C(   69.56), SIMDE_FLOAT32_C( -722.94)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -854.45), SIMDE_FLOAT32_C( -233.74), SIMDE_FLOAT32_C(  792.75), SIMDE_FLOAT32_C(  911.93)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  835.88), SIMDE_FLOAT32_C( -477.16), SIMDE_FLOAT32_C(  481.40), SIMDE_FLOAT32_C( -325.48)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  349.66), SIMDE_FLOAT32_C(  852.75), SIMDE_FLOAT32_C(  630.50), SIMDE_FLOAT32_C(  599.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  -12.39), SIMDE_FLOAT32_C(  669.65), SIMDE_FLOAT32_C(   19.88), SIMDE_FLOAT32_C( -104.79)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testz_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testz_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -133.70), SIMDE_FLOAT64_C( -364.47)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  299.27), SIMDE_FLOAT64_C(  706.73)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  411.42), SIMDE_FLOAT64_C( -916.18)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  443.76), SIMDE_FLOAT64_C(  616.70)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  177.79), SIMDE_FLOAT64_C( -562.30)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  491.38), SIMDE_FLOAT64_C(  437.67)),
      1 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -601.90), SIMDE_FLOAT64_C(  130.89)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -297.66), SIMDE_FLOAT64_C( -243.36)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -461.95), SIMDE_FLOAT64_C( -708.04)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -179.91), SIMDE_FLOAT64_C(  436.91)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -477.48), SIMDE_FLOAT64_C(  546.05)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -804.65), SIMDE_FLOAT64_C(  660.18)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  366.33), SIMDE_FLOAT64_C( -393.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  758.77), SIMDE_FLOAT64_C( -413.77)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C( -605.04), SIMDE_FLOAT64_C(  186.44)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -113.05), SIMDE_FLOAT64_C(  709.60)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testz_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testz_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  203.89), SIMDE_FLOAT32_C(  929.87),
                         SIMDE_FLOAT32_C( -921.04), SIMDE_FLOAT32_C( -927.33),
                         SIMDE_FLOAT32_C(  876.23), SIMDE_FLOAT32_C(  583.50),
                         SIMDE_FLOAT32_C(  560.83), SIMDE_FLOAT32_C( -996.47)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(   41.17), SIMDE_FLOAT32_C(  356.76),
                         SIMDE_FLOAT32_C( -537.40), SIMDE_FLOAT32_C( -959.48),
                         SIMDE_FLOAT32_C( -224.29), SIMDE_FLOAT32_C(  -28.33),
                         SIMDE_FLOAT32_C( -153.96), SIMDE_FLOAT32_C( -377.38)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  417.43), SIMDE_FLOAT32_C( -235.27),
                         SIMDE_FLOAT32_C( -869.92), SIMDE_FLOAT32_C( -107.51),
                         SIMDE_FLOAT32_C(  353.07), SIMDE_FLOAT32_C(  989.26),
                         SIMDE_FLOAT32_C(   19.42), SIMDE_FLOAT32_C(  737.36)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -799.55), SIMDE_FLOAT32_C( -863.03),
                         SIMDE_FLOAT32_C(  787.36), SIMDE_FLOAT32_C(  884.07),
                         SIMDE_FLOAT32_C( -646.88), SIMDE_FLOAT32_C(  348.23),
                         SIMDE_FLOAT32_C(  -19.97), SIMDE_FLOAT32_C(  231.76)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -434.95), SIMDE_FLOAT32_C(  367.82),
                         SIMDE_FLOAT32_C( -198.30), SIMDE_FLOAT32_C(  569.25),
                         SIMDE_FLOAT32_C(   37.80), SIMDE_FLOAT32_C(  656.68),
                         SIMDE_FLOAT32_C( -154.19), SIMDE_FLOAT32_C( -268.68)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  679.38), SIMDE_FLOAT32_C(  416.08),
                         SIMDE_FLOAT32_C(  591.38), SIMDE_FLOAT32_C( -410.17),
                         SIMDE_FLOAT32_C( -434.20), SIMDE_FLOAT32_C( -656.84),
                         SIMDE_FLOAT32_C( -369.35), SIMDE_FLOAT32_C( -216.32)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -37.47), SIMDE_FLOAT32_C(  -40.21),
                         SIMDE_FLOAT32_C(    5.31), SIMDE_FLOAT32_C(  651.03),
                         SIMDE_FLOAT32_C(   91.95), SIMDE_FLOAT32_C(  136.83),
                         SIMDE_FLOAT32_C(  215.58), SIMDE_FLOAT32_C(  976.43)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  791.68), SIMDE_FLOAT32_C(  -97.52),
                         SIMDE_FLOAT32_C(   49.28), SIMDE_FLOAT32_C(  -47.67),
                         SIMDE_FLOAT32_C( -520.82), SIMDE_FLOAT32_C(  775.18),
                         SIMDE_FLOAT32_C( -311.24), SIMDE_FLOAT32_C(   87.06)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  974.54), SIMDE_FLOAT32_C( -572.67),
                         SIMDE_FLOAT32_C(  228.68), SIMDE_FLOAT32_C( -268.11),
                         SIMDE_FLOAT32_C(   83.97), SIMDE_FLOAT32_C( -607.98),
                         SIMDE_FLOAT32_C(  317.68), SIMDE_FLOAT32_C( -118.11)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -579.32), SIMDE_FLOAT32_C( -684.32),
                         SIMDE_FLOAT32_C(  -14.94), SIMDE_FLOAT32_C(  840.53),
                         SIMDE_FLOAT32_C( -875.18), SIMDE_FLOAT32_C( -264.19),
                         SIMDE_FLOAT32_C( -675.61), SIMDE_FLOAT32_C(  236.61)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  268.13), SIMDE_FLOAT32_C(  524.74),
                         SIMDE_FLOAT32_C( -846.94), SIMDE_FLOAT32_C(  539.16),
                         SIMDE_FLOAT32_C( -824.88), SIMDE_FLOAT32_C(  966.22),
                         SIMDE_FLOAT32_C( -319.64), SIMDE_FLOAT32_C(  463.07)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -484.03), SIMDE_FLOAT32_C( -785.67),
                         SIMDE_FLOAT32_C(  818.22), SIMDE_FLOAT32_C(  722.83),
                         SIMDE_FLOAT32_C( -933.76), SIMDE_FLOAT32_C( -804.32),
                         SIMDE_FLOAT32_C(  -18.04), SIMDE_FLOAT32_C(  790.55)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  496.61), SIMDE_FLOAT32_C(  895.69),
                         SIMDE_FLOAT32_C(   83.61), SIMDE_FLOAT32_C( -625.29),
                         SIMDE_FLOAT32_C( -963.29), SIMDE_FLOAT32_C( -202.04),
                         SIMDE_FLOAT32_C( -184.94), SIMDE_FLOAT32_C(  102.69)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -121.97), SIMDE_FLOAT32_C( -483.26),
                         SIMDE_FLOAT32_C( -796.68), SIMDE_FLOAT32_C(  593.94),
                         SIMDE_FLOAT32_C( -642.73), SIMDE_FLOAT32_C( -850.47),
                         SIMDE_FLOAT32_C( -793.37), SIMDE_FLOAT32_C( -202.72)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  824.10), SIMDE_FLOAT32_C( -794.74),
                         SIMDE_FLOAT32_C( -876.82), SIMDE_FLOAT32_C(   50.96),
                         SIMDE_FLOAT32_C( -281.18), SIMDE_FLOAT32_C( -527.70),
                         SIMDE_FLOAT32_C( -453.71), SIMDE_FLOAT32_C( -588.71)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  755.45), SIMDE_FLOAT32_C( -252.04),
                         SIMDE_FLOAT32_C( -915.68), SIMDE_FLOAT32_C(  -54.75),
                         SIMDE_FLOAT32_C(  -63.75), SIMDE_FLOAT32_C(  413.61),
                         SIMDE_FLOAT32_C( -347.26), SIMDE_FLOAT32_C(  540.31)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testz_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testz_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  374.19), SIMDE_FLOAT64_C( -934.66),
                         SIMDE_FLOAT64_C(  991.69), SIMDE_FLOAT64_C(  768.86)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  772.38), SIMDE_FLOAT64_C(  118.89),
                         SIMDE_FLOAT64_C( -913.18), SIMDE_FLOAT64_C(  220.47)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -659.01), SIMDE_FLOAT64_C( -495.78),
                         SIMDE_FLOAT64_C(  343.83), SIMDE_FLOAT64_C( -984.74)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  485.80), SIMDE_FLOAT64_C(  393.82),
                         SIMDE_FLOAT64_C( -663.76), SIMDE_FLOAT64_C(  -48.15)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(   49.22), SIMDE_FLOAT64_C( -581.06),
                         SIMDE_FLOAT64_C(  568.03), SIMDE_FLOAT64_C( -985.31)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -336.00), SIMDE_FLOAT64_C( -139.33),
                         SIMDE_FLOAT64_C(  617.24), SIMDE_FLOAT64_C(  953.30)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -274.93), SIMDE_FLOAT64_C( -900.75),
                         SIMDE_FLOAT64_C( -102.71), SIMDE_FLOAT64_C( -472.84)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -901.78), SIMDE_FLOAT64_C(   12.36),
                         SIMDE_FLOAT64_C(  689.29), SIMDE_FLOAT64_C( -976.30)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  995.09), SIMDE_FLOAT64_C( -313.13),
                         SIMDE_FLOAT64_C( -440.17), SIMDE_FLOAT64_C(  189.57)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  355.51), SIMDE_FLOAT64_C( -932.21),
                         SIMDE_FLOAT64_C( -616.46), SIMDE_FLOAT64_C( -552.77)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -528.18), SIMDE_FLOAT64_C(   45.66),
                         SIMDE_FLOAT64_C(  363.59), SIMDE_FLOAT64_C(  611.34)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -921.78), SIMDE_FLOAT64_C(  818.71),
                         SIMDE_FLOAT64_C( -177.51), SIMDE_FLOAT64_C(  690.85)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -323.41), SIMDE_FLOAT64_C( -699.06),
                         SIMDE_FLOAT64_C( -250.77), SIMDE_FLOAT64_C(  136.95)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  793.97), SIMDE_FLOAT64_C( -124.81),
                         SIMDE_FLOAT64_C( -222.21), SIMDE_FLOAT64_C(    0.47)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  499.90), SIMDE_FLOAT64_C(   53.18),
                         SIMDE_FLOAT64_C(  122.29), SIMDE_FLOAT64_C( -348.92)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  656.41), SIMDE_FLOAT64_C(  401.79),
                         SIMDE_FLOAT64_C(  913.30), SIMDE_FLOAT64_C(  939.03)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testz_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testz_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C( 6293711937966483210), INT64_C( 1880458700636896550),
                             INT64_C(-2395812271494697349), INT64_C(-3219984426865676065)),
      simde_mm256_set_epi64x(INT64_C(-5944145716236985819), INT64_C( 3393778583556144207),
                             INT64_C(-7902030010445655740), INT64_C( 1343831900549571141)),
      0 },
    { simde_mm256_set_epi64x(INT64_C(-4587433109256837328), INT64_C( 4600839100559586303),
                             INT64_C(-4228750003309626741), INT64_C( 8478339671631213897)),
      simde_mm256_set_epi64x(INT64_C(-2398862596123305272), INT64_C( -195553556197471185),
                             INT64_C(-1163267556607256299), INT64_C( 8724663478814299088)),
      0 },
    { simde_mm256_set_epi64x(INT64_C( 6318565256204443110), INT64_C( 8197829483289572776),
                             INT64_C(-5241286122396602839), INT64_C( 8034039929823396869)),
      simde_mm256_set_epi64x(INT64_C( 2316518055936499365), INT64_C(-3827103871459261221),
                             INT64_C(-1074153741299789825), INT64_C(-5706377024354090462)),
      0 },
    { simde_mm256_set_epi64x(INT64_C( 6337382312890404250), INT64_C( 1040004396151504333),
                             INT64_C(-6858337698693557354), INT64_C(-3290810792006167916)),
      simde_mm256_set_epi64x(INT64_C(-5980280665599952377), INT64_C(-4826455948616871632),
                             INT64_C( 3955163730046162798), INT64_C(-5561662165703631134)),
      0 },
    { simde_mm256_set_epi64x(INT64_C(-3638435057324933583), INT64_C(-9111798730377633063),
                             INT64_C(-2892856737256268180), INT64_C( 4241350171537373665)),
      simde_mm256_set_epi64x(INT64_C(-1517017303777947826), INT64_C( 1106019512787868766),
                             INT64_C(-4154459162475494220), INT64_C( 2458562407439632505)),
      0 },
    { simde_mm256_set_epi64x(INT64_C(-8613849652924649480), INT64_C( 4502213447815150777),
                             INT64_C(  964826197151294912), INT64_C(-2062422363128377394)),
      simde_mm256_set_epi64x(INT64_C(  420430988932892588), INT64_C( 7089052628145876495),
                             INT64_C(  964826197151294912), INT64_C(-2062422363128377394)),
      0 },
    { simde_mm256_set_epi64x(INT64_C( 2313467387214959309), INT64_C( 1954089676203891706),
                             INT64_C(-5992642054331042599), INT64_C( 2987244174038246250)),
      simde_mm256_set_epi64x(~INT64_C( 2313467387214959309), ~INT64_C( 1954089676203891706),
                             ~INT64_C(-5992642054331042599), ~INT64_C( 2987244174038246250)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testz_si256(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testnzc_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128 a;
    simde__m128 b;
    int r;
  } test_vec[8] = {
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -677.80), SIMDE_FLOAT32_C(  923.51), SIMDE_FLOAT32_C(   12.34), SIMDE_FLOAT32_C(  570.37)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -986.13), SIMDE_FLOAT32_C(  240.32), SIMDE_FLOAT32_C(  591.49), SIMDE_FLOAT32_C(  161.31)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -901.76), SIMDE_FLOAT32_C( -346.47), SIMDE_FLOAT32_C(  361.48), SIMDE_FLOAT32_C(  579.94)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(   37.29), SIMDE_FLOAT32_C(  138.07), SIMDE_FLOAT32_C(  -20.49), SIMDE_FLOAT32_C(  183.91)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -126.05), SIMDE_FLOAT32_C( -737.54), SIMDE_FLOAT32_C(  797.63), SIMDE_FLOAT32_C(  -91.26)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  622.90), SIMDE_FLOAT32_C(  921.88), SIMDE_FLOAT32_C( -199.46), SIMDE_FLOAT32_C( -960.51)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -724.79), SIMDE_FLOAT32_C(  401.73), SIMDE_FLOAT32_C(  459.33), SIMDE_FLOAT32_C( -257.11)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -483.83), SIMDE_FLOAT32_C( -357.19), SIMDE_FLOAT32_C(  660.48), SIMDE_FLOAT32_C( -967.49)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  987.08), SIMDE_FLOAT32_C(  -85.77), SIMDE_FLOAT32_C(  750.67), SIMDE_FLOAT32_C( -384.35)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -846.85), SIMDE_FLOAT32_C(  171.98), SIMDE_FLOAT32_C(   38.30), SIMDE_FLOAT32_C( -999.02)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C( -535.41), SIMDE_FLOAT32_C(  674.36), SIMDE_FLOAT32_C(  853.75), SIMDE_FLOAT32_C(  423.18)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  436.68), SIMDE_FLOAT32_C( -556.22), SIMDE_FLOAT32_C( -733.91), SIMDE_FLOAT32_C( -508.00)),
      0 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(   87.42), SIMDE_FLOAT32_C(  -99.53), SIMDE_FLOAT32_C( -449.18), SIMDE_FLOAT32_C(  694.82)),
      simde_mm_set_ps(SIMDE_FLOAT32_C( -853.63), SIMDE_FLOAT32_C( -112.00), SIMDE_FLOAT32_C(   87.42), SIMDE_FLOAT32_C(  -97.80)),
      1 },
    { simde_mm_set_ps(SIMDE_FLOAT32_C(  342.14), SIMDE_FLOAT32_C(  347.96), SIMDE_FLOAT32_C( -638.14), SIMDE_FLOAT32_C( -357.36)),
      simde_mm_set_ps(SIMDE_FLOAT32_C(  103.59), SIMDE_FLOAT32_C(  685.51), SIMDE_FLOAT32_C(   13.48), SIMDE_FLOAT32_C(  108.92)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testnzc_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm_testnzc_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m128d a;
    simde__m128d b;
    int r;
  } test_vec[8] = {
   { simde_mm_set_pd(SIMDE_FLOAT64_C( -120.11), SIMDE_FLOAT64_C(  530.28)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -886.61), SIMDE_FLOAT64_C(  297.97)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  660.15), SIMDE_FLOAT64_C(  462.46)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  753.92), SIMDE_FLOAT64_C( -475.11)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  195.21), SIMDE_FLOAT64_C(  577.36)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  977.83), SIMDE_FLOAT64_C(  562.50)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  184.20), SIMDE_FLOAT64_C( -531.42)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -597.14), SIMDE_FLOAT64_C(   63.31)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  591.68), SIMDE_FLOAT64_C( -753.83)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(   42.69), SIMDE_FLOAT64_C( -626.35)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  799.46), SIMDE_FLOAT64_C(  415.70)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -755.76), SIMDE_FLOAT64_C( -637.19)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  708.86), SIMDE_FLOAT64_C( -480.39)),
      simde_mm_set_pd(SIMDE_FLOAT64_C(  417.06), SIMDE_FLOAT64_C( -687.07)),
      0 },
    { simde_mm_set_pd(SIMDE_FLOAT64_C(  -48.08), SIMDE_FLOAT64_C(  617.37)),
      simde_mm_set_pd(SIMDE_FLOAT64_C( -937.79), SIMDE_FLOAT64_C( -565.45)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm_testnzc_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testnzc_ps(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256 a;
    simde__m256 b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  583.89), SIMDE_FLOAT32_C( -712.24),
                         SIMDE_FLOAT32_C( -125.89), SIMDE_FLOAT32_C(  188.79),
                         SIMDE_FLOAT32_C(  520.73), SIMDE_FLOAT32_C(  -68.12),
                         SIMDE_FLOAT32_C(  822.52), SIMDE_FLOAT32_C( -595.06)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  671.97), SIMDE_FLOAT32_C(  390.57),
                         SIMDE_FLOAT32_C( -318.49), SIMDE_FLOAT32_C( -885.66),
                         SIMDE_FLOAT32_C( -314.30), SIMDE_FLOAT32_C( -285.04),
                         SIMDE_FLOAT32_C( -162.81), SIMDE_FLOAT32_C( -410.54)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -820.54), SIMDE_FLOAT32_C( -790.46),
                         SIMDE_FLOAT32_C(  711.91), SIMDE_FLOAT32_C(  907.30),
                         SIMDE_FLOAT32_C( -112.02), SIMDE_FLOAT32_C(  599.13),
                         SIMDE_FLOAT32_C(  409.13), SIMDE_FLOAT32_C( -352.81)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  176.49), SIMDE_FLOAT32_C(  775.58),
                         SIMDE_FLOAT32_C(  -44.34), SIMDE_FLOAT32_C( -968.49),
                         SIMDE_FLOAT32_C(   67.85), SIMDE_FLOAT32_C(  437.32),
                         SIMDE_FLOAT32_C( -839.45), SIMDE_FLOAT32_C( -726.44)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  967.58), SIMDE_FLOAT32_C( -926.13),
                         SIMDE_FLOAT32_C( -667.55), SIMDE_FLOAT32_C(  983.87),
                         SIMDE_FLOAT32_C(  566.68), SIMDE_FLOAT32_C(  720.39),
                         SIMDE_FLOAT32_C(   81.27), SIMDE_FLOAT32_C( -180.83)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -556.40), SIMDE_FLOAT32_C(   58.13),
                         SIMDE_FLOAT32_C( -255.30), SIMDE_FLOAT32_C( -733.19),
                         SIMDE_FLOAT32_C(  141.91), SIMDE_FLOAT32_C(   83.86),
                         SIMDE_FLOAT32_C(  265.25), SIMDE_FLOAT32_C(  380.17)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -290.71), SIMDE_FLOAT32_C( -838.97),
                         SIMDE_FLOAT32_C(  -21.50), SIMDE_FLOAT32_C(  222.89),
                         SIMDE_FLOAT32_C(  710.43), SIMDE_FLOAT32_C( -683.80),
                         SIMDE_FLOAT32_C( -751.33), SIMDE_FLOAT32_C(  356.34)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  328.43), SIMDE_FLOAT32_C(  897.92),
                         SIMDE_FLOAT32_C( -115.62), SIMDE_FLOAT32_C(  410.36),
                         SIMDE_FLOAT32_C(  613.67), SIMDE_FLOAT32_C( -980.39),
                         SIMDE_FLOAT32_C(  791.41), SIMDE_FLOAT32_C(  271.47)),
      0 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C(  -54.57), SIMDE_FLOAT32_C(  595.88),
                         SIMDE_FLOAT32_C(   92.56), SIMDE_FLOAT32_C(  -69.35),
                         SIMDE_FLOAT32_C(  525.25), SIMDE_FLOAT32_C(  150.31),
                         SIMDE_FLOAT32_C(  507.37), SIMDE_FLOAT32_C(  171.79)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -147.77), SIMDE_FLOAT32_C(  635.99),
                         SIMDE_FLOAT32_C(  922.13), SIMDE_FLOAT32_C( -150.43),
                         SIMDE_FLOAT32_C( -599.09), SIMDE_FLOAT32_C(  969.81),
                         SIMDE_FLOAT32_C(  -52.12), SIMDE_FLOAT32_C(  931.26)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -925.77), SIMDE_FLOAT32_C( -819.13),
                         SIMDE_FLOAT32_C( -387.03), SIMDE_FLOAT32_C(  369.31),
                         SIMDE_FLOAT32_C(  816.32), SIMDE_FLOAT32_C( -110.60),
                         SIMDE_FLOAT32_C(  155.71), SIMDE_FLOAT32_C( -467.73)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C( -249.07), SIMDE_FLOAT32_C(  262.13),
                         SIMDE_FLOAT32_C( -955.31), SIMDE_FLOAT32_C( -680.63),
                         SIMDE_FLOAT32_C( -662.36), SIMDE_FLOAT32_C(   38.93),
                         SIMDE_FLOAT32_C(  136.68), SIMDE_FLOAT32_C(  432.80)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -753.72), SIMDE_FLOAT32_C(  933.35),
                         SIMDE_FLOAT32_C(  780.23), SIMDE_FLOAT32_C(  299.81),
                         SIMDE_FLOAT32_C( -790.25), SIMDE_FLOAT32_C(  868.49),
                         SIMDE_FLOAT32_C( -966.55), SIMDE_FLOAT32_C( -856.58)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  584.14), SIMDE_FLOAT32_C( -395.66),
                         SIMDE_FLOAT32_C( -690.53), SIMDE_FLOAT32_C( -230.79),
                         SIMDE_FLOAT32_C( -409.16), SIMDE_FLOAT32_C( -954.27),
                         SIMDE_FLOAT32_C( -286.31), SIMDE_FLOAT32_C(  -72.81)),
      1 },
    { simde_mm256_set_ps(SIMDE_FLOAT32_C( -458.63), SIMDE_FLOAT32_C( -211.79),
                         SIMDE_FLOAT32_C(  179.21), SIMDE_FLOAT32_C( -282.23),
                         SIMDE_FLOAT32_C(  901.33), SIMDE_FLOAT32_C(  545.46),
                         SIMDE_FLOAT32_C(  300.44), SIMDE_FLOAT32_C(  545.25)),
      simde_mm256_set_ps(SIMDE_FLOAT32_C(  816.92), SIMDE_FLOAT32_C( -195.51),
                         SIMDE_FLOAT32_C( -422.20), SIMDE_FLOAT32_C(  587.24),
                         SIMDE_FLOAT32_C(  -85.60), SIMDE_FLOAT32_C(  249.83),
                         SIMDE_FLOAT32_C( -348.91), SIMDE_FLOAT32_C(  259.84)),
      1 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testnzc_ps(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testnzc_pd(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256d a;
    simde__m256d b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -740.05), SIMDE_FLOAT64_C( -803.89),
                         SIMDE_FLOAT64_C( -738.69), SIMDE_FLOAT64_C( -907.97)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -601.20), SIMDE_FLOAT64_C(  873.56),
                         SIMDE_FLOAT64_C( -427.28), SIMDE_FLOAT64_C( -539.59)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -679.84), SIMDE_FLOAT64_C(  334.20),
                         SIMDE_FLOAT64_C(  374.46), SIMDE_FLOAT64_C(  -17.90)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  933.19), SIMDE_FLOAT64_C(  255.92),
                         SIMDE_FLOAT64_C( -527.33), SIMDE_FLOAT64_C(  651.28)),
      0 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -960.47), SIMDE_FLOAT64_C(   47.50),
                         SIMDE_FLOAT64_C(  839.01), SIMDE_FLOAT64_C( -388.45)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -230.23), SIMDE_FLOAT64_C( -286.70),
                         SIMDE_FLOAT64_C( -578.79), SIMDE_FLOAT64_C(  287.52)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -128.67), SIMDE_FLOAT64_C( -282.41),
                         SIMDE_FLOAT64_C( -741.53), SIMDE_FLOAT64_C(  405.60)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -927.14), SIMDE_FLOAT64_C( -105.58),
                         SIMDE_FLOAT64_C( -674.42), SIMDE_FLOAT64_C( -434.93)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  469.51), SIMDE_FLOAT64_C( -726.27),
                         SIMDE_FLOAT64_C(  -57.54), SIMDE_FLOAT64_C(   10.85)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -629.68), SIMDE_FLOAT64_C(  193.64),
                         SIMDE_FLOAT64_C( -188.44), SIMDE_FLOAT64_C( -942.28)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C(  717.44), SIMDE_FLOAT64_C( -428.23),
                         SIMDE_FLOAT64_C( -903.34), SIMDE_FLOAT64_C(  963.44)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -806.29), SIMDE_FLOAT64_C(  928.14),
                         SIMDE_FLOAT64_C( -419.31), SIMDE_FLOAT64_C( -536.05)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -682.64), SIMDE_FLOAT64_C(  364.27),
                         SIMDE_FLOAT64_C(  -11.12), SIMDE_FLOAT64_C(  923.42)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C( -496.96), SIMDE_FLOAT64_C( -698.68),
                         SIMDE_FLOAT64_C(  762.99), SIMDE_FLOAT64_C(  104.59)),
      1 },
    { simde_mm256_set_pd(SIMDE_FLOAT64_C( -867.55), SIMDE_FLOAT64_C(  263.90),
                         SIMDE_FLOAT64_C( -169.35), SIMDE_FLOAT64_C(  237.91)),
      simde_mm256_set_pd(SIMDE_FLOAT64_C(  768.02), SIMDE_FLOAT64_C(  326.08),
                         SIMDE_FLOAT64_C(  577.75), SIMDE_FLOAT64_C( -405.14)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testnzc_pd(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_mm256_testnzc_si256(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde__m256i a;
    simde__m256i b;
    int r;
  } test_vec[8] = {
    { simde_mm256_set_epi64x(INT64_C(-6804708873655136040), INT64_C( 4446918229480945172),
                             INT64_C(-6458803806102185271), INT64_C( 6419639704555297719)),
      simde_mm256_set_epi64x(INT64_C( 4086527184939990173), INT64_C(-4592254743728630867),
                             INT64_C( 4970594815150486048), INT64_C(-7583682924010349946)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(-1928057325376684019), INT64_C(-8724716645086732256),
                             INT64_C(-3860992505389240967), INT64_C( 2464414912339664108)),
      simde_mm256_set_epi64x(INT64_C( 2743122637609340204), INT64_C( 1297961604072261704),
                             INT64_C( 3905148821277274727), INT64_C( 7711768841031320482)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(-1757300674109662463), INT64_C( 3540874093748815164),
                             INT64_C( 6199345139492343278), INT64_C(-2392213781376855007)),
      simde_mm256_set_epi64x(INT64_C( 3074780231229279065), INT64_C( 3565435212917289013),
                             INT64_C( 4586940771077894472), INT64_C(-7584245251433225890)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(  494161565528569426), INT64_C( 6322507550162055397),
                             INT64_C(-5323201274204502385), INT64_C(-1289213418743081892)),
      simde_mm256_set_epi64x(INT64_C(-6476107628412075124), INT64_C(-6021204385531569231),
                             INT64_C(-1583794509252285729), INT64_C( 3089826828243401077)),
      1 },
    { simde_mm256_set_epi64x(INT64_C( 8385406147133094169), INT64_C( 8814670790512562044),
                             INT64_C(-3816462967170746071), INT64_C( 6122654749309721394)),
      simde_mm256_set_epi64x(INT64_C( 3128481605987261169), INT64_C( 5408589980237811609),
                             INT64_C(  884520455099049673), INT64_C( 8133398980467634343)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(-8329161804206964235), INT64_C(  636927422382767873),
                             INT64_C( 3009146061842021624), INT64_C(-1851032033415757843)),
      simde_mm256_set_epi64x(INT64_C( 6472691381239458493), INT64_C( -333790812247230429),
                             INT64_C(-8827165560999629213), INT64_C(-6808896659071721867)),
      1 },
    { simde_mm256_set_epi64x(INT64_C( 6104921182164936438), INT64_C(-1838247589228581946),
                             INT64_C( 4047419838992777892), INT64_C(-7001360392396553117)),
      simde_mm256_set_epi64x(INT64_C( 5238813195851712113), INT64_C( -198251833482699615),
                             INT64_C(-2396015894110422309), INT64_C(-6041072787160554283)),
      1 },
    { simde_mm256_set_epi64x(INT64_C(                  -1), INT64_C(                  -1),
                             INT64_C(                  -1), INT64_C(                  -1)),
      simde_mm256_set_epi64x(INT64_C(                   0), INT64_C(                   0),
                             INT64_C(                   0), INT64_C(                   0)),
      0 }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    int r = simde_mm256_testnzc_si256(test_vec[i].a, test_vec[i].b);
    munit_assert_int(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

#endif /* !defined(SIMDE_X86_AVX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

#if HEDLEY_HAS_WARNING("-Wold-style-cast")
  #pragma clang diagnostic ignored "-Wold-style-cast"
#endif
#if HEDLEY_HAS_WARNING("-Wzero-as-null-pointer-constant")
  #pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"
#endif

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_X86_AVX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_DEFINE_TEST(mm256_set_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_epi64x),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_m128),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_m128i),
  SIMDE_TESTS_DEFINE_TEST(mm256_set_m128d),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_epi64x),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_set1_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_add_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_add_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_addsub_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_addsub_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_and_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_and_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_andnot_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_andnot_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_blend_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_blend_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_blendv_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_blendv_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_broadcast_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_broadcast_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_broadcast_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_broadcast_ss),
  SIMDE_TESTS_DEFINE_TEST(mm256_broadcast_ss),

  SIMDE_TESTS_DEFINE_TEST(mm256_castpd128_pd256),
  SIMDE_TESTS_DEFINE_TEST(mm256_castpd256_pd128),
  SIMDE_TESTS_DEFINE_TEST(mm256_castps_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_castpd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_castps128_ps256),
  SIMDE_TESTS_DEFINE_TEST(mm256_castps256_ps128),
  SIMDE_TESTS_DEFINE_TEST(mm256_castsi128_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_castsi256_si128),
  SIMDE_TESTS_DEFINE_TEST(mm256_castps_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_castpd_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_castsi256_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_castsi256_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_ceil_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_ceil_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_cmp_sd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmp_ss),
  SIMDE_TESTS_DEFINE_TEST(mm_cmp_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_cmp_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmp_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_cmp_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi32_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtepi32_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtpd_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtpd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtps_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvtps_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvttpd_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_cvttps_epi32),

  SIMDE_TESTS_DEFINE_TEST(mm256_div_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_div_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_dp_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_extract_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_extract_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_extractf128_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_extractf128_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_extractf128_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_floor_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_floor_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_hadd_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_hadd_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_hsub_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_hsub_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_insert_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_insert_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_insert_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_insert_epi64),
  SIMDE_TESTS_DEFINE_TEST(mm256_insertf128_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_insertf128_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_insertf128_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_lddqu_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_load_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_load_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_load_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu2_m128),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu2_m128d),
  SIMDE_TESTS_DEFINE_TEST(mm256_loadu2_m128i),

  SIMDE_TESTS_DEFINE_TEST(mm_maskload_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskload_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_maskload_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskload_ps),

  SIMDE_TESTS_DEFINE_TEST(mm_maskstore_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskstore_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_maskstore_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_maskstore_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_min_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_min_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_max_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_movedup_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_movehdup_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_moveldup_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_movemask_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_movemask_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_mul_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_mul_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_or_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_or_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_permute_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_permute_pd),
  SIMDE_TESTS_DEFINE_TEST(mm_permute_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_permute_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_permutevar_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_permutevar_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_permutevar_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_permutevar_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_permute2f128_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_rcp_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_round_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_round_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_rsqrt_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_setr_epi8),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_epi16),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_epi32),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_epi64x),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_m128),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_m128d),
  SIMDE_TESTS_DEFINE_TEST(mm256_setr_m128i),

  SIMDE_TESTS_DEFINE_TEST(mm256_setzero_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_setzero_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_setzero_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_shuffle_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_shuffle_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_sqrt_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_sqrt_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_store_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_store_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_store_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu_si256),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu2_m128),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu2_m128d),
  SIMDE_TESTS_DEFINE_TEST(mm256_storeu2_m128i),
  SIMDE_TESTS_DEFINE_TEST(mm256_stream_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_stream_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_stream_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_sub_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_sub_pd),

  SIMDE_TESTS_DEFINE_TEST(mm_testc_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_testc_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testc_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_testc_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testc_si256),
  SIMDE_TESTS_DEFINE_TEST(mm_testz_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_testz_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testz_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_testz_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testz_si256),
  SIMDE_TESTS_DEFINE_TEST(mm_testnzc_ps),
  SIMDE_TESTS_DEFINE_TEST(mm_testnzc_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testnzc_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_testnzc_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_testnzc_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_undefined_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_undefined_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_undefined_si256),

  SIMDE_TESTS_DEFINE_TEST(mm256_unpackhi_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_unpackhi_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_unpacklo_ps),
  SIMDE_TESTS_DEFINE_TEST(mm256_unpacklo_pd),

  SIMDE_TESTS_DEFINE_TEST(mm256_xor_pd),
  SIMDE_TESTS_DEFINE_TEST(mm256_xor_ps),

  SIMDE_TESTS_DEFINE_TEST(mm256_zextps128_ps256),
  SIMDE_TESTS_DEFINE_TEST(mm256_zextpd128_pd256),
  SIMDE_TESTS_DEFINE_TEST(mm256_zextsi128_si256),
#endif /* !defined(SIMDE_X86_AVX_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(suite)(void) {
  static MunitSuite suite = { (char*) "/" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_ISAX), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

#if defined(SIMDE_TESTS_SINGLE_ISAX)
int main(int argc, char* argv[HEDLEY_ARRAY_PARAM(argc + 1)]) {
  static MunitSuite suite = { "", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
#endif /* defined(SIMDE_TESTS_SINGLE_ISAX) */

HEDLEY_DIAGNOSTIC_POP
