#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Sema/Sema.h"
#include "llvm/Support/raw_ostream.h"

#include "LocalASTAction.h"

using namespace clang;
using namespace exar::lower;

static FrontendPluginRegistry::Add<LocalASTAction>
X("exar-lower", "Checks for class names that start with lowercase");
