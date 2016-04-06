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

/*! \file symmetric_rcm.h
 *  \brief Reverse Cuthill-Mckee of a sparse matrix
 */

#pragma once

#include <cusp/detail/config.h>
#include <cusp/detail/execution_policy.h>

namespace cusp
{
namespace graph
{

/*! \addtogroup algorithms Algorithms
 *  \addtogroup graph_algorithms Graph Algorithms
 *  \ingroup algorithms
 *  \{
 */

/* \cond */
template <typename DerivedPolicy,
          typename MatrixType,
          typename PermutationType>
void symmetric_rcm(const thrust::detail::execution_policy_base<DerivedPolicy>& exec,
                   const MatrixType& G,
                   PermutationType& P);
/* \endcond */

/**
 * \brief Compute Reverse Cuthill-McKee reordering
 *
 * \tparam MatrixType Type of input matrix
 * \tparam PermutationType Type of permutation matrix
 *
 * \param G A symmetric matrix that represents the graph
 * \param P The permutation matrix that is generated by the RCM reordering
 *
 * \par Overview
 *
 * Performs a reordering on a graph represented by a symmetric sparse
 * adjacency matrix in order to decrease the bandwidth. The reordering is computed
 * using the Cuthill-McKee algorithm and reversing the resulting index numbers.
 *
 * \see http://en.wikipedia.org/wiki/Cuthill-McKee_algorithm
 *
 * \par Example
 *
 * \code
 * #include <cusp/array2d.h>
 * #include <cusp/csr_matrix.h>
 * #include <cusp/permutation_matrix.h>
 * #include <cusp/print.h>
 * #include <cusp/gallery/grid.h>
 *
 * //include RCM header file
 * #include <cusp/graph/symmetric_rcm.h>
 *
 * #include <iostream>
 *
 * int main()
 * {
 *    // Build a 2D grid on the device
 *    cusp::csr_matrix<int,float,cusp::device_memory> G;
 *    cusp::gallery::grid2d(G, 3, 3);
 *
 *    // Allocate permutation matrix P
 *    cusp::permutation_matrix<int,cusp::device_memory> P(G.num_rows);
 *
 *    // Construct symmetric RCM permutation matrix on the device
 *    cusp::graph::symmetric_rcm(G, P);
 *
 *    // Convert permutation to dense matrix
 *    cusp::array2d<float,cusp::device_memory> P_dense(P);
 *
 *    // Print the permutation matrix
 *    cusp::print(P_dense);
 *
 *    return 0;
 * }
 * \endcode
 */
template<typename MatrixType, typename PermutationType>
void symmetric_rcm(const MatrixType& G, PermutationType& P);
/*! \}
 */

} // end namespace graph
} // end namespace cusp

#include <cusp/graph/detail/symmetric_rcm.inl>

