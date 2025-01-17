//===- ComprehensiveBufferize.h - Linalg bufferization pass -----*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_DIALECT_LINALG_COMPREHENSIVEBUFFERIZE_COMPREHENSIVE_BUFFERIZE_H
#define MLIR_DIALECT_LINALG_COMPREHENSIVEBUFFERIZE_COMPREHENSIVE_BUFFERIZE_H

#include "mlir/IR/BuiltinOps.h"

namespace mlir {

namespace linalg {
namespace comprehensive_bufferize {

class BufferizationAliasInfo;
struct BufferizationOptions;
class BufferizationState;

/// Analyze `op` and its nested ops. Bufferization decisions are stored in
/// `state`.
LogicalResult analyzeOp(Operation *op, BufferizationState &state);

/// Bufferize the given operation. Reuses an existing BufferizationState object.
/// If `runAnalysis` is set to false, all OpOperands bufferize out-of-place.
/// This function overload is for internal usage only.
LogicalResult runComprehensiveBufferize(Operation *op,
                                        const BufferizationOptions &options,
                                        BufferizationState &state,
                                        bool runAnalysis = true);

/// Bufferize the given operation.
LogicalResult
runComprehensiveBufferize(Operation *op,
                          std::unique_ptr<BufferizationOptions> options);

} // namespace comprehensive_bufferize
} // namespace linalg
} // namespace mlir

#endif // MLIR_DIALECT_LINALG_COMPREHENSIVEBUFFERIZE_COMPREHENSIVE_BUFFERIZE_H
