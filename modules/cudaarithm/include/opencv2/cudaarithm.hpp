/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef __OPENCV_CUDAARITHM_HPP__
#define __OPENCV_CUDAARITHM_HPP__

#ifndef __cplusplus
#  error cudaarithm.hpp header must be compiled as C++
#endif

#include "opencv2/core/cuda.hpp"

/**
  @addtogroup cuda
  @{
    @defgroup cudaarithm Operations on Matrices
    @{
        @defgroup cudaarithm_core Core Operations on Matrices
        @defgroup cudaarithm_elem Per-element Operations
        @defgroup cudaarithm_reduce Matrix Reductions
        @defgroup cudaarithm_arithm Arithm Operations on Matrices
    @}
  @}
 */

namespace cv { namespace cuda {

//! @addtogroup cudaarithm
//! @{

//! @addtogroup cudaarithm_elem
//! @{

/** @brief Computes a matrix-matrix or matrix-scalar sum.

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar. Matrix should have the same size and type as src1 .
@param dst Destination matrix that has the same size and number of channels as the input array(s).
The depth is defined by dtype or src1 depth.
@param mask Optional operation mask, 8-bit single channel array, that specifies elements of the
destination array to be changed.
@param dtype Optional depth of the output array.
@param stream Stream for the asynchronous version.

@sa add
 */
CV_EXPORTS void add(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), int dtype = -1, Stream& stream = Stream::Null());

/** @brief Computes a matrix-matrix or matrix-scalar difference.

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar. Matrix should have the same size and type as src1 .
@param dst Destination matrix that has the same size and number of channels as the input array(s).
The depth is defined by dtype or src1 depth.
@param mask Optional operation mask, 8-bit single channel array, that specifies elements of the
destination array to be changed.
@param dtype Optional depth of the output array.
@param stream Stream for the asynchronous version.

@sa subtract
 */
CV_EXPORTS void subtract(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), int dtype = -1, Stream& stream = Stream::Null());

/** @brief Computes a matrix-matrix or matrix-scalar per-element product.

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and number of channels as the input array(s).
The depth is defined by dtype or src1 depth.
@param scale Optional scale factor.
@param dtype Optional depth of the output array.
@param stream Stream for the asynchronous version.

@sa multiply
 */
CV_EXPORTS void multiply(InputArray src1, InputArray src2, OutputArray dst, double scale = 1, int dtype = -1, Stream& stream = Stream::Null());

/** @brief Computes a matrix-matrix or matrix-scalar division.

@param src1 First source matrix or a scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and number of channels as the input array(s).
The depth is defined by dtype or src1 depth.
@param scale Optional scale factor.
@param dtype Optional depth of the output array.
@param stream Stream for the asynchronous version.

This function, in contrast to divide, uses a round-down rounding mode.

@sa divide
 */
CV_EXPORTS void divide(InputArray src1, InputArray src2, OutputArray dst, double scale = 1, int dtype = -1, Stream& stream = Stream::Null());

//! computes element-wise weighted reciprocal of an array (dst = scale/src2)
static inline void divide(double src1, InputArray src2, OutputArray dst, int dtype = -1, Stream& stream = Stream::Null())
{
    divide(src1, src2, dst, 1.0, dtype, stream);
}

/** @brief Computes per-element absolute difference of two matrices (or of a matrix and scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param stream Stream for the asynchronous version.

@sa absdiff
 */
