/*
 *  Copyright 2008-2014 NVIDIA Corporation
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

#include <cusp/detail/config.h>

#include <cusp/detail/execution_policy.h>

namespace cusp
{
namespace precond
{
namespace aggregation
{
namespace detail
{

template<typename DerivedPolicy, typename MatrixType1, typename MatrixType2, typename ArrayType>
typename thrust::detail::enable_if_convertible<typename ArrayType::format,cusp::array1d_format>::type
evolution_strength_of_connection(thrust::execution_policy<DerivedPolicy> &exec,
                                 const MatrixType1& A, MatrixType2& S, const ArrayType& B,
                                 const double rho_DinvA, const double epsilon);

} // end namespace detail
} // end namespace aggregation
} // end namespace precond
} // end namespace cusp

#include <cusp/precond/aggregation/system/detail/generic/evolution_strength.inl>
