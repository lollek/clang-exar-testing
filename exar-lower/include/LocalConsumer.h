#include <clang/AST/AST.h>
#include <clang/AST/ASTConsumer.h>

#include "LocalVisitor.h"

namespace exar {
namespace lower {

class LocalConsumer : public clang::ASTConsumer {
public:
  void HandleTranslationUnit(clang::ASTContext& context);

private:
  LocalVisitor visitor;
};

} //namespace lower
} //namespace exar