CV_EXPORTS void absdiff(InputArray src1, InputArray src2, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes an absolute value of each matrix element.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.

@sa abs
 */
CV_EXPORTS void abs(InputArray src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes a square value of each matrix element.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void sqr(InputArray src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes a square root of each matrix element.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.

@sa sqrt
 */
CV_EXPORTS void sqrt(InputArray src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes an exponent of each matrix element.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.

@sa exp
 */
CV_EXPORTS void exp(InputArray src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes a natural logarithm of absolute value of each matrix element.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.

@sa log
 */
CV_EXPORTS void log(InputArray src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Raises every matrix element to a power.

@param src Source matrix.
@param power Exponent of power.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.

The function pow raises every element of the input matrix to power :

\f[\texttt{dst} (I) =  \fork{\texttt{src}(I)^power}{if \texttt{power} is integer}{|\texttt{src}(I)|^power}{otherwise}\f]

@sa pow
 */
CV_EXPORTS void pow(InputArray src, double power, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Compares elements of two matrices (or of a matrix and scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param cmpop Flag specifying the relation between the elements to be checked:
-   **CMP\_EQ:** a(.) == b(.)
-   **CMP\_GT:** a(.) \< b(.)
-   **CMP\_GE:** a(.) \<= b(.)
-   **CMP\_LT:** a(.) \< b(.)
-   **CMP\_LE:** a(.) \<= b(.)
-   **CMP\_NE:** a(.) != b(.)
@param stream Stream for the asynchronous version.

@sa compare
 */
CV_EXPORTS void compare(InputArray src1, InputArray src2, OutputArray dst, int cmpop, Stream& stream = Stream::Null());

/** @brief Performs a per-element bitwise inversion.

@param src Source matrix.
@param dst Destination matrix with the same size and type as src .
@param mask Optional operation mask. 8-bit single channel image.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void bitwise_not(InputArray src, OutputArray dst, InputArray mask = noArray(), Stream& stream = Stream::Null());

/** @brief Performs a per-element bitwise disjunction of two matrices (or of matrix and scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param mask Optional operation mask. 8-bit single channel image.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void bitwise_or(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), Stream& stream = Stream::Null());

/** @brief Performs a per-element bitwise conjunction of two matrices (or of matrix and scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param mask Optional operation mask. 8-bit single channel image.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void bitwise_and(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), Stream& stream = Stream::Null());

/** @brief Performs a per-element bitwise exclusive or operation of two matrices (or of matrix and scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param mask Optional operation mask. 8-bit single channel image.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void bitwise_xor(InputArray src1, InputArray src2, OutputArray dst, InputArray mask = noArray(), Stream& stream = Stream::Null());

/** @brief Performs pixel by pixel right shift of an image by a constant value.

@param src Source matrix. Supports 1, 3 and 4 channels images with integers elements.
@param val Constant values, one per channel.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void rshift(InputArray src, Scalar_<int> val, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Performs pixel by pixel right left of an image by a constant value.

@param src Source matrix. Supports 1, 3 and 4 channels images with CV\_8U , CV\_16U or CV\_32S
depth.
@param val Constant values, one per channel.
@param dst Destination matrix with the same size and type as src .
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void lshift(InputArray src, Scalar_<int> val, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes the per-element minimum of two matrices (or a matrix and a scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param stream Stream for the asynchronous version.

@sa min
 */
CV_EXPORTS void min(InputArray src1, InputArray src2, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes the per-element maximum of two matrices (or a matrix and a scalar).

@param src1 First source matrix or scalar.
@param src2 Second source matrix or scalar.
@param dst Destination matrix that has the same size and type as the input array(s).
@param stream Stream for the asynchronous version.

@sa max
 */
CV_EXPORTS void max(InputArray src1, InputArray src2, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Computes the weighted sum of two arrays.

@param src1 First source array.
@param alpha Weight for the first array elements.
@param src2 Second source array of the same size and channel number as src1 .
@param beta Weight for the second array elements.
@param dst Destination array that has the same size and number of channels as the input arrays.
@param gamma Scalar added to each sum.
@param dtype Optional depth of the destination array. When both input arrays have the same depth,
dtype can be set to -1, which will be equivalent to src1.depth().
@param stream Stream for the asynchronous version.

The function addWeighted calculates the weighted sum of two arrays as follows:

\f[\texttt{dst} (I)= \texttt{saturate} ( \texttt{src1} (I)* \texttt{alpha} +  \texttt{src2} (I)* \texttt{beta} +  \texttt{gamma} )\f]

where I is a multi-dimensional index of array elements. In case of multi-channel arrays, each
channel is processed independently.

@sa addWeighted
 */
CV_EXPORTS void addWeighted(InputArray src1, double alpha, InputArray src2, double beta, double gamma, OutputArray dst,
                            int dtype = -1, Stream& stream = Stream::Null());

//! adds scaled array to another one (dst = alpha*src1 + src2)
static inline void scaleAdd(InputArray src1, double alpha, InputArray src2, OutputArray dst, Stream& stream = Stream::Null())
{
    addWeighted(src1, alpha, src2, 1.0, 0.0, dst, -1, stream);
}

/** @brief Applies a fixed-level threshold to each array element.

@param src Source array (single-channel).
@param dst Destination array with the same size and type as src .
@param thresh Threshold value.
@param maxval Maximum value to use with THRESH\_BINARY and THRESH\_BINARY\_INV threshold types.
@param type Threshold type. For details, see threshold . The THRESH\_OTSU and THRESH\_TRIANGLE
threshold types are not supported.
@param stream Stream for the asynchronous version.

@sa threshold
 */
CV_EXPORTS double threshold(InputArray src, OutputArray dst, double thresh, double maxval, int type, Stream& stream = Stream::Null());

/** @brief Computes magnitudes of complex matrix elements.

@param xy Source complex matrix in the interleaved format ( CV\_32FC2 ).
@param magnitude Destination matrix of float magnitudes ( CV\_32FC1 ).
@param stream Stream for the asynchronous version.

@sa magnitude
 */
CV_EXPORTS void magnitude(InputArray xy, OutputArray magnitude, Stream& stream = Stream::Null());

/** @brief Computes squared magnitudes of complex matrix elements.

@param xy Source complex matrix in the interleaved format ( CV\_32FC2 ).
@param magnitude Destination matrix of float magnitude squares ( CV\_32FC1 ).
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void magnitudeSqr(InputArray xy, OutputArray magnitude, Stream& stream = Stream::Null());

/** @overload
 computes magnitude of each (x(i), y(i)) vector
 supports only floating-point source
@param x Source matrix containing real components ( CV\_32FC1 ).
@param y Source matrix containing imaginary components ( CV\_32FC1 ).
@param magnitude Destination matrix of float magnitudes ( CV\_32FC1 ).
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void magnitude(InputArray x, InputArray y, OutputArray magnitude, Stream& stream = Stream::Null());

/** @overload
 computes squared magnitude of each (x(i), y(i)) vector
 supports only floating-point source
@param x Source matrix containing real components ( CV\_32FC1 ).
@param y Source matrix containing imaginary components ( CV\_32FC1 ).
@param magnitude Destination matrix of float magnitude squares ( CV\_32FC1 ).
@param stream Stream for the asynchronous version.
*/
CV_EXPORTS void magnitudeSqr(InputArray x, InputArray y, OutputArray magnitude, Stream& stream = Stream::Null());

/** @brief Computes polar angles of complex matrix elements.

@param x Source matrix containing real components ( CV\_32FC1 ).
@param y Source matrix containing imaginary components ( CV\_32FC1 ).
@param angle Destination matrix of angles ( CV\_32FC1 ).
@param angleInDegrees Flag for angles that must be evaluated in degrees.
@param stream Stream for the asynchronous version.

@sa phase
 */
CV_EXPORTS void phase(InputArray x, InputArray y, OutputArray angle, bool angleInDegrees = false, Stream& stream = Stream::Null());

/** @brief Converts Cartesian coordinates into polar.

@param x Source matrix containing real components ( CV\_32FC1 ).
@param y Source matrix containing imaginary components ( CV\_32FC1 ).
@param magnitude Destination matrix of float magnitudes ( CV\_32FC1 ).
@param angle Destination matrix of angles ( CV\_32FC1 ).
@param angleInDegrees Flag for angles that must be evaluated in degrees.
@param stream Stream for the asynchronous version.

@sa cartToPolar
 */
CV_EXPORTS void cartToPolar(InputArray x, InputArray y, OutputArray magnitude, OutputArray angle, bool angleInDegrees = false, Stream& stream = Stream::Null());

/** @brief Converts polar coordinates into Cartesian.

@param magnitude Source matrix containing magnitudes ( CV\_32FC1 ).
@param angle Source matrix containing angles ( CV\_32FC1 ).
@param x Destination matrix of real components ( CV\_32FC1 ).
@param y Destination matrix of imaginary components ( CV\_32FC1 ).
@param angleInDegrees Flag that indicates angles in degrees.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void polarToCart(InputArray magnitude, InputArray angle, OutputArray x, OutputArray y, bool angleInDegrees = false, Stream& stream = Stream::Null());

//! @} cudaarithm_elem

//! @addtogroup cudaarithm_core
//! @{

/** @brief Makes a multi-channel matrix out of several single-channel matrices.

@param src Array/vector of source matrices.
@param n Number of source matrices.
@param dst Destination matrix.
@param stream Stream for the asynchronous version.

@sa merge
 */
CV_EXPORTS void merge(const GpuMat* src, size_t n, OutputArray dst, Stream& stream = Stream::Null());
/** @overload */
CV_EXPORTS void merge(const std::vector<GpuMat>& src, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Copies each plane of a multi-channel matrix into an array.

@param src Source matrix.
@param dst Destination array/vector of single-channel matrices.
@param stream Stream for the asynchronous version.

@sa split
 */
CV_EXPORTS void split(InputArray src, GpuMat* dst, Stream& stream = Stream::Null());
/** @overload */
CV_EXPORTS void split(InputArray src, std::vector<GpuMat>& dst, Stream& stream = Stream::Null());

/** @brief Transposes a matrix.

@param src1 Source matrix. 1-, 4-, 8-byte element sizes are supported for now.
@param dst Destination matrix.
@param stream Stream for the asynchronous version.

@sa transpose
 */
CV_EXPORTS void transpose(InputArray src1, OutputArray dst, Stream& stream = Stream::Null());

/** @brief Flips a 2D matrix around vertical, horizontal, or both axes.

@param src Source matrix. Supports 1, 3 and 4 channels images with CV\_8U, CV\_16U, CV\_32S or
CV\_32F depth.
@param dst Destination matrix.
@param flipCode Flip mode for the source:
-   0 Flips around x-axis.
-   \> 0 Flips around y-axis.
-   \< 0 Flips around both axes.
@param stream Stream for the asynchronous version.

@sa flip
 */
CV_EXPORTS void flip(InputArray src, OutputArray dst, int flipCode, Stream& stream = Stream::Null());

/** @brief Base class for transform using lookup table.
 */
class CV_EXPORTS LookUpTable : public Algorithm
{
public:
    /** @brief Transforms the source matrix into the destination matrix using the given look-up table:
    dst(I) = lut(src(I)) .

    @param src Source matrix. CV\_8UC1 and CV\_8UC3 matrices are supported for now.
    @param dst Destination matrix.
    @param stream Stream for the asynchronous version.
     */
    virtual void transform(InputArray src, OutputArray dst, Stream& stream = Stream::Null()) = 0;
};

/** @brief Creates implementation for cuda::LookUpTable .

@param lut Look-up table of 256 elements. It is a continuous CV\_8U matrix.
 */
CV_EXPORTS Ptr<LookUpTable> createLookUpTable(InputArray lut);

/** @brief Forms a border around an image.

@param src Source image. CV\_8UC1 , CV\_8UC4 , CV\_32SC1 , and CV\_32FC1 types are supported.
@param dst Destination image with the same type as src. The size is
Size(src.cols+left+right, src.rows+top+bottom) .
@param top
@param bottom
@param left
@param right Number of pixels in each direction from the source image rectangle to extrapolate.
For example: top=1, bottom=1, left=1, right=1 mean that 1 pixel-wide border needs to be built.
@param borderType Border type. See borderInterpolate for details. BORDER\_REFLECT101 ,
BORDER\_REPLICATE , BORDER\_CONSTANT , BORDER\_REFLECT and BORDER\_WRAP are supported for now.
@param value Border value.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void copyMakeBorder(InputArray src, OutputArray dst, int top, int bottom, int left, int right, int borderType,
                               Scalar value = Scalar(), Stream& stream = Stream::Null());

//! @} cudaarithm_core

//! @addtogroup cudaarithm_reduce
//! @{

/** @brief Returns the norm of a matrix (or difference of two matrices).

@param src1 Source matrix. Any matrices except 64F are supported.
@param normType Norm type. NORM\_L1 , NORM\_L2 , and NORM\_INF are supported for now.
@param mask optional operation mask; it must have the same size as src1 and CV\_8UC1 type.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

@sa norm
 */
CV_EXPORTS double norm(InputArray src1, int normType, InputArray mask, GpuMat& buf);
/** @overload
uses new buffer, no mask
*/
static inline double norm(InputArray src, int normType)
{
    GpuMat buf;
    return norm(src, normType, GpuMat(), buf);
}
/** @overload
no mask
*/
static inline double norm(InputArray src, int normType, GpuMat& buf)
{
    return norm(src, normType, GpuMat(), buf);
}

/** @brief Returns the difference of two matrices.

@param src1 Source matrix. Any matrices except 64F are supported.
@param src2 Second source matrix (if any) with the same size and type as src1.
@param normType Norm type. NORM\_L1 , NORM\_L2 , and NORM\_INF are supported for now.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

@sa norm
 */
CV_EXPORTS double norm(InputArray src1, InputArray src2, GpuMat& buf, int normType=NORM_L2);
/** @overload
uses new buffer
*/
static inline double norm(InputArray src1, InputArray src2, int normType=NORM_L2)
{
    GpuMat buf;
    return norm(src1, src2, buf, normType);
}

/** @brief Returns the sum of matrix elements.

@param src Source image of any depth except for CV\_64F .
@param mask optional operation mask; it must have the same size as src1 and CV\_8UC1 type.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

@sa sum
 */
CV_EXPORTS Scalar sum(InputArray src, InputArray mask, GpuMat& buf);
/** @overload
uses new buffer, no mask
*/
static inline Scalar sum(InputArray src)
{
    GpuMat buf;
    return sum(src, GpuMat(), buf);
}
/** @overload
no mask
*/
static inline Scalar sum(InputArray src, GpuMat& buf)
{
    return sum(src, GpuMat(), buf);
}

/** @brief Returns the sum of absolute values for matrix elements.

@param src Source image of any depth except for CV\_64F .
@param mask optional operation mask; it must have the same size as src1 and CV\_8UC1 type.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.
 */
CV_EXPORTS Scalar absSum(InputArray src, InputArray mask, GpuMat& buf);
/** @overload
uses new buffer, no mask
*/
static inline Scalar absSum(InputArray src)
{
    GpuMat buf;
    return absSum(src, GpuMat(), buf);
}
/** @overload
no mask
*/
static inline Scalar absSum(InputArray src, GpuMat& buf)
{
    return absSum(src, GpuMat(), buf);
}

/** @brief Returns the squared sum of matrix elements.

@param src Source image of any depth except for CV\_64F .
@param mask optional operation mask; it must have the same size as src1 and CV\_8UC1 type.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.
 */
CV_EXPORTS Scalar sqrSum(InputArray src, InputArray mask, GpuMat& buf);
/** @overload
uses new buffer, no mask
*/
static inline Scalar sqrSum(InputArray src)
{
    GpuMat buf;
    return sqrSum(src, GpuMat(), buf);
}
/** @overload
no mask
*/
static inline Scalar sqrSum(InputArray src, GpuMat& buf)
{
    return sqrSum(src, GpuMat(), buf);
}

/** @brief Finds global minimum and maximum matrix elements and returns their values.

@param src Single-channel source image.
@param minVal Pointer to the returned minimum value. Use NULL if not required.
@param maxVal Pointer to the returned maximum value. Use NULL if not required.
@param mask Optional mask to select a sub-matrix.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

The function does not work with CV\_64F images on GPUs with the compute capability \< 1.3.

@sa minMaxLoc
 */
CV_EXPORTS void minMax(InputArray src, double* minVal, double* maxVal, InputArray mask, GpuMat& buf);
/** @overload
uses new buffer
*/
static inline void minMax(InputArray src, double* minVal, double* maxVal=0, InputArray mask=noArray())
{
    GpuMat buf;
    minMax(src, minVal, maxVal, mask, buf);
}

/** @brief Finds global minimum and maximum matrix elements and returns their values with locations.

@param src Single-channel source image.
@param minVal Pointer to the returned minimum value. Use NULL if not required.
@param maxVal Pointer to the returned maximum value. Use NULL if not required.
@param minLoc Pointer to the returned minimum location. Use NULL if not required.
@param maxLoc Pointer to the returned maximum location. Use NULL if not required.
@param mask Optional mask to select a sub-matrix.
@param valbuf Optional values buffer to avoid extra memory allocations. It is resized
automatically.
@param locbuf Optional locations buffer to avoid extra memory allocations. It is resized
automatically.
The function does not work with CV\_64F images on GPU with the compute capability \< 1.3.

@sa minMaxLoc
 */
CV_EXPORTS void minMaxLoc(InputArray src, double* minVal, double* maxVal, Point* minLoc, Point* maxLoc,
                          InputArray mask, GpuMat& valbuf, GpuMat& locbuf);
/** @overload
uses new buffer
*/
static inline void minMaxLoc(InputArray src, double* minVal, double* maxVal=0, Point* minLoc=0, Point* maxLoc=0,
                             InputArray mask=noArray())
{
    GpuMat valBuf, locBuf;
    minMaxLoc(src, minVal, maxVal, minLoc, maxLoc, mask, valBuf, locBuf);
}

/** @brief Counts non-zero matrix elements.

@param src Single-channel source image.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

The function does not work with CV\_64F images on GPUs with the compute capability \< 1.3.

@sa countNonZero
 */
CV_EXPORTS int countNonZero(InputArray src, GpuMat& buf);
/** @overload
uses new buffer
*/
static inline int countNonZero(const GpuMat& src)
{
    GpuMat buf;
    return countNonZero(src, buf);
}

/** @brief Reduces a matrix to a vector.

@param mtx Source 2D matrix.
@param vec Destination vector. Its size and type is defined by dim and dtype parameters.
@param dim Dimension index along which the matrix is reduced. 0 means that the matrix is reduced
to a single row. 1 means that the matrix is reduced to a single column.
@param reduceOp Reduction operation that could be one of the following:
-   **CV\_REDUCE\_SUM** The output is the sum of all rows/columns of the matrix.
-   **CV\_REDUCE\_AVG** The output is the mean vector of all rows/columns of the matrix.
-   **CV\_REDUCE\_MAX** The output is the maximum (column/row-wise) of all rows/columns of the
matrix.
-   **CV\_REDUCE\_MIN** The output is the minimum (column/row-wise) of all rows/columns of the
matrix.
@param dtype When it is negative, the destination vector will have the same type as the source
matrix. Otherwise, its type will be CV\_MAKE\_TYPE(CV\_MAT\_DEPTH(dtype), mtx.channels()) .
@param stream Stream for the asynchronous version.

The function reduce reduces the matrix to a vector by treating the matrix rows/columns as a set of
1D vectors and performing the specified operation on the vectors until a single row/column is
obtained. For example, the function can be used to compute horizontal and vertical projections of a
raster image. In case of CV\_REDUCE\_SUM and CV\_REDUCE\_AVG , the output may have a larger element
bit-depth to preserve accuracy. And multi-channel arrays are also supported in these two reduction
modes.

@sa reduce
 */
CV_EXPORTS void reduce(InputArray mtx, OutputArray vec, int dim, int reduceOp, int dtype = -1, Stream& stream = Stream::Null());

/** @brief Computes a mean value and a standard deviation of matrix elements.

@param mtx Source matrix. CV\_8UC1 matrices are supported for now.
@param mean Mean value.
@param stddev Standard deviation value.
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.

@sa meanStdDev
 */
CV_EXPORTS void meanStdDev(InputArray mtx, Scalar& mean, Scalar& stddev, GpuMat& buf);
/** @overload
uses new buffer
*/
static inline void meanStdDev(InputArray src, Scalar& mean, Scalar& stddev)
{
    GpuMat buf;
    meanStdDev(src, mean, stddev, buf);
}

/** @brief Computes a standard deviation of integral images.

@param src Source image. Only the CV\_32SC1 type is supported.
@param sqr Squared source image. Only the CV\_32FC1 type is supported.
@param dst Destination image with the same type and size as src .
@param rect Rectangular window.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void rectStdDev(InputArray src, InputArray sqr, OutputArray dst, Rect rect, Stream& stream = Stream::Null());

/** @brief Normalizes the norm or value range of an array.

@param src Input array.
@param dst Output array of the same size as src .
@param alpha Norm value to normalize to or the lower range boundary in case of the range
normalization.
@param beta Upper range boundary in case of the range normalization; it is not used for the norm
normalization.
@param norm_type Normalization type ( NORM\_MINMAX , NORM\_L2 , NORM\_L1 or NORM\_INF ).
@param dtype When negative, the output array has the same type as src; otherwise, it has the same
number of channels as src and the depth =CV\_MAT\_DEPTH(dtype).
@param mask Optional operation mask.
@param norm\_buf Optional buffer to avoid extra memory allocations. It is resized automatically.
@param cvt\_buf Optional buffer to avoid extra memory allocations. It is resized automatically.

@sa normalize
 */
CV_EXPORTS void normalize(InputArray src, OutputArray dst, double alpha, double beta,
                          int norm_type, int dtype, InputArray mask, GpuMat& norm_buf, GpuMat& cvt_buf);
/** @overload
uses new buffers
*/
static inline void normalize(InputArray src, OutputArray dst, double alpha = 1, double beta = 0,
                             int norm_type = NORM_L2, int dtype = -1, InputArray mask = noArray())
{
    GpuMat norm_buf;
    GpuMat cvt_buf;
    normalize(src, dst, alpha, beta, norm_type, dtype, mask, norm_buf, cvt_buf);
}

/** @brief Computes an integral image.

@param src Source image. Only CV\_8UC1 images are supported for now.
@param sum Integral image containing 32-bit unsigned integer values packed into CV\_32SC1 .
@param buffer Optional buffer to avoid extra memory allocations. It is resized automatically.
@param stream Stream for the asynchronous version.

@sa integral
 */
CV_EXPORTS void integral(InputArray src, OutputArray sum, GpuMat& buffer, Stream& stream = Stream::Null());
static inline void integralBuffered(InputArray src, OutputArray sum, GpuMat& buffer, Stream& stream = Stream::Null())
{
    integral(src, sum, buffer, stream);
}
/** @overload
uses new buffer
*/
static inline void integral(InputArray src, OutputArray sum, Stream& stream = Stream::Null())
{
    GpuMat buffer;
    integral(src, sum, buffer, stream);
}

/** @brief Computes a squared integral image.

@param src Source image. Only CV\_8UC1 images are supported for now.
@param sqsum Squared integral image containing 64-bit unsigned integer values packed into
CV\_64FC1 .
@param buf Optional buffer to avoid extra memory allocations. It is resized automatically.
@param stream Stream for the asynchronous version.
 */
CV_EXPORTS void sqrIntegral(InputArray src, OutputArray sqsum, GpuMat& buf, Stream& stream = Stream::Null());
/** @overload
uses new buffer
*/
static inline void sqrIntegral(InputArray src, OutputArray sqsum, Stream& stream = Stream::Null())
{
    GpuMat buffer;
    sqrIntegral(src, sqsum, buffer, stream);
}

//! @} cudaarithm_reduce

//! @addtogroup cudaarithm_arithm
//! @{

/** @brief Performs generalized matrix multiplication.

@param src1 First multiplied input matrix that should have CV\_32FC1 , CV\_64FC1 , CV\_32FC2 , or
CV\_64FC2 type.
@param src2 Second multiplied input matrix of the same type as src1 .
@param alpha Weight of the matrix product.
@param src3 Third optional delta matrix added to the matrix product. It should have the same type
as src1 and src2 .
@param beta Weight of src3 .
@param dst Destination matrix. It has the proper size and the same type as input matrices.
@param flags Operation flags:
-   **GEMM\_1\_T** transpose src1
-   **GEMM\_2\_T** transpose src2
-   **GEMM\_3\_T** transpose src3
@param stream Stream for the asynchronous version.

The function performs generalized matrix multiplication similar to the gemm functions in BLAS level
3. For example, gemm(src1, src2, alpha, src3, beta, dst, GEMM\_1\_T + GEMM\_3\_T) corresponds to

\f[\texttt{dst} =  \texttt{alpha} \cdot \texttt{src1} ^T  \cdot \texttt{src2} +  \texttt{beta} \cdot \texttt{src3} ^T\f]

@note Transposition operation doesn't support CV\_64FC2 input type.

@sa gemm
 */
CV_EXPORTS void gemm(InputArray src1, InputArray src2, double alpha,
                     InputArray src3, double beta, OutputArray dst, int flags = 0, Stream& stream = Stream::Null());

/** @brief Performs a per-element multiplication of two Fourier spectrums.

@param src1 First spectrum.
@param src2 Second spectrum with the same size and type as a .
@param dst Destination spectrum.
@param flags Mock parameter used for CPU/CUDA interfaces similarity.
@param conjB Optional flag to specify if the second spectrum needs to be conjugated before the
multiplication.
@param stream Stream for the asynchronous version.

Only full (not packed) CV\_32FC2 complex spectrums in the interleaved format are supported for now.

@sa mulSpectrums
 */
CV_EXPORTS void mulSpectrums(InputArray src1, InputArray src2, OutputArray dst, int flags, bool conjB=false, Stream& stream = Stream::Null());

/** @brief Performs a per-element multiplication of two Fourier spectrums and scales the result.

@param src1 First spectrum.
@param src2 Second spectrum with the same size and type as a .
@param dst Destination spectrum.
@param flags Mock parameter used for CPU/CUDA interfaces similarity.
@param scale Scale constant.
@param conjB Optional flag to specify if the second spectrum needs to be conjugated before the
multiplication.
@param stream Stream for the asynchronous version.

Only full (not packed) CV\_32FC2 complex spectrums in the interleaved format are supported for now.

@sa mulSpectrums
 */
CV_EXPORTS void mulAndScaleSpectrums(InputArray src1, InputArray src2, OutputArray dst, int flags, float scale, bool conjB=false, Stream& stream = Stream::Null());

/** @brief Performs a forward or inverse discrete Fourier transform (1D or 2D) of the floating point matrix.

@param src Source matrix (real or complex).
@param dst Destination matrix (real or complex).
@param dft\_size Size of a discrete Fourier transform.
@param flags Optional flags:
-   **DFT\_ROWS** transforms each individual row of the source matrix.
-   **DFT\_SCALE** scales the result: divide it by the number of elements in the transform
(obtained from dft\_size ).
-   **DFT\_INVERSE** inverts DFT. Use for complex-complex cases (real-complex and complex-real
cases are always forward and inverse, respectively).
-   **DFT\_REAL\_OUTPUT** specifies the output as real. The source matrix is the result of
real-complex transform, so the destination matrix must be real.
@param stream Stream for the asynchronous version.

Use to handle real matrices ( CV32FC1 ) and complex matrices in the interleaved format ( CV32FC2 ).

The source matrix should be continuous, otherwise reallocation and data copying is performed. The
function chooses an operation mode depending on the flags, size, and channel count of the source
matrix:

-   If the source matrix is complex and the output is not specified as real, the destination
matrix is complex and has the dft\_size size and CV\_32FC2 type. The destination matrix
contains a full result of the DFT (forward or inverse).
-   If the source matrix is complex and the output is specified as real, the function assumes that
its input is the result of the forward transform (see the next item). The destination matrix
has the dft\_size size and CV\_32FC1 type. It contains the result of the inverse DFT.
-   If the source matrix is real (its type is CV\_32FC1 ), forward DFT is performed. The result of
the DFT is packed into complex ( CV\_32FC2 ) matrix. So, the width of the destination matrix
is dft\_size.width / 2 + 1 . But if the source is a single column, the height is reduced
instead of the width.

@sa dft
 */
CV_EXPORTS void dft(InputArray src, OutputArray dst, Size dft_size, int flags=0, Stream& stream = Stream::Null());

/** @brief Base class for convolution (or cross-correlation) operator. :
 */
class CV_EXPORTS Convolution : public Algorithm
{
public:
    /** @brief Computes a convolution (or cross-correlation) of two images.

    @param image Source image. Only CV\_32FC1 images are supported for now.
    @param templ Template image. The size is not greater than the image size. The type is the same as
    image .
    @param result Result image. If image is *W x H* and templ is *w x h*, then result must be *W-w+1 x
    H-h+1*.
    @param ccorr Flags to evaluate cross-correlation instead of convolution.
    @param stream Stream for the asynchronous version.
     */
    virtual void convolve(InputArray image, InputArray templ, OutputArray result, bool ccorr = false, Stream& stream = Stream::Null()) = 0;
};

/** @brief Creates implementation for cuda::Convolution .

@param user\_block\_size Block size. If you leave default value Size(0,0) then automatic
estimation of block size will be used (which is optimized for speed). By varying user\_block\_size
you can reduce memory requirements at the cost of speed.
 */
CV_EXPORTS Ptr<Convolution> createConvolution(Size user_block_size = Size());

//! @} cudaarithm_arithm

//! @} cudaarithm

}} // namespace cv { namespace cuda {

#endif /* __OPENCV_CUDAARITHM_HPP__ */
