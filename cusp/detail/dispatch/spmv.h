/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
    
#include <cusp/array1d.h>

#include <cusp/detail/host/spmv.h>
#include <cusp/detail/device/spmv.h>

namespace cusp
{
namespace detail
{
namespace dispatch
{

////////////////
// Host Paths //
////////////////
template <typename MatrixType,
          typename VectorType1,
          typename VectorType2>
void spmv(const MatrixType& A,
          const VectorType1& x,
                VectorType2& y,
          cusp::host_memory,
          cusp::host_memory,
          cusp::host_memory)
{
    cusp::detail::host::spmv(A, thrust::raw_pointer_cast(&x[0]), thrust::raw_pointer_cast(&y[0]));
}

//////////////////
// Device Paths //
//////////////////
template <typename MatrixType,
          typename VectorType1,
          typename VectorType2>
void spmv(const MatrixType& A,
          const VectorType1& x,
                VectorType2& y,
          cusp::device_memory,
          cusp::device_memory,
          cusp::device_memory)
{
#ifdef CUSP_USE_TEXTURE_MEMORY    
    cusp::detail::device::spmv_tex(A, thrust::raw_pointer_cast(&x[0]), thrust::raw_pointer_cast(&y[0]));
#else
    cusp::detail::device::spmv(A, thrust::raw_pointer_cast(&x[0]), thrust::raw_pointer_cast(&y[0]));
#endif
}

} // end namespace dispatch
} // end namespace detail
} // end namespace cusp
