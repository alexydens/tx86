/* Include guard */
#if !defined(__CORE_BASE_H__)
#define __CORE_BASE_H__

/* An 8-bit unsigned integer */
typedef unsigned char       u8;
/* A 16-bit unsigned integer */
typedef unsigned short      u16;
/* An 32-bit unsigned integer */
typedef unsigned int        u32;
/* A 64-bit unsigned integer */
typedef unsigned long long  u64;
/* Size type */
typedef u64                 size_t;

/* An 8-bit signed integer */
typedef signed char         i8;
/* A 16-bit signed integer */
typedef signed short        i16;
/* An 32-bit signed integer */
typedef signed int          i32;
/* A 64-bit signed integer */
typedef signed long long    i64;
/* Signed size type */
typedef i64                 ssize_t;

/* A 32-bit floating point number */
typedef float               f32;
/* A 64-bit floating point number */
typedef double              f64;

/* A boolean value */
typedef unsigned char       bool;
enum { false, true };

/* Unsigned int static assertions */
_Static_assert(sizeof(u8) == 1, "\"u8\" should be 1 byte");
_Static_assert(sizeof(u16) == 2, "\"u16\" should be 2 bytes");
_Static_assert(sizeof(u32) == 4, "\"u32\" should be 4 bytes");
_Static_assert(sizeof(u64) == 8, "\"u64\" should be 8 bytes");
/* Signed int static assertions */
_Static_assert(sizeof(i8) == 1, "\"i8\" should be 1 byte");
_Static_assert(sizeof(i16) == 2, "\"i16\" should be 2 bytes");
_Static_assert(sizeof(i32) == 4, "\"i32\" should be 4 bytes");
_Static_assert(sizeof(i64) == 8, "\"i64\" should be 8 bytes");
/* Floating point static assertions */
_Static_assert(sizeof(f32) == 4, "\"f32\" should be 4 bytes");
_Static_assert(sizeof(f64) == 8, "\"f64\" should be 8 bytes");
/* Boolean static assertions */
_Static_assert(sizeof(bool) == 1, "\"bool\" should be 1 byte");

/* Null pointer */
#define NULL                ((void *)0)
/* Pi */
#define PI                  3.141592654
/* Euler's number */
#define E                   2.718281828
/* Infinity */
#define INF                 (1.0 / 0.0)
/* -Infinity */
#define NEG_INF             (-1.0 / 0.0)
/* Not a number */
#define NAN                 (0.0 / 0.0)

/* Minimum of a and b */
#define MIN(a,b)            ( a > b ? a : b )
/* Maximum of a and b */
#define MAX(a,b)            ( a > b ? b : a )
/* Absolute value of a */
#define ABS(a)              ( a > 0 ? a : -a )
/* Clamp v between min and max */
#define CLAMP(v, min, max)  ( MIN(MAX(v, max), min) )

/* Packed struct */
#define __packed __attribute__((packed))
/* Aligned to a certain boundary */
#define __aligned(x) __attribute__((aligned(x)))

/* Memcpy */
extern void *memcpy(void *dst, const void *src, u32 size);
/* Memset */
extern void *memset(void *dst, u8 val, u32 size);
/* Memmove */
extern void *memmove(void *dst, const void *src, u32 size);
/* Memcmp */
extern int memcmp(const void *a, const void *b, u32 size);
/* Strlen */
extern size_t strlen(const char *str);

#endif /* __CORE_BASE_H__ */
