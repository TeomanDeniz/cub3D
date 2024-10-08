/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeniz <Discord:@teomandeniz>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:17:45 by hdeniz            #+#    #+#             */
/*   Updated: 2024/05/06 04:05:21 by hdeniz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H 202405

/* Constants */
# ifndef M_E
#  define M_E 2.71828182845904523536 // Euler's Number
# endif
# ifndef M_LOG2E
#  define M_LOG2E 1.44269504088896340736 // log2(e)
# endif
# ifndef M_LOG10E
#  define M_LOG10E 0.43429448190325182765 // log10(e)
# endif
# ifndef M_LN2
#  define M_LN2 0.69314718055994528623 // ln(2)
# endif
# ifndef M_LN10
#  define M_LN10 2.30258509299404568402 // ln(10)
# endif
# ifndef M_PIX2
#  define M_PIX2 6.28318530717958647692 // PI * 2
# endif
# ifndef M_PIX2_3
#  define M_PIX2_3 4.71238898038400589261 // PI * 2 / 3
# endif
# ifndef M_PI
#  define M_PI 3.14159265358979323846 // PI
# endif
# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923 // PI / 2
# endif
# ifndef M_PI_4
#  define M_PI_4 0.78539816339744830961 // PI / 4
# endif
# ifndef M_1_PI
#  define M_1_PI 0.31830988618379067153 // 1 / PI
# endif
# ifndef M_2_PI
#  define M_2_PI 0.63661977236758134307 // 2 / PI
# endif
# ifndef M_SQRT2
#  define M_SQRT2 1.41421356237309504880 // sqrt(2)
# endif
# ifndef M_SQRT1_2
#  define M_SQRT1_2 0.70710678118654752440 // 1 / sqrt(2)
# endif
# ifndef M_SQRTPI
#  define M_SQRTPI 1.77245385090551588191 // sqrt(PI)
# endif
# ifndef M_2_SQRTPI
#  define M_2_SQRTPI 1.12837916709551257390 // 2 / sqrt(PI)
# endif
# ifndef M_INVSQRTPI
#  define M_INVSQRTPI 0.56418958354775627928 // invsqrt(PI)
# endif
# ifndef M_TPI
#  define M_TPI 0.63661977236758138243 // 2 / PI
# endif
/* Constants */

/* <float.h> Constants */

/* Limits of float type */
# ifndef FLT_MAX
#  define FLT_MAX 3.40282347E+38F
# endif
# ifndef FLT_MIN
#  define FLT_MIN 1.17549435E-38F
# endif
# ifndef FLT_EPSILON
#  define FLT_EPSILON 1.19209290E-7F
# endif
/* Limits of float type */

/* Limits of double type */
# ifndef DBL_MAX
#  define DBL_MAX 1.7976931348623158E+308
# endif
# ifndef DBL_MIN
#  define DBL_MIN 2.2250738585072014E-308
# endif
# ifndef DBL_EPSILON
#  define DBL_EPSILON 2.2204460492503131E-16
# endif
/* Limits of double type */

/* Limits of long double type */
# ifndef LDBL_MAX
#  define LDBL_MAX 1.18973149535723176502E+4932L
# endif
# ifndef LDBL_MIN
#  define LDBL_MIN 3.36210314311209350626E-4932L
# endif
# ifndef LDBL_EPSILON
#  define LDBL_EPSILON 1.08420217248550443401E-19L
# endif
/* Limits of long double type */

/* Constants (Float) */
# ifndef M_E_F
#  define M_E_F 2.71828182845904523536F // Euler's Number
# endif
# ifndef M_LOG2E_F
#  define M_LOG2E_F 1.44269504088896340736F // log2(e)
# endif
# ifndef M_LOG10E_F
#  define M_LOG10E_F 0.43429448190325182765F // log10(e)
# endif
# ifndef M_LN2_F
#  define M_LN2_F 0.69314718055994528623F // ln(2)
# endif
# ifndef M_LN10_F
#  define M_LN10_F 2.30258509299404568402F // ln(10)
# endif
# ifndef M_PIX2_F
#  define M_PIX2_F 6.28318530717958647692F // PI * 2
# endif
# ifndef M_PIX2_3_F
#  define M_PIX2_3_F 4.71238898038400589261F // PI * 2 / 3
# endif
# ifndef M_PI_F
#  define M_PI_F   3.14159265358979323846F // PI
# endif
# ifndef M_PI_2_F
#  define M_PI_2_F 1.57079632679489661923F // PI / 2
# endif
# ifndef M_PI_4_F
#  define M_PI_4_F 0.78539816339744830961F // PI / 4
# endif
# ifndef M_1_PI_F
#  define M_1_PI_F 0.31830988618379067153F // 1 / PI
# endif
# ifndef M_2_PI_F
#  define M_2_PI_F 0.63661977236758134307F // 2 / PI
# endif
# ifndef M_SQRT2_F
#  define M_SQRT2_F 1.41421356237309504880F // sqrt(2)
# endif
# ifndef M_SQRT1_2_F
#  define M_SQRT1_2_F 0.70710678118654752440F // 1 / sqrt(2)
# endif
# ifndef M_SQRTPI_F
#  define M_SQRTPI_F 1.77245385090551588191F // sqrt(PI)
# endif
# ifndef M_2_SQRTPI_F
#  define M_2_SQRTPI_F 1.12837916709551257390F // 2 / sqrt(PI)
# endif
# ifndef M_INVSQRTPI_F
#  define M_INVSQRTPI_F 0.56418958354775627928F // invsqrt(PI)
# endif
# ifndef M_TPI_F
#  define M_TPI_F 0.63661977236758138243F // 2 / PI
# endif
/* Constants (Float) */

typedef union s_cast
{
	const char			*ptr;
	unsigned long long	integer;
}	t_cast;

/* Trigonometric functions */
/* [Float] */
extern float	ft_sinf(float x);
extern float	ft_cosf(register float x);
extern float	ft_tanf(register float x);
/* [Float] */
/* Trigonometric functions */

/* Rounding and Remainder functions */
/* [Float] */
extern float	ft_floorf(float x);
extern float	ft_fmodf(float x, float y);
/* [Float] */
/* Rounding and Remainder functions */

/* Floating-point Classification functions */
extern int		ft_isinf(register double x);
extern int		ft_isnan(double x);
/* Floating-point Classification functions */

/* Power functions */
/* [Float] */
extern float	ft_sqrtf(register float x);
/* [Float] */
/* Power functions */

/* Other functions */
extern int		ft_imax(int a, int b);
extern int		ft_rand(register int min, register int max);
/* [Float] */
extern float	ft_fabsf(float x);
extern float	ft_fminf(float x, float y);
extern float	ft_lerpf(float x, float y, float f);
/* [Float] */
/* Other functions */

#endif /* FT_MATH_H */
